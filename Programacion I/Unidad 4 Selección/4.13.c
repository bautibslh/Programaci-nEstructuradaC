/*
Un fabricante de repuestos para tractores ha descubierto que ciertos art�culos identificados por los n�meros de cat�logo 12121 al 18081; 30012 al 45565 y 67000 al 68000 son defectuosos.
Se desea confeccionar un programa al que inform�ndole el n�mero de cat�logo indique si el art�culo es o no defectuoso.
Los art�culos del cat�logo van desde el 1200 al 90000. Si se ingresa otro n�mero informar �FUERA DE CATALOGO�.
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
