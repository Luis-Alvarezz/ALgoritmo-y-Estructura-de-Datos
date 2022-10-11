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
#include <conio.h>

int main()
{
    char frase[1000];
    int k = 0, caracter_palabra = 0, total_caracteres = 0, total_palabras = 0;

    printf("\nEscriba una linea de texto: ");
    gets(frase); // Aqui almacenamos la cadena.
    printf("\n\tPalabra: \tlinea de texto: ");

    while(frase[k] != '\0')
    {
        while(frase[k] == ' ')  // Para contar los espacios y los salta
        {
            k++;
        }
        caracter_palabra = 0;
        printf("\n\t");
        while((frase[k] != ' ') && (frase[k] != '\0'))
        {
            putchar(frase[k]);
            caracter_palabra++;
            k++;
        }
        if(caracter_palabra != 0) // en caso de que el usuario por error metiera un espacio al final
        {
            printf("\t\t%i",caracter_palabra);
            total_caracteres+= caracter_palabra;
            total_palabras++;
            printf("\n");
        }   
    }
    printf("total de caracteres: %i", total_caracteres);
    printf("\nTotal de palabras: %i",total_palabras);

    getch();
    return 0;
}