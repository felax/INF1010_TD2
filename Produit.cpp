/********************************************
* Titre: Travail pratique #2 - Produit.cpp
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothee CHAUVIN
* Modifi� par: Nezha Zahri(1786454) et F�lix Montminy(1903263)
* FICHIER:	    TP2
* DATE:        11/02/2018
* DESCRIPTION: Impl�mentation de la classe Produit
*******************************************/

#include "Produit.h"

/**
 * Constructeur par default. 
 * @param nom, reference, prix	Les attributs a initializer 
 */
Produit::Produit(const string& nom, int reference, double prix) :
	nom_{ nom },
	reference_{ reference },
	prix_{ prix }
{ }

/**
 * Methode d'acces nom
 * @param 
 */
string Produit::obtenirNom() const{
	return nom_;
}

/**
 * Methode d'acces reference
 * @param 
 */
int Produit::obtenirReference() const{
	return reference_;
}

/**
 * Methode d'acces prix
 * @param 
 */
double Produit::obtenirPrix() const{
	return prix_;
}


/**
 * Methode de modification nom
 * @param nom	String du nom a modifier
 */
void Produit::modifierNom(const string& nom){
	nom_ = nom;
}

/**
 * Methode de modification reference
 * @param reference 	Int de la reference a ajouter
 */
void Produit::modifierReference(int reference){
	reference_ = reference;
}

/**
 * Methode de modification prix
 * @param prix	double prix a modifier
 */
void Produit::modifierPrix(double prix){
	prix_ = prix;
}

/**
 * Verifi si le prix de l'objet a droite est plus petit que celui a gauche
 * @param produit	Produit a comparer
 */
bool Produit::operator< (const Produit& produit) const
{
	bool smaller = false;

	if (prix_ < produit.prix_)
		smaller = true;

	return smaller;
}

/**
 * Verifi si le prix de l'objet a droite est plus grand que celui a gauche
 * @param produit	Produit a comparer
 */
bool Produit::operator> (const Produit& produit) const
{
	bool bigger = false;

	if (prix_ > produit.prix_)
		bigger = true;
	
	else 
		return bigger; 
}

/**
 * Verifi si 2 produits sont identiques
 * @param produit	Produit a comparer
 */
bool Produit::operator== (const Produit& produit) const
{
	bool same = false;

	if (nom_ == produit.nom_ && 
	reference_ == produit.reference_ && 
	prix_ == produit.prix_) 
		same = true;

	return same;
}

/**
 * Prend en input les attributs d'un produit
 * @param produit	Produit dont les attributs sont a modifier
 */
istream& operator>> (istream& is, Produit& produit)
{
	is 	>> produit.nom_
		>> produit.reference_
		>> produit.prix_;
	return is;
}

/**
 * Affiche les attributs du Produit
 * @param produit	Produit a afficher
 */
ostream& operator<< (ostream& os, const Produit& produit)
{
	os << "nom : " << produit.obtenirNom()
		<< "\t ref : " << produit.obtenirReference()
		<< "\t prix : " << produit.obtenirPrix() << endl;
	return os;
}
