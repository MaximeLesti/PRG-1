/* Maxime Lestiboudois */
/* 03/12/2023 */
/* Laboratoire 11 : Exercer l'écriture de fonctions génériques et analyse de la complexité d'algorithme de tri. */

//Tri par fusion
template <typename T>
std::vector<T> fusion(const std::vector<T> & v, const std::vector<T> & w){

	std::vector<T> liste_triee;
	//Si un vecteur est vide, on renvoie l'autre
	if(v.empty()) return w;
	if(w.empty()) return v;
	
	//Tri des vecteurs   
	//Cette fonction peut être résolue en un temps en O(nlog(n))
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

//Tri par fusion insertion
template <typename T>
void fusion_insertion(std::vector<T> & v, const std::vector<T> & w){
	//Si v est vide, on renvoie uniquement le vecteur w
	if(v.empty()) {
		v = w; 
		return;
	}
	//Insertion du vecteur w dans le vecteur v trié de manière croissante
	//Cette fonction peut être résolue en un temps O(nlog(n))
	for(int j=0; j< w.size(); ++j){
		for(int i = 0; i < v.size() ; ++i){
			if(w[j]<v[i]){
				v.insert(v.begin()+i, w[j]);
				break;
			}
		}
	}
	
}


//Tri par bulles d'un vecteur unique
template <typename T> 
void tri_a_bulle(std::vector<T> & v){

	int end = v.size();
	//Tri du vecteur
	//Cette fonction peut être résolue en un temps Big_Oméga(n) si le vecteur est déjà trié et au pire des cas, en un temps O(n²) 
	for(int j = 1; j < v.size() ; ++j){
		bool est_trie = true;
		for(int i = 1; i < end ; ++i){
			if(v[i] < v[i-1]){
				T pas = v[i];
				v[i]  = v[i-1];
				v[i-1] = pas;
				est_trie = false;
			}
		}
		--end;
		if(est_trie){
			break;
		}
	}
	
}
