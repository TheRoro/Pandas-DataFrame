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
	void encontrarTipo(){
		vector<string> a;
	        vector<int> b;
	        vector<double> c;
	        string j;
	        cin >> j;
	       if((j[0] >= 65 && j[0] <= 90) || (j[0] >= 97 && j[0] <= 122)){
		   cout << "Si" << " " << j[0] << endl;
		   a.push_back(j);
	        }else {
		   double aux = stod(j);
		   int aux2 = int(aux);
		   if( aux != (double)aux2 ){
			c.push_back(aux);
		    }else{
			b.push_back(aux2);
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
