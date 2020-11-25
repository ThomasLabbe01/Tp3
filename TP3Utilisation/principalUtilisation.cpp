/**
 * \file ProgrammePrincipal.cpp
 * \brief Programme principal du TP3
 * \author Thomas Labbe
 * \version 1.0 sans contrat
 */

#include "Date.h"
#include "Personne.h"
#include "Adresse.h"
#include "Circonscription.h"
#include "Electeur.h"
#include "Candidat.h"
#include "VerificationFormat.h"


#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace util;
using namespace elections;


int main()
{

	//Inscription du deputeSortant


	string prenomDepute;
	string nomDepute;
	long jour_de_naissanceDepute;
	long mois_de_naissanceDepute;
	long annee_de_naissanceDepute;
	string nasDepute;
	int numero_civicDepute;
	string nom_rueDepute;
	string nom_villeDepute;
	string code_postalDepute;
	string provinceDepute;

	int partiPolitiqueDepute;


	cout << "Entrez le depute sortant" << endl;
	cout << "Choisissez un parti:" << endl;
	cout << "0:BLOC_QUEBECOIS, 1:CONSERVATEUR,2:INDEPENDANT,3:LIBERAL,4:NOUVEAU_PARTI_DEMOCRATIQUE" << endl;

	int verifie_partiPolitiqueDepute = 0;
	while (verifie_partiPolitiqueDepute != 1)
	{
		cin >> partiPolitiqueDepute;
		cin.ignore();
		if (partiPolitiqueDepute >= 0 && partiPolitiqueDepute <= 4)
		{
			verifie_partiPolitiqueDepute = 1;
		}
		if (verifie_partiPolitiqueDepute == 0)
		{
			cout << "Le numéro correspondant au parti politique n'est pas valide" << endl;
		}
	}

	int verifie_nasDepute = 0;
	while (verifie_nasDepute != 1)
	{
		cout << "Entrez son numéro d'assurance sociale : " << endl;
		std::getline(cin, nasDepute);
		if (util::validerNas(nasDepute) == 1)
		{
			verifie_nasDepute = 1;
		}
		if (verifie_nasDepute == 0)
		{
			cout << "NAS invalide, " << endl;
		}
	}

	while (nomDepute.empty())
	{
		cout << "Entrez le nom : ";
		std::getline(cin, nomDepute);
		if (nomDepute.empty())
		{
			cout << "Le nom est vide" << endl;
		}
	}

	while (prenomDepute.empty())
	{
		cout << "Entrez le prenom : ";
		std::getline(cin, prenomDepute);
		if (prenomDepute.empty())
		{
			cout << "Le prenom est vide" << endl;
		}
	}
	cout << endl;

	// Date de naissance
	int verifie_dateD = 0;
	while (verifie_dateD != 1)
	{
		cout << "Veuillez entrer sa date de naissance : " << endl;
		cout << "Le jour [1..31] : ";
		cin >> jour_de_naissanceDepute;
		cout << "Le mois [1..12] : ";
		cin >> mois_de_naissanceDepute;
		cout << "L'année de naissance [1970..2037] : ";
		cin >> annee_de_naissanceDepute;

		Date date(jour_de_naissanceDepute, mois_de_naissanceDepute, annee_de_naissanceDepute);
		if (date.validerDate(jour_de_naissanceDepute, mois_de_naissanceDepute, annee_de_naissanceDepute) == 1)
		{
			verifie_dateD = 1;
		}
		if (verifie_dateD == 0)
		{
			cout << "La date de naissance n'est pas valide" << endl;
		}
			cout << endl;
	}


	// Adresse
	cout << "Entrez l'adresse" << endl;

	int verifie_numero_civicD = 0;
	while (verifie_numero_civicD!= 1)
	{
		cout << "Numéro de rue : " << endl;
		cin >> numero_civicDepute;
		cin.ignore();
		if (numero_civicDepute > 0)
		{
			verifie_numero_civicD = 1;
		}
		if (verifie_numero_civicD != 1)
		{
			cout << "Le numero civic n'est pas valide" << endl;
		}
	}

	int verifie_nom_rueD = 0;
	while (verifie_nom_rueD != 1)
	{
		cout << "Rue : " << endl;
		std::getline(cin, nom_rueDepute);
		if (!nom_rueDepute.empty())
		{
			verifie_nom_rueD = 1;
		}
		if (nom_rueDepute.empty())
		{
			cout << "Le nom de rue est vide" << endl;
		}
	}

	int verifie_villeD = 0;
	while (verifie_villeD != 1)
	{
		cout << "Ville : " << endl;
		std::getline(cin, nom_villeDepute);
		if (!nom_villeDepute.empty())
		{
			verifie_villeD = 1;
		}
		if (nom_villeDepute.empty())
		{
			cout << "Le nom de la ville est vide" << endl;
		}
	}

	int verifie_code_postalD = 0;
	while (verifie_code_postalD != 1)
	{
		cout << "Code postal : " << endl;
		std::getline(cin, code_postalDepute);
		if (!code_postalDepute.empty())
		{
			verifie_code_postalD = 1;
		}
		if (code_postalDepute.empty())
		{
			cout << "Le numéro du code postal est vide" << endl;
		}
	}

	int verifie_provinceD = 0;
	while (verifie_provinceD != 1)
	{
		cout << "Province : " << endl;
		std::getline(cin, provinceDepute);
		if (!provinceDepute.empty())
		{
			verifie_provinceD = 1;
		}
		if (provinceDepute.empty())
		{
			cout << "Le nom de la province est vide" << endl;
		}
	}

	cout << endl;

	string nom_circonscription;
	int verifie_nomCirconscription = 0;
	while (verifie_nomCirconscription != 1)
	{
		cout << "Entrez le nom de la circonscription" << endl;
		std::getline(cin, nom_circonscription);
		if (!nom_circonscription.empty())
		{
			verifie_nomCirconscription = 1;
		}
		if (nom_circonscription.empty())
		{
			cout << "Le nom de la circonscription est vide" << endl;
		}
	}



	cout << "--------------------------------------" << endl;

	Date dateDepute(jour_de_naissanceDepute, mois_de_naissanceDepute, annee_de_naissanceDepute);
	Adresse adresseDepute(numero_civicDepute, nom_rueDepute, nom_villeDepute, code_postalDepute, provinceDepute);
	Candidat depute(nasDepute, prenomDepute, nomDepute, dateDepute, adresseDepute, partiPolitiqueDepute);

	Circonscription circonscription(nom_circonscription, depute);

	//Inscription d'un candidat

	string prenomCandidat;
	string nomCandidat;
	long jour_de_naissanceCandidat;
	long mois_de_naissanceCandidat;
	long annee_de_naissanceCandidat;
	string nasCandidat;
	int numero_civicCandidat;
	string nom_rueCandidat;
	string nom_villeCandidat;
	string code_postalCandidat;
	string provinceCandidat;

	int partiPolitiqueCandidat;

	cout << "--------------------------------------------------" << endl;
	cout << "Bienvenue a l'outil d'ajout d'une personne : " << endl;
	cout << "--------------------------------------------------" << endl;
	cout << endl;


	cout << "Inscription d'un candidat" << endl;
	cout << "Choisissez un parti:" << endl;
	cout << "0:BLOC_QUEBECOIS, 1:CONSERVATEUR,2:INDEPENDANT,3:LIBERAL,4:NOUVEAU_PARTI_DEMOCRATIQUE" << endl;

	int verifie_partiPolitiqueCandidat = 0;
	while (verifie_partiPolitiqueCandidat != 1)
	{
		cin >> partiPolitiqueCandidat;
		cin.ignore();
		if (partiPolitiqueCandidat >= 0 && partiPolitiqueCandidat <= 4)
		{
			verifie_partiPolitiqueCandidat = 1;
		}
		if (verifie_partiPolitiqueCandidat == 0)
		{
			cout << "Le numéro correspondant au parti politique n'est pas valide" << endl;
		}
	}

	int verifie_nasC = 0;
	while (verifie_nasC != 1)
	{
		cout << "Entrez son numéro d'assurance sociale : " << endl;
		std::getline(cin, nasCandidat);
		if (util::validerNas(nasCandidat) == 1)
		{
			verifie_nasC = 1;
		}
		if (verifie_nasC == 0)
		{
			cout << "NAS invalide, " << endl;
		}
	}

	while (nomCandidat.empty())
	{
		cout << "Entrez le nom : ";
		std::getline(cin, nomCandidat);
		if (nomCandidat.empty())
		{
			cout << "Le nom est vide" << endl;
		}
	}

	while (prenomCandidat.empty())
	{
		cout << "Entrez le prenom : ";
		std::getline(cin, prenomCandidat);
		if (prenomCandidat.empty())
		{
			cout << "Le prenom est vide" << endl;
		}
	}
	cout << endl;

	// Date de naissance
	int verifie_dateC = 0;
	while (verifie_dateC != 1)
	{
		cout << "Veuillez entrer sa date de naissance : " << endl;
		cout << "Le jour [1..31] : ";
		cin >> jour_de_naissanceCandidat;
		cout << "Le mois [1..12] : ";
		cin >> mois_de_naissanceCandidat;
		cout << "L'année de naissance [1970..2037] : ";
		cin >> annee_de_naissanceCandidat;

		Date date(jour_de_naissanceCandidat, mois_de_naissanceCandidat, annee_de_naissanceCandidat);
		if (date.validerDate(jour_de_naissanceCandidat, mois_de_naissanceCandidat, annee_de_naissanceCandidat) == 1)
		{
			verifie_dateC = 1;
		}
		if (verifie_dateC == 0)
		{
			cout << "La date de naissance n'est pas valide" << endl;
		}
			cout << endl;
	}


	// Adresse
	cout << "Entrez l'adresse" << endl;

	int verifie_numero_civicC = 0;
	while (verifie_numero_civicC != 1)
	{
		cout << "Numéro de rue : " << endl;
		cin >> numero_civicCandidat;
		cin.ignore();
		if (numero_civicCandidat > 0)
		{
			verifie_numero_civicC = 1;
		}
		if (verifie_numero_civicC != 1)
		{
			cout << "Le numero civic n'est pas valide" << endl;
		}
	}

	int verifie_nom_rueC = 0;
	while (verifie_nom_rueC != 1)
	{
		cout << "Rue : " << endl;
		std::getline(cin, nom_rueCandidat);
		if (!nom_rueCandidat.empty())
		{
			verifie_nom_rueC = 1;
		}
		if (nom_rueCandidat.empty())
		{
			cout << "Le nom de rue est vide" << endl;
		}
	}

	int verifie_villeC = 0;
	while (verifie_villeC != 1)
	{
		cout << "Ville : " << endl;
		std::getline(cin, nom_villeCandidat);
		if (!nom_villeCandidat.empty())
		{
			verifie_villeC = 1;
		}
		if (nom_villeCandidat.empty())
		{
			cout << "Le nom de la ville est vide" << endl;
		}
	}

	int verifie_code_postalC = 0;
	while (verifie_code_postalC != 1)
	{
		cout << "Code postal : " << endl;
		std::getline(cin, code_postalCandidat);
		if (!code_postalCandidat.empty())
		{
			verifie_code_postalC = 1;
		}
		if (code_postalCandidat.empty())
		{
			cout << "Le numéro du code postal est vide" << endl;
		}
	}

	int verifie_provinceC = 0;
	while (verifie_provinceC != 1)
	{
		cout << "Province : " << endl;
		std::getline(cin, provinceCandidat);
		if (!provinceCandidat.empty())
		{
			verifie_provinceC = 1;
		}
		if (provinceCandidat.empty())
		{
			cout << "Le nom de la province est vide" << endl;
		}
	}

	cout << endl;

	cout << "Candidat enregistree" << endl;
	cout << "--------------------------------------" << endl;

	Date dateCandidat(jour_de_naissanceCandidat, mois_de_naissanceCandidat, annee_de_naissanceCandidat);
	Adresse adresseCandidat(numero_civicCandidat, nom_rueCandidat, nom_villeCandidat, code_postalCandidat, provinceCandidat);
	Candidat candidat(nasCandidat, prenomCandidat, nomCandidat, dateCandidat, adresseCandidat, partiPolitiqueCandidat);



	//Inscription Electeur

	string prenomElecteur;
	string nomElecteur;
	long jour_de_naissanceElecteur;
	long mois_de_naissanceElecteur;
	long annee_de_naissanceElecteur;
	string nasElecteur;
	int numero_civicElecteur;
	string nom_rueElecteur;
	string nom_villeElecteur;
	string code_postalElecteur;
	string provinceElecteur;

	cout << "Inscription d'un électeur" << endl;

	int verifie_nasE = 0;
	while (verifie_nasE != 1)
	{
		cout << "Entrez son numéro d'assurance sociale : " << endl;
		std::getline(cin, nasElecteur);
		if (util::validerNas(nasElecteur) == 1)
		{
			verifie_nasE = 1;
		}
		if (verifie_nasE == 0)
		{
			cout << "NAS invalide, " << endl;
		}
	}

	while (nomElecteur.empty())
	{
		cout << "Entrez le nom : ";
		std::getline(cin, nomElecteur);
		if (nomElecteur.empty())
		{
			cout << "Le nom est vide" << endl;
		}
	}

	while (prenomElecteur.empty())
	{
		cout << "Entrez le prenom : ";
		std::getline(cin, prenomElecteur);
		if (prenomElecteur.empty())
		{
			cout << "Le prenom est vide" << endl;
		}
	}
	cout << endl;

	// Date de naissance
	int verifie_dateE = 0;
	while (verifie_dateE != 1)
	{
		cout << "Veuillez entrer sa date de naissance : " << endl;
		cout << "Le jour [1..31] : ";
		cin >> jour_de_naissanceElecteur;
		cout << "Le mois [1..12] : ";
		cin >> mois_de_naissanceElecteur;
		cout << "L'année de naissance [1970..2037] : ";
		cin >> annee_de_naissanceElecteur;

		Date date(jour_de_naissanceElecteur, mois_de_naissanceElecteur, annee_de_naissanceElecteur);
		if (date.validerDate(jour_de_naissanceElecteur, mois_de_naissanceElecteur, annee_de_naissanceElecteur) == 1)
		{
			verifie_dateE = 1;
		}
		if (verifie_dateE == 0)
		{
			cout << "La date de naissance n'est pas valide" << endl;
		}
			cout << endl;
	}


	// Adresse
	cout << "Entrez l'adresse" << endl;

	int verifie_numero_civicE = 0;
	while (verifie_numero_civicE != 1)
	{
		cout << "Numéro de rue : " << endl;
		cin >> numero_civicElecteur;
		cin.ignore();
		if (numero_civicElecteur > 0)
		{
			verifie_numero_civicE = 1;
		}
		if (verifie_numero_civicE != 1)
		{
			cout << "Le numero civic n'est pas valide" << endl;
		}
	}

	int verifie_nom_rueE = 0;
	while (verifie_nom_rueE != 1)
	{
		cout << "Rue : " << endl;
		std::getline(cin, nom_rueElecteur);
		if (!nom_rueElecteur.empty())
		{
			verifie_nom_rueE = 1;
		}
		if (nom_rueElecteur.empty())
		{
			cout << "Le nom de rue est vide" << endl;
		}
	}

	int verifie_villeE = 0;
	while (verifie_villeE != 1)
	{
		cout << "Ville : " << endl;
		std::getline(cin, nom_villeElecteur);
		if (!nom_villeElecteur.empty())
		{
			verifie_villeE = 1;
		}
		if (nom_villeElecteur.empty())
		{
			cout << "Le nom de la ville est vide" << endl;
		}
	}

	int verifie_code_postalE = 0;
	while (verifie_code_postalE != 1)
	{
		cout << "Code postal : " << endl;
		std::getline(cin, code_postalElecteur);
		if (!code_postalElecteur.empty())
		{
			verifie_code_postalE = 1;
		}
		if (code_postalElecteur.empty())
		{
			cout << "Le numéro du code postal est vide" << endl;
		}
	}

	int verifie_provinceE = 0;
	while (verifie_provinceE != 1)
	{
		cout << "Province : " << endl;
		std::getline(cin, provinceElecteur);
		if (!provinceElecteur.empty())
		{
			verifie_provinceE = 1;
		}
		if (provinceElecteur.empty())
		{
			cout << "Le nom de la province est vide" << endl;
		}
	}

	cout << endl;

	cout << "Electeur enregistree" << endl;
	cout << "--------------------------------------" << endl;

	Date dateElecteur(jour_de_naissanceCandidat, mois_de_naissanceCandidat, annee_de_naissanceCandidat);
	Adresse adresseElecteur(numero_civicCandidat, nom_rueCandidat, nom_villeCandidat, code_postalCandidat, provinceCandidat);
	Electeur electeur(nasElecteur, prenomElecteur, nomElecteur, dateElecteur, adresseElecteur);

	circonscription.inscrire(candidat);
	circonscription.inscrire(electeur);

	cout << circonscription.reqCirconscriptionFormate() << endl;

	return 0;
}
