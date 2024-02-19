/* Maxime Lestiboudois */
/* 26/01/2024 */
/* Déclaration de la classe Rationnel. La classe Rationnel représente des nombres rationnels, sous forme fractionnaire. */

#ifndef RATIONNEL //Protection contre les inclusions multiples
#define RATIONNEL

//Classe levant une exception lorsque la création d'une instance de la classe Rationnel lorsque ses attributs ne sont pas compatibles avec leur définition
class Rationnel_creation: public std::out_of_range{
	public: 
		Rationnel_creation(const char* msg) : std::out_of_range(msg){ }
};

//Classe Rationnel
class Rationnel{
	private: 
		Sint numerateur;
		Sint denominateur;
	public:
		Rationnel(Sint numerateur = Sint(0), Sint denominateur=Sint(1));
		friend Rationnel operator+(const Rationnel & a, const Rationnel & b);
		friend Rationnel operator-(Rationnel a, const Rationnel & b);
		friend Rationnel operator*(Rationnel a, const Rationnel & b);
		friend Rationnel operator/(Rationnel a, const Rationnel & b);
		friend Rationnel operator +=(Rationnel & a, const Rationnel & b);
		friend bool operator==(Rationnel a, const Rationnel & b);
		friend bool operator<(Rationnel a, const Rationnel & b);
		friend bool operator>(Rationnel a, const Rationnel & b);
		friend bool operator<=(Rationnel a, const Rationnel & b);
		friend bool operator>=(Rationnel a, const Rationnel & b);
		friend void affiche(Rationnel a);
		friend std::ostream & operator<<(std::ostream & sortie, const Rationnel & objet); 
		friend std::istream & operator>>(std::istream & sortie, Rationnel & objet); 
};


#include "lestiboudois_maxime_rationnel.cpp"
#endif
