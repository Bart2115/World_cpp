#pragma once
#include "Zwierze.h"
class Antylopa : public Zwierze
{
	private:
		void Ucieczka();
	public:
		void Akcja() override;
		void Kolizja(Organizm* organizmAtakujacy) override;
		Antylopa* Potomstwo(Swiat* swiat_t, int x, int y) override;
		Antylopa(Swiat* swiat, int x, int y);
		~Antylopa();
};

