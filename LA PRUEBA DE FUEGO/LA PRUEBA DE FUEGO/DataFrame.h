#pragma once
#include "Column.h"
#include "Row.h"
#include<vector>

class DataFrame {
	Column columna;
	Row row;
	/*
	vector<fila* > arr
	*/
public:
	DataFrame() {
	    columna = Column();
		//fila = fila(1);
		row = Row();
	}
	/*void asignar() {
		for(int i = 0 ; i < (numero de filas) ; i++){
		   arr[i]->asignar(i);
		}
	}*/
};