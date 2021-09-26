#include <stdio.h>
#include "./libreriaHorarios.h"

int main(){
  int TotalEmpleados;
  int opcion;
  Horario EntradaJornadaLunes, SalidaJornadaLunes;
  Horario EntradaJornadaMartes, SalidaJornadaMartes;
  Horario EntradaJornadaMiercoles, SalidaJornadaMiercoles;
  Horario EntradaJornadaJueves, SalidaJornadaJueves;
  Horario EntradaJornadaViernes, SalidaJornadaViernes;
  Horario EntradaJornadaSabado, SalidaJornadaSabado;

  CantidadTotalFuncionarios(&TotalEmpleados);

  FILE* archivoResumen = fopen("Resumen_Colaborador.txt", "a+");
  fclose(archivoResumen);

  for(int i = 0 ; i < TotalEmpleados ; i++){
    Presentacion();
    Empleados Funcionario = nuevoIngresoFormulario();
    DatosFuncionarioIngresados(Funcionario);
    ConfirmarIngresoDeDatos(&opcion);
    if(opcion == 1){
      TableroResumenSemanal(EntradaJornadaLunes, SalidaJornadaLunes, EntradaJornadaMartes, SalidaJornadaMartes, EntradaJornadaMiercoles, SalidaJornadaMiercoles, EntradaJornadaJueves, SalidaJornadaJueves, EntradaJornadaViernes, SalidaJornadaViernes, EntradaJornadaSabado, SalidaJornadaSabado);
      printf("Sus datos han sido ingresados correctamente!!\nPor favor, rellene el tablero con los horarios de esta semana:\n");
    } else{
      i --;
      continue;
    }

    int TotalMinutosJornada1 = calcularCantMinutosLunes(&EntradaJornadaLunes, &SalidaJornadaLunes);
    TableroResumenSemanal(EntradaJornadaLunes, SalidaJornadaLunes, EntradaJornadaMartes, SalidaJornadaMartes, EntradaJornadaMiercoles, SalidaJornadaMiercoles, EntradaJornadaJueves, SalidaJornadaJueves, EntradaJornadaViernes, SalidaJornadaViernes, EntradaJornadaSabado, SalidaJornadaSabado);
    imprimirTotalMinutos(TotalMinutosJornada1);

    int TotalMinutosJornada2 = calcularCantMinutosMartes(&EntradaJornadaMartes, &SalidaJornadaMartes);
    TableroResumenSemanal(EntradaJornadaLunes, SalidaJornadaLunes, EntradaJornadaMartes, SalidaJornadaMartes, EntradaJornadaMiercoles, SalidaJornadaMiercoles, EntradaJornadaJueves, SalidaJornadaJueves, EntradaJornadaViernes, SalidaJornadaViernes, EntradaJornadaSabado, SalidaJornadaSabado);
    imprimirTotalMinutos(TotalMinutosJornada2);

    int TotalMinutosJornada3 = calcularCantMinutosMiercoles(&EntradaJornadaMiercoles, &SalidaJornadaMiercoles);
    TableroResumenSemanal(EntradaJornadaLunes, SalidaJornadaLunes, EntradaJornadaMartes, SalidaJornadaMartes, EntradaJornadaMiercoles, SalidaJornadaMiercoles, EntradaJornadaJueves, SalidaJornadaJueves, EntradaJornadaViernes, SalidaJornadaViernes, EntradaJornadaSabado, SalidaJornadaSabado);
    imprimirTotalMinutos(TotalMinutosJornada3);

    int TotalMinutosJornada4 = calcularCantMinutosJueves(&EntradaJornadaJueves, &SalidaJornadaJueves);
    TableroResumenSemanal(EntradaJornadaLunes, SalidaJornadaLunes, EntradaJornadaMartes, SalidaJornadaMartes, EntradaJornadaMiercoles, SalidaJornadaMiercoles, EntradaJornadaJueves, SalidaJornadaJueves, EntradaJornadaViernes, SalidaJornadaViernes, EntradaJornadaSabado, SalidaJornadaSabado);
    imprimirTotalMinutos(TotalMinutosJornada4);

    int TotalMinutosJornada5 = calcularCantMinutosViernes(&EntradaJornadaViernes, &SalidaJornadaViernes);
    TableroResumenSemanal(EntradaJornadaLunes, SalidaJornadaLunes, EntradaJornadaMartes, SalidaJornadaMartes, EntradaJornadaMiercoles, SalidaJornadaMiercoles, EntradaJornadaJueves, SalidaJornadaJueves, EntradaJornadaViernes, SalidaJornadaViernes, EntradaJornadaSabado, SalidaJornadaSabado);
    imprimirTotalMinutos(TotalMinutosJornada5);

    int TotalMinutosJornada6 = calcularCantMinutosSabado(&EntradaJornadaSabado, &SalidaJornadaSabado);
    TableroResumenSemanal(EntradaJornadaLunes, SalidaJornadaLunes, EntradaJornadaMartes, SalidaJornadaMartes, EntradaJornadaMiercoles, SalidaJornadaMiercoles, EntradaJornadaJueves, SalidaJornadaJueves, EntradaJornadaViernes, SalidaJornadaViernes, EntradaJornadaSabado, SalidaJornadaSabado);
    imprimirTotalMinutos(TotalMinutosJornada6);
    
    int sueldoFuncionario = calcularSueldoSemanal(TotalMinutosJornada1, TotalMinutosJornada2, TotalMinutosJornada3, TotalMinutosJornada4, TotalMinutosJornada5, TotalMinutosJornada6);
    imprimirSueldoSemanal(sueldoFuncionario);

    FILE* archivoResumen = fopen("Resumen_Colaborador.txt", "a+");
    ResumenAGerente(Funcionario, archivoResumen, TotalMinutosJornada1, TotalMinutosJornada2, TotalMinutosJornada3, TotalMinutosJornada4, TotalMinutosJornada5, TotalMinutosJornada6);
  }
  fclose(archivoResumen);
  return 0;
}