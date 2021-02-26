#pragma once
#include "Zwierze.h"
class Lis: public Zwierze
{	
	private:
		bool dobryWech();
	public:
		void Akcja() override;
		Lis* Potomstwo(Swiat* swiat_t, int x, int y) override;
		Lis(Swiat* swiat, int x, int y);
		~Lis();
};

