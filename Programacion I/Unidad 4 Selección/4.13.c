/*
Un fabricante de repuestos para tractores ha descubierto que ciertos artículos identificados por los números de catálogo 12121 al 18081; 30012 al 45565 y 67000 al 68000 son defectuosos.
Se desea confeccionar un programa al que informándole el número de catálogo indique si el artículo es o no defectuoso.
Los artículos del catálogo van desde el 1200 al 90000. Si se ingresa otro número informar “FUERA DE CATALOGO”.
*/

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int num;
    printf ("Ingresar el numero de catalogo:");
    scanf ("%d",&num);

    if (num>=1200 && num <=90000)
    {
        if (num>=12121 && num<=18081||num>=30012 && num<=45565||num>=67000 && num<=68000)
        {
            printf("\nEL ARTICULO ES DEFECTUOSO\n");
        }
        else printf ("\nEL ARTICULO NO ES DEFECTUOSO\n");
    }
    else printf ("\nFUERA DE CATALOGO\n");

    system ("pause");
    return 0;
}
