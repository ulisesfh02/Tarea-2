#include "ProfesionalHoras.h"
using namespace std;

#include <iostream>

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

double ProfesionalHoras::calcularPago(){
    return 0;
}

void ProfesionalHoras::leerProfesional(istream &i){
    i >> this->idEmpleado >> this->montoHoras >> this->horasLaboradas;
    cout << this->montoHoras << ", " << this->horasLaboradas << endl;
}

