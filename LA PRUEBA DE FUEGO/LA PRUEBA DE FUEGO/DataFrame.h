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
	Column columna;
	Row row;
	//vector<fila* > arr
	int n = 10;
	string* nombre = new string[n];
	string* apellido = new string[n];
	string* equipo = new string[n];
	char*   sexo = new char[n];
	int*    edad = new int[n];
	int*    numero = new int[n];

public:
	DataFrame() {
	    columna = Column();
		//fila = fila(1);
		row = Row();
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
	void importData() {
			
		int num = 9;
		ifstream archivo("Files//data.txt");
		archivo >> num;

		for (short i = 0; i < num; i++) {
			archivo >> nombre[i] >> apellido[i] >> equipo[i] >> sexo[i] >> edad[i] >> numero[i];
		}

		Limpiar();
		archivo.close();

		for (int i = 0; i < 10; i++) {
			cout << nombre[i] << " " << apellido[i] << " " << equipo[i] << " ";
			cout << sexo[i] << " " << edad[i] << " " << numero[i] << endl;
		}

	}
	void indexData() {

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
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			//heapSort()
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
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
			return 1; //retorna 0 si es string
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
	void siftDown(float* a, int start, int end) {
		for (int root = start; root * 2 + 1 <= end; ) {
			int child = root * 2 + 1;
			int swap = root;
			if (a[swap] < a[child]) swap = child;
			if (child + 1 <= end && a[swap] < a[child + 1]) swap = child + 1;
			if (swap == root) {
				return;
			}
			else {
				float t = a[root];
				a[root] = a[swap];
				a[swap] = t;
				root = swap;
			}
		}
	}
	void heapify(float* a, int end) {
		for (int i = (end - 1) / 2; i >= 0; i--) {
			siftDown(a, i, end);
		}

	}
	void heapSort(float* a, int n) {
		heapify(a, n);
		for (int i = 0; i < 10; i++) {
			cout << a[i] << " " << endl;
		}
		for (int end = n - 1; end > 0; end--) {
			float t = a[end];
			a[end] = a[0];
			a[0] = t;
			siftDown(a, 0, end - 1);
		}
	}
};
