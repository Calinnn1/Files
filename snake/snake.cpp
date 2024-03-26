#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    void welcome();
    void instructions();
    void record();
    void incorrectChoice();
    void lostgame();
    void win();

                    // setari initiale
    bool game = false;
    const int width = 50;
    const int height = 20;
                    // variabilele pentru pozitionarea sarpelui, fructului si scorul
    int x, y, fx, fy, score;
                    // arrayul cozii
    int tx[100], ty[100];
    int nt;

    enum Direction{STOP = 0, LEFT, RIGHT, UP, DOWN};

    Direction dir;
                    // valori initiale cand incepe jocul
void Init()
{
    game = true;
    dir = STOP;
    x=width / 2;
    y=height / 2;
    fx =rand() % width;
    fy =rand() % height;
    score = 0;
    tx[100]= {};
    ty[100]= {};
}
                    //harta ce contine fructul unde apare sarpele
void Map()
{
    system("cls");
    SetConsoleTextAttribute(hConsole, 180);
    for(int i= 0; i < width + 2; i++)
        cout<< "#";
        cout<<endl;
    for(int i=0;i< height; i++)
{
    for(int j=0;j< width; j++)
    {
        if(j==0)
            cout<< "#";
        if(i==y && j==x)
            cout<< "O";
        else if(i==fy && j==fx)
            cout<<"X";
        else
        {
            bool print = false;
            for(int k=0;k < nt; k++)
            {
                if(tx[k]==j && ty[k]==i)
                {
                    cout<<"o";
                    print=true;
                }
            }
            if(!print)
                cout<<" ";
        }
        if(j== width - 1)
            cout<<"#";
    }
        cout<< endl;
    
}
    for(int i=0; i< width +2; i++)
        cout<<"#";
        cout<< endl;
        cout<< "Scorul este "<< score<<endl;
}   
                    // controalele puse de la tastatura pentru a controla sarpele
void Input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
            case 'a':
            dir = LEFT;
            break;
            case 'd':
            dir = RIGHT;
            break;
            case 'w':
            dir = UP;
            break;
            case 's':
            dir = DOWN;
            break;
            case 'x':
            game = false;
            break;
            case 'r':
            dir = STOP;
            welcome();
            default:
            break;
        }
    }
}
                    // Logica cresterii sarpelui si cand se opreste jocul
void Logic()
{
    int prevx = tx[0];
    int prevy = ty[0];
    int prev2x, prev2y;
        tx[0] = x;
        ty[0] = y;
    for(int i=1; i< nt; i++)
{
        prev2x = tx[i];
        prev2y = ty[i];
        tx[i] = prevx;
        ty[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
}
    switch(dir)
{
    case UP:
    y--;
    break;
    case DOWN:
    y++;
    break;
    case LEFT:
    x--;
    break;
    case RIGHT:
    x++;
    break;

    default:
    break;
}
    if(x >= width) x= 0; else if(x < 0) x = width -1;
    if(y >= height) y= 0; else if(y < 0) y = height -1;

    for(int i = 0; i < nt; i++)
{
        if(tx[i] == x && ty[i] == y)
    {
        lostgame();
    }
}
        if(x== fx && y == fy)
    {
            score += 1;
            nt++;
            fx = rand() % width;
            fy = rand() % height;
    }
}
                    // conditia cand un jucator castiga
void win()
{
    if(score == 100)
    {
        system("cls");
        cout<<endl <<endl <<endl <<endl <<endl;
        cout<< "                         ";
        cout<<"Felicitari! Ai castigat jocul!"<< endl;
        cout<< endl;
        cout<< "                         ";
        cout<<"Pentru a merge inapoi apasa orice tasta"<< endl;
        char back;
        cin>> back;
        if(back)
        {
            welcome();
            game = false;
        }
    }
}
                    //inceputul jocului
void startGame()
{
    Init();
    while(game)
    {
        Map();
        Input();
        Logic();
        win();
        Sleep(10);
    }
}

void welcome()
{
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<< "                        ";
    cout<<"Bun venit in jocul Snake!"<< endl;
    cout<< "                        "<< "1. Daca doresti sa incepi jocul apasa 1"<< endl;
    cout<< "                        "<< "2. Pentru a vedea instructiuni apasa 2"<<endl;
    cout<< "                        "<< "3. Pentru a vedea recordul apasa 3"<<endl;

    char choice;
        cin>> choice;
    switch(choice)
{
    case '1':
    system("cls");
    startGame();
    case '2':
    instructions();
    case '3':
    record();
    default:
        incorrectChoice();
    }
}

void instructions()
{
    system("cls");
    cout<< endl << endl<< endl << endl<< endl << endl<< endl;
    cout<<"                               ";
    cout<<"Bun venit in jocul snake!"<<endl;
    cout<< endl;
    cout<<"                             "<<"Aici sunt instructiunile"<<endl;
    cout<<"                             "<<"1. Daca intreci recordul curent castigi jocul"<< endl;
    cout<< endl;
    cout<<"                             "<<"2. Cand cresti in lungime nu te poti atinge, "<< endl<<"                             "<<"daca te atingi vei pierde jocul"<< endl; 
    cout<< endl;
    cout<<"                             "<<"3. Cand cresti in lungime nu te poti atinge, "<< endl<<"                          "<<"daca mergi cu spatele cand ai adunat puncte"<< endl<<"                       "<< "automat pierzi jocul"<< endl;
    cout<<endl;
    char back;
        cout<<"                             "<<"Pentru a merge inapoi apasa orice tasta"<<endl;
        cin >> back;
    if(back) welcome();
}

void record()
{
    system("cls");
    cout<< endl<<endl<< endl<<endl<< endl<<endl<<endl;
    cout<<"                             ";
    cout<<"Bun venit in jocul Snake!"<<endl;
    cout<<endl;
    cout<<"                             "<<"Recordul curent este 100"<< endl;
    cout<< endl;
    cout<<"                             "<<"Daca treci de 100 vei castiga jocul"<< endl;

    char back;
        cout<< endl;
        cout<<"                             "<<"Pentru a merge inapoi apasa orice tasta"<< endl;
        cin>> back;
    if(back) welcome();
}

void incorrectChoice()
{
    cout<<"Incearca din nou"<<endl;
    cout<< endl;
    
    char back;
        cout<<"Pentru a merge inapoi apasa orice tasta"<< endl;
        cin>> back;
    if(back) welcome();
}

void lostgame()
{
    game = false;
    system("cls");
    cout<< endl<< endl<< endl<< endl<< endl<< endl<< endl;
    cout<< "                        ";
    cout<<"Imi pare rau dar ai pierdut jocul"<< endl;
    cout<< "                        "<<"Scorul tau a fost "<< score<< endl;
    cout<< "                        ";
    cout<<"Pentru a merge inapoi apasa orice tasta"<< endl;

    char back;
        cin>> back;
    if(back)
    {
        game = false;
        welcome();
    }
}

int main(){

    SetConsoleTextAttribute(hConsole, 116);
    welcome();
    return 0;
}



