/********************************************
* Titre: Travail pratique #2 - Produit.cpp
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothee CHAUVIN
*******************************************/

#include "Produit.h"

Produit::Produit(const string& nom, int reference, double prix) :
	nom_{ nom },
	reference_{ reference },
	prix_{ prix }
{ }

// Methodes d'acces
string Produit::obtenirNom() const{
	return nom_;
}

int Produit::obtenirReference() const{
	return reference_;
}

double Produit::obtenirPrix() const{
	return prix_;
}


// Methodes de modification
void Produit::modifierNom(const string& nom){
	nom_ = nom;
}

void Produit::modifierReference(int reference){
	reference_ = reference;
}

void Produit::modifierPrix(double prix){
	prix_ = prix;
}

bool Produit::operator< (const Produit& produit) const{
	bool smaller = false;

	if (prix_ < produit.prix_){
		smaller = true;
	}
	return smaller;
}

bool Produit::operator> (const Produit& produit) const{
	bool bigger = false;

	if (prix_ > produit.prix_){
		bigger = true;
	}
	return bigger;
}

bool Produit::operator== (const Produit& produit) const{
	bool same = false;

	if (nom_ == produit.nom_ && 
	reference_ == produit.reference_ && 
	prix_ == produit.prix_) {
		same = true;
	}
	return same;
}

istream& operator>> (istream& is, Produit& produit){
	is 	>> produit.nom_
		>> produit.reference_
		>> produit.prix_;
	return is;
}

ostream& operator<< (ostream& os, const Produit& produit){
	os 	<< "nom : " << produit.obtenirNom()
		<< "\t ref : " << produit.obtenirReference()
		<< "\t prix : " << produit.obtenirPrix();
	return os;
}
