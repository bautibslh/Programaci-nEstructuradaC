#include<stdio.h>

int main()
{
    int suma_1=0,contador=0,suma_2=0,n,nro,i;
    printf ("Ingrese la cantidad de numeros: \n");
    scanf ("%d",&n);
    
    for (i=1;i<=n;i++)
    {
    printf ("Ingrese el valor del numero: \n");
    scanf ("%d",&nro);
    
    if (nro%3==0)
    {
        suma_1+=nro;
    }
    
    if (nro%5==0)
    {
       contador++;
    }
    if (i%2==0)
    {
       suma_2+=nro;
    }
    }
    printf ("La suma de los multiplos de 3 es: %d\nLa cantidad de multiplos de 5 es: %d\nLa sumatoria de los valores ingresados en orden par es: %d\n",suma_1,contador,suma_2);
    
    
    
    return 0;
}