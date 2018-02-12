/********************************************
* Titre: Travail pratique #2 - Rayon.cpp
* Date: 25 janvier 2018
* Auteur: Timoth�e CHAUVIN
* Modifié par: Nezha Zahri(1786454) et Félix Montminy(1903263)
* FICHIER:	    TP2
* DATE:        11/02/2018
* DESCRIPTION: Implémentation de la classe Rayon
*******************************************/

#include "Rayon.h"

/**
 * Constructeur par default
 * @param cat	Nom de la categorie du rayon a initializer
 */
Rayon::Rayon(const string& cat) :
	categorie_{ cat }
{
}

/**
 * Destructeur par default. Vide le vecteur s'il existe
 * @param 
 */
Rayon::~Rayon()
{
	if (tousProduits_.capacity() > 0)
		tousProduits_.clear();
}

/**
 * Methode d'acces categorie
 * @param 
 */
string Rayon::obtenirCategorie() const
{
	return categorie_;
}

/**
 * Methode d'acces du vecteur tousProduits_
 * @param 
 */
vector<Produit*> Rayon::obtenirTousProduits() const
{
	return tousProduits_;
}

/**
 * Methode d'acces capacite du vecteur 
 * @param 
 */
int Rayon::obtenirCapaciteProduits() const
{
	return tousProduits_.capacity();
}

/**
 * Methode d'acces nombre de produits dans le vecteur
 * @param 
 */
int Rayon::obtenirNombreProduits() const
{
	return tousProduits_.size();
}

/**
 * Methode de modification categorie
 * @param cat	String de categorie 
 */
void Rayon::modifierCategorie(const string& cat)
{
	categorie_ = cat;
}

/**
 * Ajoute un pointeur vers un Produit au vecteur du rayon
 * @param produit	pointeur vers le produit ajouter
 */
Rayon* Rayon::operator+= (Produit* produit)
{
	tousProduits_.push_back(produit);
	return this;
}

/**
 * Affiche le contenu du rayon
 * @param os, rayon		output stream et Rayon a afficher
 */
ostream& operator<< (ostream& os, const Rayon& rayon){
	os << "Le rayon " << rayon.obtenirCategorie() << ": " << endl;
	for (int i = 0; i < rayon.obtenirNombreProduits(); i++) 
		cout << "----> " << *rayon.obtenirTousProduits()[i];

	return os;
}

/**
 * Compte le nombre de produit identiques a celui rentrer en parametre dans le rayon
 * @param produit	Pointeur vers le produit 
 */
int Rayon::compterDoublons(const Produit* produit) const {
	int nDoublons = 0;
	for (int i = 0; i < this->tousProduits_.size(); i++) {
		if (*produit == *tousProduits_[i]){
			nDoublons++;
		}
	}
	return nDoublons;
}
