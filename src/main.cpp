#include "TipoEmpleado.h"
#include "EmpleadoNomina.h"
#include "Planilla.h"

#include <sstream>
#include <fstream>
#include <map>
#include <iostream>
#include <string>

using namespace std;

int main(){

    Planilla *planilla = new Planilla();

    string nombreArchivo = "personas.txt";

    ifstream archivoPersonas(nombreArchivo, ifstream::in); // Por default abriendo como texto

    if (!archivoPersonas.is_open())
    {
        cerr << "Error leyendo archivo personas.txt" << endl;
        return -1;
    }

    
    archivoPersonas >> planilla;

    cout << planilla;

    archivoPersonas.close();

    delete planilla;

    return 0;
}