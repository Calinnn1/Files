#include <iostream> // Input & output
#include <string>  // Text
#include <ctime>   // Time sleep
#include <ctype.h> // Validation
#include <conio.h> // _getch()
#include <windows.h> // Loading
#include <fstream> // File handling 
#include <chrono>

// Header files
#include "Header.h"
#include "Loading.h"
#include "Vegetables.h"
#include "Water.h"
#include "BreadBakery.h"

using namespace std;

//pret admin & schimbari cantitate depozit
	int price;
	int quantity;
	int Overall_Sum; // calculand per total sum

//Parola si Log in pentru admin
	string Owner_Login_Sign = "Rus02";
	string Owner_Parol_Sign = "Rus02";

//string Owner_Login_Sign = "1";
//string Owner_Parol_Sign = "1";

// Objects
	Security User_1;
	Product_VegetablesFruits Test;
	Product_WaterBeverages Test1;
	Product_BreadBakery Test2;

// Functii de declarare
void F_General_Menu();
void F_Sign_in();
void F_Developers();
void F_Logo(); // Logo "Lughia" pt User
void F_Logo_Owner(); // Logo "Lughia" pt Owner

void F_Owner_Main_Menu(); // Meniu principal pt Owner
void F_Owner_Products_Stotage();
void F_Owner_Customers_List();

void F_User_Main_Menu(); // Meniu principal pt User
void F_Table_For_Increasing_And_Decreasing(); // User
void F_Vegetables_Fruits_Menu(); // User
void F_Water_Beverages_Menu(); // User
void F_Bread_Bakery_Menu(); // User
void F_Cart_Check();

// Functia Main
int main() {
	// Timpul incarcare
    	F_Loading();
	F_General_Menu();
	
	cout << "\n\n\t\t\t\t   Multumim pentru atentie!!!\n\n" << endl;
	system("pause");
	return 0;
}

void F_General_Menu() {
	// Meniul de autentificare principal
	for (int i = 0; i < 1000; i++) {
		system("cls");
		cout << "____________________________________________________________________________________________________ \n";
		cout << "     	   A U T E N T I F I C A R E					  M A R K E T          \n";
		cout << "____________________________________________________________________________________________________\n\n";
		cout << "\t\t\t\t\t  Autentificare \n" << endl;
		cout << "\t\t\t\t\t   1. Logare" << endl;
		cout << "\t\t\t\t\t   2. Inregistrare" << endl;
		cout << "\t\t\t\t\t   3. Despre" << endl;
		cout << "\t\t\t\t\t   0. Iesire" << endl << endl;
		cout << "\t\t\t\t\t  Alegerea ta: ";
		switch (_getch()) {
		case 49: // Logare
			system("cls");
			F_Sign_in();
			system("pause");
		    break;

		case 50: {   // Inregistrare ('inregistreaza-te')   // Seteaza detalii cu validarea    
			for (int i = 0; i != 1;) {
				system("cls");
				cout << "____________________________________________________________________________________________________ \n";
				cout << "       I N R E G I S T R A R E					  	    M A R K E T          \n";
				cout << "____________________________________________________________________________________________________\n\n";
				cout << "\t\t\t\t       Exemplu de Inregistrare: " << endl ;
				cout << "\t\t\t\t        ______________________" << endl;
				cout << "\t\t\t\t        Nume Utilizator  : Calin " << endl;
				cout << "\t\t\t\t        Telefon  : 0745876351 " << endl;
				cout << "\t\t\t\t        Login      : Calimov_8 " << endl;
				cout << "\t\t\t\t        Parola   : Calimov808 " << endl;
				cout << "\t\t\t\t        ______________________" << endl << endl;
				User_1.SetUser();   
				ValidationParol(User_1);
				ValidationName(User_1);
				ValidationTellNum(User_1);
				if (Validation == 3) {
					//////   File Handling pt User Info
					ofstream User_1_Info;
					User_1_Info.open("User_Info.txt");  // Opening File
					// Setand info utilizator catre Memory
					User_1_Info << Name_Memory << endl;
					User_1_Info << TellNum_Memory << endl;
					User_1_Info << Login_Memory << endl;
					User_1_Info << Parol_Memory << endl;
					User_1_Info.close();
					///////// Finalul File Handling
					cout << "\t\t              __________________________________" << endl;
					cout << "\t\t                      Validare Corecta" << endl;
					i++; 
					cout << "                          Te rog apasa orice buton pentru continuarea programului" << endl << endl; system("Pause");
					Validation = 0;
				}
				else {
					cout << "\t\t              __________________________________" << endl;
					cout << "\t\t                      Validare Invalida" << endl;
					cout << "                          Te rog apasa orice tasta pentru reintroducerea detaliilor" << endl << endl;
					system("Pause"); system("cls");
					Validation = 0;
				} // switch case sfarsit
			} // for loop sfarsit
		}break;

		case 51:   // Developers
			system("cls");
			F_Developers();
	        break;
		case 48:
			//i = 1000;
			system("exit");
			break;

			default:  cout << "\n\n\t\t\t       Alegerea ta nu este valabila in meinu." << endl;
			cout << "\t\t\t\t    Te rog introdu tastele corecte.\n" << endl;
			system("pause");
			
		} // switch case ends
	} // for loop ends
}

// functie Sign in
void F_Sign_in() {

	for (int i = 0; i < 1000; i++) {
		system("cls");
		cout << "____________________________________________________________________________________________________ \n";
		cout << "       	 L O G A R E                                                 	 M A R K E T			  \n";
		cout << "____________________________________________________________________________________________________\n\n";
		cout << "\t\t\t\t\t     Logare\n\n";
		cout << "\t\t\t\t\t1. Logare ca Admin" << endl;
		cout << "\t\t\t\t\t2. Logare ca utilizator" << endl;
		cout << "\t\t\t\t\t0. Inapoi" << endl << endl;
		cout << "\t\t\t\t\t   Alegerea ta: ";

		switch (_getch()) {
		case 49: {  // Logare ca administrator
			system("cls");
			cout << "____________________________________________________________________________________________________ \n";
			cout << "    	    A D M I N                                                        M A R K E T		       \n";
			cout << "____________________________________________________________________________________________________\n\n";
			cout << "\t\t\t\t         Autentificarea Admin\n\n";
			cout << "\t\t\t\t\t  Login   : "; cin >> Login_Sign;
			cout << "\t\t\t\t\t  Parola : "; cin >> Parol_Sign;
			if (Login_Sign == Owner_Login_Sign && Parol_Sign == Owner_Parol_Sign) {
				// meniul administratorului
				F_Owner_Main_Menu();
				system("pause");
			}
			else {  // Daca log in nu s a inregistrat
				cout << "\n\n\t\t\t        Parola ta de logare sau parola sunt invalide." << endl;
				cout << "\t\t\t     Te rog apasa orice buton pentru redirectionare in meniul 'Logare'.\n\n" << endl;
				system("pause");
				F_Sign_in();
			} // else ends
		}	break;

		case 50: {   // logare ca User
			system("cls");
			//////   File Handling For User Info
			ifstream User_1_Info;
			User_1_Info.open("User_Info.txt");
			User_1_Info >> Name_Memory;
			User_1_Info >> TellNum_Memory;
			User_1_Info >> Login_Memory;
			User_1_Info >> Parol_Memory;
			User_1_Info.close();
			///////// Sfarsitul File Handling
			cout << "____________________________________________________________________________________________________ \n";
			cout << "        	C L I E N T														   M A R K E T            \n";
			cout << "____________________________________________________________________________________________________\n\n";
			cout << "\t\t\t\t         Authenticarea Clientului\n\n";
			cout << "\t\t\t\t\t  Login    : "; cin >> Login_Sign;
			cout << "\t\t\t\t\t  Parola : "; cin >> Parol_Sign;
			if (Login_Sign == Login_Memory && Parol_Sign == Parol_Memory) {
				/////// Meniu User
				F_User_Main_Menu();
				///////
			}
			else {  // daca Login nu s-a inregistrat
				cout << "\n\n\t\t\t        Numele sau parola sunt invalide." << endl;
				cout << "\t\t\t     Te rog apasa orice buton pentru redirectionare in meniul 'Logare'.\n\n" << endl;
				system("pause");
				F_Sign_in();
			} // else terminat
		}	break;

		case 48: {   // Inapoi
			system("cls");
			i = 1000;
			F_General_Menu();
		}	break;

			default: 
			cout << "\n\n\t\t\t       Alegerea ta nu este valabila in meniu." << endl;
			cout << "\t\t\t\t    Te rog introdu tastele corecte.\n" << endl;
			system("pause");

		} // switch
	} // for
}

