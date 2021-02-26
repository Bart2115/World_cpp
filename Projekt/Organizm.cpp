#include "Organizm.h"
Organizm::Organizm(Swiat* swiat, int sila, int inicjatywa, int wiek, char symbol, int x, int y, bool czyZyje) {
	this->czyZyje = czyZyje;
	this->polozenieY = y;
	this->polozenieX = x;
	this->symbol = symbol;
	this->inicjatywa = inicjatywa;
	this->sila = sila;
	this->wiek = wiek;
	this->swiat_t = swiat;
}
bool Organizm::czyWolneMiejsce(){
	int szerokosc = this->swiat_t->getSzerokosc();
	int wysokosc = this->swiat_t->getWysokosc();
	int i = 0;
	if (this->polozenieY != 0) {
		if (swiat_t->mapa[this->polozenieY - 1][this->polozenieX] != NULL) {
			i++;
		}
	}
	else {
		i++;
	}
	if (this->polozenieX < szerokosc - 1) {
		if (swiat_t->mapa[this->polozenieY][this->polozenieX + 1] != NULL) {
			i++;
		}
	}
	else {
		i++;
	}
	if (this->polozenieY != wysokosc - 1) {
		if (swiat_t->mapa[this->polozenieY + 1][this->polozenieX] != NULL) {
			i++;
		}
	}
	else {
		i++;
	}
	if (this->polozenieX != 0) {
		if (swiat_t->mapa[this->polozenieY][this->polozenieX - 1] != NULL) {
			i++;
		}
	}
	else {
		i++;
	}
	if (i == 4) {
		return false;
	}
	else {
		return true;
	}
}
int Organizm::getWiek() {
	return this->wiek;
}
int Organizm::getSila() {
	return this->sila;
}
int Organizm::getInicjatywa() {
	return this->inicjatywa;
}
int Organizm::getPolozenieX() {
	return this->polozenieX;
}
int Organizm::getPolozenieY() {
	return this->polozenieY;
}
bool Organizm::getCzyZyje() {
	return this->czyZyje;
}
void Organizm::setCzyZyje(bool czyZyje) {
	this->czyZyje = czyZyje;
}
void Organizm::setSila(int sila) {
	this->sila += sila;
}
void Organizm::setWiek(int wiek){
	this->wiek += wiek;
}
char Organizm::getSymbol() {
	return this->symbol;
}
Swiat* Organizm::getSwiat() {
	return this->swiat_t;
}