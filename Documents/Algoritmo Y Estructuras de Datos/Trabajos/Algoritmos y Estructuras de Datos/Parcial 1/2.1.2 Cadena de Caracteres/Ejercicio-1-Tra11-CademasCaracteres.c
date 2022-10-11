/*
    Lunes 5 de Septiembre de 2022
Ejercicio:
    Implementar un programa que reciba una cadena de caracteres
    y relice un analisis de la misma mostrando como resultado
    la Siguiente tabla:

    Por ejemplo:  
    saludo a todos los presentes

    PALABRAS      Numero de caracteres por palabras
    saludos        7     
    a              1
    todos          5
    los            3
    presente       9

    Total de caracteres: 25
    total de palabras 5
    SIN ESPACIOS 
*/

#include<stdio.h>

int main()
{
    char frase[200];
    int k;
    printf("\nEscriba una linea de texto: ");
    gets(frase); // Aqui almacenamos la cadena.

    while(frase[k] != '\0')
    {
        putchar(frase[k]);
        k++;
    }

    return 0;
}