/*
Confeccionar un programa que permita convertir grados sexagesimales a radianes y viceversa, según el valor de un código que se ingresa junto al valor.
Si codigo = 1 se ingresan grados, si es 2 se ingresan radianes.
1 radian =
(180/PI)*grados
1 grado =
(pi/180)
 radianes
*/
#include <stdio.h>
#include <stdlib.h>
#define PI 3.14
int main ()
{
    int cod;
    float valor,radian,grado;

    printf ("Ingresar el codigo (1=grados o 2=radian)\n");
    scanf ("%d",&cod);
    printf ("Ingresar el valor que desea convertir\n");
    scanf ("%f",&valor);

    if (cod==1)
    {
        radian=(PI/180)*valor;
        printf ("El valor convertido en radianes es:%f\n",radian);
    }
    else if (cod==2)
    {
        grado=(180/PI)*valor;
        printf ("El valor convertido en grados es:%f\n",grado);
    }
    else printf ("ERROR DE CODIGO\n\n");

    system ("pause");
    return 0;
}
