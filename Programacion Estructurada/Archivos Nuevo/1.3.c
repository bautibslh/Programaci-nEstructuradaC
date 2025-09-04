/*1.3 En un curso de la maestría en informática los estudiantes deben exponer en forma grupal sus investigaciones
de un tema dado. El curso está formado por 5 grupos. Se pide realizar un programa para sortear el orden de
exposición de dichos grupos. Cada vez que se ejecute el programa deberá mostrar un orden de exposición
distinto para cada uno de los 5 grupos.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 5
int estaRepetido (int[],int,int);

int main()
{
    int grupos[TAM],i,num;
    srand(time(NULL));


    for(i=0;i<TAM;i++)          //Carga Vector Grupos con un numero aleatorio del 0-5
    {
        do{
            num=rand()%TAM+1;
            grupos[i]=num;
        }while (estaRepetido(grupos,i,num)!=-1);
        printf("Grupo %d orden %d\n",i+1,grupos[i]);
    }
//printf ("%d",36366%6);
return 0;
}
int estaRepetido(int v[],int ce,int dato)
{
    int i,pos=-1;
    for(i=0;i<ce;i++)
    {
        if(v[i]==dato)
            pos=i;
    }
    return pos;
}
