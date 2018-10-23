#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* vec;
    int* aux;
         vec = (int*)   malloc(sizeof(int)* 5);

         if(vec == NULL){

            printf("No se consiguio memoria\n");
            exit(1);
         }

        for(int i=0; i < 5; i++){
              printf("Ingrese un numero: ");
              scanf("%d", vec + i);

        }


           for(int i=0; i < 5; i++){
              printf("%d ", *(vec + i));


        }

       printf("\n\n");


      aux =  (int*) realloc( vec, sizeof(int)*10);

      if( aux != NULL){
        vec = aux;

         for(int i=5; i < 10; i++){
         printf("Ingrese un numero: ");
        scanf("%d", vec + i);

      }


      for(int i=0; i < 10; i++){
              printf("%d ", *(vec + i));


        }

      vec = (int*) realloc(vec, sizeof(int)* 5);

  printf("\n\n");

       for(int i=0; i < 10; i++){
              printf("%d ", *(vec + i));


        }

  printf("\n\n");


      }
      else{
      printf("No se pudo agrandar el array\n");

      }



         free(vec);



    return 0;
}


/*
#include <stdio.h>
#include <stdlib.h>

int main()
{

int* pNumero;
int* vec;
int* aux; // creo la auxiliar para no tapar el valor original.
vec = (int*) malloc(sizeof(int)*5);

if(vec==NULL)
{

    printf("No se consiguio memoria disponible \n");
    exit(1);

}
else

{
for(int i=0; i<5;i++)
    {
        printf("Ingrese un numero: \n");
        scanf("%d",vec+i);
    }
for(int i=0;i<5;i++)
    {
        printf("%d ",*(vec+i));

    }

}

printf("\n\n");

    aux=(int*) realloc(vec,sizeof(int)*10);//reacomoda en memoria dinamica, el valor que le pedimos.


    if(aux!=NULL)
    {
        vec=aux;
    }


for(int i=5; i<10;i++)
    {
        printf("Ingrese un numero: \n");
        scanf("%d",vec+i);
    }
for(int i=0;i<10;i++)
    {
        printf("%d ",*(vec+i));

    }

}


    free(vec); // se utiliza para liberar la memoria utilizada


    return 0;
}
*/
