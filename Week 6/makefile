application: functions.o application.o
	g++ functions.o application.o -o application
application.o : application.cpp film.h 
	g++ -c application.cpp -o application.o
filmfunctions.o: 
	g++ -c filmfunctions.cpp -o functions.o