void F_Developers() {
	cout << "____________________________________________________________________________________________________ \n";
	cout << "        D E S P R E					  	    M A R K E T          \n";
	cout << "____________________________________________________________________________________________________\n\n";
	cout << "\n\t\t\t\t'Lughia' Aplicatie de Cumparaturi Online " << endl << endl;

	cout << "\n\n\t\t           Apasa orice tasta pentru returnare la meniu \n\n" << endl;
	system("pause");
	F_General_Menu();
}

void F_Logo() {
	system("cls");
	cout << "____________________________________________________________________________________________________ \n";
	cout << "        L U G H I A                                                    8. Informatii Cont         \n";
	cout << "____________________________________________________________________________________________________\n\n";
}

void F_Logo_Owner() {
	system("cls");
	cout << "____________________________________________________________________________________________________ \n";
	cout << "        L U G H I A                                       M E N I U  A D M I N                 \n";
	cout << "____________________________________________________________________________________________________\n\n";
}

//Liniile/partile admin 252 - 727
void F_Owner_Main_Menu() {
	// intrand ca administrator al shopului
	for (int k = 0; k < 1000; k++) {
		F_Logo_Owner();
		cout << "      Meniu Principal\n\n";
		cout << "      1. Produse in stoc \n\n";
		cout << "      2. Lista clienti \n\n";
		cout << "      0. Inapoi\n\n";
		cout << "      Alegerea ta: ";

	switch (_getch()) {
		case 49: {
			  F_Owner_Products_Stotage();
		} 	break;

		case 50: {
			/*F_Owner_Customers_List();*/
			system("cls");
			cout << "____________________________________________________________________________________________________ \n";
			cout << "        L U G H I A                                           L I S T A  C L I E N T I        \n";
			cout << "____________________________________________________________________________________________________\n\n";
			cout << "\n\t\t\t   Lista clienti :" << endl << endl;
			cout << "\t\t      Nume Utilizator  : " << Name_Memory << endl;
			cout << "\t\t      Telefon  : " << TellNum_Memory << endl << endl << endl;
			
			system("pause");
		} 	break;

		
		case 48: {  // Inapoi la meniu
			system("cls");
			k = 1000;
			F_Sign_in();
		} 	break;

			default: { cout << "\n\n\t\t\t       Alegerea ta nu este valabia in meniu." << endl;
			cout << "\t\t\t\t    Te rog introdu tastele corecte.\n" << endl;
			system("pause");
		}
		} // switch 
	} // for loop 
}

