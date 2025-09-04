//Escribir un programa que solicite el año y el número de mes y nos informe cuantos días tiene dicho mes.
// Debemos considerar que el año puede ser bisiesto. Un año es bisiesto cuando es divisible por 4 y no por 100 o el año es divisible por 400.
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int anio,mes,dias;
    printf ("Ingresar el anio\n");
    scanf ("%d",&anio);
    printf ("Ingresar el mes(numero)\n");
    scanf ("%d",&mes);

    if (mes==2)
    {
        if ((anio%4==0&&anio%100!=0)||anio%400==0)
            dias=29;
        else
            dias=28;
    }
    else if (mes==1||mes==3||mes==5||mes==7||mes==8||mes==10||mes==12)
        dias=31;
    else
        dias=30;

    printf ("La cantidad de dias del mes %d en el anio %d es:%d\n\n",mes,anio,dias);

    system ("pause");
    return 0;
}
