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

Client::Client(const string&  nom, const string& prenom, int identifiant, const string& codePostal, long date) :
	nom_		  { nom },
	prenom_		  { prenom },
	identifiant_  { identifiant },
	codePostal_	  { codePostal },
	dateNaissance_{ date },
	monPanier_    { nullptr }
{
}

Client::~Client()
{
	if (monPanier_ != nullptr)
		delete monPanier_;
}

//Constructeur de copie
Client::Client(const Client& objetCopie )
	: nom_(objetCopie.nom_), prenom_(objetCopie.prenom_), identifiant_(objetCopie.identifiant_),
	codePostal_(objetCopie.codePostal_), dateNaissance_(objetCopie.dateNaissance_) ,monPanier_(nullptr)
{
	this->monPanier_ = new Panier(*(objetCopie.monPanier_));
	this->monPanier_->modifierTotalAPayer(objetCopie.monPanier_->obtenirTotalApayer());
	
}

// Methodes d'acces
string Client::obtenirNom() const
{
	return nom_;
}

string Client::obtenirPrenom() const
{
	return prenom_;
}

int Client::obtenirIdentifiant() const
{
	return identifiant_;
}

string Client::obtenirCodePostal() const
{
	return codePostal_;
}

long Client::obtenirDateNaissance() const
{
	return dateNaissance_;
}

Panier * Client::obtenirPanier() const
{
	return monPanier_;
}

// Methodes de modification
void  Client::modifierNom(const string& nom)
{
	nom_ = nom;
}

void Client::modifierPrenom(const string& prenom)
{
	prenom_ = prenom;
}

void Client::modifierIdentifiant(int identifiant)
{
	identifiant_ = identifiant;
}

void Client::modifierCodePostal(const string& codePostal)
{
	codePostal_ = codePostal;
}

void Client::modifierDateNaissance(long date)
{
	dateNaissance_ = date;
}

// Autres méthodes
void Client::acheter(Produit * produit)
{
	if (monPanier_ == nullptr) {
		monPanier_ = new Panier();
	}
	*monPanier_ += produit;
}

void Client::livrerPanier()
{
	monPanier_->livrer();
	delete monPanier_;
	monPanier_ = nullptr;
}

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

Client Client::operator= (Client& client) { //p-e il y a une facons plus elegante de faire ca
	this->nom_ = client.obtenirNom();
	this->prenom_ = client.obtenirPrenom();
	this->identifiant_ = client.obtenirIdentifiant();
	this->codePostal_ = client.obtenirCodePostal();
	this->dateNaissance_ = client.obtenirDateNaissance();
	this->monPanier_ = client.obtenirPanier();

	return client;
}

bool Client::operator== (const int id) const {
	bool match = false;
	if (this->obtenirIdentifiant() == id) {
		match = true;
	}
	return match;
}

bool operator== (const int id, const Client& client) {
	bool match = false;
	if (client.obtenirIdentifiant() == id) {
		match = true;
	}
	return match;
}
