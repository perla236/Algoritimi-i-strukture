#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct OE_ OE;

struct OE_ {
    int x;
    OE* sljedeci;
};

int main() {
    // Generiraj niz slučajnih brojeva
    int n = 1000000;
    clock_t pocetak, kraj;
    pocetak = clock();
    int* niz = malloc(sizeof(int) * n);
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        niz[i] = rand() % (200 + 1 - 0) + 0;
    }
    kraj = clock();
    printf("Trajanje formiranja niza: %d ms\n", (kraj - pocetak));


    // Kreiraj povezani popis od niza
    pocetak = clock();
    OE* prvi = NULL;
    for (int i = n-1; i >= 0; i--) {
        OE* novi = malloc(sizeof(OE));
        novi->x = niz[i];
        novi->sljedeci = prvi;
        prvi = novi;
    }
    kraj = clock();

    printf("Trajanje formiranja povezanog popisa: %d ms\n", (kraj - pocetak));



    // Testiraj sekvencijalno pretraživanje na nizu
    pocetak = clock();
    int trazeni = 236;
    for (int i = 0; i < n; i++) {
        if (niz[i] == trazeni) {
            printf("Pronadjen na indeksu %d\n", i);
            break;
        }
        //else printf("Nije pronadjen trazeni broj sekv_pret_niza\n"); break;
    }
    kraj = clock();
    printf("Trajanje pretrazivanja na nizu: %d ms\n", (kraj - pocetak));

    // Testiraj sekvencijalno pretraživanje na povezanom popisu
    pocetak = clock();
    OE* trenutni = prvi;
    while (trenutni != NULL) {
        if (trenutni->x == trazeni) {
            printf("Pronadjen\n");
            break;
        }
        //else printf("Nije pronadjen trazeni broj na sekv_pret_pp\n"); break;
        trenutni = trenutni->sljedeci;
    }
    kraj = clock();
    printf("Trajanje pretrazivanja na povezanom popisu: %d ms\n", (kraj - pocetak));

    // Oslobodi memoriju
    free(niz);
    while (prvi != NULL) {
        OE* trenutni = prvi;
        prvi = prvi->sljedeci;
        free(trenutni);
    }

    return 0;
}
