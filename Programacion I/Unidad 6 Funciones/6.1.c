#include <stdio.h>
#include <stdlib.h>
int mostrarMenu (int,int);

int main ()
{
    int x,y,resp;

    printf ("Ingrese dos numeros enteros\n");
    scanf ("%d%d",&x,&y);

    resp= mostrarMenu(x,y);

    while (resp!=6)
    {

        switch (resp)
        {
            case 1:
            {
                    printf ("La suma es %d\n",x+y);
                    system ("pause");
                    break;
            }
            case 2:
            {
                    printf ("La resta es %d\n",x-y);
                    system ("pause");
                    break;
            }

            case 3:
            {
                    printf ("El producto es %d\n",x*y);
                    system ("pause");
                    break;
            }

            case 4:
            {
                    if (y!=0)
                    {
                        printf ("La division da como resultado %.2f\n",x/(float)y);
                        system ("pause");
                        break;
                    }
                    else
                    {
                        printf ("Error, no se puede dividir por 0\n");
                        system ("pause");
                        break;
                    }
            }
            case 5:
            {
                    printf ("Ingrese dos numeros enteros\n");
                    scanf ("%d%d",&x,&y);
                    break;
            }
        }
        resp = mostrarMenu(x,y);

    }

    return 0;
}


int mostrarMenu(int n1,int n2)
{
    int r;

    do{
        system ("cls");
        printf ("\nMenu de opciones:\n----------------\n ");
        printf ("\nNumero 1:%d\tNumero 2:%d\n",n1,n2);
        printf ("1)Sumar\n2)Restar\n3)Multiplicar\n4)Dividir\n5)Ingresar nuevos numeros\n6)Salir\n");
        scanf ("%d",&r);
    }while (r<1||r>6);


    return r;
}
