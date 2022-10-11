// Programa que recibe el 2 matrices y calcula el producto

#include <stdio.h>
#include <conio.h>

// declarando funciones:
void captura_matriz(int mx[100][100], int num_filas, int num_columbas);
void imprime_matriz(int mx[100][100], int m, int n);

int main()
{
    int A[100][100];
    int Ma,Na;
    int B[100][100];
    int Mb,Nb;
    int c [100][100]; // -> Matriz donde se almacenaran los datos
    int Mc,Nc;

    //Llenando primera matriz:
    printf("\nLlenando la primra matriz");
    printf("\nNunmero de filas de la matriz A: ");
    scanf("%i", &Ma);
    printf("Numero de columnas de la matriz A: ");
    scanf("%i", &Na);
    captura_matriz(A,Ma,Na);

    printf("\nLlenando la segunda matriz");
    printf("\nNunmero de filas de la matriz B: ");
    scanf("%i", &Mb);
    printf("Numero de columnas de la matriz B: ");
    scanf("%i", &Nb);
    captura_matriz(B,Mb,Nb);

    // Imprimiendo la matriz:
    printf("\nMatriz A: ");
    imprime_matriz(A,Ma,Na);
    printf("\nMatriz B: ");
    imprime_matriz(B,Mb,Nb);

    getch();
    return 0;
}

void captura_matriz(int mx[100][100], int num_filas, int num_columbas)
{
    for(int i = 0; i < num_filas; i++)
    {
        for(int j = 0; j < num_columbas; j++)
        {
            printf("\ndato[%i][%i]= ", i,j);
            scanf("%i", &mx[i][j]);
        }
        printf("\n");
    }
}

void imprime_matriz(int mx[100][100], int m, int n)
{
    //imprimiendo la matriz
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("[%i][%i]",i,j , "\n");
            printf("\n");
        }
        printf("\n");
    }
}