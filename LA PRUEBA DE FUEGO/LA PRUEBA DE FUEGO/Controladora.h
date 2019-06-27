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
	vector<DataFrame*>::iterator it;
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
			cout << "A. Importaci�n de Datos " << endl;
			cout << "B. Indexado de datos por columnas" << endl;
			cout << "C. Selecci�n de datos por columnas" << endl;
			cout << "D. Flitrado de datos por columas" << endl;
			cout << "E. Ordenamiento de datos por columnas" << endl;
			cout << "F. Exportaci�n de datos a archivos planos con diferente formato" << endl;
			cout << "G. Eliminar DataFrame" << endl;
			cout << "H. Crear Dataframe desde 0" << endl;
			cout << "I. Mostrar DataFrame" << endl;
			cout << "J. Personalizar" << endl;
			cout << "X. Salir del Programa" << endl;
			cin >> option;

			switch (option) {
			case 'a':
			case 'A':
				//import
				char sep;
				do{
				cout << "Separador: " << endl;
				cout << "C. Coma (CSV) " << endl;
				cout << "T. Tab  (TSV) " << endl;
				cin >> sep;
				} while (sep != 'C' && sep != 'c' && sep != 'T' && sep != 't');
				
				DFs->push_back(new DataFrame());
				DFs->at(creados)->importData(sep);
				creados++;
				break;
			case 'b':
			case 'B':
				do {
					cout << "Ingrese el DataFrame que desea indexar: " << endl;
					cin >> df;
				} while (df >= creados);
				cout << endl;
				do {
					cout << "Cuantas columnas desea indexar: " << endl;
					cin >> ncol;
				} while (ncol > DFs->at(df)->getLength());
				for (int i = 0; i < ncol; i++) {
					do {
						cout << "Ingrese la " << i + 1 << " columna deseada (empieza en 0)";
						cin >> x;
					} while (x >= DFs->at(df)->getLength());
					poscol.push_back(x);
				}
				DFs->at(df)->indexData(poscol);
				poscol.clear();
				break;
			case 'c':
			case 'C':
				//select
				do {
					cout << "Que data frame desea editar: " << endl;
					cin >> df;
				} while (df >= creados);
				cout << endl;
				cout << "Mostrando DataFrame seleccionado---------" << endl;
				DFs->at(df)->Mostrar();
				cout << endl;
				do {
					cout << "Cuantas columnas desea seleccionar: " << endl;
					cin >> ncol;
				} while (ncol > DFs->at(df)->getLength());
				
				for (int i = 0; i < ncol; i++) {
					do {
						cout << "Ingrese la " << i + 1 << " columna deseada (empieza en 0)";
						cin >> x;
					} while (x >= DFs->at(df)->getLength());
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
				do {
					cout << "Que data frame desea editar: " << endl;
					cin >> df;
				} while (df >= creados);

				do {
					cout << "Ingrese el n�mero de columnas que desee filtrar (1 o 2)" << endl;
					cin >> dump;
				} while (dump > 2 || dump <= 0);

				if (dump == 1) {
					do {
						cout << "Ingrese el indice de la columna que desea filtrar: " << endl;
						cin >> col1;
					} while (col1 >= DFs->at(df)->getLength());
					
					DFs->at(df)->UnFiltro(col1);
				}
				else if (dump == 2) {
					do {
						cout << "Ingrese el indice de la columna que desea filtrar: " << endl;
						cin >> col1;
					} while (col1 >= DFs->at(df)->getLength());

					do {
						cout << "Ingrese el indice de la segunda columna que desea filtrar: " << endl;
						cin >> col2;
					} while (col2 >= DFs->at(df)->getLength());

					DFs->at(df)->DobleFiltro(col1, col2);
				}
				creados++;

				break;
			case 'e':
			case 'E':
				//ordena
				int col;
				do {
					cout << "Que n�mero de DataFrame desea editar:" << endl;
					cin >> df;
				} while (df >= creados);
				cout << endl;
				do {
					cout << "Seleccione el numero (0-n) de la columna que desea ordenar: " << endl;
					cin >> col;
				} while (col >= DFs->at(df)->getLength());
				cout << endl;
				DFs->push_back(DFs->at(df)->sortData(col));
				creados++;
				break;
			case 'f':
			case 'F':
				//export
				int formato;
				do {
					cout << "Que DataFrame desea Exportar" << endl;
					cin >> df;
				} while (df >= creados);

				do {
					cout << "Ingrese el formato de exportar: " << endl;
					cout << "C. Coma (CSV) " << endl;
					cout << "T. Tab  (TSV) " << endl;
					cin >> formato;
				} while (formato != 'C' && formato != 'c' && formato != 'T' && formato != 't');

				DFs->at(df)->exportData(formato);
				break;
			case 'g':
			case 'G':
				do {
					cout << "Que DataFrame desea eliminar: " << endl;
					cin >> df;
				} while (df >= creados);

				it = DFs->begin();
				for (int i = 0; i < df; i++) {
					it++;
				}
				DFs->erase(it);
				creados--;
				cout << "DataFrame eliminado satisfactoriamente :)" << endl;
				break;
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
				do {
					cout << "Que data frame desea visualizar";
					cin >> df;
				} while (df >= creados);
				cout << endl;
				DFs->at(df)->Mostrar();
				cout << endl;
				break;
			case 'j':
			case 'J':
				int set;
				cout << "SETTINGS: " << endl;
				cout << "1. Cambiar color " << endl;
				cout << "2. Cambiar visualizaci�n de DataFrame " << endl;
				cin >> set;
				switch (set)
				{
				case 1:
					int color;
					cout << "Choose your color: " << endl;
					cout << "1. Green" << endl;
					cout << "2. Blue" << endl;
					cout << "3. Yellow" << endl;
					cout << "4. White" << endl;
					cout << "5. Purple" << endl;
					cin >> color;
					switch (color)
					{
					case 1:
						system("Color 0A");
						break;
					case 2:
						system("Color 0B");
						break;
					case 3:
						system("Color 0E");
						break;
					case 4:
						system("Color 0F");
						break;
					case 5:
						system("Color 0D");
						break;
					}
					break;
				case 2:
					for (int i = 0; i < DFs->size(); i++) {
						if (DFs->at(0)->getVisualization() == true) {
							DFs->at(0)->setVisualization(false);
						}
						else {
							DFs->at(0)->setVisualization(true);
						}
					}
					cout << "The visualization settings were updated " << endl;
				}
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