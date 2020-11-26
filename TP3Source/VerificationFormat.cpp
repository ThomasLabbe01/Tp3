/**
 * \file VerificationFormat.cpp
 * \brief Implantation de fonctions utilisées par le programme principal
 * \author Thomas Labbe
 * \version 1.0 sans contrat
 */

#include <iostream>
#include <string>
#include <fstream>

#include "VerificationFormat.h"

using namespace std;

namespace util
{
/**
 * \brief Fonction qui permet de vérifier que le format d'un numéro d'assurance social est valide
 * \param[in] p_nas : numéro d'assurance social sous la forme d'une string
 */
bool validerNas(const std::string& p_nas)
{
	string test = "121 212 121";
	bool statut = false;
	bool format = false;
	int somme = 0;

	if (p_nas.length() == 11)  // un NAS valide va toujours être une string de 11 caracteres
	{
		if ((p_nas[3] == ' ') && (p_nas[7] == ' '))  // Au indice 3 et 7, il doit avoir des espaces
		{
			//cout << "Le NAS a des espaces aux bons endroits" << endl;
			int verificationNombre = 0;
			for (unsigned int i = 0; i < p_nas.length(); i++)  // Compte le nombre de
			{
				if (isdigit(p_nas[i]))
				{
					verificationNombre += 1;
				}
			}
			if (verificationNombre == 9)
			{
				format = true;
			}

		}
	}
	if ((format = true))
	{
		for (unsigned int i = 0; i < p_nas.length(); i++)
		{
			int produit = (p_nas[i] - '0') * (test[i] - '0');  // vérifie que les numéros sont bons
			if ((produit < 10) && (produit >= 0))
			{
					somme += produit;
			}
			if ((produit <= 18) && (produit >= 10))
			{
				somme += ((produit - 10) + 1);
			}
		}
	}


	//cout << "somme " << somme << endl;
	if ((somme != 0) && (somme % 10 == 0))
		{
		statut = true;
		}
	//cout << statut << endl;
	return statut;
}


} // namespace util

