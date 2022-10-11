/*
    Lunes 18 de Septiembre de 2022
    2.1.3 ESTRUCTURAS

    Una estructura es un conjunto de datos de distinto tipo que comparten un nombre en comun 
    
    la sintaxis para declarar una estructura es la siguiente:

    //
    struct 
    {
        Tipo_De_Dato Miembro1;
        Tipo_De_Dato Miembro2;
        ...
        Tipo_De_Dato MiembroN;
    }NOMBRE DE LA ESTRUCTURA;

    Para facilitar el uso de la estructura normalmente una estructura
    se define como un nuevo tipo de dato usando la instruccion "typedef"
    quedando de la siguiente manera:

    typedef struct 
 {
    Tipo_De_Dato Miembro1;
    Tipo_De_Dato Miembro2;
    ...
    Tipo_De_Dato MiembroN;
    }NOMBRE DE LA ESTRUCTURA;

    EJERCICIO:

*/
#include <stdio.h>

typedef struct
{
    int data[100];
    int Ne;
}VECTOR; // tipo de dato

//void Captura_Vector(VECTOR *V); // recibe un vector,  con el * NO se envia una copia, mas bien una referencia   ->OPCION 1
VECTOR Captura_Vector(int n); // UNA 4TA FORMA DE USAR lAS ESTRUCTURAS de un vector me puede devolver una estuctura   -> OPCION 2
void imprime_vector(VECTOR V);
float promedio_vector(VECTOR V);

int main()
{   
    VECTOR vector_entrada; // tipo de entrada, es una estructura

    float prome;
    printf("\nNumero de adatos enteros a capturar: ");
    scanf("%i", &vector_entrada.Ne); // acceder a cada uno de los miembros

    printf("\ncaptura de vector de %i elementos: ",vector_entrada.Ne);
    //Captura_Vector(&vector_entrada);
    vector_entrada = Captura_Vector(vector_entrada.Ne); // Forma 2 de hacerlo. 

    printf("\nVector Capturado: ");
    imprime_vector(vector_entrada);

    printf("\nPromedio del vector: ");
    prome = promedio_vector(vector_entrada);
    return 0;
}

/*
void Captura_Vector(VECTOR *V) // *V para modificar los valores externamente.
{
    for(int i = 0; i < V->Ne; i++) // para referirme a miembros de estructuras es ., y para refetirme a miembros de variables paso por referencia (V->data)
    {
        printf("\ndato[%i]= ",i);
        scanf("%i",&V->data[i]);
    }
}
*/

void imprime_vector(VECTOR V) 
{
    for(int i = 0; i < V.Ne; i++)  // V.Ne para referierme a miembros de paso por valor.
    {
        printf("\ndato[%i]= %i",i,V.data[i]);
    }
}

float promedio_vector(VECTOR V)
{
    int suma = 0;
    float prom;
    for(int i = 0; i < V.Ne; i++)
    {
        suma += V.data[i];
    }
    prom = suma/(float)V.Ne;
    return prom;
}
VECTOR Captura_Vector(int n)
{// vector dentro de la funcion
    VECTOR V; // V ahora es una variable normal, es una estructura., capturamos un vector, dentro de la variable V.
    V.Ne = n;
    for(int i = 0; i < V.Ne; i++) // para referirme a miembros de estructuras es ., y para refetirme a miembros de variables paso por referencia (V->data)
    {
        printf("\ndato[%i]= ",i);
        scanf("%i",&V.data[i]);
    }
    return V; // retorno del vector   
}
