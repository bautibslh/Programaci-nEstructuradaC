/*Un laboratorio dispone de una lista con sus 50 medicamentos. De cada uno conoce:
• Código del medicamento (entero, de 3 cifras).
• Precio (real).
• Stock (entero).
Se solicita:
a. Declarar un tipo de dato que contenga la información del medicamento.
b. Declarar un vector de estructura de tipo de datos creado en a.
c. Cargar en un sector de estructuras, los datos referentes a los medicamentos. Función INGRESO.
d. Consultar el precio según código del medicamento. Función BUSQUEDA_MEDI.
e. Informar los códigos de los medicamentos cuyo stock es inferior a 10 unidades. Función INFORME.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3
typedef struct {
            int codigo;
            float precio;
            int stock;
            }T_medicamento;
void INGRESO(T_medicamento[],int);
void BUSQUEDA_MEDI(T_medicamento[],int,int);
void INFORME(T_medicamento[],int,int);
int main()
{
    T_medicamento vsMedic[TAM];
    int cod;

    INGRESO(vsMedic,TAM);
    system("cls");
    printf("INGRESE CODIGO DEL MEDICAMENTO A BUSCAR\n");
    scanf("%d",&cod);
    BUSQUEDA_MEDI(vsMedic,cod,TAM);
    INFORME (vsMedic,10,TAM);
    return 0;
}
void INGRESO(T_medicamento vsm[],int ce)
{
    int i;

    for(i=0;i<ce;i++)
    {
        printf("Ingrese codigo del medicamento %d\n",i+1);
        scanf("%d",&vsm[i].codigo);
        printf("Ingrese precio del medicamento %d\n",i+1);
        scanf("%f",&vsm[i].precio);
        printf("Ingrese stock del medicamento %d\n",i+1);
        scanf("%d",&vsm[i].stock);
    }
}
void BUSQUEDA_MEDI(T_medicamento vsmed[],int dato,int ce)
{
    int i=0,encontrado=0;
    while(i<ce)
    {
        if(dato==vsmed[i].codigo)
        {
            encontrado=1;
            printf("El medicamento %d sale: $%.2f\n",vsmed[i].codigo,vsmed[i].precio);
        }
        i++;
    }
    if (encontrado==0)
        printf("Medicamento no encontrado\n");
}
void INFORME(T_medicamento vsme[],int ls,int ce)
{
    int i;
    printf("MEDICAMENTOS CON STOCK MENOR A %d\n",ls);
    for(i=0;i<ce;i++)
    {
        if (vsme[i].stock<ls)
        {
            printf("CODIGO %d\nSTOCK %d\n",vsme[i].codigo,vsme[i].stock);
        }
    }
}
