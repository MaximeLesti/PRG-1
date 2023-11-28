/* Maxime Lestiboudois */
/* 06/11/2023 */
/* Laboratoire 14: Implanter une fonction de prototype string & replace_all(string & str, const string & from, const string & to) qui remplace dans str toutes les occurences de la sous-chaîne from par la sous-châine to. */

#include <iostream>
#include <fstream>
using namespace std;
//Déclaration de constantes
const string from = "de ";
const string to = "xYxYx ";
//Déclaration de fonctions
string & replace_all(string &, const string &, const string &);
string & replace_all_not_opti(string &, const string &, const string &);

int main(){
	fstream mon_fichier("Les_Miserables.txt", ios::in | ios::out);


	string str;
	while(getline(mon_fichier, str)){
		replace_all(str, from, to);
		cout << str  << endl;
	}
	mon_fichier.close();
	/*string test = "J'ai mangé le desespoir de desdemodes";
	cout << replace_all(test, from, to) << endl; */
}
//Fonction permettant de remplacer une sous-chaîne de caractères par une autre, dans une chaîne de caractère
string & replace_all(string & str, const string & from, const string & to){
	string nouvelle_str = str;
	int pos = str.find(from);

	while(nouvelle_str.find(from, pos)!= string::npos){

		nouvelle_str = nouvelle_str.substr(0, pos) 
				+ to + nouvelle_str.substr(pos 
				+ from.length());
		pos = nouvelle_str.find(from, pos+1);
	}

	str= nouvelle_str;	

	return str;
	
	
} 

string & replace_all_not_opti(string & str, const string & from, const string & to){

	size_t nb_pos = 0;
	size_t pos = 0;
	//Trouver le nombre d'occurence de la string from dans la string str
	while(str.find(from, pos)!= string::npos){
		++nb_pos;
		pos= str.find(from, pos)+1;
	}

	//Redéfinir la taille de la chaîne str
	int difference_d_aggrandissement =  (to.length() - from.length()) * nb_pos;
	string nouvelle_str = str;
	nouvelle_str.resize(str.length()+difference_d_aggrandissement);



	// remplacer les string from par les string to dans le texte
	int nouvelle_pos = str.find(from);
	while(nouvelle_str.find(from, nouvelle_pos)!= string::npos){
		nouvelle_str.replace(nouvelle_pos, from.length(), to);
		nouvelle_pos = nouvelle_str.find(from, nouvelle_pos+1);
	} 
	
	str= nouvelle_str;	

	return str;
	
	
} 
