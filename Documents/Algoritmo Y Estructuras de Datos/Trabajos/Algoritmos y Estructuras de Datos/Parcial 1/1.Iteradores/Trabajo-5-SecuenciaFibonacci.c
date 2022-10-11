/* 
    Calcular la secuencia de los primeros N numeros de Fibonacci.
*/
#include<stdio.h>
#include<conio.h>

// Declarando la funcion: 
int Fibonacci(int n);

int main()
{  
    int N, fn;
    do
    {
        
    printf("Escriba el numero de N: ");
    scanf ("%i", &N);

        if(N < 1);
        {
            printf("N debe ser mayor a 0");
        }    
    }
    while(N < 1);
    printf("\nLa secuencia de los primeros numeros %i numeros de Fibonacci es: \n",N);
    for(int i = 0; i <= N; i++)
    {
        fn = Fibonacci(i);
        printf("%i,",fn);
    }
    getch();
    return 0;
}

int Fibonacci(int n)
{
    if(n == 1)
    {
        return 1;
    }
    if(n == 0)
    {
        return 0;
    }
    return (Fibonacci(n-1) + Fibonacci(n-2));
}
