#pragma once
#include "DataFrame.h"

using namespace std;

class Controladora {
	char option;
	string parte; //FILTER
	vector <DataFrame*>* dataframes;

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
				int colu;
				char parametro1, parametro2;
				int num;

				//PRIMERO SE INGRESA LA COLUMNA A FILTRAR
				cout << "Ingrese el indice de la columna que desea filtrar: " << endl;
				cin >> colu;
				cout << "Ingrese el parametro por el cual desea filtrar: " << endl;
				cout << "a. Mayor que x" << endl;
				cout << "b. Menor que x " << endl;
				cout << "c. Igual que x " << endl;
				cout << "d. Inicia con: " << endl;
				cout << "e. Finaliza con: " << endl;
				cout << "f. Está contenido en: " << endl;
				cout << "g. No está contenido en: " << endl;
				cin >> parametro1;
				switch (parametro1){
				case 'a':
					cout << "Ingrese el numero: " << endl;
					cin >> num;
					break;
				case 'b':
					cout << "Ingrese el numero: " << endl;
					cin >> num;
					break;
				case 'c':
					cout << "Ingrese el numero: " << endl;
					cin >> num;
					break;
				case 'd':

					break;
				case 'e':
					break;
				case 'f':
					break;
				case 'g':
					break;
				}
				dataFrame.filterData();
				break;
			case 'E':
				int col;
				cout << "Seleccione el numero (0-n) de la columna que desea ordenar: " << endl;
				cin >> col;
				cout << endl;
				dataFrame.sortData(col);
				break;
			case 'F':
				dataFrame.exportData();
				break;
			case 'G':
				continuar = false;
				break;
			case 'H':
				int numCol, numFil;
				cout << "Ingrese el numero de columnas: " << endl;
				cin >> numCol;
				cout << "Ingrese el numero de filas: " << endl;
				cin >> numFil;
				dataFrame.crear(numFil, numCol);
				break;
			}
		} while (continuar);
	}
};