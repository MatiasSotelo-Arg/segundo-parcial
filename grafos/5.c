/* 5. Escribir en lenguaje C, la declaración del tipo de dato tGrafoNoPonderado, para un grafo no ponderado 
de hasta 7 vértices. 

Utilizar la implementación de grafos con arrays. Además, escribir las funciones para:
a) iniciar el grafo
b) agregar un vértice al grafo 
c) agregar un arco al grafo
d) visualizar la matriz de adyacencia de un grafo */

#include <stdio.h>

#define N 7

typedef int tVertice;

//arcos
typedef struct {
	tVertice origen; 
	tVertice destino;
}tArco;

typedef int conjuntoVertices[N];
typedef int conjuntoArcos[N][N];

//grafo no ponderado
typedef struct {
		conjuntoVertices vertices;
		conjuntoArcos arcos;
}tGrafoNoPonderado;

//var globales
tGrafoNoPonderado grafo;
tArco arco;

//prototipo de funciones
void inicializarGrafo(tGrafoNoPonderado *); 
void agregarVertice(tGrafoNoPonderado *, tVertice);
void agregarArco(tGrafoNoPonderado *, tArco);
void visualizarMatrizAdyacencia(tGrafoNoPonderado);

//main
int main() {
	inicializarGrafo(&grafo);
	
	agregarVertice(&grafo, 0);
	agregarVertice(&grafo, 2);
	agregarVertice(&grafo, 6);
	agregarVertice(&grafo, 3);
	
	arco.origen = 6;
	arco.destino = 3;
	
	agregarArco(&grafo, arco);
	
	arco.origen = 3;
	arco.destino = 6;
	
	agregarArco(&grafo, arco);
	
	arco.origen = 1;
	arco.destino = 2;
	
	agregarArco(&grafo, arco);
	
	arco.origen = 1;
	arco.destino = 6;
	
	agregarArco(&grafo, arco);
	
	
	
	
	visualizarMatrizAdyacencia(grafo);
	
	return 0;
}

//implementacion de funciones
void inicializarGrafo(tGrafoNoPonderado * pGrafo) {
	int x, y;
	
	for(x=0;x<N;x++) {
		pGrafo->vertices[x] = 0;
		for(y=0;y<N;y++) {
			pGrafo->arcos[x][y] = 0;
		}	
	}
	
	printf("Grafo inicialziado!\n");
	
} 

void agregarVertice(tGrafoNoPonderado * pGrafo, tVertice pVertice) {
	pGrafo->vertices[pVertice] = 1;
	printf("Se creo el vertice %d\n",pVertice);
}
void agregarArco(tGrafoNoPonderado * pGrafo, tArco pArco) {
	pGrafo->arcos[pArco.origen][pArco.destino] = 1;
	printf("Se creo arco %d -> %d \n",pArco.origen,pArco.destino);	
}

void visualizarMatrizAdyacencia(tGrafoNoPonderado  pGrafo) {
	
	int x, y; 
	printf("\nMatriz de adyacencia\n");
	printf("  1 2 3 4 5 6 7\n");
	for(x=1; x<=N; x++) {
		printf("%d ",x);
		for(y = 1; y <=N; y++) {
			if(pGrafo.arcos[x][y] == 1) {
				printf("1 ");
			} else {
				printf("0 ");
			}
		}
		printf("\n");
		
	}
}

