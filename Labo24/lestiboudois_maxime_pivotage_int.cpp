
#include <iostream>
#include <vector>

int determinant_matrice_carre(const std::vector<std::vector<int>> & matrice);

std::vector<int> pivotage(std::vector<std::vector<int>> matrice, std::vector<int> coef){
	std::vector<int> solutions(matrice.size());
	int det = determinant_matrice_carre(matrice);

	if(determinant_matrice_carre(matrice) == 0) return solutions;
	for(int i  = 0 ; i < coef.size(); ++i){
	std::vector<std::vector<int>> cramer = matrice;
		
		for(int j=0 ; j < coef.size(); ++j){
			cramer[j][i] = coef[j];
		}
	
		solutions[i] = determinant_matrice_carre(cramer)/det;
	}
		
	return solutions;	
	
}


int determinant_matrice_carre(const std::vector<std::vector<int>> & matrice){

	int coefficient = 0;
	int signe = 1;
	int taille_matrice = matrice.size();
	
	std::vector<int> vecteur(taille_matrice-1);
	std::vector<std::vector<int>> det(taille_matrice-1, vecteur);
	
	bool taille_pair = (taille_matrice % 2 == 0);
	if(taille_matrice > 2){
		
		for(int i = 0; i< taille_matrice; ++i){
			signe = i%2 == 0 ? 1 : -1;
			int compt_1 = 0;
			for(int a = 0 ; a < taille_matrice; ++a){
				int compt_2 = 0;
				if(a!=i){
					for(int j = 1; j<taille_matrice; ++j){
						det[compt_1][compt_2++] = matrice[a][j];
					}
				++compt_1;
				}
			}
			coefficient += matrice[i][0] * determinant_matrice_carre(det) * signe;	
		}
	}
	
	else{
		coefficient += matrice[0][0] * matrice[1][1] - matrice[0][1] * matrice[1][0];
	}
	
	return coefficient;

	
}



int main(){

	std::vector<std::vector<int>> matrice_a ={{1,2,3},{4,5,6},{7,8,9}};
	std::vector<std::vector<int>> matrice_c ={{1,2,3,4},{5,6,7,8},{9, 10, 11,12}, {13,14,15,16}};
	std::vector<std::vector<int>> matrice_b ={{1,3},{1,2}};
	std::vector<std::vector<int>> matrice_d ={{0,0,1},{0,1,0},{1,0,0}};
	std::vector<std::vector<int>> matrice_e ={{-1,1,1,1},{1,-1,1,1},{1,1,-1,1},{1,1,1,-1}};
	
	std::vector<std::vector<int>> matrice_k ={{1,2,3},{1,0,8},{2,5,3}};
		std::vector<std::vector<int>> matrice ={
		{84,91,45,73,54,43},
		{84,76,39,22,36,94},
		{42,99,2,92,79,80},
		{48,14,72,98,63,75},
		{71,85,87,10,80,47},
		{65,64,36,8,38,90}
		};
	//std::vector<int> sol = {390,351,394,370,380,301};
	std::vector<int> sol = {3,8,2};
	std::vector<int> solution=pivotage(matrice_k, sol);
	for(int i = 0; i<sol.size(); ++i){	
		std::cout << solution[i]<<" " <<std::endl;
	}
	
}
	
	
