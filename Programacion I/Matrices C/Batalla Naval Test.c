#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void MostrarTablero(char[][5],char [],int,int,int);
void CargarDatos(char [][5],char [],int,int);
void EmpiezaJuego(char[][5],char [],int,int);

int main()
{
    char tablero[5][5]={0},vL[5]={'A','B','C','D','E'};
    MostrarTablero(tablero,vL,5,5,0);
    CargarDatos(tablero,vL,5,5);
    EmpiezaJuego(tablero,vL,5,5);

    return 0;
}

void MostrarTablero(char m[][5],char v[],int cf,int cc,int cond)
{
    int f,c,i;
    printf("\tBATALLA NAVAL\n");
    printf (" ");
    for(i=1;i<=cc;i++)
        printf("  %d  ",i);
    printf ("\n");
    for(f=0;f<cf;f++)
    {
        for(c=0;c<cc;c++)
        {
            if(c==0)
                printf ("%c",v[f]);
            if(m[f][c]=='A')
            {
                printf("|_%c_|",m[f][c]);
            }
            else if(m[f][c]=='B' && cond==1)
            {
                printf("|___|");
            }
            else if(m[f][c]=='B' && cond==0)
            {
                printf("|_%c_|",m[f][c]);
            }
            else if(m[f][c]=='X')
            {
                printf("|_%c_|",m[f][c]);
            }
            else
            {
                printf("|___|");
            }
        }
        printf ("\n");
    }
}
void CargarDatos(char m[][5],char v[],int cf,int cc)
{
    char f;
    int c,cbar=0,cond=0,error=0,fi;
    while(cbar<5)
    {
        do{
            if(error==1)
            {
                printf("ERROR. INTENTE DE NUEVO\n");
                error=0;
            }
            printf ("\nPOSICIONE SU BARCO (x-y)\n");
            error=1;
            fflush(stdin);
            scanf("%c%d",&f,&c);
            f=toupper(f);
            switch(f)
        {
            case 'A':{fi=1;break;}
            case 'B':{fi=2;break;}
            case 'C':{fi=3;break;}
            case 'D':{fi=4;break;}
            case 'E':{fi=5;break;}
        }
        }while (!((f=='A' ||f=='B'||f=='C'||f=='D'||f=='E') && (c>=1&&c<=5) && (m[fi-1][c-1]!='B')));
        error=0;
        /*switch(f)
        {
            case 'A':{f=1;break;}
            case 'B':{f=2;break;}
            case 'C':{f=3;break;}
            case 'D':{f=4;break;}
            case 'E':{f=5;break;}
        }*/
        m[fi-1][c-1]='B';

        system("cls");
        MostrarTablero(m,v,cf,cc,cond);
        cbar++;
    }
}

void EmpiezaJuego(char m[][5],char v[],int cf,int cc)
{
    char f;
    int c,contDisparos=0,contAciertos=0,error=0;
        system("pause");
    while(contAciertos!=5)
    {
        system("cls");
        printf("\tEMPIEZA EL JUEGO\n");
        MostrarTablero(m,v,cf,cc,1);

        do{
            if(error==1)
            {
                printf("ERROR. INTENTE DE NUEVO\n");
                error=0;
            }
            printf ("HAGA SU DISPARO (x-y)\n");
            fflush(stdin);
            scanf("%c%d",&f,&c);
            error=1;
            f=toupper(f);
        }while (!((f=='A' ||f=='B'||f=='C'||f=='D'||f=='E') && (c>=1&&c<=5)));
        error=0;
        switch(f)
        {
            case 'A':{f=1;break;}
            case 'B':{f=2;break;}
            case 'C':{f=3;break;}
            case 'D':{f=4;break;}
            case 'E':{f=5;break;}
        }
        if(m[f-1][c-1]=='B')
        {
            m[f-1][c-1]='X';
            contDisparos++;
            contAciertos++;
        }
        else if(m[f-1][c-1]!='X')
        {
            m[f-1][c-1]='A';
            contDisparos++;
        }
    }
    system("cls");
    printf("\tEMPIEZA EL JUEGO\n");
    MostrarTablero(m,v,cf,cc,1);
    printf("\nGANASTE!! SOLO TARDASTE %d DISPAROS\n",contDisparos);
}
