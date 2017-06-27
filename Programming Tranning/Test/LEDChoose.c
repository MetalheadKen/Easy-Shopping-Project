#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

char LED_Choose(short, short);

int main(void)
{
	short i = 8, j = 2;
	
	printf("%+d", -1);
	
	return 0;
}

char LED_Choose(short row, short col) {
	switch(row)
	{
		case 1:
			switch(col)
			{
				case 6:
					return 9;
				case 12:
					return 22;
				case 19:
					return 54;
				case 25:
					return 41;					
			}
			break;
		case 2:
			switch(col)
			{
				case 6:
					return 10;
				case 12:
					return 21;
				case 19:
					return 53;
				case 25:
					return 42;					
			}
			break;
		case 3:
			switch(col)
			{
				case 6:
					return 11;
				case 12:
					return 20;
				case 19:
					return 52;
				case 25:
					return 43;					
			}
			break;
		case 4:
			switch(col)
			{
				case 6:
					return 12;
				case 12:
					return 19;
				case 19:
					return 51;
				case 25:
					return 44;					
			}
			break;
		case 5:
			switch(col)
			{
				case 7:
					return 13;
				case 8:
					return 14;
				case 10:
					return 17;
				case 11:
					return 18;
				case 20:
					return 50;
				case 21:
					return 49;
				case 23:
					return 46;
				case 24:
					return 45;
			}
			break;
		case 6:
			switch(col)
			{
				case 9:
					return 16;
				case 22:
					return 48;				
			}
			break;
		case 7:
			switch(col)
			{
				case 9:
					return 15;
				case 22:
					return 47;			
			}
			break;
		case 8:
			switch(col)
			{
				case 1:
					return 0;
				case 2:
					return 1;
				case 3:
					return 2;
				case 4:
					return 3;
				case 5:
					return 4;
				case 6:
					return 5;
				case 7:
					return 6;
				case 8:
					return 7;
				case 9:
					return 8;
				case 10:
					return 26;
				case 11:
					return 27;
				case 12:
					return 28;
				case 13:
					return 29;
				case 14:
					return 30;
				case 15:
					return 31;
				case 16:
					return 63;
				case 17:
					return 62;
				case 18:
					return 61;
				case 19:
					return 60;
				case 20:
					return 59;
				case 21:
					return 58;
				case 22:
					return 40;
				case 23:
					return 39;
				case 24:
					return 38;
				case 25:
					return 17;
				case 26:
					return 36;
				case 27:
					return 35;
				case 28:
					return 34;
				case 29:
					return 33;
				case 30:
					return 32;
			}
			break;
		case 9:
			switch(col)
			{
				case 9:
					return 25;
				case 22:
					return 57;			
			}
			break;
		case 10:
			switch(col)
			{
				case 9:
					return 24;
				case 22:
					return 56;			
			}
			break;
		case 11:
			switch(col)
			{
				case 9:
					return 23;
				case 22:
					return 55;			
			}
			break;
	}
	
	return -1;
}
