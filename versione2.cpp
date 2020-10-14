// Gruppo 1 - Esercizio di gruppo - Versione 2 
// Create una copia della prima versione, sostituendo il giocatore2 
// con una mossa generata automaticamente dal programma stesso (tramite rand).

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX=3; //Numero Massimo per il rand

int main(){
	
	//Dichiaro il seme per il random
	int seed = time(NULL); //Time(NULL) serve a prendere il momento attuale per randomizzare
	//Dichiaro le due giocate
	char g1,g2;
	//Dichiaro la variabile vincitore (0=Giocatore 1, 1=Giocatore 2, 2=Pareggio)
	int vincitore;
	
	cout << "Per inserire una giocata,'c'=carta, 's'=sasso, 'f'= forbici" << endl;
	
	//Continua a chiedere fino a quando l'input non è valido
	do{
		cout << "Inserisci la tua giocata:" << endl;
		cin >> g1;
	}while(g1!='c' && g1!='s' && g1!= 'f');
	
	//Elaboro la giocata del computer
	srand(seed); //Randomizzo
	g2 = rand()%3; //Prendo un numero da 0 a 2 compresi (3 numeri per le 3 giocate)
	switch(g2) //Converto da int a char per verificare la giocata
	{
		case 0:
			g2='c';
			break;
		case 1:
			g2='f';
			break;
		case 2:
			g2='s';
			break;
	}
	
	cout << "Il computer ha scelto: " << g2 << endl;
	
	if(g1==g2) //Se le giocate sono le stesse, pareggio
	{
		vincitore=2;
	}
	else if(g1 == 'f') //Giocatore 1 forbice
	{
		if(g2=='c')
		{
			vincitore=0; //Forbice vs Carta vince Forbice (G1)
		}
		else
		{
			vincitore=1; //Forbice vs Sasso vince Sasso (G2)
		}
	}
	else if(g1 == 'c') //Giocatore 1 Carta
	{
		if(g2=='s')
		{
			vincitore = 0; //Carta vs Sassso vince Carta (G1)
		}
		else
		{
			vincitore = 1; //Carta vs Forbice vince Forbice (G2)
		}
	}
	else if(g1 == 's') //Giocatore 1 Sasso
	{
		if(g2=='f')
		{
			vincitore=0; //Sasso vs Forbice vince Sasso (G1)
		}
		else
		{
			vincitore=1; //Sasso vs Carta vince Carta (G2)
		}
	}
	
	switch(vincitore) //Verifico e stampo chi ha vinto tramite lo switch
	{
		case 0:
			cout << "Hai vinto!" << endl;
			break;
		case 1:
			cout << "Vince il computer" << endl;
			break;
		case 2:
			cout << "Pareggio" << endl;
			break;
	}
	
	
}

