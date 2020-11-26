/**
 * \file AdresseTesteur.cpp
 * \brief Fichier de tests unitaires pour la classe Adresse
 * \author Thomas Labbe
 * \version 1.0
 * \date 2020-11-25
 * \date dernière modification : 2020-11-25
 */

#include<gtest/gtest.h>
#include "Adresse.h"
#include "ContratException.h"
#include <iostream>
#include <sstream>


using namespace util;

/**
 * \brief Test du constructeur avec paramètres de Adresse::Adresse(int, string, string, string, string)
 *
 *    cas valide :
 *    	ConstructeurParDefaut: Création d'une adresse à l'aide du constructeur par défaut et vérifie attributs : ParametresValides
 *
 *    cas invalide :
 *    	numero civic invalide : ParametreNumeroCivicInvalide
 *      rue invalide : ParametreNomRueInvalide
 *      ville invalide : ParametreVilleInvalide
 *      code postal invalide : ParametreCodePostalInvalide
 *      province invalide : AsgProvinceInvalide
 */
TEST(Adresse, ParametresValides)
{
	Adresse adresseTest(93, "rue de l'Universite", "Quebec", "G1V 0A7", "QC");
	ASSERT_EQ(93, adresseTest.reqNumeroCivic());
	ASSERT_EQ("rue de l'Universite", adresseTest.reqNomRue());
	ASSERT_EQ("Quebec", adresseTest.reqVille());
	ASSERT_EQ( "G1V 0A7", adresseTest.reqCodePostal());
	ASSERT_EQ("QC", adresseTest.reqProvince());
}

// m_NumeroCivic invalide
TEST(Adresse, ParametreNumeroCivicInvalide)
{
	ASSERT_THROW (Adresse adresseInvalide(-1, "rue de l'Universite", "Quebec", "G1V 0A7", "QC"), ContratException)
	<< "Le numéro civic de l'adresse doit être un entier positif.";
}

// m_nomRue invalide
TEST(Adresse, ParametreNomRueInvalide)
{
	ASSERT_THROW(Adresse adresseInvalide(93, "", "Quebec", "G1V 0A7", "QC"), ContratException)
	<< "Le nom de la rue est vide";
}

// m_ville invalide
TEST(Adresse, ParametreVilleInvalide)
{
	ASSERT_THROW(Adresse adresseInvalide(93, "rue de l'Universite", "", "G1V 0A7", "QC"), ContratException)
	<< "Le nom de la ville est vide";
}

// m_codePostal invalide
TEST(Adresse, ParametreCodePostalInvalide)
{
	ASSERT_THROW(Adresse adresseInvalide(93, "rue de l'Universite", "Quebec", "", "QC"), ContratException)
	<< "Le code postal est vide";
}

// m_province invalide
TEST(Adresse, ParametreProvinceInvalide)
{
	ASSERT_THROW(Adresse adresseInvalide(93, "rue de l'Universite", "Quebec", "G1V 0A7", ""), ContratException)
	<< "Le nom de la province est vide";
}


class AdresseIntStringStringStringString: public::testing::Test // Une adresse(93, "rue de l'Universite", "Quebec", "G1V 0A7", "QC")
{
public:
	AdresseIntStringStringStringString() :
			f_adressetest(93, "rue de l'Universite", "Quebec", "G1V 0A7", "QC")
	{
	}
	;

	Adresse f_adressetest;
};

/**
 * \brief Test de la méthode int Adresse::reqNumeroCivic()
 *        cas valide reqNumeroCivic: Création adresse valide connue et test du numero civic
 *        cas invalide Aucun d'identifié
 */
TEST_F(AdresseIntStringStringStringString, reqNumeroCivic)
{
	ASSERT_EQ(93, f_adressetest.reqNumeroCivic());
}

/**
 * \brief Test de la méthode int Adresse::reqNomRue()
 *        cas valide reqNomRue: Création adresse valide connue et test du nom de la rue
 *        cas invalide Aucun d'identifié
 */
TEST_F(AdresseIntStringStringStringString, reqNomRue)
{
	ASSERT_EQ("rue de l'Universite", f_adressetest.reqNomRue());
}


