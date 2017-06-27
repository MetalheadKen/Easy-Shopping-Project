#include <stdio.h>

#define ROW 	13
#define COLUMN 	32

typedef struct Point {
	int x;
	int y;
}Point;

char  visit(char (*maze)[COLUMN], Point, Point);
Point point(int, int);
void  print(char (*maze)[COLUMN]);
void  GetRoute(char (*maze)[COLUMN], char *led, short, short);

int main(void) {
	char led[64] = {128};
	char maze[ROW][COLUMN] = {{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
							  {2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2},
							  {2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2}, 
							  {2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2},
							  {2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2}, 
							  {2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2},
							  {2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2}, 
							  {2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2}, 
							  {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2}, 
							  {2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2}, 
							  {2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2}, 
							  {2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2},
							  {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}};
							  
	if(!visit(maze, point(8, 1), point(1, 25)))
		printf("沒有找到出口！！！\n");
	else		
		/* Get The Need To LED Light */
		GetRoute(maze, led, 8, 1);
	
	print(maze);
		
	return 0;
}

char visit(char (*maze)[COLUMN], Point start, Point end) {
	
	if(!maze[start.x][start.y])
	{
		maze[start.x][start.y] = 1;
	
		/* 未找到出口時 */
		if(!maze[end.x][end.y] && !(visit(maze, point(start.x, start.y + 1), end) ||
									visit(maze, point(start.x + 1, start.y), end) ||
									visit(maze, point(start.x, start.y - 1), end) ||
									visit(maze, point(start.x - 1, start.y), end)))
		{
			maze[start.x][start.y] = 0;
		}
	}
	
	return maze[end.x][end.y];
}

Point point(int x, int y) {
	Point p = {x, y};
	
	return p;
}

void print(char (*maze)[COLUMN]) {
	for(int i = 0; i < ROW; i++)
	{
		for(int j = 0; j < COLUMN; j++)
		{
			switch(*(*(maze + i) + j))
			{
				case 0: printf("    "); break;
				case 'W': printf("◇"); break;
				case 2: printf("█");
			}
		}
		
		putchar('\n');
	}
}
void GetRoute(char (*maze)[COLUMN], char *led, short row, short col) {
	static short count = 0;
	
	maze[row][col] = 'W';
	led[count++] = count;
	
	if(maze[row][col + 1] == 1)
	{	
		GetRoute(maze, led, row, col + 1);
	}
	else if(maze[row + 1][col] == 1)
	{
		GetRoute(maze, led, row + 1, col);
	}
	else if(maze[row][col - 1] == 1)
	{
		GetRoute(maze, led, row, col - 1);
	}
	else if(maze[row - 1][col] == 1)
	{
		GetRoute(maze, led, row - 1, col);
	}
}
