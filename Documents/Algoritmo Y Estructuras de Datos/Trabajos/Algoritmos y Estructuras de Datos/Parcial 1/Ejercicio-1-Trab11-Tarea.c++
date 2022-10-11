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

#include <iostream>
#include<stdio.h>
#include <conio.h>
#include <string.h>
using std::cout; using std::cin; using std::endl;

int main()
{
    char frase[200];
    int k, total_palabras = 0, espacios = 0, palabras = 0, cont_palabras = 1, caracter_palabra = 0;

    printf("\nEscriba una linea de texto: ");
    gets(frase); // Aqui almacenamos la cadena.

    while(frase[k] != '\0')
    {
        cout << "\n";
        while(frase[k] != ' ');
        {
            caracter_palabra++;
            putchar(frase[k]);
            k++;
        }
        cout << "Caracter por palabra: " << caracter_palabra << endl;
    }
    
    // Para encontrar la cantidad de caracteres:
    palabras = strlen(frase); // sacamos la longitud de las palabras con la funcion strlen.
    for(int i = 0; i <= palabras; i++)
    {
        if(frase[i] == ' ')
        {
            espacios++;
        }
    } 
    total_palabras = palabras - espacios;
    cout << "\nTotal de caracteres: " << total_palabras << endl;
    cout << "Espacios: " << espacios << endl;
    
    // Para calcular el total de palabras:
    for(int i = 0; i < total_palabras; i++)
    {
        if(frase[i] == ' ' && frase[i+1] != ' ')
        {
            cont_palabras++;
        }
    }
    cout << "\nTotal de palabras: " << cont_palabras << endl;

    // Numero de caracteres por palabras:
    for(int i = 0; i < total_palabras; i++)
    {
        if(frase[i] == ' ' && frase[i] != ' ')
        {
            cout << "Palabra " << i+1 << ": " << frase[i] << endl;
        }
    }
    getch();
    return 0;
}