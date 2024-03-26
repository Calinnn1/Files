#include<iostream>
#include<cstring>
#include<conio.h>

#define max 100
using std::cout;
using std::cin;

//Clasa client
	class Customer
{
public:
	char name[100];
	char address[100];
	char phone[12];
	char from_date[20];
	char to_date[20];
	float payment_advance;
	int booking_id;
};


class Room
{
public:
	char type;
	char stype;
	char ac;
	int roomNumber;
	int rent;
	int status;

class Customer cust;
class Room addRoom(int);
void searchRoom(int);
void deleteRoom(int);
void displayRoom(Room);
};

//Declaratii Globale
class Room rooms[max];

	int coount=0;


Room Room::addRoom(int rno)
{
class Room room;
	room.roomNumber=rno;
	cout<<"\nTip AC/Non-AC (A/N) : ";
	cin>>room.ac;
	cout<<"\nTip Comfort (S/N) : ";
	cin>>room.type;
	cout<<"\nTip marime (B/S) : ";
	cin>>room.stype;
	cout<<"\nInchiriere : ";
	cin>>room.rent;
	room.status=0;

	cout<<"\n Camera Adaugata cu Succes!";
getch();
	return room;
}


void Room::searchRoom(int rno)
{
	
	int i,found=0;
	for(i=0;i<coount;i++)
{
	if(rooms[i].roomNumber==rno)
{
		found=1;
	break;
}
}
	if(found==1)
{
		cout<<"Detalii Camera\n";
	if(rooms[i].status==1)
{
		cout<<"\nCamera este rezervata";
}
	else
{
		cout<<"\nCamera este valabila";
}
displayRoom(rooms[i]);
getch();
}
	else
{
cout<<"\nCamera negasita";
getch();
}
}

void Room::displayRoom(Room tempRoom)
{
	cout<<"\nNumar Camera: \t"<<tempRoom.roomNumber;
	cout<<"\nTip AC/NON-AC (A/N) "<<tempRoom.ac;
	cout<<"\nTip Confort (S/N) "<<tempRoom.type;
	cout<<"\nTip Marime (B/S) "<<tempRoom.stype;
	cout<<"\nInchiriere: "<<tempRoom.rent;
}

//clasa hotel management 
class HotelMgnt:protected Room
{
	
public:
void checkIn();
void getAvailRoom();
void searchCustomer(char *);
void checkOut(int);
void guestSummaryReport();
};


void HotelMgnt::guestSummaryReport(){

	if(coount==0){
		cout<<"\n Niciun oaspete in hotel!";
}	
	for(int i=0;i<coount;i++)
{
	if(rooms[i].status==1)
{
	cout<<"\n Prenumele Clientului : "<<rooms[i].cust.name;
	cout<<"\n Numarul Camerei: "<<rooms[i].roomNumber;
	cout<<"\n Adresa(numai orasul): "<<rooms[i].cust.address;
	cout<<"\n Telefon: "<<rooms[i].cust.phone;
	cout<<"\n---------------------------------------";	
}
	
}

getch();
}

//managementul hotelului reservatie pentu camera
void HotelMgnt::checkIn()
{
	
	int i,found=0,rno;

class Room room;
	cout<<"\nIntrodu numar camera: ";
	cin>>rno;
	for(i=0;i<coount;i++)
{
	if(rooms[i].roomNumber==rno)
{
	found=1;
	break;
}
}
	if(found==1)
{
	if(rooms[i].status==1)
{
		cout<<"\nCamera este deja rezervata";
getch();
return;
}

	cout<<"\nIntroduceti codul rezervarii: ";
	cin>>rooms[i].cust.booking_id;

	cout<<"\nIntroduceti numele clientului(Nume Fam): ";
	cin>>rooms[i].cust.name;

	cout<<"\nIntrodu Adresa(numai orasul): ";
	cin>>rooms[i].cust.address;

	cout<<"\nIntrodu telefon: ";
	cin>>rooms[i].cust.phone;

	cout<<"\nIntrodu data de la: ";
	cin>>rooms[i].cust.from_date;

	cout<<"\nintrodu data catre: ";
	cin>>rooms[i].cust.to_date;

	cout<<"\nIntrodu plata in avans: ";
	cin>>rooms[i].cust.payment_advance;

	rooms[i].status=1;

	cout<<"\n Clientul s-a inregistrat cu succes...";
getch();
}
}


//hotel management shows available rooms
void HotelMgnt::getAvailRoom()
{
	int i,found=0;
	for(i=0;i<coount;i++)
{
	if(rooms[i].status==0)
{
displayRoom(rooms[i]);
	cout<<"\n\nApasa enter pentru urmatoarea camera";
	found=1;
getch();
}
}
	if(found==0)
{
	cout<<"\nToate camerele sunt rezervate";
getch();
}
}


