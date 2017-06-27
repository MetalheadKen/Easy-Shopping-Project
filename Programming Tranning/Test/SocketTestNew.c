#include "Global.h"
 
void Socket(void) {
    int listenSk, cl_sock;
    struct sockaddr_in sk_addr, cl_addr;
    pthread_t thr;
 
    //Create TCP Socket
    listenSk = socket(AF_INET , SOCK_STREAM , 0);
    
    //Initial The Data Structure Of sk_addr
    memset(&sk_addr, '0', sizeof(sk_addr));
    
    if(listenSk == -1)
		printf("Creating Socket Fail.\n");
	else
	{
		//Set Information
		sk_addr.sin_family = AF_INET;
		sk_addr.sin_port = htons(SERVER_PORT);
        sk_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        
        //Bind IP-Address And Port For Socket
        if(bind(listenSk, (struct sockaddr *)&sk_addr, sizeof(sk_addr)) == -1)
			printf("bind fail.\n");
		else
		{
			//Listening
            if(listen(listenSk, SOMAXCONN) == -1)
				printf("Listening fail.\n");
			else
			{
				//Waiting client
                printf("Waiting client conncetâ¦\n");
                
                while(1)
                {
					//Accept client
                    cl_sock = accept(listenSk, NULL, NULL);
                    printf("Client in.\n");
                    
                    //Creating Thread
                    pthread_create(&thr, NULL, ClientCommunication, (void *)cl_sock);
                 }
                 
                 pthread_join(thr, NULL);
			}
		}
	}
	
    printf("Program is end!\n");
}

void *ClientCommunication(void *Arg) {
    int  size;
    char buffer[4096] = {0};
    char number[5]    = {0};    
    int  Client;
    Client = (int *)Arg;
    
    Point start = {0, 0};
    Point end   = {0, 0};
    char  led[LED_COUNT];
    
    memset(led, ERROR, LED_COUNT);
    
    send(Client, "Welcome.\n", 100, 0);
    
    while(1)
    {
        size = recv(Client, buffer, sizeof(buffer), 0);
        buffer[size] = '\0';
		
		printf("size %d\n", size);
		printf("length %d\n", strlen(buffer));
        
        if(size <= 0)
            break;
        else
        {
			printf("%s", buffer);
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
						else if(buffer[i] == '\n')
						{
							number[y] = '\0';
							end.y     = StringToInteger(number);
							break;
						}
						
						number[y++] = buffer[i];
					}
				}
				
				if(buffer[i] == '\n')
					break;
				
				number[y++] = buffer[i];
			}
			
			RoutePlanning(start, end, led);
			while(1)
			for(int i = 0; led[i] != ERROR; i++)
			{
				if(led[i] < 32)
					LED_Light(led[i], -1);
				else
					LED_Light(-1, led[i]);
			}
			
			memset(buffer, 0, sizeof(buffer));
			bcm2835_gpio_write(PIN_ENABLEL, HIGH);
			bcm2835_gpio_write(PIN_ENABLER, HIGH);
		}
	}
	
    printf("Client out.\n");
    //close(Client);
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
