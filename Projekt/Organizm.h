#pragma once
#include "Swiat.h"
#include <iostream>
class Swiat;
class Organizm
{	
	protected:
		int wiek;
		int sila;
		int inicjatywa;
		int polozenieX;
		int polozenieY;
		bool czyZyje;
		char symbol;
		Swiat* swiat_t;
	public:
		virtual void Akcja() = 0;
		virtual void Kolizja(Organizm* organizmAtakujacy) = 0;
		virtual bool czyWolneMiejsce();
		virtual int getWiek();
		virtual int getSila();
		virtual int getInicjatywa();
		virtual int getPolozenieX();
		virtual int getPolozenieY();
		virtual bool getCzyZyje();
		virtual void setCzyZyje(bool czyZyje);
		virtual void setSila(int sila);
		virtual void setWiek(int wiek);
		virtual char getSymbol();
		virtual Swiat* getSwiat();
		virtual void Rozmnazanie(Organizm* drugiRodzic, double prawdopodobienstwo) = 0;
		virtual Organizm* Potomstwo(Swiat* swiat_t, int x, int y) = 0;
		Organizm(Swiat* swiat, int sila, int inicjatywa, int wiek, char symbol, int x, int y, bool czyZyje);
		virtual ~Organizm() {};
};