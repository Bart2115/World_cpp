#include "Roslina.h"
Roslina::Roslina(Swiat* swiat, int sila, int inicjatywa, int wiek, char symbol, int x, int y, bool czyZyje, double prawdopodobienstwoRozsienia): Organizm(swiat,sila,inicjatywa,wiek,symbol,x,y,czyZyje) {
	this->prawdopodobienstwoRozsienia = prawdopodobienstwoRozsienia;
}
void Roslina::Akcja() {
	Rozmnazanie(NULL, this->prawdopodobienstwoRozsienia);
}
void Roslina::Kolizja(Organizm* organizmAtakujacy) {
	std::cout << this->symbol << " umiera w obronie przez " << organizmAtakujacy->getSymbol() << "\n";
	this->czyZyje = false;
	this->swiat_t->mapa[this->polozenieY][this->polozenieX] = NULL;
}
void Roslina::Rozmnazanie(Organizm* drugiRodzic, double prawdopodobienstwo) {
	int szerokosc = this->swiat_t->getSzerokosc();
	int wysokosc = this->swiat_t->getWysokosc();
	if (this->wiek <= 6) {
		return;
	}
	prawdopodobienstwo *= 100;
	int x = rand() % 100;
	if (prawdopodobienstwo < x) {
		return;
	}
	if (this->czyWolneMiejsce()) {
		std::cout << "Wyrosl nowy " << this->symbol << "\n";
		Organizm* organism;
		while (1) {
			x = rand() % 4;
			//KIERUNKI: GORA 0, PRAWO 1, DOL 2, LEWO 3
			if (x == 0) {
				if (this->polozenieY != 0) {
					if (swiat_t->mapa[this->polozenieY - 1][this->polozenieX] == NULL) {
						organism = this->Potomstwo(this->swiat_t, this->polozenieX, this->polozenieY - 1);
						organism->getSwiat()->DodajDoOrganizmow(organism);
						swiat_t->mapa[this->polozenieY - 1][this->polozenieX] = organism;
					}
					break;
				}
			}
			else if (x == 1) {
				if (this->polozenieX < szerokosc - 1) {
					if (swiat_t->mapa[this->polozenieY][this->polozenieX + 1] == NULL) {
						organism = this->Potomstwo(this->swiat_t, this->polozenieX + 1, this->polozenieY);
						organism->getSwiat()->DodajDoOrganizmow(organism);
						swiat_t->mapa[this->polozenieY][this->polozenieX + 1] = organism;
					}
					break;
				}
			}
			else if (x == 2) {
				if (this->polozenieY != wysokosc - 1) {
					if (swiat_t->mapa[this->polozenieY + 1][this->polozenieX] == NULL) {
						organism = this->Potomstwo(this->swiat_t, this->polozenieX, this->polozenieY + 1);
						organism->getSwiat()->DodajDoOrganizmow(organism);
						swiat_t->mapa[this->polozenieY + 1][this->polozenieX] = organism;
					}
					break;
				}
			}
			else if (x == 3) {
				if (this->polozenieX != 0) {
					if (swiat_t->mapa[this->polozenieY][this->polozenieX - 1] == NULL) {
						organism = this->Potomstwo(this->swiat_t, this->polozenieX - 1, this->polozenieY);
						organism->getSwiat()->DodajDoOrganizmow(organism);
						swiat_t->mapa[this->polozenieY][this->polozenieX - 1] = organism;
					}
					break;
				}
			}
		}
	}
}