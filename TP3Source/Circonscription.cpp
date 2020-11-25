/**
 * \file Circonscription.cpp
 * \brief Implantation de la classe Circonscription
 * \author Thomas Labbe
 * \version 1.0 sans contrat
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
/**
 * \brief constructeur avec paramètres
 *  On construit un objet Circonscription à partir de valeurs passées en paramètres.
 * \param[in] p_nomCirconscription est un string qui représente le nom de la circonscription
 * \param[in] p_deputeElu est un objet Candidat qui représente le député sortant
 */
Circonscription::Circonscription(std::string p_nomCirconscription, Candidat p_deputeElu)
: m_nomCirconscription(p_nomCirconscription), m_deputeElu(p_deputeElu)
{

}
/**
 * \brief retourne le nom du député sortant de la circonscription
 * \return un objet string qui correspond au nom de la circonscription
 */
const string Circonscription::reqNomCirconscription() const
{
	return m_nomCirconscription;
}
/**
 * \brief retourne le député sortant
 * \return un objet string qui correspond aux renseignements du député
 */
const std::string Circonscription::reqDeputeElu() const
{
	return m_deputeElu.reqPersonneFormate();
}
/**
 * \brief retourne une circonscription formaté dans une chaîne de caractere (string)
 * \return une cironscription sous la forme du nom de la circonscription, le député sortant, puis une liste de toutes les personnes inscrites dans la circonscription
 */
const std::string Circonscription::reqCirconscriptionFormate()
{
	std::ostringstream info_circonscription;
	info_circonscription << "circonscription : " << reqNomCirconscription() << endl;
	info_circonscription << "Depute sortant : " << reqDeputeElu() << endl;
	info_circonscription << "Liste des inscrits : " << endl;

	std::vector<Personne*>::iterator iter;

	for (iter =m_vInscrits.begin(); iter != m_vInscrits.end(); ++iter)
	{
		info_circonscription << (*iter)->reqPersonneFormate() << endl;
	}

	return info_circonscription.str();
}
/**
 * \brief inscrit une personne (électeur ou candidat) dans la circonscription
 */
void Circonscription::inscrire(const Personne& p_nouvelInscrit)
{
	m_vInscrits.push_back(p_nouvelInscrit.clone());
}
/**
 * \brief va enlever tous les inscrits dans la circonscription
 */
Circonscription::~Circonscription()
{

}
/**
 * \brief constructeur avec paramètres
 *  On construit un objet Circonscription en faisant une copie d'une autre circonscription
 * \param[in] p_otherCirconscription est un objet circonscription qui représente une autre circonscription
 */
Circonscription::Circonscription(const Circonscription& p_otherCirconscription) : m_nomCirconscription(p_otherCirconscription.reqNomCirconscription()), m_deputeElu(p_otherCirconscription.m_deputeElu)
{
	copy(p_otherCirconscription.m_vInscrits.begin(), p_otherCirconscription.m_vInscrits.end(), back_inserter(m_vInscrits));
}
/**
 * \brief surcharge de l'opérateur =
 * \param[in] p_otherCirconscription, qui est une autre circonscription
 * \return une circonscription, qui est l'assignation de celle entrée en paramètre
 */
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
/**
 * \brief Teste l'invariant de la classe Candidat. L'invariant de cette classe s'assure que les candidats sont valides
 */
void Circonscription::verifieInvariant() const
{

}


} //namespace elections

