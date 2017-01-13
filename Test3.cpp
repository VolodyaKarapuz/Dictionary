#include <iostream>
#include <cmath>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <sstream>
#include <fstream>
#include <math.h>
#include <stdlib.h>


using namespace std;



int main (int argc, char* argv[])
{

	FILE *in, *out, *in2;
	char str[50], str2[50];
	char *n, *n1;
	int fl;
	in = fopen ("in.txt","r+");
	out = fopen ("out.txt","r+");
	in2 = fopen ("in2.txt", "r+");

	while (!feof(in))
	{	
		if (fl==1) {fprintf(in2,"%s%s",str,".result\n"); 
		for (int i=0; i<50; i++)
		{
			str[i]=NULL;
			str2[i]=NULL;
		}
		

		fscanf(in,"%s",str);
		while (!feof(out))
		{	
			
			fl=0;
			for (int i=0; i<50; i++)
			{
				str2[i]=NULL;
			}		
			fscanf(out,"%s",str2);
			for (int i=0; i<50; i++) if (str[i]!=str2[i]) fl=1;
			if (fl==0)
				{fprintf(in2,"%s%s",str,"\n"); break;}
	
		}
	}
	
	fclose(in);
	fclose(out);
	fclose(in2);
}
