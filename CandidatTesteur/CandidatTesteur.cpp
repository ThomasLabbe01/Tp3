/**
 * \file CandidatTesteur.cpp
 * \brief Fichier de tests unitaires pour la classe Candidat
 * \author Thomas Labbe
 * \version 1.0
 * \date 2020-11-25
 * \date dernière modification : 2020-11-25
 */

#include<gtest/gtest.h>
#include "Candidat.h"
#include "Personne.h"
#include "Adresse.h"
#include "Date.h"

using namespace std;
using namespace elections;

/**
 * \brief Test du constructeur avec paramètres de Candidat::Candidat(string, string, string, Date, Adresse, int)
 *
 *    cas valide :
 *    	Création d'un candidat à l'aide du constructeur et vérifie attributs : CandidatValide
 *
 *    cas invalide :
 *    	numero d'assurance social invalide : NasInvalide
 *    	prenom invalide : PrenomInvalide
 *    	nom invalide : NomInvalide
 *    	Parti politique invalide : PartiPolitiqueInvalide
 *
 */
TEST(Candidat, CandidatValide)
{
	Candidat candidattest("046 454 385", "prenom", "nom", util::Date(28, 11, 1998), util::Adresse(93, "rue de l'Universite", "Quebec", "G1V 0A7", "QC"), 0);

	ASSERT_EQ("046 454 385", candidattest.reqNas());
	ASSERT_EQ("prenom", candidattest.reqPrenom());
	ASSERT_EQ("nom", candidattest.reqNom());
	ASSERT_EQ(util::Date(28, 11, 1998), candidattest.reqDateNaissance());
	ASSERT_EQ(util::Adresse(93, "rue de l'Universite", "Quebec", "G1V 0A7", "QC"), candidattest.reqAdresse());
	ASSERT_EQ(0, candidattest.BLOC_QUEBECOIS);
}



//numero d'assurance social invalide
TEST(Candidat, NASInvalide)
{
	ASSERT_THROW (Candidat candidatInvalide("1", "prenom", "nom", util::Date(28, 11, 1998), util::Adresse(-1, "rue de l'Universite", "Quebec", "G1V 0A7", "QC"), 0), ContratException)
		<< "Le numéro d'assurande social doit correspondre à celui du constructeur";
}

// prenom invalide
TEST(Candidat, PrenomInvalide)
{
	ASSERT_THROW (Candidat candidatInvalide("1", "", "nom", util::Date(28, 11, 1998), util::Adresse(-1, "rue de l'Universite", "Quebec", "G1V 0A7", "QC"), 0), ContratException)
		<< "Le prenom doit être une string non vide";
}

//nom invalide
TEST(Candidat, NomInvalide)
{
	ASSERT_THROW (Candidat candidatInvalide("1", "prenom", "", util::Date(28, 11, 1998), util::Adresse(-1, "rue de l'Universite", "Quebec", "G1V 0A7", "QC"), 0), ContratException)
		<< "Le nom doit être une string non vide";
}

//PartiPolitiqueInvalide
TEST(Candidat, PartiPolitiqueInvalide)
{
	ASSERT_THROW (Candidat candidatInvalide("1", "prenom", "", util::Date(28, 11, 1998), util::Adresse(-1, "rue de l'Universite", "Quebec", "G1V 0A7", "QC"), 5), ContratException)
		<< "Le parti politique doit être un entier entre 0 et 4";
}

/**
 * \brief class fixture pour les methodes de la classe Candidat.
 */
class Candidattest: public::testing::Test
{
public:
	Candidattest():
		f_candidattest("046 454 385", "prenom", "nom", util::Date(28, 11, 1998) , util::Adresse(93, "rue de l'Universite", "Quebec", "G1V 0A7", "QC"), 0)
	{
	}
	;

	Candidat f_candidattest;
};

/**
 * \brief Test de la méthode std::string Candidat::reqPartiPolitique()
 *        cas valide reqPartiPolitique: Création candidat valide connue et test du numero du candidat
 *        cas invalide Aucun d'identifié
 */
TEST_F(Candidattest, reqPartiPolitique)
{
	ASSERT_EQ(0, f_candidattest.BLOC_QUEBECOIS);
}

/**
 * \brief Test de la méthode std::string Candidat::reqPersonneFormate()
 *        cas valide reqCandidatFormate: Création candidat valide connue et test du numero du candidat
 *        cas invalide Aucun d'identifié
 */
TEST_F(Candidattest, reqCandidatFormate)
{
	std::ostringstream info_candidat;
	info_candidat << "Candidat" << endl;
	info_candidat << "----------------------------------------------" << endl;
	info_candidat << "NAS               : " << f_candidattest.reqNas() << endl;
	info_candidat << "Prenom            : " << f_candidattest.reqPrenom() << endl;
	info_candidat << "Nom               : " << f_candidattest.reqNom() << endl;
	info_candidat << "Date de naissance : " << f_candidattest.reqDateNaissance().reqDateFormatee() << endl;
	info_candidat << "Adresse           : " << f_candidattest.reqAdresse() << endl;
	info_candidat << "Parti politique :	 " << f_candidattest.reqPartiPolitique() << endl;

	ASSERT_EQ(info_candidat.str(), f_candidattest.reqPersonneFormate());
}



