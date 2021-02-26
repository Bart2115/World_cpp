#pragma once
#include "Zwierze.h"
class Owca: public Zwierze
{
	public:
		Owca* Potomstwo(Swiat* swiat_t, int x, int y) override;
		Owca(Swiat* swiat, int x, int y);
		~Owca();
};

