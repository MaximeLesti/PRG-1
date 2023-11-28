/* Maxime Lestiboudois */
/* 17/11/2023 */
/* Concaténer  les README.txt des différents laboratoires*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Déclaration de constantes
const string nom = "README.txt";
const string sep (100, '-');

int main(){

	int compt = 0;
	int nb_fichier;
	string nom_fichier;
	string rme ="Résumé des laboratoires \n\n" + sep + '\n'+ '\n';
	cout << "Combien de fichiers devez-vous concaténer?" << endl;
	cin>>nb_fichier;
	/*cout <<"Comment voulez-vous appeler votre fichier (sans extension)?"<<endl;
	cin >> nom_fichier;*/
	nom_fichier = "README.txt";

	while(compt != nb_fichier){
		string str;
		
		string name = "Labo"+to_string(++compt)+"/" + nom;
		fstream fichier_a_lire(name);
		if(!fichier_a_lire) continue;
		while(getline(fichier_a_lire, str)){
			rme += str + '\n';
		}
		
		fichier_a_lire.close();

		 rme += '\n' + sep + '\n'+ '\n' ;
	}
	
	
	ofstream readme;
	readme.open(nom_fichier);
	readme<<rme;
	readme.close();
	system("gedit README.txt");
}
