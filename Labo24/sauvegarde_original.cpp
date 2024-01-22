/* Maxime Lestiboudois */
/* 12.01.2024*/ 
/* Laboratoire 24: Reprendre le laboratoire 20.2 en adaptant la classe Rationnel pour qu’elle soit basée sur la classe Uint mise au point au laboratoire 21 et qu’elle intègre les exceptions pouvant survenir comme la lecture erronée d’un rationnel, la division par 0, etc. Vérifier le bon fonctionnement de cette classe en résolvant de manière exacte des systèmes d’équations linéaires avec coefficients entiers (exercice 8.13). */



#include <cstdlib>
#include <iostream>
#include <fstream>
//Déclaration constante:
const int base2 = 2;
const int baseBinaire = 2;
const char minterm = '1';
const char maxterm = '0';
const char caractereVide = ' ';
const std::string incrementation = "1";
//Déclaration de fonction
std::string operator+(std::string un, const std::string & deux);
std::string operator*(std::string un, const std::string & deux);
//void nb_premiers_entre_eux(Uint &, Uint &);
int euclide(int, int);

//Déclarations de classes
class Uint{
	private: 
		std::string donnees;
	public: 
		Uint(size_t entier=0);
		//Uint(uint64_t ent);
		friend std::ostream & operator<< (std::ostream & sortie, const Uint & objet);
		friend Uint operator+(Uint gauche, const Uint & droite);
		friend Uint operator-(Uint gauche, const Uint & droite);
		friend Uint operator*(Uint gauche, const Uint & droite);
		bool operator==( const Uint & droite) const;
		bool operator<( const Uint & droite) const;
		bool operator>( const Uint & droite) const;

};

Uint::Uint(size_t entier){

	std::string passage="";
	int reste;
	if(entier == 0) passage+='0';
	while(entier != 0){
 		reste = entier % base2;
 		entier /= base2;
 		std::string valeur = std::to_string(reste);
		passage.append(valeur);

 	  }
 	  std::cout << passage << std::endl;

 	  int taille_string = passage.length()-1;
 	  for(size_t i = 0; i <= taille_string ; ++i){
 	  	donnees.push_back(passage[taille_string-i]);
 	  }


}
/*Uint::Uint(uint64_t ent){
	size_t entier = ent;
	return Uint(entier);
}
*/
std::ostream & operator<< (std::ostream & sortie, const Uint & objet){
	sortie << objet.donnees;
	return sortie;
}
Uint operator+(Uint gauche, const Uint & droite){
	Uint retour;
	retour.donnees = gauche.donnees + droite.donnees;
	
	return retour;
}

Uint operator-(Uint gauche, const Uint & droite){
	Uint retour;
	if(gauche.donnees<droite.donnees) {
		retour.donnees = "erreur";
		std::cout << retour;
		abort();
		}
	std::string str="";
	size_t indice = droite.donnees.rfind('1', droite.donnees.size()-1);
	for(size_t i = 0; i < indice; ++i){
		str.push_back(droite.donnees[i] == '0'? '1': '0');
	}
	str += droite.donnees.substr(indice, droite.donnees.size()-1);
	retour.donnees = str + gauche.donnees;

	return retour;	

}
Uint operator*(Uint gauche, const Uint & droite){
	Uint retour;
	retour.donnees = gauche.donnees * droite.donnees;
	
	return retour;
}
bool Uint::operator==(const Uint & droite) const{
	return (donnees == droite.donnees);
}
bool Uint::operator<(const Uint & droite) const{
	return (donnees < droite.donnees);
}
bool Uint::operator>(const Uint & droite) const{
	return (donnees > droite.donnees);
}

	
class Rationnel{
	private: 
		Uint numerateur;
		Uint denominateur;
	public:
		Rationnel(Uint numerateur, Uint denominateur);
		friend Rationnel operator+(Rationnel a, const Rationnel & b);
		friend Rationnel operator-(Rationnel a, const Rationnel & b);
		friend Rationnel operator*(Rationnel a, const Rationnel & b);
		friend Rationnel operator/(Rationnel a, const Rationnel & b);
		friend bool operator==(Rationnel a, const Rationnel & b);
		friend bool operator<(Rationnel a, const Rationnel & b);
		friend bool operator>(Rationnel a, const Rationnel & b);
		friend bool operator<=(Rationnel a, const Rationnel & b);
		friend bool operator>=(Rationnel a, const Rationnel & b);
		friend void affiche(Rationnel a);
};
Rationnel::Rationnel(Uint numerateur = Uint(0), Uint denominateur=Uint(1)){

	this->numerateur = numerateur;

	this->denominateur = denominateur;

	if(denominateur == 0) {
		Uint d = Uint(5);
		throw(d);
	}
}
Rationnel operator+(Rationnel a, const Rationnel & b){
	Rationnel retour = Rationnel();
	retour.numerateur = a.numerateur*b.denominateur + b.numerateur*a.denominateur;
	retour.denominateur = a.denominateur * b.denominateur;
	//nb_premiers_entre_eux(retour.numerateur, retour.denominateur);
	
	return retour;
}
Rationnel operator-(Rationnel a, const Rationnel & b){
	Rationnel retour = Rationnel();
	retour.numerateur = a.numerateur*b.denominateur - b.numerateur*a.denominateur;
	retour.denominateur = a.denominateur * b.denominateur;
	//nb_premiers_entre_eux(retour.numerateur, retour.denominateur);
	
	return retour;
}
Rationnel operator*(Rationnel a, const Rationnel & b){
	Rationnel retour = Rationnel();
	retour.numerateur = a.numerateur * b.numerateur;
	retour.denominateur = a.denominateur * b.denominateur;
	//nb_premiers_entre_eux(retour.numerateur, retour.denominateur);
	
	return retour;
}

