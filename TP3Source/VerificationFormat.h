/**
 * \file VerificationFormat.h
 * \brief Fichier qui l'ensemble des fonctions utilisées par le fichier principalUtilisation.cpp pour assurer son bon fonctionnement
 * \author Thomas Labbe
 * \version 1.0
 */

#ifndef VERIFICATIONFORMAT_H_
#define VERIFICATIONFORMAT_H_

namespace util
{
/**
 *
 *	Un numéro d'assurance social peut être vérifié avec la fonction validerNas
 *
 */
bool validerNas(const std::string& p_nas);

}

#endif /* VERIFICATIONFORMAT_H_ */
