#include "Owca.h"
Owca::Owca(Swiat* swiat, int x, int y) : Zwierze(swiat, 4, 4, 0, 'O', x, y, true) {};
Owca::~Owca() {
	//std::cout << "destruktor owcy\n";
}
Owca* Owca::Potomstwo(Swiat* swiat_t, int x, int y) {
	return new Owca(swiat_t, x, y);
}