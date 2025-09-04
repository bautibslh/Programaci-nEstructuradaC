#include <stdio.h>
#include <stdlib.h>
int Gane(int [][3],int,int,int);
void Mostrar(int [][3],int,int);
void Start(int [][3],int,int);
int main ()
{
    int mat[3][3]={0};

    Mostrar(mat,3,3);
    Start(mat,3,3);



    return 0;
}

void Mostrar (int m[3][3],int f,int c)
{
    int i,j;

    for (i=0;i<f;i++)
    {
        for(j=0;j<c;j++)
        {
            if(m[i][j]==0)
            {
                printf ("  ");
            }
            if(m[i][j]==1)
            {
                printf("X ");
            }
            if(m[i][j]==2)
            {
                printf("O ");
            }
        }
        printf ("\n");
    }
    system("pause");
    system("cls");
}

void Start(int m[][3],int f,int c)
{
    int x,y,jug=1,cont=0,ganador=0;
    while (cont<10 && ganador!=1 && ganador!=2)
    {
        Mostrar(m,3,3);
        if(jug==1)
        {
            //do{
                printf("\nJUGADOR 1\nINDIQUE SU JUGADA(x-y)\n");
                scanf("%d%d",&x,&y);
            //}while(!(x>=1&&x<=3 && y>=1 && y<=3));
            m[x-1][y-1]=1;
            jug=2;
            cont++;
            if(Gane(m,f,c,m[x-1][y-1])==1)
            {
                ganador=1;
                printf("\nEL GANADOR ES EL JUGADOR 1\n");
                Mostrar(m,3,3);
                system("pause");
                return 0;
            }
        }
        Mostrar(m,3,3);
        if(jug==2)
        {
            //do{
                printf("\nJUGADOR 2\nINDIQUE SU JUGADA(x-y)\n");
                scanf("%d%d",&x,&y);
           // }while(!(x>=1&&x<=3&&y>=1 &&y<=3));
            m[x-1][y-1]=2;
            jug=1;
            cont++;
            if(Gane(m,f,c,m[x-1][y-1])==1)
            {
                ganador=2;
                printf("\nEL GANADOR ES EL JUGADOR 2\n");
                Mostrar(m,3,3);
                system("pause");
                return 0;
            }
        }

        if(cont==9)
        {
            printf("\n\nEMPATE");
        }
    }




}

int Gane(int m[][3],int f,int c,int n)
{
    int i=0,j=0,con=0;
    if(m[i][j]==n && m[i+1][j+1]==n && m[i+2][j+2]==n || m[i][j]==n && m[i+1][j]==n && m[i+2][j]==n || m[i][j]==n && m[i][j+1]==n && m[i][j+2]==n)
    {
        con=1;
    }

    return con;

}
