// Estructuras de datos para registro de datos e información proporcionada por el usuario
struct Horario{
  int hora = 0;
  int minutos = 0;
};
struct Empleados{
  char nombre[15];
  char primerApellido[20];
  char segundoApellido[20];
  char run[13];
  long telefono;
  char correo[50];
  int dia, mes, anho;  
};
/*
struct JornadaSemanal{
  char primerDia[6] = "Lunes";
  char segundoDia[7] = "Martes";
  char tercerDia[10] = "Miercoles";
  char cuartoDia[7] = "Jueves";
  char quintoDia[8] = "Viernes";
  char sextoDia[7] = "Sabado";
};
*/