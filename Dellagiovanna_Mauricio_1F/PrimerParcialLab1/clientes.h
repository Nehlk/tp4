
typedef struct{

    int fechaAgno; //validar
    int fechaMes;  //validar
    int fechaDia;  //validar
}eFecha;


typedef struct{ //hardcodeado

     int codigoJuego; //Autoincremental (hecho manualmente en hardcode)
     char descripcion[51]; //validado
     float importe; //validado mayor a 0
}eJuegos;


typedef struct{

    char nombre[31];   //validar
    char apellido[31]; //validar
    char sexo;         //validar

    char domicilio[51];//validar
    char telefono[21]; //validar

    int codigoCliente; //Autoincremental

    int isEmpty;


}eCliente;


typedef struct{

    int isEmpty;
    int codigoAlquiler; //Autoincremental
    int codigoJuego;    //Debe existir
    int codigoCliente;  //Debe existir

    eFecha fecha;
}eAlquileres;





void _Init(eCliente cliente[], int cantClientes, eJuegos juegos[], int cantJuegos, eAlquileres alquileres[], int cantAlquileres);
