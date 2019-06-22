#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <string>
#include "Column.h"
#include "Row.h"

using namespace std;

//DATOS CON FORMATO:
//NOMBRE - APELLIDO - EQUIPO - SEXO - EDAD - NUMERO
//STRING - STRING   - STRING - CHAR - INT  - INT


class DataFrame {

	vector <Column*>* columns;
	vector <Row*>*	  rows;
	int nc;
	int nf;
	int numCol = 1;
	int numFil = 1;

public:
	DataFrame() {
		columns = new vector<Column*>;
		rows = new vector<Row*>;
		nc = 0;
		nf = 0;
	}
	void importData(char sep) {

		ifstream archivo;
		ifstream temporal;
		archivo.open("txtGrande.txt");
		temporal.open("txtGrande.txt");
		string linea;
		getline(temporal, linea);
		if (sep == 'C') {
			//FOR PARA SABER LA CANTIDAD DE COLUMNAS
			for (int i = 0; i < linea.size(); i++) {
				if (linea[i] == ',') numCol++;
			}
			//FOR PARA TENER CREADAS TODAS LAS COLUMNAS
			for (int i = 0; i < numCol; i++) {
				Column* columna;
				columna = new Column();
				columns->push_back(columna);
			}
			int i = 0;
			numFil = 1;
			linea = " ";
			while (archivo.good()) {
				if (i == numCol) {
					i = 0;
					numFil++;
				}
				if (i == numCol - 1) {
					getline(archivo, linea, '\n');
					Row* row;
					row = new Row();
					row->setInfo(linea);
					columns->at(i)->add(*row);
				}
				else {
					getline(archivo, linea, ',');
					Row* row;
					row = new Row();
					row->setInfo(linea);
					columns->at(i)->add(*row);
				}

				/*if (numFil == 0) {
					columns->at(i)->StaType(*row);
				}*/
				i++;
			}
		}
		else if (sep == 'T') {
			//FOR PARA SABER LA CANTIDAD DE COLUMNAS
			for (int i = 0; i < linea.size(); i++) {
				if (linea[i] == '	') numCol++;
			}
			//FOR PARA TENER CREADAS TODAS LAS COLUMNAS
			for (int i = 0; i < numCol; i++) {
				Column* columna;
				columna = new Column();
				columns->push_back(columna);
			}
			int i = 0;
			numFil = 1;
			linea = " ";
			while (archivo.good()) {
				if (i == numCol) {
					i = 0;
					numFil++;
				}

				if (i == numCol - 1) {
					getline(archivo, linea, '\n');
					Row* row;
					row = new Row();
					row->setInfo(linea);
					columns->at(i)->add(*row);
				}
				else {
					getline(archivo, linea, '	');
					Row* row;
					row = new Row();
					row->setInfo(linea);
					columns->at(i)->add(*row);
				}

				/*if (numFil == 0) {
					columns->at(i)->StaType(*row);
				}*/
				i++;
			}

		}
		Mostrar(numFil, numCol);
	}
	void indexData() {

	}
	void Mostrar(int numFil, int numCol) {
		for (int j = 0; j < numFil; j++) {
			for (int i = 0; i < numCol; i++) {
				cout << columns->at(i)->getDataAt_j(j) << "	";
			}
			cout << endl;
		}
	}
	void selectData() {

	}
	void filterData() {
		DataFrame df_Filtered = DataFrame();
	}
	void sortData(int col) {
		
		quicksort(columns, 0, numFil - 1, col);

		//quicksort(columns, 0, numFil - 1, col);
		Mostrar(numFil, numCol);
	}
	void exportData() {

		ofstream archivo;
		archivo.open("txtGrande.txt");

		for (int j = 0; j < numFil; j++) {
			for (int i = 0; i < numCol; i++) {
				archivo << columns->at(i)->getDataAt_j(j) << "	";
			}
			archivo << endl;
		}
		archivo.close();
	}
	void crear(int numFil, int numCol) {

		string s = " ";
		for (int i = 0; i < numCol; i++) {

			Column* columna;
			columna = new Column();
			columns->push_back(columna);

			for (int j = 0; j < numFil; j++) {

				Row* row;
				row = new Row();
				cout << "Ingrese elemento en la columna: " << i + 1 << " y fila: " << j + 1 << endl;
				cin >> s;
				row->setInfo(s);
				columns->at(i)->add(*row);
			}
		}
		cout << endl << endl << "SHOWING DATAFRAME 1:" << endl;
		cout << "////////////////////////////////////////" << endl;
		for (int j = 0; j < numFil; j++) {
			for (int i = 0; i < numCol; i++) {
				cout << columns->at(i)->getDataAt_j(j) << " ";
			}
			cout << endl;
		}

	}
private:
	void Limpiar() {
		string x;
		x = "                                                      ";
		ofstream archivo("peladas.txt");
		if (!archivo.is_open()) {
			cout << "error";
		}
		archivo << x;
		archivo.flush();
		archivo.close();
	}
	int FindType(string j) {
		if ((j[0] >= 65 && j[0] <= 90) || (j[0] >= 97 && j[0] <= 122)) {
			return 0; //retorna 0 si es string
		}
		else {
			double aux = stod(j);
			int aux2 = int(aux);
			if (aux != (double)aux2) {
				return -1; //retorna -1 si es double
			}
			else {
				return 1;//retorna 1 si es int 
			}
		}
	}
	bool estaVacio() {
		string x;
		ifstream archivo("peladas.txt");
		archivo >> x;
		archivo.close();
		if (x == " ") return true;

	}

	void swapy(vector<Column*>*& v, int x, int y) {
		for (int k = 0; k < v->size(); k++) {
			string temporal = columns->at(k)->getDataAt_j(x);
			columns->at(k)->setDataAt_j(x, columns->at(k)->getDataAt_j(y));
			columns->at(k)->setDataAt_j(y, temporal);
		}
	}
	void quicksort(vector<Column*>* &cols, int L, int R, int col) {
		string piv;
		int i, j, mid;
		i = L;
		j = R;
		mid = L + (R - L) / 2;
		piv = cols->at(col)->getDataAt_j(mid);

		while (i<R || j>L) {
			while (cols->at(col)->getDataAt_j(i) < piv)
				i++;
			while (cols->at(col)->getDataAt_j(j) > piv)
				j--;

			if (i <= j) {
				swapy(cols, i, j);
				i++;
				j--;
			}
			else {
				if (i < R)
					quicksort(cols, i, R, col);
				if (j > L)
					quicksort(cols, L, j, col);
				return;
			}
		}
	}

};
