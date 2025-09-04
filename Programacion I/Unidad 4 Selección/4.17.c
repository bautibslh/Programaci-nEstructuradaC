/*
Confeccionar un programa que pueda determinar el importe a pagar por una prestaci�n m�dica seg�n su c�digo. Los importes se cobran seg�n la siguiente tabla:

C�digo  Importe

A       20

D       40

F       60

M       150

T       150

Se debe ingresar el n�mero de historia del paciente y el c�digo de la prestaci�n. Se debe emitir un ticket con el n�mero de la historia, el c�digo y el importe a pagar
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main ()
{
    char cod;
    int nHstria;
    float importe;

    printf ("Ingresar el numero de historia del paciente:\n");
    scanf ("%d",&nHstria);
    fflush(stdin);
    printf ("Ingresar el codigo de la prestacion:\n");
    scanf ("%c",&cod);
    cod=toupper (cod);
    switch (cod)
    {
    case 'A':
        importe=20;
        break;
    case 'D':
        importe=40;
        break;
    case 'F':
        importe=60;
        break;
    case 'M':
    case 'T':
        importe=150;
        break;
    default:
        printf ("\n***ERROR. CODIGO INVALIDO.***\n");
        return 0;
    }
    printf ("---NUMERO DE HISTORIA---%d---\n---CODIGO---%c---\n---IMPORTE A PAGAR---$%.2f---\n\n",nHstria,cod,importe);
    system ("pause");
    return 0;
}
