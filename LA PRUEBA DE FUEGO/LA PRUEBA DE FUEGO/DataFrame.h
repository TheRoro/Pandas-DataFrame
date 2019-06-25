#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <string>
#include "Column.h"
#include "Row.h"
#include "Controladora.h"

using namespace std;

//DATOS CON FORMATO:
//NOMBRE - APELLIDO - EQUIPO - SEXO - EDAD - NUMERO
//STRING - STRING   - STRING - CHAR - INT  - INT


class DataFrame {

	vector <Column*>* columns;

	int nc;
	int nf;
	int numCol = 1;
	int numFil = 1;

public:
	DataFrame() {
		columns = new vector<Column*>;
		
		nc = 0;
		nf = 0;
	}
	void importData(char sep) {

		ifstream archivo;
		ifstream temporal;
		archivo.open("sampleData.txt"); //Recordar cambiarlo
		temporal.open("sampleData.txt"); //recordar cambiarlo
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
					if (numFil == 1) {
						columns->at(i)->StaType(*row);
					}
				}
				else {
					getline(archivo, linea, ',');
					Row* row;
					row = new Row();
					row->setInfo(linea);
					columns->at(i)->add(*row);
					if (numFil == 1) {
						columns->at(i)->StaType(*row);
					}
				}
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
					if (numFil == 1) {
						columns->at(i)->StaType(*row);
					}
				}
				else {
					getline(archivo, linea, '	');
					Row* row;
					row = new Row();
					row->setInfo(linea);
					columns->at(i)->add(*row);
					if (numFil == 1) {
						columns->at(i)->StaType(*row);
					}
				}
				i++;
			}

		}
		Mostrar();
	}
	void indexData() {

	}
	void Mostrar() {
		
		cout << endl << endl << "SHOWING DATAFRAME:" << endl;
		cout << "////////////////////////////////////////" << endl;
		for (int j = 0; j < numFil; j++) {
			for (int i = 0; i < numCol; i++) {
				cout << columns->at(i)->getDataAt_j(j) << "	";
			}
			cout << endl;
		}
	}
	DataFrame* selectData(vector<int> poscol) {

		DataFrame* dfNuevo = new DataFrame();
		dfNuevo->numCol = poscol.size();
		dfNuevo->numFil = numFil;
		for (int i = 0; i < poscol.size(); i++) {
			dfNuevo->columns->push_back(columns->at(poscol.at(i)));
		}
		return dfNuevo;
	}

	/*void NuevoFMayor(int columnas, int dato) {
		DataFrame df_filtrado = DataFrame();
		df_filtrado.numCol = this->numCol;
		for (int j = 0; j < numFil; j++) {
			if (stoi(columns->at(columnas)->getDataAt_j(j)) > dato) {
				for (int i = 0; i < df_filtrado.numCol; i++) {

				}
			}
		}
	} */
	void filterDataMayor(int c , int m) {
        DataFrame df_Filtered = DataFrame();
		df_Filtered.columns = this->columns;
		df_Filtered.numCol = this->numCol;
		df_Filtered.numFil = this->numFil;
		for (int j = 0; j < df_Filtered.numFil; j++) {
			if (stoi(df_Filtered.columns->at(c)->getDataAt_j(j)) <= m) {
				for (int i = 0; i < df_Filtered.numCol; i++) {
					df_Filtered.columns->at(i)->setDataAt_j(j, " ");
				}
			}
		}
		cout << endl;
		for (int j = 0; j < numFil; j++) {
			for (int i = 0; i < numCol; i++) {
				if (df_Filtered.columns->at(i)->getDataAt_j(j) != " ") {
					cout << df_Filtered.columns->at(i)->getDataAt_j(j) << "		";
				}
			}
			cout << endl;
		}
	}
	void filterDataMenor(int c, int m) {
		DataFrame df_Filtered = DataFrame();
		df_Filtered.columns = this->columns;
		df_Filtered.numCol = this->numCol;
		df_Filtered.numFil = this->numFil;
		for (int j = 0; j < df_Filtered.numFil; j++) {
			if (stoi(df_Filtered.columns->at(c)->getDataAt_j(j)) >= m) {
				for (int i = 0; i < df_Filtered.numCol; i++) {
					df_Filtered.columns->at(i)->setDataAt_j(j, " ");
				}
			}
		}
		cout << endl;
		for (int j = 0; j < numFil; j++) {
			for (int i = 0; i < numCol; i++) {
				if (df_Filtered.columns->at(i)->getDataAt_j(j) != " ") {
					cout << df_Filtered.columns->at(i)->getDataAt_j(j) << "		";
				}
			}
			cout << endl;
		}
	}
	void filterDataigual(int c, int m) {
		DataFrame df_Filtered = DataFrame();
		df_Filtered.columns = this->columns;
		df_Filtered.numCol = this->numCol;
		df_Filtered.numFil = this->numFil;
		for (int j = 0; j < df_Filtered.numFil; j++) {
			if (stoi(df_Filtered.columns->at(c)->getDataAt_j(j)) != m) {
				for (int i = 0; i < df_Filtered.numCol; i++) {
					df_Filtered.columns->at(i)->setDataAt_j(j, " ");
				}
			}
		}
		cout << endl;
		for (int j = 0; j < numFil; j++) {
			for (int i = 0; i < numCol; i++) {
				if (df_Filtered.columns->at(i)->getDataAt_j(j) != " ") {
					cout << df_Filtered.columns->at(i)->getDataAt_j(j) << "		";
				}
			}
			cout << endl;
		}
	}
	void filterDatainicia(int colu, string c) {
		DataFrame df_Filtered = DataFrame();
		df_Filtered.columns = this->columns;
		df_Filtered.numCol = this->numCol;
		df_Filtered.numFil = this->numFil;
		for (int j = 0; j < df_Filtered.numFil; j++) {
			if (df_Filtered.columns->at(colu)->getDataAt_j(j)[0] != c[0]) {
				for (int i = 0; i < df_Filtered.numCol; i++) {
					df_Filtered.columns->at(i)->setDataAt_j(j, " ");
				}
			}
		}
		cout << endl;
		for (int j = 0; j < numFil; j++) {
			for (int i = 0; i < numCol; i++) {
				if (df_Filtered.columns->at(i)->getDataAt_j(j) != " ") {
					cout << df_Filtered.columns->at(i)->getDataAt_j(j) << "		";
				}
			}
			cout << endl;
		}
	}
	void filterDataTermina(int colu, string c) {
		DataFrame df_Filtered = DataFrame();
		df_Filtered.columns = this->columns;
		df_Filtered.numCol = this->numCol;
		df_Filtered.numFil = this->numFil;
		for (int j = 0; j < df_Filtered.numFil; j++) {
			if (df_Filtered.columns->at(colu)->getDataAt_j(j)[df_Filtered.columns->at(colu)->GetSizeIterador(j) - 1] != c[0]) {
				for (int i = 0; i < df_Filtered.numCol; i++) {
					df_Filtered.columns->at(i)->setDataAt_j(j, " ");
				}
			}
		}
		cout << endl;
		for (int j = 0; j < numFil; j++) {
			for (int i = 0; i < numCol; i++) {
				if (df_Filtered.columns->at(i)->getDataAt_j(j) != " ") {
					cout << df_Filtered.columns->at(i)->getDataAt_j(j) << "		";
				}
			}
			cout << endl;
		}
	}
	void filterDataContenido(int c, int m) {
		DataFrame df_Filtered = DataFrame();
		df_Filtered.columns = this->columns;
		df_Filtered.numCol = this->numCol;
		df_Filtered.numFil = this->numFil;
		for (int j = 0; j < df_Filtered.numFil; j++) {
			if (stoi(df_Filtered.columns->at(c)->getDataAt_j(j)) <= m) {
				for (int i = 0; i < df_Filtered.numCol; i++) {
					df_Filtered.columns->at(i)->setDataAt_j(j, " ");
				}
			}
		}
		cout << endl;
		for (int j = 0; j < numFil; j++) {
			for (int i = 0; i < numCol; i++) {
				if (df_Filtered.columns->at(i)->getDataAt_j(j) != " ") {
					cout << df_Filtered.columns->at(i)->getDataAt_j(j) << "		";
				}
			}
			cout << endl;
		}
	}
	void sortData(int col) {
		if (columns->at(col)->GetTipo() == "string")
		{
			quicksort(columns, 0, numFil - 1, col); //el cero esta de más?
		}
		else if (columns->at(col)->GetTipo() == "Int") {
			quicksortInt(columns, 0, numFil - 1, col);
		}
		

		//quicksort(columns, 0, numFil - 1, col);
		Mostrar();
	}
	void exportData(int formato) {
		ofstream exported;
		if (formato == 1) { //FORMATO CSV
			exported.open("exported.csv");
			for (int j = 0; j < numFil; j++) {
				for (int i = 0; i < numCol; i++) {
					exported << columns->at(i)->getDataAt_j(j) << ",";
				}
				exported << endl;
			}
		}
		else { //FORMATO TSV
			exported.open("exported.tsv");
			for (int j = 0; j < numFil; j++) {
				for (int i = 0; i < numCol; i++) {
					exported << columns->at(i)->getDataAt_j(j) << "	";
				}
				exported << endl;
			}
		}
		exported.close();
	}
	void crear(int numFil, int numCol) {
		this->numFil = numFil;
		this->numCol = numCol;
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
				columns->at(i)->StaType(*row);
			}
		}
		Mostrar();

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
	void swapyInt(vector<Column*>*& v, int x, int y) {
		for (int k = 0; k < v->size(); k++) {
			string temporal = columns->at(k)->getDataAt_j(x);
			columns->at(k)->setDataAt_j(x, columns->at(k)->getDataAt_j(y));
			columns->at(k)->setDataAt_j(y, temporal);
		}
	}
	void quicksortInt(vector<Column*>* &cols, int L, int R, int col) {
		int piv;
		int i, j, mid;
		i = L;
		j = R;
		mid = L + (R - L) / 2;
		piv = stoi(cols->at(col)->getDataAt_j(mid));

		while (i<R || j>L) {
			while (stoi(cols->at(col)->getDataAt_j(i)) < piv)
				i++;
			while (stoi(cols->at(col)->getDataAt_j(j)) > piv)
				j--;

			if (i <= j) {
				swapyInt(cols, i, j);
				//swapy(cols, i, j);
				i++;
				j--;
			}
			else {
				if (i < R)
					quicksortInt(cols, i, R, col);
				if (j > L)
					quicksortInt(cols, L, j, col);
				return;
			}
		}
	}
};
