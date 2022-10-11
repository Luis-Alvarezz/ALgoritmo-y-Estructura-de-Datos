#include <stdio.h>
#include <conio.h>

int main()
{
    // Declarar una referencia a un archivo
    FILE *Archivo_De_Lectura;
    char caracter;
    char cadena[200];
    float real = 3.1415;
    int i = 0;

    // Abrir archivo , modo a abrir (en esta caso escritura)
    Archivo_De_Lectura = fopen("Texto.txt", "r");
    if(Archivo_De_Lectura != NULL)
    {/*
        // Si se abre el archivo
        caracter = fgetc(Archivo_De_Lectura);
        printf("\n %c",caracter);
        //cierra el archivo creado para escritura

        //Lectura de 10 caracteres 
        for(int i = 0; i < 10; i++)
        {
            caracter = fgetc(Archivo_De_Lectura);
            printf("\n %c",caracter);    
        }

        while( !feof(Archivo_De_Lectura))
        {
            caracter = fgetc(Archivo_De_Lectura);
            printf("\n %c",caracter);    
        }
        */

       /*
        // Leer una linea de teto desde el archivo
        fgets(cadena,200,Archivo_De_Lectura);
        printf("\n%s", cadena);
            // Lectura en 
        for(int i = 0; i < 3; i++)
        {
            fgets(cadena,200,Archivo_De_Lectura);
            printf("%s", cadena);
        }
          while( !feof(Archivo_De_Lectura))
        {
            fgets(cadena,200,Archivo_De_Lectura);
            printf("%s", cadena); 
        } */

        ///// Leer datos con formato desde un archivo.
        fscanf(Archivo_De_Lectura,"%f",&real);
        printf("El dato real es:&f", real);

        fscanf(Archivo_De_Lectura,"%g",&i);
        printf("El dato entero es:&f", i);
        caracter = fgetc(Archivo_De_Lectura);

        fscanf(Archivo_De_Lectura,"%c", &caracter);
        printf("El caracter es:&c", caracter);

        fscanf(Archivo_De_Lectura,"%s", &cadena);
        printf("La cadena es: %s", cadena);
        //Cerrar el archivo abierto para lectuar
        fclose(Archivo_De_Lectura);
    }
    else
    {
        printf ("Error: No se puede abrir el archivo. \n");
    }
    getch();
    return 0;
}
   