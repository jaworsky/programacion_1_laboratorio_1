#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
    float sueldo;

} ePersona;

int cargarLista(LinkedList* lista , ePersona personasHarcodeadas[]);
void mostrarPersona(ePersona* p);
int mostrarPersonas(LinkedList* lista);
int filtrarHombres(void* p);

int main()
{

    LinkedList* lista;

    lista = ll_newLinkedList();

    LinkedList* listaHombres;

    ePersona personasHarcodeadas[] = {{100, "Juan", 'm', 20000},{101,"Ana",'f', 23000},{103, "Lucia", 'f', 32000},{102, "Miguel", 'm', 27000}};

    if(lista == NULL)
    {
        exit(1);
    }

    cargarLista(lista, personasHarcodeadas);

    mostrarPersonas(lista);

    listaHombres = ll_filter(lista, filtrarHombres);

    mostrarPersonas(listaHombres);

    ll_deleteLinkedList(lista);
    ll_deleteLinkedList(listaHombres);

    return 0;
}

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*)){

    LinkedList* lista;



    return lista;
}




int cargarLista(LinkedList* lista, ePersona personasHarcodeadas[])
{


    return todoOk;
}

void mostrarPersona(ePersona* p)
{
    if(p != NULL)
    {
        printf("%d %10s %c %6.2f\n", p->id, p->nombre, p->sexo, p->sueldo);
    }
}

int mostrarPersonas(LinkedList* lista){

int todoOk = 0;
 if(lista != NULL)
    {
        for(int i = 0; i< ll_len(lista); i++){
            mostrarPersona( ll_get(lista, i));
        }
        printf("\n\n");
        todoOk = 1;
    }

return todoOk;

}

int filtrarHombres(void* p){

    int ok = 0;


    return ok;

}

