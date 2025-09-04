#include <stdio.h>
#include <stdlib.h>
#define PRODUC 20
#define MES 12

void Carga(int [][MES],float [],float [],int,int);
void Muestra(int [][MES],float [],float [],int,int);

int main ()
{
    int unidades[PRODUC][MES]={{0}};
    float recau[PRODUC]={0},trim[4]={0};
    Carga(unidades,recau,trim,PRODUC,MES);
    Muestra(unidades,recau,trim,PRODUC,MES);
    return 0;
}

void Carga(int m[][MES],float rec[],float tri[],int p, int cmes)
{
    int cod,dia,mes,cant;
    float pre;
    do{
        printf("PRECIO UNITARIO DEL PRODUCTO\n");
        scanf("%f",&pre);
    }while (pre<0);

    while(pre!=0)
    {
        do{
            printf("CODIGO DEL PRODUCTO\n");
            scanf("%d",&cod);
        }while (cod<1||cod>p);

        do{
            printf("DIA DE LA VENTA\n");
            scanf ("%d",&dia);
        }while (dia<1||dia>31);

        do{
            printf("MES DE LA VENTA\n");
            scanf ("%d",&mes);
        }while (mes<1||mes>cmes);

        do{
            printf("CANTIDAD DE VENTAS\n");
            scanf("%d",&cant);
        }while(cant<0);

        m[cod-1][mes-1]+=cant;
        rec[cod-1]+=pre*cant;

        if(mes==1||mes==2||mes==3)
        {
            tri[0]+=pre*cant;
        }
        if(mes==4||mes==5||mes==6)
        {
            tri[1]+=pre*cant;
        }
        if(mes==7||mes==8||mes==9)
        {
            tri[2]+=pre*cant;
        }
        if(mes==10||mes==11||mes==12)
        {
            tri[3]+=pre*cant;
        }

        do{
            printf("PRECIO UNITARIO DEL PRODUCTO\n");
            scanf("%f",&pre);
        }while (pre<0);
    }
}

void Muestra(int m[][MES],float v[],float tri[],int f,int c)
{
    int i,j,band=0;
    float max,min;
    printf("\nUnidades vendidas de cada producto en cada uno de los 12 meses.\n");
    printf("\t\t\t\tMESES\n");
    printf("            ");
    for(i=0;i<c;i++)
    printf("%4d",i+1);
    printf("\n");
    for (i=0;i<f;i++)
    {
        for(j=0;j<c;j++)
        {
        if(j==0)
        {
            printf("PRODUCTO %2d ",i+1);
        }
                printf("%4d",m[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<f;i++)
    {
        if(band==0)
        {
            max=v[i];
            band=1;
        }
        if(v[i]>max && band==1)
        {
            max=v[i];
        }
    }
    printf("\nEl/los producto/s que obtuvo la mayor recaudacion es:\n");
    for (i=0;i<f;i++)
    {
        if(v[i]==max)
            printf("%d\n",i+1);
    }
    printf("\nCon una recaudacion de %.2f\n",max);

    printf("\nEl trimestre de menor recaudacion del anio es:\n");
    band=0;
    for(i=0;i<4;i++)
    {
        if (band==0)
        {
            min=tri[i];
            band=1;
        }
        if(tri[i]<min && band==1)
        {
            min=tri[i];
        }
    }
    for (i=0;i<4;i++)
    {
        if(tri[i]==min)
            printf("%d\n",i+1);
    }
    printf("\nCon una recaudacion de %.2f\n",min);
}
