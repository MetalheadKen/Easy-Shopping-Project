#include "Global.h"

int main(int argc, char **argv)
{
    if (!bcm2835_init())
        return 1;
 
    LED_Initial();
    
    Socket();
 
    return 0;
}
