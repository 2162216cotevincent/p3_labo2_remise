#pragma once
#include <string>

class Sort
{
private:
	std::string m_nom;
	std::string m_type;
	int m_dommage;

public:
	/*
	* Constructeur de la classe Sort
	*/
	Sort(std::string nom, std::string type, int dommage);

	Sort();

	/*
	* Retourne le nom du sort
	*/
	std::string getNom();

	/*
	* Retourne le type du sort
	*/
	std::string getType();

	/*
	* Retourne les dommages du sort
	*/
	int getDommage();
};
