/* Maxime Lestiboudois */
/* 08/12/2024 */
/* Laboratoire 22: Écrire et tester une fonction générique qui indique si deux vector contiennent exactement les mêmes éléments */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Déclaration de fonctions
template <typename T>
bool memes_elements(vector<T> & a, vector<T> & b);
template <typename T>
bool a_contient_b(vector<T> & a, vector<T> & b);

	

int main(){
	vector <int> a = {1,2,3,4};
	vector <int> b = {1,2,4,3,3}; 
	
	bool identique = memes_elements(a,b);
	
	cout << identique <<endl;
	
}



template <typename T>
bool memes_elements(vector<T> & a, vector<T> & b){

	return (a_contient_b(a,b) && a_contient_b(b, a));
		
}
template <typename T>
bool a_contient_b(vector<T> & a, vector<T> & b){
	for(auto e: a){
			if(find(b.begin(), b.end(), e) != b.end())	
				continue;
			else
				return false;
		}
		
		return true;
}

