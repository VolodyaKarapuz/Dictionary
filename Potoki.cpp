#include <iostream>
#include <cmath>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <sstream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <thread>
#include <mutex>
#include <unistd.h> 


using namespace std;



void bar (mutex& mtx, FILE* in2, FILE* out, FILE *in)
{
	char str[50], str2[50];
	int fl=0;

	while (!feof(in))
	{
		if (fl==1) fprintf(in2,"%s%s",str,".result\n");
		for (int i=0; i<50; i++)
		{
			str[i]=NULL;
			str2[i]=NULL;
		}

		fscanf(in,"%s",str);
		mtx.lock();
		out = fopen ("out.txt","r+");
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
		fclose(out);
		cout << "POTOK1"<< endl;
		mtx.unlock();
		usleep(50000);
	}
}

void foo (mutex& mtx, FILE *in3, FILE *out, FILE *in4)
{
	
	char str[50], str2[50];
	int fl=0;

	while (!feof(in3))
	{
		if (fl==1) fprintf(in4,"%s%s",str,".result\n");
		for (int i=0; i<50; i++)
		{
			str[i]=NULL;
			str2[i]=NULL;
		}

		fscanf(in3,"%s",str);
		mtx.lock();
		out = fopen ("out.txt","r+");
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
			{fprintf(in4,"%s%s",str,"\n"); break;}
		}
		fclose(out);
		cout << "POTOK2"<< endl;
		mtx.unlock();
		usleep(50000);
	}			
	
}


int main (int argc, char* argv[])
{
	mutex mtx;
	
	FILE *in, *out, *in2, *in3, *in4;
	char str[50], str2[50];
	char *n, *n1;
	int fl=0;
	in = fopen ("in.txt","r+");
	out = fopen ("out.txt","r+");
	in2 = fopen ("in2.txt", "r+");
	in3 = fopen ("in3.txt", "r+");
	in4 = fopen ("in4.txt", "r+");


	thread t1 (foo, ref(mtx), ref(in), ref(out), ref(in2));
	thread t2 (bar, ref(mtx), ref(in3), ref(out), ref(in4));

	t1.join();
	t2.join();
	fclose(in);
	fclose(in2);
	fclose(out);
	fclose(in3);
	fclose(in4);
}




