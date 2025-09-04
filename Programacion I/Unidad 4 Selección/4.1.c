//Determinar el mayor entre 3 numeros
#include <stdio.h>

int main ()
{
    int n1,n2,n3;
    printf("Ingresar tres numeros enteros positivos\n");
    scanf ("%d%d%d",&n1,&n2,&n3);
    if (n1>n2&&n1>n3)
    {
        printf("El primer numero ingresado es el mayor\n");
    }
    else
        if (n2>n3){
        printf ("El segundo numero ingresado es el mayor\n");
        }
        else
        {
            printf ("El tercer numero ingresado es el mayor\n");
        }
    return 0;
}
