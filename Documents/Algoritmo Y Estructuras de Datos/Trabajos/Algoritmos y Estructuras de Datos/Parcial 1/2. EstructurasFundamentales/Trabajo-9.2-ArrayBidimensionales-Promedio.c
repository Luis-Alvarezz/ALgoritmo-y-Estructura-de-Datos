// Lunes 29 de Agosto de 2022.
/*
    2. Estructuras de datos fundamentales.
    2.1. Estructura de datos basica.
    2.1.1. Arreglos
/*

/*
    Programa que captura una matriz de datos enteros 
    y calula la suma de todos sus elementos.
*/
#include<stdio.h>

//Declarando funciones:
void captura_matriz(int mx[][100], int num_filas, int num_columbas);
void imprime_matriz(matriz_entrada,m,n);
void promedio_matriz(int mx[][100],int m, int n);

int main()
{                   //filas|colmnas
    int matriz_entrada[100][100], m,n;

    printf("\nNumero de filas de la matriz: ");
    scanf("%i", &m);
    printf("\nNumero de columnas de la matriz: ");
    scanf("%i", &n);

    captura_matriz(matriz_entrada,m,n);
    printf("\nLa matriz introducida fue: ");
    printf("\n");
    imprime_matriz(matriz_entrada,m,n);

    printf("\nEl promedio de la matriz es: ");
    printf("%f",promedio_matriz(matriz_entrada,m,n));

    return 0;
}
/*
    Matriz de 3x3:
       j      j     j
    i[][]  [][]  [][]
    i[][]  [][]  [][]
    i[][]  [][]  [][]
*/
void captura_matriz(int mx[][100], int num_filas, int num_columbas)
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

void imprime_matriz(int mx[][100], int m, int n)
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
void promedio_matriz(int mx[][100],int m, int n)
{
    int suma = 0;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; n++)
        {
            suma = mx[i][j];
        }
    }
    return (float)suma/(m*n);
}