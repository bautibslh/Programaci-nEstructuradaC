/*
Confeccionar un programa que exhiba por pantalla una lista, a dos columnas,
 con los primeros 15 n�meros impares en la primera y los 15 primeros pares en la segunda, incluyendo los t�tulos.
*/

#include <stdio.h>

int main ()
{
    int i;

    printf ("IMPARES\tPARES\n");
    for (i=1;i<=30;i++)
    {
        if (i%2==0)
        {
            printf ("%d\n",i);
        }
        else
        {
            printf ("%d\t",i);
        }
    }

}
