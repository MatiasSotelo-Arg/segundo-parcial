/* 
Escribe en lenguaje c, la declaración de un tipo de dato tGrafoPonderado para un grafo ponderado de 
hasta 10 vértices, donde el peso corresponde a kg. Utilizar la implementación de grafos con arrays. 
Además, escribir las funciones para:
a) iniciar el grafo
b) agregar un vértice al grafo 
c) agregar un arco al grafo
d) visualizar la matriz de pesos
*/

#include <stdio.h>

#define N 10

typedef int tVertice;
typedef float tPeso; 

//arco
typedef struct {
	tVertice destino;
	tVertice origen;
	tPeso peso;
}tArco;

typedef int conjuntoVertices[N];
typedef float conjuntoArcos[N][N];

//grafo
typedef struct {
	conjuntoVertices vertices;
	conjuntoArcos arcos;
}tGrafoPonderado;

//var globales
tGrafoPonderado grafo;
tArco arco;

//prototipo de funciones
void iniciarGrafo(tGrafoPonderado *);
void agregarVertice(tGrafoPonderado *, tVertice);
void agregarArco(tGrafoPonderado *, tArco);
void visualizarMatrizAdyacencia(tGrafoPonderado);

//main
int main() {
	iniciarGrafo(&grafo);

	//vertices
	agregarVertice(&grafo,1);
	agregarVertice(&grafo,5);
	
	//arcos
	arco.origen = 1;
	arco.destino = 5;
	arco.peso = 10;

	agregarArco(&grafo, arco);
//	printf("%.0f ",grafo.arcos[arco.origen][arco.destino]);
	visualizarMatrizAdyacencia(grafo);
	return 0;
}

//implementacion de funciones
void iniciarGrafo(tGrafoPonderado * pGrafo) {
	int x, y;
	 
	for(x = 0;x < N; x++) {
		pGrafo->vertices[x] = 0;
		
		for(y = 0; y < N; y++) {
			pGrafo->arcos[x][y] = 0;	
		}
	}	
	printf("Grafo inicializado!\n");
}

void agregarVertice(tGrafoPonderado * pGrafo, tVertice pVertice) {
	if(pVertice <= N) {
		pGrafo->vertices[pVertice] = 1;
		printf("Se agrego vertice %d\n",pVertice);
	} else {
		printf("Supero el numero de vertices (%d) <= %d\n",pVertice, N);
	}
}

void agregarArco(tGrafoPonderado * pGrafo, tArco pArco) {
	pGrafo->arcos[pArco.origen][pArco.destino] = pArco.peso;
	printf("Arco agregado %d -> %d\n",pArco.origen, pArco.destino);	
}

void visualizarMatrizAdyacencia(tGrafoPonderado pGrafo) {
	int x , y;
	printf("\nMatriz de adyacencia\n");
	for(x = 1;x <= N; x++) {
		for(y = 1; y <= N; y++) {
			printf("%.0f ",pGrafo.arcos[x][y]);
		}
		printf("\n");
	}
	printf("\n");
}







