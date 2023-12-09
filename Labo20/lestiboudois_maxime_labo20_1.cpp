/* Maxime Lestiboudois */
/* 07/12/2023 */ 
/* Laboratoire 20.1: Définir une classe Rationnel permettant de manipuler des nombres fractionnaires */

#include <cstdlib>

//Déclaration de fonctions:
void nb_premiers_entre_eux(int &, int &);
int euclide(int, int);


//Déclaration de classes
class Rationnel{
	private: 
		int numerateur;
		int denominateur;
	public:
		Rationnel(int numerateur = 0, int denominateur = 1);
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
	if(denominateur == 0) abort();
}
Rationnel operator+(Rationnel a, const Rationnel & b){
	Rationnel retour = Rationnel();
	retour.numerateur = a.numerateur*b.denominateur + b.numerateur*a.denominateur;
	retour.denominateur = a.denominateur * b.denominateur;
	nb_premiers_entre_eux(retour.numerateur, retour.denominateur);
	
	return retour;
}
Rationnel operator-(Rationnel a, const Rationnel & b){
	Rationnel retour = Rationnel();
	retour.numerateur = a.numerateur*b.denominateur - b.numerateur*a.denominateur;
	retour.denominateur = a.denominateur * b.denominateur;
	nb_premiers_entre_eux(retour.numerateur, retour.denominateur);
	
	return retour;
}
Rationnel operator*(Rationnel a, const Rationnel & b){
	Rationnel retour = Rationnel();
	retour.numerateur = a.numerateur * b.numerateur;
	retour.denominateur = a.denominateur * b.denominateur;
	nb_premiers_entre_eux(retour.numerateur, retour.denominateur);
	
	return retour;
}
#include <iostream>
Rationnel operator/(Rationnel a, const Rationnel & b){
	Rationnel retour = Rationnel();
	retour.numerateur = a.numerateur * b.denominateur;
std::cout << retour.numerateur << std::endl;
	retour.denominateur = a.numerateur * b.denominateur;
std::cout << retour.denominateur << std::endl;
	nb_premiers_entre_eux(retour.numerateur, retour.denominateur);
	
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
//#include <iostream>
void affiche(Rationnel a){
	std::cout << a.numerateur << " / " << a.denominateur << std::endl;
}

void nb_premiers_entre_eux(int & a, int & b){

	if(a>0&& b>0){
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
}
		
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
	Rationnel a = Rationnel(2,5);
	Rationnel b= Rationnel(4,8);
	affiche(a/b);
}
	
		
