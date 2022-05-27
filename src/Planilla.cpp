#include "Planilla.h"
#include "ProfesionalHoras.h"
#include <iostream>
#include <sstream>
#include <string>
#include "TipoEmpleado.h"

using namespace std;

Planilla::Planilla(){
}

Planilla::~Planilla(){
    for(pair<int, TipoEmpleado *> empleado : this->empleados){
        delete empleado.second;
    }
}

void Planilla::agregarEmpleado(TipoEmpleado * empleado){
    this->empleados.insert(pair<int, TipoEmpleado *>(empleado->getIdEmpleado(), empleado));
}

istream& operator >> (istream &i, Planilla *planilla){
    string linea;

    while(getline(i, linea)){
        istringstream streamLinea(linea);

        ProfesionalHoras *nuevoEmpleado = new ProfesionalHoras();
        streamLinea >> nuevoEmpleado;

        planilla->agregarEmpleado(nuevoEmpleado);
    }
    return i;
}
ostream& operator << (ostream &o, const Planilla *planilla){

    for(pair<int, TipoEmpleado *> empleado : planilla->empleados){
        o << empleado.second << endl;
    }
    return o;
}
