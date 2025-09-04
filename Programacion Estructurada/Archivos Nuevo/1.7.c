/*1.7 Dado un vector de 10 enteros, ingresar un entero por teclado, buscarlo y, si se lo encuentra, generar un nuevo
vector con los índices correspondientes a las ubicaciones en el primer vector del entero ingresado.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10
void cargaVec(int[],int);
int buscar(int[],int,int);
int main ()
{
    int v[TAM],v2[TAM]={0},num,pos,i=0;
    srand(time(NULL));
    cargaVec(v,TAM);
    do{
        printf("Ingrese numero a buscar\n");
        scanf("%d",&num);
    }while (num<0||num>10);
    while(i<TAM && num!=0)
    {
        pos=buscar(v,TAM,num);
        if (pos!=-1)
        {
            v2[i]=pos;
            i++;
        }
        do{
            printf("Ingrese numero a buscar\n");
            scanf("%d",&num);
        }while (num<0||num>10);
    }

    printf ("    v1\tv2\n");
    for(i=0;i<TAM;i++)
        printf("%2d  %d\t%d\n",i,v[i],v2[i]);
    return 0;
}

void cargaVec(int v[],int ce)
{
    int i;
    for(i=0;i<ce;i++)
    {
        v[i]=rand()%10;
    }
}

int buscar(int v[],int ce,int d)
{
    int i,pos=-1;
    for(i=0;i<ce;i++)
    {
        if(v[i]==d)
            pos=i;
    }
    return pos;
}
