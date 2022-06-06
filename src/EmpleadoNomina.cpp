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

void EmpleadoNomina::calcularPago(){
    this->impuestoRetenido= pagoMensual*0.07;
    this->montoAPagar = pagoMensual-impuestoRetenido;
}
