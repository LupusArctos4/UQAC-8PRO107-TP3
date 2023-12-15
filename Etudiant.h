#pragma once

#include <string>
#include <iostream>
using namespace std;

struct Etudiant {
    string nom;
    string prenom;
    string codePermanent;
    int anneeNaissance;
    string programme;
    string departement;
    float notesMoyenneTab[5];
};

// Une fonction pour afficher les informations d'un etudiant
void affichageEtudiant(Etudiant etudiant);
//-Une fonction qui calcule la moyenne d�un.e �tudiant.e � partir de ses notes
float moyenne(Etudiant etudiant);
//-Un fonction prend en entr�e un.e �tudiant.e, une ann�e et qui retourne vrai si un.e �tudiant.e est n�.e une ann�e donn�e et faux sinon.
bool anneeVerification(Etudiant etudiant, int annee);
//-Une fonction qui prend en entr�e un.e �tudiant.e, un d�partement et affiche les donn�es de l��tudiant.e si il / elle fait partie de ce d�partement.
void deperatmentVerification(Etudiant etudiant, string departement);
//-M�me principe pour le programme d��tudes.
void programmeEtudeVerification(Etudiant etudiant, string departement);