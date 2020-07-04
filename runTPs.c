#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "likedList/testing/inc/main_test.h"
#include "likedList/inc/LinkedList.h"


void runTP3() {
    char respuesta = 's';
    char confirmarRespuesta = 'n';

    char* ARCHIVO = "data.csv";
    char* ARCHIVO_BINARIO = "data_binario.csv";
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        switch(menuPrincipal()) {
            case 1:
            	if(controller_loadFromText(ARCHIVO, listaEmpleados) == 0) {
            		printf("Empleados cargados por texto con exito!\n\n");
            	} else {
            		printf("Hubo un error al intentar cargar los empleados por texto\n\n");
            	}

                break;

            case 2:
                if(controller_loadFromBinary(ARCHIVO_BINARIO, listaEmpleados) == 0) {
            		printf("Empleados cargados por binario con exito!\n\n");
                } else {
            		printf("Hubo un error al intentar cargar los empleados por binario\n\n");
                }

                break;

            case 3:
                if(controller_addEmployee(listaEmpleados) == 0) {
                	printf("Empleado agregado con exito!\n\n");
                } else {
                	printf("Hubo un error al intentar agregar el empleado\n\n");
                }

                break;

            case 4:
            	if(controller_editEmployee(listaEmpleados) == 0) {
                	printf("Empleado editado con exito!\n\n");
            	} else {
                	printf("Hubo un error al intentar editar el empleado\n\n");
            	}

                break;

            case 5:
            	if(controller_removeEmployee(listaEmpleados) == 0) {
                	printf("Empleado borrado con exito!\n\n");
            	} else {
                	printf("Hubo un error al intentar borrar el empleado\n\n");
            	}

                break;

            case 6:
            	if(controller_ListEmployee(listaEmpleados) != 0) {
            		printf("No hay empleados para mostrar\n\n");
            	}

                break;

            case 7:
            	if(controller_sortEmployee(listaEmpleados) == 0) {
            		printf("Empleados ordenados con exito!\n\n");
            	} else {
            		printf("No se pudieron ordenar los empleados\n\n");
            	}

                break;

            case 8:
            	if(controller_saveAsText(ARCHIVO, listaEmpleados) == 0) {
            		printf("Empleados almacenados por texto con exito!\n\n");
            	} else {
            		printf("Hubo un error al intentar guardar los empleados por texto\n\n");
            	}

                break;

            case 9:
            	if(controller_saveAsBinary(ARCHIVO_BINARIO, listaEmpleados) == 0) {
            		printf("Empleados almacenados por binario con exito!\n\n");
            	} else {
            		printf("Hubo un error al intentar guardar los empleados por binario\n\n");
            	}

            	break;

            case 10:
				printf("Desea salir? s/n\n");
				fflush(stdin);
				scanf("%c", &confirmarRespuesta);
				if(confirmarRespuesta == 's')
					respuesta = 'n';
				printf("\nSaliste del programa");
				break;

            default:
            	printf("Opcion invalida, intenta nuevamente\n\n");
        }

        system( "read -n 1 -s -p \"Presione enter para continuar...\"" );


    }while(respuesta == 's');
}

void runTP4() {
	startTesting(1);  // ll_newLinkedList
	startTesting(2);  // ll_len
	startTesting(3);  // getNode - test_getNode
	startTesting(4);  // addNode - test_addNode
	startTesting(5);  // ll_add
	startTesting(6);  // ll_get
	startTesting(7);  // ll_set
	startTesting(8);  // ll_remove
	startTesting(9);  // ll_clear
	startTesting(10); // ll_deleteLinkedList
	startTesting(11); // ll_indexOf
	startTesting(12); // ll_isEmpty
	startTesting(13); // ll_push
	startTesting(14); // ll_pop
	startTesting(15); // ll_contains
	startTesting(16); // ll_containsAll
	startTesting(17); // ll_subList
	startTesting(18); // ll_clone
	startTesting(19); // ll_sort */
}
