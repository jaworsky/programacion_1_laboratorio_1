#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"
#define A 2

//VIERNES Q VIENE 2 PARCIALITOS JUNTOS.
//crucigrama y ordenamiento: insertionsort y los 3 mas.

//todo lo q tiene q ver con mensajes, deberia de estar en el main. es la interfaz con el usuario.

int main()
{
    //sAlumno miAlumno={}; //definir una variable asi (cargada), es definirla por extension.
    //sAlumno otroAlumno;

    sAlumno listadoMain[A];

    int i;

    int opcion; // para el menu de opciones

    int auxInt;

    for(i=0;i<A;i++)
    {
        listadoMain[i].estado = VACIO;

    }

    do
    {
        printf("1.Alta\n 2.Modificar \n 3.Mostrar \n. 10.Salir\n Elija");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            //esta en carga secuencial, hay q pasarlo a aleatoria.
            i=cargarListadoDeAlumnos(listadoMain,A);

            if(i!=-1)
            {
                printf("Carga exitosa!\n");
            }
            else
            {
                printf("No hay espacio\n");
            }


        break;

        case 2:

        printf("Ingrese legajo a modificar: \n");
        scanf("%d",&auxInt);

        for(i=0;i<A;i++)//recorro el array para buscar
        {
            if(listadoMain[i].estado==OCUPADO  && auxInt==listadoMain[i].legajo)//TENGO Q PREGUNTAR SI ESTA OCUPAD
            {
                printf("Ingrese el nuevo promedio: \n");
                scanf("%f",&listadoMain[i].promedio);
                break;
                //agrear detalles! existe el legajo?, , diga si fue efectiva la modificacion.
            }

        }

        break;
        case 3:
        mostrarListadoDeAlumnos(listadoMain,A);
        break;

        }


    }while(opcion!=10);

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
