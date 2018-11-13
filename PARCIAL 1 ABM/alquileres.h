#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED
#include "validaciones.h"
#include "clientes.h"
#include "alquileres.h"
#include "juegos.h"

typedef struct
{
int dia;
int mes;
int anio;
}eFecha;

typedef struct
{
int codigoDeAlquiler;
int codigoDeJuego;
int codigoDeCliente;
eFecha fecha;
int isEmpty;

}eAlquileres;

void bajaAlquiler(eAlquileres listado[], int tam);

void inicializarAlquileres(eAlquileres lista[], int tam);

int buscarLibreAlquileres(eAlquileres arraydealquileres[], int tama);

void mostrarAlquileres(eAlquileres arraydealquileres[], int tama);

void mostrarAlquiler (eAlquileres alquilerAmostrar);

void altaAlquiler(eAlquileres arraydealquileres[],int tama ,eClientes arraydeclientes[], int tamc,eJuegos arraydejuegos[],int tamj,eCategoria arraydecategorias[],int tamcat, int* pId,eMarca marcas[], int tamm);

#endif // ALQUILERES_H_INCLUDED
