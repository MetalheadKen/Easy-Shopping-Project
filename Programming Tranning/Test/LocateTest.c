#include "Locate.h"

void LED_INITIAL(void) 
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

void LED_LIGHT(int left,int right)
{
	if(left != -1)
	{
		bcm2835_gpio_write(PIN_ENABLEL, LOW);
		//bcm2835_gpio_write(PIN_ENABLER, HIGH);
		
		bcm2835_gpio_write(PIN_AL, left & 0x0001);
		bcm2835_gpio_write(PIN_BL, left & 0x0002);
		bcm2835_gpio_write(PIN_CL, left & 0x0004);
		bcm2835_gpio_write(PIN_S1, left & 0x0008);
		bcm2835_gpio_write(PIN_S2, left & 0x0010);
		
		delay(10);
		
		bcm2835_gpio_write(PIN_AL, left+1 & 0x0001);
		bcm2835_gpio_write(PIN_BL, left+1 & 0x0002);
		bcm2835_gpio_write(PIN_CL, left+1 & 0x0004);
		bcm2835_gpio_write(PIN_S1, left+1 & 0x0008);
		bcm2835_gpio_write(PIN_S2, left+1 & 0x0010);
	}
	
	if(right != -1)
	{
		//bcm2835_gpio_write(PIN_ENABLEL, HIGH);
		bcm2835_gpio_write(PIN_ENABLER, LOW);
		
		bcm2835_gpio_write(PIN_AR, right & 0x0001);
		bcm2835_gpio_write(PIN_BR, right & 0x0002);
		bcm2835_gpio_write(PIN_CR, right & 0x0004);
		bcm2835_gpio_write(PIN_S3, right & 0x0008);
		bcm2835_gpio_write(PIN_S4, right & 0x0010);
		
		delay(10);
		
		bcm2835_gpio_write(PIN_AR, right+1 & 0x0001);
		bcm2835_gpio_write(PIN_BR, right+1 & 0x0002);
		bcm2835_gpio_write(PIN_CR, right+1 & 0x0004);
		bcm2835_gpio_write(PIN_S3, right+1 & 0x0008);
		bcm2835_gpio_write(PIN_S4, right+1 & 0x0010);
	}
}
#include "Locate.h"

void LED_INITIAL(void) 
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

void LED_LIGHT(int left,int right)
{
	if(left != -1)
	{
		bcm2835_gpio_write(PIN_ENABLEL, LOW);
		//bcm2835_gpio_write(PIN_ENABLER, HIGH);
		
		bcm2835_gpio_write(PIN_AL, left & 0x0001);
		bcm2835_gpio_write(PIN_BL, left & 0x0002);
		bcm2835_gpio_write(PIN_CL, left & 0x0004);
		bcm2835_gpio_write(PIN_S1, left & 0x0008);
		bcm2835_gpio_write(PIN_S2, left & 0x0010);
		
		delay(10);
		
		bcm2835_gpio_write(PIN_AL, left+1 & 0x0001);
		bcm2835_gpio_write(PIN_BL, left+1 & 0x0002);
		bcm2835_gpio_write(PIN_CL, left+1 & 0x0004);
		bcm2835_gpio_write(PIN_S1, left+1 & 0x0008);
		bcm2835_gpio_write(PIN_S2, left+1 & 0x0010);
	}
	
	if(right != -1)
	{
		//bcm2835_gpio_write(PIN_ENABLEL, HIGH);
		bcm2835_gpio_write(PIN_ENABLER, LOW);
		
		bcm2835_gpio_write(PIN_AR, right & 0x0001);
		bcm2835_gpio_write(PIN_BR, right & 0x0002);
		bcm2835_gpio_write(PIN_CR, right & 0x0004);
		bcm2835_gpio_write(PIN_S3, right & 0x0008);
		bcm2835_gpio_write(PIN_S4, right & 0x0010);
		
		delay(10);
		
		bcm2835_gpio_write(PIN_AR, right+1 & 0x0001);
		bcm2835_gpio_write(PIN_BR, right+1 & 0x0002);
		bcm2835_gpio_write(PIN_CR, right+1 & 0x0004);
		bcm2835_gpio_write(PIN_S3, right+1 & 0x0008);
		bcm2835_gpio_write(PIN_S4, right+1 & 0x0010);
	}
}
