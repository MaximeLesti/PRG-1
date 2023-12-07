/* Maxime Lestiboudois */
/* 07/12/2023 */ 
/* Laboratoire 20.1: Définir une classe Rationnel permettant de manipuler des nombres fractionnaires */

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
		Rationnel operator+(Rationnel a, const Rationnel & b);
		Rationnel operator-(Rationnel a, const Rationnel & b);
		Rationnel operator*(Rationnel a, const Rationnel & b);
		Rationnel operator/(Rationnel a, const Rationnel & b);
		bool operator==(Rationnel a, const Rationnel & b);
		bool operator<(Rationnel a, const Rationnel & b);
		bool operator>(Rationnel a, const Rationnel & b);
		bool operator<=(Rationnel a, const Rationnel & b);
		bool operator>=(Rationnel a, const Rationnel & b);
		void affiche(Rationnel a);
};
Rationnel::Rationnel(int numerateur=0, int denominateur=1){
	this->numerateur = numerateur;
	this->denominateur = denominateur;
	if(denominateur == 0) abort();
}
Rationnel Rationnel::operator+(Rationnel a, const Rationnel & b){
	Rationnel retour = Rationnel();
	retour.numerateur = a.numerateur*b.denominateur + b.numerateur*a.denominateur;
	retour.denominateur = a.denominateur * b.denominateur;
	nb_premier_entre_eux(retour.numerateur, retour.denominateur);
	
	return retour;
}
Rationnel Rationnel::operator-(Rationnel a, const Rationnel & b){
	Rationnel retour = Rationnel();
	retour.numerateur = a.numerateur*b.denominateur - b.numerateur*a.denominateur;
	retour.denominateur = a.denominateur * b.denominateur;
	nb_premier_entre_eux(retour.numerateur, retour.denominateur);
	
	return retour;
}
Rationnel Rationnel::operator*(Rationnel a, const Rationnel & b){
	Rationnel retour = Rationnel();
	retour.numerateur = a.numerateur * b.numerateur;
	retour.denominateur = a.denominateur * b.denominateur;
	nb_premier_entre_eux(retour.numerateur, retour.denominateur);
	
	return retour;
}
Rationnel Rationnel::operator/(Rationnel a, const Rationnel & b){
	Rationnel retour = Rationnel();
	retour.numerateur = a.numerateur * b.denominateur;
	retour.denominateur = a.numerateur * b.denominateur;
	nb_premier_entre_eux(retour.numerateur, retour.denominateur);
	
	return retour;
}
bool Rationnel::operator==(Rationnel a, const Rationnel & b){
	return (a.numerateur*b.denominateur == b.numerateur*a.denominateur);
}
bool Rationnel::operator<(Rationnel a, const Rationnel & b){
	return (a.numerateur*b.denominateur < b.numerateur*a.denominateur);
}
bool Rationnel::operator>(Rationnel a, const Rationnel & b){
	return (a.numerateur*b.denominateur > b.numerateur*a.denominateur);
}
bool Rationnel::operator<=(Rationnel a, const Rationnel & b){
	return ((a == b) || (a < b));
}
bool Rationnel::operator>=(Rationnel a, const Rationnel & b){
	return ((a == b) || (a > b));
}
#include <iostream>
void Rationnel::affiche(Rationnel a);
	std::cout << a.numerateur << " / " << a.denominateur << std::endl;
}

void nb_premiers_entre_eux(int & a, int & b){
	int pgdc = euclide(a,b);
	while(pgdc != 1){
		a /= pgdc;
		b/= pgdc;
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
	
		
