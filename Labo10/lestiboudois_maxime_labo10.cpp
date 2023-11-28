/* Maxime Lestiboudois */
/* 13/10/2023 */
/* Laboratoire 10: Evaluation de la racine carrée */

#include <iostream>
#include <iomanip>
using namespace std;

//Déclaration de structures
struct Racine_et_nb_iteration {double ma_racine; int nb_iteration;};
//Déclaration de fonctions
double moyenne_deux_nombres(double, double);
Racine_et_nb_iteration ma_racine_et_mon_nb_iteration(double, int);
//Déclaration de constantes
const int nb_chiffres_significatifs = 10;


int main(){
	
	//Déclaration de variable
	double nombre;
	int precision;
	
	//Introduction des données
	cout << "Introduire un nombre positif et un nombre entier spécifiant la précision du résultat"
	<< endl;
	cin >> nombre  >> precision;
	
	//calcul des données à l'aide de focntions
	Racine_et_nb_iteration mes_deux_informations = ma_racine_et_mon_nb_iteration(nombre, precision);
	
	//Affichage du résultat
	cout << "La racine carrée de " << nombre << " est " 
	<< setprecision(nb_chiffres_significatifs) << mes_deux_informations.ma_racine 
	<< "\nVoici le nombre d'itérations nécessaires à l'obtention de ce résutat: "
	<< mes_deux_informations.nb_iteration 
	<< endl;
		
}
//Fonction déterminant la moyenne entre deux nombres
double moyenne_deux_nombres(double a, double b){
	return (a + b) / 2;
}

Racine_et_nb_iteration ma_racine_et_mon_nb_iteration(double nombre, int precision){
	//Déclaration de constantes liée à la fonction
	const int bit_maximal = 50;
	const int bit_minimal  = 1;
	
	//Déclaration de variables
	Racine_et_nb_iteration mes_deux_informations;
	int compt = 0;
	double facteur_de_precision = 1;
	if(nombre < 0){
		mes_deux_informations.ma_racine = 0.0 / 0.0;
	}
	else{
		//Calcul du facteur de précision
		if(precision > bit_maximal){
			precision = bit_maximal;
		}
		else if(precision < bit_minimal){
			precision = bit_minimal;
		}
		
		for(int i = 0 ; i < precision ; ++i){
			facteur_de_precision *= 2;
		}
		facteur_de_precision = 1 / facteur_de_precision;

		//Calcul de la racine carrée et du nombre d'itération
		double r = nombre / 2;
		if(r*r != nombre){
			do{
				compt++;
				r = moyenne_deux_nombres(r, nombre / r);
				
			} while((r * r - nombre) >=  facteur_de_precision * nombre);
		}
		mes_deux_informations.ma_racine = r;
	}
	mes_deux_informations.nb_iteration = compt;
	
	return mes_deux_informations;
}

