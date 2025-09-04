#include <stdio.h>
/*
Realizar una función que, dado un mes y un año,
calcule la cantidad de días de dicho mes.
El año se utilizará en el caso de que el mes sea febrero ya que los años bisiestos
tienen 29 días en lugar de 28. Un año es bisiesto cuando:
(el año es divisible por 4 y NO por 100) o (el año es divisible por 400).
*/
int IngresaMes(void);
int IngresaAnio(void);
int CantDias(int,int);

int main ()
{
    int mes,anio,dias;
    printf ("/////////////////////////////////////////////////////");
    mes=IngresaMes();
    anio=IngresaAnio();
    dias=CantDias(mes,anio);
    printf ("\nLa cantidad de dias del mes %d del anio %d es: %d\n",mes,anio,dias);
    return 0;
}

int IngresaMes(void)
{
    int m;
    do{
       printf ("\nMES: ");
       scanf ("%d",&m);
       printf ("\n");
    }while (m<1||m>12);

    return m;
}

int IngresaAnio(void)
{
    int a;
    do{
        printf ("ANIO: ");
        scanf ("%d",&a);
        printf ("\n");
    }while (a<1582||a>2100);

    return a;
}

int CantDias(int m, int a)
{
    int d;
    if (m==2)
    {
        if (a%4==0 && a%100!=0 || a%400==0)
        {
            d=29;
        }
        else
        {
            d=28;
        }
    }
    else if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
    {
        d=31;
    }
    else
    {
        d=30;
    }
    return d;
}
