#include <stdio.h>
#include <string.h>
#include "./TDA-Lista-v2/lista.h"
#include "./libreriaHorarios.h"

// Implementaciones

void implementacionLista(int *opcion){
  /*
  * Nombre de la función: implementacionLista.
  * Tipo de función: void.
  * Parámetros: "opcion" de tipo int.
  * 
  * Dato de retorno: ---------------------
  * Descripción de la función: La función implementacionLista () muestra por pantalla la diferentes opciones 
  *                            que el usuario tiene disponible para realizar.
  */
  do{
    printf("\n--------------------------------\n");
    printf("------ CLAVISTEL EMPRESAS ------\n");
    printf("--------------------------------\n");
    printf("Ingresar que accion se desea realizar:\n");
    printf("\n*  1. Nueva Lista (Ingresar Funcionarios) *");
    printf("\n*  2. Revisar Lista                       *");
    printf("\n*  3. CANCELAR OPERACION                  *\n");
    scanf("%d", opcion);

  } while((*opcion < 1) || (*opcion > 3));
}

void CantidadTotalFuncionarios(int* Funcionarios){
  /*
  * Nombre de la función: CantidadTotalFuncionarios.
  * Tipo de función: void.
  * Parámetros: "Funcionarios” de tipo int.
  * 
  * Dato de retorno: ---------------------
  * Descripción de la función: La función CantidadTotalFuncionarios() solicita al encargado/supervisor
  *                            de la empresa donde esta implementado el sistema que contiene al algoritmo,
  *                            ingresar la cantidad total de funcionarios que se desempeñaran en el recorrido
  *                            de la semana para contabilizar la cantidad de solicitudes a realizar el programa.
  */
  printf("\nIngresar cuantos funcionarios han estado ejerciendo en la semana:\n");
  scanf("%d", Funcionarios);
}

void Presentacion(){
  /*
  * Nombre de la función: Presentacion.
  * Tipo de función: void.
  * Parámetros: ------------------
  * 
  * Dato de retorno: ---------------------
  * Descripción de la función: La función Presentacion () le muestra por pantalla una bienvenida al usuario,
  *                            a la interfaz de clavistel.
  */
  printf("\n--------------------------------\n");
  printf("------ CLAVISTEL EMPRESAS ------\n");
  printf("--------------------------------\n");
  printf("Estimado funcionario, sea bienvenido a la interfaz de Empresas 'CLAVISTEL'.\nA continuacion, se le solicita ingresar sus datos de forma correcta:\n\n");
}

void nuevoIngresoTrabajador(Lista &lista){
  /* Nombre de la función: nuevoIngresoTrabajador.
  * Tipo de función: void.
  * Parámetros: "lista” de tipo Lista.
  * 
  * Dato de retorno: ---------------------
  * Descripción de la función: La función nuevoIngresoTrabajador() solicita al trabajador, 
  *                            ingresar sus datos personales. 
  */
  trabajador nuevoTrabajador;
  // Ingreso de Datos
  printf("Ingrese su Nombre y sus 2 Apellidos:\n");
  scanf("%s %s %s", nuevoTrabajador.nombre, nuevoTrabajador.primerApellido, nuevoTrabajador.segundoApellido);
  printf("Ingrese su Run: (Solo con el guion)\n");
  scanf("%s", nuevoTrabajador.run);
  printf("Ingrese su fecha de nacimiento de la forma (dd/mm/aaaa):\n");
  scanf("%i/%i/%i", &(nuevoTrabajador.dia), &(nuevoTrabajador.mes), &(nuevoTrabajador.anho));
  printf("Ingrese su num. de telefono:\n");
  scanf("%lu", &(nuevoTrabajador.telefono));
  printf("Ingrese su correo electronico:\n");
  scanf("%s", nuevoTrabajador.correo);

  inserta(nuevoTrabajador, fin(lista), lista);
}

void DatosTrabajadorIngresado(Lista lista){
  /*
  * Nombre de la función: DatosTrabajadorIngresado.
  * Tipo de función: void.
  * Parámetros: "lista” de tipo Lista.
  * 
  * Dato de retorno: ---------------------
  * Descripción de la función: La función DatosTrabajadorIngresado() 
  *                            recupera los elementos anteriores al fin de la lista. 
  */
  tipoDato x = recupera(anterior(fin(lista), lista), lista);
  // Impresión por pantalla de los datos ingresados.
  printf("\n- Nombre   : %s. \n- Apellidos: %s %s.\n- RUN      : %s \n- Telefono : %lu.\n- Correo   : %s \n", x.nombre, x.primerApellido, x.segundoApellido, x.run, x.telefono, x.correo);
}

