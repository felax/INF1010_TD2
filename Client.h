/********************************************
* Titre: Travail pratique #2 - Client.h
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothée CHAUVIN
* Modifié par: Nezha Zahri(1786454) et Félix Montminy(1903263)
* FICHIER:	    TP2
* DATE:        11/02/2018
* DESCRIPTION: Définition de la classe Client
**************************************************/


#pragma once

#include <string>
#include "Panier.h"

using namespace std;

class Client
{

public:
	Client(const string&  nom, const string& prenom, int identifiant, const string& codePostal, long date);
	~Client();
	Client(const Client& objetCopie);

	// Methodes d'acces
	string	obtenirNom()			const;
	string	obtenirPrenom()			const;
	int		obtenirIdentifiant()	const;
	string	obtenirCodePostal()		const;
	long	obtenirDateNaissance()  const;
	Panier* obtenirPanier()			const;

	// Methodes de modification
	void modifierNom(const string& nom);
	void modifierPrenom(const string& prenom);
	void modifierIdentifiant(int identifiant);
	void modifierCodePostal(const string& codePostal);
	void modifierDateNaissance(long date);

	// Autres methodes
	void acheter(Produit * produit);
	void livrerPanier();

	// Remplace les attributs de l'objet par celui a droite
	Client operator= (Client& client);
	
	// Compare un client avec un identifiant, return un bool
	bool operator== (const int id) const;
	friend bool operator== (const int id, const Client& client);
	
	// Affiche le client et le contenu de son panier
	friend ostream& operator<< (ostream& os, const Client& client);

private:
	string 	 nom_;
	string	 prenom_;
	int		 identifiant_;
	string	 codePostal_;
	long	 dateNaissance_;
	Panier*  monPanier_;

};
