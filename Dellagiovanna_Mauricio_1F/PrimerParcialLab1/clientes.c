#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#include "clientes.h"
#include "validaciones.h"
#include "utn.h"


int contadorClientesAlta = 0;
int codCliente = 0;             //Determina el ultimo codigo de cliente asignado


 /*
  * \brief Asigna Valores a los dif campos de la esctructura cliente
  * \parametro cliente: array, cantidad: maximo de array
  * \Return void
  */
void altaCliente(eCliente cliente[], int cantidad)
{

    int i; //variable recorrido For()

    char ingresar = 'S';

    system("cls");



    while(ingresar == 'S')
    {

        for(i = 0; i < cantidad; i++)
        {
          if(cliente[i].isEmpty == 1)
          {
            printf("\nIngrese Nombre de Cliente: ");
            myFgets(cliente[i].nombre, 31);
            stringIsValid(cliente[i].nombre, 31);


            printf("\nIngrese Apellido: ");
            myFgets(cliente[i].apellido, 31);
            stringIsValid(cliente[i].apellido, 31);



            cliente[i].sexo = getMyChar("\nIngrese Sexo f/m: ");
            sexIsValid(cliente[i].sexo);


            printf("\nIngrese Domicilio: ");
            myFgets(cliente[i].domicilio, 51);
            stringIsValid(cliente[i].domicilio, 51);


            printf("\nIngrese Telefono: ");
            myFgets(cliente[i].telefono, 21);
            stringIsValid(cliente[i].telefono, 21);

            cliente[i].codigoCliente = codCliente + 1;
            codCliente = cliente[i].codigoCliente;

            cliente[i].isEmpty = 0;
            break;
          }//fin If
        }//fin For()

        contadorClientesAlta++ ;

    if(contadorClientesAlta < cantidad)
    {
        do{
            printf("\nDar de alta otro Cliente? s/n \n");
            ingresar = toupper(getch());

        }while(ingresar != 'S' && ingresar != 'N');
    }
    else{
        break; //Corta con el Alta cuando el contador supera los clientes dados de alta
    }
    }//Fin While()

}




 /*
  * \brief se da por teclado el numero de cliente y se da
  *        un menu con opciones para la modificacion del mismo
  *        (Tira alerta en caso que no haya clientes dados de alta)
  * \parametro cliente: array, cantidad: maximo de array
  * \Return void
  */
void modificarCliente(eCliente cliente[], int cantidad)
{
    int i;              //variable recorrido For()
    int auxCodCliente;  //referencia un auxiliar al codigo del cliente

    int contador = 0;   // contador de Clientes dados de alta

    int opcion;        //opcion de modificacion para el switch

    for(i = 0; i < cantidad; i++)
    {
        if(cliente[i].isEmpty == 0)
        {
            contador++ ;
        }
    }


    if( contador > 0)
    {
        auxCodCliente = getInt("\nIngrese el Codigo de Cliente a Modificar: ");

        for(i = 0; i < cantidad; i++)
        {
            if(cliente[i].codigoCliente == auxCodCliente)
            {
                system("cls");

                printf("\n\n\n1- Modificar Nombre ");
                printf("\n2- Modificar Apellido ");
                printf("\n3- Modificar Sexo ");
                printf("\n4- Modificar Domicilio ");
                printf("\n5- Modificar Telefono ");


                printf("\n\n\n0- Salir ");

                opcion = getInt("\n  Opcion -->  ");

                switch(opcion)
                {
                    case 1:
                            printf("\nIngrese Nombre: ");
                            myFgets(cliente[i].nombre, 31);
                        break;

                    case 2: printf("\nIngrese Apellido: ");
                            myFgets(cliente[i].apellido, 31);
                        break;

                    case 3: cliente[i].sexo = getMyChar("\nIngrese Sexo: ");
                        break;

                    case 4: printf("\nIngrese Domicilio");
                            myFgets(cliente[i].domicilio, 51);
                        break;

                    case 5: printf("\nIngrese Telefono: ");
                            myFgets(cliente[i].telefono, 21);
                        break;

                    case 0: break;


                }//Fin switch

            }//Fin IF

        }//Fin For

    }//Fin if contador

    else{
        printf("\nAun no hay Clientes registrados\n\n\n");
    }


}



