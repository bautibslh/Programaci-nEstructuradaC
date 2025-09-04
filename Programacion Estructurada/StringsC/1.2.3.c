/*Ingresar nombre y DNI de los alumnos de un curso.
Como máximo el curso puede tener 50 alumnos. La
carga finaliza con un alumno de nombre FIN.
Luego de cargar los alumnos se pide:
a. Ingresar nombres de a uno en uno y buscarlos.
Si el nombre está en el curso mostrar su DNI y sino
informar que no está.
Seguir ingresando nombres hasta que se ingrese un nombre
igual a NOBUSCARMAS.
b. Mostrar el listado de alumnos ordenado alfabéticamente de menor a mayor*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 50
int cargaDatos(char[][20],int[],int);
void buscaNombre(char[][20],int[],int);
void mostrarListadoOrdenado(char[][20],int);
int main()
{
    char nombre[TAM][20];
    int dni[TAM],cantCargada;
    cantCargada=cargaDatos(nombre,dni,TAM);
    buscaNombre(nombre,dni,cantCargada);
    mostrarListadoOrdenado(nombre,cantCargada);
    return 0;
}

//////////////////////////////////////////////////////
int cargaDatos(char n[][20],int d[],int ce)
{
    int i=0;
    printf("Ingresar Nombre(FIN para terminar)\n");
    fflush(stdin);
    gets(n[i]);
    while(i<ce && strcmpi(n[i],"FIN"))
    {
        printf("Indique DNI\n");
        scanf("%d",&d[i]);
        i++;
        if(i<ce){
            printf("Ingresar Nombre(FIN para terminar)\n");
            fflush(stdin);
            gets(n[i]);
        }
    }
    system("pause");
    system("cls");
    return i;
}

void buscaNombre(char nom[][20],int doc[],int ce)
{
    int i;
    char n[20];
    printf("NOMBRE A BUSCAR\n");
    fflush(stdin);
    gets(n);

    while(strcmpi(n,"NOBUSCARMAS")!=0)
    {
        for(i=0;i<ce;i++)
        {
            if (strcmpi(nom[i],n)==0)
                printf("NOMBRE:%s\tDNI:%d\n",n,doc[i]);
        }
        printf("NOMBRE A BUSCAR\n");
        fflush(stdin);
        gets(n);
    }
    system("pause");
    system("cls");
}

void mostrarListadoOrdenado(char name[][20],int ce)
{
    int i,j;
    char aux[20];
    printf ("LISTADO ORDENADO\n");
    for(i=0;i<ce-1;i++)
    {
        for(j=0;j<ce-1-i;j++)
        {
            if(strcmp(name[j],name[j+1]))
            {
                strcpy(aux,name[j]);
                strcpy(name[j],name[j+1]);
                strcpy(name[j+1],aux);
            }
        }
    }
    for(i=0;i<ce;i++)
    {
        printf ("%s\n",name[i]);
    }
}
