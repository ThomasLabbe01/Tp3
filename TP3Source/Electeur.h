/*
 * Electeur.h
 *
 *  Created on: 2020-11-11
 *      Author: etudiant
 */

#ifndef ELECTEUR_H_
#define ELECTEUR_H_
#include "Personne.h"
#include "Adresse.h"
#include <sstream>
#include <string>

namespace elections
{

class Electeur : public Personne
{

public:

	Electeur(const std::string p_nas,const std::string p_prenom,const std::string p_nom,const util::Date p_dateNaissance,const util::Adresse p_adresse);

	virtual std::string reqPersonneFormate() const;
	virtual Personne* clone() const;


}; // class Electeur

}  // namespace elections



#endif /* ELECTEUR_H_ */
