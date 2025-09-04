/*
Un negocio de artículos de computación vende DVDs según la siguiente escala de precios:

•  sueltos, entre 1 y 9 a $15 c/u.
•  la caja de 10 cuesta $120.
•  la caja de 50 cuesta $500.

Si la compra excede las 100 unidades se efectúa un descuento del 10%.

NOTA: se aceptan compras entre 1 y 500 DVDs.

Se pide que se ingrese una cantidad de DVDs que se quiere comprar y calcule e informe el importe a pagar.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cant,caja_50,caja_10;
    float precio;
    printf ("Ingrese la cantidad de DVDs que quiere comprar:");
    scanf ("%d",&cant);

    if (cant>=1 && cant<=500)
    {
        if (cant>=50)
        {
        caja_50=cant/50;
        cant=cant%50;
        caja_10=cant/10;
        cant=cant%10;
        }
        else
        {
            caja_10=cant/10;
            cant=cant%10;
            caja_50=0;
        }
    }
    else {
            printf ("\nNo se aceptan compras mayores a 500 unidades\n");
            return 0;
    }

    if (caja_50>=2)
    {
        precio=(caja_50*500+caja_10*120+cant*15)*0.90;
    }
    else
        precio=(caja_50*500+caja_10*120+cant*15);
    printf ("\n**INFORME**\n**TOTAL A PAGAR**:$%.2f\n\n",precio);
    system ("pause");
    return 0;
}
