/* Maxime Lestiboudois */
/* 08/12/2023 */ 
/* Laboratoire 23: Rendre générique la procédure du tri par peigne données, de sorte qu’elle prenne en paramètre 2 itérateurs à accès direct. Comparer le temps de calcul de cette procédure pour trier des vector<int> avec celui de std::sort. */

#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>


//Déclaration fonctions
template <typename Iterator>
void tri_peigne(Iterator first, Iterator last);
void tri_peigne_primaire(std::vector<double> & v);

/*int main(){
	std::vector<int> v = {1,3,2,5,4,9,7};
	
	tri_peigne(v.begin(), v.end());
	
	for(auto e:v){
		std::cout << e << " ";
	}
	std::cout << std::endl;
		
}*/
int main() {
	size_t n = 100;
	double temps; // Temps pour trier n nombres
	do {
		std::vector<int> v;
		v.reserve(n);
		for (size_t i = 0; i < n; ++i) // Création d’un vector de n entiers aléatoires
			v.push_back(rand());

		std::chrono::high_resolution_clock::time_point heure_avant = 
			std::chrono::high_resolution_clock::now();
		tri_peigne(v.begin(), v.end());
		//std::sort(v.begin(),v.end());
		temps = std::chrono::duration_cast<std::chrono::duration<double>>
			(std::chrono::high_resolution_clock::now()-heure_avant).count();
		std::cout << n << " " << temps << std::endl;
		n *= 2;
	} while (temps < 20.0);
}

/*Résutat tri_peigne:
100 7.5098e-05
200 0.000166975
400 0.000409275
800 0.000928221
1600 0.00194171
3200 0.00443395
6400 0.00879086
12800 0.017755
25600 0.0210186
51200 0.0446726
102400 0.092208
204800 0.161079
409600 0.346599
819200 0.664144
1638400 1.44858
3276800 3.07891
6553600 6.60188
13107200 14.2177
26214400 28.2094

*/
/* Résultat std::sort:
100 8.7227e-05
200 0.000161762
400 0.000352712
800 0.000217582
1600 0.000475369
3200 0.00103973
6400 0.00213052
12800 0.00455437
25600 0.00816969
51200 0.0164092
102400 0.0342151
204800 0.0643117
409600 0.118926
819200 0.25224
1638400 0.520227
3276800 1.07868
6553600 2.23241
13107200 4.68784
26214400 9.69045
52428800 20.1921
*/



template <typename Iterator>
void tri_peigne(Iterator first, Iterator last) {
auto delta = std::distance(first, last);
	while (delta > 34) { // Ordonner grossièrement avec un peigne aux dents écartées
		delta /= 1.33; // Diminuer l’écart des dents du peigne
		for (auto i = first, j= next(i, delta); j != last; ++i, ++j)
			if (*i > *j) {
				std::swap(*i, *j);
			}
		}
	for (auto i = first; i != last; ++i) { // Appliquer un tri par insertion standard
		double tmp = *i;
		auto j = i;
		while (j != first and *(j-1) > tmp) {
			std::swap(*j, *(j-1));
			--j;
		}
		*j = tmp;
	}
}


void tri_peigne_primaire(std::vector<double> & v) {
std::size_t delta = v.size();
	while (delta > 34) { // Ordonner grossièrement avec un peigne aux dents écartées
		delta /= 1.33; // Diminuer l’écart des dents du peigne
		for (std::size_t i = 0; i < v.size() - delta; ++i)
			if (v[i] > v[i + delta]) {
				std::swap(v[i], v[i+delta]);
			}
		}
	for (std::size_t i = 1; i < v.size(); ++i) { // Appliquer un tri par insertion standard
		double tmp = v[i];
		std::size_t j = i;
		while (j > 0 and v[j-1] > tmp) {
			std::swap(v[j], v[j - 1]);
			--j;
		}
		v[j] = tmp;
	}
}
