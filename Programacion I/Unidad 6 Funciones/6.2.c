/*
�  EstaDentroDelRango: que reciba 3 enteros correspondientes a un n�mero a validar y los l�mites superior e inferior del rango.
 La funci�n debe retornar un 1 si el n�mero a validar se encuentra dentro del rango indicado o un 0 si no lo est�.

 �  LeerYValidar: que reciba los l�mites superior e inferior de un rango y retorne un n�mero que se encuentre dentro del mismo.
 (El ingreso de datos se realiza dentro de la funci�n).
 Para validar el rango utilizar la funci�n EstaDentroDelRango realizada en el punto anterior.
*/
#include <stdio.h>
#include <stdlib.h>
#define MIN 99
#define MAX 2000

int EstaDentroDelRango (int,int,int);
int LeerYValidar (int,int);

int main ()
{
    int resp,cont1=0,cont2=0,cont3=0;
    float acum=0,prom;
    resp=LeerYValidar(MIN,MAX);


    while (resp!=99)
    {
        if (EstaDentroDelRango(100,500,resp)==1)
        {
            cont1++;
        }
        else if (EstaDentroDelRango(500,1200,resp)==1)
        {
            if (resp%2==0)
                cont2++;
        }
        else if (EstaDentroDelRango(1200,2000,resp)==1)
        {
            acum+=resp;
            cont3++;

        }

        resp=LeerYValidar(MIN,MAX);
    }

    printf ("Cantidad de numeros ingresados entre 100 y 500 es %d\n",cont1);
    printf ("Cantidad de numeros pares ingresados entre 500 y 1200 es %d\n",cont2);

    if (cont3!=0)
    {
        prom=acum/cont3;
    }
    else
    {
        prom=0;
    }
    printf ("El promedio de los numeros ingresados entre 1200 y 2000 es %.2f\n",prom);

    return 0;
}

int LeerYValidar (int li,int ls)
{
    int n;
    do{
        printf ("Ingrese un numero entre 100 y 2000\n");
        scanf ("%d",&n);
    }while (EstaDentroDelRango(li,ls,n)==0);

    return n;
}

int EstaDentroDelRango(int li,int ls,int n)
{
    int cond;

    if (n>=li && n<=ls)
    {
        cond=1;
    }
    else cond=0;

    return cond;
}
