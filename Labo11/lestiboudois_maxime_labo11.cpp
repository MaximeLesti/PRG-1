/* Maxime Lestiboudois */
/* 17/10/2023 */
/* Laboratoire 11: Déterminer si un nombre fournit par l'utilisateur est premier */

#include <iostream>
#include <random>

using namespace std;

//Déclaration de fonctions
bool est_ce_premier(int);
bool est_ce_premier_naif(int);
int exponentiation_modulaire(int, int, int);
void imprime_deux_cents_nombres_premiers_suppl(int);

int main(){

	
	//Déclaration de variables
	int nombre;
	
	//Introduction de données
	cout << "Introduire un nombre: " << endl;
	cin >> nombre;
	 //Calcul du résultat
	bool est_premier = est_ce_premier(nombre);
	
	//Affichage du résultat
	if(est_premier) cout << "Le nombre " << nombre << " est premier" << endl;
	else cout << "Le nombre " << nombre << " n'est pas premier" << endl;
	imprime_deux_cents_nombres_premiers_suppl(nombre);
	
}
bool est_ce_premier_naif(int p){
	
	int nb_iteration;
	
	if(p % 2 == 0){
		nb_iteration = p / 2;
	}
	else {
		nb_iteration = (p - 1) / 2;
	}
	for (int i=2 ; i<= nb_iteration ; ++i){
		if(p % i == 0){
			return false;
		}
	}
	return true;
}
bool est_ce_premier(int p){
	 
	int nombre_random;
	
	if(p < 2) {
		return false;
	}
	if(p == 2) {
		return true;
	}
	
	for (int i = 0 ; i < 10 ; ++i){	
		do{
			nombre_random = rand() % p;
		} while(nombre_random == 0);
		
		if(exponentiation_modulaire(nombre_random, (p - 1), p) != 1) {

		 	return false;
		 }
		 int q = 1;
		 int u = p - 1;
		 
		 while(u % 2 == 0 and q == 1){
			u = u / 2;
			q = exponentiation_modulaire(nombre_random, u, p);
			if( q != 1 and q != p-1) {

				return false;
			}				
	 	}
	}
	return true;
}

int exponentiation_modulaire(int b, int e, int m){
	
	int r = 1;
	while(e > 0){
		if(e % 2 == 0){
			b = (b * b) % m;
			e = e / 2;
		}
		else {
			r = (r * b) % m;
			e = e - 1;
		}
	}
	return r;
}

void imprime_deux_cents_nombres_premiers_suppl(int p){
	int compt = 0;
	int i = 0;
	cout <<  "Voici les deux cents prochains nombres premiers: " << endl;
	do {
		if(est_ce_premier(p+i)){
			cout << p+i << " ";
			++compt;
		}
		++i;
	}while(compt != 200);
	cout << endl;
}
