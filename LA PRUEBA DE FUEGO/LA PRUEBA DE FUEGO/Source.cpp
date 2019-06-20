#include <iostream>
#include <conio.h>
#include <locale.h>
#include "Controladora.h"


using namespace std;
using namespace System;

int main() {	

	setlocale(LC_ALL, "spanish");

	Controladora control = Controladora();

	system("Color 07");
	
	control.menu();

	_getch();
	return 0;

}