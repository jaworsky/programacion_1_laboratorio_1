#include <stdio.h>
#include "alumno.h"
#include <string.h>

void mostrarUnAlumno(sAlumno miAlumno) // siemrpe le voy a pasar un alumno
{
    printf("%d--%s--%.2f--%d\n",miAlumno.legajo,miAlumno.nombre,miAlumno.promedio,miAlumno.edad);
}

sAlumno pedirAlumno()
{


    sAlumno alumnito; // alumno local de la funcion

    printf("Ingrese legajo: \n");
    scanf("%d", &alumnito.legajo); //se le pasa la variable indicando la posicion de memoria.

    printf("Ingrese el nombre: \n");
    fflush(stdin);
    gets(alumnito.nombre);

    printf("Ingrese el promedio: \n");
    scanf("%f",&alumnito.promedio);

    printf("Ingrese edad: \n");
    scanf("%d",&alumnito.edad);

    return alumnito; // devuelve una copia de estos valores.

}

void cargarListadoDeAlumnos(sAlumno listado[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
     {
         listado[i]=pedirAlumno();
     }

}

void mostrarListadoDeAlumnos(sAlumno listado[], int tam)
{
    int i;

    for(i=0;i<tam;i++) // barrido para mostrar el vector alumnos
   {
         mostrarUnAlumno(listado[i]);//puede variar el que le paso
   }

}

void ordenarAlumnosPorNombre(sAlumno listado[], int tam) // PRESTAR ATENCION COMO SE DEBE SER EL SWAP.
{

/*
int auxint;
float auxFloat;
char auxString[50];
*/
//UN UNICO AUXILIAR.

sAlumno auxAlumno;

int i;
int j;

for(i=0;i<tam-1;i++)
{
    for(j=i+1;j<tam;j++)
    {

        if(strcmp(listado[i].nombre,listado[j].nombre)>0)//criterio de ordenamiento, hay que agregar el .nombre
        {
            /*
            auxint = listado [i].legajo;  // ASI NO SE HACE
            listado[i].legajo=listado[j].legajo;
            listado[j].legajo=auxint;
            */
            auxAlumno = listado [i];
            listado[i]= listado [j];
            listado[j]=auxAlumno;



        }
    }

}



}
