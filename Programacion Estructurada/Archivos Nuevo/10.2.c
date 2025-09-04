/*Tomando como base el archivo ALUMNOS.DAT creado en el ejercicio anterior se desea
desarrollar un programa que, basado en la información del archivo, genere 3 archivos:

 •  Uno con los alumnos PROMOCIONADOS (ambas notas mayores o igual a 7)
 •  Otro archivo con los alumnos en condición CURSADO (ambas notas mayores o igual a 4
                                                          pero no promocionados)
 •  Y un tercer archivo con los REPROBADOS (al menos una nota, menor que 4)

Para comprobar los datos guardados realizar una función que reciba por parámetro
el nombre del archivo a mostrar, lo abre y muestre su contenido. Se debe invocar a la
función 3 veces para mostrar todos los archivos generados.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
                int dni;
                char nya[81];
                int nota[2];
                float prom;
}T_alum;
//void creaArchivo(T_alum,char[20]);
void leeArchivo(T_alum,char[20]);

int main()
{
    T_alum alumno;
    FILE* pf;
    FILE* arch;
    FILE* ivo;
    FILE* fl;
    pf=fopen("ALUMNOS.dat","rb");
    if(pf==NULL)
    {
        printf("Error al abrir el archivo\n");
        system("pause");
        exit(1);
    }
    arch=fopen("PROMOCIONADOS.dat","wb");
    if(arch==NULL)
    {
        printf("Error al abrir el archivo\n");
        system("pause");
        exit(1);
    }
    ivo=fopen("REPROBADOS.dat","wb");
    if(ivo==NULL)
    {
        printf("Error al abrir el archivo\n");
        system("pause");
        exit(1);
    }
    fl=fopen("CURSADOS.dat","wb");
    if(fl==NULL)
    {
        printf("Error al abrir el archivo\n");
        system("pause");
        exit(1);
    }
    fread(&alumno,sizeof(T_alum),1,pf);
    while(!feof(pf))
    {
        if (alumno.nota[0] >= 7 && alumno.nota[1] >= 7)
        {
            fwrite(&alumno,sizeof(alumno),1,arch);
        }
        else if(alumno.nota[0]<4 && alumno.nota[1]<4)
        {
            fwrite(&alumno,sizeof(alumno),1,ivo);
        }
        else fwrite(&alumno,sizeof(alumno),1,fl);

        fread(&alumno,sizeof(T_alum),1,pf);
    }

    fclose(pf);
    fclose(arch);
    fclose(ivo);
    fclose(fl);

    leeArchivo(alumno,"PROMOCIONADOS.dat");
    leeArchivo(alumno,"CURSADOS.dat");
    leeArchivo(alumno,"REPROBADOS.dat");

    system("pause");
    return 0;
}
////////////////////////////////////////////
void leeArchivo(T_alum al,char s[])
{
    FILE* bc;
    bc=fopen(s,"rb");
    if(bc==NULL)
    {
        printf("Error al abrir el archivo\n");
        system("pause");
        exit(1);
    }
    fread(&al,sizeof(al),1,bc);
    while(!feof(bc))
    {
        printf("%s\n%d\n%s\n%d %d\n%.2f\n",s,al.dni,al.nya,al.nota[0],al.nota[1],al.prom);
        fread(&al,sizeof(al),1,bc);
    }
    fclose(bc);
}
