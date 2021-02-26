#include "Guarana.h"
Guarana::Guarana(Swiat* swiat,int x, int y) : Roslina(swiat, 0, 0, 0, 'G', x, y, true, 0.2) {};
Guarana::~Guarana() {
	//std::cout << "destruktor guarany\n";
}
void Guarana::Kolizja(Organizm* Atakujacy) {
	std::cout << this->symbol << " umiera w obronie przez " << Atakujacy->getSymbol() << "\n";
	this->czyZyje = false;
	this->swiat_t->mapa[this->polozenieY][this->polozenieX] = NULL;
	Atakujacy->setSila(3);
}
Guarana* Guarana::Potomstwo(Swiat* swiat_t, int x, int y) {
	return new Guarana(swiat_t, x, y);
}