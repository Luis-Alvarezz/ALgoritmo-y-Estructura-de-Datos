#include <stdio.h>
#include <stdlib.h>

struct REGISTRO;
typedef struct 
{
    unsigned int NumRegistro;
    char *Nombre;
    char *ApellidoPat;
    char *ApellidoMat;
    char *CorreoElec;
    unsigned int NumCelular;
    
    struct REGISTRO *siguiente;
    struct REGISTRO *anterior;
}REGISTRO;

// Funciones a ocupar:
REGISTRO *NewRegistro(unsigned int _numRegistro,char _nombre[], char _apellidoPat[],char _apellidoMat[],char _correo[],unsigned int _numCelular);
void InsertarRegistro_final(REGISTRO *registro, unsigned int _numRegistro,char _nombre[], char _apellidoPat[],char _apellidoMat[],char _correo[],unsigned int _numCelular);
void InsertarRegistro_Inicio(REGISTRO *registro,unsigned int _numRegistro,char _nombre[], char _apellidoPat[],char _apellidoMat[],char _correo[],unsigned int _numCelular);
void imprimirRegistro_adelante(REGISTRO *registro);
void imprimeRegistro_atras(REGISTRO *registro);

void EliminarRegistro_Inicio(REGISTRO *registro);
void EliminarRegistro_Final(REGISTRO *registro);

void Menu(REGISTRO *registro,unsigned int _numRegistro,char _nombre[], char _apellidoPat[],char _apellidoMat[],char _correo[],unsigned int _numCelular);
void SubMenu();
REGISTRO registro1;

