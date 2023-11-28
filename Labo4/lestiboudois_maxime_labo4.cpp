/* Indiquerle nombre de minutes et de secondes d'une montre à partir de dixième de degrés */
/* Maxime Lestiboudois*/
/* 25 septembre 2023 */

#include <iostream>
using namespace std;

int main(){
	
	const int rapport_secondes_minutes=60;
	const int decalage_horaire =15*rapport_secondes_minutes;
	const int nb_total_secondes=3600;

	
	//Introduction des données
	int dixieme_de_degrees;
	cout << "Introduire le nombre de dixième depuis l'horizontal:\n";
	cin >> dixieme_de_degrees;
	
	//adaptation de l'angle afin de rester dans le scope de la montre et de pallier au décalage mathématique
	int angle=nb_total_secondes - (dixieme_de_degrees%nb_total_secondes)+decalage_horaire;
	
	//calculs
	int minutes= (angle/rapport_secondes_minutes)%rapport_secondes_minutes;
	int secondes=angle%rapport_secondes_minutes;

	//Affichage du résultat
	cout << "L'aiguille des minutes indique " << minutes << " minutes et " << secondes << " secondes \n" ;
	
	
	

}
