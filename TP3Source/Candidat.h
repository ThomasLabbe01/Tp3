/**
 * \file Candidat.h
 * \brief Fichier qui contient l'interface de la classe Candidat qui sert au maintien et à la manipulation des candidats.
 * \author Thomas Labbe
 * \version 1.0
 */


#ifndef CANDIDAT_H_
#define CANDIDAT_H_
#include "Personne.h"
#include "Adresse.h"
#include <sstream>
#include <string>


namespace elections
{
/**
 * \class Candidat
 * \brief Cette classe sert au maintien et à la manipulation des candidats
 *
 *              Cette classe hérite de la classe personne
 *
 *              Attributs:   m_partiPolitique  nom du parti politique du candidat
 *
 */
class Candidat : public elections::Personne
{

public:

	Candidat(const std::string& p_nas,const std::string& p_prenom,const std::string& p_nom,const util::Date& p_dateNaissance,const util::Adresse& p_adresse, const int& p_partiPolitique);

	const std::string reqPartiPolitique() const;

	enum PartisPolitiques {BLOC_QUEBECOIS, CONSERVATEUR, INDEPENDANT, LIBERAL,
	NOUVEAU_PARTI_DEMOCRATIQUE};  //PartisPolitiques p = m_partiPolitique

	virtual std::string reqPersonneFormate() const;

	virtual Personne* clone() const;

private:
	int m_partiPolitique;

	void verifieInvariant() const;


}; // class Candidat

}  // namespace elections



#endif /* CANDIDAT_H_ */
