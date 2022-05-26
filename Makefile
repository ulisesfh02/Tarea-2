FLAGS = -g -c --std=c++17

all:
	mkdir -p bin
	g++ $(FLAGS) src/TipoEmpleado.cpp -o bin/TipoEmpleado.o
	g++ $(FLAGS) src/ProfesionalHoras.cpp -o bin/ProfesionalHoras.o
	g++ $(FLAGS) src/Planilla.cpp -o bin/Planilla.o
	g++ $(FLAGS) src/main.cpp -o bin/main.o
	g++ -g -o bin/planilla bin/TipoEmpleado.o bin/ProfesionalHoras.o bin/Planilla.o bin/main.o
test:
	mkdir -p bin
	g++ $(FLAGS) tests/tests_envio_fedex.cpp -o bin/tests_envio_fedex.o
	g++ $(FLAGS) tests/tests_envio_serviciopostal.cpp -o bin/tests_envio_serviciopostal.o
	g++ $(FLAGS) src/FedEX.cpp -o bin/FedEX.o
	g++ $(FLAGS) src/ServicioPostal.cpp -o bin/ServicioPostal.o
	g++ -g -o bin/tests bin/tests_envio_fedex.o bin/tests_envio_serviciopostal.o bin/FedEX.o bin/ServicioPostal.o -lgtest -lgtest_main -lpthread
clean:
	rm -Rf bin
