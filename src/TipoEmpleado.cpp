#include "TipoEmpleado.h"
#include <string>
using namespace std;

int TipoEmpleado::obtenerIdEmpleado(){
    return this->idEmpleado;
}

int TipoEmpleado::obtenerIdSupervisor(){
    return this->idSupervisor;
}

string TipoEmpleado::obtenerNombre(){
    return this->nombre;
}

TipoEmpleado* TipoEmpleado::obtenerSupervisor(){
    return this->supervisor;
}

void TipoEmpleado::insertarHijo(TipoEmpleado *hijo){
    this->hijos.push_back(hijo);
}

string TipoEmpleado::obtenerNombreSupervisor(){
    return this->supervisor->nombre;
}

void TipoEmpleado::asignarSupervisor(TipoEmpleado *supervisor){
    this->supervisor=supervisor;
    this->nombreSupervisor=supervisor->nombre;
    this->apellidoSupervisor=supervisor->apellido;
}

double TipoEmpleado::obtenerImpuestoRetenido(){
    return this->impuestoRetenido;
}
double TipoEmpleado::obtenerMontoAPagar(){
    return this->montoAPagar;
}


void TipoEmpleado::leerNomina(istream &i){
    i >> this->idEmpleado >> this->pagoMensual;
}

void TipoEmpleado::leerProfesional(istream &i){
    i >> this->idEmpleado >> this->montoHoras >> this->horasLaboradas;
}

istream& operator >> (istream &i, TipoEmpleado *tipoEmpleado){
    i >> tipoEmpleado->idEmpleado >> tipoEmpleado->nombre >> tipoEmpleado->apellido >> tipoEmpleado->email >> tipoEmpleado->tipoEmpleado >> tipoEmpleado->idSupervisor;
    return i;
}
ostream& operator << (ostream &o, const TipoEmpleado *tipoEmpleado){
    o << tipoEmpleado->idEmpleado << ", " << tipoEmpleado->nombre << " " << tipoEmpleado->apellido << ", " << tipoEmpleado->nombreSupervisor << " " << tipoEmpleado->apellidoSupervisor << ", "  << tipoEmpleado->montoAPagar;
    return o;
}