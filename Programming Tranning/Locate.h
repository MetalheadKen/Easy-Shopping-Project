#include <bcm2835.h>

//Define Pin
//RPI_BPLUS_GPIO_J8_PIN = GPIOXX
#define PIN_AL 		RPI_BPLUS_GPIO_J8_29
#define PIN_BL 		RPI_BPLUS_GPIO_J8_31
#define PIN_CL 		RPI_BPLUS_GPIO_J8_33
#define PIN_S1 		RPI_BPLUS_GPIO_J8_35
#define PIN_S2 		RPI_BPLUS_GPIO_J8_37
#define PIN_ENABLEL	RPI_BPLUS_GPIO_J8_38

#define PIN_AR 		RPI_BPLUS_GPIO_J8_16
#define PIN_BR 		RPI_BPLUS_GPIO_J8_18
#define PIN_CR 		RPI_BPLUS_GPIO_J8_22
#define PIN_S3 		RPI_BPLUS_GPIO_J8_24
#define PIN_S4 		RPI_BPLUS_GPIO_J8_26
#define PIN_ENABLER	RPI_BPLUS_GPIO_J8_40

//Define Function
void LED_Initial(void);
void LED_Light(int, int);
char LED_Choose(short, short);
