/**
 * \file Adresse.cpp
 * \brief Fichier qui contient l'interface de la classe Adresse qui sert au maintien et à la manipulation des adresses.
 * \author Thomas Labbe
 * \version 1.0 sans contrat
 */

#ifndef ADRESSE_H_
#define ADRESSE_H_
#include <string>

namespace util
{
/**
 * \class Adresse
 * \brief Cette classe sert au maintien et à la manipulation des adresses.
 *              Attributs:
 * 				int m_numeroCivic
 * 				string m_nomRue
 *				string m_ville
 *				string m_codePostal
 *				string m_province
 *
 */
class Adresse
{
public:
	Adresse(const int& p_numeroCivic, const std::string& p_nomRue, const std::string& p_ville, const std::string& p_codePostal, const std::string& p_province);

	const int reqNumeroCivic() const;
	const std::string reqNomRue() const;
	const std::string reqVille() const;
	const std::string reqCodePostal() const;
	const std::string reqProvince() const;

	void asgAdresse(const int p_numeroCivic,const std::string p_nomRue,const std::string p_ville,
			const std::string p_codePostal,const std::string p_province);

	const std::string reqAdresseFormate() const;

	bool operator ==(const Adresse& other) const;

	friend std::ostream& operator<<(std::ostream& p_os, const Adresse& p_adresse);

private:
	int m_numeroCivic;
	std::string m_nomRue;
	std::string m_ville;
	std::string m_codePostal;
	std::string m_province;

	void verifieInvariant() const;




};  // class Adresse

}  // namespace util





#endif /* ADRESSE_H_ */
