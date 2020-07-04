#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "string.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int r;
    char id[20], nombre[128], horasTrabajadas[20], sueldo[20]; //longitud que pueden llegar a tener los atributos
    Employee* emp;

    if(pFile != NULL && pArrayListEmployee != NULL) {

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo ); //para leer el header

    	while(!feof(pFile)) {

        	r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo );

            if(r == 4) {
            	emp = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
                ll_add(pArrayListEmployee, emp);
                retorno = 0;
            }
    	}

    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int r = 0;
    int headerFlag = 0; //Con esto no trata de traerse la data del encabezado a la lista

    if(pFile != NULL && pArrayListEmployee != NULL) {

    	do {
            Employee* emp = employee_new();

            if(emp != NULL && headerFlag) {
               r = fread(emp, sizeof(Employee), 1, pFile);
            } else {
            	headerFlag = 1;
            }

            if(r == 1) {
               ll_add(pArrayListEmployee, emp);
            }

            retorno = 0;

    	} while(!feof(pFile));

        fclose(pFile);
    }


    return retorno;
}
