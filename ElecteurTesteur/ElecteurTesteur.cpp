/**
 * \file ElecteurTesteur.cpp
 * \brief Fichier de tests unitaires pour la classe Electeur
 * \author Thomas Labbe
 * \version 1.0
 * \date 2020-11-25
 * \date dernière modification : 2020-11-25
 */

#include<gtest/gtest.h>
#include "Electeur.h"
#include "Personne.h"
#include "Adresse.h"
#include "Date.h"

using namespace std;
using namespace elections;


/**
 * \brief class fixture pour les methodes de la classe Candidat.
 */
class Electeurtest: public::testing::Test
{
public:
	Electeurtest():
		f_electeurtest("046 454 385", "prenom", "nom", util::Date(28, 11, 1998) , util::Adresse(93, "rue de l'Universite", "Quebec", "G1V 0A7", "QC"))
	{
	}
	;

	Electeur f_electeurtest;
};

/**
 * \brief Test de la méthode std::string Electeur::reqPersonneFormate()
 *        cas valide reqElecteurFormate: Création électeur valide connue et test format
 *        cas invalide Aucun d'identifié
 */
TEST_F(Electeurtest, reqElecteurFormate)
{
	std::ostringstream info_electeur;
	info_electeur << "Electeur" << endl;
	info_electeur << "----------------------------------------------" << endl;
	info_electeur << "NAS               : " << f_electeurtest.reqNas() << endl;
	info_electeur << "Prenom            : " << f_electeurtest.reqPrenom() << endl;
	info_electeur << "Nom               : " << f_electeurtest.reqNom() << endl;
	info_electeur << "Date de naissance : " << f_electeurtest.reqDateNaissance().reqDateFormatee() << endl;
	info_electeur << "Adresse           : " << f_electeurtest.reqAdresse() << endl;

	ASSERT_EQ(info_electeur.str(), f_electeurtest.reqPersonneFormate());
}
