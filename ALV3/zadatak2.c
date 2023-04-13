#include <stdio.h>
#include <stdlib.h>

typedef struct Cvor {
    int data;
    struct Cvor* next;
} Cvor;

Cvor* createCvor(int data) {
    Cvor* newCvor = (Cvor*) malloc(sizeof(Cvor));
    if (newCvor == NULL) {
        printf("Greška pri alociranju memorije!\n");
        exit(1);
    }
    newCvor->data = data;
    newCvor->next = NULL;
    return newCvor;
}

void push(Cvor** top, int data) {
    Cvor* newCvor = createCvor(data);
    newCvor->next = *top;
    *top = newCvor;
}

int pop(Cvor** top) {
    if (*top == NULL) {
        printf("Stog je prazan!\n");
        exit(1);
    }
    int data = (*top)->data;
    Cvor* temp = *top;
    *top = (*top)->next;
    free(temp);
    return data;
}

int povrh(int n, int m) {
    Cvor* stog = NULL;
    push(&stog, n);
    push(&stog, m);
    int rezultat = 0;
    while (stog != NULL) {
        m = pop(&stog);
        n = pop(&stog);
        if (n == m || m == 0) {
            rezultat += 1;
        } else {
            push(&stog, n - 1);
            push(&stog, m - 1);
            push(&stog, n - 1);
            push(&stog, m);
        }
    }
    return rezultat;
}

int main() {
    int n = 10;
    int m = n / 2;
    int rezultat = povrh(n, m);
    printf("Rezultat za n=%d i m=%d: %d\n", n, m, rezultat);
    return 0;
}
