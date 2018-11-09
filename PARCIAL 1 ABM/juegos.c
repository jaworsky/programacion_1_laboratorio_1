#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "clientes.h"
#include "juegos.h"
#include "alquileres.h"


void inicializarJuegos (eJuegos arrayDeJuegos[], int tamj)
{

    for(int i=0; i < tamj; i++)
    {

        arrayDeJuegos[i].isEmpty = 1;
    }

}

//
void hardCordearJuegos(eJuegos juegos[], int tamjuegos)
{
    eJuegos juegosstock[]=
    {
        {1, "juego de accion", 50 ,4,0},
        {2, "juego de magia", 100,5,0 },
        {3, "juego de estrategia en tiempo real", 125,3,0},
        {4, "juego de sumas y restas", 150,1,0},
        {5, "juego de suerte", 10,2,0},
        {6, "juego para multiplicar" , 25,1,0},
        {7, "juego de pelea", 75,4,0},
        {8, "juego de baile", 150,4,0},
        {9, "juego de ingenio", 200,1,0},
        {10, "juegos de resolver problemas", 250,1,0}
    };

    for(int i=0; i < 10; i++)
    {
        juegos[i] = juegosstock[i];
    }
}
//
void listarJuegos(eJuegos arraydejuegos[], int tamj)
{

    printf("Descripcion\n\n");
    for(int i=0; i< tamj; i++)
    {
        printf("codigo: %d descpripcion: %10s \n ID Categoria: %d importe: %d \n\n", arraydejuegos[i].codigo, arraydejuegos[i].descripcion,arraydejuegos[i].idCategoria,arraydejuegos[i].importe);
    }
    printf("\n\n");
}
//

int buscarLibreJuegos(eJuegos arrayDeJuegos[], int tamj)
{
    int indice=-1;

    for(int i=0;i<tamj;i++)
    {
        if(arrayDeJuegos[i].isEmpty==1)
        indice=i;
    }

    return indice;
}

