#pragma once
#include <vector>
#include <stdlib.h>

using namespace std;

class Column {

	vector <Row> rows;

public:
	Column() {
		string nombre;
		
		rows.push_back();
	}
	string getDataAt_j(int j) {
		
		return rows.at(j);
	}
	void add(string s) {
		rows.push_back(s);
	}

};
