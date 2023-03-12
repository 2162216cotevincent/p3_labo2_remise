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
	 * Permet de r�cup�rer le nom du baton
	 */
	std::string getNom();

	/*
	 * Permet de r�cup�rer le sort associ� � l'attaque
	 */
	Sort getSortAttaque();

	/*
	 * Permet de r�cup�rer le sort associ� � la d�fense
	 */
	Sort getSortDefense();

	/*
	 * Permet d'afficher le sort
	 */
	std::string AfficherSorts();

};
