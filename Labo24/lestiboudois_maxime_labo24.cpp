/* Maxime Lestiboudois */
/* 26.01.2024 */ 
/*  */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

#include "lestiboudois_maxime_uint.hpp"
#include "lestiboudois_maxime_sint.hpp"
#include "lestiboudois_maxime_rationnel.hpp"
#include "lestiboudois_maxime_pivotage.cpp"


//Déclaration de constantes
const char separateur = ' ';
	
	
using namespace std;

int main(){
	try{

		string nom;
		string str;
		cout << "Quel fichier voulez-vous ouvrir?" << endl;
		getline(cin, nom);
		fstream mon_fichier(nom, ios::in | ios::out);
		getline(mon_fichier, str, separateur);
		int m = stoi(str);
		getline(mon_fichier, str, separateur);
		vector<Rationnel> sol(m);
		vector<vector<Rationnel>> matrice(m, sol);
		
		for (int i = 0; i < m ; ++i){
			for(int j = 0; j < m; ++j){
				Rationnel a;
				mon_fichier >> a;
				
				matrice[i][j] = a;
			}
		}
		for(int i = 0 ; i < m ; ++i){
			Rationnel a;
			mon_fichier >> a;
			sol[i] = a;
		}
	
		mon_fichier.close();
	
	
	/*std::vector<std::vector<Rationnel>> matrice = {
	{Rationnel(Sint(1),Sint(1)), Rationnel(Sint(2),Sint(1)), Rationnel(Sint(3),Sint(1))},
	{Rationnel(Sint(1),Sint(1)), Rationnel(Sint(0), Sint(1)), Rationnel(Sint(8), Sint(1))},
	{Rationnel(Sint(2), Sint(1)), Rationnel(Sint(5), Sint(1)), Rationnel(Sint(3), Sint(1))}
	};
	
	std::vector<Rationnel> sol = {Rationnel(Sint(3), Sint(1)),Rationnel(Sint(8), Sint(1)),Rationnel(Sint(2),Sint(1))};
	*/
	cout << "-----" <<endl;
	for(int i = 0; i < m; ++i){
		for(int j = 0; j<m; ++j){
			cout << matrice[i][j];
		}
	cout << " "<<char('x'+i)<< "   " << sol[i] << endl;
	}
	
		cout << "-----" <<endl;
	
	vector<Rationnel> solution = pivotage(matrice, sol);
	
	for(int i = 0; i<sol.size(); ++i){	
		std::cout << solution[i]<<" " <<std::endl;
	}
	
	Sint a = Sint(9);
	Sint b= Sint(6);
	cout <<"ici   " <<  a+b <<endl;
	
	}
	
	catch(Rationnel_creation e){
		cout << e.what() << endl;
	}
	catch(Uint_attribut e){
		cout << e.what() << endl;
	}
	catch(exception & e){
		cout << e.what() << endl;
	}
}
