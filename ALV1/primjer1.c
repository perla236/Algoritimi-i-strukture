#include<time.h>
#include<stdlib.h>
#include<stdio.h>

void gen_arr (float V[], int n, int dg, int gg){
    int i=0;
    for(i = 0; i<n; i++){

        V[i]= rand() % (gg + 1 - dg) + dg;
    
    }


}


int sekv_pret (float V[], int n, float x ){
    
    int i= 0, flag;
    for(i=0;i<n;i++)
	{
		if(x==V[i])
			flag=1;
    }
	if(flag==1)
		printf("\nBroj %f postoji", x);
    
	else
printf("\nBroj %f ne postoji", x);
	
    return -1;
}


void sort(float V[], int n){
 int i, j, temp;
 for(i=0;i< n-1;i++)
 {
  for(j=i+1;j< n;j++)
  {
   if(V[i]>V[j])
   {
    temp = V[i];
    V[i] = V[j];
    V[j] = temp;
   }
  }
 }

    
}


void ispis(float V[], int n){
    printf("\n");
   int i;
    for (i = 0; i < n; i++)
        printf("%f ", V[i]);
    printf("\n");
    
    
}






int bin_pret(float V[], int n, float x) {
    int lijevo = 0, desno = n - 1;
    while (lijevo <= desno) {
        int sredina = (lijevo + desno) / 2;
        if (V[sredina] < x)
            lijevo = sredina + 1;
    else if (V[sredina] > x)
            desno = sredina - 1;
    else
        return sredina;
}
return -1;
}


int main()
{
time_t t1, t2, t3, t4, t5;
float V[10];
int n = 10;
float x = 13;
t1 = clock();
gen_arr(V,n,0,200);
t2 = clock();
sekv_pret (V,n,x);
t3 = clock();
sort(V,n);
t4 = clock();
bin_pret( V,n,x);
t5 = clock();
ispis(V,n);




printf( "Vrijeme trajanja gen_arr je %dms\n",t2-t1 );
printf( "Vrijeme trajanja sekv_pret je %dms\n",t3-t1 );
printf( "Vrijeme trajanja sort je %dms\n",t4-t1 );
printf( "Vrijeme trajanja bin_pret je %dms\n",t5-t1 );




    return 0;
}
