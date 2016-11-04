#include"mersul_trenurilor.h"
#include<stdlib.h>
#include<string.h>
#define NR_OPTIUNI_MENIU 8
void curatare_variabile()
{
	free(trenuri);
	free(graf);
	free(graf_distanta);
	free(orase);
	free(n_localitati);
	free(n_orase);
	free(n_trenuri);
}

int nr_cifre_nr_optiuni_meniu();

int chartoint(char c[])
{
	char d;
	int x;
	d=c[0];
	if(strlen(c)>nr_cifre_nr_optiuni_meniu())
		return -1;
	else{
		x=d;
		x=x-48;
		if(x>NR_OPTIUNI_MENIU)
			return -2;
		if(x!=0)
			return x;
		}
	return -3;
}

void curatare_variabile2()
{
	free(distanta);
	free(tata);
	free(harta);
}

int nr_cifre_nr_optiuni_meniu()
{
	int x,nr;
	x=NR_OPTIUNI_MENIU;
	nr=0;
	while(x!=0){
		nr++;
		x=x/10;
	}
	return nr;
}
