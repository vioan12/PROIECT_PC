CC=gcc
CFLAGS = -c -std=c99 -Wall

all: Trenuri

Trenuri: main.o citire.o afisare.o generare.o control_variabile.o algoritmi_prelucrare_graf.o
	$(CC) main.o citire.o afisare.o generare.o control_variabile.o algoritmi_prelucrare_graf.o -o Trenuri #linking

main.o: main.c
	$(CC) $(CFLAGS) main.c #compile

citire.o: citire.c
	$(CC) $(CFLAGS) citire.c #compile

afisare.o: afisare.c
	$(CC) $(CFLAGS) afisare.c #compile
	
generare.o: generare.c
	$(CC) $(CFLAGS) generare.c #compile
	
control_variabile.o: control_variabile.c
	$(CC) $(CFLAGS) control_variabile.c #compile
	
algoritmi_prelucrare_graf.o: algoritmi_prelucrare_graf.c
	$(CC) $(CFLAGS) algoritmi_prelucrare_graf.c #compile

clean:
	rm -f *o

#%: %.c; = tab space
#gcc main.c citire.c afisare.c generare.c control_variabile.c algoritmi_prelucrare_graf.c -o Trenuri

