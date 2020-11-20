/**
 * \file Personne.cpp
 * \brief Implantation de la classe Date
 * \author Thomas Labbe
 * \version 1.0 sans contrat
 */

#include <sstream>
#include "Personne.h"
#include "Adresse.h"
#include "Date.h"

using namespace std;
using namespace util;
namespace elections
{
/**
 * \brief constructeur avec paramètres
 *  On construit un objet Personne à partir de valeurs passées en paramètres.
 * \param[in] p_as est un string qui représente le numéro d'assurance social de la personne
 * \param[in] p_prenom est un string qui représente le prénom de la personne
 * \param[in] p_nom est un string qui représente le nom de la personne
 * \param[in] p_dateNaissance est un objet Date qui représente la date de naisssance de la personne
 * \param[in] p_adresse est un objet Adresse qui représente l'adresse de la personne
 */
Personne::Personne(const std::string p_nas,const std::string p_prenom,const std::string p_nom,const util::Date p_dateNaissance,const Adresse p_adresse)
: m_nas(p_nas), m_prenom(p_prenom), m_nom(p_nom), m_dateNaissance(p_dateNaissance), m_adresse(p_adresse)
{

}
/**
 * \brief retourne le numéro correspondant au numéro d'assurance social
 * \return un string qui représente le numéro d'assurance social de la personne
 */
const string Personne::reqNas() const
{
	return m_nas;
}
/**
 * \brief retourne le prenom de la personne
 * \return un string qui représente le prénom de la personne
 */
const string Personne::reqPrenom() const
{
	return m_prenom;
}
/**
 * \brief retourne le nom de la personne
 * \return un string qui représente le nom de la personne
 */
const string Personne::reqNom() const
{
	return m_nom;
}
/**
 * \brief retourne la date de naissance de la personne
 * \return un objet Date qui représente la date de naissance de la personne
 */
const Date Personne::reqDateNaissance() const
{
	return m_dateNaissance;
}
/**
 * \brief retourne l'adresse
 * \return un objet Adresse qui représente l'adresse de la personne
 */
const Adresse Personne::reqAdresse() const
{
	return m_adresse;
}
/**
 * \brief retourne une personne formaté dans une chaîne de caractere (string)
 * \return une personne formaté dans une chaîne de caracteres
 */
string Personne::reqPersonneFormate() const
{
	std::ostringstream info_personne;
	info_personne << "----------------------------------------------" << endl;
	info_personne << "NAS               : " << m_nas << endl;
	info_personne << "Prenom            : " << m_prenom << endl;
	info_personne << "Nom               : " << m_nom << endl;
	info_personne << "Date de naissance : " << m_dateNaissance.reqDateFormatee() << endl;
	info_personne << "Adresse           : " << m_adresse << endl;

	return info_personne.str();
}

bool Personne::operator ==(const Personne& other) const
{
	return m_nas == other.m_nas && m_prenom == other.m_prenom
			&& m_nom == other.m_nom && m_dateNaissance == other.m_dateNaissance
			&& m_adresse == other.m_adresse;
}

void asgAdresse(const util::Adresse& adresse)
{
	util::Adresse m_adresse = adresse;
}

}  // namespace elections
