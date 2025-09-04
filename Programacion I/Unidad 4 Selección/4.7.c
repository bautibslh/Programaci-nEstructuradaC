/*
Confeccionar un programa que solicite e ingrese 3 valores reales positivos, mayores que cero y determine e informe si forman o no triángulo.
Para ello utilizar el teorema de la desigualdad del triángulo que establece que la suma de las longitudes de cualesquiera de dos lados de un triángulo es mayor que la longitud del tercer lado.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    float n1,n2,n3;
    printf ("Ingresar tres valores reales positivos\n");
    scanf ("%f%f%f",&n1,&n2,&n3);
    if (n1>0&&n2>0&&n3>0)
    {
        if (n1+n2>=n3&&n2+n3>=n1&&n3+n1>=n2)
            printf ("El triangulo existe\n");
        else printf ("El triangulo no existe\n");
    }
    else printf("ERROR\nAlguno de los valores es negativo\n\n");
    system ("pause");
    return 0;
}
