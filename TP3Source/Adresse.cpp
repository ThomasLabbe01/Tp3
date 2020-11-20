/**
 * \file Adresse.cpp
 * \brief Implantation de la classe Adresse
 * \author Thomas Labbe
 * \version 1.0 sans contrat
 */

#include "Adresse.h"
#include "ContratException.h"
#include <sstream>

using namespace std;
namespace util
{
/**
 * \brief constructeur avec paramètres
 * On construit un objet Adresse à partir de valeurs passées en paramètres.
 * \param[in] p_numeroCivic est un entier int qui représente le numero_civic
 * \param[in] p_nomRue est un string qui représente le nom de la rue
 * \param[in] p_ville est un string qui représente le nom de la ville
 * \param[in] p_codePostal est un string qui représente le code postal
 * \param[in] p_province est un string qui représente la province
 */
Adresse::Adresse(const int& p_numeroCivic, const std::string& p_nomRue, const std::string& p_ville, const std::string& p_codePostal, const std::string& p_province)
: m_numeroCivic(p_numeroCivic), m_nomRue(p_nomRue), m_ville(p_ville), m_codePostal(p_codePostal), m_province(p_province)
{

}
/**
 * \brief retourne le numéro correspondant au numéro civic
 * \return un entier int qui représente le numéro correspondant au numéro civic
 */
const int Adresse::reqNumeroCivic() const
{
	return m_numeroCivic;
}
/**
 * \brief retourne le nom de la rue
 * \return un string qui représente le nom de la rue
 */
const string Adresse::reqNomRue() const
{
	return m_nomRue;
}
/**
 * \brief retourne le nom de la ville
 * \return un string qui représente le nom de la ville
 */
const string Adresse::reqVille() const
{
	return m_ville;
}
/**
 * \brief retourne le code postal
 * \return un string qui représente le code postal
 */
const string Adresse::reqCodePostal() const
{
	return m_codePostal;
}
/**
 * \brief retourne le nom de la province
 * \return un string qui représente le nom de la province
 */
const string Adresse::reqProvince() const
{
	return m_province;
}
/**
 * \brief Assigne une adresse a l'objet courant
 * \param[in] p_numeroCivic est un entier int qui représente le numero_civic
 * \param[in] p_nomRue est un string qui représente le nom de la rue
 * \param[in] p_ville est un string qui représente le nom de la ville
 * \param[in] p_codePostal est un string qui représente le code postal
 * \param[in] p_province est un string qui représente la province
 */
void Adresse::asgAdresse(const int p_numeroCivic,const std::string p_nomRue,const std::string p_ville,
		const std::string p_codePostal,const std::string p_province)
{
	m_numeroCivic = p_numeroCivic;
	m_nomRue = p_nomRue;
	m_ville = p_ville;
	m_codePostal = p_codePostal;
	m_province = p_province;
}
/**
 * \brief surcharge de l'opérateur ==
 * \param[in] other qui est une adresse valide
 * \return un booléen indiquant si les deux adresses sont égales ou pas
 */
bool Adresse::operator ==(const Adresse& other) const
{
	return m_numeroCivic == other.m_numeroCivic && m_nomRue == other.m_nomRue
			&& m_ville == other.m_ville && m_codePostal == other.m_codePostal
			&& m_province == other.m_province;
}
/**
 * \brief surcharge de la fonction << d'écriture dans une ostream
 * \param[in] stream une stream vide dans laquelle on va écrire
 * \param[in] p_adresse qui est une adresse valide
 * \return la stream dans laquelle on a écrit la date
 */
ostream& operator<<(ostream& stream, const Adresse& p_adresse)
{
	int numero_civic = p_adresse.reqNumeroCivic();
	string rue = p_adresse.reqNomRue();
	string ville = p_adresse.reqVille();
	string code_postal = p_adresse.reqCodePostal();
	string province = p_adresse.reqProvince();

	stream << numero_civic << ", ";
	stream << rue << ", ";
	stream << ville << ", ";
	stream << code_postal << ", ";
	stream << province;
	return stream;
};

}  // namespace util

