#include<stdio.h>

int main()
{
    int contador=0,i,nota,leg;
    for (i=1;i<=20;i++)
    {
        printf ("Ingrese el legajo del alumno\n");
        scanf ("%d",&leg);
        printf ("Ingrese la nota del alumno\n");
        scanf ("%d",&nota);
        
        if (nota<4)
        {
            contador++;
        }
        if (nota>=7)
        {
        printf ("EL ALUMNO CON LEGAJO %d HA PROMOCIONADO\n",leg);
        
        }
        
        
    }
    
    printf ("La cantidad de aplazos es: %d\n",contador);
    return 0;
}