#include <stdio.h>
#include <stdlib.h>
#define A 3


typedef struct // definimos la estructura, con los diferentes tipos de variables.
{
    int legajo;
    char nombre[30];
    float promedio;
    int edad;

}sAlumno; //definimos nombre de la estructura


void mostrarUnAlumno(sAlumno);
sAlumno pedirAlumno(); // una funcion puede devolver una estructura.


int main()
{
    //sAlumno miAlumno={}; //definir una variable asi (cargada), es definirla por extension.
    //sAlumno otroAlumno;

    sAlumno listadoMain[A];

    int i;

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

    for(i=0;i<A;i++) // barrido para mostrar el vector alumnos
   {
         mostrarUnAlumno(listadoMain[i]);//puede variar el que le paso
   }


    return 0;
}

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

