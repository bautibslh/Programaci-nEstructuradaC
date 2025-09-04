#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 60
typedef struct{
				int dni;
				char ayn[21];
				int p;
}t_Inscriptos;
int encontroDato(t_Inscriptos[],int,int);

int main()
{
	t_Inscriptos inscripto[TAM];
	int i=0,dni;
	char pagar,inscribir;
	FILE* pf;
	FILE* arch;
	FILE* ivo;
	pf=fopen("INSCRIPTOS.dat","rb");
	if(pf==NULL)
	{
		printf("Error al abrir codigo");
		system("pause");
		exit(1);
	}
	fread(&inscripto[i],sizeof(t_Inscriptos),1,pf);
	while(i<TAM || !feof(pf))
    {
        if(!feof(pf))
            i++;
		fread(&inscripto[i],sizeof(t_Inscriptos),1,pf);
	}
	fclose(pf);

	arch=fopen("INTERESADOS.dat","wb");
	if(arch==NULL)
	{
		printf("Error al abrir codigo");
		system("pause");
		exit(1);
	}

	printf("Ingresar DNI\n");
	scanf("%d",&dni);
	while(dni>=0)
	{
		if(encontroDato(inscripto,dni,i)!=-1)
		{
			if(inscripto[encontroDato(inscripto,dni,i)].p==1)
				printf("Ya esta pago\n");
			else
			{
				printf("Desea pagar?(S o N)\n");
				fflush(stdin);
				scanf("%c",&pagar);
				if(pagar=='S')
					inscripto[encontroDato(inscripto,dni,i)].p=1;

			}

		}
		else{
			printf("Desea inscribirlo al curso?(S o N)\n");
			fflush(stdin);
			scanf("%c",&inscribir);
			if(inscribir=='S')
			{
				inscripto[i].dni=dni;
				printf("Ingrese nombre y apellido\n");
				fflush(stdin);
				gets(inscripto[i].ayn);
				if(i<TAM)
					i++;
				else{
                    printf("Esta lleno, se te considerara interesado para la proxima inscripcion\n");
					fwrite(&inscripto[i],(sizeof (inscripto)),1,arch);
				}
			}



		}
		printf("Ingresar DNI\n");
		scanf("%d",&dni);
	}
	fclose(arch);
	ivo=fopen("INSCRIPTOS_actualziado","ab");
	if(ivo==NULL)
    {
        printf("Error al abrir archivo\n");
        system("pause");
        exit(1);
    }


	system("pause");
	return 0;
}

/////////////////////////////////////////////////
int encontroDato(t_Inscriptos v[],int dato,int ce)
{
    int i=0,pos=-1;
    while(i<ce && pos==-1)
    {
        if(v[i].dni==dato)
            pos=i;
        else i++;
    }
    return pos;
}
