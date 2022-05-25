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
    TipoEmpleado* idSupervisor;

    public:

    TipoEmpleado(int idEmpleado, string nombre, string apellido, string email, int tipoEmpleado, TipoEmpleado* idSupervisor);
    virtual double calcularPago() = 0;
}; 
#endif