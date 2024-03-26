#include <iostream>
#include <conio.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

static int p = 0;

class a

{

  char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];

public:

  void install();
  void allotment();
  void empty();
  void show();
  void avail();
  void position(int i);

}

  bus[10];
void vline(char ch)

{

  for (int i=80;i>0;i--)
  cout<<ch;

}

void a::install()

{

    cout<<"Introdu numarul autobuzului: ";
    cin>>bus[p].busn;
    cout<<"\nIntrodu numele soferului: ";
    cin>>bus[p].driver;
    cout<<"\nTimpul sosire: ";
    cin>>bus[p].arrival;
    cout<<"\nPlecare: ";
    cin>>bus[p].depart;
    cout<<"\nDin: \t\t\t";
    cin>>bus[p].from;
    cout<<"\nCatre: \t\t\t";
    cin>>bus[p].to;
    bus[p].empty();
    p++;

}

void a::allotment()

{

  int seat;
  char number[5];

  top:
  cout<<"Autobuzul cu numarul: ";
  cin>>number;
  int n;
  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busn, number)==0)

    break;

  }

  while(n<=p)

  {

    cout<<"\nNumarul locului: ";
    cin>>seat;
  if(seat>32)

    {

    cout<<"\nSunt numai 32 de scaune valabile in acest autobuz.";

    }

    else

    {

    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Gol")==0)

      {

      cout<<"Introdu numele pasagerului: ";
      cin>>bus[n].seat[seat/4][(seat%4)-1];

        break;

      }

      else

        cout<<"Scaunul cu nr. este deja rezervat.\n";

      }

      }

    if(n>p)

    {

      cout<<"Introdu autobuzul corect.\n";

      goto top;

    }

  }


void a::empty()

{

  for(int i=0; i<8;i++)

  {

    for(int j=0;j<4;j++)

    {

    strcpy(bus[p].seat[i][j], "Gol");

    }

  }

}

void a::show()

{

  int n;
  char number[5];

    cout<<"Introdu numarul autobuzului: ";
    cin>>number;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busn, number)==0)

    break;

  }

  while(n<=p)

{

    vline('*');
    cout<<"Autobuz numarul: \t"<<bus[n].busn
    <<"\nSofer: \t"<<bus[n].driver<<"\t\tTimp sosire: \t"
    <<bus[n].arrival<<"\tTimp plecare:"<<bus[n].depart
    <<"\nDe la: \t\t"<<bus[n].from<<"\t\tCatre: \t\t"<< bus[n].to<<"\n";
    vline('*');
    bus[0].position(n);
  int a=1;
    for (int i=0; i<8; i++)

    {

    for(int j=0;j<4;j++)

    {

    a++;
      if(strcmp(bus[n].seat[i][j],"Gol")!=0)
        cout<<"\nScaunul numarul "<<(a-1)<<" este rezervat pentru "<<bus[n].seat[i][j]<<".";

    }

  }

  break;

  }

  if(n>p)
    cout<<"Introdu numarul autobuzului corect: ";

}

void a::position(int l)

{

  int s=0;p=0;
  for (int i =0; i<8;i++)

  {

    cout<<"\n";
    for (int j = 0;j<4; j++)

    {

      s++;
      if(strcmp(bus[l].seat[i][j], "Gol")==0)

        {

        cout.width(5);
        cout.fill(' ');
        cout<<s<<".";
        cout.width(10);
        cout.fill(' ');
        cout<<bus[l].seat[i][j];
        p++;

        }

        else

        {

        cout.width(5);
        cout.fill(' ');
        cout<<s<<".";
        cout.width(10);
        cout.fill(' ');
        cout<<bus[l].seat[i][j];

        }

      }

    }

  cout<<"\n\nAcolo sunt "<<p<<" locuri libere in autobuzul numarului: "<<bus[l].busn;

  }

void a::avail()

{


  for(int n=0;n<p;n++)

  {

    vline('*');
    cout<<"Autobuzul numarul: \t"<<bus[n].busn<<"\nSofer: \t"<<bus[n].driver
    <<"\t\tTimp sosire: \t"<<bus[n].arrival<<"\tTimp plecare: \t"
    <<bus[n].depart<<"\nDe la: \t\t"<<bus[n].from<<"\t\tCatre: \t\t\t"
    <<bus[n].to<<"\n";
    vline('*');
    vline('_');

  }

}

int main()

{

system("cls");

  int w;
  while(1)

{

    //system("cls");

    cout<<"\n\n\n\n\n";
    cout<<"\t\t1. Instaleaza\n\t\t"
    <<"2. Rezervare\n\t\t"
    <<"3. Arata\n\t\t"
    <<"4. Autobuzuri valabile. \n\t\t"
    <<"5. Iesire"<<endl;
    cout<<"\n\t\tIntrodu alegerea ta: -> ";

    cin>>w;

  switch(w)

  {

    case 1:  bus[p].install();

      break;

    case 2:  bus[p].allotment();

      break;

    case 3:  bus[0].show();

      break;

    case 4:  bus[0].avail();

      break;

    case 5:  exit(0);

  }

}

return 0;

}
