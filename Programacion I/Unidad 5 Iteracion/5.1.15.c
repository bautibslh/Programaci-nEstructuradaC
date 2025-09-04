#include <stdio.h>
#define CANT_PART 2
#define CANT_TIROS 3
/*Se realizó un concurso de tiro al blanco. Existen 5 participantes y cada uno de ellos efectúa 3 disparos, registrándose las coordenadas X-Y de cada disparo. Determinar:

a.   Cuantos disparos se efectuaron en cada cuadrante por cada participante.
b.   Cuantos disparos se efectuaron en total en el centro.

NOTA: no considere disparos sobre los ejes.*/
int main ()
{
    int i,j,x,y;
    int contador_1=0,contador_2=0,contador_3=0,contador_4=0,contador_centro=0;

    for (i=1;i<=CANT_PART;i++)
    {
        for (j=1;j<=CANT_TIROS;j++)
            {
                printf ("Ingrese coordenadas del disparo (%d) del participante %d\n",j,i);
                scanf ("%d%d",&x,&y);

                if (x==0 && y==0)
                    contador_centro++;
                else if (x>0)
                {
                    if(y>0)
                        contador_1++;
                    else
                        contador_2++;
                }
                else if (y>0)
                        contador_4++;
                     else
                        contador_3++;
            }
    printf ("TIROS EN PRIMER CUADRANTE: %d\n",contador_1);
    contador_1=0;
    printf ("TIROS EN SEGUNDO CUADRANTE: %d\n",contador_2);
    contador_2=0;
    printf ("TIROS EN TERCER CUADRANTE: %d\n",contador_3);
    contador_3=0;
    printf ("TIROS EN CUARTO CUADRANTE: %d\n",contador_4);
    contador_4=0;
    }

    printf ("TIROS EN EL CENTRO: %d\n",contador_centro);
    return 0;
}
