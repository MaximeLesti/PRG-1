Résumé des laboratoires 

----------------------------------------------------------------------------------------------------

Résumé Labo1:

Programme Hello World

----------------------------------------------------------------------------------------------------

Résumé Labo2:

Programme convertissant une durée en secondes en des semaines, des jours, des heures, des minutes et des secondes

----------------------------------------------------------------------------------------------------

Résumé Labo3:

1) Additionner des nombres entiers introduits par l'utilisateur représentant des kilomètres, des mètres, des centimètres et des millimètres et afficher le résultat

2) Calculer le temps de trajet à l'aide de l'heure de départ et l'heure d'arrivée

----------------------------------------------------------------------------------------------------

Résumé Labo4:

Une montre mécanique voit son aiguille des minutes avancer chaque seconde, mais n’a pas de trotteuse. Connaissant l’angle que fait l’aiguille des minutes avec l’horizontale, exprimé en dixièmes de degrés et dans le sens mathématique, imprimer les minutes et les secondes.

----------------------------------------------------------------------------------------------------

Résumé Labo5:

Convertir une durée exprimée en secondes en semaines, en jours, heures, minutes et secondes et les afficher de manière soigneuse.

----------------------------------------------------------------------------------------------------

Résumé Labo6:

Déterminer à l'aide de 4 coordonnées géomètriques représentant les sommets d'un quadrilatère quel est le type de ce quadrilatère (rectangle, losange, carré, parrallèlogramme, trapèze)

----------------------------------------------------------------------------------------------------

Résumé Labo7:

Calcul de la moyenne et de la variance d'une suite de nombres positifs introduits par l'utilisateur

----------------------------------------------------------------------------------------------------

Résumé Labo8:

1) Programme lisant un nombre entier non-négatif et affichant sa valeur en base 2 à l'envers, les bits de poids faible en premier

2) Calcul du PPMC de deux nombres introduits par l'utilisateur

3) Programme affichant des carrés imbriqués avec les lettres de l'alphabet, le nombre de carrés est introduit par l'utilisateur

----------------------------------------------------------------------------------------------------

Résumé Labo9:

1) Estimation du nombre pi

2) statistique de réussite au jeu télévisé des trois portes

----------------------------------------------------------------------------------------------------

Résumé Labo10:

Calcul de la valeur de la racine carrée d'un nombre introduit par l'utilisateur
	
	Fonctions comprises dans le programme:
			- double moyenne_deux_nombres(double, double);
			- Racine_et_nb_iteration ma_racine_et_mon_nb_iteration(double, int);

----------------------------------------------------------------------------------------------------

Résumé Labo11:

Déterminer si un nombre fournit par l'utilisateur est premier

	Fonctions comprises dans le programme:
		- bool est_ce_premier(int);
		- bool est_ce_premier_naif(int);
		- int exponentiation_modulaire(int, int, int);
		- void imprime_deux_cents_nombres_premiers_suppl(int);

----------------------------------------------------------------------------------------------------

Résumé Labo12:

Implémentation du système de cryptage RSA: trouver la clé secrète, crypter un nombre, décrypter un nombre
	Fonctions comprises dans le programme:
		 - bool est_ce_premier(int);
		 - int euclide(int, int);
		 - doublet_d_euclide algo_euclide_etendu(int, int);
		 - bool sont_ils_premiers_entre_eux(int, int, int);
		 - int exponentiation_modulaire(int, int, int);
		 - int trouver_la_cle_secrete(int, int);
	 
	 Structures comprises dans le programme:
	 	 - struct doublet_d_euclide {int n1; int n2;};

----------------------------------------------------------------------------------------------------

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

----------------------------------------------------------------------------------------------------

Résumé Labo14:

Implantation d'une fonction de prototype <string & replace_all(string & str, const string & from, const string & to)> qui remplace dans la string str toutes les occurences de la sous-chaîne from par la sous-châine to. Application de la fonction sur le fichier texte Les_Miserables.txt
	
	Fonctions comprises dans le programme:
		- string & replace_all(string &, const string &, const string &);


----------------------------------------------------------------------------------------------------

Résumé Labo15:

Programme lisant un texte français au format UTF-8 et imprimant chacun des mots une seule et unique fois. 
	
	Fonctions comprises dans le programme:
		- string mots_uniques(string &);
		- string mots_uniques_bis(string &);

----------------------------------------------------------------------------------------------------

Résumé Labo16:

1) Génération d'un fichier KLM à l'aide d'un fichier txt fournissant des coordonnées WPGS84 lambda et phi
	
	Fonctions comprises dans le programme:
		- string generationKLM(string);
		- string WPGS84toCH1903(string);

2) Savoir si un fichier portant un certain nom existe déjà et, s'il existe, informer sa taille, sinon le créer 

----------------------------------------------------------------------------------------------------

Résumé Labo17:

1) Rétablir les bonnes valeurs de taille (aux bons endroits) dans un enregistrement audio 
	

2) Récupérer un fichier caché dans une image au format BMP

----------------------------------------------------------------------------------------------------

Résumé Labo18:

1) Ecrire une fonction add prenant en paramètres 2 vector représentant deux nombres et donner leur addition. Ecire un programme de test qui demandera une valeur de n à l'utilisateur et affichera le nombre de Fibonacci
	
	Fonctions comprises dans le programme:
		-  vector<int> add(const vector<int> &, const vector<int> &);
		-  vector<int> Fibonacci(int n);
		
2) /* Description du labo */
	
	Fonctions comprises dans le programme:
		- /* déclaration fonction1 */
		- /* déclaration fonction2 */
		
3) /* Description du labo */
	
	Fonctions comprises dans le programme:
		- /* déclaration fonction1 */
		- /* déclaration fonction2 */

----------------------------------------------------------------------------------------------------