//managementul hotelului arata toate persoanele care au rezervat camera
void HotelMgnt::searchCustomer(char *pname)
{
	int i,found=0;
	for(i=0;i<coount;i++)
{
	if(rooms[i].status==1 && strcmp(rooms[i].cust.name,pname)==0)
{
	cout<<"\nNume client: "<<rooms[i].cust.name;
	cout<<"\nCamera numar: "<<rooms[i].roomNumber;

	cout<<"\n\nApasa enter pentru urmatoarea inregistrare";
	found=1;
getch();
}
}
	if(found==0)
{
	cout<<"\nPersoana negasita.";
getch();
}
}


//managemtul hotelului genereaza factura pentru cheltuieli
void HotelMgnt::checkOut(int roomNum)
{
	int i,found=0,days,rno;
	float billAmount=0;
	for(i=0;i<coount;i++)
{
	if(rooms[i].status==1 && rooms[i].roomNumber==roomNum)
{
//rno = rooms[i].roomNumber;
	found=1;
//getch();
	break;
}
}
	if(found==1)
{
	cout<<"\nIntrodu numarul de zile:\t";
	cin>>days;
	billAmount=days * rooms[i].rent;

	cout<<"\n\t######## Detalii Verificare ########\n";
	cout<<"\nNume Client: "<<rooms[i].cust.name;
	cout<<"\nNumar Camera: "<<rooms[i].roomNumber;
	cout<<"\nAddress : "<<rooms[i].cust.address;
	cout<<"\nTelefon: "<<rooms[i].cust.phone;
	cout<<"\nSuma Totala Datorara: "<<billAmount<<" /";
	cout<<"\nPlatit in Avans: "<<rooms[i].cust.payment_advance<<" /";
	cout<<"\n*** Total Platibil: "<<billAmount-rooms[i].cust.payment_advance<<"/ numai";

	rooms[i].status=0;
}
getch();
}


//managing rooms (adding and searching available rooms)
void manageRooms()
{
class Room room;
	int opt,rno,i,flag=0;
	char ch;
do
{
system("cls");
cout<<"\n### Gestionare Camere ###";
cout<<"\n1. Adauga Camera";
cout<<"\n2. Cauta Camera";
cout<<"\n3. Inapoi la Meniul Principal";
cout<<"\n\nIntrodu Optiune: ";
cin>>opt;


//switch statement
	switch(opt)
{
	case 1:
		cout<<"\nIntrodu Numar Camera: ";
		cin>>rno;
		i=0;

	for(i=0;i<coount;i++)
{
	if(rooms[i].roomNumber==rno)
{
		flag=1;
}
}
	if(flag==1)
{
		cout<<"\nNumarul camerei este prezent.\nTe rog introdu numar unic";
		flag=0;
getch();
}
	else
{
	
	rooms[coount]=room.addRoom(rno);
	coount++;
}
	break;
	case 2:
		cout<<"\nIntra in camera numarul: ";
		cin>>rno;
		room.searchRoom(rno);
	break;
	case 3:
//nothing to do
	break;
	default:
		cout<<"\nTe rog introdu optiunea corecta";
	break;
}
}	while(opt!=3);
}
using namespace std;
int main()
{
class HotelMgnt hm;
	int i,j,opt,rno;
	char ch;
	char pname[100];

system("cls");

do
{
system("cls");
cout<<"######## Gestionare Hotel #########\n";
cout<<"\n1. Gestionare Camere";
cout<<"\n2. Camera Check-In";
cout<<"\n3. Camere Valabile";
cout<<"\n4. Cauta Client";
cout<<"\n5. Camera Check-Out";
cout<<"\n6. Raport Rezumat Client";
cout<<"\n7. Iesire";
cout<<"\n\nIntrodu optiunea: ";
cin>>opt;
	switch(opt)
{
	
	case 1:
manageRooms();
	break;
	case 2:
	if(coount==0)
{
		cout<<"\nDatele camerei nu sunt disponibile.\nTe rog adauga camere prima data.";
getch();
}
	else
hm.checkIn();
	break;
	case 3:
	if(coount==0)
{
		cout<<"\nDatele camerei nu sunt disponibile.\nTe rog adauga camere prima data.";
getch();
}
	else
hm.getAvailRoom();
	break;
	case 4:
		if(coount==0)
{
		cout<<"\nNu sunt camere disponibile\nTe rog adauga camere prima data.";
getch();
}
	else
{
		cout<<"Introdu nume client: ";
		cin>>pname;
hm.searchCustomer(pname);
}
	break;
	case 5:
	if(coount==0)
{
	cout<<"\nDatele camerei nu sunt disponibile.\nTe rog adauga camere prima data.";
getch();
}
	else
{
		cout<<"Introdu numar camera: ";
		cin>>rno;
hm.checkOut(rno);
}
	break;
	case 6:
hm.guestSummaryReport();	
	break;
	case 7:
		cout<<"\nMULTUMIM!";
	break;
	default:
		cout<<"\nTe rog introdu optiunea corecta";
	break;
}
}	while(opt!=7);

getch();
}