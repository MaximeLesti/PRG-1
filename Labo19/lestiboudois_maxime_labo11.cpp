/* Maxime Lestiboudois */
/* 27/11/2023 */
/* Laboratoire 11 : Exercer l'écriture de fonctions génériques et analyse de la complexité d'algorithme de tri. */

//Déclaration de constantes
#include <iostream>
#include <vector>

template <typename T>
std::vector<T> fusion(const std::vector<T> & v, const std::vector<T> & w){

	std::vector<T> liste_triee;
	
	if(!v.size()) return w;
	if(!w.size()) return v;
	
	int a =0;
	for(int i = 0 ; i < v.size(); ++i){
		for(int j = a; j < w.size() ; ++j){
			if(w[j]<v[i]){
				liste_triee.push_back(w[j]);
				++a;
				
			}
			else{
				liste_triee.push_back(v[i]);
				break;
				
			}
		}
		if(a == w.size()){
			liste_triee.push_back(v[i]);
		}
		
	}
	
	return liste_triee;
	
}


template <typename T>
std::vector<T> fusion_insertion(std::vector<T> & v, const std::vector<T> & w){
	
	if(!v.size()) return v = w;
	
	for(int j=0; j< w.size(); ++j){
		for(int i = 0; i < v.size() ; ++i){
			if(w[j]<v[i]){
				v.insert(v.begin()+i, w[j]);
				break;
			}
		}
	}
	
	return v;
	
}



template <typename T> 
void tri_a_bulle(std::vector<T> & v){
	size_t end = v.size();
	for(size_t j = 1; j < v.size() ; ++j){
		for(size_t i = 1; i < end ; ++i){
			if(v[i] < v[i-1]){
				T pas = v[i];
				v[i]  = v[i-1];
				v[i-1] = pas;
			}
		}
		--end;
	}
	
}

int main(){
	std::vector<int> un {2,4,6,7,9,11,12};
	std:: vector<int> deux {1,3,8,10};
	
	std::vector<int>fus = fusion_insertion(un, deux);
	//tri_a_bulle(un);
	
	for(int i=0; i<fus.size();++i){
		std::cout << fus[i] << " ";
	}
	std::cout << std::endl;
}
