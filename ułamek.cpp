#include <iostream>
#include <algorithm>
#include <numeric>
#include "header.h"

using namespace std;

template<class T, class U>
T Suma(U tab, int n) {
	if (n == 0) throw(invalid_argument("Tablica jest pusta"));
	T wynik = tab[0];
	for (int i = 1; i < n; ++i) wynik += *(tab + i);
	return wynik;
}

template<class T>
int IleSpelnia(const T* tab, int size, int(*kryterium)(T)) {
	int wynik = 0;
	for (unsigned int i = 0; i < size; i++) {
		if (kryterium(*(tab + i)) != 0) {
			wynik++;
		}
	}
	return wynik;
}

template<class T>
int PodzielnaPrzez3(T x) {
	if (x % 3 == 0) {
		return 1;
	}
	else return 0;
}

template<class T>
int MniejszaOd0(T x) {
	if (x < 0) {
		return 1;
	}
	else {
		return 0;
	}
}

Ulamek::Ulamek(int licznik, unsigned int mianownik) {
	this->licznik = licznik;
	this->mianownik = mianownik;
}
Ulamek::Ulamek() {
	this->licznik = 0;
	this->mianownik = 0;
}

int Ulamek::getLicznik() const {
	return licznik;
}

unsigned int Ulamek::getMianownik() const {
	return mianownik;
}

ostream& operator<<(ostream& os, const Ulamek& u) {

	if (!(u.getLicznik() % u.getMianownik())) {
		os << u.getLicznik() / u.getMianownik();
	}
	else {
		os << u.getLicznik() << "/" << u.getMianownik();
	}

	return os;
}

Ulamek& Ulamek::operator +=(const Ulamek& u) {
	unsigned int mian = mianownik;
	mianownik *= u.getMianownik();
	licznik *= u.getMianownik();
	licznik += u.getLicznik() * mian;

	int nwd = gcd(licznik, mianownik);

	licznik /= nwd;
	mianownik /= nwd;
	return *this;
}

