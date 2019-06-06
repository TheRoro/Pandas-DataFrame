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
	
	control.menu();


	_getch();
	return 0;
}