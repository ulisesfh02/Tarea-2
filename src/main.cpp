#include "TipoEmpleado.h"
#include "EmpleadoNomina.h"
#include "Planilla2.h"

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

    Planilla2 *planilla2 = new Planilla2(&firstStream, &secondStream, &thirdStream);

    planilla2->leerArchivos();

    ofstream ofs("ejemploEscritura.txt", std::ifstream::out); // Por default abriendo como texto

    if (!ofs.is_open())
    {
        std::cerr << "Error leyendo archivo ejemploEscritura.txt" << std::endl;
        return -1;
    }

    ofs << planilla2;
    

    ofs.close();

    firstStream.close();
    secondStream.close();
    thirdStream.close();

    delete planilla2;

    return 0;
}