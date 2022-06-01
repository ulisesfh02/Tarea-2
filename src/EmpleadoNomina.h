#ifndef EMPLEADONOMINA
#define EMPLEADONOMINA

#include "TipoEmpleado.h"
using namespace std;
#include <string>

class EmpleadoNomina: public TipoEmpleado{

    double pagoMensual;

    public:
    EmpleadoNomina();
    EmpleadoNomina(int, string, string, string, int, int);
    ~EmpleadoNomina();
    double calcularPago();

    void leerNomina(istream &i);
}; 
#endif