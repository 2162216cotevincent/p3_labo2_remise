#include <iostream>
#include "Magicien.h"
#include "Utilitaires.h"
#include "Sort.h"
#include "Baton.h"

using namespace std;

int main()
{
	Sort sortAttaque[2]{ Sort("Incinerateur","attaque", 20), Sort("Foudre","attaque", -10) };
	Sort sortDefense[2]{ Sort("Guerison","défense", 100), Sort("Protection","défense", -50) };

	Magicien joueur("Joueur", Baton("Baton joueur", sortAttaque[generationNombre(0, 2)], sortDefense[generationNombre(0, 2)]));
	Magicien ennemi("Ennemi", Baton("Baton ennemi", sortAttaque[generationNombre(0, 2)], sortDefense[generationNombre(0, 2)]));

	bool partieEnCours = true;

	cout << "Duel de mages! \n\n";
	cout << joueur.AfficherEtat();
	cout << ennemi.AfficherEtat();

	system("pause");

	int commence = generationNombre(1, 3);

	while (partieEnCours)
	{
		if (commence == 1)
		{
			cout << "Le joueur commence!";
			cout << joueur.GetBaton().AfficherSorts();

			bool choixValide = false;
			cout << "Appuyez sur 'A' pour utiliser le sort d'attaque, et sur 'D' pour utiliser le sort de défense.";
			string choix = "";

			while (!choixValide)
			{
				cin >> choix;

				if (choix == "a")
				{
					joueur.UtiliserSort(0, ennemi);
					choixValide = true;
				}
				else if (choix == "d")
				{
					joueur.UtiliserSort(1, joueur);
					choixValide = true;
				}
				else
				{
					cout << "Choix invalide, réessayez";
				}
				cin.ignore();
				choix = "";
			}

			int choixEnnemi = generationNombre(1, 3);
			if (choixEnnemi == 1)
			{
				ennemi.UtiliserSort(0, joueur);
			}
			else
			{
				ennemi.UtiliserSort(1, ennemi);
			}
		}
		else
		{
			int choixEnnemi = generationNombre(1, 3);
			if (choixEnnemi == 1)
			{
				ennemi.UtiliserSort(0, joueur);
			}
			else
			{
				ennemi.UtiliserSort(1, ennemi);
			}
			cout << "Le joueur commence! \n";
			cout << joueur.GetBaton().AfficherSorts();
			cout << "Appuyez sur 'A' pour utiliser le sort d'attaque, et sur 'D' pour utiliser le sort de defense.";

			bool choixValide = false;
			string choix = "";

			while (!choixValide)
			{
				cin >> choix;

				if (choix == "a")
				{
					joueur.UtiliserSort(0, ennemi);
					choixValide = true;
				}
				else if (choix == "d")
				{
					joueur.UtiliserSort(1, joueur);
					choixValide = true;
				}
				else
				{
					cout << "Choix invalide, réessayez";
				}
				cin.ignore();
				choix = "";
			}
		}

		if (joueur.EstVivant() == false)
		{
			cout << "Vous avez perdu!";
			cout << joueur.AfficherEtat();
			cout << ennemi.AfficherEtat();
			partieEnCours = false;
		}
		if (ennemi.EstVivant() == false)
		{
			cout << "Vous avez gagne!";
			cout << joueur.AfficherEtat();
			cout << ennemi.AfficherEtat();
			partieEnCours = false;
		}
		cout << "Duel de mages! \n\n";
		cout << joueur.AfficherEtat();
		cout << ennemi.AfficherEtat();
	}
}




