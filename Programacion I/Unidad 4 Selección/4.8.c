//Realizar un programa que ingrese dos n�meros e indique si el primer n�mero es divisible por el segundo.
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int n1,n2;
    printf ("Ingrese dos numeros enteros\n");
    scanf ("%d%d",&n1,&n2);

    if (n1%n2==0)
        printf ("SI es divisible\n\n");
    else printf ("NO es divisible\n\n");
    system ("pause");
    return 0;
}
