#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include "validaciones.h"




int getInt(char *msj, char *errorMsj, int minimo, int maximo, int *input)
{
    int retorno = -1;

    if(msj != NULL && errorMsj != NULL && input != NULL && maximo >= minimo )
    {
            printf("%s", msj);
            fflush(stdin);
            scanf("%d", input);

            intIsValid(*input, minimo, maximo, errorMsj);
    }
    return retorno;
}





int getFloat(char *msj, char *errorMsj, float minimo, float maximo, float *input)
{
    int retorno = -1;

    if(msj != NULL && errorMsj != NULL &&  maximo >= minimo && input != NULL )
    {
            printf("%s", msj);
            fflush(stdin);
            scanf("%f", input);
            floatIsValid(*input, "Error, Reingrese el valor", minimo, maximo );

    }
    return retorno;
}




/*
int getChar(char *msj, char *errorMsj, char minimo, char maximo, int reintentos, char *resultado)
{
    char buffer;
    int retorno = -1;
    if(msj != NULL && errorMsj != NULL && resultado != NULL && maximo >= minimo && reintentos >= 0)
    {
        do
        {
            printf("%s", msj);
            fflush(stdin);//
            //__fpurge(stdin);
            scanf("%c", &buffer);
            if(isValidChar(buffer, minimo, maximo))
            {
                *resultado = buffer;
                retorno = 0;
                break;
            }else
            {
                printf("%s", errorMsj);
            }
            reintentos--;
        }while(reintentos >= 0);
    }
    return retorno;
}

*/












int getString(char* msj, char* errorMsj, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msj != NULL && errorMsj != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {

        do
        {
            printf("%s",msj);
            //__fpurge(stdin);
            fflush(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1] = '\0';
            if(strlen(bufferStr)>=minimo && strlen(bufferStr) <maximo)
            {
                strncpy(resultado,bufferStr,maximo);
                retorno = 0;
                break;
            }
            reintentos--;
            printf("%s",errorMsj);
        }while(reintentos>=0);
    }
    return retorno;
}












/*
int getApellido (char* msj, char* errorMsj, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msj != NULL && errorMsj != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
            if(!getString(msj,errorMsj,minimo,maximo,reintentos,bufferStr))
            {
                if(isValidApellido(bufferStr))
                {
                    strncpy(resultado, bufferStr,maximo);
                    retorno = 0;
                }
                else
                {
                    printf (errorMsj);
                    reintentos--;
                }
            }
    }
    return retorno;
}

*/






/*
int getAlfanumerico(char* msj, char* msjError, int minSize, int maxSize, int reintentos, char* resultado)//patente
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msj!=NULL && msjError!=NULL && minSize<maxSize && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!getString(msj,msjError,minSize,maxSize,reintentos,bufferStr)) //==0 sin errores !0
            {
                if(isValidAlphanumeric(bufferStr)==1)
                {
                    strncpy(resultado,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",msjError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

*/





/*
int getFecha (char* msj, char* msjError, int minimo, int maximo, int reintentos, char *resultado)
{
    char buffer[30];
    int retorno=-1;

   if(msj != NULL && msjError != NULL && minimo<maximo && reintentos>=0 && resultado != NULL)
    {
        do
        {
            if(! getString(msj, msjError, minimo, maximo, reintentos, buffer))
            {

                if(isValidFecha(buffer)==1)
                {
                    strncpy(resultado,buffer,sizeof(buffer));
                    retorno=0;
                    break;
                }
                else
                {
                    printf("Fecha de Nacimiento invalida");
                    reintentos --;
                }
            }
            else
            {
                printf("%s",msjError);
                break;
            }

        }while(reintentos>=0);
    }
    return retorno;
}
*/
