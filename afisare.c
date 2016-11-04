#include"mersul_trenurilor.h"
#include<stdio.h>
FILE *file;
void afisare_matrice_adiacenta()
{
	int i,j;
	file=fopen("localitati_adiacenta.txt","w");
	fprintf(file,"%d",*n_localitati);
    for(i=1;i<=*n_localitati;i++){
        fprintf(file,"\n");
        for(j=1;j<=*n_localitati;j++)
            fprintf(file,"%d ",graf[(i-1)*(*n_localitati)+j]);
    }
    fclose(file);
}

void afisare_vector_orase()
{
	int i;
	file=fopen("orase.txt","w");
	fprintf(file,"%d\n",*n_orase);
    for(i=1;i<=*n_localitati;i++)
        if(orase[i]!=0)
            fprintf(file,"%d ",i);
    fclose(file);
}

void afisare_matrice_distanta()
{
	int i,j;
	file=fopen("localitati_distanta.txt","w");
	fprintf(file,"%d",*n_localitati);
    for(i=1;i<=*n_localitati;i++){
        fprintf(file,"\n");
        for(j=1;j<=*n_localitati;j++)
            fprintf(file,"%d ",graf_distanta[(i-1)*(*n_localitati)+j]);
    }
    fclose(file);
}

void afisare_vector_trenuri()
{
	int i,j;
	file=fopen("trenuri.txt","w");
	fprintf(file,"%d\n",*n_trenuri);
	for(i=1;i<=*n_trenuri;i++){
		fprintf(file,"%d %d ",trenuri[i].id2,trenuri[i].id);
		for(j=1;j<=4;j++)
			fprintf(file,"%d ",trenuri[i].tip[j]);
		fprintf(file,"%d %d %d ",trenuri[i].viteza,trenuri[i].distanta_totala,trenuri[i].n_traseu);
		for(j=1;j<=trenuri[i].n_traseu;j++)
			fprintf(file,"%d ",trenuri[i].traseu[j]);
		fprintf(file,"%d %d",trenuri[i].timp[1],trenuri[i].timp[2]);
		for(j=1;j<=7;j++)
			fprintf(file," %d",trenuri[i].zile[j]);
		fprintf(file,"\n");
	}
	fclose(file);
}

void afisare_tot()
{
	afisare_matrice_adiacenta();
    afisare_vector_orase();
    afisare_matrice_distanta();
    afisare_vector_trenuri();
}
