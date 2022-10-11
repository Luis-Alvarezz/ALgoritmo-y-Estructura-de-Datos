/*
    Lunes 10 de Octubre de 2022

    2.2.1 Estructura PILA
    /*
        DADA  
    /*
    
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data; // apuntador de datos
    int id; // sera el indice
    unsigned int size; // Para definir el tamaño de la pila
}PILA; // se crea arreglo.

PILA *crearPila(unsigned int tamanio); // recibe el tamano
void EliminarPila(PILA *p); // borrar la pila
char push(PILA *p, int d); // funcion que recibe la direccion de la pila donde se almacena el dato y en donde lo va a apilar
char IsFull(PILA *p); // funcion para verificar si la pila esta llena
void imprimePila(PILA *p);
char pop(PILA *p, int *d);
char IsEmpty(PILA *p);

int main()
{
    PILA *pila1;
    pila1 = crearPila(10);
    printf("\nLa lista ");
    imprimePila(pila1);

    push(pila1,10);
    push(pila1,20);
    push(pila1,30);
    printf("\nLa lista 2: ");
    imprimePila(pila1);
    push(pila1,40);
    push(pila1,50);
    
    printf("\nListado de los datos apilados: ");
    imprimePila(pila1);
    EliminarPila(pila1);
    
    return 0;
}
PILA *crearPila(unsigned int tamanio)
{
    PILA * ptr; // Se crea apuntador. que almacenara direcciones de pilas

    //asignacion dinamica
    ptr =(PILA* )malloc(sizeof(PILA));
    if(ptr == NULL)
    {
        printf("\nError al reservar memoria para la estructura PILA");
        exit(0);
    }
    // Asignacion de
    ptr->id = -1; // se crea la pila.  -1 indica que esta vacia la pila
    ptr->size = tamanio;

    // Reservar la memoria para los datos qde la PILA.
    ptr->data = (int *)malloc(tamanio*sizeof(int));
    if(ptr->data == NULL)
    {
        printf("\nError al reservar memoria para los datos de la PILA");
        exit(0);
    }
    return ptr;
}

void EliminarPila(PILA *p)
{
    // para liberar la memoria de los datos PILA
    free(p->data);
    // Liberar la memoria de la estructura PILA
    free(p);
}
char push(PILA *p, int d)
{
    char flag = 0; // el profe hizo: char flag = 0, lo mismo a bool flag = false en C++.
    if(!IsFull(p))
    {
        p->id++;
        *(p->data + p->id) = d; // para ver donde vamos a colocar el dato, id la 1ra vez vale 0.
                // direccion base + donde va id.
        flag = 1;
    }
    return flag;
}
char IsFull(PILA *p)
{
    // varficar si la pila esta llena:
    if(p->id == p->size) // p-> size almacena el tamaño de la pila
    {
        return 1; // retorna verdadero. (pila llena)
    }
    else
    {
        return 0; // retorna falso. (pila no llena)
    }

}
void imprimePila(PILA *p) // recorrer toda la pila, y mandarla a la pantalla.
{ 
    if(!IsEmpty(p))
    {
        for(int k = p->id; k >= 0; k--) // antes era k = p->id -1 pero se cambia por que ya se esta en la posicion deseada.
        {
            printf("\n%i", *(p->data+k));
        }
    }
    else
     printf("\nLa pila esta vacia!!! ");
}
char IsEmpty(PILA *p)
{
    if(p->id == -1)
     return 1;
    else
     return 0;
}
char pop(PILA *p, int *d)
{
    if(!IsEmpty(p))
    {
        *d = *(p->data + p->id); // como empi
        p->id--; // el ultimo indice es 0
        return 1;
    }
    return 0;
}