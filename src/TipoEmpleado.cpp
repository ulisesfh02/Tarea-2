#include "TipoEmpleado.h"
#include <string>
using namespace std;

int TipoEmpleado::getIdEmpleado(){
    return this->idEmpleado;
}

istream& operator >> (istream &i, TipoEmpleado *tipoEmpleado){
    i >> tipoEmpleado->idEmpleado >> tipoEmpleado->nombre >> tipoEmpleado->apellido >> tipoEmpleado->email >> tipoEmpleado->tipoEmpleado >> tipoEmpleado->idSupervisor;
    return i;
}
ostream& operator << (ostream &o, const TipoEmpleado *tipoEmpleado){
    o << tipoEmpleado->idEmpleado << "," << tipoEmpleado->nombre << " " << tipoEmpleado->apellido << "," << tipoEmpleado->supervisor->nombre << " " << tipoEmpleado->supervisor->apellido << "," << tipoEmpleado->montoAPagar;
    return o;
}