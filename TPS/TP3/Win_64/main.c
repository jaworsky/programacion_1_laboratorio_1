#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int menu();

int main()
{
    int option;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
         switch(menu())
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;

            default:
                printf("Ingrese una opcion del 1 al 10 por favor..\n");
                system("pause");
                break;
        }
    }while(option != 10);
    return 0;
}

int menu()
{
    int opcion;
    system("cls");
    printf("\n*** Menu de Opciones ***\n\n");
    printf(" 1- Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf(" 2- Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf(" 3- Alta de empleado.\n");
    printf(" 4- Modificar datos de empleado.\n");
    printf(" 5- Baja de empleado.\n");
    printf(" 6- Listar empleados.\n");
    printf(" 7- Ordenar empleados.\n");
    printf(" 8- Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf(" 9- Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf(" 10- Salir.\n");
    printf(" Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;

}
