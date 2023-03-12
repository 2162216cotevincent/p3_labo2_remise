#ifndef MAGICIEN_H
#define MAGICIEN_H

#include <string>
#include "Baton.h"

using namespace std;

class Magicien
{
private:
	string m_nom;
	int m_vie;
	int m_mana;
	int m_bouclier;
	bool m_aJouer;
	Baton m_baton;

public:
	Magicien(string nom, Baton baton);
	~Magicien();
	string AfficherEtat();
	bool RecevoirAttaqueSurBouclier(int degats);
	void RecevoirAttaqueSurVie(int degats);
	void RecevoirSoins(int valeur);
	void RecevoirReparationBouclier(int valeur);
	bool EstVivant();
	void AssignerBaton(Baton baton);
	Baton GetBaton();
	void UtiliserSort(int type, Magicien& cible);

};

#endif
