#define ROW        	13
#define COLUMN      	32
#define LED_COUNT		64

#define ROUTE			65
#define ERROR      	127

typedef struct Point {
    short x;
    short y;
} Point;

typedef unsigned char byte;

byte  RoutePlanning(Point, Point, byte * restrict);
byte  Visit(byte (*maze)[COLUMN], Point, Point);
Point point(short, short);
void  print(byte (*maze)[COLUMN]);
void  GetRoute(byte (*maze)[COLUMN], byte * restrict, short, short);
