#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Vehiculos.h"
#include <string.h>


/**
 * @brief Asigna memoria dinamica
 * @param void
 * @return this
 */
eDominio* dominio_new()
{

    eDominio* this = malloc(sizeof(eDominio));

    return this;
}


/**
 * @brief asigna el campo Id a un elemento eDominio
 * @param this: puntero a la lista
 * @param id: valor a asignar al campo ID
 * @return      -1: si la lista es NULL
 *               0: si todo ok.
 */
int dom_setId(eDominio* this, int id)
{
    int returnAux = -1;

    if(this != NULL && id >= 0)
    {
        this->id = id;
        returnAux = 0;
    }
    return returnAux;
}


int dom_getId(eDominio* this)
{
    return this->id;
}



/**
 * @brief asigna el campo Dominio a un elemento eDominio
 * @param this: puntero a la lista
 * @param dominio: valor a asignar al campo del elemento
 * @return      -1: si la lista es NULL
 *               0: si todo ok.
 */
int dom_setDominio(eDominio* this, char* dominio)
{
    int returnAux = -1;

    if(this != NULL)
    {
        strcpy(this->dominio, dominio);
        returnAux = 0;
    }
    return returnAux;

}

/** @brief Obtiene el Dominio de un vehiculo.
 *
 * @param this eDominio: dominio
 * @param char* output: dom
 * @return int retorno -1 si this es NULL o nombre es NULL
 *                      0: si todo ok.
 *
 */
int dom_getDominio(eDominio* this, char* output)
{
    int returnAux = -1;
    if(this != NULL && output != NULL)
    {
        strcpy(output, this->dominio);
        returnAux = 0;
    }
    return returnAux;
}


/**
 * @brief asigna el campo agno a un elemento eDominio
 * @param this: puntero a la lista
 * @param agno: valor a asignar al campo del elemento
 * @return      -1: si la lista es NULL
 *               0: si todo ok.
 */
int dom_setAgno(eDominio* this, int agno)
{
    int returnAux = -1;

    if(this != NULL && agno >= 1930 && agno <= 2019)
    {
        this->agno = agno;
        returnAux = 0;
    }
    return returnAux;
}



int dom_getAgno(eDominio* this)
{
    return this->agno;
}


/**
 * @brief asigna el campo tipo a un elemento eDominio
 * @param this: puntero a la lista
 * @param tipo: valor a asignar al campo del elemento
 * @return      -1: si la lista es NULL
 *               0: si todo ok.
 */
int dom_setTipo(eDominio* this, char tipo)
{
    int returnAux = -1;
    char tipoAux = toupper(tipo);

    if(this != NULL && (tipo == 'M' || tipo == 'A'))
    {
        this->tipo = tipoAux;
        returnAux = 0;
    }
    return returnAux;
}




char dom_getTipo(eDominio* this)
{
    return this->tipo;
}


/**
 * @brief asigna los campos Id, Dominio, Agno a un elemento eDominio y lo retorna
 * @param IdStr: valor a asignar al campo del elemento
 * @param dominioStr: valor a asignar al campo del elemento
 * @param agnoStr: valor a asignar al campo del elemento
 * @return      auxDominio: puntero de eDominio
 */
eDominio* dom_newParametros(char* idStr, char* dominioStr, char* agnoStr)
{
    int id, agno;

    id = atoi(idStr);
    agno = atoi(agnoStr);

    eDominio* auxDominio = NULL;

    auxDominio = dominio_new();

    dom_setId(auxDominio, id);
    dom_setAgno(auxDominio, agno);
    dom_setDominio(auxDominio, dominioStr);

    return auxDominio;
}



void dom_mapTipo(void* pDominio)
{
    char aux[10];

    if(pDominio != NULL)
    {
        dom_getDominio(pDominio, aux);

        if(aux[0] < '0' || aux[0] > '9') {
            dom_setTipo(pDominio, 'A');
        }else{
            dom_setTipo(pDominio, 'M');
        }
    }
}




int filtrarMotos(void* p)
{
    int ok = 0;
    eDominio* domAux;

    if(p != NULL )
    {
        domAux = (eDominio*) p;
        if(domAux->tipo == 'M')
        {
            ok = 1;
        }
    }
    return ok;
}



int filtrarAutos(void* p)
{
    int ok = 0;
    eDominio* domAux;

    if(p != NULL )
    {
        domAux = (eDominio*) p;
        if(domAux->tipo == 'A')
        {
            ok = 1;
        }
    }
    return ok;
}