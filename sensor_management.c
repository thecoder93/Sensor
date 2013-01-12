#include <stdio.h>
#include <time.h>

int main()
{
  FILE *f;
	int a = 0;
	int x[10];
	int i=0;
	//Controllo soglia
	for(i=0; i<10; i++)
	{
		f = fopen("/sys/devices/platform/tsc/ain2", "r");	
		if (f == NULL) 
			printf("Errore nell'apertura del file");
		else
		{
			sleep(1);
			fscanf(f, "%d", &x[i]);
			printf("%d\n", x[i]);
			if (i==0)
				a=x[i];
			else if (a<x[i])
				a=x[i];
		}	
		fclose(f);
	}
	printf("\n\nValore maggiore : %d\n", a);
	while(1)
	{
		int valore = 0;
		f = fopen("/sys/devices/platform/tsc/ain2", "r");
		if (f == NULL) 
			printf("Errore nell'apertura del file");
		else
		{
			fscanf(f, "%d", &valore);
			if (valore > a)
			{
				//Fai accadere qualcosa
				sleep(1);
			}
		}
		fclose(f);
	}	
}