void F_Owner_Products_Stotage(){
	for (int i = 0; i < 1000; i++) {
		F_Logo_Owner();
		cout << "  Lista produse                               Categorie                      Pret        Pe stoc\n";
		cout << "____________________________________________________________________________________________________ \n";
		cout << " 1. Cartofi, greutate                       Legume & Fructe                " << Test.get_price_potatoes()                << "\t\t  " << Test.get_storage_quantity_potatoes()               << endl;
		cout << " 2. Morcov Galben, greutate                 Legume & Fructe                " << Test.get_price_carrot()                  << "\t\t  " << Test.get_storage_quantity_carrot()                 << endl;
		cout << " 3. Ceapa, greutate                         Legume & Fructe                " << Test.get_price_onion()                   << "\t\t  " << Test.get_storage_quantity_onion()                  << endl;
		cout << " 4. Apa, Hydrolife fara gaz 750ml           Ape & Bauturi                  " << Test1.get_price_water_hydrolife_750ml()  << "\t\t  " << Test1.get_storage_quantity_water_hydrolife_750ml() << endl;
		cout << " 5. Bautura, Aloe Original 500ml            Ape & Bauturi                  " << Test1.get_price_drink_aloe_500ml()       << "\t\t  " << Test1.get_storage_quantity_drink_aloe_500ml()      << endl;
		cout << " 6. Nectar, Zet Mere 125ml                  Ape & Bauturi                  " << Test1.get_price_nectar_zet_125ml()       << "\t\t  " << Test1.get_storage_quantity_nectar_zet_125ml()      << endl;
		cout << " 7. Chifla Smart Food                       Paine & Produse patiserie      " << Test2.get_price_bun_smart_food()         << "\t\t  " << Test2.get_storage_quantity_bun_smart_food()        << endl;
		cout << " 8. Biscuiti Tuc cheese 100g                Paine & Produse patiserie      " << Test2.get_price_cracker_tuc_cheese_100g() << "\t\t  " << Test2.get_storage_quantity_cracker_tuc_cheese_100g() << endl;
		cout << " 9. Paine de Salonta                        Paine & Produse patiserie      " << Test2.get_price_bread_samarkand()         << "\t\t  " << Test2.get_storage_quantity_bread_samarkand() << endl;
		cout << " \n 0. Inapoi\n";
		cout << " Fa schimbari in: ";
		switch (_getch())
		{
		case '1': 			
			for (int j = 0; j < 1000; j++) {
				system("cls");
				cout << "\n  Produs                                     Categorie                     Pret         Pe stoc\n";
				cout << "____________________________________________________________________________________________________ \n";
				cout << " Cartofi, greutate                          Legume & Fructe             " << Test.get_price_potatoes() << "\t\t " << Test.get_storage_quantity_potatoes()+Test.get_storage_quantity_potatoes() << endl;
				cout << "\n 1. Schimba pretul \n 2. Schimba cantitatea in depozit\n 0. Mergi inapoi \n Apasa '1' sau '2' sau '0'\n\n";
				
				switch (_getch()) {
				case 49:
					cout << " Introdu un nou pret: ";
					cin >> price;
					if (price >= 0) {
						Test.set_price_potatoes(price);
						cout << " Schimbat cu succes!\n";
						Sleep(0700); Sleep(0700);
					}
					else {
						cout << " Pretul nu poate fi negativ! Te rog verifica din nou.\n";
						Sleep(0700); Sleep(0700);
					}
					break;
				case 50:
					cout << " Introdu o cantitate noua in depozit: ";
					cin >> quantity;
					if (quantity > 0) {
						Test.set_storage_quantity_potatoes(quantity);
						cout << " Schimbat cu succes!\n";
						Sleep(0700); Sleep(0700);
					}
					else {
						cout << " Cantitatea nu poate fi negativa\n";
						Sleep(0700); Sleep(0700);
					}
					
					break;
				case 48:
					j = 1000;
					break;
				}// 'switch' 
			}// 'for' loop 
			break;
		case '2':			
		    for (int j = 0; j < 1000; j++) {
				system("cls");
				cout << "\n  Produs                                     Categorie                     Pret         In stoc\n";
				cout << "____________________________________________________________________________________________________ \n";
				cout << " Morcov Galben, greutate                     Legume & Fructe             " << Test.get_price_carrot() << "\t\t " << Test.get_storage_quantity_carrot() << endl;
				cout << "\n 1. Schimba pretul \n 2. Schimba cantitatea in depozit\n 3. Mergi inapoi \n Apasa '1' sau '2' sau '0'\n\n ";
				switch (_getch()) {
				case 49:
					cout << "Introdu un pret nou: ";
					cin >> price;
					if (price >= 0) {
						Test.set_price_carrot(price);
						cout << " Schimbat cu succes!\n";
						Sleep(0700); Sleep(0700);
					}
					else {
						cout << " Pretul nu poate fi negativ! Te rog verifica inca o data.\n";
						Sleep(0700); Sleep(0700);
					}
					break;
				case 50:
					cout << "Introdu o cantitate noua in stoc: ";
					cin >> quantity;

					if (quantity > 0) {
						Test.set_storage_quantity_carrot(quantity);
						cout << " Schimbat cu succes!\n";
						Sleep(0700); Sleep(0700);
					}
					else {
						cout << " Cantitatea nu poate fi negativa\n";
						Sleep(0700); Sleep(0700);
					}

					break;
				case 48:
					j = 1000;
					break;
				}// 'switch' 
			}// 'for' loop 
			break;
		case '3': 			
		    for (int j = 0; j < 1000; j++) {
				system("cls");
				cout << "\n  Produs                                     Categorie                     Pret         In stoc\n";
				cout << "____________________________________________________________________________________________________ \n";
				cout << " Ceapa, greutate                             Legume & Fructe             " << Test.get_price_onion() << "\t\t " << Test.get_storage_quantity_onion() << endl;
				cout << "\n 1. Schimba pretul \n 2. Schimba cantitatea in depozit\n 3. Mergi inapoi \n Apasa '1' sau '2' sau '0'\n\n ";
				switch (_getch()) {
				case 49:
					cout << "Introdu un nou pret: ";
					cin >> price;
					if (price >= 0) {
						Test.set_price_onion(price);
						cout << " Schimbat cu succes!\n";
						Sleep(0700); Sleep(0700);
					}
					else {
						cout << " Pretul nu poate fi negativ! Te rog verifica inca o data.\n";
						Sleep(0700); Sleep(0700);
					}
					break;
				case 50:
					cout << "Introdu o noua cantitate in depozit: ";
					cin >> quantity;
					if (quantity > 0) {
						Test.set_storage_quantity_onion(quantity);
						cout << " Schimbat cu succes!\n";
						Sleep(0700); Sleep(0700);
					}
					else {
						cout << " Cantitatea nu poate fi negativa\n";
						Sleep(0700); Sleep(0700);
					}
					break;
				case 48:
					j = 1000;
					break;
				}// 'switch' 
			}// 'for' loop 
			break;
		case '4':		
			for (int j = 0; j < 1000; j++) {
				system("cls");
				cout << "\n  Produs                                     Categorie                     Pret         In stoc\n";
				cout << "____________________________________________________________________________________________________ \n";
				cout << " Apa, Hydrolife fara gaz 750ml        Ape & Bauturi               " << Test1.get_price_water_hydrolife_750ml() << "\t\t " << Test1.get_storage_quantity_water_hydrolife_750ml() << endl;
				cout << "\n 1. Schimba pretul \n 2. Schimba cantitatea in depozit\n 3. Mergi inapoi \n Apasa '1' sau '2' sau '0'\n\n ";

				switch (_getch()) {
				case 49:
					cout << "Introdu pret nou: ";
					cin >> price;
					
					if (price >= 0) {
						Test1.set_price_water_hydrolife_750ml(price);
						cout << " Schimbat cu succes!\n";
						Sleep(0700); Sleep(0700);
					}
					else {
						cout << " Pretul nu poate fi negativ! Te rog verifica inca o data..\n";
						Sleep(0700); Sleep(0700);
					}
					break;
				case 50:
					cout << "Introdu o noua cantitate in depozit: ";
					cin >> quantity;					
					if (quantity > 0) {
						Test1.set_storage_quantity_water_hydrolife_750ml(quantity);
						cout << " Schimbat cu succes!\n";
						Sleep(0700); Sleep(0700);
					}
					else {
						cout << " Cantitatea nu poate fi negativa\n";
						Sleep(0700); Sleep(0700);
					}
					break;
				case 48:
					j = 1000;
					break;
				}// 'switch' 
			}// 'for' loop 
			break;
		case '5': 		
			for (int j = 0; j < 1000; j++) {
				system("cls");
				cout << "\n  Produs                                     Categorie                     Pret         Pe Stoc\n";
				cout << "____________________________________________________________________________________________________ \n";
				cout << " Bautura, Aloe Original 500ml                Ape & Bauturi               " << Test1.get_price_drink_aloe_500ml() << "\t\t " << Test1.get_storage_quantity_drink_aloe_500ml() << endl;
				cout << "\n 1. Schimba pretul \n 2. Schimba cantitatea in depozit\n 3. Mergi inapoi \n Apasa '1' sau '2' sau '0'\n\n ";

				switch (_getch()) {
				case 49:
					cout << "Introdu un pret nou: ";
					cin >> price;

					if (price >= 0) {
						Test1.set_price_drink_aloe_500ml(price);
						cout << " Schimbat cu succes!\n";
						Sleep(0700); Sleep(0700);
					}
					else {
						cout << " Pretul nu poate fi negativ! Te rog verifica inca o data..\n";
						Sleep(0700); Sleep(0700);
					}
					break;
				case 50:
					cout << "Introdu o noua cantitate in depozit: ";
					cin >> quantity;
					
					if (quantity > 0) {
						Test1.set_storage_quantity_drink_aloe_500ml(quantity);
						cout << " Schimbat cu succes!\n";
						Sleep(0700); Sleep(0700);
					}
					else {
						cout << " Cantitatea nu poate fi negativa\n";
						Sleep(0700); Sleep(0700);
					}
					break;
				case 48:
					j = 1000;
					break;
				}// 'switch' 
			}// 'for' loop 
			break;
		case '6':		
			for (int j = 0; j < 1000; j++) {
				system("cls");
				cout << "\n  Produs                                     Categore                     Pret         Pe Stoc\n";
				cout << "____________________________________________________________________________________________________ \n";
				cout << " Nectar, Zet Mere 125ml                   Ape & Bauturi               " << Test1.get_price_nectar_zet_125ml() << "\t\t " << Test1.get_storage_quantity_nectar_zet_125ml() << endl;
					cout << "\n 1. Schimba pretul \n 2. Schimba cantitatea in depozit\n 3. Mergi inapoi \n Apasa '1' sau '2' sau '0'\n\n ";

				switch (_getch()) {
				case 49:
					cout << " Introdu un nou pret: ";
					cin >> price;	
					if (price >= 0) {
						Test1.set_price_nectar_zet_125ml(price);
						cout << " Schimbat cu succes!\n";
						Sleep(0700); Sleep(0700);
					}
					else {
						cout << " Pretul nu poate fi negativ! Te rog verifica inca o data..\n";
						Sleep(0700); Sleep(0700);
					}
					break;
				case 50:
					cout << "Introdu o noua cantitate in depozit: ";
					cin >> quantity;
					if (quantity > 0) {
						Test1.set_storage_quantity_nectar_zet_125ml(quantity);
						cout << " Schimbat cu succes!\n";
						Sleep(0700); Sleep(0700);
					}
					else {
						cout << " Cantitatea nu poate fi negativa\n";
						Sleep(0700); Sleep(0700);
					}
					break;
				case 48:
					j = 1000;
					break;
				}// 'switch' 
			}// 'for' loop 
			break;
		case '7':			
			for (int j = 0; j < 1000; j++) {
				system("cls");
				cout << "\n  Produs                                     Categorie                     Pret         Pe Stoc\n";
				cout << "____________________________________________________________________________________________________ \n";
				cout << " Chifla Smart Food                            Paine & Produse patiserie         " << Test2.get_price_bun_smart_food() << "\t\t " << Test2.get_storage_quantity_bun_smart_food() << endl;
				cout << "\n 1. Schimba pretul \n 2. Schimba cantitatea in depozit\n 3. Mergi inapoi \n Apasa '1' sau '2' sau '0'\n\n ";
				switch (_getch()) {
				case 49:
					cout << " Introdu un nou pret: ";
					cin >> price;	
					if (price >= 0) {
						Test2.set_price_bun_smart_food(price);
						cout << " Schimbat cu succes!\n";
						Sleep(0700); Sleep(0700);
					}
					else {
						cout << " Pretul nu poate fi negativ! Te rog verifica inca o data..\n";
						Sleep(0700); Sleep(0700);
					}
					break;
				case 50:
					cout << "Introdu o noua cantitate in depozit: ";
					cin >> quantity;
					if (quantity > 0) {
						Test2.set_storage_quantity_bun_smart_food(quantity);
						cout << " Schimbat cu succes!\n";
						Sleep(0700); Sleep(0700);
					}
					else {
						cout << " Cantitatea nu poate fi negativa\n";
						Sleep(0700); Sleep(0700);
					}
					break;
				case 48:
					j = 1000;
					break;
				}// 'switch' 
			}// 'for' loop 
			break;
		case '8':			
			for (int j = 0; j < 1000; j++) {
				system("cls");
				cout << "\n  Produs                                     Categorie                     Pret         In Stoc\n";
				cout << "____________________________________________________________________________________________________ \n";
				cout << " Biscuiti Tuc cheese 100g                   Paine & Produse patiserie         " << Test2.get_price_cracker_tuc_cheese_100g() << "\t\t " << Test2.get_storage_quantity_cracker_tuc_cheese_100g() << endl;
				cout << "\n 1. Schimba pretul \n 2. Schimba cantitatea in depozit\n 3. Mergi inapoi \n Apasa '1' sau '2' sau '0'\n\n ";
				switch (_getch()) {
				case 49:
					cout << " Introdu un nou pret: ";
					cin >> price;
					if (price >= 0) {
						Test2.set_price_cracker_tuc_cheese_100g(price);
						cout << " Schimbat cu succes!\n";
						Sleep(0700); Sleep(0700);
					}
					else {
						cout << " Pretul nu poate fi negativ! Te rog verifica inca o data..\n";
						Sleep(0700); Sleep(0700);
					}
					break;
				case 50:
					cout << "Introdu o noua cantitate in depozit: ";
					cin >> quantity;				
					if (quantity > 0) {
						Test2.set_storage_quantity_cracker_tuc_cheese_100g(quantity);
						cout << " Schimbat cu succes!\n";
						Sleep(0700); Sleep(0700);
					}
					else {
						cout << " Cantitatea nu poate fi negativan";
						Sleep(0700); Sleep(0700);
					}
					break;
				case 48:
					j = 1000;
					break;
				}// 'switch' 
			}// 'for' loop 
			break;
		case '9':			
			for (int j = 0; j < 1000; j++) {
				system("cls");
				cout << "\n  Produs                                     Categorie                     Pret         Pe Stoc\n";
				cout << "____________________________________________________________________________________________________ \n";
				cout << " Paine de Salonta                        Paine & Produse patiserie         " << Test2.get_price_bread_samarkand() << "\t\t " << Test2.get_storage_quantity_bread_samarkand() << endl;
	 		    cout << "\n 1. Schimba pretul \n 2. Schimba cantitatea in depozit\n 3. Mergi inapoi \n Apasa '1' sau '2' sau '0'\n\n ";
				switch (_getch()) {
				case 49:
					cout << " Introdu un nou pret: ";
					cin >> price;
					
					if (price >= 0) {
						Test2.set_price_bread_samarkand(price);
						cout << " Schimbat cu succes!\n";
						Sleep(0700); Sleep(0700);
					}
					else {
						cout << " Pretul nu poate fi negativ! Te rog verifica inca o data..\n";
						Sleep(0700); Sleep(0700);
					}
					break;
				case 50:
					cout << "Introdu o noua cantitate in depozit: ";
					cin >> quantity;					
					if (quantity > 0) {
						Test2.set_storage_quantity_bread_samarkand(quantity);
						cout << " Schimbat cu succes!\n";
						Sleep(0700); Sleep(0700);
					}
					else {
						cout << " Cantitatea nu poate fi negativa\n";
						Sleep(0700); Sleep(0700);
					}
					break;
				case 48:
					j = 1000;
					break;
				}// 'switch' 
			}// 'for' loop 
			break;
		case '0': {  // Inapoi la mienu
			system("cls");
			i = 1000;
			F_Sign_in();
		} break;

		case 'i' || 'I': { // User info   
			system("cls");
			cout << "\n\t\t\t   Informatii Utilizator:" << endl;;
			cout << "\t\t    _______________________________" << endl << endl;;
			cout << "\t\t      Nume Utilizator  : " << Name_Memory << endl;
			cout << "\t\t      Telefon  : " << TellNum_Memory << endl;
			cout << "\t\t      Login      : " << Login_Memory << endl;
			cout << "\t\t      Parola   : " << Parol_Memory << endl << endl << endl;
			system("pause");
		}
			   break;
			
		default: { cout << "\n\t\t      Alegerea ta nu este valabila in Meniu" << endl;
			cout << "\t\tTe rog apasa pe orice buton pentru a continua cu programul\n" << endl;
			system("pause");
		}
		} 
		
	} // for loop pentru produse in stoc  
}

