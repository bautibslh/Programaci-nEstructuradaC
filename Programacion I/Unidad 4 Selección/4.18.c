//Confeccionar un programa que permita ingresar la fecha actual (día, mes y año) y la fecha de nacimiento de una persona (día, mes y año). Con ambos datos debe calcular la edad de dicha persona.
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int dia,mes,anio,dian,mesn,anion,edad;
    printf ("Ingrese la fecha actual en formato dia/mes/anio\n");
    scanf ("%d%d%d",&dia,&mes,&anio);

    printf ("\nIngrese la fecha de nacimiento en formato dia/mes/anio\n");
    scanf ("%d%d%d",&dian,&mesn,&anion);

    if (mesn<mes)
    edad=anio-anion;
    else
    if (mes==mesn)
        if (dian<=dia)
        edad=anio-anion;
        else
        edad=anio-anion-1;
    else
        edad=anio-anion-1;

    printf ("La edad de la persona es: %d\n\n",edad);

    system ("pause");
    return 0;
}
