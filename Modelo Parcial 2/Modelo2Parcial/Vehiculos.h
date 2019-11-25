#ifndef VEHICULOS_H_INCLUDED
#define VEHICULOS_H_INCLUDED



typedef struct{

    int  id;
    char dominio[10];
    int  agno;
    char tipo;
}eDominio;



eDominio* dominio_new();
eDominio* dom_newParametros(char* idStr, char* dominioStr, char* agnoStr);


int dom_setId(eDominio* this, int id);
int dom_setDominio(eDominio* this, char* dominio);
int dom_setAgno(eDominio* this, int agno);
int dom_setTipo(eDominio* this, char tipo);


int dom_getDominio(eDominio* this, char* output);
int dom_getId(eDominio* this);
int dom_getAgno(eDominio* this);
char dom_getTipo(eDominio* this);

void dom_mapTipo(void* pDominio);
int filtrarAutos(void* p);
int filtrarMotos(void* p);


#endif // VEHICULOS_H_INCLUDED
