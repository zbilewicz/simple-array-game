#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
Program, ktory generuje plansze do gry - gracz jest kolkiem i trzeba dojsc do krzyzyka
rozmiary planszy mozna zmienic bo sa poza mainem
najpierw tworzona jest tablica za pomoca wskaznikow potem wypelniana #
potem generowane jest polozenie x ktore nie moze byc tam gdzie o i wstawiane do tablicy
mozna poruszac sie piszac komendy prawo lewo gora dol
poruszanie sie jest zawsze o 1 i jezeli wychodzi za granice to jest wiadomosc
funkcja move bierze polozenie pionka zwiekszone o 1 i drukuje ta tablice z zamienionym polozeniem
jak sie wpisze end to mozna skonczyc program
na koncu tablica usuwana "warstwowo" by nie zajmowac pamieci
*/


int sizex = 5;
int sizey = 5;


void move(char** array,int x,int y)
{
	if (x<0 || x>sizey || y>=sizey || y<0)
	{
		cout<<"Poza granicami"<<endl;
		return;
	}
	for (int i=0;i<sizey;i++)
	{
		for (int j=0;j<sizex;j++)
		{
			if (j==x & i==y){
				cout<<'o'<<' ';
			}
			else cout<<array[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<endl;
}

int randnum(int offset, int range)
{
	
	int random = offset + (rand() % range);

	return random;
}



int main(){
	srand((unsigned) time(NULL));
	
	
	
	int kulkax=0;
	int kulkay=sizey-1;
	
	int goalx,goaly;
	
	// y is the rows x is the column
	
	
	
	char** twod=new char*[sizey];
	
	for (int i=0;i<sizey;i++)
	{
		twod[i] = new char[sizex];
	}
	
	for (int i=0;i<sizey;i++)
	{
		for (int j=0;j<sizex;j++)
		{
			twod[i][j]='#';
		}
	}
	goaly=randnum(0,sizey);
	goalx=randnum(0,sizex);
	//cout<<goalx<<endl<<goaly<<endl;
	
	if (goalx ==0 & goaly==2)
	{
		goalx++;	
	}
	
	twod[goaly][goalx]='X';

	//goalx is the column
	//goaly is the row
	
	cout<<"Plansza startowa:";
	cout<<endl;
	move(twod,kulkax,kulkay);
		
	string ruch;
	do 
	{
	if(kulkax==goalx & kulkay==goaly)
	{
		cout<<"gratuluje"<<endl<<"twoja nagroda: $$$$$$$$$$$"<<endl;
		break;
	}
	cout<<"ruch w prawo, lewo, gora czy dol? (napisz end jezeli chcesz zakonczyc program): "<<endl;	
	cin>>ruch;
	if (ruch=="prawo")
	{
		kulkax+=1;
		move(twod,kulkax,kulkay);
		
	}
	else if(ruch=="lewo")
	{
		kulkax-=1;
		move(twod,kulkax,kulkay);
	}
	else if(ruch=="gora")
	{
		kulkay-=1;
		move(twod,kulkax,kulkay);
	}
	else if(ruch=="dol")
	{
		kulkay+=1;
		move(twod,kulkax,kulkay);
	}
	else if(ruch=="end")
	{
		break;
	}
	else cout<<"naucz sie pisac"<<endl;
	
	}while(ruch!="end");
	
		
	for (int i=0;i<sizey;i++)
	{
		delete[] twod[i];
	}
	delete [] twod;
	
	return 1;
}
