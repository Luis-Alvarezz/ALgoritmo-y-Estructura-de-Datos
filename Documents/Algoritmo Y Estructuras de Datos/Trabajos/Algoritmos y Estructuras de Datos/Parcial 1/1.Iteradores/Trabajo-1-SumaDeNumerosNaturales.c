// Entrada estandar(teclado) y salida de datos estandar(pantalla)
/*
    Programa que calcula la sumatoria de los primeros N numeros naturales
*/
#include<stdio.h>

// Declarando la funcion: 
int sumatoria (int N);

int main()
{
    int N, suma = 0;
    do
    {    
        printf("Escriba la cantidad de N de numeros naturales a sumas: ");
        scanf("%i",&N);

        if(N < 1)
        {
            printf ("\nN debe ser mayor a 0");
        }
    }
    while (N < 1);  

    // Calculando la sumaoria:
    suma = Sumatoria(N);
    printf("\nLa sumatoria de los primeros %i numeros naturales es %i",N, suma);
    return 0;
}

int Sumatoria(int N)
{
    int contador = 1, suma = 0;
    while (contador <= N)
    {
        suma += contador;
        contador++;
    }
    return suma;
}