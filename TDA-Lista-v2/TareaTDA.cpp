#include <stdio.h>
#include "lista.h"

#ifndef CABECERA_STRUCT_H
#define CABECERA_STRUCT_H

struct nodo{
int dato;
struct nodo *sgte;
};
struct cabecera{
int largo;
nodo *primero;
};


#endif

int max(cabecera* lista);

int main(){
  cabecera a;
  return 0;
}

int max(cabecera* lista){
  tipoDato datoMayor = recupera(primero(lista), lista);
  for(int i = siguiente(primero(lista), lista) ; i < fin(lista) ; i = siguiente(i, lista)){
    tipoDato valor = recupera(i, lista);
      if(valor > datoMayor){
        datoMayor = valor;
      }
  }
  return datoMayor;
}
