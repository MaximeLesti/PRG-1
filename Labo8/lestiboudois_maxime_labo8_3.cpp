/* Maxime Lestiboudois */
/* 06/10/2023 */
/* Laboratoire 8: Impression de carrés imbriqués avec des lettres de l'alphabet */

#include <iostream>
using namespace std;

const int nb_lettres_alphabet = 26;
int main(){
	int nombre;
	int diff;
	
	//Introduction des données
	cout << "Introduire le nombre de carrés imbriqués" << endl;
	cin >> nombre;
	
	//Calcul de la taille du tableau
	int nb_elements_tableau = nombre*2-1;

	//Afficher les éléments dans le tableau
	for(int i = 0; i < nb_elements_tableau ; ++i){
		for(int j = 0; j < nb_elements_tableau; ++j){
		
			//Trouver l'élément le plus proche du bord
			diff = nb_elements_tableau -i-1;
			if (diff > nb_elements_tableau - j-1){
				diff = nb_elements_tableau -j-1;
			}
			if(diff > i){
				diff = i;	
			}
			if( diff > j){
				diff = j;
			}
			
			//Afficher la lettre selon le résultat trouvé précédemment
			cout << char('A'+(nombre-1-diff)% nb_lettres_alphabet) << " ";
			
			
			  
		  }

		cout << endl;
	}
	

}


