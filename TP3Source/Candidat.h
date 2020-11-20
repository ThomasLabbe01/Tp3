/*
 * Candidat.h
 *
 *  Created on: 2020-11-11
 *      Author: etudiant
 */

#ifndef CANDIDAT_H_
#define CANDIDAT_H_
#include "Personne.h"
#include "Adresse.h"
#include <sstream>
#include <string>


namespace elections
{
class Candidat : public elections::Personne
{

public:

	Candidat(const std::string p_nas,const std::string p_prenom,const std::string p_nom,const util::Date p_dateNaissance,const util::Adresse p_adresse, const int p_partiPolitique);
	const int reqPartiPolitique() const;

	enum PartisPolitiques {BLOC_QUEBECOIS, CONSERVATEUR, INDEPENDANT, LIBERAL,
	NOUVEAU_PARTI_DEMOCRATIQUE};  //PartisPolitiques p = m_partiPolitique

	virtual std::string reqPersonneFormate() const;

	virtual Personne* clone() const;

private:
	int m_partiPolitique;

}; // class Candidat

}  // namespace elections



#endif /* CANDIDAT_H_ */
