// Gruppo 1 - Esercizio di gruppo - Versione 3
// Create una copia della seconda release, estendendo il gioco in modo che prosegua per 3
// TURNI (TURNI apposita costante dichiarata nello scope globale del programma).
// Ad ogni passo di gioco vengono stampate su stdout le seguenti frasi:
// o “Il computer gioca mossa_computer” con mossa_computer={FORBICE, CARTA, SASSO}
// o   “XX vince su YY” con XX e YY le scelte dei due giocatori
// Alla fine dei turni si deve stampare la frase “Ha vinto vincitore” con 
// vincitore={giocatore1, computer}
// Opzionale: e’ possibile chiedere al giocatore di inserire un nome o un nick;
// questo potrà essere utilizzato nella stampa finale, nel caso di vincita: “Ha vinto nick”

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

const int MAX=3; //Numero Massimo per il rand
const int TURNI = 3; //Costante per il numero di turni

int main(){
	
	//Dichiaro le due giocate
	int g1,g2;
	//Dichiaro la variabile per il nome della mossa del computer
	string mossa_computer;
	//Dichiaro la stringa dove scrivere il vincitore
	string vincitore;
	//Dichiaro la variabile per il nick del giocatore
	string nickname;
	//Dichiaro un contatore per contare il numero di Turni effettuati
	int i=0;
	//Dichiaro i due punteggi
	int puntGioc=0;
	int puntComp=0;
	
	cout << "Inserisci il nickname: " << endl;
	cin >> nickname;
	cout << "Per inserire una giocata,0=carta, 1=sasso, 2= forbici" << endl;
	
	for(i=0;i<TURNI;i++){
		
		cout << "Turno " << i+1 << endl;	
		
	
		//Continua a chiedere fino a quando l'input non è valido
		do{
			cout << "Inserisci la tua giocata:" << endl;
			cin >> g1;
		}while(g1<0 || g1>2);
	
		//Elaboro la giocata del computer
		srand(time(NULL)); //Randomizzo con il tempo attuale
		g2 = rand()%3; //Prendo un numero da 0 a 2 compresi (3 numeri per le 3 giocate)
		switch(g2) //Converto da int a char per verificare la giocata
		{
			case 0:
				mossa_computer="Carta";
				break;
			case 1:
				mossa_computer="Forbici";
				break;
			case 2:
				mossa_computer="Sasso";
				break;
		}
		
		cout << "Il computer gioca: " << mossa_computer << "!" << endl;
	
		if(g1==g2) //Se le giocate sono le stesse, pareggio
		{
			cout << "Pareggio" << endl;
		}
		else if((g1+1)%3 == g2)
		{
			vincitore=nickname;
		}else
		{
			vincitore="Computer";
		}
	
		if(g1!=g2) //Stampo il vincitore (Se non si pareggia)
		{
			cout << "Ha vinto il turno: " << vincitore << "!" << endl;
			if(vincitore==nickname)
			{
				puntGioc++; //+1 punto al giocatore
			}
			else
			{
				puntComp++; //+1 punto al computer
			}
		}
	
		cout << "--------------------------------------------------------------------" << endl; //Linea di separazione per chiarezza 
	}
	//Fuori dal ciclo dei turni verifico chi ha vinto la partita
	if(puntGioc==puntComp)
	{
		cout << "La partita finisce in pareggio!" << endl;
	}else if (puntGioc>puntComp)
	{
		vincitore = nickname;
	}else if (puntGioc<puntComp){
		vincitore = "Computer";
	}
	
	if(puntGioc!=puntComp){ //Se non pareggio, stampo il vincitore della partita
		cout << "Vince la partita " << vincitore << " con un punteggio di " << puntGioc << " a " << puntComp << endl;
	}
		
}
