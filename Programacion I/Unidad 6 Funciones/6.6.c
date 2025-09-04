#include <stdio.h>
#include <stdlib.h>
/*
Confeccionar un programa que permita determinar e informar en
 cuántos de los números enteros comprendidos entre 10001 y 90009 existen más cifras 3 que 4.
  Debe existir por lo menos, un 4 para que sea considerado el número como válido.
  Para resolverlo confeccionar una función llamada CIFRAS,
 que pueda determinar cuántas cifras “n” existen en un número de 5 cifras.
*/
//int CargaYValidaNum(void);
int cuentaCifras(int,int);

int main()
{
    int cont3=0,cont4=0,num,i,contTotal=0;

    //num=CargaYValidaNum();
    for (i=10001;i<=90009;i++)
    {
        cont3=cuentaCifras(i,3);
        cont4=cuentaCifras(i,4);

            if (cont4>0 && cont3>cont4)
            {
                contTotal++;
            }
    }
    printf("La cantidad de numeros que tienen mas cifra 3 que 4 es: %d\n",contTotal);
    return 0;
}

int cuentaCifras(int i, int cifra)
{
    int cont=0;
    while (i>0)
    {
        if (i%10==cifra)
        {
            cont++;
        }
        i/=10;
       // printf ("%d\n",i);
    }

    return cont;

}
