#include "juegos.h"

#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED


typedef struct
{
int codigoCliente;
char nombre[51];
char sexo[20];
char tel[30];
int isEmpty;

}eClientes;



//

void inicializarClientes(eClientes lista[], int tam);

void cargarCategorias(eCategoria categorias[], int tamc);

void listarCategorias(eCategoria categorias[], int tam);

int buscarLibre(eClientes lista[], int tam);

int buscarCliente(eClientes lista[], int tam, int codigo);

void altaCliente(eClientes lista[], int tam,int* pId);

void bajaCliente(eClientes listado[], int tam);

void mostrarCliente (eClientes clienteAmostrar);

void mostrarClientes (eClientes listado[], int tam);

void modificaCliente(eClientes listado[], int tam);

void hardCordearClientes(eClientes arraydeclientes[], int tamclientes);

void ordenarClientesPorSexoYnombre(eClientes arraydeclientes[], int tamc);

#endif // CLIENTES_H_INCLUDED
