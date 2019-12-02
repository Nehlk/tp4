#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"


 /*
  * \brief Solicita un numero flotante al usuario y devuelve el resultado
  * \parametro mensaje. Es el mensaje a ser mostrado
  * \Return El numero ingresado por el usuario
  */
float getFloat(char mensaje[])
{

    float auxiliar;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%f", &auxiliar);
    return auxiliar;
}



 /*
  * \brief Solicita un numero al usuario de tipo entero y devuelve el resultado
  * \parametro mensaje. Es el mensaje a ser mostrado
  * \Return El numero ingresado por el usuario
  */
int getInt(char mensaje[])
{

    int auxiliar;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%i", &auxiliar);
    return auxiliar;
}


 /*
  * \brief Solicita un caracter al usuario y devuelve el resultado
  * \parametro mensaje. Es el mensaje a ser mostrado
  * \Return El caracter ingresado por el usuario
  */
char getMyChar(char mensaje[]){

    char auxiliar;

    printf(mensaje);
    fflush(stdin);
    scanf("%c", &auxiliar);

    return auxiliar;
}




 /*
  * \brief Guarda la cadena de caracteres ingresada por teclado
  * \parametro nombre: array de char , cantidad: lenght del array char
  * \Return void
  */
void myFgets(char nombre[], int cantidad){

    fflush(stdin);
    fgets(nombre, cantidad-1, stdin);

    
}











