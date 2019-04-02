#include <stdio.h>
#include <stdlib.h>

//TAREA
//hacer una funcio que duplique el valor de los vectores.


int main()
{

 int legajos[4];
 int nota1[4];
 int nota2[4];
 float promedios[4];
 char sexos[4];
  int sumaDeNotas=0;

 for (int i=0; i<4; i++)
 {
     printf("Ingrese legajo: ");
     scanf("%d", &legajos[i]);
     printf("Ingrese nota 1: ");
      scanf("%d", &nota1[i]);
     printf("Ingrese nota 2: ");
      scanf("%d", &nota2[i]);
     printf ("Ingrese el sexo: ");
      scanf("%c", &sexos[i]);
      printf("\n");

      promedios[i]= (float) (nota1[i]+nota2[i])/2;
 }

 printf( "\n\n");
 printf("*** Listado de Alumnos ***\n\n");
 printf("*** Legajo  Sexo   Nota 1  Nota 2   Promedio ***\n\n");

 for(int i=0; i<4; i++)
 {
     printf("%d    %c     %d    %d     %f", legajo[i], sexos[i], nota1[i], nota2[i], promedios[i]);

 }


    return 0;
}

