/* Maxime Lestiboudois */
/* 26/01/2024 */
/* Déclaration de la classe Sint. La classe Sint représente les entiers signés. */


#ifndef SINT //Protection contre les inclusions multiples
#define SINT

class Rationnel;
//Définition de la classe Sint et de ses méthodes
class Sint{
	private: 
		Uint uint;
		bool signe;
		//Si signe = 0, alors le nombre est positif, s'il vaut 1, il est négatif
	public:
		Sint(int entier_signe = 0);
		Sint operator-() const;
		Sint & operator+= (const Sint & droite);
		Sint & operator-= (Sint droite);
		Sint & operator*= (const Sint & droite);
		Sint & operator/= (const Sint & droite);
		Sint operator+ (Sint droite) const;
		Sint operator- (Sint droite) const;
		Sint operator* (Sint droite) const;
		Sint operator/ (Sint droite) const;
		Sint operator% (const Sint & droite) const;
		bool operator<(const Sint & droite) const;
		bool operator>(const Sint & droite) const;
		bool operator<=(const Sint & droite) const;
		bool operator>=(const Sint & droite) const;
		bool operator==(const Sint & droite) const;
		bool operator!=(const Sint & droite) const;
		bool isNull();
		friend std::ostream & operator<< (std::ostream & sortie, const Sint & objet);
		friend class Rationnel;

};

#include "lestiboudois_maxime_sint.cpp"

#endif
