all:
	g++ -c libreriaHorarios.cpp
	g++ -c algoritmoTarea1.cpp
	g++ -o ejec libreriaHorarios.o algoritmoTarea1.o
	./ejec
	