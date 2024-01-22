

#ifndef UINT //Protection contre les inclusions multiples
#define UINT

#define SINT
class Passage{
};
class Uint{
	private: 
		std::string donnees;
		static unsigned base;
	public: 
		Uint(uint64_t entier=0);
		friend std::ostream & operator<< (std::ostream & sortie, const Uint & objet);
		friend Uint operator+(Uint gauche, const Uint & droite);
		friend Uint operator-(Uint gauche, const Uint & droite);
		friend Uint operator*(Uint gauche, const Uint & droite);
		friend Uint operator/(Uint gauche, const Uint & droite);
		friend Uint operator%(Uint gauche, const Uint & droite);
		bool operator==(const Uint & droite) const;
		friend Uint operator +=(Uint & gauche, const Uint & droite);
		friend Uint operator -=(Uint & gauche, const Uint & droite);
		friend Uint operator *=(Uint & gauche, const Uint & droite);
		friend Uint operator /=(Uint & gauche, const Uint & droite);
		bool operator<(const Uint & droite) const;
		bool operator>(const Uint & droite) const;
		bool operator<=(const Uint & droite) const;
		bool operator>=(const Uint & droite) const;
		bool isNull();
		friend Passage set_base(unsigned nouvelle_base);
		//friend std::ostream & setw(std::ostream & sortie, int n=2);
		
		friend class Sint;


};



#endif