/*
  * \brief se da por teclado el numero de cliente y se da
  *        de baja el mismo
  *        (Tira alerta en caso que no haya clientes dados de alta)
  * \parametro cliente: array, cantidad: maximo de array
  * \Return void
  */
void bajaCliente(eCliente cliente[], int cantidad)
{
    int i;
    int auxCodClient;
    int contador = 0;

    system("cls");
    for ( i = 0; i < cantidad; i++)
    {
        if (cliente[i].isEmpty == 0)
        {
            contador ++;
        }

    }


    if(contador > 0)
    {
        auxCodClient = getInt("\nIngrese el Codigo de Cliente a Eliminar: ");

        for ( i = 0; i < cantidad; i++)
        {
            if(cliente[i].codigoCliente == auxCodClient)
            {
                cliente[i].isEmpty = 1;
            }

        }// Fin For()

    }//Fin IF()
    else{
        printf("\nAun no hay Clientes dados de Alta \n\n");
    }

}



/*
  * \brief Ordena la estructura eCliente por los campos Apellido y nombre
  * \parametro cliente: array, cantidad: maximo de array
  * \Return void
  */
void ordenamientoPorApellidoYNombre(eCliente cliente[], int cantidad)
{
   eCliente auxClien;   //Auxiliar eCliente
   int i, k;            //variables recorrido For()

   for ( i = 0; i < cantidad - 1; i++)
   {
       for ( k = i +1 ; k < cantidad; k++)
       {
           if ( strcmpi(cliente[i].apellido, cliente[k].apellido) == 0 )
           {
               if (strcmpi(cliente[i].nombre, cliente[k].nombre) > 0 )
               {
                     auxClien = cliente[i];
                     cliente[i] = cliente[k];
                     cliente[k] = auxClien;
               }

           }

           else if ( strcmpi(cliente[i].apellido, cliente[k].apellido)  > 0 )
           {
                 auxClien = cliente[i];
                 cliente[i] = cliente[k];
                 cliente[k] = auxClien;
           }

       }

   }

}



/*
  * \brief Lista todos los campos de un solo cliente
  * \parametro cliente
  * \Return void
  */
void listarCliente(eCliente cliente)
{

    printf("\n\n Nombre: %s Apellido: %s Sexo: %c\n Domicilio: %s Telefono: %s Codigo Cliente: %i ",
    cliente.nombre, cliente.apellido, cliente.sexo, cliente.domicilio, cliente.telefono, cliente.codigoCliente);
}




/*
  * \brief Lista los campos de los clientes existentes
  *        (Tira alerta en caso que no haya clientes dados de alta)
  * \parametro cliente: array, cantidad: maximo de array
  * \Return void
  */
void listarTodosLosClientes(eCliente cliente[], int cantidad )
{
    int i;
    int contador = 0;

    for ( i = 0; i < cantidad; i++)
    {
        if (cliente[i].isEmpty == 0)
        {
            contador++ ;
        }

    }

    if(contador > 0)
    {
        ordenamientoPorApellidoYNombre(cliente, cantidad);

        system("cls");

        for ( i = 0; i < cantidad; i++)
         {
             if (cliente[i].isEmpty == 0)
             {
                 listarCliente(cliente[i]);
             }

         }//Fin for

        printf("\n\n\n");
    }//Fin if
    else{
        printf("\nAun no hay Clientes dados de Alta \n\n");
    }
}



/*
  * \brief Menu de opciones Alta Baja Modificar y listado de
  *        clientes
  * \parametro cliente: array, cantidad: maximo de array
  * \Return void
  */
