#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3

void mostrar(char vec[][20], int tam );

void ordenarPromedio(int legajos[], int pp[], int sp[], float promedios[],char nombres [][20], char sexo[], int tam );

int main()
{

int legajos[TAM];
int pp[TAM];
int sp[TAM];
float promedios[TAM];
char nombres [TAM] [20];
char sexo[TAM];

int autoLeg=1200;



for(int i=0;i<TAM;i++)
{
   /* printf("Ingrese el nombre: \n");
    fflush(stdin);
    gets(nombres[i]);
   */

   legajos[i]=autoLeg; // autoincrementamos el legajo.
   autoLeg++;

    printf("Ingrese el legajo: \n");
    fflush(stdin);
    scanf("%d",&legajos[i]);

    printf("Ingrese el sexo: \n");
    fflush(stdin);
    scanf("%c",&sexo[i]);

    printf("Ingrese la nota del primer parcial: \n");
    fflush(stdin);
    scanf("%d",&pp[i]);


    printf("Ingrese la nota del segundo parcial: \n");
    fflush(stdin);
    scanf("%d",&sp[i]);

    promedios[i]=(float) (sp[i]+pp[i])/2;

    system("pause");
    system("cls");

}

for(int i=0;i<TAM;i++)
{
    printf("legajo: %d  nombre: %s  pp: %d   sp: %d promedio: %2.f sexo:%c\n",legajos[i],nombres[i],pp[i],sp[i],promedios[i],sexo[i]);

}

ordenarPromedio(legajos,pp,sp,promedios,nombres,sexo,TAM);

for(int i=0;i<TAM;i++)
{
    printf("legajo: %d  nombre: %s  pp: %d   sp: %d promedio: %2.f sexo:%c\n",legajos[i],nombres[i],pp[i],sp[i],promedios[i],sexo[i]);

}


mostrar(nombres,TAM);

    return 0;
}

void mostrar(char vec[][20], int tam)
{
    for( int i=0;i<tam;i++)
    {
        printf("\n %s",vec[i]);

    }

    printf("\n\n");
}


void ordenarPromedio(int legajos[], int pp[], int sp[], float promedios[],char nombres [][20], char sexo[], int tam )

{
    int j;
    float aux;
    int i;
    int auxint;
    float auxFloat;
    char auxChar;
    char auxCad[20];

//ordenarlo x 2 criterios
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(promedios[i]<promedios[j]) // swap, por los nombres: if(strcmp(nombres[i], nombres[j])<0);
            {
                aux=promedios[i];
                promedios[i]=promedios[j];
                promedios[j]=aux;

                auxint=legajos[i];
                legajos[i]=legajos[j];
                legajos[j]=auxint;

                auxint=sp[i];
                sp[i]=sp[j];
                sp[j]=auxint;

                auxint=pp[i];
                pp[i]=pp[j];
                pp[j]=auxint;

                auxChar = sexo[i];
                sexo[i]=sexo[j];
                sexo[j]=auxChar;

                strcpy(auxCad, nombres[i]); // swap de cadenas de caracteres
                strcpy(nombres[i], nombres[j]);
                strcpy(nombres[j], auxCad);

            }
        }

    }
}



void ordenarporcriterios

{
    int j;
    float aux;
    int i;
    int auxint;
    float auxFloat;
    char auxChar;
    char auxCad[20];

//ordenarlo x 2 criterios / probar con prueba de escritorio.
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(sexo[i]<sexo[j]) // swap, por los nombres: if(strcmp(nombres[i], nombres[j])<0);
            {
                aux=promedios[i];
                promedios[i]=promedios[j];
                promedios[j]=aux;

                auxint=legajos[i];
                legajos[i]=legajos[j];
                legajos[j]=auxint;

                auxint=sp[i];
                sp[i]=sp[j];
                sp[j]=auxint;

                auxint=pp[i];
                pp[i]=pp[j];
                pp[j]=auxint;

                auxChar = sexo[i];
                sexo[i]=sexo[j];
                sexo[j]=auxChar;

                strcpy(auxCad, nombres[i]); // swap de cadenas de caracteres
                strcpy(nombres[i], nombres[j]);
                strcpy(nombres[j], auxCad);

            }
            else if(sexo[i]== sexo[j] && strcmp(nombres[i],nombres[j])>0 )
            {
                aux=promedios[i];
                promedios[i]=promedios[j];
                promedios[j]=aux;

                auxint=legajos[i];
                legajos[i]=legajos[j];
                legajos[j]=auxint;

                auxint=sp[i];
                sp[i]=sp[j];
                sp[j]=auxint;

                auxint=pp[i];
                pp[i]=pp[j];
                pp[j]=auxint;

                auxChar = sexo[i];
                sexo[i]=sexo[j];
                sexo[j]=auxChar;

                strcpy(auxCad, nombres[i]); // swap de cadenas de caracteres
                strcpy(nombres[i], nombres[j]);
                strcpy(nombres[j], auxCad);

            }

        }

    }
}

