#include "Header.h"

int main(){

	srand(time(0));
	::available = rand() % 200000;
	MainMenu();

	system("color 9E");
	system("pause");
	return 0;
}

void MainMenu()
{
	system("color 9E");
	char num;
	char choice;
	do
	{
	bool checked = false;
	string checkName, checkPassword;
	accounts data;
	accounts oldData[50];
		cout<<"\n		Selecteaza o optiune: ";
		cout<<"\n		1. Autentificare";
		cout<<"\n		2. Inregistrare";
		cout<<"\n		3. Iesire";
		choice = _getch();
		switch(choice)
		{
			case 49:
outData(oldData);
system("cls");
	cout<<"\n		Introdu numele: ";
	cout<<"\n		 ";
	cin>> checkName;
	cout<<"\n		Introdu parola: ";
	cout<<"\n		 ";
	cin>> checkPassword;
	for(int i =0; i< ::increaments; i++)
{
		if(oldData[i].name == checkName && oldData[i].password == checkPassword)
	{
			::accountNum = i;
			::balance = oldData[i].balance;
			::borrow = oldData[i].borrowed;
			checked = true;
	}
}
	if (checked)
	{
		do
		{
			system("cls");
		cout<<"\n		Bun venit "<< oldData[::accountNum].name << endl;
		cout<<"\n		Ce ai dori sa faci? "<< endl;
		cout<<"\n		1. Actiuni cu cardul ";
		cout<<"\n		2. Verifica contul ";
		cout<<"\n		0. Iesire "<<endl;
		num= _getch();
	switch(num)
	{
		case 48:
		break;
		case 49:
		Menu(oldData);
		break;
		case 50:
		CheckBalance();
		break;
		default:
		cout<<"\n		Eroare! Sectiune negasita. Incearca inca o data"<< endl
		<< endl;
		system("pause");
		break;
		}
	} 	while(num != '0');
	} 	else
		cout<<"\n		Numele sau parola sunt gresite \n";
	break;
		case 50:
		system("cls");
		cout<<"\n		Introdu numele fara spatii \n";
		cout<<"\n		";
		cin>>data.name;
		cout<<"\n		Introdu parola fara spatii\n";
		cout<<"\n		";
		cin>> data.password;
		data.balance = 0;
		data.borrowed = 0;
		inputNewData(data);
		break;
		default:
		cout<<"\n		There is no such section \n";
		cout<<"\n		one more time \n";
		break;
	}
	} 	while(choice != 51);
		cout<< "\n			";
}


