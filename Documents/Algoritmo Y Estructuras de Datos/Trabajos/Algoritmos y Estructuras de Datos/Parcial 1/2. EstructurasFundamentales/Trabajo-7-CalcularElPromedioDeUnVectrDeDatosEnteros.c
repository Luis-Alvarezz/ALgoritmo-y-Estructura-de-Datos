	
/*
2. Estructuras de datos fundamentales
2.1. Estructuras de datos básicas
2.1.1. Arreglos

Arreglo.- un conjunto de datos del MISMO TIPO que comparten un NOMBRE COMUN, y para identificar a cada de los elementos del conjunto se utiliza un número INDICE el cual inicia en CERO.

La Sintaxis para declarar arreglos es la siguiente:

tipo_de_dato NOMBRE_DEL_ARREGLO [Dim1][Dim2]...[DimN];

*/
/*
    Programa que calcula el promedio de un vector de datos 
    enteros dado por el usuario.
*/
#include<stdio.h>

// Declarando funciones:
void capturar_vector(int v[], int Ne);   // Comenzamos declarando las funciones a ocupar en el programa 
void imprime_vector(int v[], int Ne);
float promedio_vector(int v[], int Ne);

int main()
{   
    int vector_entrada[100], Ne;    // se crea un arreglo de tipo entero donde se almacenaran los datos ingresador por el usuario,
                                     //Y una variable llamada Ne para almacenar la cantidad de datos a trabajar.
    float prom;                       // Se crea una variable local de tipo flotante 
    printf("\nNumero de datos enteros a capturar: ");
    scanf("%i", &Ne);
    printf("\nCaptura de vector %i, elementos: ",Ne);   // Linea 30-33 se encargan de preguntar al usuario por los datos correspondientes, 
    capturar_vector(vector_entrada,Ne);                 // A su vez se almacena en el el numero de vueltas del vector, acompañado de los datos ingresados mediante la funcion mencionada
                        
    printf("\nVector Capturado: ");     
    imprime_vector(vector_entrada,Ne);              // linea 35-38, Para finalizar imprimiendo el vector con una de las funciones establecidas con los parametros por paso de valor.
    prom = promedio_vector(vector_entrada,Ne);      // llamamos y almacenamos la funcion del promedio_vector en la variable float creada 
    printf("\nEl promedio del vector es: %g", prom);

    return 0;  // Retornamos a 0 para ejecutado de modo exitoso.
}

void capturar_vector(int v[], int Ne)       //       Linea 43-50
{   
    for(int i = 0; i < Ne; i++)         // se encarga de capturar los datos que se almacenaran el el vector en dichas posiciones. con paso de referencia del vector y del num de vueltas
    {
        printf("\ndato[%i]= ",i);   // Se usa un for, para que cree espacios de n cantidad de datos, y los almacene de forma iterativa.
        scanf("%i",&v[i]);
    }
}

void imprime_vector(int v[], int Ne)    // Linea 52-58
{
    for(int i = 0; i < Ne; i++)     // la funcion mediante paso de datos por valor, se encarga de imprimir el vector para "Corroborar" los datos ingresados
    {
        printf("\ndato[%i]= %i",i,v[i]);    // Mediante un for, se accede al n-1 numero de vueltas, imprimiendo el vector en la posicion "i" donde se almacena cada elemento.
    }
}
float promedio_vector(int v[], int Ne)  //          Linea 59-71
{
    int suma = 0;                                   // Funcion del promedio, con paso de datos por valor del arreglo y n num de vueltas
    float prom;
        
    for(int i = 0; i < Ne; i++)             //  con la ayuda de 2 datos (int y float) locales, nos ayudaran, en este caso summa para almacenar la suma e irse iterando.
    {                                       //  el prom para almacenar la suma / n cantidad de datos y asi de manera mecanica resolver el promedio
        suma+= v[i];
    }     // suma es entero y Num Elementos es entero, por lo cual solo devuelte enteros
    prom =(float)suma / Ne;
    //  (float)suma -> se llama 
    return prom;
}