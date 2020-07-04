#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "menu.h"
#include "Controller.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    FILE* pFile = fopen(path, "r");

    if(pFile != NULL) {
        if(parser_EmployeeFromText(pFile, pArrayListEmployee) == 0) {
            retorno = 0;
        }
    }

    fclose(pFile);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    FILE* pFile = fopen(path, "rb");

    if(pFile != NULL) {
        if(parser_EmployeeFromBinary(pFile,pArrayListEmployee) == 0) {
        	retorno = 0;
        }
    }

    fclose(pFile);

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 1;
    Employee* emp;
    char nombre[20], sueldo[20], horasTrabajadas[20], id[20];
    char confirmacionAlta;

    if(pArrayListEmployee != NULL) {
        printf("Ingrese el nombre del empleado: ");
        fflush(stdin);

        gets(nombre);

        printf("ingrese sueldo del empleado: ");
        fflush(stdin);

        gets(sueldo);

        printf("ingrese horas trabajadas: ");
        fflush(stdin);

        gets(horasTrabajadas);

        fflush(stdin);
        sprintf(id, "%d", getNewId(pArrayListEmployee));

        printf("seguro que desea cargar empleado? s/n\n");
        scanf("%c", &confirmacionAlta);

        if(confirmacionAlta == 's') {
            emp = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
            ll_add(pArrayListEmployee, emp);

            retorno = 0;
        }

    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 1;
    int empId;
    int empIndice;
    char confirmarModificacion;
    Employee* emp = NULL;

	char nuevoNombre[128];
	int nuevoSueldo;
	int nuevasHoras;

    if(controller_ListEmployee(pArrayListEmployee) == 0) {
        printf("Ingrese el ID del empleado a modificar: ");
        scanf("%d", &empId);

        if(pArrayListEmployee != NULL) {
            empIndice = controller_findEmployeeById(pArrayListEmployee, empId);

            if(empIndice != -1) {
            	emp = ll_get(pArrayListEmployee, empIndice);
            } else {
            	printf("Opcion invalida!\n\n");
            }

            if(emp != NULL) {
                printf("ID             NOMBRE      HORAS         SUELDO\n");
                printf("--------------------------------------------------\n");
            	printf("%04d     %10s     %4d      %d\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
                printf("\nDesea modificar este empleado? s/n\n");

                fflush(stdin);
                scanf("%c", &confirmarModificacion);

                if(confirmarModificacion == 's') {
                    switch(menuModificar()) {

                    case 1:
                        printf("Ingrese el nuevo nombre: ");
                        fflush(stdin);
                        gets(nuevoNombre);
                        employee_setNombre(emp, nuevoNombre);
                        retorno = 0;
                        break;

                    case 2:
                        printf("Ingrese el nuevo sueldo: ");
                        scanf("%d", &nuevoSueldo);
                        employee_setSueldo(emp, nuevoSueldo);
                        retorno = 0;
                        break;

                    case 3:
                        printf("Ingrese las nuevas horas trabajadas: ");
                        scanf("%d", &nuevasHoras);
                        employee_setHorasTrabajadas(emp, nuevasHoras);
                        retorno = 0;
                        break;

                    default:
                        printf("Opcion invalida!\n\n");
                        break;
                    }

                    system( "read -n 1 -s -p \"Presione enter para continuar...\"" );
                }
            }
        }
    }

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 1;
    int idEmpleado;
    int indiceEmpleado;
    char confirmarEliminacion;

    if(controller_ListEmployee(pArrayListEmployee) == 0) {
        printf("Ingrese el ID del empleado a eliminar: ");
        scanf("%d", &idEmpleado);

        if(pArrayListEmployee != NULL) {
            indiceEmpleado = controller_findEmployeeById(pArrayListEmployee, idEmpleado);
            Employee* emp = (Employee*) ll_get(pArrayListEmployee, indiceEmpleado);

            if(emp != NULL) {
                printf("ID           Nombre      Horas Trabajadas       Sueldo\n\n");
            	printf("%04d     %10s     %4d      %d\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
                printf("\nDesea eliminar a este empleado? s/n\n");

                fflush(stdin);
                scanf("%c", &confirmarEliminacion);

                if(confirmarEliminacion == 's') {
                    ll_remove(pArrayListEmployee, indiceEmpleado);
                    retorno = 0;
                }
            }

        }

    } else {
    	printf("No hay empleados en la lista!\n\n");
    }

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;

    Employee* emp;

    if(pArrayListEmployee != NULL) {
        printf("ID             Nombre      Horas Trabajadas         Sueldo\n");
        printf("--------------------------------------------------\n");

    	int tamlong = ll_len(pArrayListEmployee);

        for(int i = 0; i < tamlong; i++) {
            emp = (Employee*) ll_get(pArrayListEmployee, i);

            if(emp != NULL) {
            	printf("%04d     %10s     %4d      %d\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
                retorno = 0;
            }

            printf("--------------------------------------------------\n");
        }
    }

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;

    if(pArrayListEmployee != NULL && controller_ListEmployee(pArrayListEmployee) == 0) {
        switch(menuSort()) {

        case 1:
        	printf("\n\nOrdenando empleados por ID, espere un momento por favor...\n\n");
            ll_sort(pArrayListEmployee, sortEmployeeById, 0);
            retorno = 0;
            break;

        case 2:
        	printf("\n\nOrdenando empleados por sueldo, espere un momento por favor...\n\n");
        	ll_sort(pArrayListEmployee, sortEmployeeBySalary, 1);
            retorno = 0;
            break;

        default:
            printf("Opcion invalida!\n\n");
            break;
        }

        system( "read -n 1 -s -p \"Presione enter para continuar...\"" );
    }


    return retorno;
}

int sortEmployeeById(void* emp1, void* emp2)
{
	Employee* primerEmp = (Employee*) emp1;
	Employee* segundoEmp = (Employee*) emp2;

	int retorno = 0;

	if(primerEmp->id > segundoEmp->id) {
		retorno = 1;
	}

	if(primerEmp->id < segundoEmp->id) {
		retorno = -1;
	}

	return retorno;
}

int sortEmployeeBySalary(void* emp1, void* emp2)
{
	Employee* primerEmp = (Employee*) emp1;
	Employee* segundoEmp = (Employee*) emp2;

	int retorno = 0;

	if(primerEmp->sueldo > segundoEmp->sueldo) {
		retorno = 1;
	}

	if(primerEmp->sueldo < segundoEmp->sueldo) {
		retorno = -1;
	}

	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_findEmployeeById(LinkedList* pArrayListEmployee, int id) {
	int indice = -1;

	if(pArrayListEmployee != NULL) {
		int longitud = ll_len(pArrayListEmployee);
		Employee* emp;

		for(int i = 0; i < longitud; i++) {
			emp = (Employee*) ll_get(pArrayListEmployee, i);

			if(emp != NULL && emp->id == id) {
				indice = i;
				break;
			}
		}

	}

	return indice;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 1;
    int tamLista = ll_len(pArrayListEmployee);

    FILE* pFile = fopen(path, "w");
    Employee* emp;

    if(pFile != NULL && pArrayListEmployee != NULL) {

        fprintf(pFile, "ID,Nombre,HorasTrabajadas,Sueldo\n");

        for(int i = 0; i < tamLista; i++) {
           emp = (Employee*)ll_get(pArrayListEmployee,i);
           fprintf(pFile, "%d,%s,%d,%d\n",emp->id,emp->nombre,emp->horasTrabajadas,emp->sueldo);
        }

        retorno = 0;
    }

    fclose(pFile);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 1;
    int tamLista = ll_len(pArrayListEmployee);

    FILE* pFile = fopen(path, "wb");
    Employee* emp;

    if(pFile != NULL && pArrayListEmployee != NULL) {

        for(int i = 0; i < tamLista; i++) {
           emp = (Employee*) ll_get(pArrayListEmployee, i);
           fwrite(emp, sizeof(Employee), 1, pFile);
        }

        retorno = 0;
    }

    fclose(pFile);
    return retorno;
}

int getNewId(LinkedList* pArrayListEmployee) {
	int tam = ll_len(pArrayListEmployee);
	int nextId = 0;
	Employee* auxEmp;

	for(int i = 0; i < tam; i++) {
		auxEmp = (Employee*) ll_get(pArrayListEmployee, i);

		if(auxEmp->id > nextId) {
			nextId = auxEmp->id;
		}
	}

	return nextId + 1;
}
