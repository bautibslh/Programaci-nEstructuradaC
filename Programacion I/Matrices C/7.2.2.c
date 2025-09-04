#include <stdio.h>
void Carga(int [][3],int,int);
void Traspuesta (int [2][3],int,int);
int main ()
{
    int m[2][3];
    Carga(m,2,3);
    Traspuesta(m,2,3);
    return 0;
}

void Carga(int m[][3],int f,int c)
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

void Traspuesta(int m[2][3],int f,int c)
{
    int i,j;

    for (i=0;i<c;i++)
    {
        for (j=0;j<f;j++)
        {
            printf ("%d\t",m[j][i]);
        }
        printf ("\n");
    }
}
