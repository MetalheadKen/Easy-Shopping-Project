#include "Global.h"

void LED_Initial(void) 
{ 
    // Set the pin to be an output
    bcm2835_gpio_fsel(PIN_AL, BCM2835_GPIO_FSEL_OUTP);     
    bcm2835_gpio_fsel(PIN_BL, BCM2835_GPIO_FSEL_OUTP);     
    bcm2835_gpio_fsel(PIN_CL, BCM2835_GPIO_FSEL_OUTP);     
    bcm2835_gpio_fsel(PIN_S1, BCM2835_GPIO_FSEL_OUTP);     
    bcm2835_gpio_fsel(PIN_S2, BCM2835_GPIO_FSEL_OUTP);     
    bcm2835_gpio_fsel(PIN_ENABLEL, BCM2835_GPIO_FSEL_OUTP); 
                                                                   
    bcm2835_gpio_fsel(PIN_AR, BCM2835_GPIO_FSEL_OUTP);     
    bcm2835_gpio_fsel(PIN_BR, BCM2835_GPIO_FSEL_OUTP);     
    bcm2835_gpio_fsel(PIN_CR, BCM2835_GPIO_FSEL_OUTP);     
    bcm2835_gpio_fsel(PIN_S3, BCM2835_GPIO_FSEL_OUTP);     
    bcm2835_gpio_fsel(PIN_S4, BCM2835_GPIO_FSEL_OUTP);     
    bcm2835_gpio_fsel(PIN_ENABLER, BCM2835_GPIO_FSEL_OUTP); 
    
    //Close ALL LED
    bcm2835_gpio_write(PIN_ENABLEL, HIGH);
    bcm2835_gpio_write(PIN_ENABLER, HIGH);
}

void LED_Light(int left,int right)
{
    if(left != -1)
    {
        bcm2835_gpio_write(PIN_ENABLEL, LOW);
        bcm2835_gpio_write(PIN_ENABLER, HIGH);
        
        bcm2835_gpio_write(PIN_AL, left & 0x0001);
        bcm2835_gpio_write(PIN_BL, left & 0x0002);
        bcm2835_gpio_write(PIN_CL, left & 0x0004);
        bcm2835_gpio_write(PIN_S1, left & 0x0008);
        bcm2835_gpio_write(PIN_S2, left & 0x0010);
    }
    else if(right != -1)
    {
        bcm2835_gpio_write(PIN_ENABLEL, HIGH);
        bcm2835_gpio_write(PIN_ENABLER, LOW);
        
        bcm2835_gpio_write(PIN_AR, right & 0x0001);
        bcm2835_gpio_write(PIN_BR, right & 0x0002);
        bcm2835_gpio_write(PIN_CR, right & 0x0004);
        bcm2835_gpio_write(PIN_S3, right & 0x0008);
        bcm2835_gpio_write(PIN_S4, right & 0x0010);
    }
    
    //usleep(10);
    delay(80);
}

byte LED_Choose(short row, short col) {
    byte choose[ROW][COLUMN] = {{ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR},
                                  {ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, 9, ERROR, ERROR, ERROR, ERROR, ERROR, 22, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, 54, ERROR, ERROR, ERROR, ERROR, ERROR, 41, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR},
                                  {ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, 10, ERROR, ERROR, ERROR, ERROR, ERROR, 21, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, 53, ERROR, ERROR, ERROR, ERROR, ERROR, 42, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR}, 
                                  {ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, 11, ERROR, ERROR, ERROR, ERROR, ERROR, 20, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, 52, ERROR, ERROR, ERROR, ERROR, ERROR, 43, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR},
                                  {ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, 12, ERROR, ERROR, ERROR, ERROR, ERROR, 19, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, 51, ERROR, ERROR, ERROR, ERROR, ERROR, 44, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR}, 
                                  {ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ROUTE, 13, 14, ROUTE, 17, 18, ROUTE, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ROUTE, 50, 49, ROUTE, 46, 45, ROUTE, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR},
                                  {ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, 16, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, 48, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR}, 
                                  {ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, 15, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, 47, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR}, 
                                  {ERROR, 0, 1, 2, 3, 4, 5, 6, 7, 8, 26, 27, 28, 29, 30, 31, 63, 62, 61, 60, 59, 58, 40, 39, 38, 37, 36, 35, 34, 33, 32, ERROR}, 
                                  {ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, 25, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, 57, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR}, 
                                  {ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, 24, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, 56, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR}, 
                                  {ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, 23, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, 55, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR},
                                  {ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR}};
    
    return choose[row][col];
}
