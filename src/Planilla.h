#ifndef PLANILLA
#define PLANILLA

#include "TipoEmpleado.h"
#include "ProfesionalHoras.h"
#include <vector>
#include <iostream>

class Planilla{
    TipoEmpleado *director;

    vector<TipoEmpleado*> empleados;

    public:
    Planilla();
    ~Planilla();

    void agregarEmpleado(TipoEmpleado * empleado);
    TipoEmpleado * buscarEmpleado(int idEmpleado);

    friend istream& operator >> (istream &i, Planilla *planilla);
    friend ostream& operator << (ostream &o, const Planilla *planilla);
};

#endif