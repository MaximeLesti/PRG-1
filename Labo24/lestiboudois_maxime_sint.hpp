



class Sint{
	private: 
		Uint uint;
		int signe;
	public:
		Sint(int sint = 0);
		friend Sint operator - (const Sint & gauche, const Sint & droite);
};

#include "lestiboudois_maxime_sint.cpp"
