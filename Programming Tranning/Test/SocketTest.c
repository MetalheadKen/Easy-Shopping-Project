#include "Socket.h"
 
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
                    pthread_create(&thr, NULL, ClientCommunication, cl_sock);
                 }
                 
                 pthread_join(thr, NULL);
			}
		}
	}
	
    printf("Program is end!\n");
}

void ClientCommunication(void* Arg) {
    int  size;
    char buffer[4096] = {0};
    int  Client = (int *)Arg;
    
    send(Client, "Welcome.\n", 100, 0);
    
    while(1)
    {
        size = recv(Client, buffer, sizeof(buffer), 0);
        buffer[size] = '\0';
        
        if(size <= 0)
            break;
        else
        {          
            if(strcmp(buffer , "GO\n") == 0)
            {
				for(int a = 0, b = 0; a < 32; a+=1, b+=1)
				{
					for(int x = 0; x < 10; x++)
						LED_LIGHT(a, b);
				}
				
				bcm2835_gpio_write(PIN_ENABLEL, HIGH);
				bcm2835_gpio_write(PIN_ENABLER, HIGH);
			}
		}
	}   
	
    printf("Client out.\n");
}
