#pragma once
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string>
#include <vector>
#include <windows.h>
#include <ctime>
#include <conio.h>

using namespace std;
	int accountNum, increaments;
	long double balance = 0;
	long double available;
	long double borrow = 0;
	struct accounts {

	string name;
	string password;
	double balance;
	double borrowed;
};
//declarare functie//////////////////////////////////////////
void CheckBalance();
void Borrow();
void Deposit();
void Return();
void Menu(accounts oldData[]);
void MainMenu();
void outData(accounts oldData[]);
void inputNewData(accounts data);
void inputUpgradeData(accounts data[]);
///////////////////////////////////////////////////////////////
//definire functie///////////////////////////////////////////
void Menu(accounts oldData[]) {
	char num = '1';
	while (num != '0')
	{
	system("CLS");
	cout << "\n          1.Depoziteaza" << endl;
	cout << "\n          2.Imprumuta bani de la banca" << endl;
	cout << "\n          3.Returneaza bani catre banca" << endl << endl;
	cout << "\n          Daca doresti sa iesi din aceasta sectiune te rugam apasa 0" << endl << endl;
	num = _getch();
switch (num) {
	case 49:
		system("CLS");
		Deposit();
		oldData[accountNum].balance = ::balance;
		inputUpgradeData(oldData);
		break;
	case 50:
		system("CLS");
		Borrow();
		oldData[accountNum].balance = ::balance;
		oldData[accountNum].borrowed = ::borrow;
		inputUpgradeData(oldData);
		break;
	case 51:
		system("CLS");
		Return();
		oldData[accountNum].balance = ::balance;
		oldData[accountNum].borrowed = ::borrow;
		inputUpgradeData(oldData);
		break;
	}
}
	cout << "\n          ";
}

void CheckBalance() {
	system("CLS");
	cout << "\n          Contul dumneavoastra: " << ::balance << "$" << endl << endl;
	cout << "\n          ";
	system("pause");
}

void Deposit()
{
	double money;
		cout << "\n          Te rog introdu o suma - ";
		cin >> money;
	if (money == 0)
	{
		cout << "\n          Ati introdus valoarea 0, sunteti redirectionat catre meniu" << endl;
	Sleep(2000);
	}
	else if (money > 0)
{
		::balance = ::balance + money;
	
		cout << "\n          Va rugam asteptati pana se vor transfera banii in contul dumneavoastra" << endl;
	Sleep(2000);
		cout << "\n          ";
		cout << money << "$ a fost adaugat contului dumneavoastra" << endl << endl;
}
	else
	{
		cout << "\n          Eroare!" << endl;
		cout << "\n          Va rog introduceti un numerar valid de bani!" << endl << endl;
	}
		cout << "\n          ";
	system("pause");
}

void Borrow()
{
	long double borrow;
		cout << "\n          In during time in our bank we have " << ::available << "$" << endl;
		cout << "\n          Cat doriti sa imprumutati?" << endl;
		cout << "\n          ";
		cin >> borrow;
	if (borrow == 0)
	{
		cout << "\n          Ati introdus valoarea 0, sunteti redirectionat catre meniu" << endl << endl;
	Sleep(2000);
	}
	else if (borrow <= ::available && borrow > 0)
	{
		cout << "\n          Va putem transfera aceasta suma." << endl;
		cout << "\n          Va rugam asteptati pana se vor transfera banii in contul dumneavoastra" << endl;
	Sleep(3000);
		::available = ::available - borrow;
		::balance = ::balance + borrow;
		::borrow = ::borrow + borrow;
		cout << "\n          Banii s-au transferat cu succes in contul dumneavoastra." << endl << endl;
	}
	else if (::borrow < 0)
	{
		cout << "\n          Eroare!" << endl;
		cout << "\n          Va rog introduceti un numerar valid de bani!" << endl << endl;
	}
	else {
		cout << "\n          Ne pare rau dar nu va putem transfera cantitatea curenta de bani" << endl << endl;
	}
		cout << "\n          ";
	system("pause");
}

void Return()
{
	char choise;
	long double retr;
	if (::borrow > 0) {
		cout << "\n          Ai imprumutat - " << ::borrow << "$" << endl;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
		cout << "\n          Daca doresti returnarea unei sume de bani te rog apasa SPACE sau apasa pe orice buton pentru a ajunge inapoi catre meniu." << endl;
		choise = _getch();
	if (choise == 32) {
		cout << "\n          Cat doresti sa returnezi?" << endl;
		cout << "\n          ";
		cin >> retr;
		if (retr == 0)
		{
			cout << "\n          Ati introdus valoarea 0, sunteti redirectionat catre meniu" << endl;
			Sleep(2000);
		}
		else if (retr > 0 && retr <= ::borrow) {
			cout << "\n          Please wait while we are taking from your account money back." << endl;
			::borrow = ::borrow - retr;
			::balance = ::balance - retr;
			::available = ::available + retr;
			Sleep(3000);
			cout << "\n          Banii s-au transferat cu succes in contul dumneavoastra." << endl << endl;
		}
		else
		{
			cout << "\n          Eroare!" << endl;
			cout << "\n          Va rog introduceti un numerar valid de bani!" << endl << endl;
		}
	}
}
		else {
			cout << "\n          Nu ati imprumutat niciun ban." << endl << endl;
			}
			cout << "\n          ";
			system("pause");
}

void outData(accounts oldData[]) {
	ifstream file;
		file.open("data.txt");
	if (!file.is_open()) {
		cout << "Error\n";

	}
	else {
	//cout << "file is opened\n";
	string str = "";
	int i = 0, j = 0;
	string strArr[4];
		do {
		getline(file, str, '|');
		if (j < 4) {
			strArr[j] = str;
			j++;
		}
		else {
			oldData[i].name = strArr[0];
			oldData[i].password = strArr[1];
			oldData[i].balance = stoi(strArr[2]);
			oldData[i].borrowed = stoi(strArr[3]);
			::increaments++;
			j = 0;
			strArr[j] = str;
			j++;
			i++;
		}


			//cout<<str<<"|";
	}while (!file.eof());
	}
}
void inputNewData(accounts data) {
	ofstream file;
		file.open("data.txt", ofstream::app);
		file << data.name;
		file << "|";
		file << data.password;
		file << "|";
		file << data.balance;
		file << "|";
		file << data.borrowed;
		file << "|";




	file.close();
}
void inputUpgradeData(accounts data[]) {
	ofstream file;
		file.open("data.txt");
	for (int i = 0; i <::increaments; i++) {
		
		file << data[i].name;
		file << "|";
		file << data[i].password;
		file << "|";
		file << data[i].balance;
		file << "|";
		file << data[i].borrowed;
		file << "|";
		
}

	file.close();
}
