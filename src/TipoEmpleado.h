#ifndef TIPOEMPLEADO
#define TIPOEMPLEADO

using namespace std;
#include <iostream>
#include <string>
#include <vector>

class TipoEmpleado{

    protected:

    int idEmpleado;
    string nombre;
    string apellido;
    string email;
    string nombreSupervisor;
    string apellidoSupervisor;
    int tipoEmpleado;
    int idSupervisor;
    TipoEmpleado * supervisor;
    vector<TipoEmpleado*> hijos;
    double montoAPagar;
    double pagoMensual;
    double montoHoras;
    double horasLaboradas;
    double impuestoRetenido;
    

    public:
    
    virtual int obtenerIdEmpleado();
    virtual int obtenerIdSupervisor();
    virtual void asignarSupervisor(TipoEmpleado*);
    virtual void insertarHijo(TipoEmpleado*);
    virtual TipoEmpleado* obtenerSupervisor();
    virtual string obtenerNombre();
    virtual string obtenerNombreSupervisor();
    virtual double obtenerImpuestoRetenido();
    virtual double obtenerMontoAPagar();

    virtual void leerNomina(istream &i);
    virtual void leerProfesional(istream &i);

    virtual void calcularPago() = 0;

    friend istream& operator >> (istream &i, TipoEmpleado *tipoEmpleado);
    friend ostream& operator << (ostream &o, const TipoEmpleado *tipoEmpleado);

}; 
#endif