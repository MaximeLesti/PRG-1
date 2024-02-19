/* Maxime Lestiboudois*/
/* Redéfinition des opérateurs de calculs de string pour les adapter au calcul binaire */

#include <iostream>

//Déclaration de constantes
const int base2 = 2;
const int baseBinaire = 2;
const char minterm = '1';
const char maxterm = '0';
const char caractereVide = ' ';
const std::string incrementation = "1";

//Fonction permettant d'avoir une représentation binaire commençant par un 1
void begin_with_one(std::string & str){
	int indice = str.find(minterm, 0);
	if(indice != std::string::npos)
		str = str.substr(indice, str.size()+1);

	else str = "0";
}
//Fonction permettant de concaténer deux strings
std::string concatene(std::string un, const std::string & deux){
	std::string retour = un + deux;
	return retour;
}

//Redéfinition de l'opérateur de l'addition pour les strings
std::string operator+(std::string un, const std::string & deux){

	std::string strInversee = "";
	std::string str = "";
	int reste = 0;
	//Calcul des tailles des strings
	int taille1 = un.length() - 1;
	int taille2 = deux.length() - 1;
	
	int tailleMax = taille1 < taille2 ? taille2 : taille1;
	//calcul de la somme des nombres binaires (format string)
	for(int i = 0; i <= tailleMax; ++i){
		//Remplacement les espaces vides par des caractères zéros
		char str1 = un[taille1-i] != caractereVide ? (char)un[taille1-i] : maxterm;
		char str2 = deux[taille2-i] != caractereVide ? (char)deux[taille2-i] : maxterm;
		
		//Passage du caractère d'emplacement i en entier
		int ch1 = (str1 == minterm);
		int ch2 = (str2 == minterm);
		
		int calcul = ch1 + ch2 + reste;
		
		//Ajout du résultat à une string
		strInversee.append(std::to_string(calcul % baseBinaire));
		//calcul du reste
		reste = calcul / baseBinaire;	
	}
	
	//Augmentation de la capacité et ajout d'un bit de poids fort s'il y a un dépassement de capacité
	if(reste == 1){
		strInversee.append("1");
		++tailleMax;
	}
	//Remise dans le bon sens des bits (bit de poids fort à gauche)
	for(size_t i = 0; i <= tailleMax; ++i){
		str.push_back((char)strInversee[tailleMax-i]);
	}
	
	return str;
}

//Redéfinition de l'opérateur de la soustraction pour les strings
std::string operator-(std::string un, const std::string & deux){

	if(un == deux)
		return "0";

	std::string strInversee = "";
	std::string str = "";
	int emprunt = 0;
	//Calcul des tailles des strings
	int taille1 = un.length() - 1;
	int taille2 = deux.length() - 1;
	
	int tailleMax = taille1 < taille2 ? taille2 : taille1;
	//calcul de la somme des nombres binaires (format string)
	for(int i = 0; i <= tailleMax; ++i){
		//Remplacement les espaces vides par des caractères zéros
		char str1 = un[taille1-i] != caractereVide ? (char)un[taille1-i] : maxterm;
		char str2 = deux[taille2-i] != caractereVide ? (char)deux[taille2-i] : maxterm;
		
		//Passage du caractère d'emplacement i en entier
		int ch1 = (str1 == minterm);
		int ch2 = (str2 == minterm);
		int calcul = ch1 - (ch2 + emprunt);

		if(calcul<0){
			calcul = -calcul%baseBinaire;
			emprunt = 1;
		}
		else emprunt = 0;
		//Ajout du résultat à une string
		strInversee.append(std::to_string(calcul));
	}

	//Remise dans le bon sens des bits (bit de poids fort à gauche)
	for(int i = 0; i <= tailleMax; ++i){
		str.push_back((char)strInversee[tailleMax-i]);
	}
	//Retrait de potentiels 0 au début de la string de retour
	begin_with_one(str);
	
	return str;
}

//Redéfinition de l'opérateur de la multiplication pour les strings
std::string operator*(std::string un, const std::string & deux){

	std::string str = "";

	//Détermination de l'ordre de string par rapport à leur longueur
	std::string grandeString = un.length() < deux.length() ? deux : un;
	std::string petiteString = un.length() < deux.length() ? un : deux;
	
	// calcul de la taille des string
	int tailleGrandeString = grandeString.length()-1;
	int taillePetiteString = petiteString.length()-1;
	
	//Boucle itérant sur la longueur de la plus petite string (le facteur multiplicateur)
	for(size_t i = 0 ; i <= taillePetiteString; ++i){
		//Création de la string  instanciant les bits de poids faible si le facteur multiplicateur comporte plus d'une unité
		std::string strMult(i, maxterm);
		//Création de la string d'inversion des caractères
		std::string strInversee = "";

		//Passage du caractère d'emplacement "taille de la petite string" -  i en entier
		char str2 = (char)petiteString[taillePetiteString-i];
		int nb2 = (str2 == minterm);
		
		//Boucle itérant sur la longueur de la grande string (le facteur multiplié)
		for(size_t j = 0; j <= tailleGrandeString; ++j){
			//Passage du caractère d'emplacement "taille de la grande string" - j en entier
			char str1 = (char)grandeString[tailleGrandeString-j];
			int nb1 = (int)(str1 == minterm);
			//Ajout du résultat de la multiplication des termes i et j à la string de résultat
			strMult.append(std::to_string(nb1 * nb2));	
		}
		//Remise dans le bon sens des bits (bit de poids fort à gauche)
		int tailleMax = strMult.length() - 1;
		for(size_t i = 0; i <= tailleMax; ++i){
			strInversee.push_back((char)strMult[tailleMax-i]);
		}
		//Ajout du résultat la multiplication par terme à la réponse finale
		str =  str+strInversee;	 
	}
	
	return str;
}

//Redéfinition de l'opérateur de la division pour les strings
std::string operator/(std::string un, const std::string & deux){

	if(deux == "1") 
		return un;

	if(deux.size() >= un.size() && deux > un) 
		return "0";
	else{
	std::string quotient = "";
	int taille_deux = deux.size();
	int taille_un = un.size();
	
	for(int i = 0 ; i < taille_un-taille_deux+1 ; ++i){
		std::string str(taille_un-taille_deux-i, maxterm);
		str = concatene(deux, str);
		if((str.size() < un.size()) || (str.size() == un.size() && str <= un)) {
			quotient += '1';
			un = un - str;
		}
		else{
			quotient += '0';
		}
	}
	begin_with_one(quotient);
	return quotient;
	}
}
//Opérateur du modulo
std::string operator%(std::string un, const std::string & deux){
	
	if(deux == "1" || deux == "0") 
		throw Uint_attribut("modulo par 0 ou 1");

	if((un.size() < deux.size()) || (un.size() == deux.size() && un <= deux)) 
		return un;
	

	int taille_deux = deux.size();
	int taille_un = un.size();
	
	for(int i = 0 ; i < taille_un-taille_deux+1 ; ++i){
	
		std::string str(taille_un-taille_deux-i, maxterm);
		str = concatene(deux, str);	
		
		if((str.size() < un.size()) || (str.size() == un.size() && str <= un)) {
			un = un - str;
		}
	}
	return un;

}

	 
