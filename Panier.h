/********************************************
* Titre: Travail pratique #2 - Panier.h
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothée CHAUVIN
*******************************************/

#pragma once

#include <string>
#include <vector>
#include "Produit.h"

using namespace std;

class Panier
{

public:
	// TODO: Noubliez pas de retirer la capacite et donc transformer ce constructeur en constructeur par default
	Panier(int capacite);
	~Panier();

	Produit **  obtenirContenuPanier()const;
	int obtenirNombreContenu() const;
	double obtenirTotalApayer() const;

	void modifierTotalAPayer(double totalAPayer);

	// TODO: Adapter l'implementation de ces deux methode pour les rendre compatibles avec le nouveau vecteur
	void ajouter(Produit * prod);
	void livrer();

	// TODO: Implementez la methode qui retourne le produit le plus cher du panier
	Produit* trouverProduitPlusCher();
	// TODO: Cette methode doit être remplacée par la surcharge de l'opérateur <<
	void afficher() const;

private:
	double totalAPayer_;

	// TODO: Remplacer ces attributs par un vecteur de la STL
	Produit ** contenuPanier_;
	int  nombreContenu_;
	int capaciteContenu_;

};
