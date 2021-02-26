#include "Czlowiek.h"
#include <conio.h>
Czlowiek::Czlowiek(Swiat* swiat, int x, int y) : Zwierze(swiat, 5, 10, 0, '$', x, y, true) {
	this->CooldownZdolnosci = 0;
	this->czyAktywnaZdolnosc = false;
	this->PozostalyCzasZdolnosci = 0;
}
bool Czlowiek::getCzyAktywnaZdolnosc() {
	return this->czyAktywnaZdolnosc;
}
int Czlowiek::getCooldownZdolnosc() {
	return this->CooldownZdolnosci;
}
void Czlowiek::Akcja() {
	int szerokosc = this->swiat_t->getSzerokosc();
	int wysokosc = this->swiat_t->getWysokosc();
	AktywowanieSuperUmiejetnosci();
	std::cout << "Ruch czlowieka!\n";
	while (1) {
		int x = 5;
		unsigned char znak = _getch();
		switch (znak) {
			case 0: //klawisze specjalne
			case 224: //klawisze specjalne
				znak = _getch();
				switch (znak) {
					case 72: //strza³ka w górê
						x = 0;
						break;
					case 80: //strza³ka w dó³
						x = 2;
						break;
					case 75: //strza³ka w lewo
						x = 3;
						break;
					case 77: //strza³ka w prawo
						x = 1;
						break;
				}
		}
		//KIERUNKI: GORA 0, PRAWO 1, DOL 2, LEWO 3
		if (x == 0) {
			if (this->polozenieY != 0) {
				//std::cout << "Ruch w gore " << this->symbol << "\n";
				if (swiat_t->mapa[this->polozenieY - 1][this->polozenieX] != NULL) {
					if (this->czyAktywnaZdolnosc && (swiat_t->mapa[this->polozenieY - 1][this->polozenieX]->getSila() > this->sila)) {
						Niesmiertelnosc();
					}
					else {
						swiat_t->mapa[this->polozenieY - 1][this->polozenieX]->Kolizja(this);
					}
					if (!this->czyZyje) {
						if (this->czyAktywnaZdolnosc) {
							this->czyNapewnoSmierc();
						}
						else {
							break;
						}
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
					if (this->czyAktywnaZdolnosc && (swiat_t->mapa[this->polozenieY][this->polozenieX + 1]->getSila() > this->sila)) {
						Niesmiertelnosc();
					}
					else {
						swiat_t->mapa[this->polozenieY][this->polozenieX + 1]->Kolizja(this);
					}
					if (!this->czyZyje) {
						if (this->czyAktywnaZdolnosc) {
							this->czyNapewnoSmierc();
						}
						else {
							break;
						}
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
					if (this->czyAktywnaZdolnosc && (swiat_t->mapa[this->polozenieY + 1][this->polozenieX]->getSila() > this->sila)) {
						Niesmiertelnosc();
					}
					else {
						swiat_t->mapa[this->polozenieY + 1][this->polozenieX]->Kolizja(this);
					}
					if (!this->czyZyje) {
						if (this->czyAktywnaZdolnosc) {
							this->czyNapewnoSmierc();
						}
						else {
							break;
						}
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
					if (this->czyAktywnaZdolnosc && (swiat_t->mapa[this->polozenieY][this->polozenieX - 1]->getSila() > this->sila)) {
						Niesmiertelnosc();
					}
					else {
						swiat_t->mapa[this->polozenieY][this->polozenieX - 1]->Kolizja(this);
					}
					if (!this->czyZyje) {
						if (this->czyAktywnaZdolnosc) {
							this->czyNapewnoSmierc();
						}
						else {
							break;
						}
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
void Czlowiek::Kolizja(Organizm* Atakujacy) {
	if (this->czyAktywnaZdolnosc && this->sila <= Atakujacy->getSila()) {
		this->Niesmiertelnosc();
	}
	else if (this->sila > Atakujacy->getSila()) {
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
bool Czlowiek::czyNajslabszy() {
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
void Czlowiek::Niesmiertelnosc() {
	int szerokosc = this->swiat_t->getSzerokosc();
	int wysokosc = this->swiat_t->getWysokosc();
	if (this->czyNajslabszy()) {
		return;
	}
	while (1) {
		int x = rand() % 4;
		//KIERUNKI: GORA 0, PRAWO 1, DOL 2, LEWO 3
		if (x == 0) {
			if (this->polozenieY != 0) {
				if (swiat_t->mapa[this->polozenieY - 1][this->polozenieX] != NULL) {
					if (swiat_t->mapa[this->polozenieY - 1][this->polozenieX]->getSila() <= this->sila) {
						swiat_t->mapa[this->polozenieY - 1][this->polozenieX]->Kolizja(this);
					}
					if (!this->czyZyje) {
						this->czyNapewnoSmierc();
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
				if (swiat_t->mapa[this->polozenieY][this->polozenieX + 1] != NULL) {
					if (swiat_t->mapa[this->polozenieY][this->polozenieX + 1]->getSila() <= this->sila) {
						swiat_t->mapa[this->polozenieY][this->polozenieX + 1]->Kolizja(this);
					}
					if (!this->czyZyje) {
						this->czyNapewnoSmierc();
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
				if (swiat_t->mapa[this->polozenieY + 1][this->polozenieX] != NULL) {
					if (swiat_t->mapa[this->polozenieY + 1][this->polozenieX]->getSila() <= this->sila) {
						swiat_t->mapa[this->polozenieY + 1][this->polozenieX]->Kolizja(this);
					}
					if (!this->czyZyje) {
						this->czyNapewnoSmierc();
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
				if (swiat_t->mapa[this->polozenieY][this->polozenieX - 1] != NULL) {
					if (swiat_t->mapa[this->polozenieY][this->polozenieX - 1]->getSila() <= this->sila) {
						swiat_t->mapa[this->polozenieY][this->polozenieX - 1]->Kolizja(this);
					}
					if (!this->czyZyje) {
						this->czyNapewnoSmierc();
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
void Czlowiek::czyNapewnoSmierc() {
	if (this->czyAktywnaZdolnosc) {
		this->swiat_t->mapa[this->polozenieY][this->polozenieX] = this;
		this->czyZyje = true;
	}
}
void Czlowiek::AktywowanieSuperUmiejetnosci() {
	if (this->CooldownZdolnosci == 1) {
		this->CooldownZdolnosci--;
	}
	if (!this->czyAktywnaZdolnosc && this->CooldownZdolnosci == 0) {
		std::cout << "Czy aktywowac superzdolnosc? (Y/N)\n";
		char odp;
		odp = _getch();
		if (odp == 'Y' || odp == 'y') {
			this->czyAktywnaZdolnosc = true;
			this->PozostalyCzasZdolnosci = 5;
			std::cout << "Superzdolnosc aktywna przez " << this->PozostalyCzasZdolnosci << " tur!\n";
		}
	}
	else if (this->CooldownZdolnosci > 1) {
		this->CooldownZdolnosci--;
		std::cout << "Cooldown supermocy: " << this->CooldownZdolnosci << "\n";
	}
	else if (this->czyAktywnaZdolnosc) {
		if (this->PozostalyCzasZdolnosci > 1) {
			this->PozostalyCzasZdolnosci--;
			std::cout << "Superzdolnosc aktywna przez " << this->PozostalyCzasZdolnosci << " tury!\n";
		}
		else {
			this->czyAktywnaZdolnosc = false;
			this->CooldownZdolnosci = 5;
			std::cout << "Cooldown supermocy: " << this->CooldownZdolnosci << "\n";
		}
	}
}