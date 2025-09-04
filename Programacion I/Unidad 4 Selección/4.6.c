/*
Confeccionar un programa que permita ingresar 4 números enteros, de a uno por vez y determine el menor valor y su número de orden.
Informe los valores ingresados e identifique al menor con mensaje aclaratorio.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1,n2,n3,n4,menor,pos;
    printf ("Ingresar un numero entero\n");
    scanf ("%d",&n1);
    printf ("Ingresar un numero entero\n");
    scanf ("%d",&n2);
    printf ("Ingresar un numero entero\n");
    scanf ("%d",&n3);
    printf ("Ingresar un numero entero\n");
    scanf ("%d",&n4);

    if (n1<n2&&n1<n3&&n1<n4)
    {
        menor=n1;
        pos=1;
    }
    if (n2<n1&&n2<n3&&n2<n4)
    {
        menor=n2;
        pos=2;
    }
    if (n3<n1&&n3<n2&&n3<n4)
    {
        menor=n3;
        pos=3;
    }
    if (n4<n1&&n4<n3&&n4<n2)
    {
        menor=n4;
        pos=4;
    }
    printf ("VALORES INGRESADOS:\n%d \n%d \n%d \n%d \nEL MENOR ES:%d\nSU POSICION ES:%d\n\n",n1,n2,n3,n4,menor,pos);
    system ("pause");
    return 0;
}
