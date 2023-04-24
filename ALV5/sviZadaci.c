#include <stdio.h>
#include <stdlib.h>
#include <time.h>


    void heapify(int *arr, int n, int i ){
        int najveci = i;
        int lijevi = 2 * i + 1;
        int desni = 2 * i +2;

        if (lijevi < n && arr[lijevi] > arr[najveci] ){
            najveci = lijevi;
        }

        if (desni < n && arr[desni] > arr[najveci]){
            najveci = desni;
        }

        if (najveci != i){
            int temp = arr[i];
            arr[najveci] = temp;
            heapify(arr, n, najveci);
        }
    }

    void heapSort(int *arr, int n){
        for(int i = n/2 - 1; i >= 0; i-- ){
            heapify(arr, n, i);
        }
    

        for(int i = n - 1; i > 0; i--){
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            heapify(arr, i, 0);
        }

    }

    void bubbleSort(int *arr, int n){
        int zamjena;
        for (int i= 0; i < n-1; i++){
            zamjena = 0;
            for (int j = 0; i < n- i - 1; i++)
            {
                if (arr[j] > arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    zamjena = 1;
                }
            }
            if(zamjena == 0){
                break;
            }
        } 

    }


    void merge(int *arr, int l, int m, int r){
        int i,j,k;
        int n1 = m-l +1;
        int n2 = r-m;
        int L[n1], R[n2];

        for(i = 0; i < n1; i++){
            L[i] = arr[l+i];
        }

        for(j = 0; j< n2; j++){
            R[j] = arr[m + 1 + j];
        }
        i = 0;
        j = 0;
        k = l;

        while( i < n1 && j < n2){
            if(L[i] <= R[j]){
                arr[k] = L[i];
                i++;
            }

            else{
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while(i < n1){
            arr[k] = L[i];
            i++;
            k++;
        }
    
        while(j < n2){
            arr[k] = R[j];
            j++;
            k++;
        }
    
    }


    void mergeSort(int *arr, int l, int r){
        if(l<r){
            int m = l + (r - l) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r);        
        }
    }



    int main()
    {
        srand(time(NULL));
        clock_t start,stop;
        
        int n = 100000;
        int *arr = (int*) malloc(n * sizeof(int));
        int arr2[10] = {12, 5, 4, 10, 7, 8, 11, 3, 6, 1};
        for(int i = 0; i < n; i++){
            arr[i]= rand() % 100000;
        }
        
        start = clock();
        heapSort(arr, n);
        stop = clock();
        printf("Vrijeme izvodjenja heap sorta: %ld s\n", (stop - start));

        start = clock();
        bubbleSort(arr, n);
        stop = clock();
        printf("Vrijeme izvodjenja bubble sorta: %ld s\n", (stop - start));

        start = clock();
        mergeSort(arr, 0, n - 1);
        stop = clock();
        printf("Vrijeme izvodjenja merge sorta: %ld s\n", (stop - start));

        free(arr);
        

        return 0;
    }
    