#ifndef PROFESIONALHORAS
#define PROFESIONALHORAS

#include "TipoEmpleado.h"
using namespace std;
#include <string>

class ProfesionalHoras: public TipoEmpleado{

    public:

    double calcularPago();

}; 
#endif