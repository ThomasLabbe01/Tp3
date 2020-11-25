/**
 * \file Electeur.h
 * \brief Fichier qui contient l'interface de la classe Electeur qui sert au maintien et à la manipulation des électeurs.
 * \author Thomas Labbe
 * \version 1.0
 */

#ifndef ELECTEUR_H_
#define ELECTEUR_H_
#include "Personne.h"
#include "Adresse.h"
#include <sstream>
#include <string>

namespace elections
{
/**
 * \class Électeur
 * \brief Cette classe sert au maintien et à la manipulation des électeurs
 *
 *              Cette classe hérite de la classe personne
 *
 */
class Electeur : public Personne
{

public:

	Electeur(const std::string p_nas,const std::string p_prenom,const std::string p_nom,const util::Date p_dateNaissance,const util::Adresse p_adresse);

	virtual std::string reqPersonneFormate() const;
	virtual Personne* clone() const;

private:
	void verifieInvariant() const;



}; // class Electeur

}  // namespace elections



#endif /* ELECTEUR_H_ */
