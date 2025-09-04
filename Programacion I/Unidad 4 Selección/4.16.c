/*
Un negocio vende distintos art�culos identificados por un c�digo, seg�n se muestra:

�  c�digo 1; 10; 100: 10 pesos la unidad.
�  c�digo 2; 22; 222: 7 pesos la unidad. La caja de 10 unidades vale 65 pesos.
�  c�digo 3; 33: 3 pesos la unidad. Si la compra es por m�s de 10 unidades se hace un descuento del 10% sobre el total de la compra.
�  c�digo 4; 44: 1 peso la unidad.

Confeccionar un programa que ingrese como dato el c�digo de un art�culo y la cantidad a comprar y se informe el importe de la compra, con las siguientes leyendas:

ART�CULO xxxxx CANTIDAD xxxx IMPORTE A PAGAR $ xxxx.xx
*/
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int cod,cant;
    float precio;
    printf ("Ingresar el codigo del articulo:\n");
    scanf ("%d",&cod);
    printf ("Ingresar la cantidad que desea comprar:\n");
    scanf ("%d",&cant);

    switch (cod)
    {
    case 1:
    case 10:
    case 100:
        precio=cant*10;
        break;
    case 2:
    case 22:
    case 222:
        precio=cant/10*65+cant%10*7;
        break;
    case 3:
    case 33:
        if (cant>10)
            precio=cant*3*0.9;
        else precio=cant*3;
        break;
    case 4:
    case 44:
        precio=cant;
        break;
    default: printf ("\nCODIGO DEL ARTICULO ERRONEO\n");
             return 0;
    }

    printf ("\nARTICULO %d\tCANTIDAD %d\tIMPORTE A PAGAR:$%.2f\n",cod,cant,precio);
    printf ("\n\n");
    system ("pause");
    return 0;
}
