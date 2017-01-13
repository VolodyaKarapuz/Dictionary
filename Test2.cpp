#include < stdio.h >  //Äëÿ printf, fgets, fopen, fclose, feof

int main ()
{  
  
   FILE *mf;
   char str[50];
   char *estr;
   mf = fopen (“test.txt”,”r+”);
   estr = fgets (str,sizeof(str),mf);
   fclose(mf);
   
   
   return 0;

} 
