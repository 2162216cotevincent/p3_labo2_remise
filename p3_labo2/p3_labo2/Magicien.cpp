#include "Magicien.h"

using namespace std;

Magicien::Magicien(string nom, Baton baton)
{
	m_nom = nom;
	m_vie = 50;
	m_mana = 50;
	m_bouclier = 0;
	m_baton = baton;
	m_aJouer = false;
}

Magicien::~Magicien()
{
}

string Magicien::AfficherEtat()
{
	string reponse;
	reponse.append(m_nom);
	reponse.append(": \n");
	reponse.append("Vie: ");
	reponse.append(to_string(m_vie));
	reponse.append("\n");
	reponse.append("Mana: ");
	reponse.append(to_string(m_mana));
	reponse.append("\n");
	reponse.append("Bouclier: ");
	reponse.append(to_string(m_bouclier));
	reponse.append("\n");
	reponse.append("\n");

	return reponse; 
}

bool Magicien::RecevoirAttaqueSurBouclier(int degats)
{
	if (m_bouclier >= 0)
	{
		m_bouclier -= degats;
		if (m_bouclier < 0)
		{
			m_vie += m_bouclier;
			m_bouclier = 0;
		}
		return true; // L'attaque a été absorbée par le bouclier
	}
	return false; // L'attaque n'a pas été absorbée par le bouclier
}

void Magicien::RecevoirAttaqueSurVie(int degats)
{
	m_vie -= degats;
}

void Magicien::RecevoirSoins(int valeur)
{
	if (valeur + m_vie >= 100)
	{
		m_vie = 100;
	}
	else
	{
		m_vie += valeur;
	}
}

void Magicien::RecevoirReparationBouclier(int valeur)
{
	if (valeur > 0 && valeur + m_bouclier >= 50)
	{
		m_bouclier = 50;
	}
	else if (valeur > 0)
	{
		m_bouclier += valeur;
	}
}

bool Magicien::EstVivant() 
{
	return m_vie > 0;

}

void Magicien::AssignerBaton(Baton baton)
{
	m_baton = baton;
}

Baton Magicien::GetBaton()
{
	return m_baton;
}

/*
 * Utilisation des sorts
 */
void Magicien::UtiliserSort(int type, Magicien& cible)
{
	if (type == 0)
	{
		if (m_mana >= 10)
		{
			if (m_baton.getSortAttaque().getDommage() > 0)
			{
				cible.RecevoirAttaqueSurBouclier(m_baton.getSortAttaque().getDommage());
			}
			else
			{
				cible.RecevoirAttaqueSurVie(m_baton.getSortAttaque().getDommage() * -1); //On retransforme en positif
			}
			m_mana -= 10;
			m_aJouer = true; // Le joueur a joué ce tour-ci
		}
	}
	else if (type == 1)
	{
		if (m_mana >= 10)
		{
			if (m_baton.getSortDefense().getDommage() < 0)
			{
				cible.RecevoirSoins(m_baton.getSortDefense().getDommage());
			}
			else
			{
				cible.RecevoirReparationBouclier(m_baton.getSortDefense().getDommage() * -1);
			}
			m_mana -= 10;
			m_aJouer = true; // Le joueur a joué ce tour-ci
		}
	}
}


