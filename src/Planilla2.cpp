#include "Planilla2.h"
#include <iostream>
#include <sstream>

Planilla2::Planilla2(istream *personas, istream *nomina, istream *horas){
    this->personas= personas;
    this->nomina=nomina;
    this->horas=horas;
}

Planilla2::~Planilla2(){
    for(pair<int, TipoEmpleado*> empleado: this->empleados){
        delete empleado.second;
    }
}

void Planilla2::leerArchivos(){
    string linea;
    string num;
    string lineaNomina;
    string lineaProfesional;

    
    getline(*(this->personas), linea);
    istringstream streamLinea(linea);
    EmpleadoNomina *nuevoEmpleado3 = new EmpleadoNomina();
    streamLinea >> nuevoEmpleado3; 
    this->director = nuevoEmpleado3;

    this->director->asignarSupervisor(this->director);

    getline(*(this->nomina), lineaNomina);
    istringstream streamNomina(lineaNomina);
    this->director->leerNomina(streamNomina);
    this->director->calcularPago();

    this->empleados.insert(pair<int, TipoEmpleado*> (director->obtenerIdEmpleado(), this->director));
    

    while(getline(*(this->personas), linea) && num!="450" && getline(*(this->nomina), lineaNomina)){
        num="";
        num+= linea[0];
        num+= linea[1];
        num+= linea[2];
        
        
        istringstream streamLinea(linea);

        EmpleadoNomina *nuevoEmpleado = new EmpleadoNomina();
        streamLinea >> nuevoEmpleado;

        TipoEmpleado *supervisor = this->empleados.at(nuevoEmpleado->obtenerIdSupervisor());

        supervisor->insertarHijo(nuevoEmpleado);
        nuevoEmpleado->asignarSupervisor(supervisor);


        istringstream streamNomina(lineaNomina);
        nuevoEmpleado->leerNomina(streamNomina);
        nuevoEmpleado->calcularPago();

        this->empleados.insert(pair<int, TipoEmpleado*> (nuevoEmpleado->obtenerIdEmpleado(), nuevoEmpleado));
    }

    istringstream str2(linea);

    ProfesionalHoras *nuevoEmpleado2 = new ProfesionalHoras();
    str2 >> nuevoEmpleado2;

    TipoEmpleado *supervisor = this->empleados.at(nuevoEmpleado2->obtenerIdSupervisor());

    supervisor->insertarHijo(nuevoEmpleado2);
    nuevoEmpleado2->asignarSupervisor(supervisor);

    getline(*(this->horas), lineaProfesional);
    istringstream streamProfesional(lineaProfesional);
    nuevoEmpleado2->leerProfesional(streamProfesional);
    nuevoEmpleado2->calcularPago();

    this->empleados.insert(pair<int, TipoEmpleado*> (nuevoEmpleado2->obtenerIdEmpleado(), nuevoEmpleado2));
    

    while(getline(*(this->personas), linea) && getline(*(this->horas), lineaProfesional)){
        num="";
        num+= linea[0];
        num+= linea[1];
        num+= linea[2];
        
        istringstream streamLinea(linea);

        ProfesionalHoras *nuevoEmpleado = new ProfesionalHoras();
        streamLinea >> nuevoEmpleado;

        TipoEmpleado *supervisor = this->empleados.at(nuevoEmpleado->obtenerIdSupervisor());

        supervisor->insertarHijo(nuevoEmpleado);
        nuevoEmpleado->asignarSupervisor(supervisor);

        istringstream streamProfesional(lineaProfesional);
        nuevoEmpleado->leerProfesional(streamProfesional);
        nuevoEmpleado->calcularPago();
    
        this->empleados.insert(pair<int, TipoEmpleado*> (nuevoEmpleado->obtenerIdEmpleado(), nuevoEmpleado));
        
    }
}

ostream& operator << (ostream &o, const Planilla2 *planilla2){
    double impuestoTotal=0;
    double subtotal=0;
    double total=0;
    for(pair<int, TipoEmpleado*> empleado: planilla2->empleados){
        o << empleado.second << endl;
        impuestoTotal += empleado.second->obtenerImpuestoRetenido();
        subtotal += empleado.second->obtenerMontoAPagar();
    }
    total = impuestoTotal+subtotal;
    o << "Subtotal" << "," << subtotal << endl;
    o << "Impuestos Retenidos" << "," << impuestoTotal << endl;
    o << "Total" << "," << total << endl;
    
    return o;
}