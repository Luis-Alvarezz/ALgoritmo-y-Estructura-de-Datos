/*
    Programa que calcula el factorial de un numero N usando una estratedia iterativa
*/
#include<stdio.h>

// Declarando la funcion:
int Factorial(int N);
int main()
{
    int f, n;

    do 
    {    
        printf ("\nEscriba el valor de n para el calculo del factorial: ");
        scanf("%i", &n);

        if( n < 1)
        {
            printf ("El valor de N debe ser mayor a 0");
        }
    }
    while(n < 1);

    f = Factorial(n);
    printf("\n %i != %i",n,f);
    return 0;
}

int Factorial(int N)
{
    int contador = 1, acomulador = 1;
    while(contador <= N) 
    {
        acomulador*= contador;
        contador++;
    }
    return acomulador;
}