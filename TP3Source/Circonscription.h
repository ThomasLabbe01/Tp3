/*
 * Circonscription.h
 *
 *  Created on: 2020-11-11
 *      Author: etudiant
 */

#ifndef CIRCONSCRIPTION_H_
#define CIRCONSCRIPTION_H_
#include "Candidat.h"
#include "Personne.h"
#include "Electeur.h"
#include <vector>


namespace elections
{


class Circonscription
{
public:
	Circonscription(std::string p_nomCirconscription, Candidat m_deputeElu);
	Circonscription(const Circonscription& p_otherCirconscription);

	const std::string reqNomCirconscription() const;
	const std::string reqDeputeElu() const;
	const std::string reqCirconscriptionFormate();

	void inscrire(const Personne& p_nouvelInscrit);

	~ Circonscription ();
	const Circonscription& operator= (const Circonscription& p_otherCirconscription);

private:
	std::string m_nomCirconscription;
	Candidat m_deputeElu;
	std::vector<Personne*> m_vInscrits;

	void verifieInvariant() const;




}; // class Circonscription


}  // namespace elections


#endif /* CIRCONSCRIPTION_H_ */
