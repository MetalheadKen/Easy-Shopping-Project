#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int connfd = 0, n = 0, listenfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;

    char charBuff[1024];
    char recvBuff[1024];
    time_t ticks;

    // init the data structure of serv_addr
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(charBuff, '\0', sizeof(charBuff));
    memset(recvBuff, '\0', sizeof(recvBuff));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(8998);

    // assign the scket port to socket
    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    listen(listenfd, 20);

    while (1)
    {
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);
   
        printf("%s %d \n", "server: connfd is", connfd);
        ticks = time(NULL);
        snprintf(charBuff, sizeof(charBuff), "%s\n", ctime(&ticks));
        printf("server: %s\n", charBuff);
        
        while ( (n = read(connfd, recvBuff, sizeof(recvBuff)-1)) > 0)
        {
           recvBuff[n] = 0;
           printf("server: read %d bytes \n", n);
           printf("server: EOF = %d \n", EOF);
           if ( fputs(recvBuff, stdout) == EOF)
           {
                printf("Error : Fputs error \n");
           }
        }

        if (n < 0)
        {
            printf("Error : read errpr \n");
        }
       //  write(connfd, sendBuff, strlen(sendBuff));
        close(connfd);
        sleep(1); 
    }
}