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

    

    return 0;
}




