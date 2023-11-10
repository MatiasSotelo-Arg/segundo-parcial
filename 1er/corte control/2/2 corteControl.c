/* Se tiene registrada la información sobre las notas de los exámenes finales de los alumnos de la facultad 
durante el presente año, en un archivo ordenado en forma ascendente por número de libreta. 
De cada alumno se conoce el: 

Número de Libreta (entero) 
Nombre y apellido ( char [50] )
Código de Materia (entero)
Nota Obtenida (real)

Se pide:
a) Listar un renglón por alumno con el promedio de notas obtenida.
b) Informar el total de alumnos.
c) Informar el alumno con mejor nota promedio
El formato de salida requerido es:

*** Listado de promedios ***
Número de Libreta Nota promedio
 xxxxx xx,xx
 xxxxx xx,xx
 ……… ……..
 xxxxx xx,xx
Total de alumnos: xxx
El alumno con mayor promedio es: xxxx xxxxx - Obtuvo: xx,xx 

acumuladorNotas
totalNotas

promedio 

subTotalAlumnos
totalAlumnos

alumnoMayorPromedio
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//tipos de datos
typedef char tString[50];

typedef struct {
	int nroLibreta;
	tString nombreApellido;
	int codMateria;
	float nota;
}tRegistroAlumno;

FILE * archivoNotas;
tRegistroAlumno registro;

float acumuladorNotas, promedio;
int totalNotas;

int subTotalAlumnos, totalAlumnos;

tRegistroAlumno ultimoRegistro,alumnoMayorPromedio;

//prototipos 
void inicializacion();
void procesoCorte();
void finalizacion();

void principioCorte();
void unGrupo();
void finCorte();

//main 
int main() {
	inicializacion();
	finalizacion();
	return 0;
}

//implementacion 
void inicializacion() {
	archivoNotas = fopen("notasAlumnos.dat","rb");
	
	if(archivoNotas != NULL) {
		printf("archivo abierto\n");
	} else {
		printf("error\n");
		exit(EXIT_FAILURE);
		printf("archivo cerrado\n");
	}
	
	fread(&registro, sizeof(tRegistroAlumno),1,archivoNotas);
	
	acumuladorNotas = 0;
	promedio = 0;
	totalNotas = 0;

	subTotalAlumnos = 0;
	totalAlumnos = 0;

	ultimoRegistro = registro;
	
	alumnoMayorPromedio = ultimoRegistro;
	
	printf("*** Listado de promedios ***\n");
	printf("Nro de Libreta | Nota promedio\n");
}

void procesoCorte() {
	while(!feof(archivoNotas)) {
		principioCorte();
	}	
}

void finalizacion(){
	fclose(archivoNotas);
	printf("archivo cerrado\n");
}



