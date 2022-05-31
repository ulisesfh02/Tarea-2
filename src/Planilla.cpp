#include "Planilla.h"
#include "ProfesionalHoras.h"
#include "EmpleadoNomina.h"
#include <iostream>
#include <sstream>
#include <string>
#include "TipoEmpleado.h"

using namespace std;

Planilla::Planilla(){
}

Planilla::~Planilla(){
    for(TipoEmpleado *empleado : this->empleados){
        delete empleado;
    }
}

void Planilla::agregarEmpleado(TipoEmpleado * empleado){
    this->empleados.push_back(empleado);
}

istream& operator >> (istream &i, Planilla *planilla){
    string linea;
    string num;


    while(getline(i, linea) && num!="450"){
    num="";
    num+= linea[0];
    num+= linea[1];
    num+= linea[2];
    cout<< num <<endl;
    
    istringstream streamLinea(linea);

    ProfesionalHoras *nuevoEmpleado = new ProfesionalHoras();
    streamLinea >> nuevoEmpleado;

    planilla->agregarEmpleado(nuevoEmpleado);
    }

    istringstream streamLinea(linea);
    EmpleadoNomina *nuevoEmpleado = new EmpleadoNomina();
    streamLinea >> nuevoEmpleado;

    planilla->agregarEmpleado(nuevoEmpleado);

    while(getline(i, linea)){
    num="";
    num+= linea[0];
    num+= linea[1];
    num+= linea[2];
    cout<< num <<endl;
    
    istringstream streamLinea(linea);

    EmpleadoNomina *nuevoEmpleado = new EmpleadoNomina();
    streamLinea >> nuevoEmpleado;

    planilla->agregarEmpleado(nuevoEmpleado);
    }
    return i;
}
ostream& operator << (ostream &o, const Planilla *planilla){

    for(TipoEmpleado *empleado : planilla->empleados){
        o << empleado << endl;
    }
    return o;
}
