#pragma once
#include "Organizm.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
class Organizm;
class Swiat
{
	private:
		std::vector<Organizm*> organizmy;
		int szerokosc;
		int wysokosc;
		Organizm*** stworzMape(int szerokosc, int wysokosc);
		void SpawnOrganizmow();
	public:
		Organizm*** mapa;
		void WczytajSwiat();
		void ZapiszSwiat();
		void DodajDoOrganizmow(Organizm* organizm);
		void RysujLegende();
		void WykonajTure();
		void RysujSwiat();
		int getSzerokosc();
		int getWysokosc();
		Swiat(int sz, int wys, bool wczytaj);
		~Swiat();
};

