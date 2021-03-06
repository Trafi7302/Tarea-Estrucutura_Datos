/* Universidad de La Frontera
* Departamento de Ingeniería Eléctrica
*
* IIE-344 ESTRUCTURA DE DATOS Y ALGORITMOS
*
* Tarea 2
*
* Autores: Alfredo Felipe Álvarez Martínez. (a.alvarez06@ufromail.cl)
*          Daniel Isaac Trafian Millán. (d.trafian01@ufromail.cl)
*
* Fecha: 14/11/2021
*
* Dado que existen diversas herramientas que nos ayudan con el proceso de remuneración y gestión de datos y horarios en una empresa en específico,
* en algunos casos se dificulta su uso, por lo que decidimos crear un algoritmo que se encargará de forma directa de este problema. 
* El algoritmo se encargará de evaluar y solicitar datos al usuario para facilitar el cálculo de las horas trabajadas. 
* Este programa presenta una mejora en comparación al anterior, ya que en este caso implementamos el TDA de lista principalmente, 
* el cual se encarga de recapitular, guardar y mostrar los datos ingresados por el trabajador para que luego el gerente o la persona encargada,
* sea capaz de modificar los datos de los trabajadores si lo desea.
*/

#include <stdio.h>
#include<string.h>
#include "TDA-Lista-v2/lista.h"
#include "libreriaHorarios.h"

int main(){
  // Variables estáticas "secundarias".
  int TotalEmpleados;
  int opcion;

  // Variables estáticas "principales" de tipo horario que serán las que el usuario ira registrando.
  Horario EntradaJornadaLunes, SalidaJornadaLunes;
  Horario EntradaJornadaMartes, SalidaJornadaMartes;
  Horario EntradaJornadaMiercoles, SalidaJornadaMiercoles;
  Horario EntradaJornadaJueves, SalidaJornadaJueves;
  Horario EntradaJornadaViernes, SalidaJornadaViernes;
  Horario EntradaJornadaSabado, SalidaJornadaSabado;
  
  Lista lista;
  int numFuncionarioLista;

  do{
    // Menu del manejo de Lista
    implementacionLista(&opcion);
    // Ofrece opciones para edición o revisión de las implementaciones del TDA-Lista.
    if(opcion == 1){

      // Funcion que determinará el número de procesos a ejecutarse
      CantidadTotalFuncionarios(&TotalEmpleados);
      // Se crea el archivo que contendrá los datos y el resumen.
      FILE* archivoResumen = fopen("Resumen_Colaborador.txt", "a+");
      fclose(archivoResumen);

      for(int i = 0 ; i < TotalEmpleados ; i++){
        // Funcion que da la bienvenida al colaborador, a la interfaz interactiva.
        Presentacion();
        // Variable de tipo Empleados que almacena los datos del funcionario que ha sido ingresado.
        nuevoIngresoTrabajador(lista);
        DatosTrabajadorIngresado(lista);
        // Corroboración del ingreso de datos para reingresar sus datos en caso de algún error.
        ConfirmarIngresoDeDatos(&opcion);
        if(opcion == 1){
          // Presentacion de la Tabla-Resumen que se le solicitará al funcionario rellenar
          TableroResumenSemanal(EntradaJornadaLunes, SalidaJornadaLunes, EntradaJornadaMartes, SalidaJornadaMartes, EntradaJornadaMiercoles, SalidaJornadaMiercoles, EntradaJornadaJueves, SalidaJornadaJueves, EntradaJornadaViernes, SalidaJornadaViernes, EntradaJornadaSabado, SalidaJornadaSabado);
          printf("Sus datos han sido ingresados correctamente!!\nPor favor, rellene el tablero con los horarios de esta semana:\n");
        } else{
          i --;
          continue;
        }

        // Ingresos de los horarios ejercidos de Lunes a Sábado y cálculo de los minutos trabajados por día.

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
        
        // Cálculo de la remuneración semanal del colaborador de acuerdo al tiempo total empleado durante la semana.
        int sueldoFuncionario = calcularSueldoSemanal(TotalMinutosJornada1, TotalMinutosJornada2, TotalMinutosJornada3, TotalMinutosJornada4, TotalMinutosJornada5, TotalMinutosJornada6);
        imprimirSueldoSemanal(sueldoFuncionario);

      // Completación de archivo-resumen, con los datos y evaluaciones de acuerdo a las exigencias minimas de la empresa.
        FILE* archivoResumen = fopen("Resumen_Colaborador.txt", "a+");
        ResumenAGerente(lista, archivoResumen, TotalMinutosJornada1, TotalMinutosJornada2, TotalMinutosJornada3, TotalMinutosJornada4, TotalMinutosJornada5, TotalMinutosJornada6);
      }
      // Se da fin a la modificación del archivo y se termina la ejecución.
      fclose(archivoResumen);
      continue;
    } else if(opcion == 2){
      // Opcion que da acceso a la revisión y edición de la lista.
      opcionesManejoDLista(lista, &opcion, &numFuncionarioLista);

      if(opcion == 3){
        printf("\nOperacion cancelada.\n");
      }
      
      continue;
    } else{
      printf("\nHASTA PRONTO !!!!\n");
      break;
    }

  } while((opcion <= 1) || (opcion >= 2));

  return 0;
}