//
void altaJuegos(eJuegos arrayDeJuegos[], int tamj)
{

    int indice;
    eJuegos nuevoJuego;
    char auxDescripcion[51];
    int auxCodigo;
    int auxIdCategoria;
    int auxImporte;

    indice = buscarLibreJuegos(arrayDeJuegos, tamj);

    system("cls");
    printf("*** Alta Juegos ***\n\n");

    if( indice == -1)
    {
        printf("No hay lugar en el sistema para cargar mas juegos.\n\n");
        system("pause");
    }
    else
    {

            while(!function_getInt2("Ingrese el codigo del juego: \n",auxCodigo))
            {
                printf("Recuerde, el codigo debe tener solo numeros.\n");
            }

            while(!function_getStringLetras("Ingrese la descripcion del juego: \n",auxDescripcion))
            {
                printf("Recuerde, ingresar la descripcion con letras\n");
            }

            while(!function_getInt2("Ingrese el ID de la categoria a la cual pertenece: \n",auxIdCategoria))
            {
                printf("Recuerde, el ID de la categoria es numerico.\n");
            }
            while(!function_getInt2("Ingrese el importe del juego: \n",auxImporte))
            {
                printf("Recuerde, el importe debe numerico.\n");
            }


            fflush(stdin);
            strcpy(nuevoJuego.codigo,auxCodigo);
            strcpy(nuevoJuego.descripcion,auxDescripcion);
            strcpy(nuevoJuego.idCategoria,auxIdCategoria);
            strcpy(nuevoJuego.importe,auxImporte);
            nuevoJuego.isEmpty=0;
            arrayDeJuegos[indice]=nuevoJuego;
            printf("Juego cargado con exito!!\n");
            system("pause");

    }

}
//
int buscarJuego(eJuegos arrayDeJuegos[], int tamj, int codigo)//devuelvo el indice del cliente.
{
    int indice = -1;

    for(int i=0; i < tamj; i++)
    {

        if( arrayDeJuegos[i].codigo == codigo && arrayDeJuegos[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;

}
//

void mostrarJuego (eJuegos juegoAmostrar)
{
    printf("el id del juego es: %d , la descripcion es: %s , el importe: %d , categoria: %d  \n",juegoAmostrar.codigo,juegoAmostrar.descripcion,juegoAmostrar.idCategoria,juegoAmostrar.importe);
}

//
void bajaJuegos(eJuegos arrayDeJuegos[], int tamj)
{

int id;
char auxCodigoDeJuego[20];
int indice;
char seguir;

   while(!function_getStringNumeros("Ingrese el codigo del juego a eliminar: ",auxCodigoDeJuego))
    {
        printf("Error ingrese un ID numerico\n.");
        break;
    }

    id=atoi(auxCodigoDeJuego);

    indice = buscarJuego(arrayDeJuegos,tamj,id);

    if(indice==-1)
    {
        printf("No existe ese juego en nuestro sistema!\n");
        system("pause");
    }
    else
    {
        mostrarJuego(arrayDeJuegos[indice]);
        seguir=function_getChar("Esta seguro de borrar ese juego? s/n: \n");

        if(seguir=='s')
        {
            arrayDeJuegos[indice].isEmpty=1;
            printf("Borrado Exitoso!!!\n");
        }
        else
        {
            printf("Baja cancelada, recuerde ingresar 's' para borrar el juego! \n");
        }
        system("pause");
    }
}
//

void modificaJuego(eJuegos listado[], int tam)
{

int id;
char auxId[10];
int indice;
char seguir;
int opcion;
char auxOpcion[10];
//variables para empleado.
//cod desc imp categ
char auxDescripcion[50];
int auxImporte;
int auxCategoria;

 while(!function_getStringNumeros("Ingrese el ID del juego a modificar: ",auxId))
    {
        printf("Error ingrese un ID numerico\n.");
        break;
    }

    id=atoi(auxId);

    indice = buscarJuego(listado,tam,id);
    if(indice==-1)
    {
        printf("No existe ese juego en nuestro sistema!\n");
        system("pause");
    }
    else
    {
        mostrarJuego(listado[indice]);
        seguir=function_getChar("Esta seguro que desea modificar ese juego? s/n: \n");
        fflush(stdin);
        if(seguir=='s')
        {
            while(!function_getStringNumeros("\nIngrese opcion a modificar:\n 1.Descripcion \n 2.Importe\n 3.Categoria\n",auxOpcion))//valido legajo siempre.
            {
                {
                printf("Error ingrese una opcion numerica del 1 al 3\n.");
                system("pause");
                fflush(stdin);
                }
            }

            opcion=atoi(auxOpcion);

            if(opcion<1 || opcion>3)
            {
            printf("Error ingrese una opcion numerica del 1 al 3\n.");
            fflush(stdin);
            }

            switch(opcion)
            {

            case 1:
            while(!function_getStringLetras("Ingrese la nueva descripcion del juego: \n",auxDescripcion))
            {
                printf("Recuerde, la descripcion solo debe tener letras.\n");
            }

            strcpy(listado[indice].descripcion,auxDescripcion);

            printf("descripcion modificada con exito!!\n");
            break;

            case 2:
            while(!function_getInt2("Ingrese el nuevo importe del juego: \n",auxImporte))
            {
                printf("Recuerde, el importe debe ser numerico.\n");
            }

            strcpy(listado[indice].importe,auxImporte);
            printf("importe modificado con exito!!\n");

            break;

            case 3:
            while(!function_getInt2("Ingrese la nueva categoria: \n",auxCategoria))
            {
                printf("Error la categoria debe ser numerica.\n");
            }
            strcpy(listado[indice].idCategoria,auxCategoria);
            printf("categoria modificada con exito!!\n");
            break;


        }


    }
        else
        {
             printf("Modificacion cancelada, recuerde ingresar 's' para continuar con la modificacion!!! \n");
        }
      system("pause");
    }
}
