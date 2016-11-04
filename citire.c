#include"mersul_trenurilor.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
FILE *file;

void citire_matrice_adiacenta()
{
	int i,j;
	file=fopen("localitati_adiacenta.txt","r");
	n_localitati=malloc(sizeof(int));
	fscanf(file,"%d",n_localitati);
	graf=malloc((*n_localitati+1)*(*n_localitati+1)*sizeof(int));
    for(i=1;i<=*n_localitati;i++){
        for(j=1;j<=*n_localitati;j++)
            fscanf(file,"%d",graf+(i-1)*(*n_localitati)+j);
    }
    fclose(file);

}


void citire_vector_orase()
{
	int i,x;
	file=fopen("orase.txt","r");
	n_orase=malloc(sizeof(int));
	fscanf(file,"%d",n_orase);
	orase=malloc((*n_localitati+1)*sizeof(int));
	for(i=1;i<=*n_localitati;i++)
		orase[i]=0;
    for(i=1;i<=*n_localitati;i++){
		fscanf(file,"%d",&x);
		orase[x]=1;
	}
    fclose(file);
}

void citire_matrice_distanta()
{
	int i,j;
	file=fopen("localitati_distanta.txt","r");
	n_localitati=malloc(sizeof(int));
	fscanf(file,"%d",n_localitati);
	graf_distanta=malloc((*n_localitati+1)*(*n_localitati+1)*sizeof(int));
    for(i=1;i<=*n_localitati;i++){
        for(j=1;j<=*n_localitati;j++)
            fscanf(file,"%d",graf_distanta+(i-1)*(*n_localitati)+j);
    }
    fclose(file);
}

void citire_vector_trenuri()
{
	int i,j;
	file=fopen("trenuri.txt","r");
	n_trenuri=malloc(sizeof(int));
	fscanf(file,"%d",n_trenuri);
	trenuri=malloc((*n_trenuri+1)*sizeof(struct tren));
	for(i=1;i<=*n_trenuri;i++){
		fscanf(file,"%d%d",&trenuri[i].id2,&trenuri[i].id);
		for(j=1;j<=4;j++)
			fscanf(file,"%d",trenuri[i].tip+j);
		fscanf(file,"%d%d%d",&trenuri[i].viteza,&trenuri[i].distanta_totala,&trenuri[i].n_traseu);
		trenuri[i].traseu=malloc((trenuri[i].n_traseu+1)*sizeof(int));
		for(j=1;j<=trenuri[i].n_traseu;j++)
			fscanf(file,"%d",trenuri[i].traseu+j);
		fscanf(file,"%d%d",&trenuri[i].timp[1],&trenuri[i].timp[2]);
		for(j=1;j<=7;j++)
			fscanf(file,"%d",&trenuri[i].zile[j]);
	}
	fclose(file);
}

void citire_tot()
{
	citire_matrice_adiacenta();
    citire_vector_orase();
    citire_matrice_distanta();
    citire_vector_trenuri();
}
