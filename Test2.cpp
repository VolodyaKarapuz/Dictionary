#include <stdio.h>  //Äëÿ printf, fgets, fopen, fclose, feof

int main ()
{  
  
   FILE *inA, *inB;
   char str[50];
   char *estr;
   inA = fopen ("in.txt","r");
   inB = fopen ("in2.txt","w");
  
   while (!feof(inA))
   {
	   estr = fgets (str,sizeof(str),inA);
	   fprintf(inB,estr);
   }
   fclose(inA);
   fclose(inB);
   
   
   return 0;

} 
