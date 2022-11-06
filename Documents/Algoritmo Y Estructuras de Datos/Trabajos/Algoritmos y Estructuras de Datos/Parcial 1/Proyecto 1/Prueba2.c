#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct REGISTRO;
typedef struct 
{
    unsigned int NumRegistro;
    char Nombre[30];
    char ApellidoPat[30];
    char ApellidoMat[30];
    char CorreoElec[30];
    //char* Nombre;
    //char* ApellidoPat;
    //char* ApellidoMat;
    //char* CorreoElec;
    
    unsigned int NumCelular;
    struct REGISTRO *siguiente;
    struct REGISTRO *anterior;
}REGISTRO;

// Funciones a ocupar:
REGISTRO *NewRegistro(unsigned int _numRegistro,char _nombre[], char _apellidoPat[],char _apellidoMat[],char _correo[],unsigned int _numCelular);
void InsertarRegistro(REGISTRO *registro, unsigned int _numRegistro,char _nombre[], char _apellidoPat[],char _apellidoMat[],char _correo[],unsigned int _numCelular);
void imprimirRegistro_adelante(REGISTRO *registro);

int main()
{
    REGISTRO registro1;

   char Nombre[]="Nombre";
   char ApellidoPat[]="paterno";
   char ApellidoMat[]="materno";
   char Correo[]="correo e";
   

    registro1.siguiente = NULL;
    registro1.anterior = NULL;

    printf("\nRegistros: ");
    imprimirRegistro_adelante(&registro1);
    printf("\n");

    printf("\nInsertando datos: ");
    InsertarRegistro(&registro1,2,"Telo Candela","Castillo","Andrade","megustanlastortugas@gmail.com", 456123456);
   // InsertarRegistro(&registro1,2,Nombre,ApellidoMat,ApellidoPat,Correo, 456123456);
    printf("\nTenemos que:");
    imprimirRegistro_adelante(&registro1);

    return 0;
}
REGISTRO *NewRegistro(unsigned int _numRegistro,char _nombre[], char _apellidoPat[],char _apellidoMat[],char _correo[],unsigned int _numCelular)
{  
    REGISTRO *ptr;
    ptr = (REGISTRO *)malloc(sizeof(REGISTRO));
    if(ptr == NULL)
    {
        printf("\nError al reservar la memoria para el registro de datos");
        exit(0);
    }
    for(int i = 0; i < 20; i++)
    {
        (ptr->Nombre[i]) = _nombre[i];
        (ptr->ApellidoPat[i]) = _apellidoPat[i];
        (ptr->ApellidoMat[i]) = _apellidoMat[i];
        (ptr->CorreoElec[i]) = _correo[i];
    }
      ptr->NumRegistro = _numRegistro;
      ptr->NumCelular = _numCelular;

    return ptr;
}
void InsertarRegistro(REGISTRO *registro,unsigned int _numRegistro,char _nombre[], char _apellidoPat[],char _apellidoMat[],char _correo[],unsigned int _numCelular)
{
    REGISTRO *new;
    REGISTRO *aux;
    
    new = NewRegistro(_numRegistro, _nombre, _apellidoPat, _apellidoMat, _correo, _numCelular);

    if((registro->siguiente == NULL) && (registro->anterior == NULL))
    {
        // en caso de que la registro este vacia
        registro->siguiente = (struct REGISTRO *)new;
        registro->anterior = (struct REGISTRO *)new;
    }
    else
    {
        // caso 2, donde el registro si tenga al menos un dato
        aux = (REGISTRO *)registro->siguiente;
        while(aux->siguiente != NULL)
        {
            aux = (REGISTRO *)aux->siguiente;
        }
        aux->siguiente = (struct REGISTRO *)new;
        new->anterior = (struct REGISTRO *)aux;

        // cuando se agrega un ultimo registro, se necesita actualizar el registro del final
        registro->anterior = (struct REGISTRO *)new;
    }
}
void imprimirRegistro_adelante(REGISTRO *registro)
{
    REGISTRO *imprime;
    if((registro->siguiente == NULL) && (registro->anterior == NULL))
    {
        printf("\nRegistro vacio.");
    }
    else
    {
        imprime = (REGISTRO *)registro->anterior; // se obtiene la direccion del primer registro.
        do
        {
            printf("\n Num de Registro: %u",imprime->NumRegistro);
            printf("\n Nombre: %s",imprime->Nombre);
            printf("\n Apellido Paterno: %s",imprime->ApellidoPat);
            printf("\n APellido Materno: %s",imprime->ApellidoMat);
            printf("\n Correo: %s",imprime->CorreoElec);
            printf("\n Num de celular: %u",imprime->NumCelular);
            imprime = (REGISTRO *)imprime->siguiente; // aqui almacenamos la direccion de momoria de la siguiente posicion
        }while(imprime != NULL);
    }
}