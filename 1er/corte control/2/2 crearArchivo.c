/* Número de Libreta (entero)
Nombre y apellido ( char [50] )
Código de Materia (entero)
Nota Obtenida (real) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

//tipos 
typedef char tString[50];

typedef struct {
	int nroLibreta;
	tString nombreApellido;
	int codMateria;
	float nota;
}tRegistroAlumno;

FILE * archivoNotas;
tRegistroAlumno registro;

//prototipos
void abrirArchivo();
void ingresarRegistro();
void cerrarArchivo();

//main
int main() {
	abrirArchivo();
	// Alumno 1
	registro.nroLibreta = 21;
	strcpy(registro.nombreApellido, "Gabriel Morales");
	registro.codMateria = 33;
	registro.nota = 8.50;
	ingresarRegistro(registro);
	
	registro.nroLibreta = 21;
	strcpy(registro.nombreApellido, "Gabriel Morales");
	registro.codMateria = 33;
	registro.nota = 7.80;
	ingresarRegistro(registro);
	
	registro.nroLibreta = 21;
	strcpy(registro.nombreApellido, "Gabriel Morales");
	registro.codMateria = 33;
	registro.nota = 9.20;
	ingresarRegistro(registro);
	
	// Alumno 2
	registro.nroLibreta = 22;
	strcpy(registro.nombreApellido, "Daniela Perez");
	registro.codMateria = 33;
	registro.nota = 7.75;
	ingresarRegistro(registro);
	
	registro.nroLibreta = 22;
	strcpy(registro.nombreApellido, "Daniela Perez");
	registro.codMateria = 33;
	registro.nota = 8.00;
	ingresarRegistro(registro);
	
	registro.nroLibreta = 22;
	strcpy(registro.nombreApellido, "Daniela Perez");
	registro.codMateria = 33;
	registro.nota = 7.00;
	ingresarRegistro(registro);
	
	// Alumno 3
	registro.nroLibreta = 23;
	strcpy(registro.nombreApellido, "Ricardo Fernandez");
	registro.codMateria = 33;
	registro.nota = 9.00;
	ingresarRegistro(registro);
	
	registro.nroLibreta = 23;
	strcpy(registro.nombreApellido, "Ricardo Fernandez");
	registro.codMateria = 33;
	registro.nota = 8.75;
	ingresarRegistro(registro);
	
	registro.nroLibreta = 23;
	strcpy(registro.nombreApellido, "Ricardo Fernandez");
	registro.codMateria = 33;
	registro.nota = 9.50;
	ingresarRegistro(registro);

	
	cerrarArchivo();
	return 0;
}

//implementacion 
void abrirArchivo() {
	archivoNotas = fopen("notasAlumnos.dat","wb");
	
	if(archivoNotas != NULL) {
		printf("archivo abierto\n");
	} else {
		printf("error\n");
		exit(EXIT_FAILURE);
	}
}

void ingresarRegistro() {
	fwrite(&registro,sizeof(tRegistroAlumno),1,archivoNotas);
	printf("%d %s %d %.2f\n",registro.nroLibreta, registro.nombreApellido, registro.codMateria, registro.nota);
}

void cerrarArchivo() {
	fclose(archivoNotas);
	printf("archivo cerrado\n");
}







