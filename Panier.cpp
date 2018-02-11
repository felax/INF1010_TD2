/********************************************
* Titre: Travail pratique #2 - Panier.cpp
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothée CHAUVIN
*******************************************/

#include "Panier.h"

Panier::Panier() {
	totalAPayer_ =  0;
}

Panier::~Panier()
{
}

// methodes d'accès
vector<Produit*> Panier::obtenirContenuPanier()const
{
	return contenuPanier_;
}

int Panier::obtenirNombreContenu() const
{
	return contenuPanier_.size();
}

double Panier::obtenirTotalApayer() const
{
	return totalAPayer_;
}

void Panier::modifierTotalAPayer(double totalAPayer)
{
	totalAPayer_ = totalAPayer;
}

// méthodes de modification

// autres méthodes
Panier* Panier::operator+= (Produit * produit)
{
	contenuPanier_.push_back(produit);
	totalAPayer_ += produit->obtenirPrix();
	return this;
	/*if (nombreContenu_ >= capaciteContenu_)
	{
		Produit ** temp;
		capaciteContenu_ *= 2;
		temp = new Produit*[capaciteContenu_];
		for (int i = 0; i < nombreContenu_; i++)
			temp[i] = contenuPanier_[i];
		delete contenuPanier_;
		contenuPanier_ = temp;
	}
	contenuPanier_[nombreContenu_++] = prod;
	totalAPayer_ += prod->obtenirPrix();*/
}

void Panier::livrer()
{
	contenuPanier_.clear();
	totalAPayer_ = 0;
}

Produit * Panier::trouverProduitPlusCher()
{
	Produit* produitPlusCher = contenuPanier_[0];
	for (int i = 1; i < contenuPanier_.size(); i++) {
		if (contenuPanier_[i] > produitPlusCher) {
			produitPlusCher = contenuPanier_[i];
		}
	}
	return produitPlusCher;
}

ostream& operator<< (ostream& os, const Panier& panier)
{
	for (int i = 0; i < panier.contenuPanier_.size(); i++){
		os << panier.contenuPanier_[i];
	}
	os << "----> total a payer : " << panier.totalAPayer_ << endl;
	return os;
}
