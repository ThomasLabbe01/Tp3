/*
 * Candidat.cpp
 *
 *  Created on: 2020-11-11
 *      Author: etudiant
 */

#include "Candidat.h"
#include "ContratException.h"
#include <sstream>
#include <string>

using namespace std;

namespace elections
{

Candidat::Candidat(const std::string p_nas,const std::string p_prenom,const std::string p_nom,const util::Date p_dateNaissance,const util::Adresse p_adresse, const int p_partiPolitique)
: elections::Personne(p_nas, p_prenom, p_nom, p_dateNaissance, p_adresse), m_partiPolitique(p_partiPolitique)
{

}


const std::string Candidat::reqPartiPolitique() const
{
	std:: string partipolitique;
	int parti = m_partiPolitique;
	switch (parti)
	{
	case 0 :
		partipolitique = "Bloc quebecois";
		break;
	case 1 :
		partipolitique = "Conservateur";
		break;
	case 2 :
		partipolitique = "Independant";
		break;
	case 3 :
		partipolitique = "Liberal";
		break;
	case 4 :
		partipolitique = "Nouveau parti democratique";
		break;
	}
	return partipolitique;
}

string Candidat::reqPersonneFormate() const
{
	std::ostringstream info_candidat;
	info_candidat << "Candidat" << endl;
	info_candidat << Personne::reqPersonneFormate();
	info_candidat << "Parti politique :	 " << reqPartiPolitique() << endl;

	return info_candidat.str();
}

Personne* Candidat::clone() const
{
	return new Candidat(*this);
}


} //namespace elections

