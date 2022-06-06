#include "Planilla.h"
#include <iostream>
#include <sstream>

Planilla::Planilla(){
}

Planilla::Planilla(istream *personas, istream *nomina, istream *horas){
    this->personas= personas;
    this->nomina=nomina;
    this->horas=horas;
}

Planilla::~Planilla(){
    for(pair<int, TipoEmpleado*> empleado: this->empleados){
        delete empleado.second;
    }
}

void Planilla::leerArchivos(){
    string linea;
    string idCheck;
    string lineaNomina;
    string lineaProfesional;

    //--------------------------------------------------//

    getline(*(this->personas), linea);
    istringstream streamLinea(linea);
    EmpleadoNomina *director = new EmpleadoNomina();
    streamLinea >> director; 
    this->director = director;

    this->director->asignarSupervisor(this->director);

    getline(*(this->nomina), lineaNomina);
    istringstream streamNomina(lineaNomina);
    this->director->leerNomina(streamNomina);
    this->director->calcularPago();

    this->empleados.insert(pair<int, TipoEmpleado*> (director->obtenerIdEmpleado(), this->director));
    

    while(getline(*(this->personas), linea) && idCheck!="450" && getline(*(this->nomina), lineaNomina)){
        idCheck="";
        idCheck+= linea[0];
        idCheck+= linea[1];
        idCheck+= linea[2];
        
        
        istringstream streamLinea(linea);

        EmpleadoNomina *nuevoEmpleadoNomina = new EmpleadoNomina();
        streamLinea >> nuevoEmpleadoNomina;

        TipoEmpleado *supervisor = this->empleados.at(nuevoEmpleadoNomina->obtenerIdSupervisor());

        supervisor->insertarHijo(nuevoEmpleadoNomina);
        nuevoEmpleadoNomina->asignarSupervisor(supervisor);


        istringstream streamNomina(lineaNomina);
        nuevoEmpleadoNomina->leerNomina(streamNomina);
        nuevoEmpleadoNomina->calcularPago();

        this->empleados.insert(pair<int, TipoEmpleado*> (nuevoEmpleadoNomina->obtenerIdEmpleado(), nuevoEmpleadoNomina));
    }

    istringstream streamLineab(linea);

    ProfesionalHoras *primerProfesionalHoras = new ProfesionalHoras();
    streamLineab >> primerProfesionalHoras;

    TipoEmpleado *supervisor = this->empleados.at(primerProfesionalHoras->obtenerIdSupervisor());

    supervisor->insertarHijo(primerProfesionalHoras);
    primerProfesionalHoras->asignarSupervisor(supervisor);

    getline(*(this->horas), lineaProfesional);
    istringstream streamProfesional(lineaProfesional);
    primerProfesionalHoras->leerProfesional(streamProfesional);
    primerProfesionalHoras->calcularPago();

    this->empleados.insert(pair<int, TipoEmpleado*> (primerProfesionalHoras->obtenerIdEmpleado(), primerProfesionalHoras));
    

    while(getline(*(this->personas), linea) && getline(*(this->horas), lineaProfesional)){
        idCheck="";
        idCheck+= linea[0];
        idCheck+= linea[1];
        idCheck+= linea[2];
        
        istringstream streamLinea(linea);

        ProfesionalHoras *nuevoProfesionalHoras = new ProfesionalHoras();
        streamLinea >> nuevoProfesionalHoras;

        TipoEmpleado *supervisor = this->empleados.at(nuevoProfesionalHoras->obtenerIdSupervisor());

        supervisor->insertarHijo(nuevoProfesionalHoras);
        nuevoProfesionalHoras->asignarSupervisor(supervisor);

        istringstream streamProfesional(lineaProfesional);
        nuevoProfesionalHoras->leerProfesional(streamProfesional);
        nuevoProfesionalHoras->calcularPago();
    
        this->empleados.insert(pair<int, TipoEmpleado*> (nuevoProfesionalHoras->obtenerIdEmpleado(), nuevoProfesionalHoras));
        
    }
}

ostream& operator << (ostream &o, const Planilla *planilla){
    double impuestoTotal=0;
    double subtotal=0;
    double total=0;
    for(pair<int, TipoEmpleado*> empleado: planilla->empleados){
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