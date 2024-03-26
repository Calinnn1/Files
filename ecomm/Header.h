#pragma once
#include <iostream>
#include <string>  // Text
#include <ctime>   // Timp
#include <ctype.h> // Validare
#include <conio.h> // Getch
#include <windows.h> // Loading
using namespace std;

// Identificatori Globali pt validare
	int Num_Upper = 0, Num_Lower = 0, Num_Number = 0, Validation = 0;
	string Login_Sign, Parol_Sign;
// Identificatori pentru Tinerea Fisei
	string Name_Memory, Login_Memory, Parol_Memory, TellNum_Memory;

class Security {
private:
	// Identificatoare
	string Name, Login, Parol, TellNum;
public:

	// Constructor implicit
	Security() {
		Name = "";
		Login = "";
		Parol = "";
		TellNum = "";
	}

	// Afisajul functiei
	void Display() {
		cout << "\t\t\tUser Information:" << endl << endl;
		cout << "\t\tUser Name  : " << Name << endl;
		cout << "\t\tTelephone  : " << TellNum << endl;
		cout << "\t\tLogin      : " << Login << endl;
		cout << "\t\tPassword   : " << Parol << endl;
	}

	// Set Info pentru Utilizator
	void SetUser() {
		cout << "\t\t\t\t       Register User:" << endl << endl;
		cout << "\t\t\t\t        User Name : "; cin >> Name;
		cout << "\t\t\t\t        Telephone : "; cin >> TellNum;
		cout << "\t\t\t\t        Login     : "; cin >> Login;
		cout << "\t\t\t\t        Password  : "; cin >> Parol;

		// Info trimis catre memorie
		Name_Memory = Name;
		Parol_Memory = Parol;
		Login_Memory = Login;
		TellNum_Memory = TellNum;
	}

	// Functii Friend
	//Validare verifica pentru patrula
	friend void ValidationParol(Security User) {
		if (User.Parol.length() >= 6 && User.Parol.length() <= 15) {
			for (int i = 0; i < User.Parol.length(); i++) {
				if (isupper(User.Parol[i])) {  // Numar pt Majuscule
					Num_Upper += 1;
				}
				if (islower(User.Parol[i])) {  // Numar pt litere joase
					Num_Lower += 1;
				}
				if (isdigit(User.Parol[i])) {  // Numar digits
					Num_Number += 1;
				}
			}
			if (Num_Upper >= 1 && Num_Upper <= 10 && Num_Lower >= 4 && Num_Lower <= 10 && Num_Number >= 2 && Num_Number <= 10) {
				Validation++;
				Num_Upper = 0; Num_Lower = 0; Num_Number = 0;
			}
			else { Num_Upper = 0; Num_Lower = 0; Num_Number = 0; }
		}
		else { Num_Upper = 0; Num_Lower = 0; Num_Number = 0; }
	}
	//Validare verificare pt nume
	friend void ValidationName(Security User) {
		if (User.Name.length() >= 1 && User.Name.length() <= 15) {
			for (int i = 0; i < User.Name.length(); i++) {
				if (isupper(User.Name[i])) {
					Num_Upper += 1;
				}
				if (islower(User.Name[i])) {
					Num_Lower += 1;
				}
				if (isdigit(User.Name[i])) {
					Num_Number += 1;
				}
			}

			if (Num_Upper <= 1 && Num_Lower >= 1 && Num_Lower <= 14 && Num_Number == 0) {
				Validation++;
				Num_Upper = 0; Num_Lower = 0; Num_Number = 0;
			}
			else { Num_Upper = 0; Num_Lower = 0; Num_Number = 0; }
		}
		else { Num_Upper = 0; Num_Lower = 0; Num_Number = 0; }
	}
	//Validare verificare pt TellNum
	friend void ValidationTellNum(Security User) {
		if (User.TellNum.length() >= 9 && User.TellNum.length() <= 12) {
			for (int i = 0; i < User.TellNum.length(); i++) {
				if (isupper(User.TellNum[i])) {
					Num_Upper += 1;
				}
				if (islower(User.TellNum[i])) {
					Num_Lower += 1;
				}
				if (isdigit(User.TellNum[i])) {
					Num_Number += 1;
				}
			}
			if (Num_Upper == 0 && Num_Lower == 0 && Num_Number >= 9 && Num_Number <= 12) {
				Validation++;
				Num_Upper = 0; Num_Lower = 0; Num_Number = 0;
			}
			else { Num_Upper = 0; Num_Lower = 0; Num_Number = 0; }
		}
		else { Num_Upper = 0; Num_Lower = 0; Num_Number = 0; }
	}

};