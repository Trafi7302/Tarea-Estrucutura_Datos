all:
	g++ libreriaHorarios.cpp -c
	g++ algoritmoTarea1.cpp -c
	g++ ./TDA-Lista-v2/lista.cpp -c
	g++ -o ejec libreriaHorarios.o algoritmoTarea1.o lista.o
	rm *.o
	./ejec

	