#include "TipoEmpleado.h"
#include <string>
using namespace std;

TipoEmpleado::TipoEmpleado(int idEmpleado, string nombre, string apellido, string email, int tipoEmpleado, TipoEmpleado* idSupervisor){
    this->idEmpleado=idEmpleado;
    this->nombre=nombre;
    this->apellido=apellido;
    this->email=email;
    this->tipoEmpleado=tipoEmpleado;
    this->idSupervisor=idSupervisor;
}