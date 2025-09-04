#include <stdio.h>

int main ()
{
    int i,n,j,k;

    printf ("Ingresar un numero entero mayor a 0\n");
    scanf ("%d",&n);

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n-i;j++)
        {
           printf(" ");
        }
        for (k=1;k<=2*i-1;k++)
        {
            printf ("*");
        }
        printf ("\n");
    }
    i=0;
    j=0;
    k=0;

    for (i=n;i>=1;i--)
    {
        for(j=1;j<=n-i;j++)
        {
            printf (" ");
        }
        for (k=2*i-1;k>=1;k--)
        {
            printf ("*");
        }
     printf ("\n");
    }
}

