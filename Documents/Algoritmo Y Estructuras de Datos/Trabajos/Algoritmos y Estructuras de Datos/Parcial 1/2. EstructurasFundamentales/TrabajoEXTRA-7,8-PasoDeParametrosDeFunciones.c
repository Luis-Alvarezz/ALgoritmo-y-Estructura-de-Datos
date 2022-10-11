/*
    Ejemplo de paso de parametos a funciones
    paso por valor
    paso por referencia
*/
#include<stdio.h>

// Declarando funciones: 
void funcion(int x); // -> Variable N es Global
void Funcion(int *num);

int main()
{
    int n = 10; // Variable Local
    printf("\n(antes de llamar a la funcion)El valor de N es %i", n);
    funcion(n);
    printf("\n(despues de llamar a la funcion)El valor de N es: %i", n);

    Funcion(&n);
    printf("\n(despues de llamar a la funcion)El valor de N es: %i", n);
    return 0;
}

void funcion(int x)
{
    printf("\nValor recibido de N= %i", x);
    x = 0;
    printf("\nEl valor modificado dentro de la funcion N= %i", x);
}

// Para que una funcion modifique una variabla del main, se necesita un psao por referencia!!!!
void Funcion(int *num)
{
    printf("\nEl valor que se recibio es N= %i", *num);
    *num = 123;
    printf("\nEl valor con modificaciones dentro de la funcion es N= %i",*num);
}