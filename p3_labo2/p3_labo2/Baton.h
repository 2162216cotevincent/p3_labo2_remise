#pragma once
#include "Sort.h"
#include <string>

using namespace std;

class Baton
{
private:
	std::string m_nomSort;
	Sort m_sortAttaque;
	Sort m_sortDefense;

public:

	/*
	 * Constructeur de la classe Baton
	 */
	Baton(std::string nom, Sort sortAttaque, Sort sortDefense);
	Baton();

	/*
	 * Permet de récupérer le nom du baton
	 */
	std::string getNom();

	/*
	 * Permet de récupérer le sort associé à l'attaque
	 */
	Sort getSortAttaque();

	/*
	 * Permet de récupérer le sort associé à la défense
	 */
	Sort getSortDefense();

	/*
	 * Permet d'afficher le sort
	 */
	std::string AfficherSorts();

};
