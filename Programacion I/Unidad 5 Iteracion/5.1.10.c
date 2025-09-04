#include <stdio.h>

/*
Confeccionar un programa que: solicite el ingreso de un valor entero N < 12 y luego una lista de N números reales sobre la cual debe calcular:

a.  el promedio de los positivos.
b.  el promedio de los negativos.
c.  la cantidad de ceros.

Si el valor ingresado N es mayor que 12 informar 'VALOR EXCEDIDO” y si es menor o igual a 0 informar “CANTIDAD INVALIDA”.
*/

int main ()
{
    int i,n,cont_0=0,cont_p=0,cont_n=0;
    float suma_p=0,suma_n=0,num;

    printf ("Ingrese un valor entero menor a 12\n");
    scanf ("%d",&n);

    if (n<=0)
    {
        printf ("CANTIDAD INVALIDA\n");
    }
    else if (n>12)
    {
        printf ("VALOR EXCEDIDO\n");
    }
    else
    {
        for (i=1;i<=n;i++)
        {
            printf ("Ingrese un valor real\n");
            scanf ("%f",&num);

            if (num<0)
            {
                cont_n++;
                suma_n+=num;
            }
            else if (num>0)
            {
                cont_p++;
                suma_p+=num;
            }
            else
            {
                cont_0++;
            }
        }
    }
    printf ("EL PROMEDIO DE LOS NUMEROS POSITIVOS ES: %.2f\n",suma_p/cont_p);
    printf ("EL PROMEDIO DE LOS NUMEROS NEGATIVOS ES: %.2f\n",suma_n/cont_n);
    printf ("LA CANTIDAD DE CEROS ES: %d",cont_0);
}
