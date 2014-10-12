// Calcular Edad.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	struct tm *tiempo;
	int dia;
	int mes;
	int anio;

	
	time_t fecha_sistema;
	time(&fecha_sistema);
	tiempo = localtime(&fecha_sistema);

	anio = tiempo->tm_year + 1900;
	mes = tiempo->tm_mon + 1;
	dia = tiempo->tm_mday;

	bool fecha_invalida = false;

	do{
		int day, month, year;
		cout << "Dada la fecha de nacimiento, diga la edad de la persona" << endl;
		cout << "Fecha actual: " << asctime(tiempo);
		cout << "Introduzca el Dia de Nacimiento: ";
		cin >> day;
		cout << "Introduzca el Mes de Nacimiento: ";
		cin >> month;
		cout << "Introduzca el Año de Nacimiento: ";
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
			}
		}
	} while (fecha_invalida);
	system("PAUSE");
	return 0;
}

