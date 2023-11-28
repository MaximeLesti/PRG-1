/* Maxime Lestiboudois */
/* 07/11/2023 */
/* Laboratoire 15 : Programme lisant un texte français au format UTF-8 et imprimant chacun des mots une seule et unique fois. */

#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

//Déclaration de constantes
const char separateur = ' ';
//Décalaration de fonctions:
string mots_uniques(string &);
string mots_uniques_bis(string &);


int main(){


	fstream mon_fichier("Les_Miserables.txt", ios::in | ios::out);


	/*string str;
	while(getline(mon_fichier, str)){

		cout << mots_uniques(str)  << endl;
	}
	mon_fichier.close(); */
	//string test = "dissident dara dissident avance bateau rêver manger bateau bateau";
	string test = "rêver, manger bouger! bouger";
	cout << mots_uniques_bis(test) << endl;

}

string mots_uniques(string & str){
	string dico = "";
	int pos = str.find(separateur);
	string mot;
	
	while(str.find(separateur) != string::npos){
		 mot = str.substr(0, pos);

		str.erase(0, pos+1);

		if(dico.find(mot) == string::npos){
			 dico+=mot+separateur;
		}
	pos = str.find(separateur);
	
	}

	if(dico.find(str) == string::npos){
			 dico+=str;
	}
	str = dico;
	return dico;
	
	
}
string mots_uniques_bis(string & str){

	string dico = "";

	while(str.length() != 0){
		string mot ="";
		int pos=0;
		for(int i=0; i<str.length(); ++i){
			if(isalpha(str[i]) || str[i] == 0xC3 || str[i] == 0xC5 || str[i] == 0xE2){
				mot += str[i];
				if(str[i] == 0xC3 || str[i] == 0xC5 || str[i] == 0xE2){
					mot += str[i+1];
					if(str[i] == 0xE2){
						mot += str[i+2];
						i++;
					}
					i++;
				}
				
			}
			else{
				pos= i;
				break;
			}

		}
		if(dico.find(mot) == string::npos){
			 dico+=mot+separateur;
		}
		str.erase(0,pos+1);

	
	}

	str = dico;
	return dico;
	
	
}

