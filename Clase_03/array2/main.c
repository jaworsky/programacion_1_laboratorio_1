#include <stdio.h>
#include <stdlib.h>


contarPares(int* vec, int tam);

int main()
{
    int vec[]={19,23,4,5,222,55,2,1,8888,3};
int contadoraux;

 contadoraux = contarPares(vec,10);
    printf("los numeros pares son %d",contadoraux);


    return 0;
}


contarPares(int* vec, int tam)
{

    int contadordepares=0;

    for(int i=0; i<tam; i++)
    {
        if(vec[i]%2==0)
        {
          contadordepares++;
        }

    }

    return contadordepares;
}
