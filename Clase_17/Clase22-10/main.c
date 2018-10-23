#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo;
    char marca[20];
    int capacidad;
    float precio;
}ePendrive;

int cargarPendrive(ePendrive* pen); // si esta ok devuelve 1, sino 0.
void mostrarPendrive(ePendrive* pen);
ePendrive* new_Pendrive();


int main()
{

ePendrive* pen1, *pen2;

pen1=new_Pendrive();



ePendrive* pen1 = new_Pendrive();

if(cargarPendrive(&pen1))
{
    mostrarPendrive(&pen1);
}

    return 0;
}

int cargarPendrive(ePendrive *pen)
{
    int todoOk=0;

    if(pen!=NULL)
    {

    printf("Ingrese el codigo del pendrive: \n");
    scanf("%d",&pen->codigo);

    printf("Ingrese la marca del pendrive: \n");
    fflush(stdin);
    gets(pen->marca);

    printf("Ingrese la capacidad del pendrive: \n");
    scanf("%d",&pen->capacidad);

    printf("Ingrese el precio: \n");
    scanf("%f",&pen->precio);

    todoOk=1;

    }

}

void mostrarPendrive(ePendrive *penAmostrar)
{
    printf("el codigo del pendrive es: %d\n",penAmostrar->codigo);
    printf("la marca es: %s \n",penAmostrar->marca);
    printf("la capacidad del pendrive es de: %d\n",penAmostrar->capacidad);
    printf("el precio es de: $ %2.f\n",penAmostrar->precio);

}

ePendrive* new_Pendrive()
{
    ePendrive* p;

    p=(ePendrive*) malloc(sizeof(ePendrive));

    if(p!=NULL)
    {
        p->codigo=0;
        strcpy(p->marca,"");
        p->capacidad=0;
        p->precio=0;
    }

    return p;
}
