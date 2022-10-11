/*
    Jueves 6 de Octubre de 2022 -FINALIZACION Lunes 10 de Octubre

    Implementar un programa que calcule el producto de dos matrices de numeros enteros 
    usando asignacion dinamica de memoria y una estructura para las matrices 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct  // Se crea estructura
{
    int *data;
    unsigned int Num_filas; // M
    unsigned int Num_columnas; //N
}MATRIZ; // Se crea "Estrutura MATRIZ"

MATRIZ *CrearMatriz(unsigned int fila, unsigned int columna);

void EliminarMAtriz(MATRIZ *ptr); // Libera memoria, recibe la direccion correspondiente a la matriz que se eliminara.
void CapturaMatriz(MATRIZ *ptr);
void ImprimeMatriz(MATRIZ *ptr);
MATRIZ *ProductoMatriz(MATRIZ *A, MATRIZ *B);

int main()
{
    MATRIZ *Matriz_A, *Matriz_B, *Matriz_C;
    unsigned int filas, columnas;

    printf("\nNumero de filas de la matriz A: ");
    scanf("%u",&filas);
    printf("\nNumero de Columnas de A: "); // %u -> Para decir que vamos a capturar un entero SIN SIGNO
    scanf("%u", &columnas);

    Matriz_A = CrearMatriz(filas,columnas);
    CapturaMatriz(Matriz_A);

    printf("\nNumero de filas de la Matriz B: ");
    scanf("%u",&filas);
    printf("\nNumero de Columnas de B: "); // %u -> Para decir queq vamos a capturar un entero SIN SIGNO
    scanf("%u",&columnas);

    Matriz_B = CrearMatriz(filas,columnas);
    CapturaMatriz(Matriz_B);

    printf("\nLa matriz de A: ");
    ImprimeMatriz(Matriz_A);

    printf("\nLa matriz B: ");
    ImprimeMatriz(Matriz_B);


    Matriz_C = ProductoMatriz(Matriz_A, Matriz_B);
    printf("\nEl producto de A*B: ");
    ImprimeMatriz(Matriz_C);
    
    EliminarMAtriz(Matriz_A);
    EliminarMAtriz(Matriz_B);
    EliminarMAtriz(Matriz_C);   
    return 0;
}
MATRIZ *CrearMatriz(unsigned int fila, unsigned int columna)
{
    MATRIZ *ptr;

    //Asignar la memoria para almacenar la estructura de la matriz
    ptr = (MATRIZ *)malloc(sizeof(MATRIZ)); // sizeof regresa la direccion de matriz,

    if(ptr == NULL)
    {
        printf("\nError al ingresar la memoria para la estructura Matriz");
        exit(0);
    }
    ptr->Num_filas = fila;
    ptr->Num_columnas = columna;
    // Asignar la memoria para los MxN enteros
    ptr->data = (int *)malloc(fila*columna*sizeof(int));
        // se hace el cast (int *)
    if(ptr->data == NULL)
    {
        printf("\nError al ingresar la memoria para la estructura Matriz");
        exit(0);
    }
    return ptr; // here
}
void EliminarMAtriz(MATRIZ *ptr) // Se libera la memoria 
{
    // Liberar la memoria de los datos de la matriz
    free(ptr->data);
    //Liberar la memoria de la estructura
    free(ptr);
}
void CapturaMatriz(MATRIZ *ptr)
{
    unsigned int i,j;
    for(i = 0; i < ptr->Num_filas; i++)
    {
        for( j = 0; j < ptr->Num_columnas; j++)
        {
            printf("\nDato[%i][%i]= ",i,j);
            scanf("%i", ptr->data + i*ptr->Num_columnas + j);  // scanf necesita la direccion donde va a almacenar la direccion por eso &variable por ejemplo, siempre &
        }               //   i(indice de posicion) * columnas tiene la dimension de las columnas
    }
} 
void ImprimeMatriz(MATRIZ *ptr)
{
    unsigned int i,j;
    for(i = 0; i < ptr->Num_filas; i++)
    {
        printf("\n");
        for(j = 0; j < ptr->Num_columnas; j++)
        {
          //  printf("Direccion: %p, dato: %i", ptr->data +i * ptr->columnas + j); // %p sirve para mostrar la direccion de memoria 
            printf("%i ",*(ptr->data + i*ptr->Num_columnas + j)); // se antepone * para ir a leer la direccion de memoria  SIN * IMPRIME LA DIRECCION MEMORIA.
            // printf("Direccion: %p, dato: %i \n", (ptr->data + i * ptr->columnas + j), *(ptr->data + i * ptr->columnas + j));
        }
    }
}
MATRIZ *ProductoMatriz(MATRIZ *A, MATRIZ *B)  // <-- Recibe 2 apuntadoes de memoria 
{
    MATRIZ *C; // Apuntador
    if(A->Num_columnas == B->Num_filas)
    {
        C = CrearMatriz(A->Num_filas,B->Num_columnas);
        C->Num_filas = A->Num_filas;
        C->Num_columnas = B->Num_columnas;
        // PARA RECORRER LA MATRIZ RESULTANTA:
        for(unsigned int i = 0; i < C->Num_filas; i++)
        {
            for(unsigned int j = 0; j < C->Num_columnas; j++)
            {
                *(C->data + i * C->Num_columnas + j) = 0;
                for(unsigned int k = 0; k < A->Num_columnas; k++)
                *(C->data + i * C->Num_columnas + j)+= *(A->data + i * A->Num_columnas + j) * *(B->data + k * B->Num_columnas); // esto calcula la direccion , para eso se pone todo entre () con el puntero
            }                                           // i -> filas A    j-> columnas B
        }
    }
    else
        return NULL; // return empty es decir, el aputador regresa una direccion nula
    return C;
}