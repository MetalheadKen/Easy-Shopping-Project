#include "Global.h"
 
void Socket(void) {
    int listenSk, cl_sock;
    struct sockaddr_in sk_addr;
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
    byte buffer[4096] = {0};
    int  Client = (int *)Arg;
    
    Point start = {0, 0};
    Point end   = {0, 0};
    byte  led[LED_COUNT];
    
    memset(led, ERROR, LED_COUNT);
    
    while(1)
    {
        size = recv(Client, buffer, sizeof(buffer), 0);
        buffer[size] = '\0';
        
        //printf("size %d\n", size);
        //printf("length %d\n", strlen(buffer));
        
        if(size <= 0)
        {
			break;
		}
        else
        {
            printf("%s", buffer);
            
            /* Divide The String To Array Coordinate */
            sscanf(buffer, "%hd,%hd %hd,%hd", &start.x, &start.y, &end.x, &end.y);

            /* Send Route To Client */
            if(!RoutePlanning(start, end, led))
            {				
				short i;
				char route[LED_COUNT] = {0};
				
				for(i = 0; led[i] != ERROR; i++)
					route[i] = led[i] + 0x30;
				
				route[i] = '\n';
				
				send(Client, route, strlen(route), 0);
			}
            
            /* Light The Two LED Of Route */
            for(int i = 0, count = 0; led[i] != ERROR && count < 3; i++)
            {
				if(led[i] == ROUTE) continue;
								
                if(led[i] < 32)
                    LED_Light(led[i], -1);
                else
                    LED_Light(-1, led[i]);
                    
                count++;
            }
            
            /* Reset All Variable */
            memset(led, ERROR, LED_COUNT);
            memset(buffer, 0, sizeof(buffer));
            bcm2835_gpio_write(PIN_ENABLEL, HIGH);
            bcm2835_gpio_write(PIN_ENABLER, HIGH);
        }
    }
    
    printf("Client out.\n");
    
    return NULL;
}