void menuClientes(eCliente cliente[], int cantidad)
{
    int opcion;
    char seguir = 'S';

    while(seguir == 'S')
    {

     printf("\n1- Dar de Alta un Cliente ");
     printf("\n2- Dar de Baja un Cliente ");
     printf("\n3- Modificar un Cliente ");
     printf("\n4- Listar Cliente ");
     printf("\n\n0- Salir ");

     opcion = getInt("\n\n Opcion --> ");

        switch (opcion)
        {
            case 1: altaCliente(cliente, cantidad); seguir = 'S'; break;

            case 2: bajaCliente(cliente, cantidad); seguir = 'S'; break;

            case 3: modificarCliente(cliente, cantidad); seguir = 'S'; break;

            case 4: listarTodosLosClientes(cliente, cantidad); seguir = 'S'; break;



            case 0: seguir = 'N';
                break;

        }//Fin switch

    }//Fin While
}


/* ------------------- JUEGOS ----------------------- */



 /*
  * \brief Ordena la estructura eJuegos por Descripcion (ascendente)
  * \parametro Juegos: array, cantidad: maximo de array
  * \Return void
  */
void ordenarJuegosPorNombre(eJuegos juegos[], int cantidad)
{
    eJuegos auxJuegos;      //Variable auxiliar para ordenar juegos
    int i, k;               //Variables Recorrido For()

    for ( i = 0; i < cantidad - 1; i++)
   {
       for ( k = i +1 ; k < cantidad; k++)
       {

         if (strcmpi(juegos[i].descripcion, juegos[k].descripcion) > 0 )
           {
                 auxJuegos = juegos[i];
                 juegos[i] = juegos[k];
                 juegos[k] = auxJuegos;
           }
        }//Fin For(k)

    }//fin For(i)
}



 /*
  * \brief Lista los campos de un Juego
  * \parametro Juegos: estructura
  * \Return void
  */
void listarUnJuego(eJuegos juego)
{
    printf("\n\nCodigo de Juego: %i \nDescripcion: %s \nImporte: $%.2f",
            juego.codigoJuego, juego.descripcion, juego.importe);

}



 /*
  * \brief Lista todos los campos de un array de Juegos
  * \parametro Juegos: array, cantidad: maximo de array
  * \Return void
  */
void listarJuegos(eJuegos juegos[], int cantidadJuegos)
{
   int i;        // Variables recorrido For()
    system("cls");

   ordenarJuegosPorNombre(juegos, cantidadJuegos);
   for(i = 0; i < cantidadJuegos; i++)
   {
       listarUnJuego(juegos[i]);
   }

   printf("\n\n\n");
}


/* ----------------- ALQUILERES --------------------- */


int codAlquiler = 0;



 /*
  * \brief Se llenan campos de la estructura Alquiler
  * \parametro Juegos: array, cantJuegos: maximo de array,
  *             cliente: array, cantCliente: maximo de array
  *             alquileres: array, cantALquileres: maximo array
  * \Return void
  */

