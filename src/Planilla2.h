#ifndef PLANILLA2
#define PLANILLA2

#include "TipoEmpleado.h"
#include "ProfesionalHoras.h"
#include "EmpleadoNomina.h"
#include <vector>
#include <iostream>

class Planilla2{

    TipoEmpleado *director;

    vector<TipoEmpleado*> empleados;

    istream *personas;
    istream *nomina;
    istream *horas;

    public:
    Planilla2(istream*, istream*, istream*);
    ~Planilla2();

    void agregarEmpleado(TipoEmpleado * empleado);
    void leerArchivos();

    friend ostream& operator << (ostream &o, const Planilla2 *planilla);
};

#endif