#include "Global.h"

byte RoutePlanning(Point start, Point end, byte * restrict led) {
    byte maze[ROW][COLUMN] = {{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
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
                  
    if(!Visit(maze, start, end))
    {
        printf("No Find Export!!!\n");
        return 1;
    }

    /* Get The Need To LED Light */
    GetRoute(maze, led, start.x, start.y);
    
    //print(maze);
    
    return 0;
}

byte Visit(byte (*maze)[COLUMN], Point start, Point end) {
    if(!(*(*(maze + start.x) + start.y)))
    {
        (*(*(maze + start.x) + start.y)) = 1;
    
        /* If No Find Export */
        if(!(*(*(maze + end.x) + end.y)) && !(Visit(maze, point(start.x, start.y + 1), end) ||
                                               Visit(maze, point(start.x + 1, start.y), end) ||
                                               Visit(maze, point(start.x, start.y - 1), end) ||
                                               Visit(maze, point(start.x - 1, start.y), end)))
        {
            (*(*(maze + start.x) + start.y)) = 0;
        }
    }
    
    return (*(*(maze + end.x) + end.y));
}

inline 
Point point(short x, short y) {
    Point p = {x, y};
    
    return p;
}


void print(byte (*maze)[COLUMN]) {
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COLUMN; j++)
        {
            switch(*(*(maze + i) + j))
            {
                case 0:     printf("@"); break;
                case 'W':   printf("*"); break;
                case 2:     printf(" ");
            }
        }
        
        putchar('\n');
    }
}

void GetRoute(byte (*maze)[COLUMN], byte * restrict led, short row, short col) {
    static short count = 0;
    
    int Choose = LED_Choose(row, col);
        
    if(Choose != ERROR)
        (*(led + count++)) = Choose;
        
    (*(*(maze + row) + col)) = 'W';
    
    if((*(*(maze + row) + col + 1)) == 1)
    {   
        GetRoute(maze, led, row, col + 1);
    }
    else if((*(*(maze + row + 1) + col)) == 1)
    {
        GetRoute(maze, led, row + 1, col);
    }
    else if((*(*(maze + row) + col - 1)) == 1)
    {
        GetRoute(maze, led, row, col - 1);
    }
    else if((*(*(maze + row - 1) + col)) == 1)
    {
        GetRoute(maze, led, row - 1, col);
    }
    
    count = 0;
}
