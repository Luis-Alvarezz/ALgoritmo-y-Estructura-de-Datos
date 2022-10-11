/*
    Programa que calcula el factorial de un numero N usando la RECURSIVIDAD
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
    printf("\n%i !=%i",n,f);
    return 0;
}

// Funcion que calcula el factorual de forma recursiva. El valor que recibe debe ser previamente valido
int Factorial(int N)
{
    int f;
    if(N == 1)
    {
        return 1;
    }
    else
    {
        f = N * Factorial(N-1);
    }
    printf(" f= %i", f);
    return f;
}