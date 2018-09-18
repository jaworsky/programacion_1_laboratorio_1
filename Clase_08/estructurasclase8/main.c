#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"
#define A 2


int main()
{
    //sAlumno miAlumno={}; //definir una variable asi (cargada), es definirla por extension.
    //sAlumno otroAlumno;

    sAlumno listadoMain[A];

    int i;

/*
    for(i=0;i<A;i++) // le guardo el alumno en la posicion del array.
    {
        listadoMain[i]=pedirAlumno();

    }


/*
    for(i=0;i<A;i++) // carga secuencial del vector de alumnos
    {
    printf("Ingrese legajo: \n");
    scanf("%d",&listadoMain[i].legajo ); //se le pasa la variable indicando la posicion de memoria.

    printf("Ingrese el nombre: \n");
    fflush(stdin);
    gets(listadoMain[i].nombre);

    printf("Ingrese el promedio: \n");
    scanf("%f",&listadoMain[i].promedio);

    printf("Ingrese edad: \n");
    scanf("%d",&listadoMain[i].edad);


    }

   /*
    printf("Ingrese legajo: \n");
    scanf("%d", &miAlumno.legajo); //se le pasa la variable indicando la posicion de memoria.

    printf("Ingrese el nombre: \n");
    fflush(stdin);
    gets(miAlumno.nombre);

    printf("Ingrese el promedio: \n");
    scanf("%f",&miAlumno.promedio);

    printf("Ingrese edad: \n");
    scanf("%d",&miAlumno.edad);


    //otroAlumno=miAlumno; // las estrcucturase se pueden copiar entre si,

   /* if(otroAlumno==miAlumno); // no se puede hacer esta comparacion.
    {

    */

    //printf("%d--%s--%.2f\n",otroAlumno.legajo,otroAlumno.nombre,otroAlumno.promedio); //con el punto nos referimos en orden a las variables
     //printf("%d--%s--%.2f\n",miAlumno.legajo,miAlumno.nombre,miAlumno.promedio);


   // miAlumno = pedirAlumno(); // le asignamos la copia del valor a mi alumno.
/*
    for(i=0;i<A;i++) // barrido para mostrar el vector alumnos
   {
         mostrarUnAlumno(listadoMain[i]);//puede variar el que le paso
   }
*/

cargarListadoDeAlumnos(listadoMain,A);
mostrarListadoDeAlumnos(listadoMain,A);

printf("Ordenar \n");

ordenarAlumnosPorNombre(listadoMain, A);

mostrarListadoDeAlumnos(listadoMain,A);

    return 0;
}


// cada opcion que se pida, ponerl odentro de una opcion del menu

// menu de opciones con carga aleatoria, preg al usuario donde kiere guardar.
//pensar la modificacion,  // graficos de barra con C con *, vertical.
