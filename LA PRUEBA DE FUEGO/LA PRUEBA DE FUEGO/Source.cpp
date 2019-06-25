#include <iostream>
#include <clocale>
#include "Controladora.h"

using namespace std;
using namespace System;

int main() {	

	system("mode 145"); //CONSOLE SIZE
	setlocale(LC_ALL, "spanish"); //TILDES Y Ñ
	system("Color 0A"); //COLOR DE LA CONSOLA

	Controladora control = Controladora();
	
	control.menu();
	return 0;
}