void F_Owner_Customers_List(){
	system("cls");
	ofstream User_1_Info;
		User_1_Info.open("User_Info.txt");  // Opening File
		// Setand Info user catre Memorie
		User_1_Info << Name_Memory << endl;
		User_1_Info << TellNum_Memory << endl;
		//User_1_Info.close();
		cout << "\n\t\t\t   Lista clienti :" << endl;;
		cout << "\t\t    _______________________________" << endl << endl;;
		cout << "\t\t      Nume utilizator  : " << Name_Memory << endl;
		cout << "\t\t      Telefon  : " << TellNum_Memory << endl << endl << endl;
	system("pause");
}

// Liniile/partile userului 728 - 1282
void F_User_Main_Menu() {
	// Intrand ca user
	for (int i = 0; i < 1000; i++) {
		F_Logo();
		cout << "      Categorii\n\n";
		cout << "      1. Legume & Fructe\n\n";
		cout << "      2. Ape & Bauturi\n\n";
		cout << "      3. Paine & Produse patiserie\n\n";
		cout << "      4. Caruciorul si suma totala\n\n";
		cout << "      0. Mergi inapoi\n\n";
		cout << "      Alegerea ta: ";

		switch (_getch()) {
		case 49: {
			F_Vegetables_Fruits_Menu();
		} break;

		case 50: {
			F_Water_Beverages_Menu();
		} break;

		case 51: {
			F_Bread_Bakery_Menu();
		}
		case 52:
		{
			F_Cart_Check();
		}
			   break;
		case 48: {  // Inapoi la meniu
			system("cls");
			i = 1000;
			F_Sign_in();
		} break;

		case 56: { // User info   
			system("cls");
			cout << "____________________________________________________________________________________________________ \n";
			cout << "        L U G H I A                                   I N F O  U T I L I Z A T O R       \n";
			cout << "____________________________________________________________________________________________________\n\n";
			cout << "\t\t\t\t    Informatii utilizator:" << endl << endl;
			cout << "\t\t\t\t      Nume utilizator  : " << Name_Memory << endl;
			cout << "\t\t\t\t      Telefon  : " << TellNum_Memory << endl;
			cout << "\t\t\t\t      Login      : " << Login_Memory << endl;
			cout << "\t\t\t\t      Parola   : " << Parol_Memory << endl << endl << endl;
			system("pause");
		}
			break;

		default: { cout << "\n\n\t\t\t       Alegerea ta nu este valabila in meniu." << endl;
			cout << "\t\t\t\t    Te rog introdu cheile corecte.\n" << endl;
			system("pause");
		}
		} // switch 
	} // for loop 
}

