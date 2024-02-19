/* Maxime Lestiboudois */ 
/* 26/01/2024 */
/* Définitions des méthodes de la classe Rationnel et fonctions utiles à la bonne conduite de ces dernières */
#include <cctype>
#include <fstream>
#include <iostream>


//Déclaration de constantes
const Sint zero = Sint(0);

//Déclarations de fonctions
void nb_premiers_entre_eux(Sint &, Sint &);
Sint euclide(Sint, Sint);


//Constructeur de la classe Rationnel
Rationnel::Rationnel(Sint numerateur, Sint denominateur){
	if(denominateur == zero) {
		throw Rationnel_creation("Division par zéro");
	}
	nb_premiers_entre_eux(numerateur, denominateur);
	this->numerateur = numerateur;
	this->denominateur = denominateur;
	
}

//Redéfintion de l'opérateur de l'addition pour les Rationnels
Rationnel operator+(const Rationnel & a, const Rationnel & b){
	Rationnel retour;
	retour.numerateur = a.numerateur*b.denominateur + b.numerateur*a.denominateur;
	retour.denominateur = a.denominateur * b.denominateur;
	nb_premiers_entre_eux(retour.numerateur, retour.denominateur);
	
	return retour;
}

//Redéfintion de l'opérateur de la soustraction pour les Rationnels
Rationnel operator-(Rationnel a, const Rationnel & b){
	Rationnel retour = Rationnel();
	retour.numerateur = a.numerateur*b.denominateur - b.numerateur*a.denominateur;
	retour.denominateur = a.denominateur * b.denominateur;
	nb_premiers_entre_eux(retour.numerateur, retour.denominateur);
	
	return retour;
}

//Redéfintion de l'opérateur de la multiplication pour les Rationnels
Rationnel operator*(Rationnel a, const Rationnel & b){
	Rationnel retour = Rationnel();
	retour.numerateur = a.numerateur * b.numerateur;
	retour.denominateur = a.denominateur * b.denominateur;
	nb_premiers_entre_eux(retour.numerateur, retour.denominateur);
	
	return retour;
}

//Redéfintion de l'opérateur de la division pour les Rationnels
Rationnel operator/(Rationnel a, const Rationnel & b){
	Rationnel retour = Rationnel();
	retour.numerateur = a.numerateur * b.denominateur;
	retour.denominateur = a.denominateur * b.numerateur;
	nb_premiers_entre_eux(retour.numerateur, retour.denominateur);
	
	return retour;
}

//Redéfinition de l'opérateur += pour les Rationnels
Rationnel operator +=(Rationnel & a, const Rationnel & b){
	a = b+a;
	return a;

}


//Redéfintion de l'opérateur d'équivalence pour les Rationnels
bool operator==(Rationnel a, const Rationnel & b){
	return (a.numerateur*b.denominateur == b.numerateur*a.denominateur);
}

//Redéfintion de l'opérateur de comparaison "inférieur à" pour les Rationnels
bool operator<(Rationnel a, const Rationnel & b){
	return (a.numerateur*b.denominateur < b.numerateur*a.denominateur);
}

//Redéfintion de l'opérateur de comparaison "supérieur à" pour les Rationnels
bool operator>(Rationnel a, const Rationnel & b){
	return (a.numerateur*b.denominateur > b.numerateur*a.denominateur);
}

//Redéfintion de l'opérateur de comparaison "inférieur ou égal à" pour les Rationnels
bool operator<=(Rationnel a, const Rationnel & b){
	return ((a == b) || (a < b));
}

//Redéfintion de l'opérateur de comparaison "supérieur ou égal à" pour les Rationnels
bool operator>=(Rationnel a, const Rationnel & b){
	return ((a == b) || (a > b));
}

//Fonction affichant le Rationnel
void affiche(Rationnel a){
	std::cout << a.numerateur << "/" << a.denominateur << std::endl;
}

//Surcharge de l'opérateur << de sortie
std::ostream & operator<<(std::ostream & sortie, const Rationnel & objet){
	if((objet.numerateur < zero && objet.denominateur > zero)|| (objet.numerateur > zero && objet.denominateur < zero))
		sortie << "-";
	else sortie << "+";
	if(objet.denominateur != Sint(1))	
		sortie << objet.numerateur << "/" << objet.denominateur ;
	else 
		sortie << objet.numerateur;
		
	return sortie;
}

	

//Surcharge de l'opérateur >> d'entrée
std::istream & operator>>(std::istream & entree, Rationnel & objet){
	bool ok = true;
	int num = 0;
	int denom = 0;

	std::string str;
	getline(entree, str, ' ');
	auto indice = str.find('/');
	if(!(std::isdigit(str[str.size()-1])))
		str.pop_back();

	if(indice == std::string::npos) 
		throw Rationnel_creation("entrée non correcte");
	bool negatif = (str[0] == '-');

	std::string numerateur = str.substr(negatif, indice);
	std::string denominateur = str.substr(indice+1, str.size());


	int coef = 1;
	for(int i = 0; i< numerateur.size(); ++i){
		if(std::isalpha(numerateur[numerateur.size()-1-i]))
			ok = false;
		num += (numerateur[numerateur.size()-1-i] - '0') * coef;
		coef *= 10;
	}
	if(negatif) 
		num = -num; 

	coef = 1;

	for(int i = 0; i< denominateur.size(); ++i){
		if(std::isalpha(numerateur[numerateur.size()-1-i]))
			ok = false;
		denom += (denominateur[denominateur.size()-1-i] - '0') * coef;
		coef *= 10;
	}


	if(ok){
		objet.numerateur = Sint(num);
		objet.denominateur = Sint(denom);
	}
	else{
		entree.clear(std::ios::badbit | entree.rdstate() );
		throw Rationnel_creation("entrée non correcte");
	}

	return entree;
}

//Fonction réduisant les facteurs d'un Rationnel en nombres premiers entre eux
void nb_premiers_entre_eux(Sint & a, Sint & b){
	bool a_neg = false;
	bool b_neg = false;
	
	if(a == b){
		a = Sint(1);
		b = Sint(1);
	}
	if(a < zero){
		a_neg = true;
		a = -a;
	}
	if(b < zero){
		b_neg = true;
		b = -b;
	}
	//if(a > Sint(0) && b > Sint(0)){
		Sint pgdc = euclide(a,b);
		while(pgdc != Sint(1)){
			a /= pgdc;
			b/= pgdc;
			pgdc = euclide(a,b);
		}
		
	if(a_neg)
		a = -a;
	if(b_neg)
		b= -b;

}

//Fonction calculant le plus grand diviseur commun de deux instances de la classe Sint	
Sint euclide(Sint nombre_1, Sint nombre_2){

	if(nombre_1 == nombre_2) return Sint(1);
	if(nombre_1 == Sint(1) or nombre_2 == Sint(1)) {
		return Sint(1);
		}

	while(nombre_2 != zero){
		Sint t = nombre_2;
		nombre_2 = nombre_1 % nombre_2;
		nombre_1 = t;
	  }
	return nombre_1;
}
	

