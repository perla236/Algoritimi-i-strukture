#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct cvor {
    int podatak;
    struct cvor *sljedeci;
} cvor;

int main() {
    long long int i = 0;
    cvor *glava, *trenutni, *privremeni;
    glava = trenutni = privremeni = NULL;
    while (1) {
        privremeni = (cvor*)malloc(sizeof(cvor));
        if (privremeni == NULL) {
            printf("Maksimalni broj cvorova: %lld\n", i-1);
            break;
        }
        if (glava == NULL) {
            glava = privremeni;
            trenutni = privremeni;
        }
        else {
            trenutni->sljedeci = privremeni;
            trenutni = privremeni;
        }
        i++;
    }
    while (glava != NULL) {
        trenutni = glava;
        glava = glava->sljedeci;
        free(trenutni);
    }
    return 0;
}