void F_Table_For_Increasing_And_Decreasing() {

	cout << "     (+)   'Apasa 1'                        \n";
	cout << "     (-)   'Apasa 2'                        \n";
	cout << "     (0)   'Inapoi'                           \n";
	cout << "____________________________________________________________________________________________________\n\n";
	cout << "     Adauga in cos:  \n";
	//cin >> VariableForIncreasingAndDecreasing;
}

void F_Vegetables_Fruits_Menu() {
	for (int k = 0; k < 1000; k++) {
		F_Logo();
		cout << "      Categorie -> Legume & Fructe \t\t Cos \n";
		cout << "____________________________________________________________________________________________________\n\n";
		cout << " 1. Cartofi, greutate \t\t\t\t\t"; cout << Test.get_quantity_potatoes() << " (kg)" << endl;
		cout << "    " << Test.get_price_potatoes() << " UZS pentru 1 kg\n\n";
		cout << " 2. Morcovi Galbeni, greutate \t\t\t\t"; cout << Test.get_quantity_carrot() << " (kg)" << endl;
		cout << "    " << Test.get_price_carrot() << " UZS pentru 1 kg\n\n";
		cout << " 3. Ceapa, greutate \t\t\t\t\t"; cout << Test.get_quantity_onion() << " (kg)" << endl;
		cout << "    " << Test.get_price_onion() << " UZS pentru 1 kg\n\n";
		cout << " 0. Inapoi\n\n";
		cout << " Alegerea ta: ";
		switch (_getch()) {
			// pentru cartofi
		case 49: {
			for (int j = 0; j < 1000; j++) {
				system("cls");
				cout << "      Categorie -> Legume & Fructe \t\t Cos \n";
				cout << "____________________________________________________________________________________________________\n";
				cout << "     Cartofi, greutate \t\t\t\t\t"; cout << Test.get_quantity_potatoes() << " (kg)" << endl;
				cout << "     " << Test.get_price_potatoes() << " UZS pentru 1 kg\n\n";
				//
				
	            F_Table_For_Increasing_And_Decreasing();
				
				switch (_getch()) {
				case 49:
					if (Test.get_storage_quantity_potatoes() > 0) { // verificand nevoi depozit si utilizator
						Test.set_quantity_potatoes_incrementing();
						cout << " Cantitate de Cartofi (kg): " << Test.get_quantity_potatoes() << endl;
						cout << "   Adaugata cu succes \n";
						Sleep(0700); Sleep(0700);
					}
					else {
						cout << " Ne pare rau s-a terminat / sfarsit produsul!\n";
						Sleep(0700); Sleep(0700);
					}
					break;
				case 50:
					if (Test.get_quantity_potatoes() > 0) { // verif pentru (-1 kg)
						Test.set_quantity_potatoes_decrementing();
						cout << " Cantitate de Cartofi (kg): " << Test.get_quantity_potatoes() << endl;
						cout << "   Scazuta cu succes \n";
						Sleep(0700); Sleep(0700);
					}
					else { cout << " 0 (kg) nu poate scadea \n"; Sleep(0700); Sleep(0700); }
					break;
				case 48:
					j = 1000;
					break;
				}// 'switch' pentru cartofi
			}// 'for' loop pentru cartofi
		}
			   break;
			   // case 2 - pentru morcov
		case 50: {
			for (int j = 0; j < 1000; j++) {
				system("cls");
				// Rustam s-a schimbat
				cout << "      Categorie -> Vegetables & Fruits \t\t Cos \n";
				cout << "____________________________________________________________________________________________________\n";
				cout << "     Morcov Galben, greutate \t\t\t\t"; cout << Test.get_quantity_carrot() << " (kg)" << endl;
				cout << "     " << Test.get_price_carrot() << " UZS pentru 1 kg\n\n";
			
				F_Table_For_Increasing_And_Decreasing();
		
				switch (_getch()) {
				case 49:
				
					//
					if (Test.get_storage_quantity_carrot() > 0) { // verificand nevoi depozit si utilizator
						Test.set_quantity_carrot_incrementing();
						cout << " Cantitate de Morcovi (kg): " << Test.get_quantity_carrot() << endl;
						cout << "   Adaugat cu succes \n";
						Sleep(0700); Sleep(0700);

					}
					else {
						cout << " Ne pare rau s-a terminat / sfarsit produsul!\n";
						Sleep(0700); Sleep(0700);
					}
					//
					break;
				case 50:
					if (Test.get_quantity_carrot() > 0) { // verif pentru (-1 kg)
						Test.set_quantity_carrot_decrementing();
						cout << " Cantitate de Morcovi (kg): " << Test.get_quantity_carrot() << endl;
						cout << "   Scazut cu succes \n";
						Sleep(0700); Sleep(0700);
					}
					else { cout << " 0 (kg) nu poate scadea \n"; Sleep(0700); Sleep(0700); }
					break;
				case 48:
					j = 1000;
					break;
				}// 'switch' pentru morcov
			}// 'for' loop pentru morcov
		}
			   break;
			   // case 3 - pentru ceapa
		case 51: {
			for (int j = 0; j < 1000; j++) {
				system("cls");
				// Rustam s-a schimbat
				cout << "      Categorie -> Vegetables & Fruits \t\t Cos \n";
				cout << "____________________________________________________________________________________________________\n";
				cout << "     Ceapa, greutate \t\t\t\t\t"; cout << Test.get_quantity_onion() << " (kg)" << endl;
				cout << "     " << Test.get_price_onion() << " UZS pentru 1 kg\n\n";
				//
				F_Table_For_Increasing_And_Decreasing();

				switch (_getch()) {
				case 49:				
					if (Test.get_storage_quantity_onion() > 0) { // verificand nevoi depozit si utilizator
						Test.set_quantity_onion_incrementing();
						cout << " Cantitate de Ceapa (kg): " << Test.get_quantity_onion() << endl;
						cout << "   Adaugat cu succes \n";
						Sleep(0700); Sleep(0700);
			       	}
					else {
					cout << " Ne pare rau s-a terminat / sfarsit produsul!\n";
					Sleep(0700); Sleep(0700);
					}
					break;
				case 50:
					if (Test.get_quantity_onion() > 0) { // verif pentru (-1 kg)
						Test.set_quantity_onion_decrementing();
						cout << " Cantitate de Ceapa (kg): " << Test.get_quantity_onion() << endl;
						cout << "   Scazut cu succes \n";
						Sleep(0700); Sleep(0700);
					}
					else { cout << " 0 (kg) cannot  decrease \n"; Sleep(0700); Sleep(0700); }
					break;
				case 48:
					j = 1000;
					break;
				}// 'switch' pentru ceapa
			}// 'for' loop pentru ceapa
		}
			   break;
			   // Inapoi la meniu F_User
		case 48: {   k = 1000;
			F_User_Main_Menu(); }
			   break;
		case 56: { // User info   
			system("cls");
			cout << "____________________________________________________________________________________________________ \n";
			cout << "        L U G H I A                                                   U S E R  I N F O         \n";
			cout << "____________________________________________________________________________________________________\n\n";
			cout << "\t\t\t\t    Informatii utilizator:" << endl << endl;
			cout << "\t\t\t\t      Nume utilizator  : " << Name_Memory << endl;
			cout << "\t\t\t\t      Telefon  : " << TellNum_Memory << endl;
			cout << "\t\t\t\t      Login      : " << Login_Memory << endl;
			cout << "\t\t\t\t      Parola   : " << Parol_Memory << endl << endl << endl;
			system("pause");
		}
			   break;
		default: { cout << "\n\n\t\t\t       Alegerea ta nu este valabila in meniu." << endl;
			cout << "\t\t\t\t    Te rog introdu tastele corecte.\n" << endl;
			system("pause");
		}	
		} // switch terminat
	} // loop terminat
} // functie terminat