void ConfirmarIngresoDeDatos(int *opcion){
  /*
  * Nombre de la función: ConfirmarIngresoDeDatos.
  * Tipo de función: void.
  * Parámetros: "opcion” de tipo int.
  * 
  * Dato de retorno: ---------------------
  * Descripción de la función: La función ConfirmarIngresoDeDatos() consulta al funcionario verificar 
  *                            si sus datos ingresados son correctos o necesita corregir alguno. 
  */
  do{
    printf("\n--------------------------------------------------------------------------------------------\n");
    printf("| Los datos ingresados anteriormente estan completamente en orden o desea reingresarlos?: |\n");
    printf("|   1. LOS DATOS ESTAN CORRECTAMENTE INGRESADOS.                                          |\n");                                      
    printf("|   2. HAY DATOS ERRONEOS, DESEO REINGRESAR MI INFORMACION.                               |\n");                             
    printf("--------------------------------------------------------------------------------------------\n");
    printf("Ingrese una opcion:\n");
    scanf("%d", opcion);

  } while((*opcion < 1) || (*opcion > 2));
}

void TableroResumenSemanal(Horario LunesEntrada, Horario LunesSalida, Horario MartesEntrada, Horario MartesSalida, Horario MiercolesEntrada, Horario MiercolesSalida, Horario JuevesEntrada, Horario JuevesSalida, Horario ViernesEntrada, Horario ViernesSalida, Horario SabadoEntrada, Horario SabadoSalida){
  /*
  * Nombre de la función: TableroResumenSemanal.
  * Tipo de función: void.
  * Parámetros: "LunesEntrada, LunesSalida" de tipo Struct_Horario.
  *             "MartesEntrada, MartesSalida" de tipo Struct_Horario.
  *             "MiercolesEntrada, MiercolesSalida" de tipo Struct_Horario.
  *             "JuevesEntrada, JuevesSalida" de tipo Struct_Horario.
  *             "ViernesEntrada, ViernesSalida" de tipo Struct_Horario.
  *             "SabadoEntrada, SabadoSalida" de tipo Struct_Horario.
  * 
  * Dato de retorno: ---------------------
  * Descripción de la función: La función TableroResumenSemanal() muestra un tablero en pantalla con los horarios de entrada y salida de cada jornada.
  */
  printf("\n                 |   Lunes    |   Martes    |     Miercoles    |     Jueves     |     Viernes     |     Sabado  \n");
  printf("-------------------------------------------------------------------------------------------------------------------\n");
  printf(" Hora de Ingreso |   %d:%d           %d:%d            %d:%d               %d:%d              %d:%d               %d:%d   \n", LunesEntrada.hora, LunesEntrada.minutos, MartesEntrada.hora, MartesEntrada.minutos, MiercolesEntrada.hora, MiercolesEntrada.minutos, JuevesEntrada.hora, JuevesEntrada.minutos, ViernesEntrada.hora, ViernesEntrada.minutos, SabadoEntrada.hora, SabadoEntrada.minutos);
  printf("-------------------------------------------------------------------------------------------------------------------\n");
  printf(" Hora de Salida  |   %d:%d         %d:%d            %d:%d              %d:%d              %d:%d               %d:%d   \n",LunesSalida.hora, LunesSalida.minutos, MartesSalida.hora, MartesSalida.minutos, MiercolesSalida.hora, MiercolesSalida.minutos, JuevesSalida.hora, JuevesSalida.minutos, ViernesSalida.hora, ViernesSalida.minutos, SabadoSalida.hora, SabadoSalida.minutos);
  printf("-------------------------------------------------------------------------------------------------------------------\n\n");
}

