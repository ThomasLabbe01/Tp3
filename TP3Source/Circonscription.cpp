/*
 * Circonscription.cpp
 *
 *  Created on: 2020-11-11
 *      Author: etudiant
 */

#include "Circonscription.h"
#include "Candidat.h"
#include "Personne.h"
#include "Electeur.h"
#include "ContratException.h"

#include <sstream>
#include <vector>


using namespace std;

namespace elections
{

/*


Circonscription::Circonscription(std::string p_nomCirconscription, Candidat p_deputeElu)
: m_nomCirconscription(p_nomCirconscription), m_deputeElu(p_deputeElu)
{
	 std::vector<Personne*> m_vInscrits;
}


Circonscription::~Circonscription()
{
	m_vInscrits.clear();

}


const string Circonscription::reqNomCirconscription() const
{
	return m_nomCirconscription;
}


const Candidat Circonscription::reqDeputeElu() const
{
	return m_deputeElu.reqPersonneFormate();
}


const std::string Circonscription::reqCirconscriptionFormate() const
{
	std::ostringstream info_circonscription;
	info_circonscription << "circonscription : " << reqNomCirconscription() << endl;
	info_circonscription << "Depute sortant : " << reqDeputeElu() << endl;
	info_circonscription << "Liste des inscrits : " << endl;

	//for

	return info_circonscription.str();
}


const std::string& Circonscription::operator= (const std::string& p_nomCirconscription)
{
	if (this != & p_nomCirconscription)
	{
		m_vInscrits.clear();
		m_vInscrits = std::vector<Personne*> ;
		m_vInscrits.assign(p_nomCirconscription.begin(), p_nomCirconscription.end());

	}
	return *this;
}


void Circonscription::inscrire(const Personne& p_nouvelInscrit)
{
	m_vInscrits.push_back(p_nouvelInscrit.clone());
}

*/


} //namespace elections

