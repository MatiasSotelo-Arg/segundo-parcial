#include <stdio.h>

#define N 10

typedef int tVectorInt;

tVectorInt vector[N] = {2,3,1,5,4,7,6,9,8,10};

//prototipo
void metodoBurbuja(tVectorInt *);
void mostrarVector(tVectorInt *);

//main 
int main() {
	metodoBurbuja(vector);
	mostrarVector(vector);
	
	return 0;
}

void mostrarVector(tVectorInt * pVector) {
	int i = 0;
	
	for(i;i<N;i++) {
		printf("%d ",pVector[i]);
	}
}

void metodoBurbuja(tVectorInt * pVector) {
	int i, j, aux;
	
	for(i = 0; i<N-1; i++) {
		for(j = 0; j<N-1; j++) {
			if(pVector[j] > pVector[j+1]) {
				aux = pVector[j];
				pVector[j] = pVector[j+1];
				pVector[j+1] = aux; 
			}
		}
	}
}





