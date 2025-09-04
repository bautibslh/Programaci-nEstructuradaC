// Se ingresan 3 números enteros. Informarlos en orden creciente.
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n1,n2,n3,menor,mediano,mayor;
    printf("Ingresar tres numeros enteros\n");
    scanf ("%d%d%d",&n1,&n2,&n3);
    if (n1<n2&&n1<n3)
    {
        menor=n1;
        if (n2<n3)
        {
            mediano=n2;
            mayor=n3;
        }
        else{
            mediano=n3;
            mayor=n2;
        }
    }
    if (n2<n3&&n2<n1)
    {
        menor=n2;
        if(n1<n3){
            mediano=n1;
            mayor=n3;
        }
        else{
            mediano=n3;
            mayor=n1;
        }
    }
    if (n3<n1&&n3<n2)
    {
        menor=n3;
        if (n1<n2)
        {
            mediano=n1;
            mayor=n2;
        }
        else {
            mediano=n2;
            mayor=n1;
        }
    }
    printf ("El orden de los numeros de manera creciente es: %d,%d,%d\n\n",menor,mediano,mayor);


    system ("pause");
    return 0;
}
