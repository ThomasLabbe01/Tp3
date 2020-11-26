/**
 * \file Electeur.cpp
 * \brief Implantation de la classe Electeur
 * \author Thomas Labbe
 * \version 1.0 sans contrat
 */

#include "Electeur.h"
#include <sstream>
#include <string>
#include "ContratException.h"


using namespace std;

namespace elections
{
/**
 * \brief constructeur avec paramètres
 *  On construit un objet Électeur à partir de valeurs passées en paramètres.
 * \param[in] p_as est un string qui représente le numéro d'assurance social de l'électeur
 * \param[in] p_prenom est un string qui représente le prénom de l'électeur
 * \param[in] p_nom est un string qui représente le nom de l'électeur
 * \param[in] p_dateNaissance est un objet Date qui représente la date de naisssance de l'électeur
 * \param[in] p_adresse est un objet Adresse qui représente l'adresse de l'électeur
 */
Electeur::Electeur(const std::string& p_nas,const std::string& p_prenom,const std::string& p_nom,const util::Date& p_dateNaissance,const util::Adresse& p_adresse)
: Personne(p_nas, p_prenom, p_nom, p_dateNaissance, p_adresse)
{

}
/**
 * \brief retourne un électeur formaté dans une chaîne de caractere (string)
 * \return un électeur forméaté dans une chaîne de caractères
 */
string Electeur::reqPersonneFormate() const
{
	std::ostringstream info_electeur;
	info_electeur << "Electeur" << endl;
	info_electeur << Personne::reqPersonneFormate();
	return info_electeur.str();
}
/**
 * \brief fait une copie allouée sur le monceau de l'objet courant.
 * \return le contenu d'un pointeur sur un électeur
 */
Personne* Electeur::clone() const
{
	return new Electeur(*this);
}
/**
 * \brief Teste l'invariant de la classe Électeur. L'invariant de cette classe s'assure que les électeurs sont valides
 */
void Electeur::verifieInvariant() const
{

}


} //namespace elections



