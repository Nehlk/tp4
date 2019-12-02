#include <stdio.h>
#include <stdlib.h>

#include "clientes.h"

#define MAXCLIENTES 10
#define ALQUILERES 60

int main()
{   
    eCliente cliente[MAXCLIENTES];


    eAlquileres alquileres[ALQUILERES];

    // Hardcodeo de estructura eJuegos
    eJuegos juegos[6] = { {1, "Grand Thef Auto", 999.99}, 
                          {2, "Call of Duty", 679.99},
                          {3, "Medal of Honor", 500},
                          {4, "Age Of Empires", 249.99},
                          {5, "Rust", 799.99},
                          {6, "Dead By Daylight", 234.99}   };
    
    _Init(cliente, MAXCLIENTES, juegos, 6, alquileres, ALQUILERES);


    return 0;
}
