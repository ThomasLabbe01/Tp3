/**
 * \file Candidat.cpp
 * \brief Implantation de la classe Candidat
 * \author Thomas Labbe
 * \version 1.0 sans contrat
 */

#include "Candidat.h"
#include "ContratException.h"
#include <sstream>
#include <string>

using namespace std;

namespace elections
{
/**
 * \brief constructeur avec paramètres
 *  On construit un objet Candidat à partir de valeurs passées en paramètres.
 * \param[in] p_as est un string qui représente le numéro d'assurance social du candidat
 * \param[in] p_prenom est un string qui représente le prénom du candidat
 * \param[in] p_nom est un string qui représente le nom du candidat
 * \param[in] p_dateNaissance est un objet Date qui représente la date de naisssance du candidat
 * \param[in] p_adresse est un objet Adresse qui représente l'adresse du candidat
 * \param[in] p_partiPolitique est un objet int qui correspond au parti politique déclaré dans Candidat.h
 */
Candidat::Candidat(const std::string& p_nas,const std::string& p_prenom,const std::string& p_nom,const util::Date& p_dateNaissance,const util::Adresse& p_adresse, const int& p_partiPolitique)
: elections::Personne(p_nas, p_prenom, p_nom, p_dateNaissance, p_adresse), m_partiPolitique(p_partiPolitique)
{
	POSTCONDITION (reqNas() == p_nas);
	POSTCONDITION (reqPrenom() == p_prenom);
	POSTCONDITION (reqNom() == p_nom);
	POSTCONDITION (reqDateNaissance() == p_dateNaissance);
	POSTCONDITION (reqAdresse() == p_adresse);
	INVARIANTS();
}
/**
 * \brief retourne le parti Politique du candidat
 * \return un objet string qui correspond aux noms d'un des partis
 */
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
/**
 * \brief retourne un candidat formaté dans une chaîne de caractere (string)
 * \return une candidat formaté dans une chaîne de caracteres
 */
string Candidat::reqPersonneFormate() const
{
	std::ostringstream info_candidat;
	info_candidat << "Candidat" << endl;
	info_candidat << Personne::reqPersonneFormate();
	info_candidat << "Parti politique :	 " << reqPartiPolitique() << endl;

	return info_candidat.str();
}
/**
 * \brief fait une copie allouée sur le monceau de l'objet courant.
 * \return le contenu d'un pointeur sur un candidat
 */
Personne* Candidat::clone() const
{
	return new Candidat(*this);
}
/**
 * \brief Teste l'invariant de la classe Candidat. L'invariant de cette classe s'assure que les candidats sont valides
 */
void Candidat::verifieInvariant() const
{
	INVARIANT(m_partiPolitique >= 0 && m_partiPolitique <= 4)
}

} //namespace elections

