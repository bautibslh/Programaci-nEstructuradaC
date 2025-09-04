/*Se ingresan código y precio unitario de los productos que vende un negocio. No se sabe la cantidad
exacta de productos, pero sí se sabe que son menos de 50. El código es alfanumérico de 3 caracteres y
la carga de los datos de productos termina con un código igual al “FIN”. Luego se registran las ventas del
día y por cada venta se ingresa el código de producto y cantidad de unidades vendidas terminando con
una cantidad igual a 0. Se solicita:
c. Calcular la recaudación total del día y el producto del cual se vendió menor cantidad de unidades.
d. Mostrar el listado de productos con su precio ordenado en forma alfabética por código de
producto*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PROD 50
int cargaProductos(char[][4],float[],int);
void ventasxDia(char[][4],float[],int[],int);
int encontrarEnVector(char[][4],char[],int);
void ordenaVectores(char[][4],float[],int);
void mostrarListado(char[][4],float[],int);
int main()
{
    char codigo[PROD][4];
    float precio[PROD]={0};
    int ventaxProd[PROD]={0};
    int cantCargada;
    cantCargada=cargaProductos(codigo,precio,PROD);
    ventasxDia(codigo,precio,ventaxProd,cantCargada);
    ordenaVectores(codigo,precio,cantCargada);
    mostrarListado(codigo,precio,cantCargada);

    return 0;
}

int cargaProductos(char cod[][4],float pr[],int ce)
{
    int i=0;
    printf("Ingresa codigo alfanumerico (3 caracteres)\n");
    fflush(stdin);
    gets(cod[i]);

    while(strcmpi(cod[i],"FIN")!=0 && i<ce)
    {
        printf("Ingresa precio unitario\n");
        scanf("%f",&pr[i]);
        i++;
        if (i<ce)
        {
            printf("Ingresa codigo alfanumerico (3 caracteres)\n");
            fflush(stdin);
            gets(cod[i]);
        }
    }
    return i;
}
int encontrarEnVector(char vs[][4],char st[],int ce)
{
    int i,pos=-1;
    for(i=0;i<ce;i++)
    {
        if(strcmpi(vs[i],st)==0)
        {
            pos=i;
        }
    }
    return pos;
}
void ventasxDia(char c[][4],float p[],int vxp[],int ce)
{
    char cod[4],menorcod[4];
    int cant,i=0,indiceProd,menor;
    float total=0;

    printf("CANTIDAD A COMPRAR\n");
    scanf("%d",&cant);

    while (cant!=0)
    {

        printf("Indicar codigo del producto\n");
        fflush(stdin);
        gets(cod);

        indiceProd=encontrarEnVector(c,cod,50);

        if(indiceProd != -1)
        {
            vxp[indiceProd]++;
            total+=p[indiceProd]*cant;
        }


        printf("CANTIDAD A COMPRAR\n");
        scanf("%d",&cant);
    }
    system("pause");
    system("cls");
    printf("Recaudacion total:%.2f",total);
    printf("Menor cantidad de ventas\nPRODUCTO:\tCANTIDAD:\n");
    menor=vxp[0];
    for(i=1;i<ce;i++)
    {
        if(vxp[i]<menor)
        {
            menor=vxp[i];
            strcpy(menorcod,c[i]);
        }
    }
    printf("%s\t   %d\n",menorcod,menor);

}
void ordenaVectores(char cod[][4],float pre[],int ce)
{
    int i,j;
    float auxf;
    char aux[4];
    for(j=0;j<ce-1;j++)
    {
        for(i=0;i<ce-1-j;i++)
        {
            if (strcmp(cod[i],cod[i+1])==1)
            {
                strcpy(aux,cod[i]);
                strcpy(cod[i],cod[i+1]);
                strcpy(cod[i+1],aux);

                auxf=pre[i];
                pre[i]=pre[i+1];
                pre[i+1]=auxf;
            }
        }
    }
}
void mostrarListado(char cod[][4],float pre[],int ce)
{
    int i;
    printf ("\nLISTADO DE PRECIOS\nCOD DE PRODUCTO:\t\tPRECIO\n");
    for(i=0;i<ce;i++)
    {
        printf("%s\t\t\t\t$%.2f\n",cod[i],pre[i]);
    }
}
