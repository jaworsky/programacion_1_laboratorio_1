#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

char nombre[20];
char auxcad[50];

printf("ingrese su nombre \n");
gets(auxcad); // guardamos el nombre ingresado en nuestra cadena auxiliar

while(strlen(auxcad) > 19) // validamos el nombre que no sea demasiado largo
{
    printf("error reingrese el nombre (nombre demasiado largo)\n");
    gets(auxcad);
}
strcpy(nombre, auxcad);

printf("usted se llama %s\n\n",nombre);

    return 0;
}
