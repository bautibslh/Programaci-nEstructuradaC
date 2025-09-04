/*Se sabe que como máximo en una comisión de Elementos de Programación hay 80 alumnos. De cada
alumno se conoce:
• Número de DNI (entero).
• Apellido y Nombre (80 caracteres).
• Nota1, Nota2 (entero).
• Nota Promedio (real, calculado según Nota1 y Nota2).
Se solicita:
a. Declarar un tipo de dato que contenga la información del alumno.
b. Declarar un vector de estructuras del tipo de dato creado en el punto a.
c. Cargar en un vector de estructuras, los datos referentes a los alumnos de la comisión, esta
información termina con DNI igual al 0. Función INGRESO.
d. Indicar cuántos alumnos aprobaron (ambos parciales con nota >= 4 y cuántos reprobaron la
materia. Función RESULTADO.
e. Informar los datos de los alumnos de (DNI – Apellido y Nombre – Nota Promedio) de los alumnos.
PROMOCIONADOS (ambas notas >= 7). Función INFORME_PROMO.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT 80
typedef struct {
                int dni;
                char ayn[81];
                int nota[2];
                float prom;
            }T_alum;
int INGRESO(T_alum[],int);
void RESULTADO(T_alum[],int,int);
void INFORME_PROMO(T_alum[],int,int);
int main()
{
    T_alum alumno[CANT];
    int cCargada;
    cCargada=INGRESO(alumno,CANT);
    RESULTADO(alumno,4,cCargada);
    INFORME_PROMO(alumno,7,cCargada);

    return 0;
}

int INGRESO(T_alum al[],int ce)
{
    int i=0;
    printf("Indicar DNI del alumno(0 para terminar)\n");
    scanf("%d",&al[i].dni);

    while(al[i].dni!=0 && i<ce)
    {
        printf("Ingresar nombre y apellido\n");
        fflush(stdin);
        gets(al[i].ayn);

        printf("Ingresar notas\n");
        scanf("%d%d",&al[i].nota[0],&al[i].nota[1]);

        al[i].prom=(al[i].nota[0] + al[i].nota[1])/2.;

        i++;
        if(i<ce)
        {
            printf("Indicar DNI del alumno(0 para terminar)\n");
            scanf("%d",&al[i].dni);
        }
    }
    return i;
}

void RESULTADO(T_alum alu[],int li,int ce)
{
    int i,contAprob=0,contDesaprob=0;
    for(i=0;i<ce;i++)
    {
        if(alu[i].nota[0]>=4 && alu[i].nota[1]>=4)
        {
            contAprob++;
        }
        else
            contDesaprob++;
    }
    printf("\nCANTIDAD DE ALUMNOS APROBADOS %d\n",contAprob);
    printf("\nCANTIDAD DE ALUMNOS DESAPROBADOS %d\n",contDesaprob);
}

void INFORME_PROMO(T_alum a[],int li,int ce)
{
    int i;
    for(i=0;i<ce;i++)
    {
        if (a[i].nota[0]>=7 && a[i].nota[1]>=7)
        {
            printf("EL ALUMNO DNI:%d %s HA PROMOCIONADO, PROMEDIO %.2f \n",a[i].dni,a[i].ayn,a[i].prom);
        }
    }
}
