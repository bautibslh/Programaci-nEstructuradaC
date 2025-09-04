#include <stdio.h>

struct test1{
	int x;
	int b;
	int z;
};

int tablero[3][3];
char tableroY[3] = {'a','b','c'};


int spacingLeft = 10;
int obtener_posicion_Y(char key){
	int c = 0;
	for(int pos = 0; pos <= 2; pos ++){
		if(tableroY[pos] == key) return c;
		c ++;
	}
	return 0;
}
int debuggin = 0;
int turno = 0;
void iniciar_tablero(){
	/* Presetea el tablero con valores 0 */
	for( int y = 0; y <= 3; y++){
		for( int x = 0; x <= 3; x++){
			tablero[y][x] = 0;
		}
	}
}
int obtener_cantidad_jugadas(){
	int c = 0; //contador
	for( int y = 0; y <= 3; y++){
		for( int x = 0; x <= 3; x++){
			if(!tablero[y][x] == 0) c++;
		}
	}
	return c;
}
void simulacion_tablero(){
	//Simulacion manual de una jugada prearmada
	/*for( int y = 0; y <= 3; y++){
		tablero[y][0] = 1;
		tablero[y][1] = 1;
		tablero[y][2] = 2;
	}*/
	tablero[0][0] = 2;
	tablero[0][1] = 1;
	tablero[0][2] = 1;

	tablero[1][0] = 2;
	tablero[1][1] = 1;
	tablero[1][2] = 1;

	tablero[2][0] = 1;
	tablero[2][1] = 1;
	tablero[2][2] = 2;
}
/*
Convierte los valores numericos de tablero a el simbolo, el 0 ocupa un lugar vacio.
@params
	int numeros[1-2]
@return
	string simbolo
*/
const char * obtener_simbolo(int num){
	if(num == 1){
		return "X";
	}else if(num == 2){
		return "O";
	}
	return " ";
}

/*
Imprime el tablero con los simbolos.
@return
	void
*/
void imprimir_tablero(){
	for( int y = 0; y <= 2; y++){
		if(y == 0){
			printf("  | 1 | 2 | 3\n-------------\n");
		}
		printf("%c | ", tableroY[y]);
		for( int x = 0; x <= 2; x++){
			printf("%s", obtener_simbolo(tablero[y][x]));
			if(x <= 1){
				printf(" | ");
			}else{
				printf("\n");
			}
		}
		//printf
		if(y < 2){
			printf("-------------\n");
		}
	}
}

int obtener_posicion(int y, int x){
	return tablero[y][x];
}

int buscar_ganador(){
/*
	CP: Cantidad de prosiblidad

	Posiblidades de ganador

	  1 2 3
	1 x|x|x
	2 x|x|x
    3 x|x|x
    P1 = Y:1-3, X:1,2,3, CP: 3
    P2 = Y:1,2,3, X:1-3, CP: 3

    -----

	  1 2 3
	1 x| |x
	2  |x|
	3 x| |x
	P3 = Y1:X1, Y2:X2, Y3:X3, CP: 1
	P4 = Y1:X3, Y2:X2, Y3:X1, CP: 1

*/
	int temp = 0;
	int ganador = 0;
	int tipo_barrido = 0;
	int tempY = 0;
	int tempX = 0;
	int actual = 0;
	do{
		temp = 0;
		for(int relativePos1 = 0; relativePos1 <= 2; relativePos1++ ){
			//Barrido horizontal
			for(int relativePos2 = 0; relativePos2 <= 2; relativePos2++){
				actual = 0;
				if(tipo_barrido == 0){
					//printf("Barrido 0");
					/*
					relativePos1 actua como eje Y
					relativePos2 actua como eje x
					*/
					actual = obtener_posicion(relativePos1, relativePos2);
					//Horizontal
				}else if(tipo_barrido == 1){
					//printf("Barrido 1");
					/*
					relativePos1 actua como eje X
					relativePos2 actua como eje Y
					*/
					actual = obtener_posicion(relativePos2, relativePos1);
					//vertical
				}else if(tipo_barrido == 2){
					//printf("Barrido 2");
					/*
					relativePos2 actua como eje x - y
					mientras recorre las diagonales
					*/
					actual = obtener_posicion(relativePos2, relativePos2);
					//Diagonal derecha
				}else if(tipo_barrido == 3){
					//printf("Barrido 3");
					actual = obtener_posicion(relativePos2, 2-relativePos2);
					//Diagonal isquierdo
				}
				if(debuggin)printf("Actual %d Relative2 %d Relative1 %d\n", actual, relativePos2, relativePos1);
				if(actual == 0 and relativePos2 == 0)	{
					/* Si en la posicion actual es igual a la
					primera posicion y esta vacia se determina que
					la linea que se intenta comprobar ya no puede ser
					completada y se salta a la siguiente cordenada
					valida en el tablero, de no existir otra cordenada valida
					se seguira con un nuevo barrido*/
					if(debuggin)printf("Break\n");
					break;
				}
				if(relativePos2 > 0){
					if(temp == actual){
						if(relativePos2 == 2){
							ganador = actual;
							if(debuggin){
								printf("Ganador %d Actual %d\n", ganador, actual);
								printf("Value: %d - Barrido %d\n", relativePos1, tipo_barrido);
							}
							return actual;
						}
					}else{
						break;
					}
				}
				temp = actual;
			}
			if(!ganador == 0) break;
		}
		if(debuggin)printf("Barrido %d Ganador %d\n", tipo_barrido, ganador);
		tipo_barrido ++;
		if(tipo_barrido == 4) return 0;
	}while(ganador == 0);
	return 0;
}

bool validar_posicion(int y, char x){
	if(!tablero[y][x] == 0) return false;
	return true;
}

void asignar_posicion(int y, int x){
	tablero[y][x] = turno+1;
	printf("Turno %d\n", turno+1);
}

void jugada(){
	int x = 0, y = 0;
	char yC;
	printf("Turno jugador %d\n", turno+1);
	do{
		printf("Ingresa la fila y columna en la que quieres jugar (1 2)\n>");
		scanf("%d %c", &x, &yC);
		y = obtener_posicion_Y(yC);
	}while(validar_posicion(y,x-1) == false);
	asignar_posicion(y,x-1);
	turno ++;
	if(turno == 2) turno = 0;
}

int main(){
	bool jugando = true;
	while(jugando){
		iniciar_tablero();
		imprimir_tablero();
		int ganador = 0;
		while(!ganador){
			jugada();
			imprimir_tablero();
			ganador = buscar_ganador();
			if(obtener_cantidad_jugadas() == 9 and ganador == 0) printf("Empate")
		}
	}
	printf("ganador %d\n", ganador);

	/*test1 b;

	b.x = 1;
	b.b = 2;
	b.z = 3;

	test1 c;

	c.x = 2;

	printf("%d\n", c.x);

	tablero[0][0] = 0;*/
}