int calcularCantMinutosLunes(Horario* Entrada, Horario* Salida){
  /*
  * Nombre de la función: calcularCantMinutosLunes.
  * Tipo de función: int.
  * Parámetros: "Entrada” de tipo Struct_Horario.
  *             "Salida” de tipo Struct_Horario.
  * 
  * Dato de retorno: "TotalMinutos" de tipo int.
  * Descripción de la función: La función calcularCantMinutosLunes() muestra por pantalla al usuario el ingreso y salida, 
  *                            para luego calcular y retornar los minutos trabajados el dia lunes.
  */
  printf("\nA continuacion digite el horario en el que hizo entrada su turno el dia lunes en formato 24 horas: (hh:mm)\n");
  scanf("%d:%d", &(Entrada->hora), &(Entrada->minutos));
  printf("A continuacion digite el horario en el que hizo termino su turno el dia lunes en formato 24 horas: (hh:mm)\n");
  scanf("%d:%d", &(Salida->hora), &(Salida->minutos));

  int TotalMinutos;
  // Cálculo del total de minutos de acuerdo a los horarios mínimos con un descanso correspondiente al almuerzo durante la jornada de un total de 1 hora y 30 minutos.
  if(Entrada->hora > Salida->hora){
    // Cálculo establecido para el caso de un turno en la noche.
    TotalMinutos = (24 - (Entrada->hora - Salida->hora))*60 + (Salida->minutos - Entrada->minutos);
    if(TotalMinutos >= 330){
      TotalMinutos -= 90;
      return TotalMinutos;

    } else{
    return TotalMinutos;
    }
  } else{
    TotalMinutos = (Salida->hora - Entrada->hora)*60 + (Salida->minutos - Entrada->minutos);
    if(TotalMinutos >= 330){
      TotalMinutos -= 90;
      return TotalMinutos;

    } else{
      return TotalMinutos;
    }
  }
}

int calcularCantMinutosMartes(Horario* Entrada, Horario* Salida){
  /*
  * Nombre de la función: calcularCantMinutosMartes.
  * Tipo de función: int.
  * Parámetros: "Entrada” de tipo Struct_Horario.
  *             "Salida” de tipo Struct_Horario.
  * 
  * Dato de retorno: "TotalMinutos" de tipo int.
  * Descripción de la función: La función calcularCantMinutosLunes() muestra por pantalla al usuario el ingreso y salida, 
  *                            para luego calcular y retornar los minutos trabajados el dia martes.
  */
  printf("A continuacion digite el horario en el que hizo entrada su turno el dia martes en formato 24 horas: (hh:mm)\n");
  scanf("%d:%d", &(Entrada->hora), &(Entrada->minutos));
  printf("A continuacion digite el horario en el que hizo termino su turno el dia martes en formato 24 horas: (hh:mm)\n");
  scanf("%d:%d", &(Salida->hora), &(Salida->minutos));

  int TotalMinutos;
  if(Entrada->hora > Salida->hora){
    TotalMinutos = (24 - (Entrada->hora - Salida->hora))*60 + (Salida->minutos - Entrada->minutos);
    if(TotalMinutos >= 330){
      TotalMinutos -= 90;
      return TotalMinutos;

    } else{
    return TotalMinutos;
    }
  } else{
    TotalMinutos = (Salida->hora - Entrada->hora)*60 + (Salida->minutos - Entrada->minutos);
    if(TotalMinutos >= 330){
      TotalMinutos -= 90;
      return TotalMinutos;

    } else{
      return TotalMinutos;
    }
  }
}

int calcularCantMinutosMiercoles(Horario* Entrada, Horario* Salida){
  /*
  * Nombre de la función: calcularCantMinutosMiercoles.
  * Tipo de función: int.
  * Parámetros: "Entrada” de tipo Struct_Horario.
  *             "Salida” de tipo Struct_Horario.
  * 
  * Dato de retorno: "TotalMinutos" de tipo int.
  * Descripción de la función: La función calcularCantMinutosLunes() muestra por pantalla al usuario el ingreso y salida, 
  *                            para luego calcular y retornar los minutos trabajados el dia miércoles.
  */
  printf("A continuacion digite el horario en el que hizo entrada su turno el dia miercoles en formato 24 horas: (hh:mm)\n");
  scanf("%d:%d", &(Entrada->hora), &(Entrada->minutos));
  printf("A continuacion digite el horario en el que hizo termino su turno el dia miercoles en formato 24 horas: (hh:mm)\n");
  scanf("%d:%d", &(Salida->hora), &(Salida->minutos));

  int TotalMinutos;
  if(Entrada->hora > Salida->hora){
    TotalMinutos = (24 - (Entrada->hora - Salida->hora))*60 + (Salida->minutos - Entrada->minutos);
    if(TotalMinutos >= 330){
      TotalMinutos -= 90;
      return TotalMinutos;

    } else{
    return TotalMinutos;
    }
  } else{
    TotalMinutos = (Salida->hora - Entrada->hora)*60 + (Salida->minutos - Entrada->minutos);
    if(TotalMinutos >= 330){
      TotalMinutos -= 90;
      return TotalMinutos;

    } else{
      return TotalMinutos;
    }
  }
}

