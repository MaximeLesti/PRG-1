

#include "lestiboudois_maxime_uint.hpp"
#include "lestiboudois_maxime_redefinition_fonctions_string.hpp"
#include <stdexcept>



Uint::Uint(uint64_t entier){
	base = 2;
	std::string passage="";
	int reste;
	if(entier == 0) passage+='0';
	while(entier != 0){
		reste = entier % base2;
		entier /= base;
		std::string valeur = std::to_string(reste);
		passage.append(valeur);

	}

	int taille_string = passage.length()-1;
	for(size_t i = 0; i <= taille_string ; ++i){
		donnees.push_back(passage[taille_string-i]);
	}

}
std::ostream & operator<< (std::ostream & sortie, const Uint & objet){
	if(Uint::base == 2) sortie << objet.donnees;
	else{
		std::string str;
		int entier = objet.donnees[objet.donnees.size()-1] == '1' ? 1 : 0;
		int coef = 1;
		int base_binaire = 2;
		for(int i = 1; i<objet.donnees.size();++i){
			coef *= base_binaire;
			if(objet.donnees[objet.donnees.size()-1-i] == '1')
				entier += coef;	
		}
		 while(entier > 0){
			str = char(entier % Uint::base + '0') + str;
			entier /= Uint::base;
		  }
	    sortie << str;
	    
	    }
	return sortie;
}
Uint operator+(Uint gauche, const Uint & droite){
	Uint retour;
	retour.donnees = gauche.donnees + droite.donnees;
	
	return retour;
}
Uint operator-(Uint gauche, const Uint & droite){
	Uint retour;
	if(gauche<droite){
		std::string s ="soustraction impossible";
		throw s;
	}
	retour.donnees = gauche.donnees - droite.donnees;
	

	return retour;	

}
Uint operator*(Uint gauche, const Uint & droite){
	Uint retour;
	retour.donnees = gauche.donnees * droite.donnees;
	
	return retour;
}
Uint operator/(Uint gauche, const Uint & droite){
	if(droite == '0'){
		std::string s ="division par zéro";
		throw s;
	}
	Uint retour = Uint();
	retour.donnees = gauche.donnees/droite.donnees;
	
	return retour;
}
Uint operator%(Uint gauche, const Uint & droite){
	if(droite == '0'){
		std::string s ="modulo par 0";
		throw s;
	}
	Uint retour = Uint();
	retour.donnees = gauche.donnees%droite.donnees;
	
	return retour;	
}
bool Uint::operator==(const Uint & droite) const{
	return (donnees == droite.donnees);
}

Uint operator +=(Uint & gauche, const Uint & droite){
	gauche = gauche + droite;
	return gauche;	
}
Uint operator -=(Uint & gauche, const Uint & droite){
	gauche = gauche - droite;
	return gauche;
}
Uint operator *=(Uint & gauche, const Uint & droite){
	gauche = gauche * droite;
	return gauche;
}
Uint operator /=(Uint & gauche, const Uint & droite){
	gauche = gauche/droite;
	return gauche;
}
bool Uint::operator<(const Uint & droite) const{
	if(donnees.size() == droite.donnees.size())
		return (donnees < droite.donnees);
	else return (donnees.size() < droite.donnees.size());
}
bool Uint::operator>(const Uint & droite) const{
	if(donnees.size() == droite.donnees.size())
		return (donnees > droite.donnees);
	else return (donnees.size() > droite.donnees.size());
}
bool Uint::operator<=(const Uint & droite) const{
	return ((*this < droite) || (*this == droite));
}
bool Uint::operator>=(const Uint & droite) const{
	return ((*this > droite) || (*this == droite));
}

bool Uint::isNull(){
	return (donnees == "0");
}
Passage set_base(unsigned nouvelle_base){
	Uint::base = nouvelle_base;
	return Passage{};
	
}
std::ostream & operator<<(std::ostream & flux, Passage droite){
    return flux;
}
	




