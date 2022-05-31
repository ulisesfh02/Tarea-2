#include "ProfesionalHoras.h"
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
}

ProfesionalHoras::~ProfesionalHoras(){
}

double ProfesionalHoras::calcularPago(){
    return 0;
}

