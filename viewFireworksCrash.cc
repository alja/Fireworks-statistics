#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include "zlib.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <iostream>

#define BUFLEN 60000



int main(int argc, char **argv)
{
   const char* fname = argv[1];
   FILE* pFile = fopen ( fname , "r" );
   if ( pFile==NULL )  { std::cerr << "Can't open " << fname << std::endl; exit(1); }

   // obtain file size:
   fseek (pFile , 0 , SEEK_END);
   unsigned int lSize = ftell (pFile);
   rewind (pFile);

   // allocate memory to contain the whole file:
   void* source1 = malloc (sizeof(Bytef)*(lSize));
   size_t result = fread (source1, 1, lSize ,pFile);
   char* source = (char*) source1; source += 4;

   unsigned int* ds = (unsigned int*) source;

   uLongf destLen =lSize*100; 
   void* dest = malloc (sizeof(Bytef)*(destLen));
   int res = uncompress((Bytef*)dest, &destLen, (Bytef*)source, lSize);

   if ( res == Z_MEM_ERROR )
      printf("AMT data error \n");

   //if ( res == Z_OK )
   //  printf("OK !!!!\n");

   if ( res == Z_MEM_ERROR )
      printf("AMT meme errr \n"); 

   printf("%s \n", dest);

   fclose(pFile);
   if ( !result ) { std::cerr << "Failed to read " << fname <<std::endl; exit(1); }
}
