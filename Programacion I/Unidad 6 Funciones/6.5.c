#include <stdio.h>
#include <stdlib.h>
/*
Confeccionar un programa que permita ingresar varias ternas de valores a punto flotante,
que finalice al ingresar una terna con los valores ORDENADOS en forma creciente.
Para cada terna exhibir la siguiente pantalla:

Según la opción deseada debe aparecer en pantalla el resultado, sin borrar el menú. No admitir otros valores de opción.
Confeccionar y utilizar una función PARA CADA UNA de las opciones y otra para detectar la condición final.
*/
float CargaValor(int);
int estaOrdenado (float,float,float);
float MayorValor(float,float,float);
float Promedio (float,float,float);
float Suma (float,float,float);
int MostrarMenu(void);

int main ()
{
    int i,op,cond=0;
    float n1,n2,n3,mayValor,prom,sum;

    n1=CargaValor(1);
    n2=CargaValor(2);
    n3=CargaValor(3);

    while (estaOrdenado(n1,n2,n3)!=1 && cond!=1)
    {
        //cond=estaOrdenado(n1,n2,n3);
        //printf ("\n\nLA CONDICION ES: %d\n",cond);
    op=MostrarMenu();

        switch (op)
            {
                case 1:{
                        mayValor=MayorValor(n1,n2,n3);
                        printf ("El mayor valor es: %.2f\n",mayValor);
                        break;
                       }
                case 2:{
                        prom=Promedio(n1,n2,n3);
                        printf ("El promedio es: %.2f\n",prom);
                        break;
                       }
                case 3:{
                        sum=Suma(n1,n2,n3);
                        printf ("La suma es: %.2f\n",sum);
                        break;
                       }
                case 4:{
                        cond=1;
                       }
            }

    if (cond==0)
    {
        n1=CargaValor(1);
        n2=CargaValor(2);
        n3=CargaValor(3);
    }
    }

    return 0;
}

float CargaValor(int n)
{
    float val;
    if (n==1)
    {
        printf ("///////////////////////////////\n");
        printf ("Ingrese el primer valor de la terna\n");
        scanf ("%f",&val);
    }
    if (n==2)
    {
        printf ("Ingrese el segundo valor de la terna\n");
        scanf ("%f",&val);
    }
    if (n==3)
    {
        printf ("Ingrese el tercer valor de la terna\n");
        scanf ("%f",&val);
    }

    return val;
}

int estaOrdenado(float n1,float n2,float n3)
{
    int cond=0;

    if (n1<n2 && n2<n3)
    {
        cond=1;
    }
    return cond;
}

float MayorValor(float n1,float n2,float n3)
{
    float v=0;

    if (n1>n2 && n1>n3)
    {
        v=n1;
    }
    if (n2>n1 && n2>n3)
    {
        v=n2;
    }
    if (n3>n1 && n3>n2)
    {
        v=n3;
    }
    return v;
}

float Promedio (float n1,float n2,float n3)
{
    float p=0;

    p+=n1;
    p+=n2;
    p+=n3;

    p=p/3.;

    return p;
}

float Suma (float n1,float n2, float n3)
{
    float s;
    s=n1;
    s+=n2;
    s+=n3;

    return s;
}
int MostrarMenu(void)
{
    int op;
    printf ("\n**OPCIONES POSIBLES**\n\n");
    printf ("1 - Mayor valor\n2 - Promedio\n3 - Suma\n4 - Finalizar\n\n");
    printf ("Digite su opcion\n\n");
    do{
            scanf ("%d",&op);
    }while (op<1||op>4);
    return op;
}
