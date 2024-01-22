Résumé Labo23:

Rendre générique la procédure du tri par peigne données, de sorte qu’elle prenne en paramètre 2 itérateurs à accès direct. Comparer le temps de calcul de cette procédure pour trier des vector<int> avec celui de std::sort.
	
	Fonctions comprises dans le programme:
		- template <typename Iterator>
		  void tri_peigne(Iterator first, Iterator last);
		- void tri_peigne_primaire(std::vector<double> & v);
		
	
