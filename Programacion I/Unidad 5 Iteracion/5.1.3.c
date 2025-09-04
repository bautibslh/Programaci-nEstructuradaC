#include <stdio.h>
#define CANT_NUM 50
int main (void)
{
    int i,num,suma=0,contador=0;

    for (i=1;i<=CANT_NUM;i++)
    {
        printf ("Ingrese un numero\n");
        scanf ("%d",&num);

        if (num%2==0)
        {
            suma+=num;
            contador++;
        }

    }
    printf ("El promedio es %.2f",suma/(float)contador);

    return 0;
}
