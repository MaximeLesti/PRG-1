Résumé Labo20:

1) Définir une classe Mot et compter le nombre d'occurence de tous les mots dans une liste (vector)
	
	Fonctions comprises dans le programme:
		- int dichotomie(const Lexique &, const string &);
		
		
	Classes comprises dans le programme:
		- class Mot
			private:
				string mot;
				int nb = 1;
			public:
				Mot(string mot);
				void incremente();
				string getMot() const;
				int getOccurence() const;

		
2) Définir une classe Rationnel permettant de manipuler des nombres fractionnaires
	
	Fonctions comprises dans le programme:
		- void nb_premiers_entre_eux(int &, int &);
		- int euclide(int, int);

		
	Classes comprises dans le programme:
		- class Rationnel{
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

