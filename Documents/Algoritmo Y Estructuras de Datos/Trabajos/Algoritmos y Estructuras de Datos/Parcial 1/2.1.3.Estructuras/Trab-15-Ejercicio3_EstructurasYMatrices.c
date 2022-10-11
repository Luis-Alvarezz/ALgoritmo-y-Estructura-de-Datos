/*
    Lunes 18 de Septiembre de 2022.
    
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
    IMplementar 
    TODO ESTE TRABAJO ES PASO POR VALOR
*/
#include <stdio.h>

typedef struct 
{
    float real;
    float imaginarios;
}COMPLEJO;

typedef struct // se crea estructura
{
    //numeros complejos sin signo
    unsigned int fil; //(m);  // filas
    unsigned int colum; //(n); // columnas
    COMPLEJO mx[10][10]; // Se crea un numero complejo., con [][] se crea un Arreglo Bidimensional de numeros complejos
}MATRIZ_COMPLEJA;

// Funciones a ocupar:
COMPLEJO suma_compleja(COMPLEJO z1, COMPLEJO z2);
void imprime_complejo(COMPLEJO z);
COMPLEJO resta_compleja(COMPLEJO z1, COMPLEJO z2);
COMPLEJO producto_complejo(COMPLEJO z1, COMPLEJO z2);
COMPLEJO division(COMPLEJO z1, COMPLEJO z2);
COMPLEJO captura_complejo(void);

// funciones de la estructura matriz_compleja:
MATRIZ_COMPLEJA captura_matriz_compleja(unsigned int filas, unsigned int columnas);
void imprime_matriz_compleja(MATRIZ_COMPLEJA A);
MATRIZ_COMPLEJA suma_matriz_compleja(MATRIZ_COMPLEJA a, MATRIZ_COMPLEJA b);
MATRIZ_COMPLEJA productoMatricesComplejas(MATRIZ_COMPLEJA A, MATRIZ_COMPLEJA B);

int main()
{   
    MATRIZ_COMPLEJA A,B,C,D;

    printf("\t\nArreglo de Matrices!!");
    printf("\nIngrese el numero de filas de A: ");
    scanf("%u", &A.fil);
    printf("Numero de columnas A: ");
    scanf("%u", &A.colum);
    
    A = captura_matriz_compleja(A.fil,A.colum);  // llamamos a la funcion donde capturamos los datos
    printf("\nLa matriz capturada es: ");
    imprime_matriz_compleja(A);

    printf("\nIngrese el numero de filas de B: ");
    scanf("%u", &B.fil);
    printf("Numero de columnas de B: ");
    scanf("%u", &B.colum);

    B = captura_matriz_compleja(B.fil,B.colum);
    printf("\nLa maatriz B capurada es: ");
    imprime_matriz_compleja(B);

    C = suma_matriz_compleja(A,B);
    printf("\nA + B= ");
    imprime_matriz_compleja(C);

    D = productoMatricesComplejas(A,B);
    printf("\nA * B= ");
    imprime_matriz_compleja(D);
    
    return 0;   
}

COMPLEJO captura_complejo(void)
{
    COMPLEJO z;
    printf("\nre= ");
    scanf("%f",&z.real);
    printf("\nImaginario= ");
    scanf("%f", &z.imaginarios);

    return z;
}
COMPLEJO suma_compleja(COMPLEJO z1, COMPLEJO z2)
{
    COMPLEJO r;
    r.real = z1.real + z2.real;
    r.imaginarios = z1.imaginarios + z2.imaginarios;

    return r;
}

MATRIZ_COMPLEJA captura_matriz_compleja(unsigned int filas, unsigned int columnas)
{
    MATRIZ_COMPLEJA a;
    a.fil = filas;
    a.colum = columnas;
    for(unsigned int i = 0; i < a.fil; i++)
    {
        for(unsigned int j = 0; j < a.colum; j++)
        {
            a.mx[i][j] = captura_complejo();
        }
    } 
    return a;
}
void imprime_complejo(COMPLEJO z)
{
    if(z.imaginarios< 0)
    {
        if(z.imaginarios == -1)
        {
            printf("%g-i",z.real);
        }
        else
        {
            printf("%g%gi",z.real,z.imaginarios);
            if(z.imaginarios == 1)
            {
                printf("%g+1",z.real);
            }
            else
            {
                printf("%g+%gi",z.real,z.imaginarios);
            }
        }
    }
}

void imprime_matriz_compleja(MATRIZ_COMPLEJA a) //jksdhjasbd
{
    for(unsigned int i = 0; i < a.fil; i++)
    {
        for(unsigned int j = 0; j < a.colum; j++)
        {
            imprime_complejo(a.mx[i][j]);
            printf(" ");
        }
    }
}
MATRIZ_COMPLEJA suma_matriz_compleja(MATRIZ_COMPLEJA a, MATRIZ_COMPLEJA b)
{
    MATRIZ_COMPLEJA suma; // con la regla de la suma de mismas dimensiones
    suma.fil = 0;
    suma .colum = 0;
    if((a.fil == b.fil) && (a.colum == b.colum))
    {
        suma.fil = a.fil;
        suma.colum= a.colum;

        for(unsigned int i=0;i < a.fil;i++)
        {
            for(unsigned int j=0; j < a.colum;j++)
            {
                suma.mx[i][j] = suma_compleja(a.mx[i][j], b.mx[i][j]);
            }
        }
    }
    else
    {
        printf("\nNo se puede realizar la suma, las dimensiones de las matrices no corresponden ");
    }
    return suma;
}
MATRIZ_COMPLEJA productoMatricesComplejas(MATRIZ_COMPLEJA A, MATRIZ_COMPLEJA B)
{
    MATRIZ_COMPLEJA C;
    COMPLEJO aux;

    if(A.colum == B.fil)
    {
        C.fil = A.fil;
        C.colum= B.colum;

        for(unsigned int i = 0; i < C.fil; i++)
        {
            for(unsigned int j = 0; j < C.colum;j++)
            {
                C.mx[i][j].real = 0;
                C.mx[i][j].imaginarios = 0;
                for(unsigned int k = 0; k < A.colum; k++)
                {  
                    aux = producto_complejo(A.mx[i][k],B.mx[k][j]);
                    C.mx[i][j] = suma_compleja(C.mx[i][j],aux);
                } 
            }
        } 
    }
    else
    {
        printf("\nNo se puede realizar el producto, las dimensiones no corresponden ");
        C.fil = 0;
        C.colum = 0;
    }

    return C;
}
COMPLEJO producto_complejo(COMPLEJO z1, COMPLEJO z2)
{   
    COMPLEJO r;
    r.real = z1.real * z2.real - z1.imaginarios * z1.imaginarios;
    r.imaginarios = z1.imaginarios * z2.imaginarios + z1.imaginarios * z2.imaginarios;

    return r;
}