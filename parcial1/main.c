#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 4


/*
ordenados por sexo y nombre
*/

typedef struct
{
int codigo;
char descripcion[20];
int importe;
int idCategoria;

}eJuego;

typedef struct
{

int id;
char descripcion[51];

}eCategoria;

typedef struct
{

int dia;
int mes;
int anio;

}eFecha;

typedef struct
{
int codigoCliente;
char nombre[51];
char sexo[20];
char telefono[20];
int isEmpty;

}eClientes;

typedef struct
{
int codigoDeAlquiler;
int codigoDeJuego;
int codigoDeCliente;
eFecha fecha;
int isEmpty;

}eAlquileres;
//




int main()
{

int opcion;
int codigoClienteAuto=1;
int codigoAlquierAuto=1;

eJuego listaDeJuegos[TAM];
eClientes listaDeClientes[TAM];
eCategoria listaDeCategorias[5];
eAlquileres listaDeAlquileres[TAM];

inicializarAlquileres(listaDeAlquileres,TAM);
inicializarClientes(listaDeClientes,TAM);

cargarCategorias(listaDeCategorias,5);

 do
        {

        switch(menu())
        {
        case 1:
        altaCliente(listaDeClientes,TAM,&codigoClienteAuto);

        break;

        case 2://modificar
        mostrarClientes(listaDeClientes,TAM);
        system("pause");
        modificaCliente(listaDeClientes,TAM);

        break;

        case 3://Baja
        bajaCliente(listaDeClientes,TAM);


        break;

        case 4://listar
        listarCategorias(listaDeCategorias,5);
        system("pause");

        break;

        case 5:
        opcion=5;
        break;
        }

        }while(opcion!=5);



    return 0;
}



//
int menu()
{
        char auxOpcion[10];
        int opcion;

        system("cls");
        printf("\n*** Bienvenido!!***\n");
        printf("\n*** Menu de opciones ***\n\n\n");
        printf("1-Alta Cliente\n");
        printf("2-Modificar Datos\n");
        printf("3-Baja de Cliente\n");
        printf("4-Listar\n"); // en este caso, informar los 2 puntos
        printf("5-Salir\n");

        while(!function_getStringNumeros("Ingrese la opcion deseada: \n",auxOpcion))
        {

            {
            printf("Error ingrese una opcion numerica del 1 al 5\n.");
            system("pause");
            fflush(stdin);
            }
        }
            opcion=atoi(auxOpcion);

            if(opcion<1 || opcion>5)
            {
            printf("Error ingrese una opcion numerica del 1 al 5\n.");
            system("pause");
            fflush(stdin);
            }
    return opcion;
}
//

//Validaciones:
int function_esTelefono(char str[])
{
    int i=0;
    int contadorGuiones=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
            return 0;
        if(str[i] == '-')
            contadorGuiones++;
        i++;
    }
    if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}
//

float getFloat(char msj[])
{
    float aux;
    printf("%s",msj);
    scanf("%f",&aux);
    return aux;
}
//

