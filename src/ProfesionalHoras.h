#ifndef PROFESIONALHORAS
#define PROFESIONALHORAS

#include "TipoEmpleado.h"
using namespace std;
#include <string>
#include <iostream>

class ProfesionalHoras: public TipoEmpleado{

    public:
    ProfesionalHoras();
    ProfesionalHoras(int, string, string, string, int, int);
    ~ProfesionalHoras();

    double calcularPago();

}; 
#endif