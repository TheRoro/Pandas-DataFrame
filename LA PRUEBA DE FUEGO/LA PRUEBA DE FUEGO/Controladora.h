#pragma once
#include "DataFrame.h"

using namespace std;

class Controladora {
	char option;
	string parte; //FILTER
	vector <DataFrame*>* DFs;
	int creados;
	int df;
	int n;
	int ncol;
	int x;			
	int i;
	vector<int> poscol;

	/*DataFrame dataFrame = DataFrame();*/
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
			cout << "G. Salir del Programa" << endl;
			cout << "H. Crear Dataframe desde 0" << endl;
			cout << "I. Mostrar DataFrame" << endl;
			cin >> option;

			switch (option) {
			case 'A':
				char sep;
				cout << "Separador: " << endl;
				cout << "C. Coma (CSV) " << endl;
				cout << "T. Tab  (TSV) " << endl;
				cin >> sep;
				
				DFs->push_back(new DataFrame());
				DFs->at(creados)->importData(sep);
				creados++;
				break;
			case 'B':
				/*dataFrame.indexData();*/
				break;
			case 'C':
				//RETORNAR UN NUEVO DATA FRAME QUE TIENE UNA SELECCION DE COLUMNAS DEL DATA FRAME SELECCIONADO
				// EL USUARIO SELCCIONA LAS COLUMNAS QUE DESEA QUE PERMANEZCAN,Y SE CREA.
				
				cout << "Que data frame desea editar: " << endl;
				cin >> n;
				cout << endl;
				cout << "Mostrando DataFrame seleccionado---------" << endl;
				DFs->at(n)->Mostrar();
				cout << endl;
				
				cout << "Cuantas columnas desea seleccionar: " << endl;
				cin >> ncol;

				for (int i = 0; i < ncol; i++) {
					cin >> x;
					poscol.push_back(x);
				}
				DFs->push_back(DFs->at(n)->selectData(poscol));
				cout << "Mostrando nuevo DataFrame--------------" << endl;
				DFs->at(creados)->Mostrar();
				creados++;

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
				/*	dataFrame.filterDataMayor(colu, num);*/
					break;
				case 'b':
					cout << "Ingrese el numero: " << endl;
					cin >> num;
					/*dataFrame.filterDataMenor(colu, num);*/
					break;
				case 'c':
					cout << "Ingrese el numero: " << endl;
					cin >> num;
				/*	dataFrame.filterDataigual(colu, num);*/
					break;
				case 'd':
					cout << "Ingrese el numero o letra con el cual quieres que empieze: " << endl;
					cin >> zh;
					/*dataFrame.filterDatainicia(colu, zh);*/
					break;
				case 'e':
					cout << "Ingrese el numero o letra con el cual quieres que termine: " << endl;
					cin >> zh;
					/*dataFrame.filterDataTermina(colu, zh);*/
					break;
				case 'f':
					cout << "Ingrese la letra: " << endl;
					break;
				case 'g':
					break;
				}
				break;
			case 'E':
				int col;

				cout << "Que número de DataFrame desea editar:" << endl;
				cin >> df;
				cout << endl;
				cout << "Seleccione el numero (0-n) de la columna que desea ordenar: " << endl;
				cin >> col;
				cout << endl;
				DFs->at(df)->sortData(col);
				break;
			case 'F':
				int i;
				int formato;
				cout << "Que DataFrame desea Exportar" << endl;
				cin >> i;
				cout << "Ingrese el formato de exportar: " << endl;
				cout << "1. CSV" << endl;
				cout << "2. TSV" << endl;
				cin >> formato;
				DFs->at(i)->exportData(formato);
				break;
			case 'H':
				int numCol, numFil;
				cout << "Ingrese el numero de columnas: " << endl;
				cin >> numCol;
				cout << "Ingrese el numero de filas: " << endl;
				cin >> numFil;
				DFs->push_back(new DataFrame());
				DFs->at(creados)->crear(numFil, numCol);
				creados++;
				break;
			case 'I':
				cout << "Que data frame desea visualizar";
				cin >> i;
				cout << endl;
				DFs->at(i)->Mostrar();
				cout << endl;
				break;
			case 'G':
				continuar = false;
				break;
			default: continuar = false;
			}
		} while (continuar);
	}
};