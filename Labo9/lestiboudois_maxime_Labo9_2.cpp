/* Maxime Lestiboudois */
/* 10/10/2023 */
/* Laboratoire 9 : partie 2, Jeu des trois portes fermées : calcul du taux de succès selon diverses tactiques */

#include <iostream>
#include <random>
#include <functional>


auto gen_int1_3 = std::bind(std::uniform_int_distribution<int>(1,3), std::mt19937(987)); // un germe
auto gen_pile_ou_face = std::bind(std::uniform_int_distribution<int>(0,1), std::mt19937(1024)); // un autre germe
const int premiere_porte = 1;
const int pile = 0;

int main() {

	int nm_tactique;
	int nb_simulations;
	int succes = 0;
	int ma_porte;
	//Introduction des données
	std::cout << " Quelle stratégie voulez-vous adopter? \n"
		"1. Vous choisissez la première porte et vous conservez ce choix \n"
		"2. Vous choisissez une porte au hasard et vous conservez ce choix \n"
		"3. Vous choisissez la première porte, puis vous ouvrez une autre porte \n"
		"4. Vous choisissez une porte au hasard, puis vous ouvrez une autre porte \n"
		"5. Vous choisissez une porte au hasard, puis vous tirez à pile ou face la porte à ouvrir \n"
		"Entrez le numéro de la tactique choisie"
		<< std::endl;
	std::cin >> nm_tactique;
	std::cout << "Combien de simulation voulez-vous effectuer?" << std::endl;
	std::cin >> nb_simulations;

	for(int i=0 ; i < nb_simulations ; ++i){
	
		int bonne_porte = gen_int1_3();
		
		switch(nm_tactique){
			case 1 : {
				ma_porte = premiere_porte;
				if(bonne_porte == ma_porte){ ++succes; }
				break;
				 }
			case 2 : {
				ma_porte = gen_int1_3();
				if(bonne_porte == ma_porte) { ++succes; }
				break;
				 }
			case 3 : {
				ma_porte = premiere_porte;
				if(bonne_porte != ma_porte) { ++succes; }
				break;
				 }
			case 4 : {
				ma_porte = gen_int1_3();
				if(bonne_porte != ma_porte) { ++succes; }
				break;
				 }
			case 5 : {
				ma_porte = gen_int1_3();
				int pile_ou_face = gen_pile_ou_face();
				if(pile_ou_face == pile){
					if(bonne_porte == ma_porte) { ++succes; }
						}
				else {
					if(bonne_porte != ma_porte) { ++succes; }
				     }
				break;
				}
			default : { 
		 		std::cout << "Vous n'avez pas introduit un numéro de tactique cohérent" 
		 		     << std::endl;
		 		break; }
		}
	}
	double taux_de_succes = (double)succes / nb_simulations;
	std::cout << "Le taux de succès est de " << taux_de_succes << std::endl;
}
