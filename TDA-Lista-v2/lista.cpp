#include <stdio.h>
#include<string.h>
#include "lista.h"

bool vacia(Lista lista){
	return fin(lista)==primero(lista);
}

int primero(Lista lista){
	return 1;
}

int fin(Lista lista){
	int c=1;
	nodo*aux = lista.primero;
	while(aux!=NULL){
		aux = aux->next;
		c++;
	}
	return c;
}

int anterior(int p, Lista lista){
	return p-1;
}

int siguiente(int p, Lista lista){
	return p+1;
}

void inserta(tipoDato x, int p, Lista &lista){
	nodo* nuevo= new nodo(x);
	nodo* aux = lista.primero;
	if(primero(lista)==p){
		nuevo->next=lista.primero;
		lista.primero = nuevo;
	}else{
		for(int i=0;i<p-2;i++)
			aux=aux->next;
		nuevo->next=aux->next;
		aux->next=nuevo;
	}
}

void imprime(Lista lista){
	
	printf("\n- Funcionarios Registrados:\n");
	if(vacia(lista)){
		printf("------- NO SE PRESENTAN REGISTROS. -------\n");
	} else{
		for(int i=primero(lista);i<fin(lista);i=siguiente(i,lista)){
			tipoDato x = recupera(i,lista);
			printf("[%d, %s %s %s]\n", i, x.nombre, x.primerApellido, x.segundoApellido);
		}
	}
	printf("\n");
	
}

void anula(Lista &lista){
	while(!vacia(lista))
		suprime(primero(lista),lista);
}

int localiza(tipoDato x, Lista lista){
	for(int i=primero(lista);i<fin(lista);i=siguiente(i,lista))
		if((strcmp(recupera(i,lista).nombre, x.nombre) == 0) && (strcmp(recupera(i,lista).primerApellido, x.primerApellido) == 0) && (strcmp(recupera(i,lista).segundoApellido, x.segundoApellido) == 0))
			return i;
	return fin(lista);
}

tipoDato recupera(int p, Lista lista){
	nodo* aux = lista.primero;
	for(int i=1;i<p;i++)
		aux=aux->next;
	return aux->dato;
}
void suprime(int p, Lista &lista){
	nodo* aux = lista.primero;
	if(primero(lista)==p)
		lista.primero=aux->next;
	else{
		nodo* aux2 = lista.primero;
		for(int i=0;i<p-2;i++)
			aux2=aux2->next;
		aux=aux2->next;
		aux2->next = aux->next;
	}
	aux->next = NULL;
	delete aux;
}

