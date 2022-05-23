#include <gtest/gtest.h>
#include "../src/EmpleadoNomina.h"
#include "../src/Planilla.h"

namespace{
    TEST(Test_EmpleadoNomina, Test_Agregar_EmpleadoNomina){
        /// AAA

        // Arrange - configurar el escenario
        Planilla *planilla = new Planilla();
        EmpleadoNomina *empleado = new EmpleadoNomina();
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