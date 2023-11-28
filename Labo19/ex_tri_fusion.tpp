/* Maxime Lestiboudois */
/* 27/11/2023 */
/* Laboratoire 11 : Exercer l'écriture de fonctions génériques et analyse de la complexité d'algorithme de tri. */

template <typename T>
std::vector<T> fusion(const std::vector<T> & v, const std::vector<T> & w){

	std::vector<T> liste_triee;
	
	if(!v.size()) return w;
	if(!w.size()) return v;
	
	int init = 0;
	for(int i = 0 ; i < v.size(); ++i){
		for(int j = init; j < w.size() ; ++j){
			if(w[j]<v[i]){
				liste_triee.push_back(w[j]);
				++init;
				
			}
			else{
				liste_triee.push_back(v[i]);
				break;
				
			}
		}
		if(init == w.size()){
			liste_triee.push_back(v[i]);
		}
		
	}
	
	return liste_triee;
	
}


template <typename T>
void fusion_insertion(std::vector<T> & v, const std::vector<T> & w){
	
	if(!v.size()) {
		v = w; 
		return;
	}
	
	for(int j=0; j< w.size(); ++j){
		for(int i = 0; i < v.size() ; ++i){
			if(w[j]<v[i]){
				v.insert(v.begin()+i, w[j]);
				break;
			}
		}
	}
	
}



template <typename T> 
void tri_a_bulle(std::vector<T> & v){
	int end = v.size();
	for(int j = 1; j < v.size() ; ++j){
		for(int i = 1; i < end ; ++i){
			if(v[i] < v[i-1]){
				T pas = v[i];
				v[i]  = v[i-1];
				v[i-1] = pas;
			}
		}
		--end;
	}
	
}
