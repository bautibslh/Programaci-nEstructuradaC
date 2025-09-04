#include <stdio.h>

int main ()
{
    int i,n,j;
    printf ("Ingresar un numero entero mayor a 0\n\n");
    scanf ("%d",&n);

    if (n>0&&n<=6)
    {
        for (i=1;i<=n;i++)
        {
        printf ("\t");
            for (j=1;j<=i;j++)
            {
                printf ("*");
            }
        printf ("\n");
        }
    }
    else
        printf ("ERROR NUMERO INVALIDO\n");
}
