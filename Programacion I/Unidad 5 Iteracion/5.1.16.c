#include <stdio.h>
#define CANT_ALUM 10
//Se ingresan DNI y la nota promedio de 10 alumnos. Determinar el DNI del alumno de mayor nota promedio (considerar único).
int main ()
{
    int i,dni,dni_max=0;
    float nota,nota_max=0;
    for (i=1;i<=CANT_ALUM;i++)
    {
        printf ("Ingrese el dni:\n");
        scanf ("%d",&dni);
        printf ("Ingrese la nota:\n");
        scanf ("%f",&nota);


        if (nota_max<nota)
        {
            nota_max=nota;
            dni_max=dni;
        }

    }
    printf ("EL ALUMNO CON MAYOR NOTA PROMEDIO ES %d con %.2f\n\n",dni_max,nota_max);
    return 0;
}
