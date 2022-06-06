#include "ProfesionalHoras.h"
#include <iostream>

using namespace std;

ProfesionalHoras::ProfesionalHoras(){
}

ProfesionalHoras::ProfesionalHoras(int idEmpleado, string nombre, string apellido, string email, int tipoEmpleado, int idSupervisor){
    this->idEmpleado=idEmpleado;
    this->nombre=nombre;
    this->apellido=apellido;
    this->email=email;
    this->tipoEmpleado=tipoEmpleado;
    this->idSupervisor=idSupervisor;
    this->montoHoras=0;
    this->horasLaboradas=0;
}

ProfesionalHoras::~ProfesionalHoras(){
}

void ProfesionalHoras::calcularPago(){
    this->montoAPagar=this->montoHoras*this->horasLaboradas;
}

