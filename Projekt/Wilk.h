#pragma once
#include "Zwierze.h"
class Wilk : public Zwierze
{
	public:
		Wilk* Potomstwo(Swiat* swiat_t, int x, int y) override;
		Wilk(Swiat* swiat, int x, int y);
		~Wilk();
};

