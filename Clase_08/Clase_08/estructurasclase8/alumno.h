#define VACIO 0
#define OCUPADO 1

//en el punto.h tambien se declara la estructura.
typedef struct // definimos la estructura, con los diferentes tipos de variables.
{
    int legajo;
    char nombre[30];
    float promedio;
    int edad;
    int estado;//variable como bandera, para saber si el dato esta lleno o vacio..

}sAlumno; //definimos nombre de la estructura

//el brief siemrpe va al .h
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void mostrarUnAlumno(sAlumno);
sAlumno pedirAlumno(); // una funcion puede devolver una estructura.

/** \brief carga un alumno
 *
 * \param sAlumno[]
 * \param int
 * \return int -1: sino hay lugar >=0 si hay lugar.
 *
 */


int cargarListadoDeAlumnos(sAlumno listado[], int ); // no hace falta en el parametro pasarle el tamaño de la funcion

void mostrarListadoDeAlumnos(sAlumno listado[], int );

void ordenarAlumnosPorNombre(sAlumno listado[], int);

int buscarLibre(sAlumno[], int);
