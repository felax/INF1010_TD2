/********************************************
* Titre: Travail pratique #2 - Panier.cpp
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothée CHAUVIN
* Modifié par: Nezha Zahri(1786454) et Félix Montminy(1903263)
* FICHIER:	    TP2
* DATE:        11/02/2018
* DESCRIPTION: Implémentation de la classe Panier
**************************************************/


#include "Panier.h"

/**
 * Constructeur par default
 * @param 
 */
Panier::Panier() {
	totalAPayer_ =  0;
}

/**
 * Destructeur par default
 * @param 
 */
Panier::~Panier()
{
}

/**
 * Methode d'acces contenu du panier
 * @param 
 */
vector<Produit*> Panier::obtenirContenuPanier()const
{
	return contenuPanier_;
}

/**
 * Methode d'acces nombre de produits contenu dans le panier
 * @param 
 */
int Panier::obtenirNombreContenu() const
{
	return contenuPanier_.size();
}

/**
 * Methode d'acces total a payer
 * @param 
 */
double Panier::obtenirTotalApayer() const
{
	return totalAPayer_;
}

/**
 * Methode de modification total a payer
 * @param totalAPayer	Double representant le montant a payer
 */
void Panier::modifierTotalAPayer(double totalAPayer)
{
	totalAPayer_ = totalAPayer;
}


/**
 * Ajoute un pointeur vers un Produit au panier
 * @param produit	Pointeur vers le produit a ajouter
 */
Panier* Panier::operator+= (Produit * produit)
{
	contenuPanier_.push_back(produit);
	totalAPayer_ += produit->obtenirPrix();
	return this;
	
}

/**
 * Vide le vecteur contenuPanier_ et reinitialize le total
 * @param 
 */
void Panier::livrer()
{
	contenuPanier_.clear();
	totalAPayer_ = 0;
}

/**
 * Trouve le produit le plus cher dans le Panier (les egalites sont resolues au hazard)
 * @param 
 */
Produit* Panier::trouverProduitPlusCher()
{
	Produit* produitPlusCher = new Produit(*contenuPanier_[0]);
	for (unsigned int i = 1; i < contenuPanier_.size(); i++) 
		if (contenuPanier_[i]->obtenirPrix() > produitPlusCher->obtenirPrix()) 
			produitPlusCher = contenuPanier_[i];

	return produitPlusCher;
}

/**
 * Affiche le contenu du panier
 * @param os, panier	Le output stream ainsi que le Panier a afficher
 */
ostream& operator<< (ostream& os, const Panier& panier)
{
	for (unsigned int i = 0; i < panier.contenuPanier_.size(); i++){
		os << *(panier.contenuPanier_[i]);
	}
	os << "----> total a payer : " << panier.totalAPayer_ << endl;
	return os;
}
