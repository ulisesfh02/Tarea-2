#include <gtest/gtest.h>
#include "../src/ProfesionalHoras.h"
#include "../src/Planilla.h"

namespace{
    TEST(Test_ProfesionalHoras, Test_Agregar_ProfesionalHoras){
        /// AAA

        // Arrange - configurar el escenario
        Planilla *planilla = new Planilla();
        ProfesionalHoras *empleado = new ProfesionalHoras();
        // Act - ejecute la operación
        planilla->agregarEmpleado(empleado);

        int actual = planilla->obtenerIdEmpleado(2);
        int esperada = 2;

        delete planilla;
        delete empleado;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);
    }
}
