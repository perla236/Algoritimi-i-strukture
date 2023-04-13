#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cvor {
    char slovo;
    struct cvor* lijevo;
    struct cvor* desno;
};

void dodajP(struct cvor** root, char slovo) {
    if (*root == NULL) {
        *root = (struct cvor*) malloc(sizeof(struct cvor));
        (*root)->slovo = slovo;
        (*root)->lijevo = NULL;
        (*root)->desno = NULL;
    } else {
        if (slovo < (*root)->slovo) {
            dodajP(&((*root)->lijevo), slovo);
        } else if (slovo > (*root)->slovo) {
            dodajP(&((*root)->desno), slovo);
        }
    }
}

void NLD(struct cvor* root) {
    if (root != NULL) {
        printf("%c ", root->slovo);
        NLD(root->lijevo);
        NLD(root->desno);
    }
}

void LND(struct cvor* root) {
    if (root != NULL) {
        LND(root->lijevo);
        printf("%c ", root->slovo);
        LND(root->desno);
    }
}

void LDN(struct cvor* root) {
    if (root != NULL) {
        LDN(root->lijevo);
        LDN(root->desno);
        printf("%c ", root->slovo);
    }
}

void printStabloLND(struct cvor* root, int razina) {
    if (root == NULL) {
        return;
    }
    
    printStabloLND(root->desno, razina + 1);

    for (int i = 0; i < razina; i++) {
        printf("    ");
    }
    
    printf("%c\n", root->slovo);

    printStabloLND(root->lijevo, razina + 1);
}


int main() {
    char ime_prezime[] = "Lovro Perlic";
    int n = strlen(ime_prezime);
    struct cvor* root = NULL;

    for (int i = 0; i < n; i++) {
        dodajP(&root, ime_prezime[i]);
    }

    printf("NLD: ");
    NLD(root);
    printf("\n");

    printf("LND: ");
    LND(root);
    printf("\n");

    printf("LDN: ");
    LDN(root);
    printf("\n");

    printStabloLND(root, 1);
    return 0;
}



