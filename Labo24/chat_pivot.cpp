#include <iostream>
#include <vector>

double determinant_matrice_carre(const std::vector<std::vector<double>> &matrice);

std::vector<double> pivotage(const std::vector<std::vector<double>> &matrice, const std::vector<double> &coef)
{
    std::vector<double> solutions(matrice.size());
    double det = determinant_matrice_carre(matrice);

    if (det == 0.0)
    {
        std::cerr << "Le déterminant est nul, le système n'a pas de solution unique." << std::endl;
        return solutions;
    }

    for (int i = 0; i < coef.size(); ++i)
    {
        std::vector<std::vector<double>> cramer = matrice;

        for (int j = 0; j < coef.size(); ++j)
        {
            cramer[j][i] = coef[j];
        }

        solutions[i] = determinant_matrice_carre(cramer) / det;
    }

    return solutions;
}

double determinant_matrice_carre(const std::vector<std::vector<double>> &matrice)
{
    int taille_matrice = matrice.size();

    if (taille_matrice == 2)
    {
        return matrice[0][0] * matrice[1][1] - matrice[0][1] * matrice[1][0];
    }

    double coefficient = 0.0;
    int signe = 1;

    std::vector<std::vector<double>> det(taille_matrice - 1, std::vector<double>(taille_matrice - 1));

    for (int i = 0; i < taille_matrice; ++i)
    {
        signe = i % 2 == 0 ? 1 : -1;
        int compt_1 = 0;

        for (int a = 0; a < taille_matrice; ++a)
        {
            int compt_2 = 0;

            if (a != i)
            {
                for (int j = 1; j < taille_matrice; ++j)
                {
                    det[compt_1][compt_2++] = matrice[a][j];
                }

                ++compt_1;
            }
        }

        coefficient += matrice[i][0] * determinant_matrice_carre(det) * signe;
    }

    return coefficient;
}

int main()
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
}

