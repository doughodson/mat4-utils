
/*
 * Print contents of matlab version 4 header file
*/

#include <stdio.h>

typedef struct {
   long type;
   long mrows;
   long ncols;
   long imagf;
   long namelen;
} MAT4Header;


int main()
{
   MAT4Header header;

   FILE* fp = fopen("A025001.mat", "r");
   if (fp != NULL) {
      fread(&header, sizeof(MAT4Header), 1, fp);

      printf("type    : %lX\n", header.type);
      printf("mrows   : %ld\n", header.mrows);
      printf("ncols   : %ld\n", header.ncols);
      printf("imagf   : %ld\n", header.imagf);
      printf("namelen : %ld\n", header.namelen);

   } else
      printf("File could not be opened.\n");

   fclose(fp);
   return 0;
}


