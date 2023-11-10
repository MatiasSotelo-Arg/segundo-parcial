/* Se tiene registrada la informaci�n sobre las notas de los ex�menes finales de los alumnos de la facultad 
durante el presente a�o, en un archivo ordenado en forma ascendente por n�mero de libreta. 
De cada alumno se conoce el: 

N�mero de Libreta (entero) 
Nombre y apellido ( char [50] )
C�digo de Materia (entero)
Nota Obtenida (real)

Se pide:
a) Listar un rengl�n por alumno con el promedio de notas obtenida.
b) Informar el total de alumnos.
c) Informar el alumno con mejor nota promedio
El formato de salida requerido es:

*** Listado de promedios ***
N�mero de Libreta Nota promedio
 xxxxx xx,xx
 xxxxx xx,xx
 ��� ��..
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

tRegistroALumno alumnoMayorPromedio;

//prototipos 
inicializacion();
procesoCorte();
finalizacion();

principioCorte();
unGrupo();
finCorte();

//main 
int main() {
	return 0;
}

//implementacion 
void inicializacion() {
	archivoNotas = fopen("notasAlumnos.dat","rb");
	
	if(archivoNotas != NULL) {
		printf("archivo abierto\n");
	} else {
		printf("error\");
		exit(EXIT_FAILURE);
		printf("archivo cerrado\n");
	}
}



