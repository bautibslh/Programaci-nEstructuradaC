#include <stdio.h>
#include <stdlib.h>
/*
Se ingresa valores positivos entre 1 y 50, finalizando el ingreso con el valor -10, para ello generar una función que valide dicho ingreso. Calcular:

  a. Cuántos números son primos.

  b. Cantidad de números pares.

  c. Promedio de los números impares.

Utilizar las siguientes funciones:

 •  Resto: recibe por parámetro el Dividendo y el Divisor; Retorna el resto
 •  EsPar: recibe por parámetro un número; Retorna 1 si es Par, 0 si es Impar; Invoca a la función Resto
 •  EsPrimo: recibe por parámetro un número; Retorna 1 si es primo, 0 si no es primo; Invoca a la función Resto. (un número es primero si solo es divisible por 1 y por sí mismo)
 •  Promedio: recibe por parámetro la suma y el contador; Retorna el promedio si contador > 0 sino Retorna 0.
*/
int CargaDatos (void);
int Resto (int,int);
int EsPar (int);
int EsPrimo (int);
float Promedio (int,int);

int main ()
{
    int num,cPrimos=0,cPares=0,acum=0,cImp=0;
    float prom;

    num = CargaDatos();

    while (num!=-10)
    {

        if (EsPrimo(num)==1)
        {
            cPrimos++;
        }
        if (EsPar(num)==1)
        {
            cPares++;
        }
        if (EsPar(num)==0)
        {
            acum+=num;
            cImp++;
        }
        num = CargaDatos();
    }

    prom=Promedio(acum,cImp);

    printf ("//////////////////////////\n");
    printf ("Cantidad de numeros primos: %d\n",cPrimos);
    printf ("Cantidad de numeros pares: %d\n",cPares);
    printf ("Promedio de los impares: %.2f\n",prom);

    return 0;
}

int CargaDatos()
{
    int n,error=0;
        do{
            if (error==1)
            {
                printf ("Error numero invalido\n");
            }
            error=0;
            printf ("Ingrese un valor positivo entre 1 y 50 (Finaliza con -10)\n");
            scanf ("%d",&n);
            error=1;

        }while (!(n>=1 && n<=50|| n== -10));
    return n;
}

int EsPrimo(int n)
{
    int i,band=1;

    for (i=2;i<n;i++)
    {
        if (Resto(n,i)==0)
        {
            band=0;
        }

    }
    return band;
}

int EsPar(int n)
{
    int cond=0;
    if (n%2==0)
    {
        cond=1;
    }
  return cond;
}

int Resto(int dividendo, int divisor)
{
    int r;

    r=dividendo%divisor;

    return r;
}

float Promedio(int suma,int contador)
{
    float prom=0;
    if (contador!=0)
    {
        prom=suma/(float)contador;
    }
    return prom;
}
