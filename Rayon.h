/********************************************
* Titre: Travail pratique #2 -Rayon.h
* Date: 25 janvier 2018
* Auteur: Timoth�e CHAUVIN
*******************************************/

#pragma once

#include <string>
#include <vector>
#include "Produit.h"

using namespace std;

class Rayon
{

public:
	Rayon(const string& cat = "inconnu");
	~Rayon();

	string obtenirCategorie() const;
	vector<Produit*> obtenirTousProduits() const;
	int obtenirCapaciteProduits() const;
	int obtenirNombreProduits() const;

	void modifierCategorie(const string& cat);

	// TODO: Cette methode doit etre remplacee par la surchage de l'operateur +=
	Rayon* operator+= (Produit* produit);
	// TODO: Implermenter la methode compterDoublons
	int compterDoublons(const Produit* produit) const;
	// TODO: Cette methode doit �tre remplacee par la surcharge de l'op�rateur <<
	friend ostream& operator<< (ostream& os, const Rayon& rayon);

private:
	string categorie_;

	vector <Produit*> tousProduits_;
	// TODO: Remplacer ces attributs par un vecteur de la STL
	// Produit ** tousProduits_;
	// int capaciteProduits_;
	// int nombreProduits_;

};
