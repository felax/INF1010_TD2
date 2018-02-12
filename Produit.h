/********************************************
* Titre: Travail pratique #2 - Produit.h
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timoth�e CHAUVIN
* Modifié par: Nezha Zahri(1786454) et Félix Montminy(1903263)
* FICHIER:	    TP2
* DATE:        11/02/2018
* DESCRIPTION: Description de la classe Produit
*******************************************/

#pragma once

#include <string>
#include <iostream>

using namespace std;

class Produit
{

public:

	// Constructeur par default
	Produit(const string& nom = "outil", int reference = 0, double prix = 0.0);

	// Methodes d'acces
	string	obtenirNom()		 const;
	int		obtenirReference()	 const;
	double	obtenirPrix()		 const;

	// Methodes de modification
	void modifierNom(const string& nom);
	void modifierReference(int reference);
	void modifierPrix(double prix);

	// Compare la capiciter de 2 produits
	bool operator> (const Produit& produit) const;
	bool operator< (const Produit& produit) const;
	
	// Compare 2 produits
	bool operator== (const Produit& produit) const;
	
	// Affiche les attributs d'un produit
	friend istream& operator>> (istream& is, Produit& produit);
   
	// Affiche les caracteristiques du produit 
	friend ostream& operator<< (ostream& os, const Produit&);
   
private:
	string	nom_;
	int		reference_;
    double	prix_;
};
