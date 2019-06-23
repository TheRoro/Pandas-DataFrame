#pragma once
#include <vector>
#include <stdlib.h>
#include "Row.h"

using namespace std;

class Column {

	vector <Row> rows;
	string tipo;

public:
	Column() {
		tipo = " ";
		string nombre;
	}
	string getDataAt_j(int j) {
		
		return rows.at(j).getInfo();
	}
	void setDataAt_j(int j, string data) {

		rows.at(j).setInfo(data);
	}
	void add(Row r) {
		rows.push_back(r);
	}
	string GetTipo() { return tipo; }
	int GetSizeIterador(int i) {
		return rows.at(i).GetSize();
	}
	void ErasePosition(int pos) {
		rows.erase(rows.begin() + pos);
	}
private:
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
	void CambiarPosición(int i, int j ) {
		string temporal = rows.at(i).getInfo();
		rows[i].setInfo(rows[j].getInfo());
		rows[j].setInfo(temporal);
	}
public:
	void StaType(Row r) { // establecer tipo
		if (FindType(r.getInfo()) == 0) {
			tipo = "string";
		}
		else if (FindType(r.getInfo()) == -1) {
			tipo = "Double";
		}
		else if (FindType(r.getInfo()) == 1) {
			tipo = "Int";
		}
	}

};
