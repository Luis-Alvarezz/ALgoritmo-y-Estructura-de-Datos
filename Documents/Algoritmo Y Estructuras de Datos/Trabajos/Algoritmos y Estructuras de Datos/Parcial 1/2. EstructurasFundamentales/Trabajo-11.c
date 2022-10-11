// Programa que recibe el 2 matrices y calcula el producto

#include <stdio.h>

// declarando funciones:
void captura_matriz(int mx[][100], int num_filas, int num_columbas);
void imprime_matriz(int mx[][100], int m, int n);   
void producto_matriz(int A[][100], int Ma, int Na,
                     int B[][100], int Mb, int Nb,
                     int C [][100], int *Mc,int *Nc);
int main()
{
    int A[100][100],Ma,Na;
    int B[100][100],Mb,Nb;
    int C [100][100];       // -> Matriz donde se almacenaran los datos
    int Mc,Nc;

    //Llenando primera matriz:
    printf("\nLlenando la primra matriz");
    printf("\nNumero de filas de la matriz A: ");
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

    producto_matriz(A,Ma,Na, B,Mb,Nb, C, &Mc,&Nc);
    printf("\nLa matriz C= A*B es: " );
    imprime_matriz(C,Mc,Nc);

    return 0;
}
                                 // Filas | columnas
void producto_matriz(int A[][100], int Ma, int Na,
                     int B[][100], int Mb, int Nb,
                     int C[][100], int *Mc, int *Nc)
{   int k, filasDeA,ColumbasDeB;
    if (Na == Mb)
    {
        *Mc = Ma;
        *Nc = Nb;
        // Para movernos en la matriz rsultante:
        for(int i = 0; i < *Mc; i++)
        {
            for(int j = 0; j < *Nc; j++)
            {
                // Matriz C [i][j] = 0;
                for(int k = 0; k < Na; k++)   // Permite calcular el producto de fila n * columna n.
                {
                    C[i][j] = 0;
                    C[i][j] += A[i][k]*B[k][j];   
                }
            }
        }
    }
    else
    {
       // no cumple la condicion para el producto
        *Mc = 0;
        *Nc = 0;
    }
}
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
            printf("\n""%i",mx[i][j]);
        }
        printf("\n");
    }
}