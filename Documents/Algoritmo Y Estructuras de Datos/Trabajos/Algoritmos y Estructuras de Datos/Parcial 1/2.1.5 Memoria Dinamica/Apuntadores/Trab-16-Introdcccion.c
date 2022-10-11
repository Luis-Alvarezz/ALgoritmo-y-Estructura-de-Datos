/*  2.1.5 Memoria Dinamica
    
    Cuando un programa requiere el uso de memoria, para que no sabemos 
    de antemano cuanta memoria se requiere, de dice que se necesita 
    manejar la memoria de forma dinamica. Esto implica que en 
    "Tiempo de Ejecucion" podamos crear nuevas variables o tipos de datos en
    la cantidad necesaria justo cuando el programa lo requiera.


    Para realizar la solicitud de memoria al sistema, se tiene la siguiente funcion:

        void* malloc("Numero de Bytes requeridos"); -> Solo otorga una cantidad de memoria especificada por el usuario.
*/
/*
    EJERCICIO:  
    CAlculo del  promedio de un vevtor de datos enteros positivos, usando asignacion dinamica para el arreglo
*/
#include <stdio.h>
#include<stdlib.h>

/*int main()
{
    unsigned int n, k;
    int suma;
    float promedio;
    int *vector; // sirve para almacenar la direccion de memoria del conjunto de enteros que se reserva de manera dinamica
    // Se solicita la cantidad de datos 
    printf("\nNumero de datos a capturar: ");
    scanf("%u", &n); // &n regresa la referencia de la direccion de memoria de la variable.
    //Asignar o reservar de manera dinamica la memoria.
    vector = (int *)malloc(4*sizeof(int)); // 4(valor de un byte de enteros) * numero de vueltas, con sizeof regrese el numero de bytes. 
    // malloc regresa direccion de memoria que no esta especificada a ningun tipo, para eso (int *)

    // despues de hacer una asignacion denamica de la memoria
    // debemos validar dicha asignacion
    if(vector ==NULL)
    {
        printf("Error al reservar la memoria para el vector de datos. ");
        exit(0); // para salir xd
    }

    // Capturar los datos
    for(k = 0; k < n; k++)
    {
        printf("dato[%i]= ",k);
        scanf("%i",vector+k);
    }

    // Calcular el promedio
    for(k = 0; k < n; k++)
    {
        suma += *(vector+k);  // k es quien mueve de elemento en elemento, // si vector fuera arreglo, equivale a-> vector[k]
    }
    // promedio:
    promedio = (float)suma/n;
    //Mostrando los datos en pantalla
    printf("\n RESULTADO: \n");
    for( k = 0; k < n; k++)
    {
        printf("\nDato[%i]= %i",k,*(vector+k));  //  vector[k];
    }
    printf("\nPromedio=%f",promedio);

    // Para liberar la memoria:
    free(vector); // solo se requiere la direccion del primer elemento de la memoria dinamica
    return 0;
}*/


                                                                // Ahora con funciones
int *CapturaVector(unsigned int Ne);
float promedioVector(int *ptr, int Ne);
void imprimeVector(int *ptr, int Ne);
int main()
{
    unsigned int n;
    int suma;
    float promedio;
    int *vector; // sirve para almacenar la direccion de memoria del conjunto de enteros que se reserva de manera dinamica
    // Se solicita la cantidad de datos 
    printf("\nNumero de datos a capturar: ");
    scanf("%u", &n); // &n regresa la referencia de la direccion de memoria de la variable.
    //Asignar o reservar de manera dinamica la memoria.
    vector = (int *)malloc(4*sizeof(int)); // 4(valor de un byte de enteros) * numero de vueltas, con sizeof regrese el numero de bytes. 
    // malloc regresa direccion de memoria que no esta especificada a ningun tipo, para eso (int *)

    // despues de hacer una asignacion denamica de la memoria
    // debemos validar dicha asignacion
    if(vector ==NULL)
    {
        printf("Error al reservar la memoria para el vector de datos. ");
        exit(0); // para salir xd
    }

    // Capturar los datos
    vector = CapturaVector(n);

    // Calcular el promedio
    for(unsigned int k = 0; k < n; k++)
    {
        suma += *(vector+k);  // k es quien mueve de elemento en elemento, // si vector fuera arreglo, equivale a-> vector[k]
    }
    // promedio:
    promedio = (float)suma/n;
    //Mostrando los datos en pantalla
    printf("\n RESULTADO: \n");
    for( unsigned int k = 0; k < n; k++)
    {
        printf("\nDato[%i]= %i",k,*(vector+k));  //  vector[k];
    }
    printf("\nPromedio=%f",promedio);

    // Para liberar la memoria:
    free(vector); // solo se requiere la direccion del primer elemento de la memoria dinamica
   return 0;
}

int *CapturaVector(unsigned int Ne)  // funcion para regresar la direccion donde estan los datos
{
    int *ptr;
     //Asignar o reservar de manera dinamica la memoria.
    ptr = (int *)malloc(4*sizeof(int)); // 4(valor de un byte de enteros) * numero de vueltas, con sizeof regrese el numero de bytes. 
    // malloc regresa direccion de memoria que no esta especificada a ningun tipo, para eso (int *)

    // despues de hacer una asignacion denamica de la memoria
    // debemos validar dicha asignacion
    if(ptr ==NULL)
    {
        printf("Error al reservar la memoria para el vector de datos. ");
        exit(0); // para salir xd
    }

    // Capturar los datos
    for(unsigned int k = 0; k < Ne; k++)
    {
        printf("dato[%i]= ",k);
        scanf("%i",ptr+k);
    }
    return ptr;
}
float promedioVector(int *ptr, int Ne)
{
    int suma = 0;
    float prom;
    //calcular el promedio
    for(unsigned int k = 0; k < Ne; k++)
    {
        suma += suma + *(ptr+k); // vector 
    }
    prom = (float)suma/Ne;
    return prom;
}
void imprimeVector(int *ptr, int Ne)
{
    for(unsigned int k = 0; k<Ne; k++)
    {
        printf("\ndato[%i]=",k,*(ptr+k));
    }
}