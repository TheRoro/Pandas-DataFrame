#pragma once
#include "DataFrame.h"

using namespace std;

class Controladora {
	char option;
	DataFrame dataFrame = DataFrame();
	bool continuar = true;
public:
	Controladora() { }

	void menu() {

		do {
			cout << "------------------------------PANDAS--------------------------" << endl;
			cout << "By: Los Papi Pros && Vila" << endl;
			cout << "A. Importación de Datos " << endl;
			cout << "B. Indexado de datos por columnas" << endl;
			cout << "C. Selección de datos por columnas" << endl;
			cout << "D. Flitrado de datos por columas" << endl;
			cout << "E. Ordenamiento de datos por columnas" << endl;
			cout << "F. Exportación de datos a archivos planos con diferente formato" << endl;
			cout << "G. Salir del Programa" << endl;
			cout << "H. Crear Dataframe desde 0" << endl;
			cin >> option;

			switch (option) {
			case 'A':
				char sep;
				cout << "Separador: " << endl;
				cout << "C. Coma (CSV) " << endl;
				cout << "T. Tab  (TSV) " << endl;
				cin >> sep;
				dataFrame.importData(sep);
				break;
			case 'B':
				dataFrame.indexData();
				break;
			case 'C':
				dataFrame.selectData();
				break;
			case 'D':
				dataFrame.filterData();
				break;
			case 'E':
				dataFrame.sortData();
				break;
			case 'F':
				dataFrame.exportData();
				break;
			case 'G':
				continuar = false;
				break;
			case 'H':
				dataFrame.crear();
				break;
			}
		} while (continuar);
	}
};