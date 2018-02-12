/********************************************
* Titre: Travail pratique #2 -Rayon.h
* Date: 25 janvier 2018
* Auteur: Timoth�e CHAUVIN
* Modifié par: Nezha Zahri(1786454) et Félix Montminy(1903263)
* FICHIER:	    TP2
* DATE:        11/02/2018
* DESCRIPTION: Description de la classe Rayon
*******************************************/

#pragma once

#include <string>
#include <vector>
#include "Produit.h"

using namespace std;

class Rayon
{

public:

	// Constructeur et destructeur par default
	Rayon(const string& cat = "inconnu");
	~Rayon();

	// Methodes d'acces
	string			 obtenirCategorie()			const;
	vector<Produit*> obtenirTousProduits()		const;
	int				 obtenirCapaciteProduits()	const;
	int				 obtenirNombreProduits()	const;

	// Methode de modification
	void modifierCategorie(const string& cat);

	// Ajoute un produit au rayon
	Rayon* operator+= (Produit* produit);
	
	// Compte le nombre de produit identiques dans un rayon
	int compterDoublons(const Produit* produit) const;
	
	// Affiche les produits dans le rayon
	friend ostream& operator<< (ostream& os, const Rayon& rayon);

private:
	string			  categorie_;
	vector <Produit*> tousProduits_;
};
