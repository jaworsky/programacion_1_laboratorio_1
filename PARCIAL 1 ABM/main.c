#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMC 10
#define TAMJ 50
#define TAMA 10
#define TAMCAT 5
#include "clientes.h"
#include "validaciones.h"
#include "alquileres.h"
#include "juegos.h"

int menu();
void mostrarJuego(eJuegos juegoAmostrar);
void juegosCategoriaMesa(eJuegos arrayDeJuegos[],int tamj);
void alquileresXcliente(eAlquileres arrayDeAlquileres[], int tama,eClientes arrayDeClientes[],int tamc,eJuegos arraDeJuegos[],int tamj);

int main()
{

    int flag1=0;
    int opcion;
    int codigoClienteAuto=6;
    int codigoAlquierAuto=6;
    int codigoJuegoAuto=11;
    int flagAlquiler=0;

    eJuegos listaDeJuegos[TAMJ];
    eClientes listaDeClientes[TAMC];
    eCategoria listaDeCategorias[TAMCAT];
    eAlquileres listaDeAlquileres[TAMA];

    inicializarJuegos(listaDeJuegos,TAMJ);
    inicializarAlquileres(listaDeAlquileres,TAMA);
    inicializarClientes(listaDeClientes,TAMC);

    cargarCategorias(listaDeCategorias,TAMCAT);
    hardCordearJuegos(listaDeJuegos, TAMJ);
    hardCordearClientes(listaDeClientes,TAMC);
    hardCordearAlquileres(listaDeAlquileres,TAMA);


    do
    {

        switch(menu())
        {
        case 1://Alta
            altaCliente(listaDeClientes,TAMC,&codigoClienteAuto);
            flag1=1;

            break;

        case 2://Baja

            if(flag1=0)
            {
                printf("ERROR, primero debe cargar un cliente\n");
            }

            bajaCliente(listaDeClientes,TAMC);

            break;

        case 3://Modificacion

            if(flag1=0)
            {
                printf("ERROR, primero debe cargar un cliente\n");
            }


            mostrarClientes(listaDeClientes,TAMC);

            system("pause");
            modificaCliente(listaDeClientes,TAMC);

            break;

        case 4://listar
            listarCategorias(listaDeCategorias,5);
            listarJuegos(listaDeJuegos,TAMJ);
            ordenarClientesPorSexoYnombre(listaDeClientes,TAMC);
            mostrarClientes(listaDeClientes,TAMC);
            system("pause");

            break;

        case 5: //Alquileres

            altaAlquiler(listaDeAlquileres,TAMA,listaDeClientes,TAMC,listaDeJuegos,TAMJ,listaDeCategorias,TAMCAT,&codigoAlquierAuto);
            flagAlquiler=1;
            printf("Alquier cargado con exito!\n");
            system("pause");

            break;

        case 6: //Mostrar Alquileres

            if(flagAlquiler=0)
            {
                printf("ERROR, primero debe cargar un alquiler\n");
                system("pause");
                break;

            }

            mostrarAlquileres2(listaDeAlquileres,TAMA,listaDeClientes,TAMC,listaDeJuegos,TAMJ);
            system("pause");

            break;

        case 7: // Alta juegos

            altaJuegos(listaDeJuegos,TAMJ);

            break;

        case 10: //jeugos de categoria mesa
            listarJuegos(listaDeJuegos,TAMJ);
            juegosCategoriaMesa(listaDeJuegos,TAMJ);
            system("pause");
            break;

        case 11://alquileres efectuados por algun cliente seleccionado.

            alquileresXcliente(listaDeAlquileres,TAMA,listaDeClientes,TAMC,listaDeJuegos,TAMJ);
            system("pause");

            break;

        case 12: //importe por cliente

            importeXcliente(listaDeAlquileres,TAMA,listaDeClientes,TAMC,listaDeJuegos,TAMJ);
            system("pause");

            break;

        case 13: //juego x cliente

            juegoXcliente(listaDeAlquileres,TAMA,listaDeClientes,TAMC,listaDeJuegos,TAMJ);
            system("pause");

            break;

        case 14:

            clientesQueNoAlquilan(listaDeAlquileres,TAMA,listaDeClientes,TAMC);

            break;

        case 20 :
            opcion=20;
            break;

        }

    }
    while(opcion!=20);


    return 0;
}
//
int menu()
{
        char auxOpcion[10];
        int opcion;

        system("cls");
        printf("\n*** Bienvenido!!***\n");
        printf("\n*** Menu de opciones ***\n\n\n");
        printf("1-Alta Cliente\n");
        printf("2-Baja de Cliente\n");
        printf("3-Modificar Datos\n");
        printf("4-Listar\n"); // en este caso, informar los 2 puntos
        printf("5-Alta Alquiler\n");
        printf("6-Mostrar Alquileres\n");
        printf("7-Alta Juegos\n");
        printf("8-Baja Juegos\n");
        printf("9-Modificar Juegos\n");


        printf("10-Mostrar Juegos de categoria mesa\n");
        printf("11-Mostrar Alquileres por cliente\n");
        printf("12-Mostrar importe por cliente\n");
        printf("13-Mostrar Clientes que alquilaron un determinado juego\n");
        printf("14-Mostrar Clientes que no alquilaron\n");
        printf("20-Salir\n");


        while(!function_getStringNumeros("Ingrese la opcion deseada: \n",auxOpcion))
        {
            {
            printf("Error ingrese una opcion numerica del 1 al 20\n.");
            system("pause");
            fflush(stdin);
            }
        }
            opcion=atoi(auxOpcion);

            if(opcion<1 || opcion>20)
            {
            printf("Error ingrese una opcion numerica del 1 al 20\n.");
            system("pause");
            fflush(stdin);
            }

    return opcion;
}

