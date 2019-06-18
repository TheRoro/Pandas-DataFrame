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
		string nombre;
	}
	string getDataAt_j(int j) {
		
		return rows.at(j).getInfo();
	}
	void add(Row r) {
		rows.push_back(r);
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
};
