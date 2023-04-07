#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define M 7


int main(){
/*int i,j;
int mt[N][M], *punt=mt;

for(i = 0;i<N; i++)
{
    for(j = 0;j<M; j++)
    {
        punt[i][j]=1+rand()%100;
        printf("%lf", punt[i][j]);
    }
    printf("\n");
}*/
int i,j;
int mt[N][M], *puntero=&mt[0][0];
srand(time(NULL));
/*
while (puntero < &mt[N][M])
{
}*/


for(i = 0;i<N; i++) {
    for(j = 0;j<M; j++) {
        //Mueve el puntero
        /* 
        *puntero=1+rand()%100; 
        printf("%d ", *puntero); 
        puntero++;
        */ 
        //No mueve al puntero
        *(puntero+(i*M+j))=1+rand()%100;
        printf("%d ", *(puntero+(i*M+j))); 
    }
    printf("\n"); 
}

    return 0;
}