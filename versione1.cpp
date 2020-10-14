// Gruppo 1 - Esercizio di gruppo - Versione 1
// Realizzate una prima implementazione in C++ di un passo di gioco con due input
// (giocatore 1 e giocatore 2) inseriti da tastiera. Calcolate il vincitore e memorizzate una
// codifica del vincitore in una variabile apposita. Dopo di che stampate il vincitore su stdout
// (attraverso lo stream cout).

#include <iostream>

using namespace std;
int main(){

	//Dichiaro le due giocate
	char g1,g2;
	//Dichiaro la variabile vincitore (0=Giocatore 1, 1=Giocatore 2, 2=Pareggio)
	int vincitore;
	
	cout << "Per inserire una giocata,'c'=carta, 's'=sasso, 'f'= forbici" << endl;
	
	//Continua a chiedere fino a quando l'input non è valido
	do{
		cout << "Inserisci la giocata del primo giocatore:" << endl;
		cin >> g1;
	}while(g1!='c' && g1!='s' && g1!= 'f');
	
	//Stesso per il secondo giocatore
	do{
		cout << "Inserisci la giocata del secondo giocatore:" << endl;
		cin >> g2;
	}while(g2!='c' && g2!='s' && g2!= 'f');
	
	
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

