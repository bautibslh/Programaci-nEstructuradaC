//Ingresar el valor de la hora y la cantidad de horas trabajadas por un empleado.
// Calcular su sueldo tomando en cuenta que recibe un premio de $500 si trabajo más de 50 horas y, además, si trabajó más de 150 horas se le otorgan $1000 adicionales
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int canth;
    float vph,sueldo;

    printf ("Ingresar la cantidad de horas trabajadas: ");
    scanf ("%d",&canth);
    printf ("\nIngresar el valor por hora:");
    scanf ("%f",&vph);

    sueldo=canth*vph;
    if (canth>50)
        sueldo=sueldo+500;
    if (canth>150)
        sueldo+=1000;

    printf ("\nEl sueldo del empleado es:%.2f\n",sueldo);

    system ("pause");
    return 0;
}
