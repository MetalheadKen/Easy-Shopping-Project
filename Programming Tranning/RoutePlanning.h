#define ROW 		13
#define COLUMN 	32
#define LED_COUNT 64

#define ERROR		128

typedef struct Point {
	short x;
	short y;
} Point;

void  RoutePlanning(Point, Point, char*);
char  Visit(char (*maze)[COLUMN], Point, Point);
Point point(short, short);
void  print(char (*maze)[COLUMN]);
void  GetRoute(char (*maze)[COLUMN], char *, short, short);
