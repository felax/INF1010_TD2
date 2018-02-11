/********************************************
* Titre: Travail pratique #2 - Rayon.cpp
* Date: 25 janvier 2018
* Auteur: Timoth�e CHAUVIN
*******************************************/

#include "Rayon.h"

Rayon::Rayon(const string& cat) :
	categorie_{ cat }
{
}

Rayon::~Rayon()
{
	if (tousProduits_.capacity() > 0)
		tousProduits_.clear();
}

// Methodes d'acces
string Rayon::obtenirCategorie() const
{
	return categorie_;
}

vector<Produit*> Rayon::obtenirTousProduits() const
{
	return tousProduits_;
}

int Rayon::obtenirCapaciteProduits() const
{
	return tousProduits_.capacity();
}

int Rayon::obtenirNombreProduits() const
{
	return tousProduits_.size();
}

// Methodes de modification
void Rayon::modifierCategorie(const string& cat)
{
	categorie_ = cat;
}

Rayon* Rayon::operator+= (Produit* produit)
{
	tousProduits_.push_back(produit);
	return this;
}

ostream& operator<< (ostream& os, const Rayon& rayon){
	os << "Le rayon " << rayon.obtenirCategorie() << ": " << endl;
	for (int i = 0; i < rayon.obtenirNombreProduits(); i++) {
		cout << "----> " << *rayon.obtenirTousProduits()[i] << endl;
	}
	return os;
}

int Rayon::compterDoublons(const Produit* produit) const {
	int nDoublons = 0;
	for (int i = 0; i < this->tousProduits_.size(); i++) {
		if (*produit == *tousProduits_[i]){
			nDoublons++;
		}
	}
	return nDoublons;
}
