/*
 * Electeur.cpp
 *
 *  Created on: 2020-11-11
 *      Author: etudiant
 */

#include "Electeur.h"
#include <sstream>
#include <string>

using namespace std;

namespace elections
{

Electeur::Electeur(const std::string p_nas,const std::string p_prenom,const std::string p_nom,const util::Date p_dateNaissance,const util::Adresse p_adresse)
: elections::Personne(p_nas, p_prenom, p_nom, p_dateNaissance, p_adresse)
{

}

string Electeur::reqPersonneFormate() const
{
	std::ostringstream info_electeur;
	info_electeur << "Electeur" << endl;
	info_electeur << Personne::reqPersonneFormate();
	return info_electeur.str();
}

Personne* Electeur::clone() const
{
	return new Electeur(*this);
}


} //namespace elections



