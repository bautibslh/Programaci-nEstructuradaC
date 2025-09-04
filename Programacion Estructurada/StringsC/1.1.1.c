#include <stdio.h>
#include <stdlib.h>
#define CE 10
void ingresaCodigos(int [],int);
void cargaPedidos(int [],int [],int);
int main()
{
    int vCod[CE],vPed[CE]={0},i;
    ingresaCodigos(vCod,CE);
    cargaPedidos(vCod,vPed,CE);
    for (i=0;i<CE;i++)
    {
        printf ("\nCOD:%d\tCANT:%d",vCod[i],vPed[i]);
    }
    return 0;
}

void ingresaCodigos(int v[],int ce)
{
    int i;
    printf ("***CARGA DE CODIGOS***\n");
    for (i=0;i<ce;i++)
    {
        printf ("   Ingrese codigo del producto %d\n",i+1);
        do{
            scanf("%d",&v[i]);
        }while (!(v[i]>999 && v[i]<10000));
    }
}

void cargaPedidos(int vC[],int vP[],int ce)
{
    int i,acum=0,cod,encontro,indicePedido;
    while (cod!=0)
    {
        printf ("Indique codigo del producto\n");
        scanf ("%d",cod);
        for (i=0;i<ce;i++)
        {
            if (cod==vC[i])
            {
                encontro=1;
                indicePedido=i;
            }
            else encontro=0;
        }
        if (encontro=1)
        {
            do{
                printf ("Ingrese unidades solicitadas\n");
                scanf("%d",&vP[indicePedido]);
            }while (vP[indicePedido]<1);
        }
    }
}
