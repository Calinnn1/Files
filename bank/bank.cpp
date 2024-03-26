#include<stdio.h>
#include<conio.h>
#include<iostream>

 using namespace std;

class bank
{
    private:
    char name[100];
    char add[100];
    char y;
    int balance;
    public:
void open_account();
void deposit_money();
void withdraw_money();
void display_account();

};
void bank::open_account()
{
    cout <<"introduceti numele intreg :: ";
    cin.ignore();
    cin.getline(name, 100);
    cout<<"introduceti adresa ::";
    cin.ignore();
    cin.getline(add, 100);
    cout<<"ce tip de cont doresti sa deschizi? Salvari (s) sau curent (c) ? ::";
    cin>>y;
    cout<< "introdu suma pentru depozit ::";
    cin>> balance;
    cout<< "\n contul tau este creat\n";
}

void bank::display_account()
{
    cout <<"\n    numele intreg :: \t\t"<< name<<endl;
    cout <<"    adresa dumneavoastra :: \t" <<add<<endl;
    cout <<"    tipul de cont deschis :: \t" << y<<endl;
    cout <<"    suma depusa :: \t\t" << balance<<endl;
}
void bank::deposit_money()
{
    char q;
    int a;
        cout <<"introdu cat depozitezi :: ";
        cin >>a;
        balance+=a;
        cout <<"suma totala depozitata :: \t "<< balance;
}

void bank::withdraw_money()
{
    float amount, b;
        cout <<" \n retrage :: ";
        cout <<"introdu suma de retragere ::";
        cin >> amount;
        balance -= amount;
        cout <<"suma totala ramasa :: "<< balance;
}


int main()
{
    int ch;
    bank obj;
    char n,x;
    do
    {
        cout << "\n       1) Deschidere cont \n";
        cout << "       2) Depozit bancar \n";
        cout << "       3) Retragere bani \n";
        cout << "       4) Despre cont \n";
        cout << "       5) Iesire \n"<<endl;
        cout <<"    Selecteaza optiunile de deasupra\n";
        cin >> ch;
    system("cls");
    switch(ch)
{
        case 1:
        cout<< "1) Deschidere cont \n";
        obj.open_account();
        break;

        case 2:
        cout<< "2) Depozit bancar \n";
        obj.deposit_money();
        break;

        case 3:
        cout<< "3) Retragere bani \n";
        obj.withdraw_money();
        break;

        case 4:
        cout<< "4) Despre cont \n";
        obj.display_account();
        break;

        case 5:
        if(ch==5)
    {
        exit(1);
    }
        default:

        cout<<" aceasta nu este iesirea, incercati din nou \n";
}
        cout <<"\n intoarcere catre meniu. Apasa :: y \n";
        cout << "    doresti sa iesi? Apasa :: n";
        x=getch();
    if(x=='n' || x=='N')
    exit(0);

}   
    while (x=='y'|| x=='Y');

   getch();
    return 0;

}





