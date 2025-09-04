/*
Los datos de los alumnos de una comisión de Computación Transversal son:

• Número de DNI (entero).
• Nombre y Apellido (80 caracteres).
• Nota1, Nota2 (entero).
• Nota Promedio (real, calculado según Nota1 y Nota2)

 a.  Declarar un tipo de dato que contenga la información del alumno.
 b.  Con la información indicada para los alumnos. Grabar los datos en el archivo “ALUMNOS.dat”.
 Esta información de grabación finaliza con DNI cero.
 c.  Leer los datos del archivo, mediante la Función LECTURA.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  {
	int dni;
	char nya[81];
	int nota[2];
	float promedio;
}T_alum;

void Lectura(T_alum);
int main ()
{

	T_alum va;

	FILE* arch;
	arch=fopen("ALUMNOS.dat","wb");



	if(arch==NULL)
    {
        printf("ERROR al abrir el archivo\n");
        system("pause");
        exit(1);
    }


    printf ("Ingreso de datos\n");
	printf("DNI del alumno - 0 (cero) para terminar \n");
	scanf("%d",&va.dni);
	while(va.dni!=0)
	{

			printf("Nombre y apellido del alumno\n");
			fflush(stdin);
			gets(va.nya);

		do{
			printf("Nota primer parcial\n");
			scanf("%d,%d",&va.nota[0]);
		}while (va.nota[0]<1 || va.nota[0]>10);
		do{
			printf("Nota segundo parcial\n");
			scanf("%d,%d",&va.nota[1]);
		}while (va.nota[1]<1 || va.nota[1]>10);

		va.promedio= (va.nota[0] + va.nota[1])/2.;

        fwrite(&va,sizeof va,1,arch);


        printf("DNI del alumno - 0 (cero) para terminar \n");
        scanf("%d",&va.dni);

	}
        fclose(arch);
    //Lectura(va);

	return 0;
}

/*void Lectura(T_alum al)
{
    int i=0;
    FILE* pf;

	pf=fopen("ALUMNOS.dat","rb");
	if(pf==NULL)
	{
        printf("Error al abrir el archivo\n");
        exit(2);
	}
	i=0;
	fread(&al,sizeof al,1,pf);
	while(!feof(pf))
    {
        i++;
        fprintf(pf, "%d;%c;%d;%d;%.2f\n",al.dni,al.nya,al.nota[0],al.nota[1],al.promedio);
        fread(&al,sizeof al,1,pf);

    }

}
*/


