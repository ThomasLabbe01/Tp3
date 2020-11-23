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


Circonscription::Circonscription(std::string p_nomCirconscription, Candidat p_deputeElu)
: m_nomCirconscription(p_nomCirconscription), m_deputeElu(p_deputeElu)
{

}


const string Circonscription::reqNomCirconscription() const
{
	return m_nomCirconscription;
}


const std::string Circonscription::reqDeputeElu() const
{
	return m_deputeElu.reqPersonneFormate();
}


const std::string Circonscription::reqCirconscriptionFormate()
{
	std::ostringstream info_circonscription;
	info_circonscription << "circonscription : " << reqNomCirconscription() << endl;
	info_circonscription << "Depute sortant : " << reqDeputeElu() << endl;
	info_circonscription << "Liste des inscrits : " << endl;

	//info_circonscription << (int)m_vInscrits.size() << endl;

	std::vector<Personne*>::iterator iter;

	for (iter =m_vInscrits.begin(); iter != m_vInscrits.end(); ++iter)
	{
		info_circonscription << (*iter)->reqPersonneFormate() << endl;
	}

	return info_circonscription.str();
}

void Circonscription::inscrire(const Personne& p_nouvelInscrit)
{
	m_vInscrits.push_back(p_nouvelInscrit.clone());
}

Circonscription::~Circonscription()
{
	// refaire avec delete or some shit
}

Circonscription::Circonscription(const Circonscription& p_otherCirconscription) : m_nomCirconscription(p_otherCirconscription.reqNomCirconscription()), m_deputeElu(p_otherCirconscription.m_deputeElu)
{
	copy(p_otherCirconscription.m_vInscrits.begin(), p_otherCirconscription.m_vInscrits.end(), back_inserter(m_vInscrits));
}

const Circonscription& Circonscription::operator= (const Circonscription& p_otherCirconscription)
{
	if (this != & p_otherCirconscription)
	{
		m_vInscrits.clear();
		m_nomCirconscription = p_otherCirconscription.m_nomCirconscription;
		copy(p_otherCirconscription.m_vInscrits.begin(), p_otherCirconscription.m_vInscrits.end(), back_inserter(m_vInscrits));
	}
	return *this;
}


void Circonscription::verifieInvariant() const
{

}





} //namespace elections

