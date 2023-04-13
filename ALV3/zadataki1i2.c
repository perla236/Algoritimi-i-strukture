#include <stdio.h>
#include <time.h>
#include <stdlib.h>



int povrhRek(int n, int m) {
    
    if (n == m || m == 0) {
        return 1;
    } else {
        return povrhRek(n-1, m-1) + povrhRek(n-1, m);
    }
}


int povrhStog(int n, int m) {
    
    int stog[n+1];
    stog[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j > 0; j--) {
            if (j == i) {
                stog[j] = 1;
            } else {
                stog[j] = stog[j] + stog[j-1];
            }
        }
    }
    return stog[m];
}



//Drugi zad
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

int povrhStogPP(int n, int m) {
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






int main(int argc, char const *argv[])
{
    int n = 10;
    int m = n/2;
    int rez;
    clock_t start, stop;
    start = clock();
    rez = povrhRek(n,m);
    stop = clock();

    printf("Vrijeme rekurzije je %dms\n", (stop - start));
    printf("Rezultat rekurzije je %d\n", rez);


    start = clock();
    rez = povrhStog(n,m);
    stop = clock();
    
    printf("Vrijeme stoga je %dms\n", (stop - start));
    printf("Rezultat stoga je %d\n", rez);

    //Drugi zad
    start = clock();
    rez = povrhStogPP(n,m);
    stop = clock();
    
    printf("Vrijeme stoga PP je %dms\n", (stop - start));
    printf("Rezultat stoga PP je %d\n", rez);

    return 0;
}




