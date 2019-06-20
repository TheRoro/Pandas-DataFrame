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

	int n = 10;
	string* nombre = new string[n];
	string* apellido = new string[n];
	string* equipo = new string[n];
	char*   sexo = new char[n];
	int*    edad = new int[n];
	int*    numero = new int[n];

public:
	DataFrame() {
		columns = new vector<Column*>;
		rows = new vector<Row*>;
		nc = 0;
		nf = 0;
	}

	/*
	void importData() {	
		int Ncolumnas = 0;
		int Nfilas = 0; // iterador de filas
		int iteradorC = 0;
		ifstream f("Numerost.txt");
		bool contar = true;
		string line, num;
		if (!f.is_open())
		{
			cout << "El archivo no se logro abrir " << endl;
		}
		else {
			while (f >> line)
			{
				stringstream ss(line);
				while (getline(ss, num, ','))
				{
					cout << num << " " << endl;
					if (contar) {
						Ncolumnas++; //esto solo ocurre en la primera pasada(fila 1°)... Se genera la columna, usando la función FindType() para saber que 
					}
					iteradorC++;
					cout << "--------------------" << endl;
					cout << iteradorC << endl;
					cout << "--------------------" << endl;
					//pongo la función que me permite identificar el tipo de una variable y creo la columna
				}
				iteradorC = 0;
				contar = false;
				Nfilas++;// genero una nueva fila
				cout << endl;
			}
		}
		cout << "-------------------------" << endl;
		cout << "N de f: " << Nfilas << endl;//prueba
		cout << "N de columnas: " << Ncolumnas << endl;//prueba
		f.close();
		_getch();

	}
	*/

	void importData(char sep) {
		int numCol = 1;
		ifstream archivo;
		ifstream temporal;
		archivo.open("peladas.txt");
		temporal.open("peladas.txt");
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
			int numFil = 1;
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
			cout << "Numero de columnas: " << numCol << endl;
			cout << "Numero de filas: "  << numFil << endl;
			for (int j = 0; j < numFil; j++) {
				for (int i = 0; i < numCol; i++) {
					cout << columns->at(i)->getDataAt_j(j) << "		";
				}
				cout << endl;
			}
			nf = numFil;
			nc = numCol;
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
			int numFil = 1;
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
			cout << "Numero de columnas: " << numCol << endl;
			cout << "Numero de filas: " << numFil << endl;
			for (int j = 0; j < numFil; j++) {
				for (int i = 0; i < numCol; i++) {
					cout << columns->at(i)->getDataAt_j(j) << "		";
				}
				cout << endl;
			}
			nf = numFil;
			nc = numCol;
		}
	}
	void indexData() {

	}
	void Mostrar() {
		for (int j = 0; j < nf; j++) {
			for (int i = 0; i < nc; i++) {
				cout << columns->at(j)->getDataAt_j(i) << " ";
			}
			cout << endl;
		}
	}
	void selectData() {

	}
	void filterData() {

	}
	void sortData() {
		int opcion = 0;
		cout << "Seleccione que columna desea ordenar: " << endl;
		cout << "1. Nombre" << endl;
		cout << "2. Apellido" << endl;
		cout << "3. Equipo" << endl;
		cout << "4. Sexo" << endl;
		cout << "5. Edad" << endl;
		cout << "6. Numero" << endl;
		cout << "7. Ordenar todos los arreglos a partir del nombre" << endl;
		cout << "8. Ordenar todos los arreglos a partir del apellido" << endl;
		cout << "9. Ordenar todos los arreglos a partir del equipo" << endl;
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			heapSort(nombre, 5);
			break;
		case 2:
			heapSort(apellido, 5);
			break;
		case 3:
			heapSort(equipo, 5);
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			cin >> nombre[0];
			cin >> nombre[1];
			cin >> nombre[2];
			cin >> nombre[3];

			heapSortTodos(nombre, 5);

			cout << "Arreglo ordenado:" << endl;
			for (int i = 0; i < 5; i++) {
				cout << nombre[i] << " ";
			}

			break;
		case 8:
			heapSortTodos(apellido, 5);
			break;
		case 9:
			heapSortTodos(equipo, 5);
			break;
		}
	}
	void exportData() {

		ofstream archivo;
		archivo.open("Files//data.txt");
		int numFilas = 10;
		archivo << numFilas << " ";

		for (int i = 0; i < 10; i++) {
			archivo << nombre[i] << " " << apellido[i] << " " << equipo[i] << " ";
			archivo << sexo[i] << " " << edad[i] << " " << numero[i] << endl;
		}
		archivo.close();

	}
	void crear() {
		int numCol, numFil;
		cout << "Ingrese el numero de columnas: " << endl;
		cin >> numCol;
		cout << "Ingrese el numero de filas: " << endl;
		cin >> numFil;
		//columns->at(i)->getDataAt_j(0);
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
	void show() {

	}
private:
	void Limpiar() {
		string x;
		x = "                                                      ";
		ofstream archivo("Files//data.txt");
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
		ifstream archivo("Files//data.txt");
		archivo >> x;
		archivo.close();
		if (x == " ") return true;

	}
	void siftDown(string *a, int start, int end) {
		for (int root = start; root * 2 + 1 <= end; ) {
			int child = root * 2 + 1;
			int swap = root;
			if (a[swap] < a[child]) swap = child;
			if (child + 1 <= end && a[swap] < a[child + 1]) swap = child + 1;
			if (swap == root) {
				return;
			}
			else {
				string t = a[root];
				a[root] = a[swap];
				a[swap] = t;
				root = swap;
			}
		}
	}
	void heapify(string *a, int end) {
		for (int i = (end - 2) / 2; i >= 0; i--) {
			siftDown(a, i, end);
		}

	}
	void heapSort(string *a, int n) {
		heapify(a, n);
		for (int i = 0; i < 5; i++) {
			cout << a[i] << " " << endl;
		}
		for (int end = n - 1; end > 0; end--) {
			string t = a[end];
			a[end] = a[0];
			a[0] = t;
			siftDown(a, 0, end - 1);
		}
	}
	void siftDownS(string* a, int start, int end) {
		for (int root = start; root * 2 + 1 <= end; ) {
			int child = root * 2 + 1;
			int swap = root;
			if (a[swap] < a[child]) swap = child;
			if (child + 1 <= end && a[swap] < a[child + 1]) swap = child + 1;
			if (swap == root) {
				return;
			}
			else {
				if (a[0] == nombre[0]) {
					string t = a[root];
					string A = apellido[root];
					string E = equipo[root];
					a[root] = a[swap];
					apellido[root] = apellido[swap];
					equipo[root] = equipo[swap];
					a[swap] = t;
					apellido[swap] = A;
					equipo[swap] = E;
					root = swap;
				}
				else if (a[0] == apellido[0]) {
					string t = nombre[root];
					string A = a[root];
					string E = equipo[root];
					nombre[root] = nombre[swap];
					a[root] = a[swap];
					equipo[root] = equipo[swap];
					nombre[swap] = t;
					a[swap] = A;
					equipo[swap] = E;
					root = swap;
				}
				else if (a[0] == equipo[0]) {
					string t = nombre[root];
					string A = apellido[root];
					string E = a[root];
					nombre[root] = nombre[swap];
					a[root] = a[swap];
					equipo[root] = equipo[swap];
					nombre[swap] = t;
					apellido[swap] = A;
					a[swap] = E;
					root = swap;
				}
			}
		}
	}
	void heapifyS(string*a, int end) {
		for (int i = (end - 2) / 2; i >= 0; i--) {
			siftDownS(a, i, end);
		}
	}
	void heapSortTodos(string*a , int n) {
		heapifyS(a,n);
		for (int i = 0; i < 5; i++) {
			cout << nombre[i] << " " << apellido[i] << " " <<equipo[i] << " "<< endl;
		}
		for (int end = n - 1; end > 0; end--) {
			if (a[0] == nombre[0]) {
				string t = a[end];
				string A = apellido[end];
				string E = equipo[end];
				a[end] = a[0];
				apellido[end] = apellido[0];
				equipo[end] = equipo[0];
				a[0] = t;
				apellido[0] = A;
				equipo[0] = E;
			}
			else if (a[0] == apellido[0]) {
				string t = nombre[end];
				string A = a[end];
				string E = equipo[end];
				nombre[end] = nombre[0];
				a[end] = a[0];
				equipo[end] = equipo[0];
				nombre[0] = t;
				a[0] = A;
				equipo[0] = E;
			}
			else if (a[0] == equipo[0]) {
				string t = nombre[end];
				string A = apellido[end];
				string E = a[end];
				nombre[end] = nombre[0];
				apellido[end] = apellido[0];
				a[end] = a[0];
				nombre[0] = t;
				apellido[0] = A;
				a[0] = E;
			}
			siftDownS(a, 0, end - 1);
		}
	}

};
