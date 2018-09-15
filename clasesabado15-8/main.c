#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LEN 500


/* armar funciones  /  reciba un string y devuelva title

funcion q pida nombre, lo valide ( sin numeros ), y lo guarde en formato tittle.

*/


void funcionnombreenformatotittle(char nombre[]);

int main()
{

char nombre[100];

printf("Ingrese un nombre: \n");

gets(nombre);

fflush(stdin);

funcionnombreenformatotittle(nombre);



    return 0;
}

void funcionnombreenformatotittle(char nombre[])
{

printf("Ingrese un nombre: \n");

int retorno;
char auxiliar[LEN];
fgets(auxiliar,LEN,stdin); // usar fgets antes q gets.

for (int i=0;i<strlen(auxiliar)-1;i++)
{
auxiliar[i] = tolower(auxiliar[i]); // lo paso a minuscula

    if(auxiliar[i]<'a'||auxiliar[i]>'z' || auxiliar[i] !=' ')
    {


    }

}

printf("%s",auxiliar);

}
