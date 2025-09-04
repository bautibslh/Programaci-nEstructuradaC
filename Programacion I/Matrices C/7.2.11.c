#include <stdio.h>
#include <stdlib.h>
#define SUC 40
#define RUB 120
/*
La cadena de supermercados NORTE, tiene 40 sucursales y comercializa 120 rubros de distintas
mercaderías. La Casa Central recibe a diario las notas de pedido de mercaderías emitidas por cada una de las
sucursales.
Se ingresa por teclado las unidades pedidas (estos datos se ingresan hasta que aparece una sucursal igual
a 99, los datos vienen desordenados, y puede venir más de una información de una misma sucursal y el
mismo rubro):
 Número de sucursal (1 a 40).
 Código de rubro (1 a 120).
 Cantidad de unidades pedidas.
Informar:
a. La cantidad de pedidos por sucursal.
b. Cuál fue la sucursal que pidió la menor cantidad en total (puede haber varias sucursales que
tienen el mismo valor mínimo).
FUNCIONES
I. Para inicializar la matriz.
II. Para mostrar el resultado del punto b.
*/
void InicializaM(int [][RUB],int,int);
void MostrarMin(int [][RUB],int[],int,int);
int main()
{
    int mat[SUC][RUB],i,j,pexsuc[SUC],min[SUC];
    InicializaM(mat,SUC,RUB);

    for(i=0;i<SUC;i++)
    {
        pexsuc[i]=0;
        for(j=0;j<RUB;j++)
        {
            pexsuc[i]+=mat[i][j];
        }
        if(pexsuc[i]!=0)
        printf("SUCURSAL %d: %d pedidos\n",i+1,pexsuc[i]);
    }

    MostrarMin(mat,min,SUC,RUB);
    return 0;
}

void InicializaM(int m[][RUB],int cf,int cc)
{
    int f,c,un;
    for (f=0;f<cf;f++)
    {
        for(c=0;c<cc;c++)
        {
            m[f][c]=0;
        }
    }
    printf("\t\t\tCADENA DE SUPERMERCADOS - NORTE\n");
    printf("\t\t\tPEDIDO DE MERCADERIA\n");
    do{
        printf("\nINGRESE NUMERO DE SUCURSAL (99 para terminar)\n");
        scanf("%d",&f);
    }while ((f<1||f>40) && f!=99);
    while (f!=99)
    {
        do{
            printf("INGRESE NUMERO DE RUBRO\n");
            scanf("%d",&c);
        }while (c<1||c>120);
        do{
            printf("CANTIDAD DE UNIDADES PEDIDAS\n");
            scanf("%d",&un);
        }while (un<0);
        system("cls");

        m[f-1][c-1]+=un;

        printf("\t\t\tCADENA DE SUPERMERCADOS - NORTE\n");
        printf("\t\t\tPEDIDO DE MERCADERIA\n");
        do{
            printf("\nINGRESE NUMERO DE SUCURSAL (99 para terminar)\n");
            scanf("%d",&f);
        }while ((f<1||f>40) && f!=99);
    }
}

void MostrarMin(int m[][RUB],int v[],int cf,int cc)
{
    int f,c,min,band=0;
    for (f=0;f<cf;f++)
    {
        v[f]=0;
        for(c=0;c<cc;c++)
        {
            v[f]+=m[f][c];
        }
    }
    for (f=0;f<cf;f++)
    {
        if(band==0 &&v[f]!=0)
        {
            min=v[f];
            band=1;
        }
        else if(v[f]!=0 && v[f]<min && band!=0)
            min=v[f];
    }
    printf("LA/S SUCURSAL/ES CON MENOS PEDIDOS SON:\n");
    for(f=0;f<cf;f++)
    {
        if(v[f]==min)
        {
            printf("SUCURSAL %d\n",f+1);
        }
    }
    printf("Y SU MINIMO ES:%d\n",min);
}
