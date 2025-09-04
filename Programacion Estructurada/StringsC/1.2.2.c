/*Ingresar dos Strings, uno con el nombre y
el otro con el apellido de una persona.
Utilizando las
funciones de la biblioteca string.h
generar un tercer string formado por:
NOMBRE, APELLIDO (nombre
coma espacio y apellido) y mostrarlo*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ()
{
    char nombre[16],apellido[16],resul[31];

    printf ("INDICAR\nNOMBRE:\n");
    fflush(stdin);
    gets(nombre);
    printf ("APELLIDO:\n");
    fflush(stdin);
    gets(apellido);

    strcpy(resul,nombre);
    strcat(resul,", ");
    strcat(resul,apellido);

    printf("%s",resul);
    return 0;
}
