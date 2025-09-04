#include<stdio.h>
#define CANTIDAD_ALUMNOS 45
int main()
{
    int suma_1=0,suma_2=0,cont_1=0,cont_2=0,edad,i;
    float estat;
    for (i=1;i<=CANTIDAD_ALUMNOS;i++)
    {
        printf ("Inngrese la edad del alumno:\n");
        scanf ("%d",&edad);
        printf ("Ingresa la estatura del alumno (metros):  \n");
        scanf ("%f");
        
        suma_1+=edad;
        suma_2+=estat;
        
        if (edad>10)
        cont_1++;
        
        if (estat<1.40)
        cont_2++;
        
    }
    printf ("EDAD PROMEDIO: %.2f\n",(float)suma_1/CANTIDAD_ALUMNOS);
    printf ("ESTATURA PROMEDIO: %.2f\n",(float)suma_2/CANTIDAD_ALUMNOS);
    printf ("CANTIDAD DE ALUMNOS MAYORES DE 10 ANIOS: %d\n",cont_1);
    printf ("CANTIDAD DE ALUMNOS QUE MIDEN MENOS DE 1.4Om: %d\n",cont_2);
    
    return 0;
}