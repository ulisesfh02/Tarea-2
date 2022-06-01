#include "EmpleadoNomina.h"
using namespace std;

#include <iostream>

EmpleadoNomina::EmpleadoNomina(){
}

EmpleadoNomina::EmpleadoNomina(int idEmpleado, string nombre, string apellido, string email, int tipoEmpleado, int idSupervisor){
    this->idEmpleado=idEmpleado;
    this->nombre=nombre;
    this->apellido=apellido;
    this->email=email;
    this->tipoEmpleado=tipoEmpleado;
    this->idSupervisor=idSupervisor;
    this->pagoMensual=0;
    
}

EmpleadoNomina::~EmpleadoNomina(){
}

double EmpleadoNomina::calcularPago(){
    return 0;
}

void EmpleadoNomina::leerNomina(istream &i){
    i >> this->idEmpleado >> this->pagoMensual;
    cout << pagoMensual<< endl;
}
