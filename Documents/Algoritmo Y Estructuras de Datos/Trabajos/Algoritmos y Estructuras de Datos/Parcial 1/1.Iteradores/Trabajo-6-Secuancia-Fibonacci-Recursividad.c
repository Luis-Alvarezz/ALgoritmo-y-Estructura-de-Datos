/* 
    Calcular la secuencia de los primeros N numeros de Fibonacci.
*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
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
    printf("\n(NO RECURSIVO) La secuencia de los primeros numeros %i numeros de Fibonacci es: \n",N);
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
    float fn, r = (1.0 + sqrt(5.0)) / 2.0;
    fn = (pow(r,n) - pow(1-r,n)) / sqrt (5.0);
    return (int)fn;
}
