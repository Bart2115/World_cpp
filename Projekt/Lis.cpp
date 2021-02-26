#include "Lis.h"
Lis::Lis(Swiat* swiat, int x, int y) : Zwierze(swiat, 3, 7, 0, 'L', x , y, true) {};
Lis::~Lis() {
	//std::cout << "destruktor lisa\n";
}
bool Lis::dobryWech() {
	int szerokosc = this->swiat_t->getSzerokosc();
	int wysokosc = this->swiat_t->getWysokosc();
	int i = 0;
	if (this->polozenieY != 0) {
		if (swiat_t->mapa[this->polozenieY - 1][this->polozenieX] != NULL) {
			if (swiat_t->mapa[this->polozenieY - 1][this->polozenieX]->getSila() > this->sila) {
				i++;
			}
		}
	}
	else {
		i++;
	}
	if (this->polozenieX < szerokosc - 1) {
		if (swiat_t->mapa[this->polozenieY][this->polozenieX + 1] != NULL) {
			if (swiat_t->mapa[this->polozenieY][this->polozenieX + 1]->getSila() > this->sila) {
				i++;
			}
		}
	}
	else {
		i++;
	}
	if (this->polozenieY != wysokosc - 1) {
		if (swiat_t->mapa[this->polozenieY + 1][this->polozenieX] != NULL) {
			if (swiat_t->mapa[this->polozenieY + 1][this->polozenieX]->getSila() > this->sila) {
				i++;
			}
		}
	}
	else {
		i++;
	}
	if (this->polozenieX != 0) {
		if (swiat_t->mapa[this->polozenieY][this->polozenieX - 1] != NULL) {
			if (swiat_t->mapa[this->polozenieY][this->polozenieX - 1]->getSila() > this->sila) {
				i++;
			}
		}
	}
	else {
		i++;
	}
	if (i == 4) {
		return true;
	}
	else {
		return false;
	}
}
void Lis::Akcja() {
	int szerokosc = this->swiat_t->getSzerokosc();
	int wysokosc = this->swiat_t->getWysokosc();
	while (1) {
		int x = rand() % 4;
		if (dobryWech()) {
			//std::cout << "Bezczynnosc " << this->symbol << "\n";
			break;
		}
		//KIERUNKI: GORA 0, PRAWO 1, DOL 2, LEWO 3
		if (x == 0) {
			if (this->polozenieY != 0) {
				if (swiat_t->mapa[this->polozenieY - 1][this->polozenieX] != NULL) {
					if (swiat_t->mapa[this->polozenieY - 1][this->polozenieX]->getSila() > this->sila) {
						continue;
					}
					swiat_t->mapa[this->polozenieY - 1][this->polozenieX]->Kolizja(this);
					if (!this->czyZyje) {
						//std::cout << "Ruch w gore " << this->symbol << "\n";
						break;
					}
				}
				if (swiat_t->mapa[this->polozenieY - 1][this->polozenieX] == NULL) {
					//std::cout << "Ruch w gore " << this->symbol << "\n";
					swiat_t->mapa[this->polozenieY - 1][this->polozenieX] = this;
					swiat_t->mapa[this->polozenieY][this->polozenieX] = NULL;
					this->polozenieY -= 1;

				}
				break;
			}
		}
		else if (x == 1) {
			if (this->polozenieX < szerokosc - 1) {
				if (swiat_t->mapa[this->polozenieY][this->polozenieX + 1] != NULL) {
					if (swiat_t->mapa[this->polozenieY][this->polozenieX + 1]->getSila() > this->sila) {
						continue;
					}
					swiat_t->mapa[this->polozenieY][this->polozenieX + 1]->Kolizja(this);
					if (!this->czyZyje) {
						//std::cout << "Ruch w prawo " << this->symbol << "\n";
						break;
					}
				}
				if (swiat_t->mapa[this->polozenieY][this->polozenieX + 1] == NULL) {
					//std::cout << "Ruch w prawo " << this->symbol << "\n";
					swiat_t->mapa[this->polozenieY][this->polozenieX + 1] = this;
					swiat_t->mapa[this->polozenieY][this->polozenieX] = NULL;
					this->polozenieX += 1;
				}
				break;
			}
		}
		else if (x == 2) {
			if (this->polozenieY != wysokosc - 1) {
				if (swiat_t->mapa[this->polozenieY + 1][this->polozenieX] != NULL) {
					if (swiat_t->mapa[this->polozenieY + 1][this->polozenieX]->getSila() > this->sila) {
						continue;
					}
					swiat_t->mapa[this->polozenieY + 1][this->polozenieX]->Kolizja(this);
					if (!this->czyZyje) {
						//std::cout << "Ruch w dol " << this->symbol << "\n";
						break;
					}
				}
				if (swiat_t->mapa[this->polozenieY + 1][this->polozenieX] == NULL) {
					//std::cout << "Ruch w dol " << this->symbol << "\n";
					swiat_t->mapa[this->polozenieY + 1][this->polozenieX] = this;
					swiat_t->mapa[this->polozenieY][this->polozenieX] = NULL;
					this->polozenieY += 1;

				}
				break;
			}
		}
		else if (x == 3) {
			if (this->polozenieX != 0) {
				if (swiat_t->mapa[this->polozenieY][this->polozenieX - 1] != NULL) {
					if (swiat_t->mapa[this->polozenieY][this->polozenieX - 1]->getSila() > this->sila) {
						continue;
					}
					swiat_t->mapa[this->polozenieY][this->polozenieX - 1]->Kolizja(this);
					if (!this->czyZyje) {
						//std::cout << "Ruch w lewo " << this->symbol << "\n";
						break;
					}
				}
				if (swiat_t->mapa[this->polozenieY][this->polozenieX - 1] == NULL) {
					//std::cout << "Ruch w lewo " << this->symbol << "\n";
					swiat_t->mapa[this->polozenieY][this->polozenieX - 1] = this;
					swiat_t->mapa[this->polozenieY][this->polozenieX] = NULL;
					this->polozenieX -= 1;

				}
				break;
			}
		}
	}
}
Lis* Lis::Potomstwo(Swiat* swiat_t, int x, int y) {
	return new Lis(swiat_t, x, y);
}