/*Se ingresan las ventas de un comercio de insumos de computación. Por cada venta se ingresa:
• Número de cliente (entero de 4 dígitos no correlativos).
• Importe (mayor a cero).
• Número de vendedor (entero de 1 a 10).
El ingreso de datos finaliza con un número de cliente 999.
Se sabe que no son más de 100 clientes, la carga de los clientes se debe realizar al inicio del programa con la
función CARGA_CLIENTE () y para cada uno se ingresa:
• Código de cliente (entero de 4 dígitos no correlativos).
• Nombre y Apellido (50 caracteres máximo).
Se solicita:
a. Determinar la cantidad de ventas realizadas por cliente.
b. La cantidad de ventas realizadas por vendedor.
c. Informar en forma ordenada por total facturado (modo descendente), el total facturado a cada
cliente, informando:
CODIGO DE CLIENTE NOMBRE Y APELLIDO TOTAL FACTURADO
X XXXXX XXXXXXXX $ XXXXXXXXX,XX*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT 100
#define MAX_LENGTH 50
typedef struct {
                int nCliente;
                float importe;
                int nVendedor;
            }T_venta;
typedef struct {
                int cCliente;
                char nya[MAX_LENGTH];
            }T_cliente;
int CARGA_CLIENTE (T_cliente[],int);
int estaEnRango(int,int,int);
//int tieneDuplicado(T_cliente[],int,int);
int main ()
{
    T_venta ventas;
    T_cliente cliente[CANT];
    int cCargada;
    cCargada=CARGA_CLIENTE(cliente,CANT);
    return 0;
}
int estaEnRango(int dato,int li,int ls)
{
    int cond=0;
    if(dato>=li && dato<=ls)
        cond=1;
    return cond;
}

/*int tieneDuplicado(T_cliente cl[],int dato,int ce)
{
    int i,pos=-1;
    for(i=0;i<ce;i++)
    {
        if(cl[i].cCliente==dato)
        {
            pos=i;
        }
    }
    return pos;
}*/
int CARGA_CLIENTE(T_cliente cl[],int ce)
{
    int i=0,dato;
    printf("CARGA DATOS DE CLIENTES\n");
    do{
        printf("INDICAR CODIGO DE CLIENTE(999 para terminar)\n");
        scanf("%d",&dato);
    }while(!(estaEnRango(dato,1000,9999)==1 && dato==999));
    while(dato!=999)
    {
        cl[i].cCliente=dato;
        printf("NOMBRE Y APELLIDO DEL CLIENTE\n");
        fflush(stdin);
        gets(cl[i].nya);

        i++;
        printf("INDICAR CODIGO DE CLIENTE(999 para terminar)\n");
        scanf("%d",&dato);
    }
    return i;
}
