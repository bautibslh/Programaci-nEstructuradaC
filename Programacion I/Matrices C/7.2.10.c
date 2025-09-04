#include <stdio.h>
#include <stdlib.h>
#define FIL 5
#define COL 3
/*
Ingresar por teclado valores enteros y generar una matriz de 5x3 (5 filas y 3 por columnas).
Informar:
a. La suma de los elementos de las columnas.
b. Las sumas de los elementos de las filas.
c. La suma total de los elementos.
d. El valor promedio de toda la matriz.
e. El valor promedio por columna.
f. El máximo valor de la matriz y en qué posición se encuentra (el máximo es único).
g. El mínimo valor de cada columna y en qué posición se encuentra (el mínimo es único).
Utilizar funciones para la carga y para resolver cada uno de los puntos.
*/
void Carga(int[][COL],int,int);
void SumaxCol(int[][COL],int[],int,int);
void SumaxFil(int[][COL],int[],int,int);
void SumaTotal(int[][COL],int,int);
void ValorPromedio(int[][COL],int,int);
void PromXCol(int[][COL],float [],int,int);
void Maximo(int [][COL],int,int);
void MinXCol(int [][COL],int [],int[],int,int);
int main()
{
    int mat[FIL][COL],sxc[COL],sxf[FIL],mxc[COL],pos[COL];
    float pxc[COL];
    Carga(mat,FIL,COL);
    SumaxCol(mat,sxc,FIL,COL);
    SumaxFil(mat,sxf,FIL,COL);
    SumaTotal(mat,FIL,COL);
    ValorPromedio(mat,FIL,COL);
    PromXCol(mat,pxc,FIL,COL);
    Maximo(mat,FIL,COL);
    MinXCol(mat,mxc,pos,FIL,COL);


    return 0;
}

void Carga(int m[][COL],int f,int c)
{
    int i,j,n;
    for(i=0;i<f;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("INGRESE ELEMENTO %d/%d\n",i+1,j+1);
            scanf("%d",&m[i][j]);
            //m[i][j]=n;
        }
    }
}

void SumaxCol(int m[][COL],int v[],int f,int c)
{
    int i,j;
    printf("Suma por columna\n");
    for(j=0;j<c;j++)
    {
        v[j]=0;
        for(i=0;i<f;i++)
        {
            v[j]+=m[i][j];
        }
    }
    for(i=0;i<c;i++)
        printf("COLUMNA %d=%d\n",i+1,v[i]);
}

void SumaxFil(int m[][COL],int v[],int cf,int cc)
{
    int c,f;
    printf("Suma por fila\n");
    for(f=0;f<cf;f++)
    {
        v[f]=0;
        for(c=0;c<cc;c++)
        {
            v[f]+=m[f][c];
        }
    }
    for(f=0;f<cf;f++)
    {
        printf("FILA %d=%d\n",f+1,v[f]);
    }
}

void SumaTotal(int m[][COL],int cf,int cc)
{
    int c,f,sum=0;
    for(f=0;f<cf;f++)
    {
        for(c=0;c<cc;c++)
        {
            sum+=m[f][c];
        }
    }
    printf("LA SUMA DE TODOS LOS ELEMENTOS ES: %d\n",sum);
}

void ValorPromedio(int m[][COL],int cf,int cc)
{
    int c,f,sum=0;
    for(f=0;f<cf;f++)
    {
        for(c=0;c<cc;c++)
        {
            sum+=m[f][c];
        }
    }
    printf("EL PROMEDIO DE TODOS LOS ELEMENTOS ES: %.2f\n",sum/(float)(cf*cc));
}

void PromXCol(int m[][COL],float v[],int cf,int cc)
{
    int f,c;
    for (c=0;c<cc;c++)
    {
        v[c]=0;
        for(f=0;f<cf;f++)
        {
            v[c]=v[c]+(m[f][c])/(float)cf;
        }
    }
    for(c=0;c<cc;c++)
        printf("PROM COLUMNA %d=%.2f\n",c+1,v[c]);
}

void Maximo(int m[][COL],int cf,int cc)
{
    int f,c,max,band=0,mf,mc;
    for(f=0;f<cf;f++)
    {
        for (c=0;c<cc;c++)
        {
            if (band==0)
            {
                max=m[0][0];
                mf=0;
                mc=0;
                band=1;
            }
            else if(m[f][c]>max && band!=0)
            {
                max=m[f][c];
                mf=f;
                mc=c;
            }
        }
    }
    printf("EL MAXIMO ELEMENTO ES %d\nY SU POSICION ES %d/%d\n",max,mf+1,mc+1);
}

void MinXCol(int m[][COL],int v[],int vp[],int cf,int cc)
{
    int f,c,min,band=0,minp;
    for (c=0;c<cc;c++)
    {
        min=m[0][c];
        minp=0;
        for(f=0;f<cf;f++)
        {
            if(m[f][c]<min)
            {
                min=m[f][c];
                minp=f;
            }
        }
        v[c]=min;
        vp[c]=minp+1;

    }
    for(c=0;c<cc;c++)
        printf("MINIMO EN COLUM %d= %d en posicion %d\n",c+1,v[c],vp[c]);
}