int function_getInt(char msj[] )
{
    int resultado;
    printf("%s",msj);
    scanf("%d",&resultado);
    return resultado;
}
//
char function_getChar(char msj[])
{
    char aux;
    printf("%s",msj);
    fflush(stdin);
    scanf("%c",&aux);
    return aux;
}
//
int function_esNum(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] < '0' || str[i] > '9')&&(str[i]!='.')&&(str[i]!=',')&&(str[i]!=NULL)&&(str[i]!=' '))
           return 0;
       i++;
   }
   return 1;
}
//
int function_esSoloLetras(char str[])
{
    int i=0;
    int retorno = 1;
    if(str[i] == '\0')
        retorno = 0;
    else{
        while(str[i] != '\0')
        {
            if(  (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')){
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}
//
void function_getString (char msj[],char input[])
{
    printf("%s",msj);
    fflush(stdin) ;
    gets(input) ;
}
//
int function_getStringLetras(char msj[],char input[])
{
    char aux[256];
    function_getString(msj,aux);
    if(function_esSoloLetras(aux)&&(strlen(aux)<51))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0 ;
}
//
int function_getStringNumeros(char msj[],char input[])
{
    char aux[256];
    function_getString(msj,aux);
    if(function_esNum(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
//
void inicializarClientes(eClientes lista[], int tam)
{

    for(int i=0; i < tam; i++)
    {

        lista[i].isEmpty = 1;
    }
}
//
void inicializarAlquileres(eAlquileres lista[], int tam)
{

    for(int i=0; i < tam; i++)
    {

        lista[i].isEmpty = 1;
    }
}
//
void cargarCategorias(eCategoria categorias[])
{
    eCategoria sec[]=
    {
        {1, "Mesa"},
        {2, "Azar"},
        {3, "Estrategia"},
        {4, "salon"},
        {5, "magia"}
    };

    for(int i=0; i < 5; i++)
    {
        categorias[i] = sec[i];
    }
}
//
void listarCategorias(eCategoria categorias[], int tam)
{

    printf("Descripcion\n\n");
    for(int i=0; i< tam; i++)
    {
        printf("%d   %10s\n", categorias[i].id, categorias[i].descripcion);

    }
    printf("\n\n");
}
//
int buscarLibre(eClientes lista[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( lista[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
//
int buscarCliente(eClientes lista[], int tam, int codigo)//devuelvo el indice del cliente.
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( lista[i].codigoCliente == codigo && lista[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;

}
// case 1
void altaCliente(eClientes lista[], int tam,int* pId)
{
    int idCliente= *pId;
    int indice;
    eClientes nuevoCliente;
    char auxName[51];
    char auxChar[10];
    char auxTel[51];

    indice = buscarLibre(lista, tam);

    system("cls");
    printf("*** Alta cliente ***\n\n");

    if( indice == -1)
    {
        printf("No hay lugar en el sistema para cargar mas clientes.\n\n");
        system("pause");
    }
    else
    {

            while(!function_getStringLetras("Ingrese el nombre del cliente: \n",auxName))
            {
                printf("Recuerde, el nombre solo debe tener letras.\n");
            }

            while(!function_getStringLetras("Ingrese el sexo del cliente: \n",auxChar))
            {
                printf("Recuerde, ingresar el sexo como m o f\n");
            }

            while(!function_getStringNumeros("Ingrese el telefono del cliente: \n",auxTel))
            {
                printf("Recuerde ingresar el telefono con numeros\n");
            }

            strcpy(nuevoCliente.nombre,auxName);
            strcpy(nuevoCliente.sexo,auxChar);
            strcpy(nuevoCliente.telefono,auxTel);
            nuevoCliente.codigoCliente=idCliente;

            nuevoCliente.isEmpty=0;
            lista[indice]=nuevoCliente;
            *pId = idCliente + 1;
            printf("Empleado cargado con exito!!\n");
            system("pause");

    }

}
//

void bajaCliente(eClientes listado[], int tam)
{

int id;
char auxId[10];
int indice;
char seguir;

   while(!function_getStringNumeros("Ingrese el ID: ",auxId))
    {
        printf("Error ingrese un ID numerico\n.");
        break;
    }

    id=atoi(auxId);

    indice = buscarCliente(listado,tam,id);

    if(indice==-1)
    {
        printf("No existe ese empleado en nuestro sistema!\n");
        system("pause");
    }
    else
    {
        mostrarCliente(listado[indice]);
        seguir=function_getChar("Esta seguro de borrar este empleado? s/n: \n");

        if(seguir=='s')
        {
            listado[indice].isEmpty=1;
            printf("Borrado Exitoso!!!\n");
        }
        else
        {
            printf("Baja cancelada, recuerde ingresar 's' para borrar el empleado! \n");
        }
        system("pause");
    }
}



//

void mostrarCliente (eClientes clienteAmostrar)
{
    printf("el cliente es: %d , nombre: %s , sexo: %s, telefono: %c  \n",clienteAmostrar.codigoCliente,clienteAmostrar.nombre,clienteAmostrar.sexo,clienteAmostrar.telefono);
}
//
void mostrarClientes (eClientes listado[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
   {
       if(listado[i].isEmpty==0)
        {
         mostrarCliente(listado[i]);
        }
   }
}

//
void altaAlquiler(eClientes lista[], int tam,int* pId)
{
    int idAlquiler=*pId;
    int indice;
    eAlquileres nuevoAlquiler;
    char auxName[51];
    char auxChar[10];
    char auxTel[51];


    indice = buscarLibre(lista, tam);

    system("cls");
    printf("*** Alta Alquiler ***\n\n");

    if( indice == -1)
    {
        printf("No hay lugar en el sistema para cargar mas clientes.\n\n");
        system("pause");
    }
    else
    {

            while(!function_getStringLetras("Ingrese el nombre del cliente: \n",auxName))
            {
                printf("Recuerde, el nombre solo debe tener letras.\n");
            }

            while(!function_getStringLetras("Ingrese el sexo del cliente: \n",auxChar))
            {
                printf("Recuerde, ingresar el sexo como m o f\n");
            }

            while(!function_getStringNumeros("Ingrese el telefono del cliente: \n",auxTel))
            {
                printf("Recuerde ingresar el telefono con numeros\n");
            }

            strcpy(nuevoCliente.nombre,auxName);
            strcpy(nuevoCliente.sexo,auxChar);
            strcpy(nuevoCliente.telefono,auxTel);

            lista[indice]=nuevoCliente;

            *pId = *pId+1;

    }

}
//modificar

void modificaCliente(eClientes listado[], int tam)
{

int id;
char auxId[10];
int indice;
char seguir;
int opcion;
char auxOpcion[10];
//variables para empleado.
char auxName[21];
char auxSexo[21];
char auxTel[10] ;

 while(!function_getStringNumeros("Ingrese el ID: ",auxId))
    {
        printf("Error ingrese un ID numerico\n.");
        break;
    }

    id=atoi(auxId);

    indice = buscarCliente(listado,tam,id);
    if(indice==-1)
    {
        printf("No existe ese cliente en nuestro sistema!\n");
        system("pause");
    }
    else
    {
        mostrarCliente(listado[indice]);
        seguir=function_getChar("Esta seguro que desea modificar este cliente? s/n: \n");
        fflush(stdin);
        if(seguir=='s')
        {
            while(!function_getStringNumeros("\nIngrese opcion a modificar:\n 1.Nombre \n 2.Sexo\n 3.Telefono\n",auxOpcion))//valido legajo siempre.
            {
                {
                printf("Error ingrese una opcion numerica del 1 al 3\n.");
                system("pause");
                fflush(stdin);
                }
            }

            opcion=atoi(auxOpcion);

            if(opcion<1 || opcion>3)
            {
            printf("Error ingrese una opcion numerica del 1 al 3\n.");
            fflush(stdin);
            }

            switch(opcion)
            {

            case 1:
            while(!function_getStringLetras("Ingrese el nuevo nombre del empleado: \n",auxName))
            {
                printf("Recuerde, el nombre solo debe tener letras.\n");
            }

            strcpy(listado[indice].nombre,auxName);

            printf("Nombre modificado con exito!!\n");
            break;

            case 2:
            while(!function_getStringLetras("Ingrese el nuevo sexo del cliente: \n",auxSexo))
            {
                printf("Recuerde, el sexo solo debe tener letras.\n");
            }

            strcpy(listado[indice].sexo,auxSexo);
            printf("sexo modificado con exito!!\n");

            break;

            case 3:
            while(!function_getStringNumeros("Ingrese el nuevo telefono del empleado: \n",auxTel))
            {
                printf("Error el telefono debe ser numerico.\n");
            }
            strcpy(listado[indice].telefono,auxTel);
            printf("telefono modificado con exito!!\n");
            break;


        }


    }
        else
        {
             printf("Modificacion cancelada, recuerde ingresar 's' para continuar con la modificacion!!! \n");
        }
      system("pause");
    }
}
// listado de alquileres:
void orderPorApellidoYnombre(eClientes x[],int tam)
{
    char auxApellidoI[20]; // auxiliares para descripcion del sector.
    char auxApellidoJ[20];
    eClientes auxCliente;

    for(int i=0; i<tam -1; i++)
    {
        for(int j = i +1; j < tam; j++)
        {
            if( strcmp(descripcionI, descripcionJ) > 0)
            {
                auxEmpleado = x[i];
                x[i] = x[j];
                x[j] = auxEmpleado;
            }
            else if( strcmp(descripcionI, descripcionJ) == 0 && strcmp(x[i].nombre, x[j].nombre) > 0)
            {
                auxEmpleado = x[i];
                x[i] = x[j];
                x[j] = auxEmpleado;
            }
        }
    }
    printf("\nEmpleados ordenados con exito!!!\n\n");

}