void altaAlquileres(eAlquileres alquileres[], int cantAlquileres, eCliente clientes[], int cantClientes, eJuegos juegos[], int cantJuegos)
{
    int i, k; //variable recorrido For()

    char ingresar = 'S';

   system("cls");

    while(ingresar == 'S')
    {

        for(i = 0; i < cantAlquileres; i++)
        {
            if (alquileres[i].isEmpty == 1)
            {


                for ( k = 0; k < cantJuegos; k++)
                 {
                    printf("\n%i - %s ", k+1,  juegos[k].descripcion);
                 }

              alquileres[i].codigoJuego = getInt("\nCodigo Juego: ");


              for ( k = 0; k < cantClientes; k++)
              {
                if (clientes[k].isEmpty == 0)
                {
                    printf("\n%i - %s ", clientes[k].codigoCliente,  clientes[k].nombre);
                }

              }

               alquileres[i].codigoCliente = getInt("\nSeleccione Cliente: ");



               alquileres[i].codigoAlquiler = codAlquiler + 1;
               codAlquiler = alquileres[i].codigoAlquiler;


              alquileres[i].fecha.fechaAgno = getInt("\nIntroducir Agno: ");
              yearIsValid(alquileres[i].fecha.fechaAgno);

              alquileres[i].fecha.fechaMes = getInt("\nIntroducir Mes: ");
              monthIsValid(alquileres[i].fecha.fechaMes);

              alquileres[i].fecha.fechaDia = getInt("\nIntroducir Dia: ");
              dayIsValid(alquileres[i].fecha.fechaMes, alquileres[i].fecha.fechaDia);


              alquileres[i].isEmpty = 0;

               break;
            }//Fin if



        }//fin For()




        do{
            printf("\nDar de alta otro Alquiler? s/n\n");
            ingresar = toupper(getch());

        }while(ingresar != 'S' && ingresar != 'N');

    }//Fin While()

}





 /* Ej Nº 9
  * \brief Imprime la cantidad de clientes y sus datos que alquilo uno de los juegos en particular
  * \parametro Juegos: array, cantJuegos: maximo de array,
  *             cliente: array, cantCliente: maximo de array
  *             alquileres: array, cantALquileres: maximo array
  * \Return void
  */
void listadoDeClientesQueAlquilaronJuego(eAlquileres alquileres[], int cantAlquileres, eCliente clientes[], int cantClientes, eJuegos juegos[], int cantJuegos)
{

   int aux;
   int i, k, e;  //variables recorrido For()
   int contador = 0;

    system("cls");
   for ( i = 0; i < cantClientes; i++)
   {
       if (clientes[i].isEmpty == 0)
       {
           contador++ ;
       }

   }


    if(contador > 0)
    {
        aux = getInt("\nDigite Codigo del Juego: ");
        for ( i = 0; i < cantJuegos; i++)
        {
            if (aux == juegos[i].codigoJuego)
            {
                for ( k = 0; k < cantAlquileres; k++)
                {
                    if (aux == alquileres[k].codigoJuego)
                    {
                        for ( e = 0; e < cantClientes; e++)
                        {
                            if (alquileres[k].codigoCliente == clientes[e].codigoCliente && clientes[e].isEmpty == 0)
                            {
                                printf("\n Cliente: %s Codigo Cliente: %i\n Juego: %s  -- Importe: $%.2f\n Fecha: %i/%i/%i \n",
                                        clientes[e].nombre, alquileres[k].codigoCliente, juegos[i].descripcion, juegos[i].importe,
                                        alquileres[k].fecha.fechaDia, alquileres[k].fecha.fechaMes, alquileres[k].fecha.fechaAgno );

                            }

                        }

                    }

                }

            }

        }

    }else
    {
        system("cls");
        printf("\n\nNo hay Clientes dados de alta");
    }




}






/*Ej Nº 7
  * \brief Recorre los juegos alquilados y almacena un total del importe
  *        / un total de la cantidad / saca un promedio
  * \parametro Juegos: array, cantJuegos: maximo de array,
  *             cliente: array, cantCliente: maximo de array
  *             alquileres: array, cantALquileres: maximo array
  *             char devolver: se ingresa T (total) o P(promedio)
  * \Return  float(segun el char indicado por parametro devuelve o total o promedio)
  */
