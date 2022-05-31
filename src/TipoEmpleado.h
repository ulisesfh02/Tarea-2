#ifndef TIPOEMPLEADO
#define TIPOEMPLEADO

using namespace std;
#include <iostream>
#include <string>

class TipoEmpleado{

    protected:

    int idEmpleado;
    string nombre;
    string apellido;
    string email;
    int tipoEmpleado;
    int idSupervisor;

    public:
    virtual double calcularPago() = 0;
    virtual int getIdEmpleado();

    friend istream& operator >> (istream &i, TipoEmpleado *tipoEmpleado);
    friend ostream& operator << (ostream &o, const TipoEmpleado *tipoEmpleado);

}; 
#endif