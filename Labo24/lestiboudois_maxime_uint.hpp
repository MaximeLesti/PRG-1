/* Maxime Lestiboudois */
/* 26/01/2024 */ 
/* Déclaration de la classe Uint. La classe Uint représente des entiers non-signés */


#include <stdexcept>

#ifndef UINT //Protection contre les inclusions multiples
#define UINT
//Classe permettant le changement de base de la classe Uint
class Passage_Base{};
//Classe permettant le changement de la largeur de l'affichage de la classe Uint
class Passage_Largeur{};
//Classe lançant une erreur lorsque un attribut de la class Uint est contraire à sa définition
class Uint_attribut: public std::out_of_range{
	public: 
		Uint_attribut(const char* msg) : std::out_of_range(msg){ }
};
//Déclaration de la classe Uint
class Uint{
	private: 
		std::string donnees;
		static unsigned base;
		static unsigned largeur;
		static char bourrage;
	public: 
		Uint(uint64_t entier=0);
		friend std::ostream & operator<< (std::ostream & sortie, const Uint & objet);
		Uint operator+(const Uint & droite) const;
		Uint operator-(const Uint & droite) const;
		Uint operator*(const Uint & droite) const;
		Uint operator/(Uint & droite) const;
		friend Uint operator%(Uint gauche, const Uint & droite);
		bool operator==(const Uint & droite) const;
		bool operator!=(const Uint & droite) const;
		friend Uint operator +=(Uint & gauche, const Uint & droite);
		friend Uint operator -=(Uint & gauche, const Uint & droite);
		friend Uint operator *=(Uint & gauche, const Uint & droite);
		Uint & operator /=(Uint droite);
		bool operator<(const Uint & droite) const;
		bool operator>(const Uint & droite) const;
		bool operator<=(const Uint & droite) const;
		bool operator>=(const Uint & droite) const;
		bool isNull();
		friend Passage_Base set_base(unsigned nouvelle_base);
		friend Passage_Largeur setw(unsigned largeur, char bourrage );

		
		friend class Sint;


};

#include "lestiboudois_maxime_uint.cpp"

#endif
