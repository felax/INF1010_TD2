/********************************************
* Titre: Travail pratique #2 - Client.cpp
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothée CHAUVIN
* Modifié par: Nezha Zahri(1786454) et Félix Montminy(1903263)
* FICHIER:	    TP2
* DATE:        11/02/2018
* DESCRIPTION: Implémentation de la classe Client
**************************************************/


#include "Client.h"
/**
 * Constructeur par default
 * @param nom, prenom, identifiant, codePostal, date
 */
Client::Client(const string&  nom, const string& prenom, int identifiant, const string& codePostal, long date) :
	nom_		  { nom },
	prenom_		  { prenom },
	identifiant_  { identifiant },
	codePostal_	  { codePostal },
	dateNaissance_{ date },
	monPanier_    { nullptr }
{
}

/**
 * Destructeur par default
 * @param 
 */
Client::~Client()
{
	if (monPanier_ != nullptr)
		delete monPanier_;
}

/**
 * Constructeur de copie. Permet d'effectuer un "deep copy"
 * @param objetCopie	Objet Client a copier
 */
Client::Client(const Client& objetCopie )
	: nom_(objetCopie.nom_), prenom_(objetCopie.prenom_), identifiant_(objetCopie.identifiant_),
	codePostal_(objetCopie.codePostal_), dateNaissance_(objetCopie.dateNaissance_) ,monPanier_(nullptr)
{
	this->monPanier_ = new Panier(*(objetCopie.monPanier_));
	this->monPanier_->modifierTotalAPayer(objetCopie.monPanier_->obtenirTotalApayer());
	
}

/**
 * Methode d'acces nom
 * @param 
 */
string Client::obtenirNom() const
{
	return nom_;
}

/**
 * Methode d'acces prenom
 * @param 
 */
string Client::obtenirPrenom() const
{
	return prenom_;
}

/**
 * Methode d'acces identifiant
 * @param 
 */
int Client::obtenirIdentifiant() const
{
	return identifiant_;
}

/**
 * Methode d'acces code postal
 * @param 
 */
string Client::obtenirCodePostal() const
{
	return codePostal_;
}

/**
 * Methode d'acces date de naissance
 * @param 
 */
long Client::obtenirDateNaissance() const
{
	return dateNaissance_;
}

/**
 * Methode d'acces panier
 * @param 
 */
Panier * Client::obtenirPanier() const
{
	return monPanier_;
}

/**
 * Methode de modification nom
 * @param nom 	Nom a modifier
 */
void  Client::modifierNom(const string& nom)
{
	nom_ = nom;
}

/**
 * Methode de modification prenom
 * @param prenom 	Prenom a modifier
 */
void Client::modifierPrenom(const string& prenom)
{
	prenom_ = prenom;
}

/**
 * Methode de modification ientifiant
 * @param identifiant 	Identifiant a modifier
 */
void Client::modifierIdentifiant(int identifiant)
{
	identifiant_ = identifiant;
}

/**
 * Methode de modification code postal
 * @param codePostal 	Code postal a modifier
 */
void Client::modifierCodePostal(const string& codePostal)
{
	codePostal_ = codePostal;
}

/**
 * Methode de modification date de naissance
 * @param date 	Date a modifier
 */
void Client::modifierDateNaissance(long date)
{
	dateNaissance_ = date;
}

/**
 * Ajoute un produit au panier du client
 * @param *produit 	Pointeur vers le produit a jouter
 */
void Client::acheter(Produit * produit)
{
	if (monPanier_ == nullptr) {
		monPanier_ = new Panier();
	}
	*monPanier_ += produit;
}

/**
 * Appelle la fonction livrer de la classe panier et enleve le panier du client
 * @param 
 */
void Client::livrerPanier()
{
	monPanier_->livrer();
	delete monPanier_;
	monPanier_ = nullptr;
}

/**
 * Affiche le client et le contenu de son panier
 * @param os, client	ostream& et le Client a afficher
 */
ostream& operator<< (ostream& os, const Client& client)
{
	if (client.monPanier_ != nullptr) {
		cout << "Le panier de " << client.prenom_ << ": "
			<< endl;
		cout << *client.monPanier_;
	}
	else {
		cout << "Le panier de " << client.prenom_ << " est vide !" << endl;
	}

	return os;
}

/**
 * Remplace les attributs de l'objet par ceux du Client en argument
 * @param client	Le Client dont les attribus vont etre copies
 */
Client Client::operator= (Client& client) 
{
	this->nom_ = client.obtenirNom();
	this->prenom_ = client.obtenirPrenom();
	this->identifiant_ = client.obtenirIdentifiant();
	this->codePostal_ = client.obtenirCodePostal();
	this->dateNaissance_ = client.obtenirDateNaissance();
	this->monPanier_ = client.obtenirPanier();

	return client;
}

/**
 * Compare l'identifant du Client avec celui en parametre
 * @param id 	Indentifiant a comparer
 */
bool Client::operator== (const int id) const 
{
	bool match = false;
	if (this->obtenirIdentifiant() == id) {
		match = true;
	}
	return match;
}

/**
 * Compare l'identifant du Client avec celui en parametre (autre sens)
 * @param id, client 	Indentifiant a comparer et Client avec lequel le comparer
 */
bool operator== (const int id, const Client& client) 
{
	bool match = false;
	if (client.obtenirIdentifiant() == id) {
		match = true;
	}
	return match;
}
