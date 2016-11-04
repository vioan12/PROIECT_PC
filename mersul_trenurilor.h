struct tren{
    int id;
    int id2;
    int tip[5];
    int *traseu;
    int n_traseu;
    int viteza; //km\h
    int zile[8];
    int timp[3];
    int distanta_totala;
} *trenuri;

int *tata,*distanta,*harta;
int *graf,*orase,*graf_distanta;

int *n_localitati,*n_orase,*n_trenuri;

void generare_matrice_adiacenta();
void afisare_matrice_adiacenta();
void citire_matrice_adiacenta();

void generare_vector_orase();
void afisare_vector_orase();
void citire_vector_orase();

void generare_matrice_distanta();
void afisare_matrice_distanta();
void citire_matrice_distanta();

void generare_vector_trenuri();
void afisare_vector_trenuri();
void citire_vector_trenuri();

void initializare_rand();
void generare_tot();
void afisare_tot();
void citire_tot();
void curatare_variabile();
void curatare_variabile2();
int chartoint(char []);
void dijkstra(int );
