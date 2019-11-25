#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "input.h"
#include "LinkedList.h"
#include "FileController.h"

#define PATHFILE "datos.csv"

int main()
{
    char continuar = 'S';
    int opcion;

    LinkedList* listaDominios = ll_newLinkedList();




        printf("*********** Bienvenido al programa de Listas ***********");
    do{

        printf("\n\n1 - Cargar datos desde archivo (Modo Texto)");
        printf("\n2 - Listar datos por consola");
        printf("\n3 - Mappear Lista");
        printf("\n4 - Filtrar y Mostrar Lista de Autos");
        printf("\n5 - Filtrar y mostrar Lista de Motos");
        printf("\n6 - Guardar Archivo Autos.csv");
        printf("\n7 * Guardar Archivo Motos.csv");

        getInt("\n\nIngrese opcion:", "\nError.Reingrese Opcion", 0, 7, &opcion);



        switch(opcion)
        {
            case 1:  controller_loadFromText(PATHFILE, listaDominios);
                break;

            case 2: controller_showList(listaDominios);
                break;

            case 3: controller_mappedList(listaDominios);
                break;

            case 4: controller_showList(controller_ListaAutos(listaDominios));
                break;

            case 5: controller_showList(controller_ListaMotos(listaDominios));
                break;

            case 6: controller_saveAsText("Autos.csv", controller_ListaAutos(listaDominios));
                break;

            case 7: controller_saveAsText("Motos.csv", controller_ListaMotos(listaDominios));
                break;

            case 0: continuar = 'N';
                break;
        }

    }while(continuar == 'S');
}
