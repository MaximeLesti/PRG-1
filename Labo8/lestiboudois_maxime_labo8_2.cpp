/* Maxime Lestiboudois */
/* 06/10/2023 */
/* Laboratoire 8: Détermination du PPMC (Plus Petit Multiple Commun) de deux nombres positifs */

#include <iostream>
using namespace std;

//Fonction d'Euclide
int euclide(int nombre_1, int nombre_2){
	while(nombre_2 != 0){
		int t = nombre_2;
		nombre_2 = nombre_1 % nombre_2;
		nombre_1 = t;
	  }
	return nombre_1;
}

int main(){
	int nombre_1;
	int nombre_2;
	int ppmc;
	
	//Introduction des données
	cout << "Introduire deux nombres strictement positifs" << endl;
	cin >> nombre_1 >> nombre_2;
	
	//Affichage du résultat
	if(nombre_1 > nombre_2){
		ppmc = nombre_1 * nombre_2 / euclide(nombre_1,nombre_2);
	  }
	else {
				ppmc = nombre_1 * nombre_2 / euclide(nombre_2,nombre_1);
	  }
		cout << "Le PPMC de "<< nombre_1 << " et " << nombre_2 
		<< " est " << ppmc << endl; 
	
}


