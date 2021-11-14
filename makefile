all:
	g++ libreriaHorarios.cpp -c
	g++ algoritmoTarea.cpp -c
	g++ ./TDA-Lista-v2/lista.cpp -c
	g++ -o ejec libreriaHorarios.o algoritmoTarea.o lista.o
	rm *.o
	./ejec

	