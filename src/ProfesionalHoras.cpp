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


istream& operator >> (istream &i, ProfesionalHoras *profesionalHoras){
    i >> profesionalHoras->idEmpleado >> profesionalHoras->nombre >> profesionalHoras->apellido >> profesionalHoras->email >> profesionalHoras->tipoEmpleado >> profesionalHoras->idSupervisor;
    return i;
}
ostream& operator << (ostream &o, const ProfesionalHoras *profesionalHoras){
    o << profesionalHoras->idEmpleado << "," << profesionalHoras->nombre << "," << profesionalHoras->apellido << "," << profesionalHoras->email << "," << profesionalHoras->tipoEmpleado << "," << profesionalHoras->idSupervisor;
    return o;
}