#ifndef TIPOEMPLEADO
#define TIPOEMPLEADO

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TipoEmpleado{

    protected:

    int idEmpleado;
    string nombre;
    string apellido;
    string email;
    int tipoEmpleado;
    int idSupervisor;
    TipoEmpleado * supervisor;
    vector<TipoEmpleado*> hijos;

    string nombreSupervisor;
    string apellidoSupervisor;
    
    double montoAPagar;
    double pagoMensual;
    double montoHoras;
    double horasLaboradas;
    double impuestoRetenido;
    
    public:
    
    virtual int obtenerIdEmpleado();
    virtual int obtenerIdSupervisor();
    virtual double obtenerImpuestoRetenido();
    virtual double obtenerMontoAPagar();

    virtual void insertarHijo(TipoEmpleado*);
    virtual void asignarSupervisor(TipoEmpleado*);

    virtual void leerNomina(istream &i);
    virtual void leerProfesional(istream &i);

    friend istream& operator >> (istream &i, TipoEmpleado *tipoEmpleado);
    friend ostream& operator << (ostream &o, const TipoEmpleado *tipoEmpleado);

    virtual void calcularPago() = 0;
}; 
#endif