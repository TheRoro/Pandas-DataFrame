#pragma once
#include "DataFrame.h"
#include "AVLTree.h"


using namespace std;

class Controladora {
	char option;
	vector <DataFrame*>* DFs;
	int creados;
	int df;
	int ncol;
	int x;			
	vector<int> poscol;

	bool continuar = true;
public:
	Controladora() { 
		DFs = new vector<DataFrame*>;
		
		creados = 0;
	}

	void menu() {
		string zh;
		do {
			cout << "------------------------------PANDAS--------------------------" << endl;
			cout << "By: Los Papi Pros && Vila" << endl;
			cout << "A. Importación de Datos " << endl;
			cout << "B. Indexado de datos por columnas" << endl;
			cout << "C. Selección de datos por columnas" << endl;
			cout << "D. Flitrado de datos por columas" << endl;
			cout << "E. Ordenamiento de datos por columnas" << endl;
			cout << "F. Exportación de datos a archivos planos con diferente formato" << endl;
			cout << "G. Eliminar DataFrame" << endl;
			cout << "H. Crear Dataframe desde 0" << endl;
			cout << "I. Mostrar DataFrame" << endl;
			cout << "X. Salir del Programa" << endl;
			cin >> option;

			switch (option) {
			case 'a':
			case 'A':
				//import
				char sep;
				cout << "Separador: " << endl;
				cout << "C. Coma (CSV) " << endl;
				cout << "T. Tab  (TSV) " << endl;
				cin >> sep;
				
				DFs->push_back(new DataFrame());
				DFs->at(creados)->importData(sep);
				creados++;
				break;
			case 'b':
			case 'B':
				cout << "Ingrese el DataFrame que desea indexar: " << endl;
				cin >> df;
				cout << endl;
				cout << "Cuantas columnas desea indexar :" << endl;
				cin >> ncol;
				for (int i = 0; i < ncol; i++) {
					cout << "Ingrese la " << i + 1 << " columna deseada (empieza en 0)";
					cin >> x;
					poscol.push_back(x);
				}

				break;
			case 'c':
			case 'C':
				//select
				
				cout << "Que data frame desea editar: " << endl;
				cin >> df;
				cout << endl;
				cout << "Mostrando DataFrame seleccionado---------" << endl;
				DFs->at(df)->Mostrar();
				cout << endl;
				
				cout << "Cuantas columnas desea seleccionar: " << endl;
				cin >> ncol;

				for (int i = 0; i < ncol; i++) {
					cout << "Ingrese la " << i + 1 << " columna deseada (empieza en 0)";
					cin >> x;
					poscol.push_back(x);
				}
				DFs->push_back(DFs->at(df)->selectData(poscol));
				cout << "Dataframe creado satisfactoriamente" << endl;
				creados++;
				poscol.clear();

				break;
			case 'd':
			case 'D':
				//filtrado
				int dump;
				int col1, col2;
				cout << "Ingrese el data frame que desea editar: " << endl;
				cin >> df;
				cout << "Ingrese el número de columnas que desee filtrar" << endl;
				cin >> dump;
				if (dump == 1) {
					cout << "Ingrese el indice de la columna que desea filtrar: " << endl;
					cin >> col1;
					DFs->at(df)->UnFiltro(col1);
				}
				else if (dump == 2) {
					cout << "Ingrese el indice de la primera columna que desea filtrar: " << endl;
					cin >> col1;
					cout << "Ingrese el indice de la segunda columna que desea filtrar: " << endl;
					cin >> col2;
					DFs->at(df)->DobleFiltro(col1, col2);
				}
				creados++;

				break;
			case 'e':
			case 'E':
				//ordena
				int col;

				cout << "Que número de DataFrame desea editar:" << endl;
				cin >> df;
				cout << endl;
				cout << "Seleccione el numero (0-n) de la columna que desea ordenar: " << endl;
				cin >> col;
				cout << endl;
				DFs->push_back(DFs->at(df)->sortData(col));
				creados++;
				break;
			case 'f':
			case 'F':
				//export
				int formato;
				cout << "Que DataFrame desea Exportar" << endl;
				cin >> df;
				cout << "Ingrese el formato de exportar: " << endl;
				cout << "1. CSV" << endl;
				cout << "2. TSV" << endl;
				cin >> formato;
				DFs->at(df)->exportData(formato);
				break;
			case 'g':
			case 'G':
				cout << "Que DataFrame desea eliminar: " << endl;
				cin >> df;
				
				cout << DFs->size() << endl;
			case 'h':
			case 'H':
				//desde 0
				int numCol, numFil;
				cout << "Ingrese el numero de columnas: " << endl;
				cin >> numCol;
				cout << "Ingrese el numero de filas: " << endl;
				cin >> numFil;
				DFs->push_back(new DataFrame());
				DFs->at(creados)->crear(numFil, numCol);
				creados++;
				break;
			case 'i':
			case 'I':
				cout << "Que data frame desea visualizar";
				cin >> df;
				cout << endl;
				DFs->at(df)->Mostrar();
				cout << endl;
				break;
			case 'x': 
			case 'X':
				continuar = false;
				break;
			default: cout << "Ingrese tecla nuevamente" << endl;
			}
		} while (continuar);
	}
};