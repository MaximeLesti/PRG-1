/* Maxime Lestiboudois */
/* 09/10/2023 */
/* 10/10/2023 */
/* Laboratoire 9: Approximer la valeur de pi à l'aide de valeurs aléatoires (bibliothèqe <random>) */

#include <iostream>
#include <random>
#include <functional>

auto gen_double01 = std::bind(std::uniform_real_distribution<double>(0,1), std::mt19937(1234)); // germe: 1234

const int unite = 1;
const int nb_points_total = 1000000;
const int axes=4;

int main(){
	
	int nb_points=0;
	
	//Calcul des points appartenant à l'arc de cercle d'unité
	for(int i=0; i<nb_points_total; ++i){
	
		double x = gen_double01();
		double y=gen_double01();
		
		double distance = sqrt(x*x + y*y);
		
		if( distance <= unite){
			nb_points++;
		}

	}
	//Calcul de pi
	double pi= ((double)nb_points/nb_points_total)*axes;
	
	//Affichage du résultat
	std::cout << pi << std::endl;

} 
