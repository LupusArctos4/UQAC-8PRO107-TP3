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
//-Une fonction qui calcule la moyenne d’un.e étudiant.e à partir de ses notes
float moyenne(Etudiant etudiant);
//-Un fonction prend en entrée un.e étudiant.e, une année et qui retourne vrai si un.e étudiant.e est né.e une année donnée et faux sinon.
bool anneeVerification(Etudiant etudiant, int annee);
//-Une fonction qui prend en entrée un.e étudiant.e, un département et affiche les données de l’étudiant.e si il / elle fait partie de ce département.
void deperatmentVerification(Etudiant etudiant, string departement);
//-Même principe pour le programme d’études.
void programmeEtudeVerification(Etudiant etudiant, string departement);