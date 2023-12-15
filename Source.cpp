//Partie en tete
//Nom prenom codeurs : 
// Loïc FAUCQUENOY
// Louis DE MILLEVILLE
//Nom programme : TP 3
//Created : 21/11/2023
//Last update : 15/12/2023
/*Description :
TP n 3
Automne 2023
Enseignante : Imene Benkalai
Date de remise 15 decembre 2023 avant 23h59
*/

//Partie Clauses d'inclusion
#include <iostream> // lib de lecture écriture
#include <string> // lib pour variable string
#include <math.h> // lib pour les fonctions mathématique = cmath
#include <sstream> // lib pour string to int
#include <time.h> // lib pour manipuler des dates et heures = ctime
#include <fstream> // lib pour manipuler des fichiers
#include <vector> // lib pour manipuler des listes vectorielles
using namespace std; // utiliser l'espace de noms standard
#include "Etudiant.h"

/*
Enonce du TP
L objectif du TP est de pratiquer tout ce qu on a vu jusqu a present. Votre TP devra contenir ce qui suit :

				Structure GOOD
Une structure Etudiant. Chaque etudiant.e a un nom (0), un prenom (1), un code permanent (2), une annee de naissance (3),
un programme d etude (4) et un departement (5). On retrouve egalement dans la structure,
un tableau de taille 5 qui contient 4 notes de l etudiant.e et sa moyenne (6,7,8,9,10).

				Fichier text GOOD
Un fichier .txt qui contient les informations de 10 etudiant.es. Chaque donnee est ecrite sur une ligne separee.
Les 4 notes sont donnees mais pas la moyenne, elle sera calculee par la suite.

				Tableau / Vector GOOD
Le fichier de 10 etudiant.es devra etre lu dans le main dans un tableau d etudiant.es.

				Fonction GOOD
- Une fonction qui calcule la moyenne d un.e etudiant.e a partir de ses notes et la met a sa place dans le tableau.
float moyenne(Etudiant etudiant);
- Un fonction prend en entree un.e etudiant.e, une annee
et qui retourne vrai si un.e etudiant.e est ne.e une annee donnee et faux sinon.
bool anneeVerification(Etudiant etudiant, int annee);
- Une fonction qui prend en entree un.e etudiant.e, un departement 
et affiche les donnees de l etudiant.e si il/elle fait partie de ce departement.
bool deperatmentVerification(Etudiant etudiant, departement);
- Meme principe pour le programme d etudes.
bool programmeEtudeVerification(Etudiant etudiant, departement);

				Main GOOD
Dans le main, une fois le tableau d etudiant.es rempli, vous devez proposer un menu qui permet de choisir
si on veut afficher les etudiant.es ne.es une annee particuliere, affilie.es a un programme ou a un departement particulier.
Ensuite, selon le choix, on saisit la donnee necessaire et on execute les fonctions necessaires.
Le menu se repete tant qu on n a pas choisi de quitter. Bon courage ! :)
*/



// Fonction principale
int main()
{
	ifstream etudiantTxt;
	etudiantTxt.open("Etudiant.txt");

	string line; // pour stocker la ligne
	vector<Etudiant> listeEtudiants; // pour stocker les etudiants
	Etudiant etudiant; // pour stocker les etudiants avant de les ajouter dans le vector


	if (!etudiantTxt.fail()) {
        // Boucle qui recupere les informations du fichier texte pour les stocker dans le vector
		while (getline(etudiantTxt, line)) {
			etudiant.nom = line;
			getline(etudiantTxt, etudiant.prenom);
			getline(etudiantTxt, etudiant.codePermanent);
			getline(etudiantTxt, line);
			etudiant.anneeNaissance = stoi(line);
			getline(etudiantTxt, etudiant.programme);
			getline(etudiantTxt, etudiant.departement);

			for (int i = 0; i < 4; i++) {
				getline(etudiantTxt, line);
				etudiant.notesMoyenneTab[i] = stoi(line);
			}

			etudiant.notesMoyenneTab[4] = moyenne(etudiant);

			listeEtudiants.push_back(etudiant);
		}
	}
	else
	{
		cout << "Erreur lors de l'ouverture du fichier !" << endl;
	}

	etudiantTxt.close();

	//// Vérification pour voir si le code fonctionne correctement
	//for (int i = 0; i < 10; i++) {
	//	affichageEtudiant(listeEtudiants.at(i));
	//}

    // Menu interactif
    int choix;
    do {
        cout << endl << endl;
        cout << "Menu : " << endl;
        cout << "1. Afficher les etudiants d'une annee particuliere" << endl;
        cout << "2. Afficher les etudiants affilies a un programme particulier" << endl;
        cout << "3. Afficher les etudiants affilies a un departement particulier" << endl;
        cout << "4. Quitter" << endl;
        cout << "Choix : ";
        cin >> choix;

        switch (choix) {
        case 1: {
            int annee;
            cout << "Entrez l'annee : ";
            cin >> annee;
            for (int i = 0; i < 10; i++) {
                if (anneeVerification(listeEtudiants.at(i), annee)) {
                    affichageEtudiant(listeEtudiants.at(i));
                }
            }
            break;
        }
        case 2: {
            string programme;
            cout << "Entrez le programme : ";
            cin.ignore();
            getline(cin, programme);
            for (int i = 0; i < 10; i++) {
                programmeEtudeVerification(listeEtudiants.at(i), programme);
            }
            break;
        }
        case 3: {
            string departement;
            cout << "Entrez le departement : ";
            cin.ignore();
            getline(cin, departement);
            for (int i = 0; i < 10; i++) {
                deperatmentVerification(listeEtudiants.at(i), departement);
            }
            break;
        }
        case 4:
            cout << "Au revoir !" << endl;
            break;
        default:
            cout << "Choix invalide. Veuillez entrer un nombre entre 1 et 4." << endl;
        }
    } while (choix != 4);


	return 0;
}

