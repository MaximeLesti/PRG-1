Résumé Labo13:

1) Implémentation d'une fonction retournant au format string la forme binaire d'un nombre de type size_t passé en paramètre 

2) Implémentation d'une fonction retournant sous forme de string la représentation binaire de la somme de ses opérandes (en format binaire). Vérification de la fonction en calculant des valeurs de la suite de Fibonacci en sachant que f0 = 0, f1 = 1 et f(i+1) = fi + f(i-1)

	Fonctions comprises dans le programme:
		- string Fibonacci(int);
		- string operator+(string, const string &);
		- int deBinaireADecimal(string);
		
2_suppl) Même chose que 2) mais avec des fonctions supplémentaires pour un autre aperçu de la suite de Fibonacci

	Fonctions comprises dans le programme:
		- string Fibonacci(int);
		- string operator+(string, const string &);
		- int deBinaireADecimal(string);
		- string prochainTermeDeFibonacci(string, string);
		- bool appartientAlaSuiteDeFibonacci(string);
		- bool consecutifDansLaSuiteFibonacci(string, string);
		- int puissance(int, int);
		
3) Implémentation une fonction retournant sous la forme de string la multiplication binaire de deux valeurs binaires (ses opérandes). Vérification la fonction par le calcul de factorielles.

	Fonctions comprises dans le programme:
		- string operator+(string, const string &);
		- string operator*(string, const string &);
		- string factoriel(string);