int calcularCantMinutosJueves(Horario* Entrada, Horario* Salida){
  /*
  * Nombre de la función: calcularCantMinutosJueves.
  * Tipo de función: int.
  * Parámetros: "Entrada” de tipo Struct_Horario.
  *             "Salida” de tipo Struct_Horario.
  * 
  * Dato de retorno: "TotalMinutos" de tipo int.
  * Descripción de la función: La función calcularCantMinutosLunes() muestra por pantalla al usuario el ingreso y salida, 
  *                            para luego calcular y retornar los minutos trabajados el dia jueves.
  */
  printf("A continuacion digite el horario en el que hizo entrada su turno el dia jueves en formato 24 horas: (hh:mm)\n");
  scanf("%d:%d", &(Entrada->hora), &(Entrada->minutos));
  printf("A continuacion digite el horario en el que hizo termino su turno el dia jueves en formato 24 horas: (hh:mm)\n");
  scanf("%d:%d", &(Salida->hora), &(Salida->minutos));

  int TotalMinutos;
  if(Entrada->hora > Salida->hora){
    TotalMinutos = (24 - (Entrada->hora - Salida->hora))*60 + (Salida->minutos - Entrada->minutos);
    if(TotalMinutos >= 330){
      TotalMinutos -= 90;
      return TotalMinutos;

    } else{
    return TotalMinutos;
    }
  } else{
    TotalMinutos = (Salida->hora - Entrada->hora)*60 + (Salida->minutos - Entrada->minutos);
    if(TotalMinutos >= 330){
      TotalMinutos -= 90;
      return TotalMinutos;

    } else{
      return TotalMinutos;
    }
  }
}

int calcularCantMinutosViernes(Horario* Entrada, Horario* Salida){
  /*
  * Nombre de la función: calcularCantMinutosViernes.
  * Tipo de función: int.
  * Parámetros: "Entrada” de tipo Struct_Horario.
  *             "Salida” de tipo Struct_Horario.
  * 
  * Dato de retorno: "TotalMinutos" de tipo int.
  * Descripción de la función: La función calcularCantMinutosLunes() muestra por pantalla al usuario el ingreso y salida, 
  *                            para luego calcular y retornar los minutos trabajados el dia viernes.
  */
  printf("A continuacion digite el horario en el que hizo entrada su turno el dia viernes en formato 24 horas: (hh:mm)\n");
  scanf("%d:%d", &(Entrada->hora), &(Entrada->minutos));
  printf("A continuacion digite el horario en el que hizo termino su turno el dia viernes en formato 24 horas: (hh:mm)\n");
  scanf("%d:%d", &(Salida->hora), &(Salida->minutos));

  int TotalMinutos;
  if(Entrada->hora > Salida->hora){
    TotalMinutos = (24 - (Entrada->hora - Salida->hora))*60 + (Salida->minutos - Entrada->minutos);
    if(TotalMinutos >= 330){
      TotalMinutos -= 90;
      return TotalMinutos;

    } else{
    return TotalMinutos;
    }
  } else{
    TotalMinutos = (Salida->hora - Entrada->hora)*60 + (Salida->minutos - Entrada->minutos);
    if(TotalMinutos >= 330){
      TotalMinutos -= 90;
      return TotalMinutos;

    } else{
      return TotalMinutos;
    }
  }
}

