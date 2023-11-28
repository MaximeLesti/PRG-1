/* Maxime Lestiboudois */
/* 20/11/2023 */
/* Laboratoire 18.1: Ecrire une fonction add prenant en paramètres 2 vector représentant deux nombres et donner leur addition. Ecire un programme de test qui demandera une valeur de n à l'utilisateur et affichera le nombre de Fibonacci */

 #include <iostream>
 #include <vector>
 using namespace std;
 
 //Déclaration de constantes
const int base_decimale = 10;
const vector<int> premier_terme_Fibonacci {0};
const vector<int> second_terme_Fibonacci {1};
 
 //Déclaration de fonctions
  vector<int> add(const vector<int> &, const vector<int> &);
  vector<int> Fibonacci(int n);
  
 int main(){
 	
 	int n;
 	cout <<"Quel valeur n de la suite de Fibonacci voulez-vous?" << endl;
 	cin >> n;
 	
 	vector<int> somme = Fibonacci(n);
 	
 	for(int i = 0; i< somme.size() ; ++i){
 		cout << somme[somme.size()-1-i];
 	}
 	cout << endl;
 
 }
 
 
 vector<int> add(const vector<int> & premier_nombre, const vector<int> & deuxieme_nombre){
 
 	int reste = 0;
 	int boucle = premier_nombre.size() > deuxieme_nombre.size() ? deuxieme_nombre.size() : premier_nombre.size();

 	int indice_premier = premier_nombre.size()-1;
 	int indice_deuxieme = deuxieme_nombre.size()-1;
 	bool plus_grand_1 = false;
 	bool plus_grand_2 = false;
 	
 	vector<int> addi;
 	
 	for(int i = 0 ; i < boucle ; ++i){
 		int addition = premier_nombre[indice_premier - i] + deuxieme_nombre[indice_deuxieme - i] + reste;

 		if(addition > 9){
 			reste = addition / base_decimale;
 			addition = addition % base_decimale;
 		}
 		else{
 			reste = 0;
 		}
 		plus_grand_1 = indice_premier - i > 0;
 		plus_grand_2 = indice_deuxieme - i > 0;
 		
		addi.push_back(addition);	
 	}
 	if(plus_grand_1){

 		int taille = premier_nombre.size() -1- boucle;

 		for(int i = 0; i <= taille ; ++i){

 			int addition = premier_nombre[taille - i] + reste;

	 		if(addition > 9){
	 			reste = addition / base_decimale;
	 			addition = addition % base_decimale;
	 		}
	 		else{
	 			reste = 0;
	 		}
	 		addi.push_back(addition);
	 	}
	 }
 	if(plus_grand_2){
	int taille = deuxieme_nombre.size()-1 - boucle;
		for(int i = 0; i < taille ; ++i){
			int addition = deuxieme_nombre[taille - i] + reste;
	 		if(addition > 9){
	 			reste = addition / base_decimale;
	 			addition = addition % base_decimale;
	 		}
	 		else{
	 			reste = 0;
	 		}
	 		addi.push_back(addition);
 		}
 	}
 	if(reste > 0){
 		addi.push_back(reste);
 	}
 			
 	return addi;
 
 }
 
 vector<int> Fibonacci(int n){
 	vector<int> pass;
 	vector<int> un = premier_terme_Fibonacci;
 	vector<int> deux = second_terme_Fibonacci;
 	int compt = 0;
 	 while(compt != n){
 	 	pass = un;
 	 	un = add(un, deux);
 	 	deux = pass;
 	 	++compt;
 	 }
 	 return un;
 
 }
