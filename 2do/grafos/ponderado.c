/* Codificar un tipo de dato tGrafoPlayas para modelar un grafo ponderado de hasta 15 vértices, 
que representan las playas de la costa atlántica Argentina. 
El peso de los arcos es un dato compuesto que representa la distancia en km y la cantidad 
promedio de combustible en litros que se consume entre nodos. 
Utilizar la implementación de grafos con arrays.

Además:

-Codificar una función que permita agregar un vértice al grafo definido anteriormente.

-Codificar la función que permita agregar un arco al grafo definido anteriormente.

- Codificar una función que permita imprimir la matriz de pesos ó la matriz de adyacencia, 
según sea un valor del tipo char que se recibe como parámetro (a-adyacencia p-pesos). 
En el caso de la matriz de pesos, los valores de los arcos deberán mostrarse como en 
el siguiente ejemplo: (90.24 km, 35.25 ltrs) */ 

#include <stdio.h>

#define N 7

typedef int tVertice;

typedef struct {
	float distanciaKm;
	float cantPromCombustible;
}tPeso;

typedef struct {
	tVertice origen;
	tVertice destino;
	tPeso peso;
}tArco;

typedef int conjuntoVertices[N];
typedef tPeso conjuntoArcos[N][N];

typedef struct {
	conjuntoVertices vertices;
	conjuntoArcos arcos;
}tGrafoPlayas; 

//globales
tGrafoPlayas grafo;
tArco arco;

//implementacion 
void inicializarMatriz(tGrafoPlayas *);
void agregarVertice(tGrafoPlayas *, tVertice);
void agregarArco(tGrafoPlayas *, tArco);
void imprimirMatriz(tGrafoPlayas, char);

//main 
int main() {
	inicializarMatriz(&grafo);
	agregarVertice(&grafo, 0);
	agregarVertice(&grafo, 1);
	
	arco.origen = 0;
	arco.destino = 1;
	arco.peso.distanciaKm = 100.00;
	arco.peso.cantPromCombustible = 2.00;
	agregarArco(&grafo, arco);
//	
	fflush(stdin);
	imprimirMatriz(grafo,'p'); // (a-adyacencia p-pesos)
	return 0;
}

//implementacion 
void inicializarMatriz(tGrafoPlayas * pGrafo) {
	int i, j;
	
	for(i=0;i<N;i++) {
		pGrafo->vertices[i] = 0;
		for(j=0;j<N;j++) {
			pGrafo->arcos[i][j].distanciaKm = 00.00;
			pGrafo->arcos[i][j].cantPromCombustible = 00.00; 
		}
	}
	printf("matriz inicializada\n");
} 

void agregarVertice(tGrafoPlayas * pGrafo, tVertice pVertice) {
	if(pVertice <= N) {
		pGrafo->vertices[pVertice] = 1;
		printf("Se agrego el vertice %d\n",pVertice);
	} else {
		printf("el vertice no existe\n");
	}
}

void agregarArco(tGrafoPlayas * pGrafo, tArco pArco) {
	if(pGrafo->vertices[pArco.origen] == 1 && pGrafo->vertices[pArco.destino] == 1) {
		pGrafo->arcos[pArco.origen][pArco.destino] = pArco.peso;
		printf("Se agrego el arco %d %d\n",pArco.origen, pArco.destino);
	}	
}

void imprimirMatriz(tGrafoPlayas pGrafo, char pChar) {


	if(pChar != 'a' && pChar != 'p') {
		printf("No se peude\n");
	} else {
			
		int i,j; 
		for(i=0;i<N;i++) {
			for(j=0;j<N;j++) {

				if(pChar == 'a') {
					
					if(pGrafo.arcos[i][j].distanciaKm != 0 || pGrafo.arcos[i][j].cantPromCombustible != 0) {
						printf("1 ");
					} else {
						printf("0 ");
					}	
				}
				if(pChar == 'p') {
				
					printf("%-6.2f %-6.2f |", pGrafo.arcos[i][j].distanciaKm, pGrafo.arcos[i][j].cantPromCombustible);
				}
			}
			printf("\n");
		}
	}
}



