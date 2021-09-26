#include "./libreriaStruct.h"
#include <stdio.h>

// Prototipos
void CantidadTotalFuncionarios(int* Funcionarios);

void Presentacion();
Empleados nuevoIngresoFormulario();
void DatosFuncionarioIngresados(Empleados nuevo);
void ConfirmarIngresoDeDatos(int *opcion);

void TableroResumenSemanal(Horario LunesEntrada, Horario LunesSalida, Horario MartesEntrada, Horario MartesSalida, Horario MiercolesEntrada, Horario MiercolesSalida, Horario JuevesEntrada, Horario JuevesSalida, Horario ViernesEntrada, Horario ViernesSalida, Horario SabadoEntrada, Horario SabadoSalida);

int calcularCantMinutosLunes(Horario* Entrada, Horario* Salida);
int calcularCantMinutosMartes(Horario* Entrada, Horario* Salida);
int calcularCantMinutosMiercoles(Horario* Entrada, Horario* Salida);
int calcularCantMinutosJueves(Horario* Entrada, Horario* Salida);
int calcularCantMinutosViernes(Horario* Entrada, Horario* Salida);
int calcularCantMinutosSabado(Horario* Entrada, Horario* Salida);

void imprimirTotalMinutos(int totalMinCalculados);
int calcularSueldoSemanal(int cantMinutos1, int cantMinutos2, int cantMinutos3, int cantMinutos4, int cantMinutos5, int cantMinutos6);
void imprimirSueldoSemanal(int sueldoCalculado);

void ResumenAGerente(Empleados Colaborador, FILE* archivo, int minutosLunes, int minutosMartes, int minutosMiercoles, int minutosJueves, int minutosViernes, int minutosSabado);