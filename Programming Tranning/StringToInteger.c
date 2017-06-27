#include <stdio.h>
#include "string.h"

typedef struct Point {
	short x;
	short y;
} Point;

short StringToInteger(char *);

int main(void) {
    int  size;
    char buffer[4096] = {0};
    char number[5]    = {0};
    
    Point start = {0, 0};
    Point end   = {0, 0};
        
    while(gets(buffer) != NULL)
    {
		printf("%d\n", strlen(buffer));
		
        for(int i = 0, y = 0; i <= strlen(buffer); i++)
		{
			if(buffer[i] == ',')
			{
				number[y] = '\0';
				start.x   = StringToInteger(number);
				y = 0;
				continue;
			}
			else if(buffer[i] == ' ')
			{
				i++;
				number[y] = '\0';
				start.y   = StringToInteger(number);
				
				for(y = 0; i <= strlen(buffer); i++)
				{
					if(buffer[i] == ',')
					{
						number[y] = '\0';
						end.x     = StringToInteger(number);
						y = 0;
						continue;
					}
					else if(buffer[i] == '\0')
					{
						number[y] = '\0';
						end.y     = StringToInteger(number);
						break;
					}
					
					number[y++] = buffer[i];
				}
			}
							
			if(buffer[i] == '\0')
				{printf("break");break;}
			
			number[y++] = buffer[i];
		}
		
		printf("%d %d %d %d\n", start.x, start.y, end.x, end.y);
	}
	
	return 0;
}

short StringToInteger(char *string) {
	short number = 0;
	
	for(int i = 0; string[i]; i++)
	{
		if(string[i] >= '0' && string[i] <= '9')
		{
			number = number * 10 + string[i] - '0';
		}
	}
	
	return (string[0] != '-') ? (number) : (number * -1);
}
