#ifndef PROFESIONALHORAS
#define PROFESIONALHORAS

#include "TipoEmpleado.h"
using namespace std;
#include <string>
#include <iostream>

class ProfesionalHoras: public TipoEmpleado{

    double montoHoras;
    double horasLaboradas;

    public:
    ProfesionalHoras();
    ProfesionalHoras(int, string, string, string, int, int);
    ~ProfesionalHoras();

    void leerProfesional(istream &i);
    double calcularPago();
}; 
#endif