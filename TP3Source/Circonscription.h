/**
 * \file Circonscription.h
 * \brief Fichier qui contient l'interface de la classe Circonscription qui sert au maintien et à la manipulation des circonscriptions.
 * \author Thomas Labbe
 * \version 1.0
 */

#ifndef CIRCONSCRIPTION_H_
#define CIRCONSCRIPTION_H_
#include "Candidat.h"
#include "Personne.h"
#include "Electeur.h"
#include <vector>


namespace elections
{
/**
 * \class Circonscription
 * \brief Cette classe sert au maintien et à la manipulation des circonscriptions
 *
 *
 *              Attributs:  string m_nomCirconscription  nom de la circonscription
 *							Candidat m_deputeElu  candidat correspondant au député sortant
 *							vector<Personne*> m_vInscrits;  vecteur qui contient toute les personnes incrites à la circonscription.
 *
 */
class Circonscription
{
public:
	Circonscription(const std::string p_nomCirconscription,const Candidat m_deputeElu);

	const std::string reqNomCirconscription() const;
	const std::string reqDeputeElu() const;
	const std::string reqCirconscriptionFormate();

	void inscrire(const Personne& p_nouvelInscrit);

	~ Circonscription ();

private:
	std::string m_nomCirconscription;
	Candidat m_deputeElu;
	std::vector<Personne*> m_vInscrits;

	void verifieInvariant() const;

	const Circonscription& operator= (const Circonscription& p_otherCirconscription);
	Circonscription(const Circonscription& p_otherCirconscription);





}; // class Circonscription


}  // namespace elections


#endif /* CIRCONSCRIPTION_H_ */