float promedioJuegosAlquilados(eAlquileres alquileres[], int cantAlquileres, eCliente clientes[],int cantClientes, eJuegos juegos[], int cantJuegos, char devolver)
{

   int i, k;  //variables recorrido For()
   int contador = 0;
   float contadorJuegos = 0;
   float contadorImporteJuegos = 0;
   float promedio;

    //system("cls");
   for ( i = 0; i < cantClientes; i++)
   {
       if (clientes[i].isEmpty == 0)
       {
           contador++ ;
       }

   }


    if(contador > 0)
    {
       for(i = 0; i < cantAlquileres; i++)
       {
           if(alquileres[i].isEmpty == 0)
           {
               for(k = 0; k < cantJuegos; k++)
               {
                   if(alquileres[i].codigoJuego == juegos[k].codigoJuego)
                   {
                       contadorJuegos++ ;
                       contadorImporteJuegos += juegos[k].importe;
                   }
               }
           }
       }//fin For(i)

       promedio = contadorImporteJuegos / contadorJuegos;



       if(devolver == 'p')
       {
           return promedio;
       }
       else if(devolver == 't'){
           return contadorImporteJuegos;
       }

    }
}



 /*Ej Nº 7
  * \brief Imprime por pantalla el promedio y el total de importes de
  *         juegos alquilados y lo imprime por pantalla
  * \parametro Juegos: array, cantJuegos: maximo de array,
  *             cliente: array, cantCliente: maximo de array
  *             alquileres: array, cantALquileres: maximo array
  *             char devolver: se ingresa T (total) o P(promedio)
  * \Return  float(segun el char indicado por parametro devuelve o total o promedio)
  */
void promedioJuegosAlq(eAlquileres alquileres[], int cantAlquileres, eCliente clientes[],int cantClientes, eJuegos juegos[], int cantJuegos)
{
    float promedioGames = promedioJuegosAlquilados( alquileres, cantAlquileres, clientes, cantClientes, juegos, cantJuegos, 'p');
    float totalImportes = promedioJuegosAlquilados( alquileres, cantAlquileres, clientes, cantClientes, juegos, cantJuegos, 't');

    system("cls");

       printf("\nTotal del Importe de juegos Alquilados: %.2f", totalImportes);
       printf("\nPromedio del Importe de juegos Alquilados: %.2f", promedioGames);
}



 /*Ej Nº 8
  * \brief Imprime por pantalla la cantdidad de juegos que no superan el promedio
  *         de importe del item Nº 7
  * \parametro Juegos: array, cantJuegos: maximo de array,
  *             cliente: array, cantCliente: maximo de array
  *             alquileres: array, cantALquileres: maximo array
  *             char devolver: se ingresa T (total) o P(promedio)
  * \Return  float(segun el char indicado por parametro devuelve o total o promedio)
  */
void juegosQueNoSuperanImportes(eAlquileres alquileres[], int cantAlquileres, eCliente clientes[],int cantClientes, eJuegos juegos[], int cantJuegos)
{
    int i, k;  //variables recorrido For()
    int contador = 0;       //Contador clientes dados de alta
    int cantidadGames = 0;  //Contador de juegos que no superan promedio

    float promedioGames = promedioJuegosAlquilados( alquileres, cantAlquileres, clientes, cantClientes, juegos, cantJuegos, 'p');


    system("cls");
   for ( i = 0; i < cantClientes; i++)
   {
       if (clientes[i].isEmpty == 0)
       {
           contador++ ;
       }

   }


    if(contador > 0)
    {
       for(i = 0; i < cantAlquileres; i++) //recorre los alquileres
       {
           if(alquileres[i].isEmpty == 0) //consulta si los alquileres no estan vacios
           {
               for(k = 0; k < cantJuegos; k++) //recorre los juegos
               {

                   if(juegos[k].importe < promedioGames)
                   {
                       cantidadGames++ ;
                   }

               }
           }
       }//fin For(i)


       printf("\nLa cantidad de Juegos que no superan el promedio de importe es de: %i", cantidadGames);




    }else
    {
        system("cls");
        printf("\n\nNo hay Clientes dados de alta");
    }
}





/* Ej Nº 10
  * \brief Imprime la cantidad de juegos que alquilo un cliente en particular
  * \parametro Juegos: array, cantJuegos: maximo de array,
  *             cliente: array, cantCliente: maximo de array
  *             alquileres: array, cantALquileres: maximo array
  * \Return void
  */
