#ifndef PLANILLA
#define PLANILLA

#include "TipoEmpleado.h"
#include "ProfesionalHoras.h"
#include "EmpleadoNomina.h"
#include <map>
#include <iostream>

class Planilla{

    TipoEmpleado *director;
    map<int, TipoEmpleado*> empleados;

    istream *personas;
    istream *nomina;
    istream *horas;

    public:
    
    Planilla(istream*, istream*, istream*);
    ~Planilla();

    void leerArchivos();

    friend ostream& operator << (ostream &o, const Planilla *planilla);
};

#endif