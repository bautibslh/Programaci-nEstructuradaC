#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT 50
typedef struct {
                char codigo[6];
                float precio;
                char descripcion[31];
                int cantVendida;
                float importeTotal;
            }T_product;
void reiniciarVentasDelMes(T_product[],int);
int existeCodigo(T_product[],char[],int);
int cargaProductos(T_product[],int);
void cargaVentas(T_product[],int);
void mostrarListado(T_product[],int);
int main ()
{
    T_product producto[50];
    int cCargada;
    cCargada=cargaProductos(producto,CANT);
    system("pause");
    system("cls");
    cargaVentas(producto,cCargada);
    system("pause");
    system("cls");
    mostrarListado(producto,cCargada);
    return 0;
}
void reiniciarVentasDelMes(T_product produ[],int ce)
{
    int i;
    for(i=0;i<ce;i++)
    {
        produ[i].cantVendida=0;
    }
}
int existeCodigo(T_product prod[],char dato[],int ce)
{
    int i,pos=-1;
    for(i=0;i<ce;i++)
    {
        if(strcmpi(prod[i].codigo,dato)==0)
        {
            pos=i;
        }
    }
    return pos;
}
int cargaProductos(T_product pr[],int ce)
{
    int i=0;
    printf("\nCARGA DE PRODUCTOS\n");

    printf("Descripcion del producto - FIN para terminar\n");
    fflush(stdin);
    gets(pr[i].descripcion);

    while(strcmpi(pr[i].descripcion,"FIN")!=0 && i<ce)
    {
            printf("PRODUCTO N°%d\n",i+1);
            printf("CODIGO DEL PRODUCTO:\n");
            gets(pr[i].codigo);

            printf("PRECIO DEL PRODUCTO\n");
            scanf("%f",&pr[i].precio);

            printf("CANTIDAD VENDIDA (ultimo mes)\n");
            scanf("%d",&pr[i].cantVendida);

            printf("IMPORTE TOTAL (ultimo mes)\n");
            scanf("%f",&pr[i].importeTotal);

            i++;
            if(i<ce)
            {
                printf("Descripcion del producto - FIN para terminar\n");
                fflush(stdin);
                gets(pr[i].descripcion);
            }
    }
    return i;
}
void cargaVentas(T_product pro[],int ce)
{
    int cant,posicion;
    char cProd[6];

    printf ("VENTAS\n");
    printf("CANTIDAD A COMPRAR (0 para terminar)\n");
    scanf("%d",&cant);
    reiniciarVentasDelMes(pro,ce);
    while (cant!=0)
    {
        do{
            printf("CODIGO DEL PRODUCTO A COMPRAR\n");
            fflush(stdin);
            gets(cProd);
            if(existeCodigo(pro,cProd,ce)==-1)
                printf("ERROR, CODIGO INCORRECTO\n");
        }while (existeCodigo(pro,cProd,ce)==-1);

        posicion=existeCodigo(pro,cProd,ce);
        pro[posicion].cantVendida+=cant;

        printf ("VENTAS\n");
        printf("CANTIDAD A COMPRAR (0 para terminar)\n");
        scanf("%d",&cant);

    }

}
void mostrarListado(T_product p[],int ce)
{
    int i;
    printf("LISTADO DE VENTAS DE ESTE MES\n");
    printf("DESCRIPCION\t\t\tUNIDADES VENDIDAS\tIMPORTE TOTAL\n");
    for(i=0;i<ce;i++)
    {
        printf("%-30s\t%-17d\t%.2f\n",p[i].descripcion,p[i].cantVendida,p[i].cantVendida*p[i].precio);
    }
}
