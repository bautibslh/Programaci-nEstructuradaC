#include <stdio.h>
#include <stdlib.h>
#define CE 3
void ingresaCodigos(int [],int);
int codRepetido(int [],int,int);
void cargaPedidos(int [],int [],int);
void mostrarListado(int[],int [],int);
void mostrarMayor(int [],int[],int);
void mostrarMenor(int [],int[],int);
int main ()
{
    int codigos[CE],i,pedidos[CE]={0};
    ingresaCodigos(codigos,CE);
    cargaPedidos(codigos,pedidos,CE);
    mostrarListado(codigos,pedidos,CE);
    mostrarMayor(codigos,pedidos,CE);
    mostrarMenor(codigos,pedidos,CE);   /*Solo muestran UN mayor y UN menor, para mostrar todos los
                                        mayores/menores comparar en un ciclo for y mostrar posicion en vCod*/

    return 0;
}

void ingresaCodigos(int v[],int ce)
{
    int i;
    printf ("***CARGA DE CODIGOS***\n");
    for (i=0;i<ce;i++)
    {
        printf ("Ingrese codigo del producto %d\n",i+1);
        do{
            scanf("%d",&v[i]);
        }while (!(v[i]>999 && v[i]<10000 && codRepetido(v,v[i],i)==0));
    }
}

int codRepetido(int ve[],int num,int ce)
{
    int i,cond=0;
    for (i=0;i<ce;i++)
    {
        if(num==ve[i])
        {
            cond=1;
        }
    }
    return cond;
}



void cargaPedidos(int vc[],int vp[],int ce)
{
    int i=0,cod,cant,indice;
    system("cls");
    do{
        printf ("Ingrese codigo del producto\n");
        scanf("%d",&cod);
    }while (!(cod==0 || codRepetido(vc,cod,ce)==1));

    while (cod!=0)
    {
        do{
            printf ("Ingrese unidades solicitadas\n");
            scanf ("%d",&cant);
        }while (cant<1);

        for (i=0;i<ce;i++)
        {
            if (cod==vc[i])
            {
                indice=i;
            }
        }

        vp[indice]+=cant;

        do{
            printf ("Ingrese codigo del producto\n");
            scanf("%d",&cod);
        }while (!(cod==0 || codRepetido(vc,cod,ce)==1));
    }
}

void mostrarListado(int v1[],int v2[],int ce)
{
    int i;
    printf ("  ***LISTADO***\n");
    printf ("CODIGO\tUNIDADES\n");
    for(i=0;i<ce;i++)
    {
        printf ("%6d\t%8d\n",v1[i],v2[i]);
    }
}

void mostrarMayor(int vcod[],int vped[],int ce)
{
    int i,mCod,mPed;
    mCod=vcod[0];
    mPed=vped[0];
    for(i=1;i<ce;i++)
    {
        if(vped[i]>mPed)
        {
            mPed=vped[i];
            mCod=vcod[i];
        }
    }
    printf ("\nEl producto %d es el que mas unidades tiene (%d)\n",mCod,mPed);
}

void mostrarMenor(int vcod[],int vped[],int ce)
{
    int i,mCod,mPed;
    mCod=vcod[0];
    mPed=vped[0];
    for (i=1;i<ce;i++)
    {
        if(vped[i]<mPed)
        {
            mPed=vped[i];
            mCod=vcod[i];
        }
    }
    printf ("\nEl producto %d es el que menos unidades tiene (%d)\n",mCod,mPed);
}
