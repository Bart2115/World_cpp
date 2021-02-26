#include "Wilk.h"
Wilk::Wilk(Swiat* swiat, int x, int y) : Zwierze(swiat, 9, 5, 0, 'W',x, y, true) {};
Wilk::~Wilk(){
	//std::cout << "destruktor wilka\n";
}
Wilk* Wilk::Potomstwo(Swiat* swiat_t, int x, int y) {
	return new Wilk(swiat_t, x, y);
}