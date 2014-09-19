/* udpServer.c */

/* Converted to echo client/server with select() (timeout option). See udpClient.c */
/* 3/30/05 John Schultz */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <time.h>


#define LOCAL_SERVER_PORT 9699
#define MAX_MSG 60000

int main(int argc, char *argv[])
{
   int sd=socket(AF_INET, SOCK_DGRAM, 0);
   if(sd<0) 
   {
      printf("%s: cannot open socket \n",argv[0]);
      exit(1);
   }

   struct sockaddr_in servAddr;
   servAddr.sin_family = AF_INET;
   servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
   servAddr.sin_port = htons(LOCAL_SERVER_PORT);
   int rc = bind (sd, (struct sockaddr *) &servAddr,sizeof(servAddr));
   if(rc<0) 
   {
      printf("%s: cannot bind port number %d \n",argv[0], LOCAL_SERVER_PORT); 
      exit(1);
   }

   time_t rawtime;
   char fbuff[128];   
   char msg[MAX_MSG];
   int flags = 0;

   struct sockaddr_in cliAddr;
   socklen_t cliLen = sizeof(cliAddr);

   memset(msg,0x0,MAX_MSG);

   while (true)
   {
      printf("%s: waiting for data on port UDP %u\n",  argv[0],LOCAL_SERVER_PORT);

      int n = recvfrom(sd, msg, MAX_MSG, flags, (struct sockaddr *) &cliAddr, &cliLen);  
      time ( &rawtime );
 
      if(n<0)
      { 
         snprintf(fbuff, sizeof(fbuff), "/home/alja/fireworks/crashes/fail_%d", rawtime );
         FILE* repFile = fopen(fbuff, "w");
         fclose(repFile);
      }
      else
      {      
         snprintf(fbuff, sizeof(fbuff), "/home/alja/fireworks/crashes/crashReport_%d_%s.gz", rawtime , inet_ntoa(cliAddr.sin_addr));
         // mkdir log printf("writing to %s ...\n", &fbuff[0] );
         FILE* repFile = fopen(fbuff, "w");
         fwrite(msg, n, 1, repFile);
         fclose(repFile);
      }
   }

   return 0;
}
