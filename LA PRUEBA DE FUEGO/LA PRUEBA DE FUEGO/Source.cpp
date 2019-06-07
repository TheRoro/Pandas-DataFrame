#include <iostream>
#include <conio.h>
#include "Controladora.h"


using namespace std;
using namespace System;

int main() {	

	Controladora control = Controladora();

	system("Color 0F");
	
	control.menu();

	_getch();
	return 0;
}