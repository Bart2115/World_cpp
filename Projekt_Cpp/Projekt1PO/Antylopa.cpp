#include "Antylopa.h"
Antylopa::Antylopa(Swiat* swiat, int x, int y) : Zwierze(swiat, 4, 4, 0, 'A', x, y, true) {};
Antylopa::~Antylopa() {
	//std::cout << "destrukor antylopy\n";
}
void Antylopa::Ucieczka() {
	int szerokosc = this->swiat_t->getSzerokosc();
	int wysokosc = this->swiat_t->getWysokosc();
	int tab[] = {-1,-1,-1,-1};
	while (1) {
		int spr = 0;
		for (int i = 0; i < 4; i++) {
			spr += tab[i];
		}
		if (spr == 4) {
			//std::cout << "Bezczynnosc " << this->symbol << "\n";
			break;
		}
		int x = rand() % 4;
		if (x == 0) {
			if (this->polozenieY != 0){
				if (swiat_t->mapa[this->polozenieY - 1][this->polozenieX] == NULL) {
					//std::cout << "Ruch w gore " << this->symbol << "\n";
					swiat_t->mapa[this->polozenieY - 1][this->polozenieX] = this;
					swiat_t->mapa[this->polozenieY][this->polozenieX] = NULL;
					this->polozenieY -= 1;
					break;
				}
				else {
					tab[x] = 1;
				}
			}
			else {
				tab[x] = 1;
			}
		}
		else if (x == 1) {
			if (this->polozenieX < szerokosc-1) {
				if (swiat_t->mapa[this->polozenieY][this->polozenieX+1] == NULL) {
					//std::cout << "Ruch w prawo " << this->symbol << "\n";
					swiat_t->mapa[this->polozenieY][this->polozenieX+1] = this;
					swiat_t->mapa[this->polozenieY][this->polozenieX] = NULL;
					this->polozenieX += 1;
					break;
				}
				else{
					tab[x] = 1;
				}
			}
			else {
				tab[x] = 1;
			}
		}
		else if (x == 2) {
			if (this->polozenieY != wysokosc-1) {
				if (swiat_t->mapa[this->polozenieY+1][this->polozenieX] == NULL) {
					//std::cout << "Ruch w dol " << this->symbol << "\n";
					swiat_t->mapa[this->polozenieY+1][this->polozenieX] = this;
					swiat_t->mapa[this->polozenieY][this->polozenieX] = NULL;
					this->polozenieY += 1;
					break;
				}
				else {
					tab[x] = 1;
				}
			}
			else {
				tab[x] = 1;
			}
		}
		else if (x == 3) {
			if (this->polozenieX != 0) {
				if (swiat_t->mapa[this->polozenieY][this->polozenieX - 1] == NULL) {
					//std::cout << "Ruch w lewo " << this->symbol << "\n";
					swiat_t->mapa[this->polozenieY][this->polozenieX - 1] = this;
					swiat_t->mapa[this->polozenieY][this->polozenieX] = NULL;
					this->polozenieX -= 1;
					break;
				}
				else {
					tab[x] = 1;
				}
			}
			else {
				tab[x] = 1;
			}
		}
	}
}
void Antylopa::Akcja() {
	int szerokosc = this->swiat_t->getSzerokosc();
	int wysokosc = this->swiat_t->getWysokosc();
	while (1) {
		int x = rand() % 4;
		//KIERUNKI: GORA 0, PRAWO 1, DOL 2, LEWO 3
		if (x == 0) {
			if (this->polozenieY > 1) {
				//std::cout << "Ruch w gore " << this->symbol << "\n";
				if (swiat_t->mapa[this->polozenieY - 2][this->polozenieX] != NULL) {
					swiat_t->mapa[this->polozenieY - 2][this->polozenieX]->Kolizja(this);
					if (!this->czyZyje) {
						break;
					}
				}
				if (swiat_t->mapa[this->polozenieY - 2][this->polozenieX] == NULL) {
					swiat_t->mapa[this->polozenieY - 2][this->polozenieX] = this;
					swiat_t->mapa[this->polozenieY][this->polozenieX] = NULL;
					this->polozenieY -= 2;
				}
				break;
			}
		}
		else if (x == 1) {
			if (this->polozenieX < szerokosc - 2) {
				//std::cout << "Ruch w prawo " << this->symbol << "\n";
				if (swiat_t->mapa[this->polozenieY][this->polozenieX + 2] != NULL) {
					swiat_t->mapa[this->polozenieY][this->polozenieX + 2]->Kolizja(this);
					if (!this->czyZyje) {
						break;
					}
				}
				if (swiat_t->mapa[this->polozenieY][this->polozenieX + 2] == NULL) {
					swiat_t->mapa[this->polozenieY][this->polozenieX + 2] = this;
					swiat_t->mapa[this->polozenieY][this->polozenieX] = NULL;
					this->polozenieX += 2;
				}
				break;
			}
		}
		else if (x == 2) {
			if (this->polozenieY < wysokosc - 2) {
				//std::cout << "Ruch w dol " << this->symbol << "\n";
				if (swiat_t->mapa[this->polozenieY + 2][this->polozenieX] != NULL) {
					swiat_t->mapa[this->polozenieY + 2][this->polozenieX]->Kolizja(this);
					if (!this->czyZyje) {
						break;
					}
				}
				if (swiat_t->mapa[this->polozenieY + 2][this->polozenieX] == NULL) {
					swiat_t->mapa[this->polozenieY + 2][this->polozenieX] = this;
					swiat_t->mapa[this->polozenieY][this->polozenieX] = NULL;
					this->polozenieY += 2;
				}
				break;
			}
		}
		else if (x == 3) {
			if (this->polozenieX > 1) {
				//std::cout << "Ruch w lewo " << this->symbol << "\n";
				if (swiat_t->mapa[this->polozenieY][this->polozenieX - 2] != NULL) {
					swiat_t->mapa[this->polozenieY][this->polozenieX - 2]->Kolizja(this);
					if (!this->czyZyje) {
						break;
					}
				}
				if (swiat_t->mapa[this->polozenieY][this->polozenieX - 2] == NULL) {
					swiat_t->mapa[this->polozenieY][this->polozenieX - 2] = this;
					swiat_t->mapa[this->polozenieY][this->polozenieX] = NULL;
					this->polozenieX -= 2;

				}
				break;
			}
		}
	}
}
void Antylopa::Kolizja(Organizm* Atakujacy) {
	if (Atakujacy->getSymbol() == this->symbol) {
		this->Rozmnazanie(Atakujacy, 1);
		return;
	}
	int x = rand() % 2;
	if (x == 0) {
		Ucieczka();
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
Antylopa* Antylopa::Potomstwo(Swiat* swiat_t, int x, int y) {
	return new Antylopa(swiat_t, x, y);
}