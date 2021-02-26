#pragma once
#include "Organizm.h"
class Roslina: public Organizm
{
	protected:
		double prawdopodobienstwoRozsienia;
	public:
		virtual void Akcja() override;
		virtual void Kolizja(Organizm* organizmAtakujacy) override;
		virtual void Rozmnazanie(Organizm* drugiRodzic, double prawdopodobienstwo) override;
		Roslina(Swiat* swiat, int sila, int inicjatywa, int wiek, char symbol, int x, int y, bool czyZyje, double prawdopodobienstwoRozsienia);
		virtual ~Roslina() {};
};