void listadoDeJuegosPorCliente(eAlquileres alquileres[], int cantAlquileres, eCliente clientes[], int cantClientes, eJuegos juegos[], int cantJuegos)
{

   int auxCliente;
   int i, k, e;  //variables recorrido For()
   int contador = 0;

    system("cls");
   for ( i = 0; i < cantClientes; i++)
   {
       if (clientes[i].isEmpty == 0)
       {
           contador++ ;
       }

   }


    if(contador > 0)
    {
        auxCliente = getInt("\nDigite Codigo del Cliente: ");

        printf("\nCliente: %i - %s", auxCliente, clientes[auxCliente].nombre);

        for ( i = 0; i < cantClientes; i++)//recorro clientes
        {
            if (auxCliente == clientes[i].codigoCliente && clientes[i].isEmpty == 0)
            {
                for ( k = 0; k < cantAlquileres; k++) // recorro alquileres
                {


                        for ( e = 0; e < cantJuegos; e++) //recorro juegos
                        {
                            if (alquileres[k].codigoJuego == juegos[e].codigoJuego && alquileres[k].isEmpty == 0)
                            {
                                printf("\n Game: %s -- Importe: $%.2f\n Fecha: %i/%i/%i \n",
                                        juegos[e].descripcion, juegos[k].importe,
                                        alquileres[k].fecha.fechaDia, alquileres[k].fecha.fechaMes, alquileres[k].fecha.fechaAgno );

                            }

                        }



                }

            }

        }

    }else
    {
        system("cls");
        printf("\n\nNo hay Clientes dados de alta");
    }




}




/* Ej Nº 12
  * \brief Imprime el cliente con mas alquileres
  * \parametro Juegos: array, cantJuegos: maximo de array,
  *             cliente: array, cantCliente: maximo de array
  *             alquileres: array, cantALquileres: maximo array
  * \Return void
  */
void clientesConMasAlquileres(eAlquileres alquileres[], int cantAlquileres, eCliente clientes[], int cantClientes, eJuegos juegos[], int cantJuegos)
{
    int i, k;
    int contador = 0;
    int maximo = 0;


   system("cls");
   for ( i = 0; i < cantClientes; i++)
   {
       if (clientes[i].isEmpty == 0)
       {
           contador++ ;
       }

   }

   if(contador > 0)
   {

       for(i = 0; i < cantClientes; i++)//recorro clientes
       {
           if(clientes[i].isEmpty == 0 )//Pregunto que no este vacio
           {
               for(k = 0; k < cantAlquileres; k++)//recorro la cantidad de alquileres
               {
                    if (alquileres[k].codigoJuego == juegos[i].codigoJuego && alquileres[k].isEmpty == 0)
                    {
                        maximo++;

                    }


               }
           }
       }


   // printf("\nTotal  cliente con mas alquileres: %s", clientes[maximo].nombre);

   }
   else{
        system("cls");
        printf("\n\nNo hay Clientes dados de alta");
   }

}





 /* Ej Nº 9
  * \brief Imprime los juegos alquilados en una fecha determinada
  * \parametro Juegos: array, cantJuegos: maximo de array,
  *             cliente: array, cantCliente: maximo de array
  *             alquileres: array, cantALquileres: maximo array
  * \Return void
  */
