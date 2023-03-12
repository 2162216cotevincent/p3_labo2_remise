#pragma once
#include "Sort.h"

/*
 * Constructeur de la classe Sort
 */
Sort::Sort(std::string nom, std::string type, int dommage) : m_nom(nom), m_type(type), m_dommage(dommage) {}

Sort::Sort() : m_nom{}, m_type{ }, m_dommage{ } {};

/*
 * Retourne le nom du sort
 */
std::string Sort::getNom()
{
	return m_nom;
}

/*
 * Retourne le type du sort
 */
std::string Sort::getType()
{
	return m_type;
}

/*
 * Retourne les dommages du sort
 */
int Sort::getDommage()
{
	return m_dommage;
}
