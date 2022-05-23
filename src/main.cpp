#include "TipoEmpleado.h"
#include "EmpleadoNomina.h"
#include "ProfesionalHoras.h"
#include "Planilla.h"

#include <vector>
#include <iostream>

using namespace std;

int main(){


    // Ejemplo 4: Ejemplo de inyección de dependencias para stream de entrada
    /*

    ifstream ifs("ejemplo.txt", std::ifstream::in); // Por default abriendo como texto

    if (!ifs.is_open())
    {
        std::cerr << "Error leyendo archivo ejemplo.txt" << std::endl;
        return -1;
    }

    CuentaPalabras *cuentaPalabras = new CuentaPalabras(&ifs);
    std::cout << "Número de palabras: " << cuentaPalabras->ContarPalabras();
    delete cuentaPalabras;

    ifs.close();
    */

    // Ejemplo 5: Ejemplo escritura
    ofstream ofs("ejemploEscritura.txt", std::ifstream::out); // Por default abriendo como texto

    if (!ofs.is_open())
    {
        std::cerr << "Error leyendo archivo ejemploEscritura.txt" << std::endl;
        return -1;
    }

    ofs << "Número de palabras: " << 4 << endl;
    ofs << "Segunda línea: " << 4 << endl;

    ofs.close();

    return 0;
}