#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

typedef char tString[10];

typedef struct {
	tString nombre;
	int edad;
}tRegistro;

FILE * archivoAlumnos;
tRegistro alumno;

//implementacion 
void abrirArchivo(); 
void agregarRegistro(tRegistro);
void cerrarArchivo();

int main() {
	abrirArchivo(); 
	
	strcpy(alumno.nombre,"matias");
	alumno.edad = 24;
	
	agregarRegistro(alumno);
	 
	strcpy(alumno.nombre,"fernando");
	alumno.edad = 20;
	
	agregarRegistro(alumno);
	cerrarArchivo();
	return 0;
}

void abrirArchivo() {
	archivoAlumnos = fopen("alumnos.dat","wb");
	
	if(archivoAlumnos == NULL) {
		printf("error");
		exit(EXIT_FAILURE);
	} else {
		printf("archivo alumnos abierto\n");
	}
}

void agregarRegistro(tRegistro pRegistro) {
	fwrite(&pRegistro, sizeof(tRegistro), 1 , archivoAlumnos);
	printf("alumno %s %d ingresado\n",alumno.nombre,alumno.edad);
}

void cerrarArchivo() {
	fclose(archivoAlumnos);
	printf("Archivo cerrado");
}
