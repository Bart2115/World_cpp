#include "Wilcze_Jagody.h"
Wilcze_Jagody::Wilcze_Jagody(Swiat* swiat, int x, int y) : Roslina(swiat, 99, 0, 0, 'J', x, y, true, 0.2) {};
Wilcze_Jagody::~Wilcze_Jagody() {
	//std::cout << "destruktor wilczych jagod\n";
}
void Wilcze_Jagody::Kolizja(Organizm* Atakujacy) {
	std::cout << this->symbol << " i " << Atakujacy->getSymbol() << " umieraja w konfrontacji\n";
	this->czyZyje = false;
	this->swiat_t->mapa[this->polozenieY][this->polozenieX] = NULL;
	Atakujacy->setCzyZyje(false);
	Atakujacy->getSwiat()->mapa[Atakujacy->getPolozenieY()][Atakujacy->getPolozenieX()] = NULL;
}
Wilcze_Jagody* Wilcze_Jagody::Potomstwo(Swiat* swiat_t, int x, int y) {
	return new Wilcze_Jagody(swiat_t, x, y);
}