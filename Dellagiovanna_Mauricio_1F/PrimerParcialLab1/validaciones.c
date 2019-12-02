#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "validaciones.h"




 /*
  * \brief Verifica que la cadena no supere el maximo de caracteres dado
  * \parametro name: array de char , length: lenght del array char
  * \Return void
  */
void stringIsValid(char string[], int cantidad)
{

    if (strlen(string) > cantidad)
    {
        do
        {
            system("cls");
            printf("\nERROR. Reingrese Nuevamente: ");
            scanf("%s", string);
        } while (strlen(string-1) > cantidad);

    }
}




 /*
  * \brief Verifica que el caracter Introducido sea F o M
  *        haciendo referencia al sexo
  * \parametro nombre: char introducido por usuario
  * \Return void
  */
void sexIsValid(char sex)
{
   while(sex != 'f' && sex != 'm')
   {
       system("cls");
       printf("\nError. reingrese Sexo: ");
       scanf("%c", &sex);
   }

}



 /*
  * \brief Verifica que el numero entero sea  mayor a 0
  * \parametro entero: numero de tipo Int
  * \Return void
  */
void intIsValid(int entero)
{
    while(entero < 0)
    {
       system("cls");
       printf("\nError. Reingrese nuevamente: ");
       scanf("%i", &entero);
    }
}


 /*
  * \brief Verifica que el flotante entero sea  mayor a 0
  * \parametro entero: numero de tipo Float
  * \Return void
  */
void floatIsValid(float flotante)
{
    while(flotante < 0)
    {
       system("cls");
       printf("\nError. Reingrese nuevamente: ");
       scanf("%f", &flotante);
    }
}




 /*
  * \brief Verifica el año entre el 1900 como minimo y 2019 como Max
  * \parametro year: numero de tipo Int
  * \Return void
  */
void yearIsValid(int year)
{

    while(year < 1900 || year > 2019)
    {
        system("cls");
       printf("\nError. Reingrese Agno: ");
       scanf("%i", &year);
    }
}




 /*
  * \brief Verifica el mes entre el 1 como minimo y 12 como Max
  * \parametro month: numero de tipo Int
  * \Return void
  */
void monthIsValid(int month)
{
    while(month < 1 || month > 12)
    {
        system("cls");
       printf("\nError. reingrese Mes: ");
       scanf("%i", &month);
    }
}




 /*
  * \brief Verifica el dia para cada tipo de Mes en particular
  *         acorde al mes introducido anteriormente
  * \parametro month: numero de tipo Int, day: numero tipo Int
  * \Return void
  */
void dayIsValid(int month, int day)
{

    switch (month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
             while(day < 1 || day > 31) { printf("\nError. reingrese Dia: "); scanf("%i", &day); }
             break;
        case 2:
             while(day < 1 || day > 28) { printf("\nError. reingrese Dia: "); scanf("%i", &day); }
             break;

        case 4:
        case 9:
        case 6:
        case 11:
             while(day < 1 || day > 30) { printf("\nError. reingrese Dia: "); scanf("%i", &day); }
             break;

    }
}