int calcularCantMinutosSabado(Horario* Entrada, Horario* Salida){
  /*
  * Nombre de la función: calcularCantMinutosSabado.
  * Tipo de función: int.
  * Parámetros: "Entrada” de tipo Struct_Horario.
  *             "Salida” de tipo Struct_Horario.
  * 
  * Dato de retorno: "TotalMinutos" de tipo int.
  * Descripción de la función: La función calcularCantMinutosLunes() muestra por pantalla al usuario el ingreso y salida, 
  *                            para luego calcular y retornar los minutos trabajados el dia sábado.
  */
  printf("A continuacion digite el horario en el que hizo entrada su turno el dia sabado en formato 24 horas: (hh:mm)\n");
  scanf("%d:%d", &(Entrada->hora), &(Entrada->minutos));
  printf("A continuacion digite el horario en el que hizo termino su turno el dia sabado en formato 24 horas: (hh:mm)\n");
  scanf("%d:%d", &(Salida->hora), &(Salida->minutos));

  int TotalMinutos;
  if(Entrada->hora > Salida->hora){
    TotalMinutos = (24 - (Entrada->hora - Salida->hora))*60 + (Salida->minutos - Entrada->minutos);
    if(TotalMinutos >= 330){
      TotalMinutos -= 90;
      return TotalMinutos;

    } else{
    return TotalMinutos;
    }
  } else{
    TotalMinutos = (Salida->hora - Entrada->hora)*60 + (Salida->minutos - Entrada->minutos);
    if(TotalMinutos >= 330){
      TotalMinutos -= 90;
      return TotalMinutos;

    } else{
      return TotalMinutos;
    }
  }
}

void imprimirTotalMinutos(int totalMinCalculados){
  /*
  * Nombre de la función: imprimirTotalMinutos.
  * Tipo de función: void.
  * Parámetros: "totalMinCalculados” de tipo int.
  * 
  * Dato de retorno: ---------------------
  * Descripción de la función: La función imprimirTotalMinutos() imprime por pantalla el total de  los minutos trabajados.
  */
    printf("El total de los minutos es: %d\n\n", totalMinCalculados);
}

// Cálculo de la remuneración semanal con respecto a los minutos calculados previamente por día de Lunes a Sábado.
int calcularSueldoSemanal(int cantMinutos1, int cantMinutos2, int cantMinutos3, int cantMinutos4, int cantMinutos5, int cantMinutos6){
  /*
  * Nombre de la función: calcularSueldoSemanal.
  * Tipo de función: int.
  * Parámetros: "cantMinutos1” de tipo int.
  *             "cantMinutos2” de tipo int.
  *             "cantMinutos3” de tipo int.
  *             "cantMinutos4” de tipo int.
  *             "cantMinutos5” de tipo int.
  *             "cantMinutos6” de tipo int.
  * 
  * Dato de retorno: sueldoSemanalFuncionario de tipo int.
  * Descripción de la función: La función calcularSueldoSemanal() calcula el sueldo por el dia y luego lo suma para dar un monto final, para dar un retorno de tipo entero.
  */
  int sueldoSemanalFuncionario = (cantMinutos1 + cantMinutos2 + cantMinutos3 + cantMinutos4 + cantMinutos5 + cantMinutos6) * 40;
  return sueldoSemanalFuncionario;
}

void imprimirSueldoSemanal(int sueldoCalculado){
  /*
  * Nombre de la función: imprimirSueldoSemanal.
  * Tipo de función: void.
  * Parámetros: "sueldoCalculado” de tipo int.
  * 
  * Dato de retorno: ---------------------
  * Descripción de la función: La función imprimirSueldoSemanal() muestra por pantalla el sueldo por honorarios de la semana correspondiente.
  */
    printf("El sueldo por honorarios correspondientes a esta semana es de: $%d pesos.\n\n", sueldoCalculado);
}

