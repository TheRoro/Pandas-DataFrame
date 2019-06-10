#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
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
	void importData() {
		int Ncolumnas = 0; //prueba
		int iteradorF = 0; // iterador de filas
		int iteradorC = 0; // iterador de columnas
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
					cout << num << " " << endl; // prueba
					//cout << num << " "; //esto es lo que normalmente iria para leer el archivo
					if (contar) {
						Ncolumnas++; //esto solo ocurre en la primera pasada(fila 1°)... Se genera la columna, usando la función FindType() para saber que 
					}
					iteradorC++;
					cout << "--------------------" << endl;//prueba
					cout << iteradorC << endl;//prueba
					cout << "--------------------" << endl;//prueba
					//pongo la función que me permite identificar el tipo de una variable y creo la columna
				}
				iteradorC = 0;
				contar = false;
				iteradorF++;// genero una nueva fila
				cout << endl;
			}
		}
		cout << "-------------------------" << endl; //prueba
		cout << "N de f: " << iteradorF << endl;//prueba
		cout << "N de columnas: " << Ncolumnas << endl;//prueba
		f.close();
	}
	void indexData() {

	}
	void selectData() {

	}
	void filterData() {

	}
	void sortData() {

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
};
