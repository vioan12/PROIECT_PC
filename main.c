#include"mersul_trenurilor.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x,ok,i;
	char c[10];
	ok=0;
	printf("\n1)Generare tot\n2)Citire fisiere\n3)Afisare\n4)Golire variabile\n5)Golire variabile2\n6)Dijkstra\n77)Reafisare meniu\n8)Iesire\n");
	do{
		printf("\nIntroduceti optinuea dorita:"); scanf("%s",c);
		switch_etch:
		x=chartoint(c);
		switch(x){
			case 1:
				initializare_rand();
				generare_tot();
				printf("Succes!\n");
				break;
			case 2:
				citire_tot();
				printf("Succes!\n");
				break;
			case 3:
				afisare_tot();
				printf("Succes!\n");
				break;
			case 4:
				curatare_variabile();
				printf("Succes!\n");
				break;
			case 5:
				curatare_variabile2();
				printf("Succes!\n");
				break;
			case 6:
				dijkstra(5);
				printf("Succes!\n");
				printf("Tata:\n");
				for(i=1;i<=*n_localitati;i++)
					printf("%d ",tata[(i-1)*(*n_localitati)]);
				printf("\nDistanta:\n");
				for(i=1;i<=*n_localitati;i++)
					printf("%d ",distanta[(i-1)*(*n_localitati)]);
				printf("\n");
				break;
			case 7:
				printf("\n1)Generare tot\n2)Citire fisiere\n3)Afisare\n4)Golire variabile\n5)Golire variabile2\n6)Dijkstra\n77)Reafisare meniu\n8)Iesire\n");
				break;
			case 8:
				ok=1;
				printf("Iesire.\n");
				break;
			default:
				printf("Ati introdus o optiune %d inexistenta, reintroduceti alta optiune:",x); scanf("%s",c);
				goto switch_etch;
		}
	}while(ok==0);
	return 0;
}
