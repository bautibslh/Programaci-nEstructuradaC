#include <stdio.h>
//Ingresar un número entero mayor a 0. Debe dibujar una pirámide con * con tantas filas como el número indicado.
// En cada fila se va incrementando la cantidad de asteriscos de 2 en 2.
// Por ejemplo si se ingresa el número 5 debe mostrar en pantalla:
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
}
