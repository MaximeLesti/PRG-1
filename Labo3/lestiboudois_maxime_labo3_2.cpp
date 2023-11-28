/* Calculer le temps de trajet avec une heure d'arrivée et une heure d'arrivée*/
/* Maxime Lestiboudois */
/* 25 septembre 2023 */

#include <iostream>
using namespace std;


int main(){

	const int heure_en_minutes=60;
	const int temps_de_voyage_en_heure_maximum=24;

	int heure_de_depart_heures;
	int heure_de_depart_minutes;
	int heure_d_arrivee_heures;
	int heure_d_arrivee_minutes;

	//Introduction des données
	cout << "Introduire l'heure de départ (heures et minutes séparées par un espace): \n";
	cin >> heure_de_depart_heures >> heure_de_depart_minutes;
	cout << "Introduire l'heure d'arrivée (heures et minutes séparées par un espace): \n";
	cin >> heure_d_arrivee_heures >> heure_d_arrivee_minutes;

	//Calcul du temps de trajet
	int heure_de_depart=heure_de_depart_heures*heure_en_minutes + heure_de_depart_minutes;
	int heure_d_arrivee= heure_d_arrivee_heures*heure_en_minutes + heure_d_arrivee_minutes;

	int temps_de_trajet=heure_d_arrivee - heure_de_depart + (heure_en_minutes*temps_de_voyage_en_heure_maximum);

	int trajet_heure=(temps_de_trajet/heure_en_minutes)%temps_de_voyage_en_heure_maximum;
	int trajet_minutes=temps_de_trajet%heure_en_minutes;
	
	// Affichage du résultat
	cout << "Le trajet dure " << trajet_heure << "h" << trajet_minutes << "\n";

}
