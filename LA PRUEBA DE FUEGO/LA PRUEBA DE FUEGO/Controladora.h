#pragma once
#include "DataFrame.h"

using namespace std;

class Controladora {
	char option;
public:
	Controladora() {
		DataFrame dataFrame = DataFrame();
	}
	void menu() {

		cout << "------------------------------PANDAS--------------------------" << endl;
		cout << "By: Los Papi Pros && Vila" << endl;
		cout << "A. Importación de Datos " << endl;
		cout << "B. Indexado de datos por columnas" << endl;
		cout << "C. Seleccion de datos por columnas" << endl;
		cout << "D. Flitrado de datos por columas" << endl;
		cout << "E. Ordenamiento de datos por columnas" << endl;
		cout << "F. Exportación de datos a archivos planos con diferente formato" << endl;
		cin >> option;

		switch (option) {
		case 'A':
		
			break;
		case 'B':
			
			break;
		case 'C':
			
			break;
		case 'D':
			
			break;
		case 'E':
			
			break;
		case 'F':
			
			break;
		}

	}

};