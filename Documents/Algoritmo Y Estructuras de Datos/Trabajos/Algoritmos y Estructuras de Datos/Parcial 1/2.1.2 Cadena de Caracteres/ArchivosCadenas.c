/*
    Lunes 12 de Septiembre de 2022.

    MANEJO DEA ARCHIVOS EN C (Lectura y escritura de archivos)

    Manejo del archivo
    fopen  ..... abrir archivo desde HD
    fclose ..... Cerrar archivo                         
    feof ....... Indica si llegamos al final del archivo
    frewind ..... regresa el apuntador al inicio del archivo 

    Lectura del archivo 
    fgetc - lee un caracter del archivo
    fgets - lee una linea de caractres del archivo
    fread - lee datos binarios desde el archivo
    fscanf - lee datos con formato especifico desde el archivo

    Escritura del archivo
    fputc  - escribe un caraacter en el archivo
    fputs  - escribe una cadena de caracteres en el archivo
    fwrite  - escribe datos binarios en el archivo.
    fprintf  - escribe datos con formato especifico en el archivo.

    FILE* fopen(const char* Nombre_del_archivo, const char* tipo_de_lectura);

    "r" abrir archivo en modo lectura
        (regresa NULL si no existe archivo)
    
    "w" abrir el archivo en modo escritura
        Si no exite, crea el archivo
        Si existe el archivo lo sobre escribe.

    "a" abrir archivo en modo escritura añadiendo la nueva informacion al final del archivo
        Si no existe, crea uno.

    "r+" Crea un archivo para lectura y escritura.
        (regresa NULL si no existe el archivo)

    "w+" Crea un archivo para lectura y escritura.
        Si no existe, crea el archivo
        Si existe el archivo, lo sobre escribe

    "rb" 
*/

#include <stdio.h>
#include <conio.h>

int main()
{
    // Declarar una referencia a un archivo
    FILE *Archivo_De_Escritura;
    char caracter;
    char cadena[] = "Esta es una linea de texto escrita con la funcion fputs() ";
    float r;
    // Abrir archivo , modo a abrir (en esta caso escritura)
    Archivo_De_Escritura = fopen("Texto.txt", "w");

    if(Archivo_De_Escritura != NULL)
    {
        // Si se creo el archivo
        caracter = 'X';
        // Escribe un caracater en el archivo, recibe el caracter, referencia del archivo a escribir.
        fputc(caracter, Archivo_De_Escritura);
                // cadena, REFERENCIA
        fputc(' ', Archivo_De_Escritura);
        fputc(65,Archivo_De_Escritura); // en Codigo ASCII (65 -> A) 
        fputc(10, Archivo_De_Escritura); // (10 -> ESPACIO EN TEXTO).
        //Ahora con cadena[] -> Escribe una cadena en el archivo, recibe 2 parametros
        fputc(cadena, Archivo_De_Escritura);
     //->// NombreCadena, Referencia
         
         for(int i = 0; i < 4; i++)
         {
            r = i*(3.1416/2.0);
            printf(Archivo_De_Escritura,"\n Dato [%i] = %f",i,r);
         }
        //cierra el archivo creado para escritura
        fclose(Archivo_De_Escritura);
    }
    else
    {
        printf ("Error: No se puede abrir el archivo. \n");
    }
    getch();
    return 0;
}