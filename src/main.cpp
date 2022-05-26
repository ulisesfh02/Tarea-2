#include "TipoEmpleado.h"
#include "EmpleadoNomina.h"
#include "ProfesionalHoras.h"
#include "Planilla.h"

#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

int main(){

    Planilla *planilla = new Planilla();

    ifstream ifs("../textFiles/personas.txt", ifstream::in); // Por default abriendo como texto

    if (!ifs.is_open())
    {
        cerr << "Error leyendo archivo ejemplo.txt" << endl;
        return -1;
    }

    
    ifs >> planilla;

    cout << planilla;

    ifs.close();

    delete planilla;

    return 0;
}