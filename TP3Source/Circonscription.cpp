/*
 * Circonscription.cpp
 *
 *  Created on: 2020-11-11
 *      Author: etudiant
 */

#include "Circonscription.h"
#include <sstream>
#include <vector>


using namespace std;

namespace elections
{
/*


Circonscription::Circonscription(std::string p_nomCirconscription, Candidat p_deputeElu)
: m_nomCirconscription(p_nomCirconscription), m_deputeElu(p_deputeElu)
{
	m_vInscrits = new vector[m_vInscrits.size()+1]; // Allocation dynamique
	strcpy(m_vInscrit, p_); // Copie de p_strP dans m_strP
}


Circonscription::~Circonscription()
{
delete[] m_vInscrits;
}
 */

const string Circonscription::reqNomCirconscription() const
{
	return m_nomCirconscription;
}

const Candidat Circonscription::reqDeputeElu() const
{
	return m_deputeElu;
}

/*
const std::string Circonscription::reqCirconscriptionFormate() const
{

}


const std::string& Circonscription::operator= (const std::string& p_nomCirconscription)
{
	if (this != & p_nomCirconscription)
	{
		delete [] m_nomCirconscription;
		m_strP = new char[strlen(p_chaine.m_strP)+1];
		strcpy(m_strP, p_chaine.m_strP);
	}
	return *this;
}
*/

void Circonscription::inscrire(const Personne& p_nouvelInscrit)
{
	m_vInscrits.push_back(p_nouvelInscrit.clone());
}



} //namespace elections


