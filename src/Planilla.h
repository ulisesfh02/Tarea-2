#ifndef PLANILLA
#define PLANILLA

#include "TipoEmpleado.h"
#include <vector>

class Planilla{

    vector<TipoEmpleado *> empleados;

    public:
    Planilla();
    ~Planilla();

    void agregarEmpleado(TipoEmpleado * empleado);

    friend istream& operator >> (istream &i, Planilla *planilla);
    friend ostream& operator << (ostream &i, const Planilla *planilla);

};

#endif