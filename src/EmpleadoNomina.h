#ifndef EMPLEADONOMINA
#define EMPLEADONOMINA

#include "TipoEmpleado.h"
using namespace std;
#include <string>

class EmpleadoNomina: public TipoEmpleado{

    public:
    EmpleadoNomina();
    EmpleadoNomina(int, string, string, string, int, int);
    ~EmpleadoNomina();
    
    void calcularPago();

}; 
#endif