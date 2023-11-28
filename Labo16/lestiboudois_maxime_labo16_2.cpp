/* Maxime Lestiboudois */
/* 14/11/2023 */
/* Laboratoire 16.2 : Savoir si un fichier portant un certain nom existe déjà et, s'il existe, informer sa taille, sinon le créer */
#include <iostream>
#include <fstream>
using namespace std;

int main(){
	
	string nom_fichier;
	cout << "Quel fichier vous intéresse (n'oubliez pas d'ajouter l'extension)?" << endl;
	getline(cin, nom_fichier);

	ifstream mon_fichier(nom_fichier, ios::ate);
	if(mon_fichier){
	
		int longu =(int) mon_fichier.tellg() - 1;
		cout <<"Voici la taille du fichier: " << longu <<endl;
	}
	else{
		ofstream nouveau_fichier;
		nouveau_fichier.open(nom_fichier);
		nouveau_fichier.close();
		cout << "Vous avez créé un nouveau fichier nommé " << nom_fichier << endl;
	}
}
