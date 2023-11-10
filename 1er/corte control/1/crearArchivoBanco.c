/*

Número de Cuenta (entero)
Nombre del Cliente ( char [50] )
Código de Operación (entero)
Importe (real) - 

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

tRegistro cliente;

FILE * archivoMovBanco;

//prototipos 
void abrirArchivo();
void guardarRegistro(tRegistro);
void cerrarArchivo();

int main() {
	
	abrirArchivo();
	
	// Movimiento 1
	cliente.nroCuenta = 1;
	strcpy(cliente.nombreCliente, "Ana");
	cliente.codOperacion = 1; // Depósito
	cliente.importe = 200.00;
	guardarRegistro(cliente);
	
	// Movimiento 2
	cliente.nroCuenta = 1;
	strcpy(cliente.nombreCliente, "Ana");
	cliente.codOperacion = 2; // Extracción
	cliente.importe = 25.00;
	guardarRegistro(cliente);
	
	// Movimiento 3
	cliente.nroCuenta = 1;
	strcpy(cliente.nombreCliente, "Ana");
	cliente.codOperacion = 2; // Extracción
	cliente.importe = 50.00;
	guardarRegistro(cliente);
	
	// Movimiento 4
	cliente.nroCuenta = 2;
	strcpy(cliente.nombreCliente, "Luis");
	cliente.codOperacion = 2; // Extracción
	cliente.importe = 50.00;
	guardarRegistro(cliente);
	
	// Movimiento 5
	cliente.nroCuenta = 2;
	strcpy(cliente.nombreCliente, "Luis");
	cliente.codOperacion = 1; // Depósito
	cliente.importe = 120.00;
	guardarRegistro(cliente);
	
	// Movimiento 6
	cliente.nroCuenta = 2;
	strcpy(cliente.nombreCliente, "Luis");
	cliente.codOperacion = 2; // Extracción
	cliente.importe = 90.00;
	guardarRegistro(cliente);
	
	// Movimiento 7
	cliente.nroCuenta = 3;
	strcpy(cliente.nombreCliente, "Elena");
	cliente.codOperacion = 1; // Depósito
	cliente.importe = 75.50;
	guardarRegistro(cliente);
	
	// Movimiento 8
	cliente.nroCuenta = 3;
	strcpy(cliente.nombreCliente, "Elena");
	cliente.codOperacion = 2; // Extracción
	cliente.importe = 30.00;
	guardarRegistro(cliente);
	
	// Movimiento 9
	cliente.nroCuenta = 3;
	strcpy(cliente.nombreCliente, "Elena");
	cliente.codOperacion = 1; // Depósito
	cliente.importe = 150.00;
	guardarRegistro(cliente);

	cerrarArchivo();
	
	return 0;
}

//implementacion 
void abrirArchivo() {
	archivoMovBanco = fopen("movimientosClientes.dat","wb");
	if(archivoMovBanco == NULL) {
		printf("error\n");
		exit(EXIT_FAILURE);
	} else {
		printf("archivo abierto\n");
	}
}

void guardarRegistro(tRegistro pRegistro) {
	fwrite(&pRegistro, sizeof(tRegistro),1,archivoMovBanco);
	printf("%-2d %-6s %-10s $%.2f\n", pRegistro.nroCuenta, pRegistro.nombreCliente, pRegistro.codOperacion == 1 ? "Deposito" : "Extraccion", pRegistro.importe);
}
	
void cerrarArchivo() {
	fclose(archivoMovBanco);
	printf("archivo cerrado\n");
}
