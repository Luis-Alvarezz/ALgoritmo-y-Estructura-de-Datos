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
    Implementar funciones que realicen lsa operaciones aritmeticas basicas sobre numeros complejos.
    Utilizar una estructura para el manejo de los numeros complejos.

    TODO ESTE TRABAJO ES PASO POR VALOR
*/
#include <stdio.h>

typedef struct 
{
    float real;
    float imaginarios;
}COMPLEJO; // es una estrutura que contiene arrays

// Funciones a ocupar:
COMPLEJO suma_compleja(COMPLEJO z1, COMPLEJO z2);
void imprime_complejo(COMPLEJO z);
COMPLEJO resta_compleja(COMPLEJO z1, COMPLEJO z2);
COMPLEJO producto_completo(COMPLEJO z1, COMPLEJO z2);
COMPLEJO division(COMPLEJO z1, COMPLEJO z2);

int main()
{
    COMPLEJO w,z,sum, res, prod_comp, cociente;

    w.real = 3;
    w.imaginarios = 5;
    printf("\nw= ");
    imprime_complejo(w);

    z.real = 2;
    z.imaginarios = 2;
    printf("\nz= ");
    imprime_complejo(z);

    sum =  suma_compleja(w,z);
    printf("\nLa suma w+z: ");
    imprime_complejo(sum);

    res = resta_compleja(w,z);
    printf("\nLa resta w-z: ");
    imprime_complejo(res);

    prod_comp = producto_completo(w,z);
    printf("\nEL producto completo es: ");
    imprime_complejo(prod_comp);

    cociente = division(w,z);
    printf("\nLa division es: ");
    imprime_complejo(cociente);


    return 0;
}

COMPLEJO suma_compleja(COMPLEJO z1, COMPLEJO z2)
{
    COMPLEJO r;
    r.real = z1.real + z2.real;
    r.imaginarios = z1.imaginarios + z2.imaginarios;
    return r;
}
void imprime_complejo(COMPLEJO z)
{
    if(z.imaginarios < 0)
    {
        printf("%g%gi",z.real,z.imaginarios);
    }
    else
    {
        printf("%g+%gi",z.real,z.imaginarios);
    }

}
COMPLEJO resta_compleja(COMPLEJO z1, COMPLEJO z2)
{
    COMPLEJO sub_r;
    sub_r.real = z1.real - z2.real;
    sub_r.imaginarios = z1.imaginarios - z2.imaginarios; 
    return sub_r;
}
COMPLEJO producto_completo(COMPLEJO z1, COMPLEJO z2)
{
    /*
        Supongamos:
            (a+bi)(c+di)= ac + adi+bic + bidi = ac-bd 
    */
   COMPLEJO r;
   r.real = z1.real*z2.real - z1.imaginarios*z2.imaginarios;
   r.imaginarios = z1.real*z2.imaginarios + z1.imaginarios*z2.real; // tiene q imprimir 16-4i

   return r;
}

COMPLEJO division(COMPLEJO z1, COMPLEJO z2)
{
    /*
        (a+bi)      (a+bi)      (c-di)      ac-adi+cbi-bidi     (ac+bd)+(cb-ad)i
        ------  = --------  *  ------- =    --------------- =   ----------------
        (c+di)      (c+di)      (c-di)         (c^2+d^2)               (c^2+d^2)


        (ac+bd)         (cb-ad)
        -------  +     --------- i
        (c^2+d^2)      (c^2+d^2)
    */
   COMPLEJO div, conjugado,aux;
   float denominador;

    conjugado.real = z2.real;
    conjugado.imaginarios = z2.imaginarios;
    denominador = (z2.real*z2.real) + (z2.imaginarios*z2.imaginarios); // cuadrado de C + cuadrado de D
    aux = producto_completo(z1,conjugado);
    div.real = aux.real / denominador;
    div.imaginarios = aux.imaginarios / denominador;
 // tiene que devolver -1/2 + 2i.
    return div;
}