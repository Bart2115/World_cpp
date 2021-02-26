#include "Trawa.h"
Trawa::Trawa(Swiat* swiat, int x, int y) : Roslina(swiat, 0, 0, 0, 'T', x, y, true, 0.3) {};
Trawa::~Trawa() {
	//std::cout << "destruktor trawy\n";
}
Trawa* Trawa::Potomstwo(Swiat* swiat_t, int x, int y) {
	return new Trawa(swiat_t, x, y);
}