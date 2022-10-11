/*
    Lunes 5 de Septiembre de 2022
    2.2.2 CADENA DE CARACTERES

    Una cadena de caractees es un caso particular de un arreglo unidimensional utilizado 
    para almacenar datos de tipo de caracter que representan lineas de texto.

    Sintaxis:
    char Cadena_De_texto[80];
    char Cadana_De_Texto[Total de caracteres];

    Una caracteristica praticular de los arreglos que representan 
    cadenas de caracteres es que terminan con un caracter especial 
    llamado caracter nulo "/0"
*/

/*Ejercicio:
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


#include <stdio.h>

int main()
{
    char linea_texto[100];
    char letra;
    int x;
    char linea[100];

    // Captura de un caracter o una linea de texto podemos usar las siguientes funciones:
    printf("\nEscribe una letra: ");
    scanf("%c", &letra);  // %c es para indicarle que va a almacenar una cadena
    printf("\nEl caracter capturado es: %c", letra);
    //getchar(); o fflush();
    fflush(stdin);
    printf("\nEscribe otra letra: ");
    letra = getchar();
    printf("\nEl caracter capturado es: %c", letra);

    /*printf("\nEscribe un numero entero: ");
    scanf("&i", &x);
    printf("\nEl numero es: ",x);
    /*
     Modos de almacenar una cadena de texto:
     getchar();
     getc();
    */

   printf("\nEscribe una linea de texto: ");
   // scanf("%s", linea_texto); // no es recomendable por que temina en cuanto encuentre un espacio. tipo cin  >> linea_texto en C++.
   gets(linea); // en C++ es como gets()
   printf("\nEl texto es: \n%s", linea);
   
   printf("\nEl texto es: \n");
   int i = 0;
   while(i < 5)
   {
        putchar(linea[i]);
        i++;
   }

   while(linea[i] != '0')
   {    putchar(linea[i]);
        i++;
   }
   
   /*printf("\nEscribe una linea de texto: ");
   gets(linea);
   printf("\nEl texto es: \n%s", linea); */
   
}