void F_Water_Beverages_Menu() {
	for (int k = 0; k < 1000; k++) {
		F_Logo();
		cout << "      Categorie -> Ape & Bauturi \t\t\t Cos \n";
		cout << "____________________________________________________________________________________________________\n\n";
		cout << " 1. Apa, Hydrolife without gas 750ml \t\t\t"; cout << Test1.get_quantity_water_hydrolife_750ml() << " (pc)" << endl;
		cout << "    " << Test1.get_price_water_hydrolife_750ml() << " UZS pentru 1 pc\n\n";
		cout << " 2. Bautura, Aloe Original 500ml \t\t\t\t"; cout << Test1.get_quantity_drink_aloe_500ml() << " (pc)" << endl;
		cout << "    " << Test1.get_price_drink_aloe_500ml() << " UZS pentru 1 pc\n\n";
		cout << " 3. Nectar, Zet Apple 125ml \t\t\t\t"; cout << Test1.get_quantity_nectar_zet_125ml() << " (pc)" << endl;
		cout << "    " << Test1.get_price_nectar_zet_125ml() << " UZS pentru 1 pc\n\n";
		cout << " 0. Inapoi\n\n";
		cout << " Alegerea ta: ";
		switch (_getch()) {
		case 49: {
			for (int j = 0; j < 1000; j++) {
				system("cls");
				cout << "      Categorie -> Ape & Bauturi \t\t\t Cos \n";
				cout << "____________________________________________________________________________________________________\n";
				cout << "     Apa, Hydrolife fara gaz 750ml \t\t  "; cout << Test1.get_quantity_water_hydrolife_750ml() << " (pc)" << endl;
				cout << "     " << Test1.get_price_water_hydrolife_750ml() << " UZS pentru 1 pc\n\n";

				F_Table_For_Increasing_And_Decreasing();
				switch (_getch()) {
				case 49:
					if (Test1.get_storage_quantity_water_hydrolife_750ml() > 0) { // verificand nevoi depozit si utilizator
						Test1.set_quantity_water_hydrolife_750ml_incrementing();
						cout << " Cantitate a sticlelor (pc): " << Test1.get_quantity_water_hydrolife_750ml() << endl;
						cout << "   Adaugat cu succes \n";
						Sleep(0700); Sleep(0700);
					}
					else {
						cout << " Produsul s-a sfarsit / terminat. Ne pare rau!\n";
						Sleep(0700); Sleep(0700);
					}
					break;
				case 50:
					if (Test1.get_quantity_water_hydrolife_750ml() > 0) { // verif pentru (-1 kg)
						Test1.set_quantity_water_hydrolife_750ml_decrementing();
						cout << " Cantitate a sticlelor (pc): " << Test1.get_quantity_water_hydrolife_750ml() << endl;
						cout << "   Scazut cu succes \n";
						Sleep(0700); Sleep(0700);
					}
					else { cout << " 0 (pc) nu poate scadea \n"; Sleep(0700); Sleep(0700); }
					break;
				case 48:
					j = 1000;
					break;
				}// 'switch' pentru apa
			}// 'for' loop pentru apa
		}
			   break;
			   // case 2 - pentru drink_aloe_500ml
		case 50: {
			for (int j = 0; j < 1000; j++) {
				system("cls");
				// Rustam s-a schimbat
				cout << "      Categorie -> Ape & Bauturi \t\t\t Cos \n";
				cout << "____________________________________________________________________________________________________\n";
				cout << "     Bautura, Aloe Original 500ml \t\t\t  "; cout << Test1.get_quantity_drink_aloe_500ml() << " (pc)" << endl;
				cout << "     " << Test1.get_price_drink_aloe_500ml() << " UZS pentru 1 pc\n\n";
				//
				F_Table_For_Increasing_And_Decreasing();
				switch (_getch()) {
				case 49:
					if (Test1.get_storage_quantity_drink_aloe_500ml() > 0) { // verificand nevoi depozit si utilizator
						Test1.set_quantity_drink_aloe_500ml_incrementing();
						cout << " Cantitate a sticlelor (pc): " << Test1.get_quantity_drink_aloe_500ml() << endl;
						cout << "   Adaugat cu succes \n";
						Sleep(0700); Sleep(0700);
					}
					else {
						cout << " Produsul s-a sfarsit / terminat. Ne pare rau!\n";
						Sleep(0700); Sleep(0700);
					}
					break;
				case 50:
					if (Test1.get_quantity_drink_aloe_500ml() > 0) { // verif pentru (-1 kg)
						Test1.set_quantity_drink_aloe_500ml_decrementing();
						cout << " Cantitate a sticlelor (pc): " << Test1.get_quantity_drink_aloe_500ml() << endl;
						cout << "   Scazut cu succes \n";
						Sleep(0700); Sleep(0700);
					}
					else { cout << " 0 (pc) nu poate scadea \n"; Sleep(0700); Sleep(0700); }
					break;
				case 48:
					j = 1000;
					break;
				}// 'switch' pentru bautura aloe
			}// 'for' loop pentru bautura aloe
		}
			   break;
			   // case 3 - pentru nectar_zet_125ml
		case 51: {
			for (int j = 0; j < 1000; j++) {
				system("cls");
				// Rustam s-a schimbat
				cout << "      Categorie -> Ape & Bauturi \t\t\t Cos \n";
				cout << "____________________________________________________________________________________________________\n";
				cout << "     Nectar, Zet Mere 125ml \t\t\t\t"; cout << Test1.get_quantity_nectar_zet_125ml() << " (pc)" << endl;
				cout << "     " <<Test1.get_price_nectar_zet_125ml() << " UZS pentru 1 pc\n\n";
				//
				F_Table_For_Increasing_And_Decreasing();
				switch (_getch()) {
				case 49:
					//
					if (Test1.get_storage_quantity_nectar_zet_125ml() > 0) { // verificand nevoi depozit si utilizator
						Test1.set_quantity_nectar_zet_125ml_incrementing();
						cout << " Cantitate de Nectar 125ml (pc): " << Test1.get_quantity_nectar_zet_125ml() << endl;
						cout << "   Adaugat cu succes \n";
						Sleep(0700); Sleep(0700);
					}
					else {
						cout << " Produsul s-a sfarsit / terminat. Ne pare rau!\n";
						Sleep(0700); Sleep(0700);
					}
					break;
				case 50:
					if (Test1.get_quantity_nectar_zet_125ml() > 0) { // verif pentru (-1 kg)
						Test1.set_quantity_nectar_zet_125ml_decrementing();
						cout << " Cantitate de nectar 125ml (pc): " << Test1.get_quantity_nectar_zet_125ml() << endl;
						cout << "   Scazut cu succes \n";
						Sleep(0700); Sleep(0700);
					}
					else { cout << " 0 (pc) nu poate scadea \n"; Sleep(0700); Sleep(0700); }
					break;
				case 48:
					j = 1000;
					break;
				}// 'switch' pentru nectar_zet_125ml
			}// 'for' loop pentru nectar_zet_125ml
		}
			   break;
			   // Inapoi la meniul F_User
		case 48: {   k = 1000;
			F_User_Main_Menu(); }
			   break;
		case 56: { // User info   
			system("cls");
			cout << "____________________________________________________________________________________________________ \n";
			cout << "        L U G H I A                                           I N F O  U T I L I Z A T O R       \n";
			cout << "____________________________________________________________________________________________________\n\n";
			cout << "\t\t\t\t    Informatii utilizator:" << endl << endl;
			cout << "\t\t\t\t      Nume utilizator  : " << Name_Memory << endl;
			cout << "\t\t\t\t      Telefon  : " << TellNum_Memory << endl;
			cout << "\t\t\t\t      Logare      : " << Login_Memory << endl;
			cout << "\t\t\t\t      Parola   : " << Parol_Memory << endl << endl << endl;
			system("pause");
		}
			   break;
		default: { cout << "\n\n\t\t\t       Alegerea ta nu este valabila in meniu." << endl;
			cout << "\t\t\t\t    Te rog introdu tastele corecte.\n" << endl;
			system("pause");
		}
		} // switch terminat

	} // loop terminat

} // function terminat

