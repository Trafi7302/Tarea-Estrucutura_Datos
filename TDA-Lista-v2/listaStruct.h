#ifndef LISTA_STRUCT_H
#define LISTA_STRUCT_H

struct trabajador{
	char nombre[15];
  char primerApellido[20];
  char segundoApellido[20];
  char correo[50];
  long telefono;
  char run[13];
  int edad;
	int dia, mes, anho;
	int horasTrabajadas;
	bool tipoJornada;  
};

#define tipoDato trabajador
/* Estructuras*/
struct nodo{
	tipoDato dato;
	struct nodo* next;
	nodo(){
		next=NULL;
	}
	nodo(tipoDato x){
		nodo();
		dato=x;
	}
};

struct Lista{
	struct nodo* primero;
	Lista(){
		primero=NULL;
	}
};

#endif

