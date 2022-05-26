#ifndef PLANILLA
#define PLANILLA

#include "TipoEmpleado.h"
#include <map>

class Planilla{
    TipoEmpleado *director;

    map<int, TipoEmpleado *> empleados;

    public:
    Planilla();
    ~Planilla();

    void agregarEmpleado(TipoEmpleado * empleado);
    TipoEmpleado * buscarEmpleado(int idEmpleado);

    friend istream& operator >> (istream &i, Planilla *planilla);
    friend ostream& operator << (ostream &i, const Planilla *planilla);
};

#endif