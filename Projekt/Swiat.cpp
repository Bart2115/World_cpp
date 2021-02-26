#pragma once
#include <fstream>
#include "Swiat.h"
#include "Wilk.h"
#include "Owca.h"
#include "Antylopa.h"
#include "Zolw.h"
#include "Lis.h"
#include "Wilcze_Jagody.h"
#include "Guarana.h"
#include "Mlecz.h"
#include "Trawa.h"
#include "Czlowiek.h"
#include "Barszcz_Sosnowskiego.h"
Organizm*** Swiat::stworzMape(int szerokosc, int wysokosc) {
	Organizm*** mapa;
	mapa = new Organizm**[wysokosc];
	for (int i = 0; i < wysokosc; ++i) {
		mapa[i] = new Organizm*[szerokosc];
		for (int j = 0; j < szerokosc; ++j) {
			mapa[i][j] = NULL;
		}
	}
	return mapa;
}
Swiat::Swiat(int sz, int wys, bool wczytaj) {
	szerokosc = sz;
	wysokosc = wys;
	if (wczytaj) {
		WczytajSwiat();
	}
	else {
		mapa = stworzMape(szerokosc, wysokosc);
		SpawnOrganizmow();
	}
}
Swiat::~Swiat() {
	for (int i = 0; i < wysokosc; ++i) {
		delete[] mapa[i];
	}
	delete[] mapa;
	std::cout << "Destruktor swiata\n";
}
void Swiat::RysujLegende() {
	std::cout << "Bartlomiej Buklewski 180275\n\n";
	std::cout << "A - Antylopa, B - Barszcz Sosnowskiego, G - Guarana, L - Lis\n";
	std::cout << "M - Mlecz, O - Owca, T - Trawa, J - Wilcze Jagody\n";
	std::cout << "W - Wilk, Z - Zolw, $ - Czlowiek\n\n";
	std::cout << "Super umiejetnosc czlowieka zapewnia mu niesmiertelnosc, w przypadku kolizji z przeciwnikiem silniejszym zostanie przeniesiony na losowe miejsce obok.\n\n";
}
void Swiat::RysujSwiat() {
	for (int i = 0; i < this->wysokosc; ++i) {
		std::cout << "|";
		for (int j = 0; j < this->szerokosc; ++j) {
			if (this->mapa[i][j] == NULL) {
				std::cout << " |";
			}
			else {
				std::cout << this->mapa[i][j]->getSymbol() << "|";
			}
		}
		std::cout << "\n";
	}
}
void Swiat::SpawnOrganizmow() {
	srand(time(NULL));
	for (int i = 0; i < 36; i++) {
		Organizm* organism = NULL;
		int y = rand() % wysokosc;
		int x = rand() % szerokosc;
		if (i == 0) {
			organism = new Czlowiek(this, x, y);
		}
		else if (i < 6) {
			organism = new Wilk(this,x,y);
		}
		else if (i < 11) {
			organism = new Owca(this,x,y);
		}
		else if (i < 16) {
			organism = new Lis(this,x,y);
		}
		else if (i < 21) {
			organism = new Antylopa(this,x,y);
		}
		else if (i < 26) {
			organism = new Zolw(this, x,y);
		}
		else if (i < 28) {
			organism = new Guarana(this, x, y);
		}
		else if (i < 30) {
			organism = new Wilcze_Jagody(this, x, y);
		}
		else if (i < 32) {
			organism = new Mlecz(this, x, y);
		}
		else if (i < 34) {
			organism = new Trawa(this, x, y);
		}
		else if (i < 36) {
			organism = new Barszcz_Sosnowskiego(this, x, y);
		}
		if (mapa[y][x] != NULL) {
			i--;
			continue;
		}
		mapa[y][x] = organism;
		organizmy.push_back(organism);
	}
}
int Swiat::getSzerokosc() {
	return this->szerokosc;
}
int Swiat::getWysokosc(){
	return this->wysokosc;
}
void Swiat::DodajDoOrganizmow(Organizm* organizm) {
	this->organizmy.push_back(organizm);
}
void Swiat::WykonajTure() {
	//Sortowanie wedlug kolejnosci wykonywania akcji
	int k = 0;
	while (organizmy.size() - k > 1) {
		int max = 0;
		for (int i = 1; i < organizmy.size() - k; i++) {
			if (organizmy[max]->getInicjatywa() > organizmy[i]->getInicjatywa()) {
				max = i;
			}
		}
		std::swap(organizmy[max], organizmy[organizmy.size()-k-1]);
		k++;
	}
	//Sortowanie wedlug wieku
	for (int i = 1; i < this->organizmy.size(); i++) {
		if (organizmy[i - 1]->getInicjatywa() == organizmy[i]->getInicjatywa()) {
			if (organizmy[i - 1]->getWiek() < organizmy[i]->getWiek()) {
				std::swap(organizmy[i-1], organizmy[i]);
				if (i >= 2) {
					i -= 2;
				}
			}
		}
	}
	for (int i = 0; i < this->organizmy.size(); i++) {
		if (organizmy[i]->getCzyZyje() == true) {
			this->organizmy[i]->Akcja();
		}
	}
	//Sprawdzenie czy jakieœ zwierzê nie umar³o , zwiekszenie wieku , zmniejszenie cooldownu superumiejetnosci lub czas aktywnej zdolnosci
	for (int i = 0; i < this->organizmy.size(); i++) {
		this->organizmy[i]->setWiek(1);
		if (this->organizmy[i]->getCzyZyje() == false) {
			delete organizmy[i];
			organizmy.erase(organizmy.begin() + i);
			i--;
		}
	}
}
void Swiat::ZapiszSwiat() {
	if (this->organizmy[0]->getSymbol() == '$') {
		if (dynamic_cast<Czlowiek*>(this->organizmy[0])->getCzyAktywnaZdolnosc() || dynamic_cast<Czlowiek*>(this->organizmy[0])->getCooldownZdolnosc() > 0) {
			std::cout << "Aby zapisac gre, czlowiek nie moze miec aktywnej super umiejetnosci lub miec cooldown!\n";
			std::cout << "Enter by kontynuowac!\n";
			getchar();
			return;
		}
	}
	std::ofstream plik;
	plik.open("zapisGry.txt", std::ios::out | std::ios::trunc);
	if (plik.good() == true) {
		plik << "X 0 0 "<< this->wysokosc << " " << this->szerokosc << "\n";
		for (int i = 0; i < this->organizmy.size(); i++) {
			plik << organizmy[i]->getSymbol() << " " << organizmy[i]->getWiek() << " " << organizmy[i]->getSila() << " ";
			plik << organizmy[i]->getPolozenieY() << " " << organizmy[i]->getPolozenieX() << "\n";
		}
		plik.close();
	}
}
void Swiat::WczytajSwiat() {
	std::ifstream plik;
	plik.open("zapisGry.txt", std::ios::in);
	char symbol;
	int wiek, sila, y, x, sz, wys;
	if (plik.good() == true) {
		while (plik >> symbol >> wiek >> sila >> y >> x){
			Organizm* organism = NULL;
			if (symbol == 'X') {
				this->mapa = stworzMape(y, x);
				this->wysokosc = y;
				this->szerokosc = x;
				continue;
			}
			else if (symbol == '$') {
				organism = new Czlowiek(this, x, y);
			}
			else if (symbol == 'A') {
				organism = new Antylopa(this, x, y);
			}
			else if (symbol == 'B') {
				organism = new Barszcz_Sosnowskiego(this, x, y);
			}
			else if (symbol == 'G') {
				organism = new Guarana(this, x, y);
			}
			else if (symbol == 'J') {
				organism = new Wilcze_Jagody(this, x, y);
			}
			else if (symbol == 'M') {
				organism = new Mlecz(this, x, y);
			}
			else if (symbol == 'T') {
				organism = new Trawa(this, x, y);
			}
			else if (symbol == 'Z') {
				organism = new Zolw(this, x, y);
			}
			else if (symbol == 'L') {
				organism = new Lis(this, x, y);
			}
			else if (symbol == 'W') {
				organism = new Wilk(this, x, y);
			}
			else if (symbol == 'O') {
				organism = new Owca(this, x, y);
			}
			organism->setSila(sila-organism->getSila());
			organism->setWiek(wiek - organism->getWiek());
			this->mapa[y][x] = organism;
			this->organizmy.push_back(organism);
		}
		plik.close();
	}
}