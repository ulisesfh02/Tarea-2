#include "TipoEmpleado.h"
#include "EmpleadoNomina.h"
#include "ProfesionalHoras.h"
#include "Planilla.h"

#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

int main(){

    ifstream ifs("ejemplo.txt", ifstream::in); // Por default abriendo como texto

    if (!ifs.is_open())
    {
        cerr << "Error leyendo archivo ejemplo.txt" << endl;
        return -1;
    }

    CuentaPalabras *cuentaPalabras = new CuentaPalabras(&ifs);
    cout << "Número de palabras: " << cuentaPalabras->ContarPalabras();
    delete cuentaPalabras;

    ifs.close();

    // Ejemplo 5: Ejemplo escritura
    ofstream ofs("ejemploEscritura.txt", ifstream::out); // Por default abriendo como texto

    if (!ofs.is_open())
    {
        cerr << "Error leyendo archivo ejemploEscritura.txt" << endl;
        return -1;
    }

    ofs << "Número de palabras: " << 4 << endl;
    ofs << "Segunda línea: " << 4 << endl;

    ofs.close();

    return 0;
}