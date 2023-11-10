#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char tString[10];

typedef struct {
	tString nombre;
	int edad;
}tRegistro;

FILE * archivoAlumnos;
tRegistro alumno;

//prototipos 
void abrirArchivo();
void leerRegistros();
void cerrarArchivos();

//main
int main() {
	abrirArchivo();
	leerRegistros();
	cerrarArchivos();
	return 0;
}

//implementacion
void abrirArchivo() {
	archivoAlumnos = fopen("alumnos.dat","rb");
	
	if(archivoAlumnos == NULL) {
		printf("error\n");
		exit(EXIT_FAILURE);
	} else {
		printf("archivo alumnos abierto\n");
	}
}
void leerRegistros() {
	
	fread(&alumno, sizeof(alumno), 1, archivoAlumnos);
	
	while(!feof(archivoAlumnos)) {
		printf("%s %d\n",alumno.nombre, alumno.edad);
		fread(&alumno, sizeof(alumno), 1, archivoAlumnos);
	}
	
	
}
void cerrarArchivos() {
	fclose(archivoAlumnos);
	printf("archivo alumnos cerrado");	
}

