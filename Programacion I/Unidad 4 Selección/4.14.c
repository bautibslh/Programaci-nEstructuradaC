/*
La farmacia Sindical efectúa descuentos a sus afiliados según el importe de la compra con la siguiente escala:

a. menor de $55 el descuento es del 4.5%.
b. entre $55 y $100 el descuento es del 8%.
c. más de $100 el descuento es del 10.5%.

Confeccionar un programa que reciba un importe e informe: el descuento y el precio neto a cobrar, con mensajes aclaratorios.
*/
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    float importe,dto,precio;
    printf ("Ingrese el importe de la compra\n");
    scanf ("%f",&importe);

    if (importe<55)
    {
        dto=importe*(4.5/100);
    }
    else {
        if (importe<100)
            dto=importe*(8/100.);
        else
            dto=importe*(10.5/100);
    }
    precio=importe-dto;

    printf ("DESCUENTO: %.2f\nTOTAL A PAGAR:%.2f\n\n",dto,precio);
    system ("pause");
    return 0;
}
