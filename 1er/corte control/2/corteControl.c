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

//variables globales
FILE * archivoNotas;
tRegistroAlumno registro, registroAnterior, alumnoMayorPromedio;

int cantNotas,totalAlumnos;
float sumaNotas, promedio, promedioMayor;


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
	archivoNotas = fopen("notasAlumnos.dat","rb");
	
	if(archivoNotas != NULL) {
		printf("archivo abierto\n");
		fread(&registro,sizeof(tRegistroAlumno),1,archivoNotas);
	} else {
		printf("error\n");
		exit(EXIT_FAILURE);
		printf("archivo cerrado\n");
	}
	
	
	cantNotas = 0; 
	sumaNotas = 0;
	promedio = 0;
	promedioMayor = 0;
	totalAlumnos = 0;
	
	alumnoMayorPromedio = registro;
	registroAnterior = registro;
	
	printf("*** Listado de promedios ***\n");
	printf("Nro de Libreta | Nota promedio");
}

void procesoCorte() {
	while(!feof(archivoNotas)) {
		principioCorte();
		while(!feof(archivoNotas) && registro.nroLibreta == registroAnterior.nroLibreta) {
			unGrupo();
			fread(&registro,sizeof(tRegistroAlumno),1,archivoNotas);
		}
		finCorte();
	}
}

void principioCorte() {
	cantNotas = 0;
	sumaNotas = 0;
	promedio = 0;
	promedioMayor = 0;
}

void unGrupo() {
	cantNotas++;
	sumaNotas = sumaNotas + registro.nota;	
}

void finCorte() {
	promedio = sumaNotas / (float) cantNotas;
	
	if(promedio > promedioMayor) {
		promedioMayor = promedio;
		alumnoMayorPromedio = registroAnterior;
	}
	
	totalAlumnos++; 
	
	printf("%d %.2f",registro.nroLibreta, promedio);
}

void finalizacion() {

	printf("Total de alumnos: %d\n",totalAlumnos);
	printf("El alumno con mayor promedio es: %s %.2f\n",alumnoMayorPromedio.nombreApellido,promedioMayor);
	
	fclose(archivoNotas);
	printf("archivo cerrado\n");
}


