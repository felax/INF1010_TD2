/********************************************
* Titre: Travail pratique #2 - Rayon.cpp
* Date: 25 janvier 2018
* Auteur: Timoth�e CHAUVIN
*******************************************/

#include "Rayon.h"

Rayon::Rayon(const string& cat) :
	categorie_{ cat },
	tousProduits_{ nullptr }
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
	/*if (tousProduits_ != nullptr)
	{
		if (nombreProduits_ >= capaciteProduits_)
		{
			Produit ** temp;
			capaciteProduits_ += 5;
			temp = new Produit*[capaciteProduits_];
			for (int i = 0; i < nombreProduits_; i++)
				temp[i] = tousProduits_[i];
			delete[] tousProduits_;
			tousProduits_ = temp;

		}
		tousProduits_[nombreProduits_++] = produit;
	}
	else
	{
		capaciteProduits_ = 5;
		tousProduits_ = new Produit*[capaciteProduits_];
		tousProduits_[nombreProduits_++] = produit;
	}*/
}

ostream& operator<< (ostream& os, const Rayon& rayon){
	os << "Le rayon " << rayon.obtenirCategorie() << ": " << endl;
	for (int i = 0; i < rayon.obtenirNombreProduits(); i++) {
		cout << "----> ";
		cout << rayon.obtenirTousProduits()[i];
	}
	return os;
}

/*void Rayon::afficher() const
{
	cout << "Le rayon " << categorie_ << ": " << endl;
	for (int i = 0; i < nombreProduits_; i++) {
		cout << "----> ";
		tousProduits_[i]->afficher();
	}
}*/

int Rayon::compterDoublons(const Produit* produit) const{
	int taille = this->tousProduits_.size();
	int nDoublons = 0;
	for (int i = 0; i < taille; i++) {
		if (*produit == *tousProduits_[i]){
			nDoublons++;
		}
	}
}
