#include <stdio.h>
#include "listaStruct.h"

/* Prototipos */
bool vacia(Lista lista);
int primero(Lista lista); // revisa el primer elemento de la lista-cola-pila
int fin(Lista lista); // llega al ultimo elemento de la lista-cola-pila
int anterior(int p, Lista lista);
int siguiente(int p, Lista lista);
void inserta(tipoDato x, int p, Lista &lista);
tipoDato recupera(int p, Lista lista);
void imprime(Lista lista);
int localiza(tipoDato x, Lista lista);
void suprime(int p, Lista &lista);
void anula(Lista &lista);