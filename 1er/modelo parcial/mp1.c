/* Codificar un tipo de dato tGrafoPlayas para modelar un grafo ponderado de hasta 15 v�rtices, 
que representan las playas de la costa atl�ntica Argentina. 
El peso de los arcos es un dato compuesto que representa la distancia en km y la cantidad 
promedio de combustible en litros que se consume entre nodos. 
Utilizar la implementaci�n de grafos con arrays.

Adem�s:

-Codificar una funci�n que permita agregar un v�rtice al grafo definido anteriormente.

-Codificar la funci�n que permita agregar un arco al grafo definido anteriormente.

- Codificar una funci�n que permita imprimir la matriz de pesos � la matriz de adyacencia, 
seg�n sea un valor del tipo char que se recibe como par�metro (a-adyacencia p-pesos). 
En el caso de la matriz de pesos, los valores de los arcos deber�n mostrarse como en 
el siguiente ejemplo: (90.24 km, 35.25 ltrs) */ 

#include <stdio.h>

#define N 15

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

tArco arco;
tGrafoPlayas grafo;

//prototipos 
void inicializarMatriz(tGrafoPlayas *);
void agregarVertice(tGrafoPlayas *, tVertice);
void agregarArco(tGrafoPlayas *, tArco);
void imprimirMatriz(tGrafoPlayas, char);

//main
int main() {
	inicializarMatriz(&grafo);
	
	imprimirMatriz(grafo,'p'); // (a-adyacencia p-pesos)
	return 0;
}

//implementacion
void inicializarMatriz(tGrafoPlayas * pGrafo) {
    int x, y;

    for (x = 0; x < N; x++) {
        pGrafo->vertices[x] = 0;
        for (y = 0; y < N; y++) {
            pGrafo->arcos[x][y].distanciaKm = 0.0;
            pGrafo->arcos[x][y].cantPromCombustible = 0.0;
        }
    }
    printf("Grafo inicializado!\n");
}


void agregarVertice(tGrafoPlayas * pGrafo, tVertice pVertice) {
	pGrafo->vertices[pVertice] = 1;
	printf("Se agrego el vertice %d\n",pVertice);
}

void agregarArco(tGrafoPlayas * pGrafo, tArco pArco) {
	pGrafo->arcos[pArco.origen][pArco.destino] = pArco.peso;
	printf("Se agrego el arco %d %d\n",pArco.origen, pArco.destino);
}

void imprimirMatriz(tGrafoPlayas pGrafo, char pTipo) {
	
	if(pTipo != 'a' && pTipo != 'p') {
		printf("%c: no es opcion valida\n",pTipo);	
	} else {
		
		int x,y;
		
		for(x = 0; x < N; x++) {
			for(y = 0; y < N; y++) {
				if(pTipo == 'a') {
					if(pGrafo.arcos[x][y].distanciaKm != 0 || pGrafo.arcos[x][y].cantPromCombustible != 0) {
						printf("1 ");
					} else {
						printf("0 ");
					}
				} else {
					printf("%.2f , %.2f ", pGrafo.arcos[y][x].distanciaKm, pGrafo.arcos[y][x].cantPromCombustible);
				}
			}
			printf("\n");
		}
		
	}
	
}


