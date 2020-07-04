#include "menu.h"

int menuPrincipal() {
	int respuesta;

	printf("----------------Bienvenido----------------\n\n");

	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
	printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
	printf("3. Alta de empleado\n");
	printf("4. Modificar datos de empleado\n");
	printf("5. Baja de empleado\n");
	printf("6. Listar empleados\n");
	printf("7. Ordenar empleados\n");
	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
	printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
	printf("10. Salir\n\n");

	printf("Elige una opcion: ");

	scanf("%d", &respuesta);


	return respuesta;
}

int menuSort() {
	int respuesta;

    printf("1. Ordenar por ID\n");
    printf("2. Ordenar por Sueldo\n\n");

    printf("Elija la opcion para ordenar a los empleados en la lista: ");
    scanf("%d", &respuesta);

    return respuesta;
}

int menuModificar() {
	int respuesta;

	printf("1. Modificar nombre\n");
	printf("2. Modificar sueldo\n");
	printf("3. Modificar las horas trabajadas\n\n");

    printf("Elija la opcion: ");
    scanf("%d", &respuesta);

    return respuesta;
}
