#include "Zwierze.h"
Zwierze::Zwierze(Swiat* swiat, int sila, int inicjatywa, int wiek, char symbol, int x, int y, bool czyZyje) : Organizm(swiat,sila,inicjatywa,wiek,symbol,x,y,czyZyje){}
void Zwierze::Akcja() {
	int szerokosc = this->swiat_t->getSzerokosc();
	int wysokosc = this->swiat_t->getWysokosc();
	while (1) {
		int x = rand() % 4;
		//KIERUNKI: GORA 0, PRAWO 1, DOL 2, LEWO 3
		if (x == 0) {
			if(this->polozenieY != 0){
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
			if (this->polozenieX < szerokosc-1) {
				//std::cout << "Ruch w prawo " << this->symbol << "\n";
				if(swiat_t->mapa[this->polozenieY][this->polozenieX + 1] != NULL){
					swiat_t->mapa[this->polozenieY][this->polozenieX+1]->Kolizja(this);
					if (!this->czyZyje) {
						break;
					}
				}
				if (swiat_t->mapa[this->polozenieY][this->polozenieX+1] == NULL) {
					swiat_t->mapa[this->polozenieY][this->polozenieX+1] = this;
					swiat_t->mapa[this->polozenieY][this->polozenieX] = NULL;
					this->polozenieX += 1;
				}
				break;
			}
		}
		else if (x == 2) {
			if (this->polozenieY != wysokosc-1) {
				//std::cout << "Ruch w dol " << this->symbol << "\n";
				if (swiat_t->mapa[this->polozenieY + 1][this->polozenieX] != NULL) {
					swiat_t->mapa[this->polozenieY+1][this->polozenieX]->Kolizja(this);
					if (!this->czyZyje) {
						break;
					}
				}
				if (swiat_t->mapa[this->polozenieY+1][this->polozenieX] == NULL) {
					swiat_t->mapa[this->polozenieY+1][this->polozenieX] = this;
					swiat_t->mapa[this->polozenieY][this->polozenieX] = NULL;
					this->polozenieY += 1;
					
				}
				break;
			}
		}
		else if (x == 3) {
			if (this->polozenieX != 0) {
				//std::cout << "Ruch w lewo " << this->symbol << "\n";
				if(swiat_t->mapa[this->polozenieY][this->polozenieX - 1] != NULL) {
					swiat_t->mapa[this->polozenieY][this->polozenieX-1]->Kolizja(this);
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
void Zwierze::Kolizja(Organizm* Atakujacy) {
	if (Atakujacy->getSymbol() == this->symbol) {
		this->Rozmnazanie(Atakujacy, 1);
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
void Zwierze::Rozmnazanie(Organizm* drugiRodzic, double prawdopodobienstwo) {
	int szerokosc = this->swiat_t->getSzerokosc();
	int wysokosc = this->swiat_t->getWysokosc();
	if (this->wiek <= 3 && drugiRodzic->getWiek() <= 3) {
		return;
	}
	prawdopodobienstwo *= 100;
	int x = rand() % 100;
	if (prawdopodobienstwo < x) {
		return;
	}
	if (this->czyWolneMiejsce()) {
		std::cout << "Urodzil sie nowy " << this->symbol << "\n";
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
	else if (drugiRodzic->czyWolneMiejsce()) {
		std::cout << "Urodzil sie nowy " << this->symbol << "\n";
		Organizm* organism;
		while (1) {
			int x = rand() % 4;
			//KIERUNKI: GORA 0, PRAWO 1, DOL 2, LEWO 3
			if (x == 0) {
				if (drugiRodzic->getPolozenieY() != 0) {
					if (swiat_t->mapa[drugiRodzic->getPolozenieY() - 1][drugiRodzic->getPolozenieX()] == NULL) {
						organism = drugiRodzic->Potomstwo(drugiRodzic->getSwiat(), drugiRodzic->getPolozenieX(), drugiRodzic->getPolozenieY() - 1);
						organism->getSwiat()->DodajDoOrganizmow(organism);
						swiat_t->mapa[drugiRodzic->getPolozenieY() - 1][drugiRodzic->getPolozenieX()] = organism;
					}
					break;
				}
			}
			else if (x == 1) {
				if (this->polozenieX < szerokosc - 1) {
					if (swiat_t->mapa[drugiRodzic->getPolozenieY()][drugiRodzic->getPolozenieX() + 1] == NULL) {
						organism = drugiRodzic->Potomstwo(drugiRodzic->getSwiat(), drugiRodzic->getPolozenieX() + 1, drugiRodzic->getPolozenieY());
						organism->getSwiat()->DodajDoOrganizmow(organism);
						swiat_t->mapa[drugiRodzic->getPolozenieY()][drugiRodzic->getPolozenieX() + 1] = organism;
					}
					break;
				}
			}
			else if (x == 2) {
				if (drugiRodzic->getPolozenieY() != wysokosc - 1) {
					if (swiat_t->mapa[drugiRodzic->getPolozenieY() + 1][drugiRodzic->getPolozenieX()] == NULL) {
						organism = drugiRodzic->Potomstwo(this->swiat_t, drugiRodzic->getPolozenieX(), drugiRodzic->getPolozenieY() + 1);
						organism->getSwiat()->DodajDoOrganizmow(organism);
						swiat_t->mapa[this->polozenieY + 1][this->polozenieX] = organism;
					}
					break;
				}
			}
			else if (x == 3) {
				if (this->polozenieX != 0) {
					if (swiat_t->mapa[this->polozenieY][this->polozenieX - 1] == NULL) {
						organism = drugiRodzic->Potomstwo(this->swiat_t, this->polozenieX - 1, this->polozenieY);
						organism->getSwiat()->DodajDoOrganizmow(organism);
						swiat_t->mapa[this->polozenieY][this->polozenieX - 1] = organism;
					}
					break;
				}
			}
		}
	}
}