void juegosPorFechaDeterminada(eAlquileres alquileres[], int cantAlquileres, eCliente clientes[], int cantClientes, eJuegos juegos[], int cantJuegos)
{

   int aux;
   int i, k, e;  //variables recorrido For()
   int contador = 0;

    system("cls");
   for ( i = 0; i < cantClientes; i++)
   {
       if (clientes[i].isEmpty == 0)
       {
           contador++ ;
       }

   }


    if(contador > 0)
    {
        aux = getInt("\nDigite dia: ");
        for ( i = 0; i < cantAlquileres; i++)//recorro alquileres
        {
            if (aux == alquileres[i].fecha.fechaDia && alquileres[i].isEmpty == 0) //pregunto fecha
            {
                for ( k = 0; k < cantClientes; k++)
                {
                    if ( alquileres[i].codigoCliente == clientes[k].codigoCliente && clientes[e].isEmpty == 0)
                    {
                        for ( e = 0; e < cantClientes; e++)
                        {
                            if (alquileres[k].codigoJuego == juegos[e].codigoJuego )
                            {
                                printf("\n Game: %s -- Importe: $%.2f\n Fecha: %i/%i/%i \n",
                                        juegos[e].descripcion, juegos[k].importe,
                                        alquileres[k].fecha.fechaDia, alquileres[k].fecha.fechaMes, alquileres[k].fecha.fechaAgno );

                            }

                        }

                    }

                }

            }

        }

    }else
    {
        system("cls");
        printf("\n\nNo hay Clientes dados de alta");
    }




}




/* Ej Nº 15
  * \brief ordena un array de juegos por importe de forma descendente
  * \parametro Juegos: array, cantJuegos: maximo de array,
  *
  * \Return void
  */
void ordenamientoPorImporte(eJuegos juegos[], int cantidad)
{
    eJuegos auxJuegos;      //Variable auxiliar para ordenar juegos
    int i, k;               //Variables Recorrido For()

    for ( i = 0; i < cantidad - 1; i++)
   {
       for ( k = i +1 ; k < cantidad; k++)
       {

         if (juegos[i].importe < juegos[k].importe )
           {
                 auxJuegos = juegos[i];
                 juegos[i] = juegos[k];
                 juegos[k] = auxJuegos;
           }
        }//Fin For(k)

    }//fin For(i)
}



/* Ej Nº 15
  * \brief ordena un array de juegos por importe de forma descendente
  * \parametro Juegos: array, cantJuegos: maximo de array
  * \Return void
  */
void listarJuegosPorImportes(eJuegos juegos[], int cantidadJuegos)
{
    int i;        // Variables recorrido For()
    system("cls");

   ordenamientoPorImporte(juegos, cantidadJuegos);
   for(i = 0; i < cantidadJuegos; i++)
   {
       listarUnJuego(juegos[i]);
   }

   printf("\n\n\n");
}






/* Ej Nº 16
  * \brief ordena un array de clientes por apellido de forma descendente
  * \parametro clientes: array, cantCliente: maximo de array
  * \Return void
  */
void listarClientesPorApellido(eCliente cliente[], int cantCliente)
{
    int i;
    int contador = 0;

    for ( i = 0; i < cantCliente; i++)
    {
        if (cliente[i].isEmpty == 0)
        {
            contador++ ;
        }

    }

    if(contador > 0)
    {
        //ordenamientoApellidosClientes(cliente, cantCliente);

        system("cls");

        for ( i = 0; i < cantCliente; i++)
         {
             if (cliente[i].isEmpty == 0)
             {
                 listarCliente(cliente[i]);
             }

         }//Fin for

        printf("\n\n\n");
    }//Fin if
    else{
        printf("\nAun no hay Clientes dados de Alta \n\n");
    }
}



 /*
  * \brief Menu de Informes
  * \parametro Juegos: array, cantJuegos: maximo de array,
  *             cliente: array, cantCliente: maximo de array
  *             alquileres: array, cantALquileres: maximo array
  * \Return void
  */
