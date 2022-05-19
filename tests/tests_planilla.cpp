#include <gtest/gtest.h>
#include "../src/Planilla.h"
#include "../src/EmpleadoNomina.h"

namespace{
    TEST(test_planilla, agregar){
        /// AAA

        // Arrange - configurar el escenario
        Planilla *planilla = new Planilla();
        TipoEmpleado *empleado = new TipoEmpleado();
        // Act - ejecute la operación
        planilla->agregarEmpleado(empleado);

        int actual = arbol->ObtenerValor(2);
        int esperada = 7;

        delete arbol;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);
    }
}