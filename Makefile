FLAGS = -g -c --std=c++17

all:
	mkdir -p bin
	g++ $(FLAGS) src/TipoEmpleado.cpp -o bin/TipoEmpleado.o
	g++ $(FLAGS) src/ProfesionalHoras.cpp -o bin/ProfesionalHoras.o
	g++ $(FLAGS) src/EmpleadoNomina.cpp -o bin/EmpleadoNomina.o
	g++ $(FLAGS) src/Planilla.cpp -o bin/Planilla.o
	g++ $(FLAGS) src/main.cpp -o bin/main.o
	g++ -g -o bin/planilla bin/TipoEmpleado.o bin/ProfesionalHoras.o bin/EmpleadoNomina.o bin/Planilla.o bin/main.o
test:
	mkdir -p bin
	g++ $(FLAGS) tests/tests_empleadoNomina.cpp -o bin/tests_empleadoNomina.o
	g++ $(FLAGS) tests/tests_profesionalHoras.cpp -o bin/tests_profesionalHoras.o
	g++ -g -o bin/tests bin/tests_empleadoNomina.o bin/tests_profesionalHoras.o -lgtest -lgtest_main -lpthread
clean:
	rm -Rf bin
