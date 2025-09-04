#include <stdio.h>
void Carga(int[3][3],int,int);

int main ()
{
    int mat[3][3];
    Carga(mat,3,3);
    return 0;
}

void Carga(int m[3][3],int f,int c)
{
    int i,j,n,e;

    for (i=0;i<f;i++)
    {
        for (j=0;j<c;j++)
        {
            printf ("INGRESE ELEMENTO %d/%d\n",i+1,j+1);
            scanf("%d",&n);
            m[i][j]=n;
        }
    }
    printf ("INGRESE ESCALAR\n");
    scanf ("%d",&e);
    printf("MATRIZ\n");
    for (i=0;i<f;i++)
    {
        for (j=0;j<c;j++)
        {
            printf ("%d\t",m[i][j]*e);
        }
        printf ("\n");
    }
}
