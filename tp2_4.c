#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANO 5
//4)a)i. Declara un tipo de dato estructura
struct compu {
    int velocidad;//entre 1 y 3 GHz
    int anio;//entre 2015 y 2023
    int cantidad;//entre 1 y 8
    char *tipo_cpu; //valores del arreglo tipos
}typedef PC;

//Funciones
void mostrarPC(PC *punteroArreglo, int Componentes);
void viejaPC(PC *punteroArreglo, int Componentes);
void velozPC(PC *punteroArreglo, int Componentes);

int main(){
    char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};//4)a)iii.
    int procesador;
    PC arreglo[TAMANO], *punteroArreglo=arreglo; //4)b.

    srand(time(NULL));

    for (int i = 0; i < TAMANO; i++)
    {
        procesador=rand()%6;
        punteroArreglo->velocidad = 1+rand()%3;
        punteroArreglo->anio = rand() % (2023-2015+1) + 2015; 
        punteroArreglo->cantidad = 1+rand()%8;
        punteroArreglo->tipo_cpu = &tipos[procesador][0];
        punteroArreglo++;
    }
    mostrarPC(arreglo, TAMANO);
    viejaPC(arreglo, TAMANO);
    velozPC(arreglo, TAMANO);

    return 0;
}

void mostrarPC(PC *punteroArreglo, int Componentes)//4)c.
{
    for (int i = 0; i < Componentes; i++)
    {
        printf("------ PC %dº------\n", i+1);
        printf("Velocidad de procesamiento en GHz: %d\n", punteroArreglo->velocidad);
        printf("Anio de fabricación: %d\n", punteroArreglo->anio);
        printf("Cantidad de núcleos: %d\n", punteroArreglo->cantidad);
        printf("Tipo de procesador: %s\n", punteroArreglo->tipo_cpu);
        punteroArreglo++;
    }
}

void viejaPC(PC *punteroArreglo, int Componentes)//4)d.
{
    int vieja = punteroArreglo->anio;
    PC *masVieja = punteroArreglo;

    for (int i = 0; i < Componentes-1; i++)
    {
        punteroArreglo++;
        if (punteroArreglo->anio <= vieja)
        {
            vieja = punteroArreglo->anio;
            masVieja = punteroArreglo;
        }
    }
    
    printf("------ PC mas Vieja ------\n");
    printf("Velocidad de procesamiento en GHz: %d\n", masVieja->velocidad);
    printf("Anio de fabricación: %d\n", masVieja->anio);
    printf("Cantidad de núcleos: %d\n", masVieja->cantidad);
    printf("Tipo de procesador: %s\n", masVieja->tipo_cpu);
}

void velozPC(PC *punteroArreglo, int Componentes)//4)e.
{
    int veloz = punteroArreglo->velocidad;
    PC *masVeloz = punteroArreglo;

    for (int i = 0; i < Componentes-1; i++)
    {
        punteroArreglo++;
        if (punteroArreglo->velocidad >= veloz)
        {
            veloz = punteroArreglo->velocidad;
            masVeloz = punteroArreglo;
        }
    }
    
    printf("------ PC mas Veloz ------\n");
    printf("Velocidad de procesamiento en GHz: %d\n", masVeloz->velocidad);
    printf("Anio de fabricación: %d\n", masVeloz->anio);
    printf("Cantidad de núcleos: %d\n", masVeloz->cantidad);
    printf("Tipo de procesador: %s\n", masVeloz->tipo_cpu);
}