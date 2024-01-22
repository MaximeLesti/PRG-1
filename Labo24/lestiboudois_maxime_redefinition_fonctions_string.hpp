/* Maxime Lestiboudois*/
/* Redéfinition des opérateurs de calculs de string pour les adapter au calcul binaire */

#include <iostream>


const int base2 = 2;
const int baseBinaire = 2;
const char minterm = '1';
const char maxterm = '0';
const char caractereVide = ' ';
const std::string incrementation = "1";

void begin_with_one(std::string & str){
	int indice = str.find(minterm, 0);
	if(indice != std::string::npos)
		str = str.substr(indice, str.size()+1);
	else str = "0";
}

//Opérateur de l'addition
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
		//Remplacer les espaces vides par des caractères zéros
		char str1 = un[taille1-i] != caractereVide ? (char)un[taille1-i] : maxterm;
		char str2 = deux[taille2-i] != caractereVide ? (char)deux[taille2-i] : maxterm;
		
		//modification du caractère d'emplacement i en entier
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
	//Remise dans le bon sens des bits
	for(size_t i = 0; i <= tailleMax; ++i){
		str.push_back((char)strInversee[tailleMax-i]);
	}
	
	return str;
}

//Opérateur de la soustraction
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
		//Remplacer les espaces vides par des caractères zéros
		char str1 = un[taille1-i] != caractereVide ? (char)un[taille1-i] : maxterm;
		char str2 = deux[taille2-i] != caractereVide ? (char)deux[taille2-i] : maxterm;
		
		//modification du caractère d'emplacement i en entier
		int ch1 = (str1 == minterm);
		int ch2 = (str2 == minterm);
		
		int calcul = ch1 - (ch2 + emprunt);
		if(calcul<0){
			calcul = -calcul;
		}
		//Ajout du résultat à une string
		strInversee.append(std::to_string(calcul));
		//calcul du reste
		emprunt = (ch1<ch2);
	}

	//Remise dans le bon sens des bits
	for(int i = 0; i <= tailleMax; ++i){
		str.push_back((char)strInversee[tailleMax-i]);
	}

	begin_with_one(str);
	
	return str;
}

//Opérateur de la multiplication
std::string operator*(std::string un, const std::string & deux){

	std::string str = "";

	//Détermination de l'ordre de string par rappor à leur longueur
	std::string grandeString = un.length() < deux.length() ? deux : un;
	std::string petiteString = un.length() < deux.length() ? un : deux;
	
	// calcul de la taille des string
	int tailleGrandeString = grandeString.length()-1;
	int taillePetiteString = petiteString.length()-1;

	for(size_t i = 0 ; i <= taillePetiteString; ++i){
		//Création de la string  instanciant les bits de poids faible si le facteur multiplicateur comporte plus d'une unité
		std::string strMult(i, maxterm);
		//Création de la string d'inversion des caractères
		std::string strInversee = "";

		char str2 = (char)petiteString[taillePetiteString-i];
		int nb2 = (str2 == minterm);
		
		for(size_t j = 0; j <= tailleGrandeString; ++j){
			char str1 = (char)grandeString[tailleGrandeString-j];
			int nb1 = (int)(str1 == minterm);
			
			strMult.append(std::to_string(nb1 * nb2));	
		}
		
		int tailleMax = strMult.length() - 1;
		for(size_t i = 0; i <= tailleMax; ++i){
			strInversee.push_back((char)strMult[tailleMax-i]);
		}

		str =  str+strInversee;	 
	}
	
	return str;
}
/*!!!!!!!!!!!!!!!!!!!!!!!!!peut être optimiser !!!!!!!!!!!!!!!!!!!!!*/
//Opérateur de la division
std::string operator/(std::string un, const std::string & deux){
	
	if(deux == "1") return un;
	if(deux.size()>un.size()) return "0";
	
	std::string quotient ="";
	std::string reste = un;
	

	for(int i = deux.size(); i < un.size()+1 ; ++i){
		
		std::string divise_local = reste.substr(0,i);
		
		std::string diviseur(divise_local.size(), maxterm);
		diviseur = diviseur + deux;
		
		
		if(diviseur>divise_local)
			quotient += '0';
		
		else{
			quotient += '1';
			
			std::string reste_local = (divise_local - diviseur);
			std::string strMult(i - (reste_local.size()-1), maxterm);
			
			reste = strMult + reste_local + reste.substr(i, reste.size());
		}	
	}
	
	begin_with_one(quotient);
	
	return quotient;

}
//Opérateur de la division
std::string operator%(std::string un, const std::string & deux){
	
	if(deux == "1") return un;
	if(deux.size()>un.size()) return "0";
	
	std::string quotient ="";
	std::string reste = un;
	

	for(int i = deux.size(); i < un.size()+1 ; ++i){
		
		std::string divise_local = reste.substr(0,i);
		
		std::string diviseur(divise_local.size(), maxterm);
		diviseur = diviseur + deux;
		
		
		if(diviseur>divise_local)
			quotient += '0';
		
		else{
			quotient += '1';
			
			std::string reste_local = (divise_local - diviseur);
			std::string strMult(i - (reste_local.size()-1), maxterm);
			
			reste = strMult + reste_local + reste.substr(i, reste.size());
		}	
	}
	begin_with_one(reste);
	
	return reste;

}


	 
