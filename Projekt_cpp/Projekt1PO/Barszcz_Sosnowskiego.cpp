#include "Barszcz_Sosnowskiego.h"
#include "Zwierze.h"
#include "Czlowiek.h"
Barszcz_Sosnowskiego::Barszcz_Sosnowskiego(Swiat* swiat, int x, int y) : Roslina(swiat, 10, 0, 0, 'B', x, y, true, 0.1) {};
Barszcz_Sosnowskiego::~Barszcz_Sosnowskiego() {
	//std::cout << "Destruktor barszczu\n";
}
void Barszcz_Sosnowskiego::Kolizja(Organizm* Atakujacy) {
	std::cout << this->symbol << " i " << Atakujacy->getSymbol() << " umieraja w konfrontacji\n";
	this->czyZyje = false;
	this->swiat_t->mapa[this->polozenieY][this->polozenieX] = NULL;
	Atakujacy->setCzyZyje(false);
	Atakujacy->getSwiat()->mapa[Atakujacy->getPolozenieY()][Atakujacy->getPolozenieX()] = NULL;
}
void Barszcz_Sosnowskiego::Akcja() {
	Rozmnazanie(NULL, this->prawdopodobienstwoRozsienia);
	int szerokosc = this->swiat_t->getSzerokosc();
	int wysokosc = this->swiat_t->getWysokosc();
	if (this->polozenieY != 0) {
		if (swiat_t->mapa[this->polozenieY - 1][this->polozenieX] != NULL) {
			if (dynamic_cast<Zwierze*>(swiat_t->mapa[this->polozenieY - 1][this->polozenieX]) != nullptr){
				if (this->swiat_t->mapa[this->polozenieY - 1][this->polozenieX]->getSymbol() == '$') {
					if (dynamic_cast<Czlowiek*>(this->swiat_t->mapa[this->polozenieY - 1][this->polozenieX])->getCzyAktywnaZdolnosc()) {
						return;
					}
				}
				Organizm* tmp = swiat_t->mapa[this->polozenieY - 1][this->polozenieX];
				swiat_t->mapa[this->polozenieY - 1][this->polozenieX]->setCzyZyje(false);
				std::cout << swiat_t->mapa[this->polozenieY - 1][this->polozenieX]->getSymbol() << " umiera przez " << this->symbol << "\n";
				swiat_t->mapa[this->polozenieY - 1][this->polozenieX] = NULL;
			}
		}
	}
	if (this->polozenieX < szerokosc - 1) {
		if (swiat_t->mapa[this->polozenieY][this->polozenieX + 1] != NULL) {
			if (dynamic_cast<Zwierze*>(swiat_t->mapa[this->polozenieY][this->polozenieX + 1]) != nullptr) {
				if (this->swiat_t->mapa[this->polozenieY][this->polozenieX+1]->getSymbol() == '$') {
					if (dynamic_cast<Czlowiek*>(this->swiat_t->mapa[this->polozenieY][this->polozenieX+1])->getCzyAktywnaZdolnosc()) {
						return;
					}
				}
				Organizm* tmp = swiat_t->mapa[this->polozenieY][this->polozenieX + 1];
				swiat_t->mapa[this->polozenieY][this->polozenieX + 1]->setCzyZyje(false);
				std::cout << swiat_t->mapa[this->polozenieY][this->polozenieX + 1]->getSymbol() << " umiera przez " << this->symbol << "\n";
				swiat_t->mapa[this->polozenieY][this->polozenieX + 1] = NULL;
			}
		}
	}
	if (this->polozenieY != wysokosc - 1) {
		if (swiat_t->mapa[this->polozenieY + 1][this->polozenieX] != NULL) {
			if (dynamic_cast<Zwierze*>(swiat_t->mapa[this->polozenieY + 1][this->polozenieX]) != nullptr) {
				if (this->swiat_t->mapa[this->polozenieY + 1][this->polozenieX]->getSymbol() == '$') {
					if (dynamic_cast<Czlowiek*>(this->swiat_t->mapa[this->polozenieY + 1][this->polozenieX])->getCzyAktywnaZdolnosc()) {
						return;
					}
				}
				Organizm* tmp = swiat_t->mapa[this->polozenieY + 1][this->polozenieX];
				swiat_t->mapa[this->polozenieY + 1][this->polozenieX]->setCzyZyje(false);
				std::cout << swiat_t->mapa[this->polozenieY + 1][this->polozenieX]->getSymbol() << " umiera przez " << this->symbol << "\n";
				swiat_t->mapa[this->polozenieY + 1][this->polozenieX] = NULL;
			}
		}
	}
	if (this->polozenieX != 0) {
		if (swiat_t->mapa[this->polozenieY][this->polozenieX - 1] != NULL) {
			if (dynamic_cast<Zwierze*>(swiat_t->mapa[this->polozenieY][this->polozenieX - 1]) != nullptr) {
				if (this->swiat_t->mapa[this->polozenieY][this->polozenieX-1]->getSymbol() == '$') {
					if (dynamic_cast<Czlowiek*>(this->swiat_t->mapa[this->polozenieY][this->polozenieX-1])->getCzyAktywnaZdolnosc()) {
						return;
					}
				}
				Organizm* tmp = swiat_t->mapa[this->polozenieY][this->polozenieX - 1];
				swiat_t->mapa[this->polozenieY][this->polozenieX - 1]->setCzyZyje(false);
				std::cout << swiat_t->mapa[this->polozenieY][this->polozenieX - 1]->getSymbol() << " umiera przez " << this->symbol << "\n";
				swiat_t->mapa[this->polozenieY][this->polozenieX - 1] = NULL;
			}
		}
	}
}
Barszcz_Sosnowskiego* Barszcz_Sosnowskiego::Potomstwo(Swiat* swiat_t, int x, int y) {
	return new Barszcz_Sosnowskiego(swiat_t, x, y);
}
