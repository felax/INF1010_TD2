/********************************************
* Titre: Travail pratique #2 - Produit.h
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timoth�e CHAUVIN
*******************************************/

#pragma once

#include <string>
#include <iostream>

using namespace std;

class Produit
{

public:
	Produit(const string& nom = "outil", int reference = 0, double prix = 0.0);

	string obtenirNom() const;
	int obtenirReference() const;
	double obtenirPrix() const;

	void modifierNom(const string& nom);
	void modifierReference(int reference);
	void modifierPrix(double prix);

	// TODO: Ajouter la surcharge de l'op�rateur >
	bool operator> (const Produit& produit) const;
	// TODO: Ajouter la surcharge de l'op�rateur <
	bool operator< (const Produit& produit) const;
	// TODO: Ajouter la surcharge de l'operateur ==
	bool operator== (const Produit& produit) const;
	// Entrer les parametres du produit >>
	void operator>> (const Produit& produit);
    // Affiche les caracteristiques du produit <<
	friend ostream& operator<< (ostream& os, const Produit& produit);
   
private:
	string nom_;
	int reference_;
    double prix_;
};
