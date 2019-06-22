#include <iostream>
#include <conio.h>
#include <locale.h>
#include "Controladora.h"


using namespace std;
using namespace System;

int main() {	
	//system("mode con: cols=110 lines=30");
	setlocale(LC_ALL, "spanish");
	system("Color 07");

	Controladora control = Controladora();
	
	control.menu();

	_getch();
	return 0;

}