#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"mersul_trenurilor.h"
#define MAX_NR_LOCALITATI 200
#define MIN_NR_LOCALITATI 70
#define MAX_NR_ORASE 60
#define MIN_NR_ORASE 50
#define MAX_DISTANTA 300
#define MIN_DISTANTA 20
#define MAX_NR_TRENURI 220
#define MIN_NR_TRENURI 100
#define MAX_DISTANTA_TRENURI 70
#define MIN_DISTANTA_TRENURI 20
#define MAX_DISTANTA_TRENURI_DORMIT 40
#define VITEZA_TREN1 30
#define VITEZA_TREN2 55
#define VITEZA_TREN3 90
#define VITEZA_TREN4 125
#define NR_MUCHII 3//x% din nr total de muchii
#define INFINIT 500000
void initializare_rand(){
	srand(time(NULL));
}

void generare_matrice_adiacenta()
{
    int i,n,m;
    n_localitati=malloc(sizeof(int));
    *n_localitati=rand()%(MAX_NR_LOCALITATI-MIN_NR_LOCALITATI);
    *n_localitati+=MIN_NR_LOCALITATI;
    graf=malloc((*n_localitati+1)*(*n_localitati+1)*sizeof(int));
    for(i=1;i<=*n_localitati*(*n_localitati);i++)
        graf[i]=0;
    for(i=1;i<=*n_localitati*(*n_localitati-1)/2*NR_MUCHII/100;i++){
        n=rand()%(*n_localitati)+1;
        m=rand()%(*n_localitati)+1;
        if(n!=m)
            graf[(n-1)*(*n_localitati)+m]=graf[(m-1)*(*n_localitati)+n]=1;
    }


}

void generare_vector_orase()
{
    int i,x;
    n_orase=malloc(sizeof(int));
    *n_orase=rand()%(MAX_NR_ORASE-MIN_NR_ORASE);
    *n_orase+=MIN_NR_ORASE;
    orase=malloc((*n_localitati+1)*sizeof(int));
    for(i=1;i<=*n_localitati;i++)
            orase[i]=0;
    for(i=1;i<=*n_orase;i++){
		do{
        x=rand()%(*n_localitati)+1;
		}while(orase[x]==1);
        orase[x]=1;
    }
}

void generare_matrice_distanta()
{
    int i,j,x;
    graf_distanta=malloc((*n_localitati+1)*(*n_localitati+1)*sizeof(int));
    for(i=1;i<=*n_localitati;i++)
        for(j=1;j<=*n_localitati;j++){
            graf_distanta[(i-1)*(*n_localitati)+j]=graf[(i-1)*(*n_localitati)+j];
            if(graf[(i-1)*(*n_localitati)+j]==1){
               x=rand()%(MAX_DISTANTA-MIN_DISTANTA);
               x+=MIN_DISTANTA;
               graf_distanta[(i-1)*(*n_localitati)+j]=x;
               graf_distanta[(j-1)*(*n_localitati)+i]=x;
            }
            if(graf_distanta[(i-1)*(*n_localitati)+j]==0 && i!=j)
				graf_distanta[(i-1)*(*n_localitati)+j]=INFINIT;
        }
}

int alegere_nod(int x)
{
	int k,n_v,*v,y;
	n_v=0;
	v=malloc((*n_localitati+1)*sizeof(int));
	for(k=1;k<=*n_localitati;k++)
		if( (graf[(x-1)*(*n_localitati)+k]==1) && (graf[(k-1)*(*n_localitati)+x]==1) ){
			n_v+=1;
			v[n_v]=k;
		}
	if(n_v!=0){
		y=rand()%n_v+1;
		k=v[y];
	}
	else
		k=0;
	return k;
}

int alegere_nod2(int *v,int n,int x)
{
	int i;
	for(i=1;i<=n;i++)
		if(x==v[n])
			return 0;
	return 1;
}
void generare_vector_trenuri()
{
    int i,distantatren,x,j,y;
    n_trenuri=malloc(sizeof(int));
    *n_trenuri=rand()%(MAX_NR_TRENURI-MIN_NR_TRENURI);
    *n_trenuri+=MIN_NR_TRENURI;
    trenuri=malloc((*n_trenuri+1)*sizeof(struct tren));
    for(i=1;i<=*n_trenuri;i++){
        distantatren=rand()%(MAX_DISTANTA_TRENURI-MIN_DISTANTA_TRENURI);
        distantatren+=MIN_DISTANTA_TRENURI;
        trenuri[i].n_traseu=distantatren;
        trenuri[i].id=(rand()%1001)+9000;
        x=rand()%2;
        if(x==1){
			trenuri[i].id-=8000;
			trenuri[i].id2=1;
            trenuri[i].tip[1]=1;
            trenuri[i].tip[2]=1;
            trenuri[i].tip[3]=1;
            trenuri[i].viteza=VITEZA_TREN3;
            trenuri[i].tip[4]=0;
            if(distantatren>=MAX_DISTANTA_TRENURI_DORMIT){
                trenuri[i].tip[4]=1;
                trenuri[i].viteza=VITEZA_TREN4;
			}
        }
        if(x==0){
			trenuri[i].id2=0;
			y=rand()%2;
            trenuri[i].tip[1]=y;
            trenuri[i].tip[2]=1;
            trenuri[i].tip[3]=0;
            trenuri[i].tip[4]=0;
            if(y==1)
				trenuri[i].viteza=VITEZA_TREN2;
			else
				trenuri[i].viteza=VITEZA_TREN1;
        }
        for(j=1;j<=7;j++)
			trenuri[i].zile[j]=rand()%2;
		trenuri[i].timp[1]=rand()%24;
		trenuri[i].timp[2]=rand()%60;
		trenuri[i].traseu=malloc((distantatren+1)*sizeof(int));
		trenuri[i].distanta_totala=0;
		for(j=1;j<distantatren;j++){
			if(j==1){
				x=rand()%(*n_localitati)+1;
				y=alegere_nod(x);
				while(y==0){
					x=rand()%(*n_localitati)+1;
					y=alegere_nod(x);
				}
				trenuri[i].traseu[j]=x;
				trenuri[i].traseu[j+1]=y;
				trenuri[i].distanta_totala+=graf_distanta[(trenuri[i].traseu[j]-1)*(*n_localitati)+trenuri[i].traseu[j+1]];
			}else{
				do{
					x=alegere_nod(trenuri[i].traseu[j]);
				}while(alegere_nod2(trenuri[i].traseu,j,x)==0);
				if(x!=0){
					trenuri[i].traseu[j+1]=x;
					trenuri[i].distanta_totala+=graf_distanta[(trenuri[i].traseu[j]-1)*(*n_localitati)+trenuri[i].traseu[j+1]];
				}else{
					distantatren=j;
					trenuri[i].n_traseu=distantatren;
				}
			}
		}

	}
}

void generare_tot()
{
	generare_matrice_adiacenta();
	generare_vector_orase();
	generare_matrice_distanta();
	generare_vector_trenuri();
}

