/*  
    Lunes 3 de Octubre de 2022.
    
    EJERCICIO:  
    CAlculo del  promedio de un vevtor de datos enteros positivos, usando asignacion dinamica para el arreglo
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    unsigned int Ne;
}VECTOR;

VECTOR *crearVector(unsigned int N); // gestionar la memoria dinamica para los datos del vector.
void capturaVector(VECTOR *ptr);
void imprimeVector(VECTOR *ptr);
void eliminarVector(VECTOR *ptr);
float promedioVector (VECTOR *ptr);

int main()
{
    VECTOR *V; // *v es una variable que almacena datos en el vector
    unsigned int N;
    float prom;
    //Solicitar la cantidad de datos:
    printf("\nNumero de datos a capturar: ");
    scanf("%u",&N);

    // Crear de manera dinamica el vector de datos
    V = crearVector(N);

    // Capturar el vector:
    capturaVector(V);

    printf("\nResultado");
    imprimeVector(V);

    printf("\nPROMEDIO: ");
    prom = promedioVector(V);
    printf("\nPromedio=%f",prom);

    // liberacion de memoria
    eliminarVector(V);

    return 0;
}
VECTOR *crearVector(unsigned int N)
{
    VECTOR *PtrVector; // convertimos en apuntador el vector

    // Asignar la memoria necesaria para almacenar una estructura VECTOR
    PtrVector =(VECTOR *)malloc(1*sizeof(VECTOR)); // sizeof(vector) regresa el tamaño en bytes de la estructura.
    // VALIDAR SI SE ASIGNO LA MEMORIA PARA EL VECTOR
    if(PtrVector == NULL)
    {
        printf("\nError al reservar la memoria para la estructura vector. ");
        exit(0);
    }
    // Asignar la memoria para los N datos enteros.
    PtrVector->data = malloc(N*sizeof(int)); 
    if(PtrVector->data == NULL)
    {
        printf("\nError al reservar la memoria para los datos enteros. ");
        exit(0);
    }
    PtrVector->Ne = N;
    return PtrVector;
}
void capturaVector(VECTOR *ptr)
{
    // Capturar los datos;
    for(unsigned int k=0; k < ptr->Ne; k++)
    {
        printf("dato[%i]= ",k);
        scanf("%i",ptr->data+k);
    }
    // no se regresa nada, por que obtenemos la direccion para manipular directamente los datos a travez de paso por referencia.
}
void imprimeVector(VECTOR *ptr)
{
    //Mostrar los datos en la pantalla
    for(unsigned int k=0; k < ptr->Ne;k++)
        printf("\nDato[%i]= %i",k,*(ptr->data+k));
    
}
void eliminarVector(VECTOR *ptr)
{
    free(ptr->data); // se libera la memoria de los datos enteros 
    free(ptr);  // Se lbera la memoria de la estructura VECTOR;
    // se cambia en ese orden, si fuera primero la estrcutra se pierde el apuntador
}
float promedioVector (VECTOR *ptr)
{
    int suma = 0;
    float prom;
    for(unsigned int k=0; k < ptr->Ne; k++)
    {
        suma += *(ptr->data+k); // equivale a tener vector[k];
    }
    prom = (float)suma/ptr->Ne;
    return prom;
}