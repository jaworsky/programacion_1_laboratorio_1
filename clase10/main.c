#include <stdio.h>
#include <stdlib.h>
#define TAM 2

typedef struct
{

    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int isEmpty;

} eEmpleado;

int menu(); // funcion para menu

void inicializarEmpleados (eEmpleado lista[],int tam);
void mostrarEmpleado(eEmpleado unEmpleado);
void mostrarEmplados(eEmpleado lista[], int tam);
int buscarLibre(eEmpleado lista[],int tam);
int buscarEmpleado(eEmpleado lista[], int tam, int legajo);
void altaEmpleado(eEmpleado lista[], int tam);

int main()
{

eEmpleado empleados[TAM];
char seguir = 's';

inicializarEmpleados(empleados,TAM);

do
{

    switch(menu()) // llamo a la funcion menu
    {
    case 1:

    printf("1.Alta\n\n");
    altaEmpleado(empleados, TAM);
    break;
    case 2:
    printf("2.Baja\n\n");
    system("pause");
    break;
    case 3:
    printf("3.Modificacion\n\n");
    system("pause");
    break;
    case 4:
    printf("4.Listar\n\n");
    mostrarEmpleados(empleados,TAM);
    system("pause");
    break;
    case 5:
    printf("4.Ordenar Empleados\n\n");
    system("pause");
    break;
    case 6:
    printf("6.Salir\n\n");
    seguir='n';
    break;


    }






}while(seguir == 's');



    return 0;
}



    int menu() // funcion para el menu
    {
    // validar todo

        int opcion;

        system("cls");
        printf("\n*** Menu de opciones ***\n\n");
        printf("1-Alta\n");
        printf("2-Baja\n");
        printf("3-Modificacion\n");
        printf("4-Listar empleados\n");
        printf("5-Ordenar Emplados\n");
        printf("Ingrese Opcion: ");
        scanf("%d",&opcion);

        return opcion;

    }


void inicializarEmpleados (eEmpleado lista[],int tam)
{


  for(int i=0;i<tam;i++)
    {
        lista[i].isEmpty = 1;
    }


}

void mostrarEmpleado(eEmpleado unEmpleado) // recibe 1 solo empleado
{

printf("%d %s %c %2.f \n",unEmpleado.legajo, unEmpleado.nombre,unEmpleado.sexo,unEmpleado.sueldo);


}

//funcion para mostrar emplados, recorre el array y le pasa los emplados a mostrar 1 empelado.

void mostrarEmpleados(eEmpleado lista[], int tam)
{

    system("cls");
    printf("Legajo Nombre Sexo Sueldo \n\n");

    for(int i=0;i<tam;i++)
    {

        if(lista[i].isEmpty==0)//el empleado q esta en ese indice
        {
            mostrarEmpleado(lista[i]);

        }


    }

}
//
int buscarLibre(eEmpleado lista[],int tam)
{
    int i;
    int indice=-1; // para saber si estan todos llenos

    for(i=0; i<tam; i++)
     {
         if(lista[i].isEmpty==1) // el estado esta vacio
         {
             indice=i;
             break; // para que corte al encontrar el primero, sino devolveria el ultimo.
         }


     }

    return indice; // devuelvo el indice que esta disponible para cargar.

}

//

int buscarEmpleado(eEmpleado lista[], int tam, int legajo) // sirve para buscar un empleado.
{
    {
    int i;
    int indice=-1; // no esta repetido

    for(i=0; i<tam; i++)
     {
         if(lista[i].legajo==legajo && lista[i].isEmpty==0) // chequea si esta el mismo legajo
         {
             indice=i; // devuelve el indice del empleado a modficiar.
             break; // para que corte al encontrar el primero, sino devolveria el ultimo.
         }
     }

    return indice; // devuelvo el indice que esta disponible para cargar.
}

}

// alta empleado

void altaEmpleado(eEmpleado lista[], int tam)
{
    int indice;
    int legajo;
    int existe;
    eEmpleado nuevoEmpleado;

    indice=buscarLibre(lista,tam);

    if(indice==-1) // o sea me devuelve el indice donde se puede cargar.
    {
        printf("No hay lugar en el sistema para cargar el empleado \n");
        system("pause");
    }
    else
    {
        printf("Ingrese el legajo: \n");
        scanf("%d",&legajo);

        existe=buscarEmpleado(lista,tam,legajo);

        if(existe!=-1) // me devuelve el legajo del empleado, lo miestro y aclaro que ese legajo, ya existe
        {
            printf("Ya existe un empleado con ese numero de legajo: %d \n",legajo);
            mostrarEmpleado(lista[existe]);
            system("pause");
        }
        else
        {
        nuevoEmpleado.legajo=legajo;
        printf("Ingrese nombre: \n");
        fflush(stdin);
        gets(nuevoEmpleado.nombre);
        printf("Ingrese sexo: \n");
        fflush(stdin);
        scanf("%c",&nuevoEmpleado.sexo);
        printf("Ingrese el sueldo: \n");
        fflush(stdin);
        scanf("%f",&nuevoEmpleado.sueldo);

        nuevoEmpleado.isEmpty=0; // pongo el estado lleno al array

        lista[indice]=nuevoEmpleado;

        printf("Se dio de alta un nuevo empleado!!");
        system("pause");

        }
    }
}


