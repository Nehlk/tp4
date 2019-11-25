#ifndef FILECONTROLLER_H_INCLUDED
#define FILECONTROLLER_H_INCLUDED



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pListDominio);



/** \brief Parsea los datos  de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_FromText(FILE* pFile, LinkedList* pListDominio);


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee);

int controller_showList(LinkedList* pListDominio);


int controller_mappedList(LinkedList* this);

LinkedList* controller_ListaAutos(LinkedList* this);
LinkedList* controller_ListaMotos(LinkedList* this);


#endif // FILECONTROLLER_H_INCLUDED
