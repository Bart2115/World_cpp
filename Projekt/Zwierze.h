#pragma once
#include "Organizm.h"
class Zwierze : public Organizm
{	
	public:
		virtual void Akcja() override;
		virtual void Kolizja(Organizm* organizmAtakujacy) override;
		virtual void Rozmnazanie(Organizm* drugiRodzic, double prawdopodobienstwo) override;
		Zwierze(Swiat* swiat, int sila, int inicjatywa, int wiek, char symbol, int x, int y, bool czyZyje);
		virtual ~Zwierze() {};
};

