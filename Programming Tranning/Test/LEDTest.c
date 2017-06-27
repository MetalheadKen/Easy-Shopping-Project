#include <stdio.h>
#include <stdlib.h>
#include "Socket.h"
#include "Locate.h"

int main(int argc, char **argv)
{
    if (!bcm2835_init())
	return 1;
 
	LED_INITIAL();
	
	Socket();
	
	// Blink
    //while (1)
    //{
	 
		/*for(int x=0;x<32;x++)
		{
			LED_LIGHT(x,-1);
			printf("LED:%d\n",x);
			delay(200);
		}
		
		for(int x=0;x<32;x++)
		{
			LED_LIGHT(-1,x);
			printf("LED:%d\n",x);
			delay(200);
		}*/
		
		/*for(int a = 0, b = 0; a < 32; a+=1, b+=1)
		{
			for(int x = 0; x < 32; x++)
				LED_LIGHT(a, b);
			
			//delay(200);
		}
	}*/
 
    return 0;
}