void F_Bread_Bakery_Menu() {
	for (int k = 0; k < 1000; k++) {
		F_Logo();
		cout << "      Categorie -> Paine & Produse patiserie \t\t Cos \n";
		cout << "____________________________________________________________________________________________________\n\n";
		cout << " 1. Chifla Smart Food \t\t\t\t\t"; cout << Test2.get_quantity_bun_smart_food() << " (pc)" << endl;
		cout << "    " << Test2.get_price_bun_smart_food() << " UZS pentru 1 pc\n\n";
		cout << " 2. Cracker Tuc cheese 100g \t\t\t\t"; cout << Test2.get_quantity_cracker_tuc_cheese_100g() << " (pc)" << endl;
		cout << "    " << Test2.get_price_cracker_tuc_cheese_100g() << " UZS pentru 1 pc\n\n";
		cout << " 3. Paine de Salonta \t\t\t\t\t"; cout << Test2.get_quantity_bread_samarkand() << " (pc)" << endl;
		cout << "    " << Test2.get_price_bread_samarkand() << " UZS pentru 1 pc\n\n";
		cout << " 0. Inapoi\n\n";
		cout << " Alegerea ta: ";
		switch (_getch()) {
		case 49: {
			for (int j = 0; j < 1000; j++) {
				system("cls");
				cout << "      Categorie -> Paine & Produse patiserie \t\t Cos \n";
				cout << "____________________________________________________________________________________________________\n";
				cout << "     Chifla Smart Food \t\t\t\t\t"; cout << Test2.get_quantity_bun_smart_food() << " (pc)" << endl;
				cout << "     " << Test2.get_price_bun_smart_food() << " UZS pentru 1 pc\n\n";

				F_Table_For_Increasing_And_Decreasing();
				switch (_getch()) {
				case 49:
					if (Test2.get_storage_quantity_bun_smart_food() > 0) { // verificand nevoi depozit si utilizator
						Test2.set_quantity_bun_smart_food_incrementing();
						cout << " Cantitate Chifla Smart Food (pc): " << Test2.get_quantity_bun_smart_food() << endl;
						cout << "   Adaugat cu succes \n";
						Sleep(0700); Sleep(0700);
					}
					else {
						cout << " Produsul s-a sfarsit / terminat. Ne pare rau!\n";
						Sleep(0700); Sleep(0700);
					}
					break;
				case 50:
					if (Test2.get_quantity_bun_smart_food() > 0) { // verif pentru (-1 pc)
						Test2.set_quantity_bun_smart_food_decrementing();
						cout << " Quantity of Bun Smart Food (pc): " << Test2.get_quantity_bun_smart_food() << endl;
						cout << "   Successfully decreased \n";
						Sleep(0700); Sleep(0700);
					}
					else { cout << " 0 (pc) nu poate scadea \n"; Sleep(0700); Sleep(0700); }
					break;
				case 48:
					j = 1000;
					break;
				}// 'switch' pentru chifla
			}// 'for' loop pentru chifla
		}
			   break;
			   // case 2 - pentru cracker_tuc_cheese_100g
		case 50: {
			for (int j = 0; j < 1000; j++) {
				system("cls");
				// Rustam s-a schimbat
				cout << "      Categorie -> Paine & Produse patiserie \t\t Cos \n";
				cout << "____________________________________________________________________________________________________\n";
				cout << "     Biscuiti Tuc cheese 100g  \t\t\t\t"; cout << Test2.get_quantity_cracker_tuc_cheese_100g() << " (pc)" << endl;
				cout << "     " << Test2.get_price_cracker_tuc_cheese_100g() << " UZS pentru 1 pc\n\n";
				//
				F_Table_For_Increasing_And_Decreasing();
				switch (_getch()) {
				case 49:
					
					if (Test2.get_storage_quantity_cracker_tuc_cheese_100g() > 0) { // verificand nevoi depozit si utilizator
						Test2.set_quantity_cracker_tuc_cheese_100g_incrementing();
						cout << " Cantitate biscuiti Tuc Cheese 100g (pc): " << Test2.get_quantity_cracker_tuc_cheese_100g() << endl;
						cout << "   adaugat cu succes \n";
						Sleep(0700); Sleep(0700);
						
					}
					else {
						cout << " Produsul s-a sfarsit / terminat. Ne pare rau!\n";
						Sleep(0700); Sleep(0700);
					}
					break;
				case 50:
					if (Test2.get_quantity_cracker_tuc_cheese_100g() > 0) { // verifica pentru (-1 pc)
						Test2.set_quantity_cracker_tuc_cheese_100g_decrementing();
						cout << " Cantitate biscuiti Tuc Cheese 100g (pc): " << Test2.get_quantity_cracker_tuc_cheese_100g() << endl;
						cout << "   scazut cu succes \n";
						Sleep(0700); Sleep(0700);
					}
					else { cout << " 0 (pc) nu poate scadea \n"; Sleep(0700); Sleep(0700); }
					break;
				case 48:
					j = 1000;
					break;
				}// 'switch' pentru cracker_tuc_cheese_100g
			}// 'for' loop pentru cracker_tuc_cheese_100g
		}
			   break;
			   // case 3 - pentru paine Salonta
		case 51: {
			for (int j = 0; j < 1000; j++) {
				system("cls");
				// Rustam s-a schimbat
				cout << "      Categorie -> Paine & Produse patiserie \t\t Cos \n";
				cout << "____________________________________________________________________________________________________\n";
				cout << "     Paine de Salonta \t\t\t\t  "; cout << Test2.get_quantity_bread_samarkand() << " (pc)" << endl;
				cout << "     " << Test2.get_price_bread_samarkand() << " UZS pentru 1 pc\n\n";
				
				F_Table_For_Increasing_And_Decreasing();
				switch (_getch()) {
				case 49:
					if (Test2.get_storage_quantity_bread_samarkand() > 0) { // verificand pentru depozit si nevoi user
						Test2.set_quantity_bread_samarkand_incrementing();
						cout << " Cantitate paine de Salonta (pc): " << Test2.get_quantity_bread_samarkand() << endl;
						cout << "   Adaugat cu succes \n";
						Sleep(0700); Sleep(0700);
					}
					else {
						cout << " Produsul s-a sfarsit / terminat. Ne pare rau!\n";
						Sleep(0700); Sleep(0700);
					}
					break;
				case 50:
					if (Test2.get_quantity_bread_samarkand() > 0) { // verifica pentru (-1 pc)
						Test2.set_quantity_bread_samarkand_decrementing();
						cout << " Cantitate paine de Salonta (pc): " << Test2.get_quantity_bread_samarkand() << endl;
						cout << "   Scazut cu succes \n";
						Sleep(0700); Sleep(0700);
					}
					else { cout << " 0 (pc) nu poate scadea \n"; Sleep(0700); Sleep(0700); }
					break;
				case 48:
					j = 1000;
					break;
				}// 'switch' pentru paine Salonta
			}// 'for' loop pentru paine Salonta
		}
			   break;
			   // inapoi la meniul F_User
		case 48: {   k = 1000;
			F_User_Main_Menu(); }
			   break;
		case 56: { // User info   
			system("cls");
			cout << "____________________________________________________________________________________________________ \n";
			cout << "        L U G H I A                                                   U S E R  I N F O         \n";
			cout << "____________________________________________________________________________________________________\n\n";
			cout << "\t\t\t\t    Informatie utilizator:" << endl << endl;
			cout << "\t\t\t\t      Nume utilizator  : " << Name_Memory << endl;
			cout << "\t\t\t\t      Telefon  : " << TellNum_Memory << endl;
			cout << "\t\t\t\t      Login      : " << Login_Memory << endl;
			cout << "\t\t\t\t      Parola   : " << Parol_Memory << endl << endl << endl;
			system("pause");
		}
			break;
			default: { cout << "\n\n\t\t\t       Alegerea ta nu este valabila in meniu." << endl;
			cout << "\t\t\t\t    Te rog introdu tastele corecte.\n" << endl;
			system("pause");
		}
		} // switch terminat

	} // bucla terminata

} // functie terminata

