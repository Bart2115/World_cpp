#pragma once
#include <iostream>
#include <conio.h>
#include "Organizm.h"
#include "Swiat.h"

using namespace std;

int main() {
	int wys = 0;
	int sz = 0;
	bool wczytac = false;
	Swiat* x = NULL;
	std::cout << "Czy wczytac gre? (Y/N)\n";
	char wybor = _getch();
	if (wybor == 'Y' || wybor == 'y') {
		wczytac = true;
	}
	if (wczytac) {
		x = new Swiat(wys, sz, true);
		system("cls");
		if (x->getSzerokosc() == 0 || x->getWysokosc() == 0) {
			std::cout << "Blad wczytania!\n";
			wczytac = false;
		}
	}
	if(!wczytac){
		while (wys < 10 || wys > 100) {
			std::cout << "Podaj wysokosc mapy! (min 10, max 100)\n";
			cin >> wys;
		}
		while (sz < 10 || sz > 100) {
			std::cout << "Podaj szerokosc mapy! (min 10, max 100)\n";
			cin >> sz;
		}
		system("cls");
		x = new Swiat(wys, sz, false);
	}
	while (1) {
		x->RysujLegende();
		x->RysujSwiat();
		x->WykonajTure();
		char znak;
		std::cout << "\nWcisnij enter przy przejsc do kolejnej tury!\n";
		std::cout << "Wcisnij Q by wylaczyc gre lub S by zapisac obecny stan\n\n";
		znak = _getch();
		if (znak == 'q' || znak == 'Q') {
			return 0;
		}
		else if (znak == 's' || znak == 'S') {
			x->ZapiszSwiat();
		}
		system("cls");
	}
	return 0;
}