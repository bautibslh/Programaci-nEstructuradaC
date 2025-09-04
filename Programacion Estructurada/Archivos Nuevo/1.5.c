/*1.5 Se ingresan los códigos de 15 productos de una empresa (números de 3 dígitos). Luego del ingreso se debe
ordenar de forma ascendente la colección con dichos códigos para permitir realizar búsquedas binarias.
Luego se ingresan las ventas realizadas durante el día. Por cada venta se ingresa código de vendedor, código
de artículo y cantidad.
Los vendedores son 5 y están codificados en forma correlativa de 1001 a 1005. Se puede recibir más de una
venta de un mismo vendedor y artículo. El ingreso de datos finaliza con código de vendedor igual a 0. Se desea:
a. Mostrar un listado ordenado de mayor a menor por cantidad de unidades vendidas de cada producto.
b. Indicar el/los vendedores que realizaron menor cantidad de ventas (no de unidades).*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 15
void cargaCodigos(int [],int);
void ordenamM(int [],int);
void cargaVentas(int[],int[],int[],int[],int,int);
int busquedaBinaria(int[],int,int);
void ordenaMm(int [],int[],int);
void mostrarPuntoA(int [],int[],int);
void mostrarPuntoB(int [],int);
int estaEnRango(int,int,int);

int main ()
{
    int vc[TAM],vv[5],vxa[TAM]={0},vxv[5]={0},i;//vv NO NECESARIO PARA EL PROGRAMA, PERO INDICA VENTAS TOTALES POR VENDEDOR
    srand(time(NULL));
    cargaCodigos(vc,TAM);   //UTILIZO CARGA ALEATORIA PARA NO CARGAR 15 CODIGOS CADA PRUEBA, PARA QUE SEAN DE 3 DIGITOS DIVIDO A RESTO X 1000
    for(i=0;i<TAM;i++)
        printf("%d\n",vc[i]);//MUESTRO CODIGO DE ARTICULO PARA CONOCERLOS EN MI PRUEBA
    ordenamM(vc,TAM);//ORDENO CODIGOS DE MENOR A MAYOR PARA BUSQUEDA BINARIA
    cargaVentas(vc,vv,vxa,vxv,TAM,5);//ENVIO TODOS LOS VECTORES PARA REALIZAR CARGAS
    ordenaMm(vc,vxa,TAM);//ORDENO CODIGOS DE ART. Y VENTAS POR ARTICULO DE MAYOR A MENOR PARA PUNTO A
    mostrarPuntoA(vc,vxa,TAM);
    mostrarPuntoB(vxv,5);


    return 0;
}

void cargaCodigos(int v[],int ce)//FUNCION PARA CARGA RAPIDA DE CODIGOS
{
    int i;
    for(i=0;i<ce;i++)
    {
        v[i]=rand()%1000;//%1000 PARA QUE SEA DE 3 DIGITOS
    }
}

void ordenamM(int v[],int ce)
{
    int i,j,aux;
    for(i=0;i<ce-1;i++)         //UTILIZO METODO DE BURBUJEO PARA ORDENAR
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
void cargaVentas(int vc[],int vv[],int vxa[],int vxv[],int cc,int cv)
{
    int cod,indice,codVend,cvent;

        do{
            printf("Ingrese codigo de vendedor\n");
            scanf("%d",&codVend);
           // codVend=codVend-1001;
        }while(estaEnRango(1001,1005,codVend)!=1 && codVend!=0);//VALIDO QUE ESTE EN RANGO O QUE SEA CONDICION DE FIN DEL CICLO


    while(codVend!=0)
    {

        do{
            printf("Ingrese codigo de articulo\n");
            scanf("%d",&cod);
            indice=busquedaBinaria(vc,cc,cod);//UTILIZO UNA NUEVA VARIABLE POR COMODIDAD PARA NO USAR LA FUNCION VARIAS VECES
        }while(indice==-1);//CONFIRMO QUE SEA UN CODIGO VALIDO
        do{
            printf("Ingrese cantidad a comprar\n");
            scanf("%d",&cvent);
        }while(cvent<=0);//las ventas no pueden ser negativas o 0


        vv[codVend-1001]+=cvent;//NO REQUERIDO PARA EL PROBLEMA, INDICA VENTAS TOTALES POR VENDEDOR
        vxa[indice]+=cvent;//VENTAS POR ARTICULO
        vxv[codVend-1001]++;//VECTOR CONTADOR, INDICA CUANTAS VENTAS REALIZA CADA VENDEDOR

        do{
            printf("Ingrese codigo de vendedor\n");
            scanf("%d",&codVend);
           // codVend=codVend-1001;
        }while(estaEnRango(1001,1005,codVend)!=1 && codVend!=0);

    }
}

int busquedaBinaria(int v[],int ce,int dato)
{
    int pos=-1,li=0,ls=ce-1,med;
    while(pos==-1 && li<=ls)
    {
        med=(li+ls)/2;
        if(v[med]==dato)
            pos=med;
        else
            if(dato>v[med])
                li=med+1;
            else
                ls=med-1;
    }
    return pos;
}

void ordenaMm(int vc[],int vvent[],int ce)
{
    int i,j,aux;
    for(i=0;i<ce-1;i++)
    {
        for(j=0;j<ce-1-i;j++)
        {
            if(vvent[j]<=vvent[j+1])
            {
                aux=vvent[j];
                vvent[j]=vvent[j+1];
                vvent[j+1]=aux;

                aux=vc[j];
                vc[j]=vc[j+1];
                vc[j+1]=aux;
            }
        }
    }
}

void mostrarPuntoA(int vc[],int vv[],int ce)
{
    int i;
    printf("COD. ARTICULO\tVENTAS\n");
    for (i=0;i<ce;i++)
    {
        printf("%d \t\t\t%d\n",vc[i],vv[i]);
    }
}

void mostrarPuntoB(int v[],int ce)
{
    int i,menor;
    menor=v[0];
    for(i=1;i<ce;i++)
    {
        if(menor>v[i])
            menor=v[i];
    }
    for(i=0;i<ce;i++)
    {
        if(v[i]==menor)
            printf("El/los vendedor con menos articulos vendidos es: %d con %d articulos\n",i+1001,v[i]);
    }
}

int estaEnRango(int li,int ls,int d)
{
    int r=0;
    if (d>=li && d<=ls)
        r=1;
    return r;
}