void menuInforme(eAlquileres alquileres[], int cantAlquileres, eCliente clientes[], int cantClientes, eJuegos juegos[], int cantJuegos)
{
    int opcion;
    char continuar = 'S';

    printf("\n\n1- Datos Alquileres ");
    printf("\n2- Promedio y Total de importe juegos Alquilados ");
    printf("\n3- Juegos Que no superan el Importe Promedio ");
    printf("\n4- Listar que Juegos Alquilo un Cliente ");
    printf("\n5- Cliente con Mas Alquileres ");
    printf("\n6- Lista de Juegos por Importe (Descendente) ");
    printf("\n7- Lista de Clientes por Apellido (Descendente) ");
    printf("\n8- Juegos por Fecha determinada ");

    printf("\n0- Salir ");

    while (continuar == 'S')
    {
        opcion = getInt("\n\n Opcion (0- para salir): ");
        switch (opcion)
        {
        case 1: listadoDeClientesQueAlquilaronJuego(alquileres, cantAlquileres, clientes, cantClientes, juegos, cantJuegos); continuar = 'S';
            break;

        case 2: promedioJuegosAlq(alquileres, cantAlquileres, clientes, cantClientes, juegos, cantJuegos); continuar = 'S';
            break;

        case 3: juegosQueNoSuperanImportes(alquileres, cantAlquileres, clientes, cantClientes, juegos, cantJuegos); continuar = 'S';
            break;

        case 4: listadoDeJuegosPorCliente(alquileres, cantAlquileres, clientes, cantClientes, juegos, cantJuegos); continuar = 'S';
            break;

        case 5: clientesConMasAlquileres(alquileres, cantAlquileres, clientes, cantClientes, juegos, cantJuegos); continuar = 'S';
            break;

        case 6: listarJuegosPorImportes(juegos, cantJuegos); continuar = 'S';
            break;

        case 7: listarClientesPorApellido(clientes, cantClientes); continuar = 'S';
            break;

        case 8: juegosPorFechaDeterminada(alquileres, cantAlquileres, clientes, cantClientes, juegos, cantJuegos); continuar = 'S';
            break;

        case 0: continuar = 'N';
            break;
        }
    }

}










/* --------------------------  MAIN  --------------------------------- */



 /*
  * \brief Menu Inicial con opciones para Clientes y Juegos
  * \parametro Juegos: array, cantidad: maximo de array,
  *             cliente: array, cantidad: maximo de array
  * \Return void
  */
void menuInicial(eCliente cliente[], int cantClientes, eJuegos juegos[], int cantJuegos, eAlquileres alquileres[], int cantAlquileres)
{
     int opcion;
     char continuar = 'S';


    while (continuar == 'S')
    {
         printf("\n1- Menu Clientes ");
         printf("\n2- Listado de Juegos ");
         printf("\n3- Alta alquileres ");
         printf("\n4- Informes ");

         printf("\n\n0- Salir ");
         opcion = getInt("\n  Opcion: ");

         switch(opcion)
         {
             case 1: menuClientes(cliente, cantClientes); continuar = 'S';
                break;

             case 2: listarJuegos(juegos, cantJuegos);  continuar = 'S';
                break;

             case 3: altaAlquileres(alquileres, cantAlquileres, cliente, cantClientes, juegos, cantJuegos); continuar = 'S';
                break;

             case 4: menuInforme(alquileres, cantAlquileres, cliente, cantClientes, juegos, cantJuegos); continuar = 'S';
                break;

             case 0: continuar = 'N';
               break;
         }

    } //fin While()

}






/*
  * \brief Inicializador del programa
  * \parametro Juegos: array, cantidad: maximo de array
  *             cliente: array, cantidad: maximo de array
  * \Return void
  */
void _Init(eCliente cliente[], int cantClientes, eJuegos juegos[], int cantJuegos, eAlquileres alquileres[], int cantAlquileres)
{
    int i;
    system("color f0");

    for(i = 0; i < cantClientes; i ++)
    {
        cliente[i].isEmpty = 1;
    }

    for ( i = 0; i < cantAlquileres; i++)
    {
        alquileres[i].isEmpty = 1;
    }


    menuInicial(cliente, cantClientes, juegos, cantJuegos, alquileres, cantAlquileres);
}
