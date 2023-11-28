/* Maxime Lestiboudois */
/* 02/10/2023 */
/* Laboratoire 7: calculer la variance et la moyenne de nombres fournis par l'utilisateur*/

#include <iostream>
using namespace std;

int main(){
	double nb_introduit = 0.0;
	double xi = 0.0;
	double xi_au_carre = 0.0;
	int n = 0;
	
	cout << "Introduire un nombre supérieur ou égal à 0, "
		"ou négatif pour arrêter la saisie \n";	 
		
	while(nb_introduit >= 0){
	
		cin >> nb_introduit;
		if(nb_introduit >= 0){
			xi += nb_introduit;
			xi_au_carre += nb_introduit * nb_introduit; 
			n++;
		  }
	}
	  
	//calcul de la moyenne et de la variance:
	double moyenne = xi / n;
	double variance = (xi_au_carre - xi * xi / n) / (n - 1);
	
	//Affichage des résultats
	if(n == 0){
		cout << "Vous n'avez introduit aucune donnée exploitable" << endl;
	 }
	 else if(n == 1){
		cout << "La moyenne est de " << moyenne <<
		 " mais on ne peut calculer la variance avec une unique donnée" << endl;
	  }
	 else {
	 	cout << "La moyenne est de " << moyenne 
	 	<< " et la  variance est de " << variance << endl;
	  }
}
