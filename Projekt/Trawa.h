#pragma once
#include "Roslina.h"
class Trawa: public Roslina
{
	public:
		Trawa* Potomstwo(Swiat* swiat_t, int x, int y) override;
		Trawa(Swiat* swiat, int x, int y);
		~Trawa();
};

