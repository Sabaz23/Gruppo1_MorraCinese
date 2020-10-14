// Gruppo 1 - Esercizio di gruppo - Versione 1
// Realizzate una prima implementazione in C++ di un passo di gioco con due input
// (giocatore 1 e giocatore 2) inseriti da tastiera. Calcolate il vincitore e memorizzate una
// codifica del vincitore in una variabile apposita. Dopo di che stampate il vincitore su stdout
// (attraverso lo stream cout).

#include <iostream>

using namespace std;
int main(){

	//Dichiaro le due giocate
	int g1,g2;
	//Dichiaro la variabile vincitore (0=Giocatore 1, 1=Giocatore 2, 2=Pareggio)
	int vincitore;
	
	cout << "Per inserire una giocata, 0=carta, 1=sasso, 2= forbici" << endl;
	
	//Continua a chiedere fino a quando l'input non è valido
	do{
		cout << "Inserisci la giocata del primo giocatore:" << endl;
		cin >> g1;
	}while(g1<0 || g1 >2);
	
	//Stesso per il secondo giocatore
	do{
		cout << "Inserisci la giocata del secondo giocatore:" << endl;
		cin >> g2;
	}while(g2<0 || g2>2);
	
	
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
			cout << "Vince il giocatore 1" << endl;
			break;
		case 1:
			cout << "Vince il giocatore 2" << endl;
			break;
		case 2:
			cout << "Pareggio" << endl;
			break;
	}
	
	
}
