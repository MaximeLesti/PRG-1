/* Maxime Lestiboudois */
/* 29/10/2023 */
/* Laboratoire 13.2 : Ecrire une fonction retournant sous forme de string la représentation binaire de la somme de ses opérandes (en format binaire). Tester le résultat en calculant des valeurs de la suite de Fibonacci en sachant que f0 = 0, f1 = 1 et f(i+1) = fi + f(i-1) */

#include <iostream>
using namespace std;

//Décalaration de constantes
const int baseBinaire = 2;
const char minterm = '1';
const char maxterm = '0';
const char caractereVide = ' ';
const string premierTermeDeFibonacci = "0";
const string secondTermeDeFibonacci = "1";

//Déclaration de fonctions
string Fibonacci(int);
string operator+(string, const string &);
int deBinaireADecimal(string);

//Fonction principale
int main(){
	int terme;
	cout << "Le combientième terme de la suite de Fibonacci voulez-vous afficher?" << endl;
	cin >> terme;
	cout << "Voici le " << terme << "ieme terme de la suite de Fibonacci en base binaire: " << Fibonacci(terme) << endl;;
}

//Fonction redéfinissant l'opération + pour les strings
string operator+(string un, const string & deux){

	string strInversee = "";
	string str = "";
	int reste = 0;
	//Calcul des tailles des strings
	int taille1 = un.length() - 1;
	int taille2 = deux.length() - 1;
	
	int tailleMax = taille1 < taille2 ? taille2 : taille1;
	//calcul de la somme des nombres binaires (format string)
	for(int i = 0; i <= tailleMax; ++i){
		//Remplacer les espaces vides par des caractères zéros
		char str1 = un[taille1-i] != caractereVide ? (char)un[taille1-i] : maxterm;
		char str2 = deux[taille2-i] != caractereVide ? (char)deux[taille2-i] : maxterm;
		
		//modification du caractère d'emplacement i en entier
		int ch1 = (str1 == minterm);
		int ch2 = (str2 == minterm);
		
		int calcul = ch1 + ch2 + reste;
		
		//Ajout du résultat à une string
		strInversee.append(to_string(calcul % baseBinaire));
		//calcul du reste
		reste = calcul / baseBinaire;	
	}
	
	//Augmentation de la capacité et ajout d'un bit de poids fort s'il y a un dépassement de capacité
	if(reste == 1){
		strInversee.append("1");
		++tailleMax;
	}
	//Remise dans le bon sens des bits
	for(size_t i = 0; i <= tailleMax; ++i){
		str.push_back((char)strInversee[tailleMax-i]);
	}
	
	return str;
}

//Fonction calculant le ième terme (passé en paramètre) de la suite de Fibonacci
string Fibonacci(int terme){
	string fi = secondTermeDeFibonacci;
	string fiMoins1 = premierTermeDeFibonacci;
	if(terme < 1){
		return fiMoins1;
	}
	for(int i = 0 ; i < terme; ++i){
		string fiPassage = fi;
		fi = fi+fiMoins1;
		fiMoins1 = fiPassage;
	}

	return fi;
}


