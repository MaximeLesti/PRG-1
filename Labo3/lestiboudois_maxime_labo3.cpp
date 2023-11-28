/* Additionner des nombres représentant des kilomètres, mètres, centimètres et millimètres*/
/* Maxime Lestiboudois */
/* 25 septembre 2023 */

#include <iostream>
using namespace std;

int main(){

	const int kilometre_en_millimetres=1'000'000;
	const int metre_en_millimetres=1000;
	const int centimetre_en_millimetres=10;
	const int prendre_1_decimale=10;
	const int prendre_2_decimales=100;
	const int prendre_3_decimales=1000;

	int nb_kilometres_1;
	int nb_metres_1;
	int nb_centimetre_1;
	int nb_millimetre_1;
	int nb_kilometre_2;
	int nb_metre_2;
	int nb_centimetre_2;
	int nb_millimetre_2;

	// Introduction des données
	cout << "Entrez les premiers nombres (kilomètres, mètres, centimètres, millimètres) séparés d'un espace: \n";
	cin >> nb_kilometres_1 >> nb_metres_1 >> nb_centimetre_1 >> nb_millimetre_1;
	cout << "Entrez les nombres à additionner (kilomètres, mètres, centimètres, millimètres) séparés d'un espace: \n";
	cin >> nb_kilometre_2 >> nb_metre_2 >> nb_centimetre_2 >> nb_millimetre_2;

	//calcul du résultat
	int nombre1= nb_kilometres_1*kilometre_en_millimetres + nb_metres_1*metre_en_millimetres + nb_centimetre_1*centimetre_en_millimetres + nb_millimetre_1;
	int nombre2= nb_kilometre_2*kilometre_en_millimetres + nb_metre_2*metre_en_millimetres + nb_centimetre_2*centimetre_en_millimetres + nb_millimetre_2;

	int nombre=nombre1+nombre2;

	int nombre_millimetre= nombre%prendre_1_decimale;
	nombre=(nombre-nombre_d)/prendre_1_decimale;
	int nombre_centimetre=nombre%prendre_2_decimales;
	nombre=(nombre-nombre_c)/prendre_2_decimales;
	int nombre_metre=nombre%prendre_3_decimales;
	int nombre_kilometre=(nombre-nombre_b)/prendre_3_decimales;


	// Affichage du résultat
	cout << "Le résultat est: "<< nombre_kilometre << "km, "<< nombre_metre <<"m, "<< nombre_centimetre << "cm, " << nombre_millimetre << "mm \n";

}
