/* Maxime Lestiboudois */
/* 29/10/2023 */
/* Laboratoire 13.1: Fonction retournant au format string la forme binaire d'un nombre de type size_t passé en paramètre */ 

#include <iostream>
using namespace std;
//Déclaration de fonctions
string formeBinaire(size_t);
//Déclaration de constantes
const int base2 = 2;

int main(){
	
	size_t nombre;
	cout << "Entrez un nombre qui sera passé sous forme binaire" << endl;
	cin >> nombre;

	cout << nombre << " vaut " << formeBinaire(nombre) << " en format binaire" << endl;

}

string formeBinaire(size_t nombre){
	string reponse;
	string passage="";
	int reste;
	while(nombre > 0){
 		reste = nombre % base2;
 		nombre /= base2;
 		string valeur = to_string(reste);
		passage.append(valeur);

 	  }
 	  
 	  int taille_string = passage.length()-1;
 	  for(size_t i = 0; i <= taille_string ; ++i){
 	  	reponse.push_back(passage[taille_string-i]);
 	  }

	return reponse;
}
