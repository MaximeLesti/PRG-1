/* Maxime Lestiboudois */
/* 22/11/2023 */
/* Laboratoire 18.2: Implémenter un programme capable de résoudre un système d'équations à n inconnues, nb spécifié par l'utilisateur. */ 

#include <iostream>
#include <vector>
using namespace std;

using Ligne = vector<int>;
//Déclaration de constantes

//Déclaration de fonctions


int main(){

	int nb_inconnues;
	cout << "Entrez le nombre d'inconnues de votre système" << endl;
	cin >> nb_inconnues;
	int nb_colonnes;
	int nb_lignes;
	int element;
	
	vector<Ligne> matrice;
	
	cout << "Entrez les éléments de la matrice" << endl;
	int i = 0;
	while(i<nb_colonnes){
		int j=0;
		Ligne ligne;
		while (j < nb_lignes){
			cin >> element;
			ligne.push_back(element);
			++j;
		}
		matrice.push_back(ligne);
		++i;
	}
	
	for(int k=1; k < nb_lignes; ++k){
		int pivot = matrice[k][k];
		if(pivot != 0){
			for(int i = k+1; i <= nb_lignes ; ++i){
				matrice[i] -= matrice!!!!!!!!!!!;
				
				for(int j = k+1; j<= nb_lignes ; ++j){
					matrice[i][j] -= matrice[i][k]* matrice[k][j]/pivot 
				}
			}
		}
		else{
			cout << "Il y a un problème" << endl;
			break;
		}
			
	
			
	
	
	
	
	

}

