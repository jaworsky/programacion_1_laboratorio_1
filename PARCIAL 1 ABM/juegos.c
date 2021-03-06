#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "clientes.h"
#include "juegos.h"
#include "alquileres.h"
#include "informes.h"


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
        {1, "juego de accion", 50 ,4,1,0},
        {2, "juego de magia", 100,5,2,0 },
        {3, "juego de estrategia en tiempo real", 125,3,3,0},
        {4, "juego de sumas y restas", 150,1,4,0},
        {5, "juego de suerte", 10,2,5,0},
        {6, "juego para multiplicar" , 25,1,1,0},
        {7, "juego de pelea", 75,4,2,0},
        {8, "juego de baile", 150,4,3,0},
        {9, "juego de ingenio", 200,1,4,0},
        {10, "juegos de resolver problemas", 250,1,5,0}
    };

    for(int i=0; i < 10; i++)
    {
        juegos[i] = juegosstock[i];
    }
}
//
void listarJuegos(eJuegos arraydejuegos[], int tamj,eMarca arrayDeMarcas[], int tamm)
{

    printf("Descripcion\n\n");
    for(int i=0; i< tamj; i++)
    {
        if(arraydejuegos[i].isEmpty==0)
        {
          // printf("codigo: %d descpripcion: %10s \n ID Categoria: %d importe: %d marca: %d \n\n", arraydejuegos[i].codigo, arraydejuegos[i].descripcion,arraydejuegos[i].idCategoria,arraydejuegos[i].importe,arraydejuegos[i].marca);
            mostrarJuegosDeUnaMarca(arraydejuegos[i],tamj,arrayDeMarcas,tamm);


        }
    }
    printf("\n\n");
    system("pause");
}
//
    void mostrarJuegosDeUnaMarca(eJuegos juegoAmostrar,int tamj,eMarca arrayDeMarcas[],int tamm)
    {

    char marcaAux[20];
    obtenerMarca(arrayDeMarcas,tamm,juegoAmostrar.marca,marcaAux);
    printf("codigo: %d descpripcion: %10s \n ID Categoria: %d importe: %d marca: %s\n",juegoAmostrar.codigo,juegoAmostrar.descripcion,juegoAmostrar.idCategoria,juegoAmostrar.importe,marcaAux);

    }
