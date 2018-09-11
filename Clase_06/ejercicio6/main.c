#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{

char nombre[20]={"MariAna INes"};
char apellido[20]={"INSAurralde"};
char nombreCompleto[40]={};

strcpy(nombreCompleto,nombre);
strcat(nombreCompleto," ");
strcat(nombreCompleto,apellido);

//strcat(nombreCompleto,nombre);
//strcat(nombreCompleto,apellido);

strlwr(nombreCompleto);
//pongo en mayuscula la pimer letra.
nombreCompleto[0]=toupper(nombreCompleto[0]);


//cuando encuentra un espacio, sea el q sea, le pone una mayuscula a lo q sigue
int cant=strlen(nombreCompleto);

for(int i=0; i<cant; i++)
{
    if(nombreCompleto[i]==' ')
    {
        nombreCompleto[i+1]=toupper(nombreCompleto[i+1]);
    }


}




//strupr(nombreCompleto);

printf("%s",nombreCompleto);






    return 0;
}
