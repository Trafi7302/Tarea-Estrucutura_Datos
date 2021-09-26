#include <stdio.h>
#include "./libreriaHorarios.h"

// Implementaciones

void CantidadTotalFuncionarios(int* Funcionarios){
  printf("Ingresar cuantos funcionarios han estado ejerciendo en la semana:\n");
  scanf("%d", Funcionarios);
}

void Presentacion(){
  printf("\n--------------------------------\n");
  printf("------ CLAVISTEL EMPRESAS ------\n");
  printf("--------------------------------\n");
  printf("Estimado funcionario, sea bienvenido a la interfaz de Empresas 'CLAVISTEL'.\nA continuacion, se le solicita ingresar sus datos de forma correcta:\n\n");
}

Empleados nuevoIngresoFormulario(){
  Empleados Funcionario;
  // Ingreso de Datos
  printf("Ingrese su Nombre y sus 2 Apellidos:\n");
  scanf("%s %s %s", Funcionario.nombre, Funcionario.primerApellido, Funcionario.segundoApellido);
  printf("Ingrese su Run: (Solo con el guion)\n");
  scanf("%s", Funcionario.run);
  printf("Ingrese su fecha de nacimiento de la forma (dd/mm/aaaa):\n");
  scanf("%i/%i/%i", &(Funcionario.dia), &(Funcionario.mes), &(Funcionario.ano));
  printf("Ingrese su num. de telefono:\n");
  scanf("%lu", &(Funcionario.telefono));
  printf("Ingrese su correo electronico:\n");
  scanf("%s", Funcionario.correo);

  return Funcionario;
}

void DatosFuncionarioIngresados(Empleados nuevo){
  // Impresión por pantalla de los datos ingresados.
  printf("\n- Nombre   : %s. \n- Apellidos: %s %s.\n- RUN      : %s \n- Telefono : %lu.\n- Correo   : %s \n", nuevo.nombre, nuevo.primerApellido, nuevo.segundoApellido, nuevo.run, nuevo.telefono, nuevo.correo);
}

void ConfirmarIngresoDeDatos(int *opcion){
  // Confirmación de datos.
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
  // Ejemplo Tabla-Resumen 1 
/*
  printf("\n    Dia    | Hora de Ingreso  | Hora de Salida \n");
  printf("-----------------------------------------------\n");
  printf("  Lunes    |       %d:%d               %d:%d     \n", LunesEntrada.hora, LunesEntrada.minutos, LunesSalida.hora, LunesSalida.minutos);
  printf("-----------------------------------------------\n");
  printf("  Martes   |       %d:%d               %d:%d     \n", MartesEntrada.hora, MartesEntrada.minutos, MartesSalida.hora, MartesSalida.minutos);
  printf("-----------------------------------------------\n");
  printf(" Miercoles |       %d:%d               %d:%d     \n", MiercolesEntrada.hora, MiercolesEntrada.minutos, MiercolesSalida.hora, MiercolesSalida.minutos);
  printf("-----------------------------------------------\n");
  printf("  Jueves   |       %d:%d               %d:%d     \n", JuevesEntrada.hora, JuevesEntrada.minutos, JuevesSalida.hora, JuevesSalida.minutos);
  printf("-----------------------------------------------\n");
  printf("  Viernes  |       %d:%d               %d:%d     \n", ViernesEntrada.hora, ViernesEntrada.minutos, ViernesSalida.hora, ViernesSalida.minutos);
  printf("-----------------------------------------------\n");
  printf("  Sabado   |       %d:%d               %d:%d    \n\n", SabadoEntrada.hora, SabadoEntrada.minutos, SabadoSalida.hora, SabadoSalida.minutos);
*/
  // Ejemplo Tabla-Resumen 2
  printf("\n                 |   Lunes    |   Martes    |     Miercoles    |     Jueves     |     Viernes     |     Sabado  \n");
  printf("-------------------------------------------------------------------------------------------------------------------\n");
  printf(" Hora de Ingreso |   %d:%d           %d:%d            %d:%d               %d:%d              %d:%d               %d:%d   \n", LunesEntrada.hora, LunesEntrada.minutos, MartesEntrada.hora, MartesEntrada.minutos, MiercolesEntrada.hora, MiercolesEntrada.minutos, JuevesEntrada.hora, JuevesEntrada.minutos, ViernesEntrada.hora, ViernesEntrada.minutos, SabadoEntrada.hora, SabadoEntrada.minutos);
  printf("-------------------------------------------------------------------------------------------------------------------\n");
  printf(" Hora de Salida  |   %d:%d         %d:%d            %d:%d              %d:%d              %d:%d               %d:%d   \n",LunesSalida.hora, LunesSalida.minutos, MartesSalida.hora, MartesSalida.minutos, MiercolesSalida.hora, MiercolesSalida.minutos, JuevesSalida.hora, JuevesSalida.minutos, ViernesSalida.hora, ViernesSalida.minutos, SabadoSalida.hora, SabadoSalida.minutos);
  printf("-------------------------------------------------------------------------------------------------------------------\n\n");
}

