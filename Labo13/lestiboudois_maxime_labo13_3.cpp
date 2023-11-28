/* Maxime Lestiboudois */
/* 31/10/2023 */
/* Laboratoire 13.3 : Ecrire une fonction retournant sous la forme de string la multiplication binaire de deux valeurs binaires (ses opérandes). Tester la fonction en calculant des factoriels. */

#include <iostream>
using namespace std;


//Décalaration de constantes
const char minterm = '1';
const char maxterm = '0';
const char caractereVide = ' ';
const int baseBinaire = 2;
const string incrementation = "1";

//Déclaration de fonctions
string operator+(string, const string &);
string operator*(string, const string &);
string factoriel(string);

int main(){
	
	string str1;
	cout << "Entrez un nombre en base binaire qui sera passé en factoriel" << endl;
	cin >> str1;
	cout << "(" << str1 << ")! vaut " << factoriel(str1) << endl;
	
}

//Fonction redéfinissant l'opération + pour les strings
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

//Fonction redéfinissant l'opération * pour les strings
string operator*(string un, const string & deux){

	string str = "";

	//Détermination de l'ordre de string par rappor à leur longueur
	string grandeString = un.length() < deux.length() ? deux : un;
	string petiteString = un.length() < deux.length() ? un : deux;
	
	// calcul de la taille des string
	int tailleGrandeString = grandeString.length()-1;
	int taillePetiteString = petiteString.length()-1;

	for(size_t i = 0 ; i <= taillePetiteString; ++i){
		//Création de la string  instanciant les bits de poids faible si le facteur multiplicateur comporte plus d'une unité
		string strMult(i, maxterm);
		//Création de la string d'inversion des caractères
		string strInversee = "";

		char str2 = (char)petiteString[taillePetiteString-i];
		int nb2 = (str2 == minterm);
		
		for(size_t j = 0; j <= tailleGrandeString; ++j){
			char str1 = (char)grandeString[tailleGrandeString-j];
			int nb1 = (int)(str1 == minterm);
			
			strMult.append(to_string(nb1 * nb2));	
		}
		
		int tailleMax = strMult.length() - 1;
		for(size_t i = 0; i <= tailleMax; ++i){
			strInversee.push_back((char)strMult[tailleMax-i]);
		}

		str =  str+strInversee;	 
	}
	
	return str;
}

//Fonction calculant la factorielle d'un nombre binaire (format string)
string factoriel(string nombre){

	string str = "1";
	string compte = "1";
	
	if(nombre == str){
		return str;
	}
	do{
		compte = compte + incrementation;
		str = str * compte;
	}while(compte != nombre);

		 
	return str;
}