/**
 * \brief Test de la méthode int Adresse::reqVille()
 *        cas valide reqVille: Création adresse valide connue et test du nom de la ville
 *        cas invalide Aucun d'identifié
 */
TEST_F(AdresseIntStringStringStringString, reqVille)
{
	ASSERT_EQ("Quebec", f_adressetest.reqVille());
}

/**
 * \brief Test de la méthode int Adresse::reqCodePostal()
 *        cas valide reqCodePostal: Création adresse valide connue et test du code postal
 *        cas invalide Aucun d'identifié
 */
TEST_F(AdresseIntStringStringStringString, reqCodePostal)
{
	ASSERT_EQ("G1V 0A7", f_adressetest.reqCodePostal());
}

/**
 * \brief Test de la méthode int Adresse::reqProvince()
 *        cas valide reqProvince: Création adresse valide connue et test de la province
 *        cas invalide Aucun d'identifié
 */
TEST_F(AdresseIntStringStringStringString, reqProvince)
{
	ASSERT_EQ("QC", f_adressetest.reqProvince());
}

/**
 * \brief Test de la méthode int Adresse::reqAdresse()
 *        cas valide reqAdresse: Création adresse valide connue et test de son contenu
 *        cas invalide Aucun d'identifié
 */

TEST_F(AdresseIntStringStringStringString, reqAdresse)
{
	ASSERT_EQ("93, rue de l'Universite, Quebec, G1V 0A7, QC", f_adressetest.reqAdresseFormate());
}


/**
 * \brief Test de la méthode void asgAdresse()
 *     	cas valide
 *     		AsgAdresseValide: Assigner une adresse avec numero civic, rue, ville, code postal, province
 */

TEST_F(AdresseIntStringStringStringString, AsgAdresseValide)
{
	f_adressetest.asgAdresse(5, "rue", "ville", "codepostal", "province");
	ASSERT_EQ(5, f_adressetest.reqNumeroCivic());
	ASSERT_EQ("rue", f_adressetest.reqNomRue());
	ASSERT_EQ("ville", f_adressetest.reqVille());
	ASSERT_EQ("codepostal", f_adressetest.reqCodePostal());
	ASSERT_EQ("province", f_adressetest.reqProvince());
}


/**
 * \class DeuxDates
 * \brief Fixture pour les tests comparaisons de Deux dates
 */
class DeuxAdresses: public ::testing::Test
{
public:
	DeuxAdresses() :
			f_adresse1(93, "rue de l'Universite", "Quebec", "G1V 0A7", "QC"), f_adresse2(1, "string", "string", "string", "string")
	{
	}
	;

	Adresse f_adresse1;
	Adresse f_adresse2;
};
/**
 * \brief  Test de la méthode bool Adresse::operator== (const Adresse& obj)
 *        cas valide:
 *   		OperatorEgalEgalVrai: 	Adresses indentique à elle-même.
 *  		OperatorEgalEgalFaux: 	Adresses différentes
 *        cas invalide Aucun d'identifié
 */
TEST_F(DeuxAdresses, OperatorEgalEgalVrai)
{
	ASSERT_EQ(f_adresse1, f_adresse1);
}

TEST_F(DeuxAdresses, OperatorEgalEgalFaux)
{
	ASSERT_FALSE(f_adresse1 == f_adresse2); // On ne peut utiliser ASSERT_NE() si l'opérateur != n'est pas implémenté
}


/**
 * \brief  Test de la méthode ostream& Date::operator<<(ostream&, const Date&)
 * 	cas valide:
 *  	OperatorPlusPetitPlusPetit: Date valide connue qu'on envoie dans un ostringstream
 *  	et qu'on compare avec la sortie prévue.
 * 	cas invalide Aucun d'identifié
 */
TEST_F(AdresseIntStringStringStringString, OperatorPlusPetitPlusPetit)
{
	std::ostringstream os;
	os << f_adressetest;
	ASSERT_EQ("93, rue de l'Universite, Quebec, G1V 0A7, QC",os.str());
}

