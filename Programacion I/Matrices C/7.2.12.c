#include <stdio.h>
#include <stdlib.h>
#define TOUR 10
#define AGEN 15
/*
La empresa de turismo GUADALAJARA VIAJES comercializa 10 diferentes tours a través de 15 agencias en
todo el país. Diariamente cada agencia envía la cantidad de ventas efectuadas de cada tour, indicando
agencia, tours y la cantidad de pasajes. Algunas agencias envían o en la cantidad cuando no existen pasajes
para un tour determinado, pero no en todas.
La información que se envía tiene los siguientes datos que se ingresan en forma desordenada:
1 Código de agencia (de 1 a 15)
2 Código de tour (1 a 10)
3 Cantidad de pasajes (0 a 20)
Informar:
a. El total de pasajes vendidos por tour.
b. El número de agencia que obtuvo la máxima cantidad de pasajes vendidos.
FUNCIONES:
I. Para inicializar la matriz
II. Para mostrar el resultado del punto a.
*/
void InicializaM(int [][AGEN],int,int);
void MuestraPasXT(int [][AGEN],int [],int,int);
int main()
{
    int mat[TOUR][AGEN]={{0}},pxT[TOUR],i,j,vMax[AGEN],band=0,max,maxp;
    InicializaM(mat,TOUR,AGEN);
    MuestraPasXT(mat,pxT,TOUR,AGEN);
    for(j=0;j<AGEN;j++)
    {
        vMax[j]=0;
        for(i=0;i<TOUR;i++)
        {
            vMax[j]+=mat[i][j];
        }
    }
    for(i=0;i<AGEN;i++)
    {
        if (band==0)
        {
            max=vMax[i];
            maxp=i;
            band=1;
        }
        else if (vMax[i]>max && band!=0)
        {
            max=vMax[i];
            maxp=i;
        }
    }
    printf("\nLA AGENCIA CON MAYOR VENTA DE PASAJEROS ES:%2d CON UN TOTAL DE %2d PASAJEROS\n",maxp+1,max);


    return 0;
}

void InicializaM(int m[][AGEN],int cf,int cc)
{
    int f,c,pas;
    printf("\t\t\t\tGUADALAJARA VIAJES\n");
    printf("\t\t\tCantidad de pasajes de cada tour por agencia\n");
    do{
        printf("Ingrese codigo de agencia\n");
        scanf("%d",&c);
    }while (c<0||c>cc);
    while (c!=0)
    {
        do{
            printf("Ingrese codigo de tour\n");
            scanf ("%d",&f);
        }while (f<1||f>cf);
        do{
            printf("Ingrese cantidad de pasajes\n");
            scanf("%d",&pas);
        }while (pas<0||pas>20);

        m[f-1][c-1]+=pas;
        system("cls");
        printf("\t\t\t\tGUADALAJARA VIAJES\n");
        printf("\t\t\tcantidad de pasajes de cada tour por agencia\n");
        do{
            printf("Ingrese codigo de agencia\n");
            scanf("%d",&c);
        }while (c<0||c>cc);
    }
}

void MuestraPasXT(int m[][AGEN],int v[],int cf,int cc)
{
    int f,c;
    for(f=0;f<cf;f++)
    {
        v[f]=0;
        for(c=0;c<cc;c++)
        {
            v[f]+=m[f][c];
        }
        printf("TOUR %2d: %2d pasajeros\n",f+1,v[f]);
    }
}
