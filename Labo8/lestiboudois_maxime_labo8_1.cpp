/*Maxime Lestiboudois*/
/*06/10/2023*/
/*Laboratoire 8: Translation de nombres entiers non négatif en base 2 écrits à l'envers*/
		 
#include <iostream>
using namespace std;

int main(){
	
	const int base = 2;
	int nombre;
	int reste;

	//Introduction des données
	cout << "Introduire un nombre qui sera transcrit en base 2" << endl;
 	cin >> nombre;
 	
 	//Calcul et affichage du nombre en base 2
 	cout << "Le nombre " << nombre << " vaut ";
 	while(nombre > 0){
 		reste = nombre % base;
 		nombre /= base;
 		cout << reste;
 	  }
 	cout << " en base 2" << endl;
}
 		
