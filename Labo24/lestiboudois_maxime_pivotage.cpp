#include <iostream>
#include <vector>

Rationnel determinant_matrice_carre(const std::vector<std::vector<Rationnel>> & matrice);

std::vector<Rationnel> pivotage(const std::vector<std::vector<Rationnel>> & matrice, const std::vector<Rationnel> & coef){

	std::vector<Rationnel> solutions(matrice.size());
	Rationnel det = determinant_matrice_carre(matrice);
std::cout << "det " << det <<std::endl;									
	if(det == Rationnel(Sint(0),Sint(1))){
    		throw std::out_of_range("Déterminant égal à 0, le système n'a pas de solution");
        	return solutions;
	}

	for(int i = 0; i < coef.size(); ++i){
		std::vector<std::vector<Rationnel>> cramer = matrice;
		for (int j = 0; j < coef.size(); ++j){
			cramer[j][i] = coef[j];
		}
std::cout << " debut " << std::endl;
	for(int i = 0; i < cramer.size() ; ++i){
		for(int j = 0 ; j < cramer.size(); ++j){
			std::cout << cramer[i][j] << " ";
		}
		std::cout << std::endl;
	}
std::cout << " fin " << std::endl;	

std::cout << "determinant_matrice_carre(cramer) " << determinant_matrice_carre(cramer) <<std::endl;									
		solutions[i] = determinant_matrice_carre(cramer) / det;
	}

	return solutions;
}

Rationnel determinant_matrice_carre(const std::vector<std::vector<Rationnel>> & matrice){

	int taille_matrice = matrice.size();

	if(taille_matrice == 2){
	std::cout << "00 " << matrice[0][0] <<std::endl;									
	std::cout << "11 " << matrice[1][1] <<std::endl;									
	std::cout << "01 " << matrice[0][1] <<std::endl;									
	std::cout << "10 " << matrice[1][0] <<std::endl;
	std::cout << "det " << matrice[0][0] * matrice[1][1] - matrice[0][1] * matrice[1][0] <<std::endl;							
		return matrice[0][0] * matrice[1][1] - matrice[0][1] * matrice[1][0];
	}

	Rationnel coefficient = Rationnel(Sint(0),Sint(1));

	Rationnel signe = Rationnel(Sint(1), Sint(1));

	std::vector<Rationnel> vecteur(taille_matrice-1, Rationnel(Sint(0),Sint(1)));
	std::vector<std::vector<Rationnel>> det(taille_matrice-1, vecteur);

	for(int i = 0; i < taille_matrice; ++i){
		signe = i % 2 == 0 ? Rationnel(Sint(1),Sint(1)) : Rationnel(Sint(-1),Sint(1));
		int compt_1 = 0;
		for(int a = 0; a < taille_matrice; ++a){
			int compt_2 = 0;
			if (a != i){
				for (int j = 1; j < taille_matrice; ++j){
					det[compt_1][compt_2++] = matrice[a][j];
				}
				++compt_1;
			}
		}
std::cout <<"signe " << signe <<std::endl;
std::cout <<"   dsf "<< determinant_matrice_carre(det) * signe << std::endl;
		coefficient += matrice[i][0] * determinant_matrice_carre(det) * signe;
	}

	return coefficient;
}

/*int main()
{
    // Exemple d'utilisation
    //std::vector<std::vector<double>> matrice ={{1,2,3},{1,0,8},{2,5,3}};
    //std::vector<std::vector<double>> matrice = {{2, 1, -1}, {-3, -1, 2}, {-2, 1, 2}};
    //std::vector<double> coefficients = {3,8,2};
  //  std::vector<double> coefficients = {8, -11, -3};
  std::vector<std::vector<double>> matrice ={
		{84,91,45,73,54,43},
		{84,76,39,22,36,94},
		{42,99,2,92,79,80},
		{48,14,72,98,63,75},
		{71,85,87,10,80,47},
		{65,64,36,8,38,90}
		};
	std::vector<double> coefficients = {390,351,394,370,380,301};

    std::vector<double> solutions = pivotage(matrice, coefficients);

    std::cout << "Solutions du système : ";
    for (const double &sol : solutions)
    {
        std::cout << sol << " ";
    }
    std::cout << std::endl;

    return 0;
}*/

