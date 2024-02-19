/* Maxime Lestiboudois */
/* 26/01/24 */
/* Définitions des méthodes de la classe Uint */

#include "lestiboudois_maxime_redefinition_fonctions_string.hpp"
//Déclaration de constantes
const int base_binaire = 2;

//Initialisation des variables statiques 
unsigned Uint::base = 10;
unsigned Uint::largeur = 0;
char Uint::bourrage = ' ';

//Constructeur de Uint
Uint::Uint(uint64_t entier){
	std::string passage="";
	//Passage du uint64_t en binaire dans une string avec le bit de poids fort à droite
	int reste;
	if(entier == 0) passage+='0';
	
	while(entier != 0){
		reste = entier % base2;
		entier /= base_binaire;
		std::string valeur = std::to_string(reste);
		passage.append(valeur);

	}
	//Inversion de l'ordre de la string, le bit de poids fort passe à gauche
	int taille_string = passage.length()-1;
	for(size_t i = 0; i <= taille_string ; ++i){
		donnees.push_back(passage[taille_string-i]);
	}


}
//Redéfinition de l'opérateur de flux de sortie pour des Uint
std::ostream & operator<< (std::ostream & sortie, const Uint & objet){

	if(Uint::base == 2 || objet.donnees =="0") sortie << objet.donnees;
	else{
		//Passage des données en binaire sous forme de string en entier de forme décimale
		std::string str;
		int entier = objet.donnees[objet.donnees.size()-1] == '1' ? 1 : 0;
		int coef = 1;

		for(int i = 1; i<objet.donnees.size();++i){
			coef *= base_binaire;
			if(objet.donnees[objet.donnees.size()-1-i] == '1')
				entier += coef;	
		}
		//Ecriture dans la string de l'entier trouvé précédemment dans la base statique de Uint
		while(entier > 0){
			str = char((entier % Uint::base) <= 9 ? entier % Uint::base +'0' : (entier % Uint::base) - 10 +'A') + str;
			entier /= Uint::base;
		}
		
		//Ajout du caractère statique de bourrage de Uint au début de la string de résultat 
		//si le membre statique largeur de Uint est supérieur à la taille du résultat
		//(string) trouvé précédemment
		if(Uint::largeur > str.size()){
		  	std::string bourrage((Uint::largeur-str.size()), Uint::bourrage);
		  	str = concatene(bourrage, str);
		}
		  
		//Passage de la string de résultat dans le flux de sortie
		sortie << str;
	    
	    }
	return sortie;
}

//Redéfinition de l'opérateur d'addition pour les Uint
Uint Uint::operator+(const Uint & droite) const{
	Uint retour;
	retour.donnees = this->donnees + droite.donnees;
	
	return retour;
}

//Redéfinition de l'opérateur de soustraction pour les Uint
Uint Uint::operator-(const Uint & droite) const{
	Uint retour;
	if(droite<*this){
		throw Uint_attribut("soustraction impossible");
		
	}
	retour.donnees = this->donnees - droite.donnees;
	
	return retour;	

}

//Redéfinition de l'opérateur de multiplication pour les Uint
Uint Uint::operator*(const Uint & droite) const{
	Uint retour;
	retour.donnees = this->donnees * droite.donnees;
	
	return retour;
}

//Redéfinition de l'opérateur de division pour les Uint
Uint Uint::operator/(Uint & droite) const{
	//lancement d'erreur si le diviseur est égal à 0
	if(droite == Uint(0)){
		throw Uint_attribut("division par zéro");
	}
	Uint retour = Uint();
	retour.donnees = droite.donnees/this->donnees;

	return retour;
}

//Redéfinition de l'opérateur modulo pour les Uint
Uint operator%(Uint gauche, const Uint & droite){
	//lancement d'erreur si le modulo est égal à 0 ou 1
	if(droite == Uint(0)){
		throw Uint_attribut("modulo par 0");	
	}
	Uint retour = Uint();
	if(droite == gauche) 
		retour.donnees ="1";
	else if(droite == Uint(1) ) 
		retour.donnees = "0";
	else
		retour.donnees = gauche.donnees%droite.donnees;
	
	return retour;	
}

//Redéfinition de l'opérateur d'équivalence
bool Uint::operator==(const Uint & droite) const{
	return (donnees == droite.donnees);
}

//Redéfinition de l'opérateur de non-équivalence
bool Uint::operator!=(const Uint & droite) const{
	return !(*this == droite);
}

//Redéfinition de l'opérateur plus-égal
Uint operator +=(Uint & gauche, const Uint & droite){
	gauche = gauche + droite;
	return gauche;	
}

//Redéfinition de l'opérateur moins-égal
Uint operator -=(Uint & gauche, const Uint & droite){
	gauche = gauche - droite;
	return gauche;
}

//Redéfinition de l'opérateur fois-égal
Uint operator *=(Uint & gauche, const Uint & droite){
	gauche = gauche * droite;
	return gauche;
}

//Redéfinition de l'opérateur divisé-égal
Uint & Uint::operator /=( Uint  droite){
	*this = *this/droite;
	return *this;
}

//Redéfinition de l'opérateur de comparaison "plus petit que"
bool Uint::operator<(const Uint & droite) const{
	if(donnees.size() == droite.donnees.size())
		return (droite.donnees < donnees);
	else return (droite.donnees.size()<donnees.size());
}

//Redéfinition de l'opérateur de comparaison "plus grand que"
bool Uint::operator>(const Uint & droite) const{
	if(donnees.size() == droite.donnees.size())
		return (droite.donnees > donnees);
	else return (droite.donnees.size() > donnees.size());
}

//Redéfinition de l'opérateur de comparaison "plus petit ou égal à"
bool Uint::operator<=(const Uint & droite) const{
	return ((*this < droite) || (*this == droite));
}

//Redéfinition de l'opérateur de comparaison "plus grand ou égal à"
bool Uint::operator>=(const Uint & droite) const{
	return ((*this > droite) || (*this == droite));
}

//Méthode rendant un booléen, vrai si la valeur du Uint l'appelant vaut 0
bool Uint::isNull(){
	return (donnees == "0");
}

//Méthode amie permettant de changer la valeur du membre statique base de Uint
Passage_Base set_base(unsigned nouvelle_base){
	//lancement d'erreur si la nouvelle base est supérieur à 27 ou inférieur à 1
	if(nouvelle_base > 27 || nouvelle_base <= 1){
		throw Uint_attribut("base inconnue ou trop petite");
	}
	Uint::base = nouvelle_base;
	return Passage_Base{};	
}

//Méthode amie permettant de changer les valeurs des membres statiques largeur et bourrage de Uint
Passage_Largeur setw(unsigned largeur, char bourrage = ' '){
	//lancement d'erreur si la nouvelle largeur est inférieur à 0
	if(largeur == 0){
		throw Uint_attribut("largeur nulle");
	}
	Uint::largeur = largeur;
	Uint::bourrage = bourrage;
	return Passage_Largeur{};
}

//Surcharge de l'opérateur de sortie des flux prenant en paramètre un objet de type Passage_Base
std::ostream & operator<<(std::ostream & flux, Passage_Base droite){
    return flux;
}

//Surcharge de l'opérateur de sortie des flux prenant en paramètre un objet de type Passage_Largeur
std::ostream & operator<<(std::ostream & flux, Passage_Largeur droite){
    return flux;
}
	




