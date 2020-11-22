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


const std::string Circonscription::reqCirconscriptionFormate() const
{
	std::ostringstream info_circonscription;
	info_circonscription << "circonscription : " << reqNomCirconscription() << endl;
	info_circonscription << "Depute sortant : " << reqDeputeElu() << endl;
	info_circonscription << "Liste des inscrits : " << endl;

	//for

	return info_circonscription.str();
}

void Circonscription::inscrire(const Personne& p_nouvelInscrit)
{
	m_vInscrits.push_back(p_nouvelInscrit.clone());
}

Circonscription::~Circonscription()
{
	m_vInscrits.clear();
}

Circonscription::Circonscription(const Circonscription& p_otherCirconscription) : m_nomCirconscription(p_otherCirconscription.m_nomCirconscription)
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

