/********************************************
* Titre: Travail pratique #2 - Panier.h
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothée CHAUVIN
* Modifié par: Nezha Zahri(1786454) et Félix Montminy(1903263)
* FICHIER:	    TP2
* DATE:        11/02/2018
* DESCRIPTION: Description de la classe Panier
*******************************************/

#pragma once

#include <string>
#include <vector>
#include "Produit.h"

using namespace std;

class Panier
{

public:
	// constructeur et destructur par default
	Panier();
	~Panier();

	// methodes d'acces
	vector <Produit*>	obtenirContenuPanier()	const;
	int					obtenirNombreContenu()	const;
	double				obtenirTotalApayer()	const;

	// methode de modification
	void modifierTotalAPayer(double totalAPayer);

	// Methode d'ajout de produit au panier
	Panier* operator+= (Produit * produit);
	// Methode pour livrer le panier
	void livrer();

	// Trouve le produit le plus cher dans le panier
	Produit* trouverProduitPlusCher();
	
	// Affiche le contenu du panier
	friend ostream& operator<< (ostream& os, const Panier& panier);

private:
	double			  totalAPayer_;
	vector <Produit*> contenuPanier_;
};
