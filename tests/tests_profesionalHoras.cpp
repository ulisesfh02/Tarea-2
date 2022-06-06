#include <gtest/gtest.h>
#include "../src/ProfesionalHoras.h"
#include "../src/TipoEmpleado.h"

using namespace std;

namespace{
    TEST(Test_ProfesionalHoras, Test_ObtenerId){
        /// AAA

        // Arrange - configurar el escenario
        ProfesionalHoras *empleado = new ProfesionalHoras(1, "Ulises", "Fonseca", "ulises@gmail.com", 1, 2);
        // Act - ejecute la operación
        
        int actual = empleado->obtenerIdEmpleado();
        int esperada = 1;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);

        delete empleado;
    }
    TEST(Test_ProfesionalHoras, Test_asignarYVerIdSupervisor){
        /// AAA

        // Arrange - configurar el escenario
        ProfesionalHoras *empleado = new ProfesionalHoras(1, "Ulises", "Fonseca", "ulises@gmail.com", 1, 1);
        ProfesionalHoras *supervisor = new ProfesionalHoras(2, "Alejandro", "Fonseca", "alejandro@gmail.com", 2, 1);
        empleado->asignarSupervisor(supervisor);
        // Act - ejecute la operación
        
        int actual = empleado->obtenerIdSupervisor();
        int esperada = 2;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);
        
        delete empleado;
        delete supervisor;
    }
}