// Resumen y evaluación final que tiene el fin de presentarle un informe completo de acuerdo a las exigencias minimas de la empresa. 
void ResumenAGerente(Lista lista, FILE* archivo, int minutosLunes, int minutosMartes, int minutosMiercoles, int minutosJueves, int minutosViernes, int minutosSabado){
  /*
  * Nombre de la función: ResumenAGerente.
  * Tipo de función: void.
  * Parámetros: "lista" de tipo Lista.
  *             "archivo" de tipo FILE.
  *             "minutosLunes” de tipo int.
  *             "minutosMartes” de tipo int.
  *             "minutosMiercoles” de tipo int.
  *             "minutosJueves” de tipo int.
  *             "minutosViernes” de tipo int.
  *             "minutosSabado” de tipo int.
  * 
  * Dato de retorno: ---------------------
  * Descripción de la función: La función ResumenAGerente(), a partir del último trabajador ingresado y los horarios que haya ingresado,
  *                            calcula y muestra por pantalla el sueldo y los minutos trabajados totales por semana,
  *                            con el fin de evaluar si el trabajador cumplio con lo mínimo establecido.
  */
  tipoDato x = recupera(anterior(fin(lista), lista), lista);

  fprintf(archivo,"-----------------------------------------------------\n");
  fprintf(archivo,"------------     RESUMEN COLABORADOR     ------------\n");
  fprintf(archivo,"-----------------------------------------------------\n");
  fprintf(archivo,"Nombre Completo: %s %s %s.        RUN: %s          Telefono: %lu\nCorreo: %s                 Fecha nacimiento: %d del %d del año %d\n\n", x.nombre, x.primerApellido, x.segundoApellido, x.run, x.telefono, x.correo, x.dia, x.mes, x.anho);
  fprintf(archivo,"\n    Dia    | Total de Minutos  |   Monto \n");
  fprintf(archivo,"-----------------------------------------------\n");
  fprintf(archivo,"  Lunes    |       %d             $%d     \n", minutosLunes, minutosLunes *40);
  fprintf(archivo,"-----------------------------------------------\n");
  fprintf(archivo,"  Martes   |       %d             $%d     \n", minutosMartes, minutosMartes*40);
  fprintf(archivo,"-----------------------------------------------\n");
  fprintf(archivo," Miercoles |       %d             $%d     \n", minutosMiercoles, minutosMiercoles*40);
  fprintf(archivo,"-----------------------------------------------\n");
  fprintf(archivo,"  Jueves   |       %d             $%d     \n", minutosJueves, minutosJueves*40);
  fprintf(archivo,"-----------------------------------------------\n");
  fprintf(archivo,"  Viernes  |       %d             $%d     \n", minutosViernes, minutosViernes*40);
  fprintf(archivo,"-----------------------------------------------\n");
  fprintf(archivo,"  Sabado   |       %d             $%d     \n", minutosSabado, minutosSabado*40);
  fprintf(archivo,"-----------------------------------------------\n");
  fprintf(archivo,"  Total    |      %d             $%d pesos.  \n\n", (minutosLunes + minutosMartes + minutosMiercoles + minutosJueves + minutosViernes + minutosSabado), (minutosLunes + minutosMartes + minutosMiercoles + minutosJueves + minutosViernes + minutosSabado)*40);
  fprintf(archivo,"   ***** LOS MINUTOS MINIMOS SEMANALES CON LOS QUE DEBE CUMPLIR UN COLABORADOR SON 2400 min. ---> 40 hrs. *****\n     ************       POR LO TANTO, LA REMUNERACION MINIMA CORRESPONDE A $96.000 pesos      ************\n");
  if((minutosLunes + minutosMartes + minutosMiercoles + minutosJueves + minutosViernes + minutosSabado) < 2400){
    fprintf(archivo,"---------- El funcionario no ha cumplido durante esta semana con el minimo de horas solicitadas!!! ----------\n\n");
  }
  if((minutosLunes + minutosMartes + minutosMiercoles + minutosJueves + minutosViernes + minutosSabado) >= 2400){
    fprintf(archivo,"++++++++++++  El colaborador ha cumplido correctamente con el horario minimo durante esta semana!!!  +++++++++++++\n\n");
  }
}

void opcionesManejoDLista(Lista &lista, int *opcion, int *numeroFuncionario){
  /*
  * Nombre de la función: opcionesManejoDLista.
  * Tipo de función: void.
  * Parámetros: "lista" de tipo Lista.
  *             "opcion” de tipo int.
  *             "numeroFuncionario" de tipo int.
  * 
  * Dato de retorno: ---------------------
  * Descripción de la función: La función opcionesManejoDLista() muestra por pantalla las diferentes opciones a realizar con la lista,
  *                            en caso de necesitar revisarla o modificarla.
  */
  do{
    printf("\nQue operacion se realizara?\nIndique la opcion:\n");
    printf("\n  1. Eliminar funcionario de la lista.");
    printf("\n  2. Imprimir lista.");
    printf("\n  3. CANCELAR.\n");  
    scanf("%d", opcion);

    if(*opcion == 1){
      if(vacia(lista)){
        imprime(lista);
      } else{
        imprime(lista);
        printf("Ingrese el numero del funcionario correspondiente que desea eliminar:\n");
        scanf("%d", numeroFuncionario);
        suprime(*numeroFuncionario, lista);

      }
    } else if(*opcion == 2){
      imprime(lista);
    }
  } while((*opcion < 1) || (*opcion > 3));
  
}