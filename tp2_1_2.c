#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

int main(){
// codigo a completar
int i=0;
double vt[N], *punt=vt;
srand(time(NULL));
while (i<N)
{
    *punt=1+rand()%100;
    printf("%.2f\n", *punt);
    punt++;
    i++;
}

return 0;
}