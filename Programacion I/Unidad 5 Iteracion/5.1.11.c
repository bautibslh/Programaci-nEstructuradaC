/*
Ingresar 18 valores de temperatura distintos de cero.
Se pide determinar e informar cuantas ternas (tres valores seguidos) de valores positivos y cuantas de negativos hay.¨
*/
#include <stdio.h>
#define CANT_NUM 9

int main()
{
    int i,cont_p=0,cont_n=0,terna_p=0,terna_n=0;
    float temperatura;

    for (i=1;i<=CANT_NUM;i++)
    {
        printf("Ingrese el valor de una temperatura\n");
        scanf ("%f",&temperatura);

         if (temperatura<0)
        {
            cont_n++;
            cont_p=0;
        }
         else if (temperatura>0)
        {
            cont_p++;
            cont_n=0;
        }
        if (cont_n==3)
        {
            terna_n++;
            cont_n=0;
        }
        if (cont_p==3)
        {
            terna_p++;
            cont_p=0;
        }
    }
    printf ("La cantidad de ternas de valores positivos es:%d\n",terna_p);
    printf ("La cantidad de ternas de valores negativos es:%d\n",terna_n);
    return 0;
}
