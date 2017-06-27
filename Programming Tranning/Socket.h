#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <string.h>

#define SERVER_PORT 8998

void  Socket(void);
void  *ClientCommunication(void* Arg);
