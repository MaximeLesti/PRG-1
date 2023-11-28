/* Maxime Lestiboudois */
/* 14/11/2023 */
/* Laboratoire 17: Rétablir les bonnes valeurs de taille (aux bons endroits) dans un enregistrement audio */
#include <iostream>
#include <fstream>
using namespace std;

//Déclaration de constantes
const uint32_t pos_taille_donnees = 40;
const uint32_t pos_taille_fichier = 4;
const uint32_t huit = 8;
int nombres_octet_a_modifier = 4;

int main(){


	string nom_fichier;
	int compt=1;
	cout << "Quel fichier audio voulez-vous ouvrir (sans l'extension)" << endl;
	getline(cin, nom_fichier);
	string fichier = nom_fichier + "_"+ to_string(compt) + "_.wav";
	string sys = "cp " + nom_fichier + ".wav " + fichier ;
	system(sys.data());
	fstream audio(fichier, ios::in | ios::out |ios::ate | ios::binary);
	
	
	uint32_t taille_fichier = audio.tellg();
	
	uint32_t taille_nette_fichier = taille_fichier - huit;
	uint32_t taille_donnees = taille_fichier - pos_taille_donnees;

	
	audio.seekp(pos_taille_donnees);
	audio.write((char*)&taille_nette_fichier, nombres_octet_a_modifier);
	
	audio.seekp(pos_taille_fichier);
	audio.write((char*) &taille_donnees, nombres_octet_a_modifier);
	
	audio.close();

}
