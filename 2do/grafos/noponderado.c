/* 5. Escribir en lenguaje C, la declaración del tipo de dato tGrafoNoPonderado, para un grafo no ponderado 
de hasta 7 vértices. 

Utilizar la implementación de grafos con arrays. Además, escribir las funciones para:
a) iniciar el grafo
b) agregar un vértice al grafo 
c) agregar un arco al grafo
d) visualizar la matriz de adyacencia de un grafo */

#include <stdio.h>
#include <stdbool.h>

#define N 7
//tipos datos
typedef int tVertice;

typedef struct {
	tVertice origen;
	tVertice destino;
}tArco;

typedef bool conjuntoVertices[N];
typedef tVertice conjuntoArcos[N][N];

typedef struct {
	conjuntoVertices vertices;
	conjuntoArcos arcos;
}tGrafo;

tGrafo grafo;
tArco arco;

//prototipos 
void inicializarGrafo(tGrafo *);
void agregarVertice(tGrafo *,tVertice);
void agregarArcos(tGrafo *, tArco);
void mostrarMatrizAdyacencia(tGrafo);

//main
int main() {
	inicializarGrafo(&grafo);
	
	agregarVertice(&grafo,0);
	agregarVertice(&grafo,1); 
	
	arco.origen = 0; 
	arco.destino = 1; 
	
	agregarArcos(&grafo,arco);
	
	agregarVertice(&grafo,6);
	
	arco.origen = 1; 
	arco.destino = 6;
	
	agregarArcos(&grafo,arco);
	
	mostrarMatrizAdyacencia(grafo);
	return 0;
}

//implementacion 
void inicializarGrafo(tGrafo * pGrafo) {
	int i, j;
	
	for(i=0;i<N;i++) {
		pGrafo->vertices[i] = 0;
		for(j=0;j<N;j++) {
			pGrafo->arcos[i][j] = 0;
		}
	}
	printf("Grafo inicializado\n");
}

void agregarVertice(tGrafo * pGrafo, tVertice pVertice) {
	pGrafo->vertices[pVertice] = 1;
	printf("vertice ingresado %d\n",pVertice+1);
}

void agregarArcos(tGrafo * pGrafo, tArco pArco) {
	if(pGrafo->vertices[pArco.origen] == 1 && pGrafo->vertices[pArco.destino] == 1) {
		pGrafo->arcos[pArco.origen][pArco.destino] = 1;
		printf("vertice ingresado %d -> %d\n",pArco.origen+1, pArco.destino+1);
	} else {
		printf("error pq no existe algun vertice\n");
	}
}

void mostrarMatrizAdyacencia(tGrafo pGrafo) {
	int i, j;
	for(i = 0; i<N;i++) {
		for(j=0;j<N;j++) {
			if(pGrafo.arcos[i][j] == 1) {
				printf("1 ");
			} else {
				printf("0 ");
			}
		}
		printf("\n");
	}
}


