#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char id[20];
    char nombre[20];
    char apellido[20];
    char edad[20];
}ePersona;

int main()
{

int cant;

FILE* f;

ePersona listaDePersonas[4][20];

f= fopen("personas.csv","r");

if(f==NULL)
{
    exit(1);
}

while(!feof(f))
{
    cant = fscanf(f,"%[^,]%[^,],%[^,],%[^\n]\n",listaDePersonas.id,listaDePersonas.nombre,listaDePersonas.apellido,listaDePersonas.edad);

    if(cant == 4)
    {
        printf("Los datos leidos son: %s,%s,%s,%s",listaDePersonas.id,listaDePersonas.nombre,listaDePersonas.apellido,listaDePersonas.edad);

    }
    else
        {
        break;
        }
}






    return 0;
}
