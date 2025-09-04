#include<stdio.h>

int main()
{
    int n,suma=0,i;
    printf ("Ingrese la cantidad de numeros que desea sumar (N)\n");
    scanf ("%d",&n);
    for (i=1;i<=n;i++)
    {
        suma+=i;
    }
    printf ("La suma es %d\n",suma);
    return 0;
}