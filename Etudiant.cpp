#include <iostream>
#include <string>
#include "Etudiant.h"
using namespace std;

//-Une fonction qui calcule la moyenne d’un.e étudiant.e à partir de ses notes
float moyenne(Etudiant etudiant) {
	float moyenneFloat;
	float somme = 0;
	for (int i = 0; i < 4; i++) {
		somme += etudiant.notesMoyenneTab[i];
	}
	moyenneFloat = somme / 4;
	return moyenneFloat;
}


// Une fonction pour afficher les informations d'un etudiant
void affichageEtudiant(Etudiant etudiant) {
	// Afficher les informations de l'étudiant
	cout << endl;
	cout << "Nom: " << etudiant.nom << " " << etudiant.prenom << std::endl;
	cout << "Code Permanent: " << etudiant.codePermanent << std::endl;
	cout << "Annee de naissance: " << etudiant.anneeNaissance << std::endl;
	cout << "Programme: " << etudiant.programme << std::endl;
	cout << "Departement: " << etudiant.departement << std::endl;
	cout << "Notes: " << etudiant.notesMoyenneTab[0] << " " << etudiant.notesMoyenneTab[1] << " " << etudiant.notesMoyenneTab[2] << " " << etudiant.notesMoyenneTab[3] << std::endl;
	cout << "Moyenne: " << etudiant.notesMoyenneTab[4] << std::endl;
	cout << "---" << endl;
}

//-Un fonction prend en entrée un.e étudiant.e, une année
// et qui retourne vrai si un.e étudiant.e est né.e une année donnée et faux sinon.
bool anneeVerification(Etudiant etudiant, int annee) {
	return etudiant.anneeNaissance == annee;
}

//-Une fonction qui prend en entrée un.e étudiant.e, un département
// et affiche les données de l’étudiant.e si il / elle fait partie de ce département.
void deperatmentVerification(Etudiant etudiant, string departement) {
	if (etudiant.departement == departement) {
		affichageEtudiant(etudiant);
	}
	else {
		cout << "L'etudiant " << etudiant.nom << " " << etudiant.prenom <<
			" ne fait pas parti du departement suivant : " << departement << "." << endl;
	}
}

//-Même principe pour le programme d’études.
void programmeEtudeVerification(Etudiant etudiant, string programmeEtude) {
	if (etudiant.programme == programmeEtude) {
		affichageEtudiant(etudiant);
	}
	else {
		cout << "L'etudiant " << etudiant.nom << " " << etudiant.prenom <<
			" ne fait pas parti du programme d'etude suivant : " << programmeEtude << "." << endl;
	}
}