int calcularCantMinutosLunes(Horario* Entrada, Horario* Salida){
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
    printf("El total de los minutos es: %d\n\n", totalMinCalculados);
}

// Cálculo de la remuneración semanal con respecto a los minutos calculados previamente por día de Lunes a Sábado.
int calcularSueldoSemanal(int cantMinutos1, int cantMinutos2, int cantMinutos3, int cantMinutos4, int cantMinutos5, int cantMinutos6){
  int sueldoSemanalFuncionario = (cantMinutos1 + cantMinutos2 + cantMinutos3 + cantMinutos4 + cantMinutos5 + cantMinutos6) * 40;
  return sueldoSemanalFuncionario;
}

void imprimirSueldoSemanal(int sueldoCalculado){
    printf("El sueldo por honorarios correspondientes a esta semana es de: $%d pesos.\n\n", sueldoCalculado);
}

// Resumen y evaluación final que tiene el fin de presentarle un informe completo de acuerdo a las exigencias minimas de la empresa. 
void ResumenAGerente(Empleados Colaborador, FILE* archivo, int minutosLunes, int minutosMartes, int minutosMiercoles, int minutosJueves, int minutosViernes, int minutosSabado){
  fprintf(archivo,"-----------------------------------------------------\n");
  fprintf(archivo,"------------     RESUMEN COLABORADOR     ------------\n");
  fprintf(archivo,"-----------------------------------------------------\n");
  fprintf(archivo,"Nombre Completo: %s %s %s.        RUN: %s          Telefono: %lu\nCorreo: %s                 Fecha nacimiento: %d del %d del año %d\n\n", Colaborador.nombre, Colaborador.primerApellido, Colaborador.segundoApellido, Colaborador.run, Colaborador.telefono, Colaborador.correo, Colaborador.dia, Colaborador.mes, Colaborador.ano);
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
  fprintf(archivo,"     ***** LOS MINUTOS MINIMOS SEMANALES CON LOS QUE DEBE CUMPLIR UN COLABORADOR SON 2400 min. ---> 40 hrs. *****\n       *************       POR LO TANTO, LA REMUNERACION MINIMA CORRESPONDE A $96.000 pesos       *************\n");
  if((minutosLunes + minutosMartes + minutosMiercoles + minutosJueves + minutosViernes + minutosSabado) < 2400){
    fprintf(archivo,"------------- El funcionario no ha cumplido durante esta semana con el minimo de horas solicitadas!!! -------------\n\n");
  }
  if((minutosLunes + minutosMartes + minutosMiercoles + minutosJueves + minutosViernes + minutosSabado) >= 2400){
    fprintf(archivo,"++++++++++++++  El colaborador ha cumplido correctamente con el horario minimo durante esta semana!!!  +++++++++++++++\n\n");
  }
}