//

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
    int auxMarca;

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

            auxCodigo=function_getInt("Ingrese el codigo del juego: \n");

            while(!function_getStringLetras("Ingrese la descripcion del juego: \n",auxDescripcion))
            {
                printf("Recuerde, ingresar la descripcion con letras\n");
            }

            auxIdCategoria=function_getInt("Ingrese el ID de la categoria a la cual pertenece: \n");

            /*
            while(!function_getInt2("Ingrese el ID de la categoria a la cual pertenece: \n",auxIdCategoria))
            {
                printf("Recuerde, el ID de la categoria es numerico.\n");
            }

            while(!function_getInt2("Ingrese el importe del juego: \n",auxImporte))
            {
                printf("Recuerde, el importe debe numerico.\n");
            }
            */
            auxImporte=function_getInt("Ingrese el importe del juego: ");
            auxMarca=function_getInt("Ingrese la marca del juego: ");

            fflush(stdin);
            nuevoJuego.codigo=auxCodigo;
            strcpy(nuevoJuego.descripcion,auxDescripcion);
            nuevoJuego.idCategoria=auxIdCategoria;
            nuevoJuego.importe=auxImporte;
            nuevoJuego.marca=auxMarca;
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
void juegosCategoriaMesa(eJuegos arrayDeJuegos[],int tamj)
{
    for(int i=0; i<tamj; i++)
    {
        if(arrayDeJuegos[i].idCategoria==1)
        {
            mostrarJuegoDeCatMesa(arrayDeJuegos[i]);
        }

    }

}
//
void juegosDeUnaDeterminadaMarca(eJuegos arrayDeJuegos[],int tamj,eMarca arrayDeMarcas[],int tamm)
{
    int auxMarca;
    printf("Ingrese la marca :\n 1.Ditoys\n 2.Vulcanita \n 3.Yetem\n 4.Ruibal\n 5.TopToys\n ");
    scanf("%d",&auxMarca);
    //printf("%d",auxMarca);
    //system("pause");
    for(int i=0; i<tamj; i++)
    {
        if(arrayDeJuegos[i].marca==auxMarca && arrayDeJuegos[i].isEmpty==0)
        {
            mostrarJuegosDeUnaMarca(arrayDeJuegos[i],tamj,arrayDeMarcas,tamm);
        }

    }

    system("pause");
}
//
void mostrarJuego (eJuegos juegoAmostrar)
{
    printf("el id del juego es: %d , la descripcion es: %s , el importe: %d , categoria: %d y la marca es: %s \n",juegoAmostrar.codigo,juegoAmostrar.descripcion,juegoAmostrar.importe,juegoAmostrar.idCategoria);
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

            auxImporte=function_getInt("Ingrese el nuevo importe: \n");

            listado[indice].importe=auxImporte;
            printf("importe modificado con exito!!\n");

            break;

            case 3:

            auxCategoria=function_getInt("Ingrese la nueva categoria: \n");

            listado[indice].idCategoria=auxCategoria;
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
//
    void obtenerMarca(eMarca marcas[],int tamm, int codigoAbuscar, char* cadena)
    {
        for(int i=0; i < tamm; i++)
        {
            if( marcas[i].idMarca== codigoAbuscar)
            {
                strcpy(cadena, marcas[i].nombre );
            }
        }
    }
//
    void JuegosPorMarca(eAlquileres arrayDeAlquileres[], int tama,eClientes arrayDeClientes[],int tamc,eJuegos arrayDeJuegos[],int tamj,eMarca arrayDeMarcas[],int tamm)
    {
        int auxCodDeJuego;
        int auxCliente,index;

        listarJuegos(arrayDeJuegos,tamj,arrayDeMarcas,5);
        auxCodDeJuego=function_getInt("Ingrese la marca :\n 1.Ditoys\n 2.Vulcanita \n 3.Yetem\n 4.Ruibal\n 5.TopToys\n \n\n");

        int flag = 0;

        system("cls");
        printf("Clientes que alquilaron los juegos de: %d\n",auxCodDeJuego);
        printf("id   cod de juego:   cod de cliente:   fecha:   \n\n");

        for(int i=0; i < tamj; i++)
        {
            if(arrayDeJuegos[i].marca==auxCodDeJuego && arrayDeJuegos[i].isEmpty==0)
            {
             auxCliente=buscarCliente(arrayDeClientes,tamc,arrayDeAlquileres[i].codigoDeCliente);
            mostrarCliente(arrayDeClientes[auxCliente]);
             //   index=arrayDeAlquileres[i].codigoDeCliente-1;
              //  mostrarCliente(arrayDeClientes[index]);
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
void cuantosAlquileresDeMarca(eAlquileres arrayDeAlquileres[],int tama,eClientes arrayDeClientes[],int tamc,eJuegos arrayDeJuegos[],int tamj, eMarca arrayDeMarcas[],int tamm)
{
        int auxCodDeJuego;
        int auxCliente;

        auxCodDeJuego=function_getInt("Ingrese la marca :\n 1.Ditoys\n 2.Vulcanita \n 3.Yetem\n 4.Ruibal\n 5.TopToys\n \n\n");

        for(int i=0;i<tamj;i++)
        {
            if(arrayDeJuegos[i].marca==auxCodDeJuego && arrayDeJuegos[i].isEmpty==0)
                {
                    for(int j=0;j<tama;j++)
                    {
                        if(arrayDeAlquileres[j].codigoDeJuego==arrayDeJuegos[i].codigo && arrayDeAlquileres[j].isEmpty==0)
                        {
                            mostrarAlquiler(arrayDeAlquileres[j]);
                            system("pause");
                        }


                    }

                }
        }



}
//
void cuantosClientesDeMarca(eAlquileres arrayDeAlquileres[],int tama,eClientes arrayDeClientes[],int tamc,eJuegos arrayDeJuegos[],int tamj, eMarca arrayDeMarcas[],int tamm)
{
        int auxCodDeJuego;
        int auxCliente;
        int index;
        int flag=0;

        auxCodDeJuego=function_getInt("Ingrese la marca :\n 1.Ditoys\n 2.Vulcanita \n 3.Yetem\n 4.Ruibal\n 5.TopToys\n \n\n");

        for(int i=0;i<tamj;i++)
        {

             if(arrayDeJuegos[i].marca==auxCodDeJuego && arrayDeJuegos[i].isEmpty==0)
             {

                 for(int j=0;j<tama;j++)
                 {
                     if(arrayDeAlquileres[j].codigoDeJuego==arrayDeJuegos[i].codigo && arrayDeAlquileres[j].isEmpty==0)
                     {
                         index=buscarCliente(arrayDeClientes,tamc,arrayDeAlquileres[j].codigoDeCliente);
                         mostrarCliente(arrayDeClientes[index]);
                         flag=1;

                     }
                 }
             }


        }

        if(flag==0)
        {
            printf("Nadie alquilo ningun juego de esa marca\n");
            system("pause");
        }
      system("pause");

}
//
void cuantosAlquileresDeMarca2(eAlquileres arrayDeAlquileres[],int tama,eClientes arrayDeClientes[],int tamc,eJuegos arrayDeJuegos[],int tamj, eMarca arrayDeMarcas[],int tamm)
{
        int auxCodDeJuego;
        int auxCliente;
        int index;
        int flag=0;
        char auxName[25];

        auxCodDeJuego=function_getInt("Ingrese la marca :\n 1.Ditoys\n 2.Vulcanita \n 3.Yetem\n 4.Ruibal\n 5.TopToys\n \n\n");

        for(int i=0;i<tamj;i++)
        {

             if(arrayDeJuegos[i].marca==auxCodDeJuego && arrayDeJuegos[i].isEmpty==0)
             {

                 for(int j=0;j<tama;j++)
                 {
                     if(arrayDeAlquileres[j].codigoDeJuego==arrayDeJuegos[i].codigo && arrayDeAlquileres[j].isEmpty==0)
                     {
                         printf("asdad");
                         //index=buscarCliente(arrayDeClientes,tamc,arrayDeAlquileres[j].codigoDeCliente);
                         //mostrarAlquiler2(arrayDeAlquileres[j],arrayDeClientes[index],arrayDeJuegos[i],auxName);
                         flag=1;

                     }
                 }
             }


        }

        if(flag==0)
        {
            printf("Nadie alquilo ningun juego de esa marca\n");
            system("pause");
        }
      system("pause");

}
//
void cuantosClientesDeMarca3(eAlquileres arrayDeAlquileres[],int tama,eClientes arrayDeClientes[],int tamc,eJuegos arrayDeJuegos[],int tamj, eMarca arrayDeMarcas[],int tamm)
{

        int auxCodDeJuego;
        int auxCliente;
        int index;
        int flag=0;
        char auxName[25];
        int contadores[tama];
        int mayor;



        for(int i=0;i<tama;i++)
        {
            contadores[i]=0;
        }

        auxCodDeJuego=function_getInt("Ingrese la marca :\n 1.Ditoys\n 2.Vulcanita \n 3.Yetem\n 4.Ruibal\n 5.TopToys\n \n\n");

         mayor=contadores[0];

        for(int i=0;i<tamj;i++)
        {

             if(arrayDeJuegos[i].marca==auxCodDeJuego && arrayDeJuegos[i].isEmpty==0)
             {

                 for(int j=0;j<tama;j++)
                 {
                     if(arrayDeAlquileres[j].codigoDeJuego==arrayDeJuegos[i].codigo && arrayDeAlquileres[j].isEmpty==0)
                     {

                        contadores[j]++;
                        flag=1;

                         /*
                        obtenerNombreCliente(arrayDeClientes,tamc,arrayDeAlquileres[j].codigoDeCliente,auxName);
                        index=buscarCliente(arrayDeClientes,tamc,arrayDeAlquileres[j].codigoDeCliente);
                        mostrarAlquiler2(arrayDeAlquileres[j],arrayDeClientes[index],arrayDeJuegos[i],auxName);

                        */
                     }
                 }
             }


        }



        for(int i=1;i<tama;i++)
        {
            if(contadores[i]>mayor)
            {
                mayor=contadores[i];
            }

        }

        printf("La cantidad de alquileres de la marca es de: %d \n\n",mayor);

        if(flag==0)
        {
            printf("Nadie alquilo ningun juego de esa marca\n");
            system("pause");
        }
      system("pause");

}
//
    void obtenerDescripcionCategoria(eCategoria arrayDeCategorias[],int tamc, int codigoAbuscar, char* cadena)
    {
        for(int i=0; i < tamc; i++)
        {
            if( arrayDeCategorias[i].id == codigoAbuscar)
            {
                strcpy(cadena, arrayDeCategorias[i].descripcion );
            }
        }
    }
//
void listarJuegos2(eJuegos arraydejuegos[], int tamj,eMarca arrayDeMarcas[], int tamm,eCategoria arrayDeCategorias[],int tamc)
{

    printf("Descripcion\n\n");
    for(int i=0; i< tamj; i++)
    {
        if(arraydejuegos[i].isEmpty==0)
        {
          // printf("codigo: %d descpripcion: %10s \n ID Categoria: %d importe: %d marca: %d \n\n", arraydejuegos[i].codigo, arraydejuegos[i].descripcion,arraydejuegos[i].idCategoria,arraydejuegos[i].importe,arraydejuegos[i].marca);
            mostrarJuegosDeUnaMarca2(arraydejuegos[i],tamj,arrayDeMarcas,tamm,arrayDeCategorias,tamc);


        }
    }
    printf("\n\n");
    system("pause");
}
//
    void mostrarJuegosDeUnaMarca2(eJuegos juegoAmostrar,int tamj,eMarca arrayDeMarcas[],int tamm,eCategoria arrayDeCategorias[],int tamc)
    {
    char categoriaAux[20];
    obtenerDescripcionCategoria(arrayDeCategorias,tamc,juegoAmostrar.idCategoria,categoriaAux);
    char marcaAux[20];
    obtenerMarca(arrayDeMarcas,tamm,juegoAmostrar.marca,marcaAux);
    printf("codigo: %d descpripcion: %10s \n ID Categoria: %s importe: %d marca: %s\n",juegoAmostrar.codigo,juegoAmostrar.descripcion,categoriaAux,juegoAmostrar.importe,marcaAux);

    }
