/*
Confeccionar un programa que permita ingresar un carácter alfanumérico y determine
e informe si lo ingresado corresponde a una vocal, con el mensaje “VOCAL”. y su correspondiente valor numérico en ASCII.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main ()
{
    char letra,letra2;

    printf("Ingrese un caracter alfanumerico\n");
    scanf ("%c",&letra);

    letra2=tolower(letra);

    if (letra2=='a'||letra2=='e'||letra2=='i'||letra2=='o'||letra2=='u')
        printf ("La letra ingresada (%c) es una VOCAL\nY su correspondiente valor en numero ASCII es:%d\n",letra,letra);
    else
        printf ("La letra ingresada (%c) NO es una VOCAL\n\n",letra);

    system ("pause");
    return 0;
}
