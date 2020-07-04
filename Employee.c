#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "string.h"

Employee* employee_new() {
	Employee* emp = (Employee*) malloc(sizeof(Employee));

	if(emp != NULL) {
		emp->id = 0;
		strcpy(emp->nombre, "");
		emp->horasTrabajadas = 0;
		emp->sueldo = 0;
	}

	return emp;
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr) {
	Employee* emp = employee_new();

	if(emp != NULL) {
		int id = atoi(idStr);
		int horasTrabajadas = atoi(horasTrabajadasStr);
		int sueldo = atoi(sueldoStr);

		if(employee_setId(emp, id) ||
		employee_setNombre(emp, nombreStr) ||
		employee_setHorasTrabajadas(emp, horasTrabajadas) ||
		employee_setSueldo(emp, sueldo))
		{
			free(emp);
			emp = NULL;
		}
	}

	return emp;
}

void employee_delete(Employee* this) {
	this = NULL;
	free(this);
}

int employee_setId(Employee* this, int id) {
	int retorno = 1;

	if(this != NULL) {
		this->id = id;
		retorno = 0;
	}

	return retorno;
}

int employee_getId(Employee* this, int* id) {
	int retorno = 1;

	if(this != NULL && id != NULL) {
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

int employee_setNombre(Employee* this, char* nombre) {
	int retorno = 1;

	if(this != NULL) {
		strcpy(this->nombre, nombre);
		retorno = 0;
	}

	return retorno;
}

int employee_getNombre(Employee* this, char* nombre) {
	int retorno = 1;

	if(this != NULL && nombre != NULL) {
		strcpy(nombre, this->nombre);
		retorno = 0;
	}

	return retorno;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas) {
	int retorno = 1;

	if(this != NULL) {
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas) {
	int retorno = 1;

	if(this != NULL && horasTrabajadas != NULL) {
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}

int employee_setSueldo(Employee* this, int sueldo) {
	int retorno = 1;

	if(this != NULL) {
		this->sueldo = sueldo;
		retorno = 0;
	}

	return retorno;
}

int employee_getSueldo(Employee* this, int* sueldo) {
	int retorno = 1;

	if(this != NULL && sueldo != NULL) {
		*sueldo = this->sueldo;
		retorno = 0;
	}

	return retorno;
}


