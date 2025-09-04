/*Los datos de los alumnos de una comisión de Computación Transversal son:

• Número de DNI (entero).
• Nombre y Apellido (80 caracteres).
• Nota1, Nota2 (entero).
• Nota Promedio (real, calculado según Nota1 y Nota2)

 a.  Declarar un tipo de dato que contenga la información del alumno.
 b.  Con la información indicada para los alumnos. Grabar los datos en el archivo “ALUMNOS.dat”. Esta información de grabación finaliza con DNI cero.
 c.  Leer los datos del archivo, mediante la Función LECTURA.*/
 #include <stdio.h>
 #include <stdlib.h>
 #define CALUM 80
 typedef struct {
                int dni;
                char nya[81];
                int nota[2];
                float prom;
    }T_alum;
void grabarArchivo(T_alum);
void leeArchivo(T_alum);
int main()
{
    T_alum alumno;

    grabarArchivo(alumno);
    leeArchivo(alumno);
    return 0;
}

void grabarArchivo(T_alum a)
{
    int i=0;
    FILE* pf;
    pf=fopen("ALUMNOS.dat","wb");
    if(pf==NULL)
    {
        printf("Error al abrir el archivo\n");
        system("pause");
        exit(1);
    }
    printf("CARGA DEL ARCHIVO ALUMNOS\n");
    printf("Ingrese DNI (0 para terminar)\n");
    scanf("%d",&a.dni);
    while(a.dni!=0)
    {
        printf("Nombre y Apellido del alumno\n");
        fflush(stdin);
        gets(a.nya);
        printf("Ingrese nota del primer parcial\n");
        scanf("%d",&a.nota[0]);
        printf("Ingrese nota del segundo parcial\n");
        scanf("%d",&a.nota[1]);
        a.prom=(a.nota[1]+a.nota[0])/2.;//promedio de las notas en campo prom;
        fwrite(&a,sizeof(T_alum),1,pf);

        printf("Ingrese DNI (0 para terminar)\n");
        scanf("%d",&a.dni);
    }
    fclose(pf);

}

void leeArchivo(T_alum a)
{
    FILE* arch;
    arch=fopen("ALUMNOS.dat","rb");
    if(arch==NULL)
    {
        printf("Error al abrir el arhivo\n");
        system("pause");
        exit(1);
    }
    system("cls");
    printf("LECTURA DEL ARCHIVO\n");
    fread(&a,sizeof(T_alum),1,arch);
    while(!feof(arch))
    {
        printf("DNI %d\nNombre y apellido %-80s\nNota 1 %d Nota 2 %d\nPromedio %.2f\n",a.dni,a.nya,a.nota[0],a.nota[1],a.prom);
        fread(&a,sizeof(T_alum),1,arch);
    }
}
