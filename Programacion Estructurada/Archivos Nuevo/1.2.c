/*1.2 Una empresa debe registrar los pedidos recibidos de cada uno sus 10 productos a lo largo del día. Cada
producto está identificado por un código de 4 cifras. Los códigos deben ingresarse al inicio del programa
mediante la función IngresaCódigos y no pueden repetirse.
Por cada pedido se recibe:
• Código de producto
• Cantidad de unidades solicitadas
Se puede recibir más de un pedido por producto.
 La carga de pedidos finaliza cuando se ingresa un producto igual a 0
Al finalizar se debe:
a) Emitir un listado con código y cantidad de unidades solicitadas de cada producto.
b) El / los productos del cual se solicitaron mayor cantidad de unidades.
c) El / los productos del cual se solicitaron menos cantidad de unidades.*/
#include<stdio.h>
#include <stdlib.h>
#define TAM 10

int estaRepetido (int[],int,int);
void IngresaCodigos(int[],int);
void IngresaCantidades(int[],int[],int);
void MostrarListado(int[],int[],int);
void MostrarMayorMenor(int[],int[],int);

int main ()
{
    int cod[TAM],cant[TAM]={0};
    IngresaCodigos(cod,TAM);
    system("cls");
    IngresaCantidades(cant,cod,TAM);
    system("cls");
    MostrarListado(cod,cant,TAM);
    MostrarMayorMenor(cod,cant,TAM);

    return 0;
}

void IngresaCodigos(int vcod[],int ce)
{
    int i,aux;

    for (i=0;i<ce;i++)
    {
        do{
            printf("\nINGRESAR CODIGO DEL PRODCUTO\n");
            do{
                scanf("%d",&aux);
            }while(aux<1000||aux>9999);
            if(estaRepetido(vcod,i,aux)!=-1)
                            printf("Error, codigo ya ingreasdo\n");
        }while(estaRepetido(vcod,i,aux)!=-1);
        vcod[i]=aux;
    }
}

int estaRepetido(int v[],int ce,int dato)
{
    int i,pos=-1;
    for(i=0;i<ce;i++)
    {
        if(v[i]==dato)
            pos=i;
    }
    return pos;
}

void IngresaCantidades(int v[],int vcod[],int ce)
{
    int i,cod,cant,pos;
    do{
        printf("Ingrese codigo del producto\n");
        scanf("%d",&cod);
    }while(estaRepetido(vcod,ce,cod)==-1 && cod!=0);
    while(cod!=0)
    {
        pos=estaRepetido(vcod,ce,cod);
        printf("Ingrese unidades solicitadas del producto %d\n",cod);
        scanf("%d",&cant);
        v[pos]+=cant;

    do{
        printf("Ingrese codigo del producto\n");
        scanf("%d",&cod);
    }while(estaRepetido(vcod,ce,cod)==-1 && cod!=0);

    }
}

void MostrarListado(int v[],int vcant[],int ce)
{
    int i=0;
    printf("\nLISTADO\nCODIGO\tCANTIDAD\n");
    for(i=0;i<ce;i++)
    {
        printf("%d\t%d\n",v[i],vcant[i]);
    }
}

void MostrarMayorMenor(int v[],int vcant[],int ce)
{
    int menor,mayor,i;
    menor=vcant[0];
    for(i=1;i<ce;i++)
    {
        if(menor>vcant[i])
            menor=vcant[i];
    }
    mayor=vcant[0];
    for(i=1;i<ce;i++)
    {
        if(mayor<vcant[i])
            mayor=vcant[i];
    }
    for(i=0;i<ce;i++)
    {
        if(vcant[i]==menor)
            printf("\nEl de menor cantidad es el producto %d con %d unidades\n",v[i],vcant[i]);
        else if(vcant[i]==mayor)
            printf("El de mayor cantidad es el producto %d con %d unidades\n",v[i],vcant[i]);
    }
}
