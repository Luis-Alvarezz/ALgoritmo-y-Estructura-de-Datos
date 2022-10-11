// Lunes 29 de Agosto de 2022.
/*
    2. Estructuras de datos fundamentales.
    2.1. Estructura de datos basica.
    2.1.1. Arreglos

    Arreglo- Un cinjuno de MISMO TIPO que compraten un NOMBRE COMUN 

    La sintaxsis para decladrar arreglos es:
    tipo_de_dato NOMBRE _DEL_ARREGLO [Dim1][Dim2]... [Dim_n];
*/
/* Programa que recibe un vector de datos enteros y lo sepera en dos 
   vectores con lo datos pares e impares.
*/
#include<stdio.h> // Standar input - output header

// Funciones a ocupar: 
void ImprimeVector(int V[],int Ne);
void SepararVector(int Vin[],int Ne,int Pa[],int *Np,int Im[],int *Ni); // Parametros arreglos, punteros, datos normales.

int main()
{ 
    //Declaracion e inicializacion del arreglo unidimensional.
  int VectorDeEntrada[100]={12,11,56,78,98,89,65,33,45,78,16,84,98,65,1,3,7,5,9,2}; // Se crea un vector con definicion de 20 elementos 
  int Pares[100];                                                                    // Se crea vector de max 100 elementos llamado Par de tipo entero
  int Impares[100];                                                                 // Se crea un vector de max 100 elementos, llamado Impar de tipo entero
  int Ne=20,Ni=0,Np=0;                                                  // Se crea y define NumElemen = 20, Num Impares, Num Pares.

  SepararVector(VectorDeEntrada,Ne,Pares,&Np,Impares,&Ni);  
  
  printf("\nDatos de entrada:");            
  ImprimeVector(VectorDeEntrada,Ne);                    // LINEA 29-38: LLamado de funciones con dichos num de parametros 
  
  printf("\nDatos Pares:");
  ImprimeVector(Pares,Np);
  
  printf("\nDatos Impares:");
  ImprimeVector(Impares,Ni);

  return 0;  // exit successfully program 
} 

void SepararVector(int Vin[],int Ne,int Pa[],int *Np,int Im[],int *Ni)  // Declaracion de funcion separar vector.
{ 
    int i,IndiceImpares,IndicePares;          
     //Ciclo que recorre todos los elementos del Vector de Entrada
  for(i=0,IndicePares=0,IndiceImpares=0; i<Ne; i++)                                 // Siempre que de que i=0,indicePares=0,indiceImpares=0; i < NumElemn:
     {
         //Verificar si el elemento Vin con indice i es par o impar
        if(Vin[i]%2)                                                                //  en caso de que Vector en las iteraciones i, % 2:  NUM IMPAR
        { 
            // es impar 
            //Copiar el valor impar en el vector de impares
            Im[IndiceImpares]=Vin[i];                                                       // el vector en la pos[i], se almcena en el vector Im en la pocions del contador indiceImpar
            IndiceImpares++;                                                                // Aumenta el contador
        }       
        else
        { 
            //es par
            //Copiar el valor par en el vector de pares
            Pa[IndicePares]=Vin[i];                                                     // en caso de que sea numero par: el vector[i], lo almacenamos en Pa en las posiciones del contador IndicePares
            IndicePares++;                                                               // Aumenta el contador
        }
     }
 *Np=IndicePares;  // los contadores son mandados en forma de puntero para imprimir dicho numero de elementos 
 *Ni=IndiceImpares;
}

void ImprimeVector(int V[],int Ne)      // FUNCION de imprimir vector
{ int i;
  for(i=0; i<Ne; i++)                       // Se crea mediante bucle for, desde indice = 0, hasta i menor al numero de elementos.
     printf("\ndato[%i]=%i",i,V[i]);        // imprime el dato en la pos[i], del vector en pos i
}

/*
    for(inicializacion; condicion; incremento)
    {
        enuciados a ejecutar;
    }
for(expresioon_1, expresion_2; expresion_3)
    {
        enunciados_a_ejecutar;
    }

*/