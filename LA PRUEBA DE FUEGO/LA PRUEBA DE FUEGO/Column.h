#pragma once
#include <vector>
#include <stdlib.h>
#include "Row.h"

using namespace std;

class Column {

	vector <Row> rows;

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

};
