#pragma once

/* TODO : Funkcji
Suma - suma n warto�ci z tablicy --- DONE
IleSpelnia - ile podzielnych przez 3, ile mniejszych od 0, ... Warunek jako funkcja lub obiekt typu z operatorem ()
klasa Ulamek, wyposa�ona we wszystko co potrzebne dla ww szablon�w
*/

using namespace std;

class Ulamek {
	int licznik;
	unsigned int mianownik;
public:
	Ulamek(int licznik, unsigned int mianownik);
	int getLicznik() const;
	unsigned int getMianownik() const;
	Ulamek& operator +=(const Ulamek& u);
	Ulamek();
};

ostream& operator << (ostream& os, const Ulamek& u);