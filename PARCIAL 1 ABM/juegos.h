#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED


typedef struct
{

int id;
char descripcion[51];

}eCategoria;


typedef struct
{
int codigo;
char descripcion[51];
int importe;
int idCategoria;
int marca;
int isEmpty;

}eJuegos;


typedef struct
{
    int idMarca;
    char nombre[20];
}eMarca;


void hardCordearJuegos(eJuegos juegos[], int tamjuegos);

void listarJuegos(eJuegos arraydejuegos[], int tamj,eMarca arrayDeMarcas[],int tamm);

void inicializarJuegos (eJuegos arrayDeJuegos[], int tamj);

int buscarLibreJuegos(eJuegos arrayDeJuegos[], int tamj);

void altaJuegos(eJuegos arrayDeJuegos[], int tamj);

int buscarJuego(eJuegos arrayDeJuegos[], int tamj, int codigo);

void mostrarJuego (eJuegos juegoAmostrar);

void bajaJuegos(eJuegos arrayDeJuegos[], int tamj);

void modificaJuego(eJuegos listado[], int tam);

void juegosCategoriaMesa(eJuegos arrayDeJuegos[],int tamj);

#endif // JUEGOS_H_INCLUDED


