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

    string archivoPersonas = "personas.txt";
    string archivoNomina = "nomina.txt";
    string archivoHoras = "horastrabajadas.txt";
    

    ifstream firstStream(archivoPersonas, ifstream::in);
    ifstream secondStream(archivoNomina, ifstream::in); 
    ifstream thirdStream(archivoHoras, ifstream::in);

    if (!secondStream.is_open())
    {
        cerr << "Error leyendo archivo horastrabajadas.txt" << endl;
        return -1;
    }

    if (!firstStream.is_open())
    {
        cerr << "Error leyendo archivo personas.txt" << endl;
        return -1;
    }
    
    if (!thirdStream.is_open())
    {
        cerr << "Error leyendo archivo nomina.txt" << endl;
        return -1;
    }

    Planilla *planilla = new Planilla(&firstStream, &secondStream, &thirdStream);

    planilla->leerArchivos();


    ofstream ofs("Reporte.csv", std::ofstream::out); // Por default abriendo como texto

    if (!ofs.is_open())
    {
        std::cerr << "Error abriendo archivo Reporte.csv" << std::endl;
        return -1;
    }

    ofs << planilla;

    ofs.close();

    firstStream.close();
    secondStream.close();
    thirdStream.close();

    delete planilla;

    return 0;
}