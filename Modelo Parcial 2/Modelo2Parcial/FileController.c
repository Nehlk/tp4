#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Vehiculos.h"






/** \brief Parsea los datos  de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*  ubicacion del archivo
 * \param  pListDominio LinkedList* puntero a la lista
 * \return int
 *
 */
int parser_FromText(FILE* pFile, LinkedList* pListDominio)
{

    eDominio* auxDominio;   //Cambiar en el parcial por el nombre que sea acorde

    char id[10];
    char dominio[50];
    char agno[10];       //Las variables tambien, cambiar


    fscanf(pFile, "%[^,], %[^,], %[^\n]\n", id, dominio, agno);

    do
    {
        fscanf(pFile, "%[^,], %[^,], %[^\n]\n", id, dominio, agno);


        auxDominio = dom_newParametros(id, dominio, agno);

        ll_add(pListDominio, auxDominio);      //recordar aca poner parametro correcto de Lista

    }
    while(!feof(pFile));


    return 0;
}






/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*  ubicacion del archivo
 * \param  pListDominio LinkedList* puntero a la lista
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pListDominio)
{
    FILE* pFile;

    system("cls");

    if(pListDominio != NULL)
    {
        ll_clear(pListDominio);
        printf("\nList cleared");


        if ( (pFile = fopen(path,"r+") ) != NULL ) // Si la carga de archivos es diferente a NULL, abre..
        {
            pFile = fopen(path, "r+");

            parser_FromText(pFile, pListDominio);

            printf("\n\n Carga modo Texto OK.");

        }
        else
        {
            printf("\n\nNo se pudo realizar la carga.");
        }
    }





    fclose(pFile);

    return 0;
}



/** \brief Imprime por pantalla los elementos de la lista
 *
 * \param pListDominio LinkedList* puntero a la lista
 * \return int: -1 si la lista es NULL
 *               0 si todo ok.
 */
int controller_showList(LinkedList* pListDominio)
{
    int returnAux = -1;
    int a;

    eDominio* auxDom = NULL;


    if(pListDominio != NULL && ll_len(pListDominio) != NULL)
    {
        system("cls");

        for(a = 0; a < ll_len(pListDominio); a++)
        {
            auxDom = ll_get(pListDominio, a);
            if(auxDom->tipo == 'A' || auxDom->tipo == 'M')
            {
                printf("\n%i, %s, %i, %c", dom_getId(auxDom), auxDom->dominio, dom_getAgno(auxDom), dom_getTipo(auxDom));
            }else{
                printf("\n%i, %s, %i", dom_getId(auxDom), auxDom->dominio, dom_getAgno(auxDom));
            }


        }
        returnAux = 0;
    }
    else{
        system("cls");
        printf("\n\nLa lista Esta vacia");
    }
    return returnAux;
}



int controller_mappedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = 0;

        ll_map(this, dom_mapTipo);
    }

    return returnAux;
}


LinkedList* controller_ListaMotos(LinkedList* this)
{
    LinkedList* listaMotos;

    if(this != NULL)
    {
        listaMotos = ll_filter(this, filtrarMotos);
        controller_showList(listaMotos);
    }

    return listaMotos;
}


LinkedList* controller_ListaAutos(LinkedList* this)
{
    LinkedList* listaAutos;

    if(this != NULL)
    {
        listaAutos = ll_filter(this, filtrarAutos);
        controller_showList(listaAutos);
    }
    return listaAutos;
}



/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int length = ll_len(pArrayListEmployee);
    int a;      //variable for


    eDominio* auxDom;      //Cambiar nombre y tipo de variable en el examen

    FILE* archivo;

    system("cls");

    if ( (archivo = fopen(path,"w+")) == NULL )

    {
        printf("No se pudo abrir el archivo");
        exit(1);
    }
    else
    {
        archivo = fopen(path, "r+");
    }

    fprintf(archivo, "%s,%s,%s,%s\n", "id", "nombre", "horasTrabajadas" , "sueldo");
    for(a = 0; a < length; a++)
    {
        auxDom = ll_get(pArrayListEmployee, a);

        fseek(archivo, 0L, SEEK_END);

        fprintf(archivo, "%i,%s,%i,%c\n", dom_getId(auxDom), auxDom->dominio, dom_getAgno(auxDom), dom_getTipo(auxDom));
    }

    ll_clear(pArrayListEmployee);
    printf("\nArchivo Guardado en modo texto correctamente.");
    fclose(archivo);

    return 0;
}

