/* Maxime Lestiboudois */
/* 12.01.2024*/ 
/* Laboratoire 24: Reprendre le laboratoire 20.2 en adaptant la classe Rationnel pour qu’elle soit basée sur la classe Uint mise au point au laboratoire 21 et qu’elle intègre les exceptions pouvant survenir comme la lecture erronée d’un rationnel, la division par 0, etc. Vérifier le bon fonctionnement de cette classe en résolvant de manière exacte des systèmes d’équations linéaires avec coefficients entiers (exercice 8.13). */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "lestiboudois_maxime_uint.cpp"
#include "lestiboudois_maxime_sint.hpp"


//void nb_premiers_entre_eux(Uint &, Uint &);
int euclide(int, int);

//Déclarations de classes

class Rationnel{
	private: 
		int numerateur;
		int denominateur;
	public:
		Rationnel(int numerateur = 0, int denominateur=1);
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
Rationnel::Rationnel(int numerateur, int denominateur){
	this->numerateur = numerateur;
	this->denominateur = denominateur;
	if(denominateur==1) {
		std::string d = "errore";
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
	


	
	
using namespace std;

int main(){
	try{
		Uint a = Uint(5); //101

		Uint b = Uint(27); // 1010

		Uint c = Uint(3); //11

		Uint d = Uint(2); //10
		//d-=c;	
		//b/=d;
		cout << std::setbase(8) << 12 << endl;
		

		//Rationnel u = Rationnel(a, b);

		//Rationnel v = Rationnel(c,d);

		//affiche(u/v);
	/*Rationnel a = Rationnel(2,5);
	Rationnel b= Rationnel(4,8);
	affiche(a/b);*/
	}
	catch(string s){
		cout << s << endl;
	}
	catch(Uint){
		cout << "Ce n'est pas bon" << endl;
	}
}
