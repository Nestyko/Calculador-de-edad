// Calcular Edad.cpp : Defines the entry point for the console application.
// Editado desde la tablet. con AIDE y GIThub

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <time.h>

//Debi de agregar estas lineas debido a que en visual studio no permiten utilizar localtime.
#ifdef _MSC_VER // check MSC version
#define _CRT_SECURE_NO_WARNINGS // Disable all warnings
#endif


using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	time_t fecha_sistema;
	struct tm *tiempo;
	
	time(&fecha_sistema);
	tiempo = localtime(&fecha_sistema);

	int dia;
	int mes;
	int anio;
	anio = tiempo->tm_year + 1900;
	mes = tiempo->tm_mon + 1;
	dia = tiempo->tm_mday;

	bool fecha_invalida = false;

	do{
		int day, month, year;
		cout << "Dada la fecha de nacimiento, diga la edad de la persona" << endl;
		//cout << "Fecha actual: " << asctime(tiempo);
		cout << "Introduzca el Dia de Nacimiento: ";
		cin >> day;
		cout << "Introduzca el Mes de Nacimiento: ";
		cin >> month;
		cout << "Introduzca el A�o de Nacimiento: ";
		cin >> year;
		if ((year > 2014) || (month>12) || (month<1) || (day<1) || (day>31)) {
			cout << endl << "Fecha invalida." << endl << endl;
			fecha_invalida = true;
		}
		else{
			fecha_invalida = false;
			if ((mes == month && dia>day) || (mes<month)){
				cout << "Edad: " << ((anio - year) - 1);
			}
			else{
				cout << "Edad: " << (anio - year);
				cout << endl << endl;
			}
		}
	} while (fecha_invalida);
	system("PAUSE");
	return 0;
}