int main()
{
    /*REGISTRO registro1;

    registro1.siguiente = NULL;
    registro1.anterior = NULL;
    
    printf("\nRegistros: ");
    imprimirRegistro_adelante(&registro1);
    printf("\n");

    printf("\nInsertando datos: ");
    InsertarRegistro_final(&registro1,1,"Telo MARQUEZ","Castillo","Andrade","megustanlastortugas@gmail.com", 456123456);
    InsertarRegistro_final(&registro1,2,"Messi","CR7 SIUUUU","Andrade","gomezpelon@gmail.com", 477456890);
    InsertarRegistro_final(&registro1,3,"Mi nina hermosa","Silva","Gutierrez","loveall@gmail.com",3231389);
    imprimirRegistro_adelante(&registro1);
    InsertarRegistro_Inicio(&registro1,0,"Chilito Rico","Blalbla","Andrade","megs@gmail.com", 452111226);
    imprimirRegistro_adelante(&registro1);

    EliminarRegistro_Final(&registro1);
    imprimirRegistro_adelante(&registro1);*/
    Menu(&registro1);

    return 0;
}
void Menu(REGISTRO *registro,unsigned int _numRegistro,char _nombre[], char _apellidoPat[],char _apellidoMat[],char _correo[],unsigned int _numCelular)
{
    unsigned int num,NUMregistros = 0;
    printf("\n--Bienvenido Usuario, tome asiento--");
    printf("\nIngrese la cantidad de usuarios a llenar en los registros: ");
    scanf("%u",&NUMregistros);
    printf("¿Que opcion desea tomar?");
    printf("\n1 - Insertar un registro al inicio de la lista");
    printf("\n2 - Insertar un registro al final de la lista");
    printf("\n3 - Insertar un registro en una posición especifica de la lista.");
    printf("\n4 - Eliminar un registro del inicio de la lista.");
    printf("\n5 - Eliminar un registro del final de la lista.");
    printf("\n6 - Eliminar un registro especifico de la lista.");
    printf("\n7 - Listar los registros en pantalla del inicio al fin.");
    printf("\n8 - Listar los registros en pantalla del final al inicio.");
    printf("\nOpcion: ");
    scanf("%u",&num);
    system("cls");

    switch(num)
    {
        case 1:
            printf("opcion tomada: 1");
            REGISTRO registro1;
            registro1.anterior = NULL;
            registro1.siguiente = NULL;
            for(int i = 0; i < NUMregistros; i++)
            {
                printf("\nNum de registro: ");
                scanf("%u",_numRegistro);
                printf("\nNombre: ");
                scanf("%s",_nombre);
                printf("\nApellido Paterno: ");
                scanf("%s",_apellidoPat);
                printf("\nApellido Materno: ");
                scanf("%s",_apellidoMat);
                printf("\nCorreo Electronico: ");
                scanf("%s",_correo);
                printf("\nNum de celular: ");
                scanf("%u",_numCelular);
            }
    }
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
    ptr->NumRegistro = _numRegistro;
    ptr->Nombre = _nombre;
    ptr->ApellidoPat = _apellidoPat;
    ptr->ApellidoMat = _apellidoMat;
    ptr->CorreoElec = _correo;
    ptr->NumCelular = _numCelular;

    return ptr;
}
void InsertarRegistro_final(REGISTRO *registro,unsigned int _numRegistro,char _nombre[], char _apellidoPat[],char _apellidoMat[],char _correo[],unsigned int _numCelular)
{
    REGISTRO *new; // acceso a la estructura para verificar si el registro esta vacio 
    REGISTRO *aux;
    
    new = NewRegistro(_numRegistro, _nombre, _apellidoPat, _apellidoMat, _correo, _numCelular);

    if((registro->siguiente == NULL) && (registro->anterior == NULL))
    {
        // en caso de que el registro este vacio
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
void InsertarRegistro_Inicio(REGISTRO *registro,unsigned int _numRegistro,char _nombre[], char _apellidoPat[],char _apellidoMat[],char _correo[],unsigned int _numCelular)
{
    REGISTRO *NewData; // Acceso a la estructura donde se almacenara un nuevo registro
    REGISTRO *AUX;  // Acceso a la estructura para almacenar el siguiente registro

    NewData = NewRegistro(_numRegistro, _nombre, _apellidoPat, _apellidoMat, _correo, _numCelular);
    if((registro->siguiente == NULL) && (registro->anterior == NULL))
    {
        // en caso de que el registro este vacia    
        registro->siguiente = (struct REGISTRO *)NewData;
        registro->anterior = (struct REGISTRO *)NewData;
    }
    else
    {
        AUX = (REGISTRO *)registro->siguiente;
        AUX->anterior = (struct REGISTRO*)NewData;
        NewData->siguiente =  (struct REGISTRO*)AUX;
        registro->siguiente = (struct REGISTRO*)NewData;
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
        imprime = (REGISTRO *)registro->siguiente; // se obtiene la direccion del primer registro.
        do
        {
            printf("\n Num de Registro: %u",imprime->NumRegistro);
            printf("\n Nombre: %s",imprime->Nombre);
            printf("\n Apellido Paterno: %s",imprime->ApellidoPat);
            printf("\n APellido Materno: %s",imprime->ApellidoMat);
            printf("\n Correo: %s",imprime->CorreoElec);
            printf("\n Num de celular: %u",imprime->NumCelular);
            printf("\n");
            imprime = (REGISTRO *)imprime->siguiente; // aqui almacenamos la direccion de momoria de la siguiente posicion
        }while(imprime != NULL);
    }
}
void imprimeRegistro_atras(REGISTRO *registro)
{
    REGISTRO *aux;
    if((registro->siguiente == NULL) && (registro->anterior == NULL))
    {
        printf("\nRegistro vacio.");
    }
    else
    {
        aux = (REGISTRO *)registro->anterior; // se obtiene la direccion del primer registro.
        do
        {
            printf("\n Num de Registro: %u",aux->NumRegistro);
            printf("\n Nombre: %s",aux->Nombre);
            printf("\n Apellido Paterno: %s",aux->ApellidoPat);
            printf("\n APellido Materno: %s",aux->ApellidoMat);
            printf("\n Correo: %s",aux->CorreoElec);
            printf("\n Num de celular: %u",aux->NumCelular);
            printf("\n");
            aux = (REGISTRO *)aux->anterior; // aqui almacenamos la direccion de momoria de la siguiente posicion
        }while(aux != NULL);
    }
}


void EliminarRegistro_Inicio(REGISTRO *registro)
{
    REGISTRO *aux;
    
    if(registro->siguiente == NULL)
    {
        printf("\nNo se puede eliminar un dato, por que el registro esta vacio");
    }
    else
    {
        aux = (REGISTRO*)registro->siguiente;
        aux = (REGISTRO*)aux->siguiente;
        aux->anterior = NULL;
        registro->siguiente = (struct REGISTRO*)aux;
    }
}
void EliminarRegistro_Final(REGISTRO *registro)
{
    REGISTRO *aux;

    if(registro->siguiente == NULL)
    {
        printf("\nNo se puede eliminar un dato, por que el registro esta vacio");
    }
    else
    {
        aux = (REGISTRO*)registro->anterior; // tomamos a la ultima persona
        aux = (REGISTRO*)aux->anterior; // Tomamos a la persona "anterior" de la ultima persona.
        aux->siguiente = NULL; // Borramos el ultimo dato
        registro->anterior = (struct REGISTRO*)aux;
    }
}