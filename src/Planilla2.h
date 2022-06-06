#ifndef PLANILLA2
#define PLANILLA2

#include "TipoEmpleado.h"
#include "ProfesionalHoras.h"
#include "EmpleadoNomina.h"
#include <map>
#include <iostream>

class Planilla2{

    TipoEmpleado *director;

    map<int, TipoEmpleado*> empleados;

    istream *personas;
    istream *nomina;
    istream *horas;

    public:
    Planilla2(istream*, istream*, istream*);
    ~Planilla2();

    void leerArchivos();
    TipoEmpleado* obtenerSupervisor(int idEmpleado);

    friend ostream& operator << (ostream &o, const Planilla2 *planilla);
};

#endif