//

//
void mostrarJuegoDeCatMesa(eJuegos juegoAmostrar)
{
    printf("Los juegos de categoria mesa son: %d, descripcion: %s \n , de la categoria: %d\n\n",juegoAmostrar.codigo,juegoAmostrar.descripcion,juegoAmostrar.idCategoria);
}
//
void alquileresXcliente(eAlquileres arrayDeAlquileres[], int tama,eClientes arrayDeClientes[],int tamc, eJuegos arrayDeJuegos[],int tamj)
{
    int auxCodCliente;
    mostrarClientes(arrayDeClientes,tamc);
    auxCodCliente=function_getInt("Ingrese el codigo del cliente: \n\n");

    int flag = 0;

    system("cls");
    printf("id   cod de juego:   cod de cliente:   fecha:   \n\n");

    for(int i=0; i < tama; i++)
    {
        if(arrayDeAlquileres[i].codigoDeCliente==auxCodCliente && arrayDeAlquileres[i].isEmpty==0)
        {
            mostrarAlquiler2(arrayDeAlquileres[i],arrayDeClientes[i],arrayDeJuegos[i]);


            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay alquileres cargados para ese cliente");
    }
    printf("\n\n");
}
//
void clientesQueNoAlquilan(eAlquileres arrayDeAlquileres[], int tama,eClientes arrayDeClientes[],int tamc)
{
    system("cls");

    int j;
    int i;

    for(int i=0; i<tamc; i++)
    {
        if(arrayDeClientes[i].isEmpty==0)

        {

            for( j=0; j<tama; j++)//reorro array de alquileres
            {

                if(arrayDeAlquileres[j].codigoDeCliente==arrayDeClientes[i].codigoCliente && arrayDeAlquileres[j].isEmpty==0)
                {

                    break; // para que salte el if
                }

            }

            if( j==tama)
            {
                mostrarCliente(arrayDeClientes[i]);
            }


            }
        }

        system("pause");

    }
//
    void juegoXcliente(eAlquileres arrayDeAlquileres[], int tama,eClientes arrayDeClientes[],int tamc,eJuegos arrayDeJuegos[],int tamj)
    {
        int auxCodDeJuego;
        int auxCliente,index;

        listarJuegos(arrayDeJuegos,tamj);
        auxCodDeJuego=function_getInt("Ingrese el codigo del juego: \n\n");

        int flag = 0;

        system("cls");
        printf("Clientes que alquilaron el juego %d\n",auxCodDeJuego);
        printf("id   cod de juego:   cod de cliente:   fecha:   \n\n");

        for(int i=0; i < tama; i++)
        {
            if(arrayDeAlquileres[i].codigoDeJuego==auxCodDeJuego && arrayDeAlquileres[i].isEmpty==0)
            {
             auxCliente=buscarCliente(arrayDeClientes,tamc,arrayDeAlquileres[i].codigoDeCliente);
            // mostrarCliente(arrayDeClientes[auxCliente]);
                //index=arrayDeAlquileres[i].codigoDeCliente-1;
                mostrarCliente(arrayDeClientes[index]);
                flag = 1;
            }
        }

        if(flag == 0)
        {
            printf("No se alquilo ese juego\n");
        }
        printf("\n\n");
    }
//
    void hardCordearAlquileres(eAlquileres arraydealquileres[], int tama)
    {
        eAlquileres hardCodeoAlquiler[]=
        {
            {1,2,2,{12,10,2018},0},
            {2,3,3,{11,9,2018},0},
            {3,1,4,{12,1,2018},0},
            {4,1,5,{9,2,2018},0},
            {5,4,1,{1,1,2018},0}
        };

          for(int i=0; i < 5; i++)
        {
            arraydealquileres[i] = hardCodeoAlquiler[i];
        }
    }
//
    void importeXcliente(eAlquileres arrayDeAlquileres[], int tama,eClientes arrayDeClientes[],int tamc,eJuegos arrayDeJuegos[],int tamj)
    {
        int auxCodCliente;
        int deuda;

        mostrarClientes(arrayDeClientes,tamc);
        auxCodCliente=function_getInt("Ingrese el codigo del cliente: \n\n");

        int flag = 0;

        system("cls");
        printf("id   cod de juego:   cod de cliente:   fecha:   \n\n");

        for(int i=0; i < tama; i++)
        {
            if(arrayDeAlquileres[i].codigoDeCliente==auxCodCliente && arrayDeAlquileres[i].isEmpty==0)
            {
                mostrarAlquiler2(arrayDeAlquileres[i],arrayDeClientes[i],arrayDeJuegos[i]);

                deuda=arrayDeJuegos[i].importe;

                flag = 1;
            }
        }

        printf("El cliente abono: %d \n",deuda);

        if(flag == 0)
        {
            printf("No hay alquileres cargados para ese cliente");
        }
        printf("\n\n");
    }
//
    void mostrarAlquiler2 (eAlquileres alquilerAmostrar, eClientes clienteAmostrar,eJuegos juegoAmostrar)
    {

        printf("\ncodigo de alquiler: %d  codigo de juego: %d \n descripcion: %s \n codigo de cliente: %d , fecha:  %02d/%02d/%d\n  nombre: %s\n",alquilerAmostrar.codigoDeAlquiler,alquilerAmostrar.codigoDeJuego,juegoAmostrar.descripcion,alquilerAmostrar.codigoDeCliente,alquilerAmostrar.fecha.dia,alquilerAmostrar.fecha.mes,alquilerAmostrar.fecha.anio,clienteAmostrar.nombre);
    }
//
    void mostrarAlquileres2(eAlquileres arraydealquileres[], int tama,eClientes arrayDeClientes[],int tamc,eJuegos arrayDeJuegos[],int tamj)
    {
        int flag = 0;

        system("cls");

        for(int i=0; i < tama; i++)
        {
            if( arraydealquileres[i].isEmpty == 0)
            {
                mostrarAlquiler2(arraydealquileres[i],arrayDeClientes[i],arrayDeJuegos[i]);
                flag = 1;
            }
        }

        if(flag == 0)
        {
            printf("No hay alquileres cargados");
        }
        printf("\n\n");
    }
// a terminar //
    /*

    void mostrarAlquiler3 (eAlquileres alquilerAmostrar, eClientes clienteAmostrar,int tamc,eJuegos juegoAmostrar)
    {

        char auxNombreCliente[50];

        auxNombreCliente=obtenerNombreCliente()


        printf("\ncodigo de alquiler: %d  codigo de juego: %d \n descripcion: %s \n codigo de cliente: %d , fecha:  %02d/%02d/%d\n  nombre: %s\n",alquilerAmostrar.codigoDeAlquiler,alquilerAmostrar.codigoDeJuego,juegoAmostrar.descripcion,alquilerAmostrar.codigoDeCliente,alquilerAmostrar.fecha.dia,alquilerAmostrar.fecha.mes,alquilerAmostrar.fecha.anio,clienteAmostrar.nombre);
    }

    */

// obtener nombre de cliente para mostrar, utilizando el cod de cliente:
    void obtenerNombreCliente(eClientes c[], int tamc, int codigoDeClienteAlquiler, char* cadena)
    {
        for(int i=0; i < tamc; i++)
        {
            if( c[i].codigoCliente == codigoDeClienteAlquiler)
            {
                strcpy(cadena, c[i].nombre);
            }
        }
    }
//
//void obtenerDescripcionCategoria()

//

 void juegoXcliente2(eAlquileres arrayDeAlquileres[], int tama,eClientes arrayDeClientes[],int tamc,eJuegos arrayDeJuegos[],int tamj)
    {
        int auxCodDeJuego;
        int auxCliente,index;

        listarJuegos(arrayDeJuegos,tamj);
        auxCodDeJuego=function_getInt("Ingrese el codigo del juego: \n\n");

        system("cls");
        printf("Clientes que alquilaron el juego %d\n",auxCodDeJuego);
        printf("id   cod de juego:   cod de cliente:   fecha:   \n\n");

    int j;
    int i;

    for(int i=0; i<tamc; i++)
    {
        if(arrayDeClientes[i].isEmpty==0)

        {

            for( j=0; j<tama; j++)//recorro array de alquileres
            {

                if(arrayDeAlquileres[j].codigoDeJuego==auxCodDeJuego && arrayDeAlquileres[j].isEmpty==0)
                {

                     mostrarCliente(arrayDeClientes[i]);
                }

            }

        }
    }

        system("pause");

    }
