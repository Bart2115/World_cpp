#include "Zolw.h"
Zolw::Zolw(Swiat* swiat, int x, int y) : Zwierze(swiat, 2, 1, 0, 'Z', x, y, true) {};
Zolw::~Zolw() {
	//std::cout << "Destruktor Zolwia\n";
}
void Zolw::Akcja() {
	int szerokosc = this->swiat_t->getSzerokosc();
	int wysokosc = this->swiat_t->getWysokosc();
	while (1) {
		int x = rand() % 4;
		if (x == 0) {
			x = rand() % 4;
		}
		else {
			//std::cout << "Bezczynnosc " << this->symbol << "\n";
			break;
		}
		//KIERUNKI: GORA 0, PRAWO 1, DOL 2, LEWO 3
		if (x == 0) {
			if (this->polozenieY != 0) {
				//std::cout << "Ruch w gore " << this->symbol << "\n";
				if (swiat_t->mapa[this->polozenieY - 1][this->polozenieX] != NULL) {
					swiat_t->mapa[this->polozenieY - 1][this->polozenieX]->Kolizja(this);
					if (!this->czyZyje) {
						break;
					}
				}
				if (swiat_t->mapa[this->polozenieY - 1][this->polozenieX] == NULL) {
					swiat_t->mapa[this->polozenieY - 1][this->polozenieX] = this;
					swiat_t->mapa[this->polozenieY][this->polozenieX] = NULL;
					this->polozenieY -= 1;

				}
				break;
			}
		}
		else if (x == 1) {
			if (this->polozenieX < szerokosc - 1) {
				//std::cout << "Ruch w prawo " << this->symbol << "\n";
				if (swiat_t->mapa[this->polozenieY][this->polozenieX + 1] != NULL) {
					swiat_t->mapa[this->polozenieY][this->polozenieX + 1]->Kolizja(this);
					if (!this->czyZyje) {
						break;
					}
				}
				if (swiat_t->mapa[this->polozenieY][this->polozenieX + 1] == NULL) {
					swiat_t->mapa[this->polozenieY][this->polozenieX + 1] = this;
					swiat_t->mapa[this->polozenieY][this->polozenieX] = NULL;
					this->polozenieX += 1;

				}

				break;
			}
		}
		else if (x == 2) {
			if (this->polozenieY != wysokosc - 1) {
				//std::cout << "Ruch w dol " << this->symbol << "\n";
				if (swiat_t->mapa[this->polozenieY + 1][this->polozenieX] != NULL) {
					swiat_t->mapa[this->polozenieY + 1][this->polozenieX]->Kolizja(this);
					if (!this->czyZyje) {
						break;
					}
				}
				if (swiat_t->mapa[this->polozenieY + 1][this->polozenieX] == NULL) {
					swiat_t->mapa[this->polozenieY + 1][this->polozenieX] = this;
					swiat_t->mapa[this->polozenieY][this->polozenieX] = NULL;
					this->polozenieY += 1;

				}
				break;
			}
		}
		else if (x == 3) {
			if (this->polozenieX != 0) {
				//std::cout << "Ruch w lewo " << this->symbol << "\n";
				if (swiat_t->mapa[this->polozenieY][this->polozenieX - 1] != NULL) {
					swiat_t->mapa[this->polozenieY][this->polozenieX - 1]->Kolizja(this);
					if (!this->czyZyje) {
						break;
					}
				}
				if (swiat_t->mapa[this->polozenieY][this->polozenieX - 1] == NULL) {
					swiat_t->mapa[this->polozenieY][this->polozenieX - 1] = this;
					swiat_t->mapa[this->polozenieY][this->polozenieX] = NULL;
					this->polozenieX -= 1;

				}
				break;
			}
		}
	}
}
void Zolw::Kolizja(Organizm* Atakujacy) {
	if (Atakujacy->getSymbol() == this->symbol) {
		this->Rozmnazanie(Atakujacy, 1);
		return;
	}
	if(Atakujacy->getSila() < 5){
		return;
	}
	if (this->sila > Atakujacy->getSila()) {
		std::cout << "Atakujacy " << Atakujacy->getSymbol() << " umiera w ataku na " << this->symbol << "\n";
		Atakujacy->setCzyZyje(false);
		Atakujacy->getSwiat()->mapa[Atakujacy->getPolozenieY()][Atakujacy->getPolozenieX()] = NULL;
	}
	else if (this->sila <= Atakujacy->getSila()) {
		std::cout << this->symbol << " umiera w obronie przez " << Atakujacy->getSymbol() << "\n";
		this->czyZyje = false;
		this->swiat_t->mapa[this->polozenieY][this->polozenieX] = NULL;
	}
}
Zolw* Zolw::Potomstwo(Swiat* swiat_t, int x, int y) {
	return new Zolw(swiat_t, x, y);
}