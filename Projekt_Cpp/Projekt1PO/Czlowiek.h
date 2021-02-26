#pragma once
#include "Zwierze.h"
class Czlowiek: public Zwierze
{
	private:
		int PozostalyCzasZdolnosci, CooldownZdolnosci;
		bool czyAktywnaZdolnosc;
		void Niesmiertelnosc();
		bool czyNajslabszy();
		void AktywowanieSuperUmiejetnosci();
	public:
		void Akcja() override;
		void Kolizja(Organizm* atakujacy) override;
		void czyNapewnoSmierc();
		bool getCzyAktywnaZdolnosc();
		int getCooldownZdolnosc();
		Organizm* Potomstwo(Swiat* swiat_t, int x, int y) override { return NULL; };
		Czlowiek(Swiat* swiat, int x, int y);
		~Czlowiek() {};
};

