#include<stdio.h>

int main()
{
    int i,suma;
    suma=0;
    for (i=100;i>=50;i-=5)
    {
        suma+=i;
    }
    printf("La sumatoria es: %d \n",suma);
    return 0;
}