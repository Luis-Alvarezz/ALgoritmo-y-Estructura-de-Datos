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
    Implementar un programa que lea un archivo de texto y almacene 
    su contenido en un arreglo de cadena de catacteres 
*/
#include <stdio.h>

int main()
{
    char lista[100][256];
    int k, total;
    FILE *Archivo;
    Archivo = fopen("lista.txt", "r");
    if(Archivo != NULL)
    {
        printf("\nSe abrio el archivo");
    
        // Lectura del archivo.
        k = 0;
        while(!feof(Archivo))
        {
            fgets(&lista[k][0],256,Archivo);
            printf("\n1. %s",&lista[k][0]);
        }
        total = k;
        fclose(Archivo);
    }
    else
    {
        printf("\nNo se abrio el archivo");
    }
    // Mostrar el contenido del archivo en pantalla
    for(int k = 0; k < total; k++)
    {
        printf("\n1. %s",&lista[k][0]);
    }
    return 0;
}