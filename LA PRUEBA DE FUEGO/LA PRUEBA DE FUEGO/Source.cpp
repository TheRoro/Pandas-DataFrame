#include <iostream>
#include <conio.h>

#include "DataFrame.h"
#include "Controladora.h"
#include "Column.h"
#include "Row.h"

using namespace std;
using namespace System;

int main() {	

	DataFrame    dataFrame = DataFrame();
	Controladora control   = Controladora();
	Column       column    = Column();
	Row          row       = Row();

	system("Color 0F");
	

	cout << "------------------------------PANDAS---------------------------" << endl;
	cout << "By: Los Papi Pros && Vila" << endl;
	cout << "A. Importación de Datos " << endl;
	cout << "B. Indexado de datos por columnas" << endl;
	cout << "C. Seleccion de datos por columnas" << endl;
	cout << "D. Flitrado de datos por columas" << endl;
	cout << "E. Ordenamiento de datos por columnas" << endl;
	cout << "F. Exportación de datos a archivos planos con diferente formato" << endl;




	_getch();
	return 0;
}