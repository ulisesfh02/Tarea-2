#include "Planilla.h"
#include <iostream>
#include <sstream>
#include <string>

Planilla::Planilla(){
}

Planilla::~Planilla(){
    for(TipoEmpleado* empleado: this->empleados){
        delete empleado;
    }
}

void Planilla::agregarEmpleado(TipoEmpleado * empleado){
    this->empleados.push_back(empleado);
}

istream& operator >> (istream &i, Planilla *planilla){
}
ostream& operator << (ostream &i, const Planilla *planilla){
}
