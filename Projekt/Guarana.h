#pragma once
#include "Roslina.h"
class Guarana : public Roslina
{
	public:
		void Kolizja(Organizm* Atakujacy) override;
		Guarana* Potomstwo(Swiat* swiat_t, int x, int y) override;
		Guarana(Swiat* swiat, int x, int y);
		~Guarana();
};

