#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void MostrarTablero(char[][3],int,int);
int hayGanador(char[][3],int,int);
int Ocupado(char[][3],int,int);
void StartGame(char[][3],int,int);
int main ()
{
	char tablero[3][3]={0};
	MostrarTablero(tablero,3,3);
	StartGame(tablero,3,3);

	return 0;
}

void MostrarTablero(char m[][3],int cf,int cc)
{
	int f,c;
	printf("TABLERO TA TE TI\n");

   // printf("_____________\n");
	for(f=0;f<cf;f++)
	{
		for(c=0;c<cc;c++)
		{
		    if(m[f][c]=='X')
                printf("|_%c_|",m[f][c]);
		    else if((m[f][c]=='O'))
                printf("|_%c_|",m[f][c]);
            else
                printf("|___|");
		}
		printf("\n");
	}
}

void StartGame(char m[][3],int cf,int cc)
{
    int jugador,i=1,f,c,ganador=0;
    while(i<10 && ganador==0)
    {
        if(i%2==1)
        {
            jugador=1;
        }
        else
            jugador=2;

        do{
            printf("TURNO DEL JUGADOR %d\n",jugador);
            scanf("%d%d",&f,&c);
        }while ((!(f>=1&&f<=3 && c>=1&&c<=3))|| Ocupado(m,f,c)!=0);
        if(jugador==1)
        m[f-1][c-1]='X';
        else if(jugador==2)
        m[f-1][c-1]='O';

        system("cls");
        MostrarTablero(m,3,3);
        if(hayGanador(m,3,3)!=0)
        {
            printf("\nEL GANADOR ES JUGADOR %d\n",hayGanador(m,3,3));
            ganador=hayGanador(m,3,3);
        }
        if(i==9 && ganador==0)
        {
            ganador=3;
            printf("\nEMPATE");
        }
        i++;
    }

}

int hayGanador(char m[][3],int cf,int cc)
{
    int f,c,gan=0;
    if(m[0][0]=='X' && m[1][1]=='X' && m[2][2]=='X')
    {
        gan=1;
    }
    if(m[0][2]=='X' && m[1][1]=='X' && m[2][0]=='X')
    {
        gan=1;
    }
    for(f=0;f<cf;f++)
    {

        if(m[f][0]=='X' && m[f][1]=='X' && m[f][2]=='X')
            gan=1;
    }
    for(c=0;c<cc;c++)
    {
        if(m[0][c]=='X' && m[1][c]=='X' && m[2][c]=='X')
            gan=1;
    }

    ///////////////////////////////////////////////////////////
        if(m[0][0]=='O' && m[1][1]=='O' && m[2][2]=='O')
    {
        gan=2;
    }
        if(m[0][2]=='O' && m[1][1]=='O' && m[2][0]=='O')
    {
        gan=2;
    }
    for(f=0;f<cf;f++)
    {

        if(m[f][0]=='O' && m[f][1]=='O' && m[f][2]=='O')
            gan=2;
    }
    for(c=0;c<cc;c++)
    {
        if(m[0][c]=='O' && m[1][c]=='O' && m[2][c]=='O')
            gan=2;
    }

    return gan;
}

int Ocupado(char m[][3],int f,int c)
{
    int ocu=0;
    if(m[f-1][c-1]=='X' || m[f-1][c-1]=='O')
    {
        ocu=1;
    }
    return ocu;
}
