#include <stdio.h>
#define COL 4
void Carga(int m[][COL],int,int);
void GeneraVector (int m[][COL],int[],int,int);
int main ()
{
    int mat[5][COL],vec[5];
    Carga(mat,5,COL);
    GeneraVector(mat,vec,5,COL);
    return 0;
}

void Carga(int m[][COL],int f,int c)
{
    int i,j,n;
    for (i=0;i<f;i++)
    {
        for(j=0;j<c;j++)
        {
            printf ("Ingrese elemento %d %d\n",i+1,j+1);
            scanf ("%d",&n);
            m[i][j]=n;
        }
    }
}

void GeneraVector(int m[][COL],int v[],int f,int c)
{
    int i,j,k,sum=0;
    for (i=0;i<f;i++)
    {
        for (j=0;j<c;j++)
        {
            sum+=m[i][j];
        }
        v[i]=sum;
        sum=0;
    }
    printf ("VECTOR\n");
    for (k=0;k<f;k++)
    {
        printf ("%d\n",v[k]);
    }
}
