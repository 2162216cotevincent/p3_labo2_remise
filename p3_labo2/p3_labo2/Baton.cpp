#pragma once
#include "Baton.h"
#include "Sort.h"
#include "Magicien.h"


/*
 * Constructeur de la classe Baton
 */
Baton::Baton(std::string nom, Sort sortAttaque, Sort sortDefense) : m_nomSort(nom), m_sortAttaque(sortAttaque), m_sortDefense(sortDefense) 
{
	m_nomSort = m_sortAttaque.getNom() + " de " + m_sortDefense.getNom();
}

Baton::Baton() : m_nomSort{}, m_sortAttaque{ }, m_sortDefense{ } {};

/*
 * Permet de récupérer le nom du baton
 */
std::string Baton::getNom()
{
	return m_nomSort;
}

/*
 * Permet de récupérer le sort associé à l'attaque
 */
Sort Baton::getSortAttaque()
{
	return m_sortAttaque;
}

/*
 * Permet de récupérer le sort associé à la défense
 */
Sort Baton::getSortDefense()
{
	return m_sortDefense;
}

/*
 * Afficher les informations du baton et des sorts
 */
std::string Baton::AfficherSorts()
{
	std::string reponse;
	reponse.append("Baton: ");
	reponse.append(m_nomSort);
	reponse.append(": \n");
	reponse.append("Sort attaque: ");
	reponse.append(m_sortAttaque.getNom());
	reponse.append("\n");
	reponse.append("Sort defense: ");
	reponse.append(m_sortDefense.getNom());
	reponse.append("\n");
	reponse.append("\n");

	return reponse;

}


