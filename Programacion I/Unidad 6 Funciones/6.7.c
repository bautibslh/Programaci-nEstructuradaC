#include <stdio.h>
#include <ctype.h>
/*
Confeccionar un programa que permita ingresar diversas ternas de valores enteros mayores que 0 y
menores que 99. Finalizar el ingreso cuando se informen 3 valores iguales a 96, 97 y 98.
Determinar e informar para cada terna, el mayor y el menor de los valores.
Confeccionar y utilizar una función con parámetros llamada MayorMenor,
que permita calcular el menor o el mayor valor de la terna según un parámetro de configuración.
*/
int CargaValor(int);
int esValido(int,int,int);
void muestraMayorMenor(int,int,int);
int main()
{
    int n1,n2,n3;

    n1=CargaValor(1);
    n2=CargaValor(2);
    n3=CargaValor(3);

    while (esValido(n1,n2,n3)!=1)
    {
        muestraMayorMenor(n1,n2,n3);

        n1=CargaValor(1);
        n2=CargaValor(2);
        n3=CargaValor(3);
    }

    return 0;
}

int CargaValor(int i)
{
    int n;

    if (i==1)
    {
        do{
            printf ("Ingrese el primer valor\n");
            scanf ("%d",&n);
        }while (n<=0||n>=99);
    }
    if (i==2)
    {
        do{
            printf ("Ingrese el segundo valor\n");
            scanf ("%d",&n);
        }while (n<=0||n>=99);
    }
    if (i==3)
    {
        do{
            printf ("Ingrese el tercer valor\n");
            scanf ("%d",&n);
        }while (n<=0||n>=99);
    }
    return n;
}

int esValido(int n1,int n2, int n3)
{
    int cond=0;
    if (n1==96 && n2==97 && n3==98)
    {
        cond=1;
    }

    return cond;
}

void muestraMayorMenor(int n1,int n2,int n3)
{
    int resul;
    char c;
    printf ("Desea saber el menor o el mayor?(m o M)\n");
    fflush (stdin);
    scanf ("%c",&c);

    if (c=='m')
    {
        if (n1<n2 && n1<n3)
        {
            resul=n1;
        }
        if (n2<n1 && n2<n3)
        {
            resul=n2;
        }
        if (n3<n1 && n3<n2)
        {
            resul=n3;
        }

        printf ("El menor es %d\n",resul);
    }
    else if (c=='M')
    {
        if (n1>n2 && n1>n3)
        {
            resul=n1;
        }
        if (n2>n1 && n2>n3)
        {
            resul=n2;
        }
        if (n3>n1 && n3>n2)
        {
            resul=n3;
        }

        printf ("El mayor es %d\n",resul);
    }


}
