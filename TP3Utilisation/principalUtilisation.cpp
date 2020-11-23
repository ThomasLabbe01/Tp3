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

#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace util;
using namespace elections;


int main()
{
	long jour = 1;
	long mois = 2;
	long anne = 1980;
	const int norue = 6;
	const string nomrue = "rue";
	const string ville = "ville";
	const string codepostal = "code postal";
	const string province = "province";
	const string nom = "nom";
	const string prenom = "prenom";
	const string nas =  "640 454 286";
	Date date(jour, mois, anne);
	Adresse adresse(norue, nomrue, ville, codepostal, province);

	Electeur electeurtest(nas, prenom, nom, date, adresse);
	Candidat candidattest(nas, prenom, nom, date, adresse, 0);


	Circonscription testcir("Circonscription1", candidattest);
	testcir.inscrire(electeurtest);
	testcir.inscrire(electeurtest);

	cout << "test" << endl;
	cout << testcir.reqNomCirconscription() << endl;
	cout << testcir.reqDeputeElu() << endl;

	cout << "inscription electeur" << endl;
	cout << "test" << endl;


	cout << testcir.reqCirconscriptionFormate() << endl;

	cout << "IT WORKS!!!!" << endl;

	Circonscription c1(testcir);

	c1 = testcir;





	return 0;
}
