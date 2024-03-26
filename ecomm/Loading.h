#pragma once
#include <iostream>
#include <ctime>   // Timp
#include <windows.h> // Incarcare

void gotoXY(int x, int y) {
	//'COORD' e o functie built-in pt pozitionarea obiectelor
	COORD d;
	d.X = x;
	d.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), d);
}

void F_Loading() {
	cout << "\n\n\n\n\n\n";
	cout << "\t\t\t       -------------------------------------  \n";
	cout << "\t\t\t         G A L E A  C A L I N  V I C T O R      \n";
	cout << "\t\t\t       -------------------------------------  \n";
	cout << "\t\t\t	      L U G H I A  M A R K E T           \n";
	cout << "\t\t\t       _____________________________________  \n";

	char a = 219;
	gotoXY(5, 14);

	cout << "INCARCARE... " << endl;

	gotoXY(37, 16);
	for (int r = 1; r <= 26; r++)
	{
		// pentru viteza
		for (int speed = 0; speed <= 110000000; speed++);
		cout << a;
	}
	cout << endl;
}