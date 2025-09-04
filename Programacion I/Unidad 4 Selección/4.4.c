/*
Ingresar 3 valores reales y:

a. Si los dos primeros son mayores al tercero informar “MAYORES AL TERCERO”

b. Si los tres son iguales informar “TRES IGUALES”

c. Si alguno de los dos primeros es menor al tercero informar “ALGUNO ES MENOR”
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1,n2,n3;
    printf("Ingresar tres numeros enteros\n");
    scanf ("%d%d%d",&n1,&n2,&n3);
    if (n1>n3 && n2>n3)
        printf ("Los primeros dos numeros (%d y %d)son mayores al tercero (%d)\n",n1,n2,n3);
    if (n1==n2&&n2==n3)
        printf ("Los tres numeros(%d,%d,%d) son iguales\n",n1,n2,n3);
    if (n1<n3||n2<n3)
        printf("Alguno de los dos primeros(%d y %d) es menor al primero(%d)\n\n",n1,n2,n3);
    system ("pause");
    return 0;
}
