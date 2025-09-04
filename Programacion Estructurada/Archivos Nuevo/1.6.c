/*1.6 Dado un conjunto de 10 números enteros ordenados de menor a mayor, ingresar por teclado 3 números más
no ordenados. Insertarlos donde correspondan. Mostrar en pantalla la serie inicial y la final. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 13
void cargaVec(int[],int);
void ordenamM(int[],int);
void ingresaNum(int[],int);
void mostrarVec(int[],int);
int main ()
{
    int vec[TAM];
    srand(time(NULL));
    cargaVec(vec,TAM-3);
    ordenamM(vec,TAM-3);
    mostrarVec(vec,TAM-3);
    ingresaNum(vec,TAM);
    ordenamM(vec,TAM);
    mostrarVec(vec,TAM);
    return 0;
}

void cargaVec(int v[],int ce)
{
    int i;
    for(i=0;i<ce;i++)
    {
        v[i]=rand()%100;
    }
}

void ordenamM(int v[],int ce)
{
    int i,j,aux;
    for(i=0;i<ce-1;i++)
    {
        for(j=0;j<ce-1-i;j++)
        {
            if(v[j]>=v[j+1])
            {
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
        }
    }
}

void ingresaNum(int v[],int ce)
{
    int i;
    for(i=10;i<ce;i++)
    {
        printf("INGRESE NUEVO NUMERO %d/3\n",i-9);
        scanf("%d",&v[i]);
    }
}

void mostrarVec(int v[],int ce)
{
    int i;
    printf("POSICION\tNUMERO\n");
    for(i=0;i<ce;i++)
    {
        printf("%d       \t%d\n",i+1,v[i]);
    }
}
