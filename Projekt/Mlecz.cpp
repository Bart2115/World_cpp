#include "Mlecz.h"
Mlecz::Mlecz(Swiat* swiat, int x, int y) : Roslina(swiat, 0, 0, 0, 'M', x, y, true, 0.2) {};
Mlecz::~Mlecz() {
	//std::cout << "destruktor mlecza\n";
}
void Mlecz::Akcja() {
	for (int i = 0; i < 3; ++i) {
		Rozmnazanie(NULL, this->prawdopodobienstwoRozsienia);
	}
}
Mlecz* Mlecz::Potomstwo(Swiat* swiat_t, int x, int y) {
	return new Mlecz(swiat_t, x, y);
}