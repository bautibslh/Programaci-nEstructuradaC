//Confeccionar un programa que pueda determinar de 3 números enteros que se ingresan si alguno de ellos es igual a la suma de los otros dos.
#include <stdio.h>

int main ()
{
    int n1,n2,n3;
    printf("Ingresar tres numeros enteros\n");
    scanf ("%d%d%d",&n1,&n2,&n3);
    if (n1==n2+n3||n2==n1+n3||n3==n2+n1)
    {
        printf("Alguno es igual a la suma de los otros dos\n");
    }
    else
        printf ("Ninguno es igual  a la suma de los otros dos\n");
    return 0;
}
