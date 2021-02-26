#pragma once
#include "Roslina.h"
class Barszcz_Sosnowskiego : public Roslina
{
	public:
	void Kolizja(Organizm* Atakujacy) override;
	void Akcja() override;
	Barszcz_Sosnowskiego* Potomstwo(Swiat* swiat_t, int x, int y) override;
	Barszcz_Sosnowskiego(Swiat* swiat, int x, int y);
	~Barszcz_Sosnowskiego();
};

