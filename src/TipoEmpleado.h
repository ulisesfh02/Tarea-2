#ifndef TIPOEMPLEADO
#define TIPOEMPLEADO

using namespace std;
#include <string>

class TipoEmpleado{

    protected:

    int idEmpleado;
    string nombre;
    string apellido;
    string email;
    int tipoEmpleado;
    int idSupervisor;

}; 
#endif