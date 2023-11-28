/* Maxime Lestiboudois */
/* 27/11/2023 */
/* Laboratoire 11 : Exercer l'écriture de fonctions génériques et analyse de la complexité d'algorithme de tri. */

//Déclaration de constante
template <typename T>

std::vector<T> fusion(const std::vector<T> & v, const std::vector<T> & w){

	std::vector<T> liste_triee;
	if(!v.size()) liste_triee = w;
	if(!w.size()) liste_triee = v;
	
	for(int i = 0 ; i < v.size(); ++i){
		for(int j = 0; j < w.size() ; ++j){
			if(w[j]<v[i]){
				liste_triee.push_back(w[j]);
			}
			else{
				liste_triee.push_back(v[i]);
			}
		}
	}
	
	return liste_triee;
	
}

std::vector<T> fusion_insertion(std::vector<T> & v, const std::vector<T> & w){
	
	if(!v.size()) liste_triee = w;
	if(!w.size()) liste_triee = v;
	
	int n = v.size();
	int m = w.size();
	
	for(int i = n-1; i == 0 ; ++i){
		int j = m-1;
		int pos_ins = n + m - 1;
		
		while(j>=0){
			if(w[j] > v[i]){
				v[pos_ins] = w[j];
				j -=1;
			}
			else{
				v[pos_ins] -= 1;
			}
		}
	}
	
	while(j>0
	
	return v;
	
	
	
}

void tri_a_bulle(std::vector<T> &v){
	
	for(int i = v.size()-1; i > 0; ++i){
		bool trie = false;
		if(!trie){
			for(int j = 0 ; j < i; ++j){
				if(v[j+1] < v[j]){
					T pas = v[j+1];
					v[j+1] = v[j];
					v[j] = pas;
					trie = false;
				}
				else trie = true;
			}
		}
	}
	return v;	
}
