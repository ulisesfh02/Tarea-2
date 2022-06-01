#include "Planilla2.h"
#include <iostream>
#include <sstream>

Planilla2::Planilla2(istream *personas, istream *nomina, istream *horas){
    this->personas= personas;
    this->nomina=nomina;
    this->horas=horas;
}

Planilla2::~Planilla2(){
    for(TipoEmpleado *empleado : this->empleados){
        delete empleado;
    }
}

void Planilla2::agregarEmpleado(TipoEmpleado * empleado){
    this->empleados.push_back(empleado);
}

void Planilla2::leerArchivos(){
    string linea;
    string num;
    string lineaNomina;
    string lineaProfesional;


    while(getline(*(this->personas), linea) && num!="450" && getline(*(this->nomina), lineaNomina)){
    num="";
    num+= linea[0];
    num+= linea[1];
    num+= linea[2];
    
    istringstream streamLinea(linea);

    EmpleadoNomina *nuevoEmpleado = new EmpleadoNomina();
    streamLinea >> nuevoEmpleado;

    istringstream streamNomina(lineaNomina);
    nuevoEmpleado->leerNomina(streamNomina);

    empleados.push_back(nuevoEmpleado);
    }

    istringstream streamLinea(linea);

    ProfesionalHoras *nuevoEmpleado = new ProfesionalHoras();
    streamLinea >> nuevoEmpleado;

    getline(*(this->horas), lineaProfesional);
    istringstream streamProfesional(lineaProfesional);
    nuevoEmpleado->leerProfesional(streamProfesional);

    empleados.push_back(nuevoEmpleado);

    while(getline(*(this->personas), linea) && getline(*(this->horas), lineaProfesional)){
    num="";
    num+= linea[0];
    num+= linea[1];
    num+= linea[2];
    
    istringstream streamLinea(linea);

    ProfesionalHoras *nuevoEmpleado = new ProfesionalHoras();
    streamLinea >> nuevoEmpleado;

    istringstream streamProfesional(lineaProfesional);
    nuevoEmpleado->leerProfesional(streamProfesional);

    empleados.push_back(nuevoEmpleado);
    }
}

ostream& operator << (ostream &o, const Planilla2 *planilla2){
    for(TipoEmpleado *empleado : planilla2->empleados){
        o << empleado << endl;
    }
    return o;
}