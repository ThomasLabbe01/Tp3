/**
 * \file Personne.h
 * \brief Fichier qui contient l'interface de la classe Personne qui sert au maintien et à la manipulation des personnes.
 * \author Thomas Labbe
 * \version 1.0 sans contrat
 */

#ifndef PERSONNE_H_
#define PERSONNE_H_
#include <string>
#include "Date.h"
#include "Adresse.h"

namespace elections
{
/**
 * \class Personne
 * \brief Cette classe sert au maintien et à la manipulation des personnes.
 *              Attributs:
 * 				string m_nas
 * 				string m_prenom
 *				string m_nom
 *				Date m_dateNaissance
 *				Adresse m_adresse
 *
 */
class Personne
{
public:
	Personne(const std::string p_nas,const std::string p_prenom,const std::string p_nom,const util::Date p_dateNaissance,const util::Adresse p_adresse);

	virtual ~Personne() = 0;
	virtual Personne* clone() const =0;

	const std::string reqNas() const;
	const std::string reqPrenom() const;
	const std::string reqNom() const;
	const util::Date reqDateNaissance() const;
	const util::Adresse reqAdresse() const;

	//void asgPersonne(std::string p_nas, std::string p_prenom, std::string p_nom, util::Date p_dateNaissance, util::Adresse p_adresse);

	bool operator ==(const Personne& other) const;

	virtual std::string reqPersonneFormate() const = 0;

	void asgAdresse(const util::Adresse& adresse);


private:
	std::string m_nas;
	std::string m_prenom;
	std::string m_nom;
	util::Date m_dateNaissance;
	util::Adresse m_adresse;

};  // class Personne

}  // namespace util

#endif /* PERSONNE_H_ */
