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
	int g1,g2;
	//Dichiaro la variabile vincitore (0=Giocatore 1, 1=Giocatore 2, 2=Pareggio)
	int vincitore;
	
	cout << "Per inserire una giocata, 0=carta, 1=sasso, 2= forbici" << endl;
	
	//Continua a chiedere fino a quando l'input non è valido
	do{
		cout << "Inserisci la tua giocata:" << endl;
		cin >> g1;
	}while(g1<0 || g1>2);
	
	//Elaboro la giocata del computer
	srand(seed); //Randomizzo
	g2 = rand()%3; //Prendo un numero da 0 a 2 compresi (3 numeri per le 3 giocate)
	
	cout << "Il computer ha scelto: " << g2 << endl;
	
	if(g1==g2) //Se le giocate sono le stesse, pareggio
	{
		vincitore=2;
	}
	else if((g1+1)%3 == g2)
	{
		vincitore=0;
	}else
	{
		vincitore=1;
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
