/* 1. Se tiene registrada la información sobre los movimientos de los clientes de un Banco. 
De cada movimiento se conoce: 

Número de Cuenta (entero)
Nombre del Cliente ( char [50] )
Código de Operación (entero)
Importe (real) - 1-Depósito;2-Extracción

Se solicita:
a) Listar el detalle de movimientos por cuenta.
b) Informar cantidad de movimientos y totales de importes de depósitos y extracción, por cuenta.
El formato de salida requerido es:

*** Detalle de Movimientos por cuenta ***
Nro.Cuenta Depósito Extracción
111  	   xxxxx,xx 0
111 	   0 		xxxxx,xx
111 	   xxxxx,xx 0
111		   0 		xxxxx,xx

Total Cta 111 Cantidad de mov. Cta 111 2 2

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//tipos de datos
typedef char tString[50];

typedef struct {
	int nroCuenta;
	tString nombreCliente;
	int codOperacion; //1-Depósito, 2-Extracción.
	float importe;
}tRegistro;

tRegistro cliente, registroAnterior;

FILE * archivoMovBanco;

int totalDepositos, totalExtraccion;

//prototipo
void inicializacion(); 
void procesoCorte();
void finalizacion();

void principioCorte();
void unGrupo();
void finCorte();

//main
int main() {
	inicializacion();
	procesoCorte();
	finalizacion();
	return 0;
}

//implementacion
void inicializacion() {
	//abrir archivo
	archivoMovBanco = fopen("movimientosClientes.dat","rb");
	
	if(archivoMovBanco == NULL) {
		printf("error\n");
		exit(EXIT_FAILURE);
	} else {
		printf("archivo abierto\n");
		//primer lectura
		fread(&cliente, sizeof(tRegistro),1,archivoMovBanco);
	} 
	
	//inicializa variables
	registroAnterior = cliente;
	totalDepositos = 0;
	totalExtraccion = 0;
	
	printf("*** Detalle de Movimientos por cuenta ***\n");
	
	printf("|Nro.Cuenta |Deposito |Extraccion|\n");
}

void procesoCorte() {

	while(!feof(archivoMovBanco)) { 
		principioCorte();
		while(!feof(archivoMovBanco) && cliente.nroCuenta == registroAnterior.nroCuenta) {
			unGrupo();
			fread(&cliente, sizeof(tRegistro),1,archivoMovBanco);
		}
		finCorte();
	}		
}

void principioCorte() {
	totalDepositos = 0;
	totalExtraccion = 0;
}

void unGrupo() {
	
	printf("|%-11s|%-9.2f|%-10.2f|\n", cliente.nombreCliente, cliente.codOperacion == 1 ? cliente.importe : 0, cliente.codOperacion == 2 ? cliente.importe : 0);

	cliente.codOperacion == 1 ? totalDepositos++ : totalExtraccion++;
	
}
void finCorte() {
	printf("\nCantidad de mov. Cta %-s %d %d\n\n",cliente.nombreCliente, totalDepositos, totalExtraccion);
	registroAnterior = cliente;
}

void finalizacion() {
	fclose(archivoMovBanco);
	printf("archivo cerrado");
}
