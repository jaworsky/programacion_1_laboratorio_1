#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMC 10
#define TAMJ 10
#define TAMA 10
#define TAMCAT 5
#include "clientes.h"
#include "validaciones.h"
#include "alquileres.h"

int main()
{

int flag1=0;
int opcion;
int codigoClienteAuto=6;
int codigoAlquierAuto=1;
int flagAlquiler=0;

eJuegos listaDeJuegos[TAMJ];
eClientes listaDeClientes[TAMC];
eCategoria listaDeCategorias[TAMCAT];
eAlquileres listaDeAlquileres[TAMA];

inicializarAlquileres(listaDeAlquileres,TAMA);
inicializarClientes(listaDeClientes,TAMC);

cargarCategorias(listaDeCategorias,TAMCAT);
hardCordearJuegos(listaDeJuegos, TAMJ);
hardCordearClientes(listaDeClientes,TAMC);

 do
        {

        switch(menu())
        {
        case 1://Alta
        altaCliente(listaDeClientes,TAMC,&codigoClienteAuto);
        flag1=1;

        break;

        case 2://modificar

        if(flag1=0)
        {
            printf("ERROR, primero debe cargar un cliente\n");
        }


        mostrarClientes(listaDeClientes,TAMC);

        system("pause");
        modificaCliente(listaDeClientes,TAMC);

        break;

        case 3://Baja

        if(flag1=0)
        {
            printf("ERROR, primero debe cargar un cliente\n");
        }

        bajaCliente(listaDeClientes,TAMC);

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

        mostrarAlquileres(listaDeAlquileres,TAMA);
        system("pause");

        break;

        case 7:
        opcion=7;
        break;


        }



        }while(opcion!=7);


    return 0;
}


//

//