// functie cart
void F_Cart_Check() {
	system("cls");
	cout << "____________________________________________________________________________________________________ \n";
	cout << "                                              C A R T \n";
	cout << "____________________________________________________________________________________________________\n\n";
	// verifica
	for (int i = 1; i <= 1; i++) {
		if (Test.get_quantity_potatoes() > 0) {
			cout << "\n\t  " << i << "." << "Cartofi, greutate    " << Test.get_quantity_potatoes() << " (kg)     Pret: " << Test.get_quantity_potatoes() * Test.get_price_potatoes();
			i++;
			Overall_Sum += Test.get_quantity_potatoes() * Test.get_price_potatoes();
		}
		if (Test.get_quantity_carrot() > 0) {
			cout << "\n\t  " << i << "." << "Morcov, greutate      " << Test.get_quantity_carrot() << " (kg)     Pret: " << Test.get_quantity_carrot() * Test.get_price_carrot();
			i++;
			Overall_Sum += Test.get_quantity_carrot() * Test.get_price_carrot();
		}
		if (Test.get_quantity_onion() > 0) {
			cout << "\n\t  " << i << "." << "Ceapa, greutate       " << Test.get_quantity_onion() << " (kg)     Pret: " << Test.get_quantity_onion() * Test.get_price_onion();
			i++;
			Overall_Sum += Test.get_quantity_onion() * Test.get_price_onion();
		}
		if (Test1.get_quantity_drink_aloe_500ml() > 0) {
			cout << "\n\t  " << i << "." << "Aloe 500ml          " << Test1.get_quantity_drink_aloe_500ml() << " (pc)     Pret: " << Test1.get_quantity_drink_aloe_500ml() * Test1.get_price_drink_aloe_500ml();
			i++;
			Overall_Sum += Test1.get_quantity_drink_aloe_500ml() * Test1.get_price_drink_aloe_500ml();
		}
		if (Test1.get_quantity_nectar_zet_125ml() > 0) {
			cout << "\n\t  " << i << "." << "Nectar Zet 125ml    " << Test1.get_quantity_nectar_zet_125ml() << " (pc)     Pret: " << Test1.get_quantity_nectar_zet_125ml() * Test1.get_price_nectar_zet_125ml();
			i++;
			Overall_Sum += Test1.get_quantity_nectar_zet_125ml() * Test1.get_price_nectar_zet_125ml();
		}
		if (Test1.get_quantity_water_hydrolife_750ml() > 0) {
			cout << "\n\t  " << i << "." << "Hydrolife 750ml     " << Test1.get_quantity_water_hydrolife_750ml() << " (pc)     Pret: " << Test1.get_quantity_water_hydrolife_750ml() * Test1.get_price_water_hydrolife_750ml();
			i++;
			Overall_Sum += Test1.get_quantity_water_hydrolife_750ml() * Test1.get_price_water_hydrolife_750ml();
		}
		if (Test2.get_quantity_bread_samarkand() > 0) {
			cout << "\n\t  " << i << "." << "Salonta Paine ,   " << Test2.get_quantity_bread_samarkand() << " (pc)     Pret: " << Test2.get_quantity_bread_samarkand() * Test2.get_price_bread_samarkand();
			i++;
			Overall_Sum += Test2.get_quantity_bread_samarkand() * Test2.get_price_bread_samarkand();
		}
		if (Test2.get_quantity_bun_smart_food() > 0) {
			cout << "\n\t  " << i << "." << "Chifla Smart Food ,    " << Test2.get_quantity_bun_smart_food() << " (pc)     Pret: " << Test2.get_quantity_bun_smart_food() * Test2.get_price_bun_smart_food();
			i++;
			Overall_Sum += Test2.get_quantity_bun_smart_food() * Test2.get_price_bun_smart_food();
		}
		if (Test2.get_quantity_cracker_tuc_cheese_100g() > 0) {
			cout << "\n\t  " << i << "." << "Tuc Cheese 100g ,   " << Test2.get_quantity_cracker_tuc_cheese_100g() << " (pc)     Pret: " << Test2.get_quantity_cracker_tuc_cheese_100g() * Test2.get_price_cracker_tuc_cheese_100g();
			i++;
			Overall_Sum += Test2.get_quantity_cracker_tuc_cheese_100g() * Test2.get_price_cracker_tuc_cheese_100g();
		}

		if (i == 1) { // Daca nimic nu merge catre meniu
			cout << "\n\t Nu ai niciun produs in carucior.\n";
			cout << "\tIntrodu orice tasta, mergi inapoi la meniu\n\n" << endl;
			system("pause");
			Overall_Sum = 0;
			F_User_Main_Menu();
		}
		if (i > 1) { // Meniu pentru cumparat sau back
			cout << "\n\n\t\t Pretul total: " << Overall_Sum << " Sum" << endl;
			cout << "\n 1. Cumpara-l acum" << endl;
			cout << " 0. Mergi inapoi la meniu" << endl;

			switch (_getch()) {
			case 49: { //buy
				system("cls");
				////
				// trebuie sa adaugam
				////
				cout << "Functioneaza !" << endl;
				system("pause");
			}
				break;
			case 48: { // Back
				system("cls");
				Overall_Sum = 0;
				F_User_Main_Menu();
			}
				break;
			default: F_Cart_Check();
			} // switch terminat

		} //if terminat

	}// loop terminat
	//system("pause");
} // functie terminat