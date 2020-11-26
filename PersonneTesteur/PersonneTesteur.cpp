/**
 * \file PersonneTesteur.cpp
 * \brief Fichier de tests unitaires pour la classe Personne
 * \author Thomas Labbe
 * \version 1.0
 * \date 2020-11-25
 * \date dernière modification : 2020-11-25
 */

#include<gtest/gtest.h>
#include "Personne.h"
#include "Date.h"
#include "Adresse.h"



using namespace elections;
/**
 * \class PersonneStringStringStringDateAdresse
 * \brief Fixture pour les tests sur une personne
 */

class Personnetest: public Personne // Une personne("046 454 286", "Marie Antoinette", "Gipsy", datetest, adressetest)





/**
 * \brief Test du constructeur avec paramètres de Personne::Personne(string, string, string, Date, Adresse)
 *
 *    cas valide :
 *    	Création d'une Personne à l'aide du constructeur et vérifie attributs : PersonneValide
 *
 *    cas invalide :
 *    	numero civic invalide : ParametreNumeroCivicInvalide
 *      rue invalide : ParametreNomRueInvalide
 *      ville invalide : ParametreVilleInvalide
 *      code postal invalide : ParametreCodePostalInvalide
 *      province invalide : AsgProvinceInvalide
 */
TEST(Personne, PersonneValide)
{
	Personnetest personnetest(std::string nas = "046 454 286", std::string prenom = "Marie Antoinette", std::string nom =  "Gipsy", util::Date datetest(),util::Adresse adressePersonneTest(93, "rue de l'Universite", "Quebec", "G1V 0A7", "QC"));
}

