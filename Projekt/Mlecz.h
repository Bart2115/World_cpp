#pragma once
#include "Roslina.h"
class Mlecz : public Roslina
{
	public:
		void Akcja() override;
		Mlecz* Potomstwo(Swiat* swiat_t, int x, int y) override;
		Mlecz(Swiat* swiat, int x, int y);
		~Mlecz();
};

