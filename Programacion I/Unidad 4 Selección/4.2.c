//Dados tres números determinar e informar con un mensaje si el primer número ingresado es menor que los otros dos.
#include <stdio.h>

int main()
{
    int n1,n2,n3;
    printf("Ingresar tres numeros enteros\n");
    scanf ("%d%d%d",&n1,&n2,&n3);
    if (n1<n2&&n2<n3)
        printf("El primer numero (%d) ingresado es menor que los otros dos\n",n1);
    else
        printf ("El primer numero (%d) ingresado NO es menor que los otros dos\n",n1);
    return 0;
}
