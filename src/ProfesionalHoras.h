#ifndef PROFESIONALHORAS
#define PROFESIONALHORAS

#include "TipoEmpleado.h"
#include <string>

using namespace std;

class ProfesionalHoras: public TipoEmpleado{

    public:
    ProfesionalHoras();
    ProfesionalHoras(int, string, string, string, int, int);
    ~ProfesionalHoras();

    void calcularPago();
}; 
#endif