Rationnel operator/(Rationnel a, const Rationnel & b){
	Rationnel retour = Rationnel();
	retour.numerateur = a.numerateur * b.denominateur;
	retour.denominateur = a.numerateur * b.denominateur;
	//nb_premiers_entre_eux(retour.numerateur, retour.denominateur);
	
	return retour;
}
bool operator==(Rationnel a, const Rationnel & b){
	return (a.numerateur*b.denominateur == b.numerateur*a.denominateur);
}
bool operator<(Rationnel a, const Rationnel & b){
	return (a.numerateur*b.denominateur < b.numerateur*a.denominateur);
}
bool operator>(Rationnel a, const Rationnel & b){
	return (a.numerateur*b.denominateur > b.numerateur*a.denominateur);
}
bool operator<=(Rationnel a, const Rationnel & b){
	return ((a == b) || (a < b));
}
bool operator>=(Rationnel a, const Rationnel & b){
	return ((a == b) || (a > b));
}

void affiche(Rationnel a){
	std::cout << a.numerateur << " / " << a.denominateur << std::endl;
}

/*void nb_premiers_entre_eux(Uint & a, Uint & b){

	if(a>0 && b>0){
		int pgdc = euclide(a,b);
		while(pgdc != 1){
			a /= pgdc;
			b/= pgdc;
			pgdc = euclide(a,b);
		}
	}
	if(a<0){
		a = -a;
		int pgdc = euclide(a,b);
		while(pgdc != 1){
			a /= pgdc;
			b/= pgdc;
		}
		a = -a;
	}
	if(b<0){
		b = -b;
		int pgdc = euclide(a,b);
		while(pgdc != 1){
			a /= pgdc;
			b/= pgdc;
		}
		b = -b;
	}
}*/
		
int euclide(int nombre_1, int nombre_2){
	while(nombre_2 != 0){
		int t = nombre_2;
		nombre_2 = nombre_1 % nombre_2;
		nombre_1 = t;
	  }
	return nombre_1;
}
	

//Déclaration de fonction


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
	
	
using namespace std;

int main(){
	try{
		Uint a = Uint(5);
		cout <<"a"<<endl;
		Uint b = Uint(10);
		cout <<"b"<<endl;
		Uint c = Uint(1);
		cout <<"c"<<endl;
		Uint d = Uint(2);
		cout <<d<<endl;
		Rationnel u = Rationnel(a, b);
		affiche(u);
		Rationnel v = Rationnel(c,d);
		affiche(v);
		affiche(u/v);
	/*Rationnel a = Rationnel(2,5);
	Rationnel b= Rationnel(4,8);
	affiche(a/b);*/
	}
	catch(Uint){
		cout << "Ce n'est pas bon" << endl;
	}
}
