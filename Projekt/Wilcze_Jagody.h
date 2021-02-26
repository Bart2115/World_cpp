#pragma once
#include "Roslina.h"
class Wilcze_Jagody : public Roslina
{
	public:
		void Kolizja(Organizm* Atakujacy) override;
		Wilcze_Jagody* Potomstwo(Swiat* swiat_t, int x, int y) override;
		Wilcze_Jagody(Swiat* swiat, int x, int y);
		~Wilcze_Jagody();
};

