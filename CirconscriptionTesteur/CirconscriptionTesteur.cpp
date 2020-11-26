/**
 * \file CirconscriptionTesteur.cpp
 * \brief Fichier de tests unitaires pour la classe Circonscription
 * \author Thomas Labbe
 * \version 1.0
 * \date 2020-11-25
 * \date dernière modification : 2020-11-25
 */

#include<gtest/gtest.h>
#include "Circonscription.h"
#include "Candidat.h"

using namespace std;
using namespace elections;


/**
 * \brief Test du constructeur avec paramètres de Circonscription::Circonscription(string, Candidat)
 *
 *    cas valide :
 *    	Création d'une circonscription à l'aide du constructeur et vérifie attributs : CirconscriptionValide
 *
 *    cas invalide :
 *    	nom circonscription invalide : NomCirconscriptionInvalide
 */
TEST(Circonscription, CirconscriptionValide)
{
	Circonscription circonscriptionTest("nom circonscription", Candidat ("046 454 385", "prenom", "nom", util::Date(28, 11, 1998), util::Adresse(93, "rue de l'Universite", "Quebec", "G1V 0A7", "QC"), 0));
	ASSERT_EQ("nom circonscription", circonscriptionTest.reqNomCirconscription());
	ASSERT_EQ(Candidat("046 454 385", "prenom", "nom", util::Date(28, 11, 1998), util::Adresse(93, "rue de l'Universite", "Quebec", "G1V 0A7", "QC"), 0).reqPersonneFormate(), circonscriptionTest.reqDeputeElu());
}

// nom de la circonscription est invalide
TEST(Circonscription, NomCirconscriptionInvalide)
{
	ASSERT_THROW (Circonscription circonscriptionInvalide("", Candidat("046 454 385", "prenom", "nom", util::Date(28, 11, 1998), util::Adresse(93, "rue de l'Universite", "Quebec", "G1V 0A7", "QC"), 0)), ContratException)
			<< "Le nom de la circonscription ne doit pas être vide";

}

/**
 * \brief class fixture pour les methodes de la classe Candidat.
 */
class CirconscriptionTest: public::testing::Test
{
public:
	CirconscriptionTest():
		f_circonscriptiontest("circonscription 1", Candidat("046 454 385", "prenom", "nom", util::Date(28, 11, 1998) , util::Adresse(93, "rue de l'Universite", "Quebec", "G1V 0A7", "QC"), 0))
	{
	}
	;

	Circonscription f_circonscriptiontest;
};

/**
 * \brief Test de la méthode std::string Circonscription::reqNomCirconscription()
 *        cas valide reqNomCirconscription: Création circonscription valide connue et test du nom de la circonscription
 *        cas invalide Aucun d'identifié
 */
TEST_F(CirconscriptionTest, reqNomCirconscription)
{
	ASSERT_EQ("circonscription 1", f_circonscriptiontest.reqNomCirconscription());
}

