/*
Se ingresan los códigos de 15 productos de una empresa (números de 3 dígitos). Luego se ingresan las
ventas realizadas durante el día. Por cada venta se ingresa código de vendedor, código de artículo y cantidad.
Los vendedores son 5 y están codificados en forma correlativa de 1001 a 1005. Se puede recibir más de una venta
de un mismo vendedor y artículo. El ingreso de datos finaliza con código de vendedor igual a 0. Se desea:
a. Mostrar un listado ordenado de mayor a menor por cantidad de unidades vendidas de cada producto.
b. Indicar el/los vendedores que realizaron menor cantidad de ventas (no de unidades).
*/
#include <stdio.h>
#include <stdlib.h>
#define CANT 5
#define VEND 5
int estaEnRango(int,int,int);
int buscaEnVector(int[],int,int);
void cargaCodigos(int [],int);
void cargaVentas(int[],int[],int[],int[],int,int);
void ordenaMayorMenor(int[],int[],int);
void muestraListado(int[],int[],int);
void indicaMenoresVentas(int[],int[],int);
int main ()
{
    int productos[CANT],vendedores[VEND],ventas[CANT],ventasxvend[VEND];
    cargaCodigos(productos,CANT);
    cargaVentas(vendedores,productos,ventas,ventasxvend,VEND,CANT);
    ordenaMayorMenor(productos,ventas,CANT);
    muestraListado(productos,ventas,CANT);
    indicaMenoresVentas(vendedores,ventasxvend,VEND);
    return 0;
}

int estaEnRango(int dato,int li,int ls)
{
    int cond=0;
    if (dato>=li && dato <=ls)
        cond=1;
    return cond;
}
void cargaCodigos(int v[],int ce)
{
    int i;
    printf("CARGA CODIGOS DE PRODUCTOS\n");
    for (i=0;i<ce;i++)
    {
        do{
            printf ("CODIGO PRODUCTO %d\n",i+1);
            scanf("%d",&v[i]);
            if(estaEnRango(v[i],100,999)==0)
                printf("Error, debe ser un codigo de 3 digitos\n");
        }while(estaEnRango(v[i],100,999)==0);
    }
    system("pause");
    system ("cls");
}
int buscaEnVector(int v[],int dato,int ce)
{
    int i,pos=-1;
    for (i=0;i<ce;i++)
    {
        if (v[i]==dato)
            pos=i;
    }
    return pos;
}
void cargaVentas(int ven[],int prod[],int ventas[],int venxvend[], int cv,int ca)
{
    int indiceVendedor,cArt,venxprod=0;
    do{
        printf ("Ingrese codigo de vendedor\n");
        scanf("%d",&indiceVendedor);
        if((estaEnRango(indiceVendedor,1001,1005)==0 && indiceVendedor!=0))
            printf ("Error, intente de nuevo\n");
    }while (estaEnRango(indiceVendedor,1001,1005)==0 && indiceVendedor!=0);

    while (indiceVendedor!=0)
    {
        venxprod=0;
        do{
            printf ("Ingrese codigo del articulo\n");
            scanf("%d",&cArt);
            if(buscaEnVector(prod,cArt,ca)==-1)
                printf ("Error, intente de nuevo\n");
        }while (buscaEnVector(prod,cArt,ca)==-1);

        do{
            printf("Cantidad a comprar\n");
            scanf("%d",&venxprod);
        }while (venxprod<0);

        prod[buscaEnVector(prod,cArt,ca)]+=venxprod;
        venxvend[indiceVendedor-1001]++;
        do{
            printf ("Ingrese codigo de vendedor\n");
            scanf("%d",&indiceVendedor);
            if((estaEnRango(indiceVendedor,1001,1005)==0 && indiceVendedor!=0))
                printf ("Error, intente de nuevo\n");
        }while (estaEnRango(indiceVendedor,1001,1005)==0 && indiceVendedor!=0);
    }

}

void ordenaMayorMenor(int p[],int v[],int ce)
{
    int i,j,aux;
    for(i=0;i<ce-1;i++)
    {
        for(j=0;j<ce-1-i;j++)
        {
            if(v[i]>v[i+1])
            {
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;

                aux=p[i];
                p[i]=p[i+1];
                p[i+1]=aux;
            }
        }
    }
}
void muestraListado(int prod[],int vent[],int ce)
{
    int i;
    printf ("LISTADO CANTIDAD DE VENTAS POR PRODUCTO\n");
    printf ("CODIGO DEL PRODUCTO\tCANTIDAD\n");
    for(i=0;i<ce;i++)
    {
        printf ("%5d\t%d\n",prod[i],vent[i]);
    }
}
void indicaMenoresVentas(int vend[],int cdv[],int ce)
{
    int i,menor=0;
    for(i=0;i<ce;i++)
    {
        if(cdv[i]<=menor)
        {
            menor=cdv[i];
        }
    }
    for (i=0;i<ce;i++)
    {
        if(cdv[i]==menor)
        {
            printf ("El vendedor con menor cantidad de ventas es:%d con %d\n",vend[i],cdv[i]);
        }
    }
}
