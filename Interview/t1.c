#include <stdio.h>
int main()
{
   FILE *fp;

   fp = fopen("test.txt", "r+");
   fprintf(fp, "This is testdlmsfmkmdkfming for fprintf...\n");
   fputs("This is testing for fputs...\n", fp);
   fclose(fp);
}
