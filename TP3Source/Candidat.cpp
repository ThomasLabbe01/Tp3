/*
 * Candidat.cpp
 *
 *  Created on: 2020-11-11
 *      Author: etudiant
 */

#include "Candidat.h"
#include <sstream>
#include <string>

using namespace std;

namespace elections
{

Candidat::Candidat(const std::string p_nas,const std::string p_prenom,const std::string p_nom,const util::Date p_dateNaissance,const util::Adresse p_adresse, const int p_partiPolitique)
: elections::Personne(p_nas, p_prenom, p_nom, p_dateNaissance, p_adresse), m_partiPolitique(p_partiPolitique)
{

}

/*
const int Candidat::reqPartiPolitique() const
{
	return m_partiPolitique;
}
*/
string Candidat::reqPersonneFormate() const
{
	std::ostringstream info_candidat;
	info_candidat << "Candidat" << endl;
	info_candidat << Personne::reqPersonneFormate();
	info_candidat << "Parti politique :	 ";

	int parti = m_partiPolitique;
	switch (parti)
	{
	case 0 :
		info_candidat << "Bloc quebecois"<< endl;
		break;
	case 1 :
		info_candidat << "Conservateur" << endl;
		break;
	case 2 :
		info_candidat << "Independant" << endl;
		break;
	case 3 :
		info_candidat << "Liberal" << endl;
		break;
	case 4 :
		info_candidat << "Nouveau parti democratique" << endl;
		break;
	}

	return info_candidat.str();
}

Personne* Candidat::clone() const
{
	return new Candidat(*this);
}


} //namespace elections

