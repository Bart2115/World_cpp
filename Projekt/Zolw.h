#pragma once
#include "Zwierze.h"
class Zolw: public Zwierze
{
	public:
		void Akcja() override;
		void Kolizja(Organizm* organizmAtakujacy) override;
		Zolw* Potomstwo(Swiat* swiat_t, int x, int y) override;
		Zolw(Swiat* swiat, int x, int y);
		~Zolw();
};

