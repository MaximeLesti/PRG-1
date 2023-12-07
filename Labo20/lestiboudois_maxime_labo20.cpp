/* Maxime Lestiboudois */
/* 04/12/2023 */
/* Laboratoire 20: Définir une classe Mot et compter le nombre d'occurence de tous les mots dans une liste (vector) */

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//Déclaration de classes
class Mot{
	private:
		string mot;
		int nb = 1;
	public:
		Mot(string mot);
		void incremente();
		string getMot() const;
		int getOccurence() const;
};

Mot::Mot(string nmot){
	mot = nmot;
};
void Mot::incremente(){
	++nb;
};
string Mot::getMot() const{
	return mot;
};
int Mot::getOccurence() const{
	return nb;
}
using Lexique = vector<Mot>;

//Déclaration de fonction
int dichotomie(const Lexique &, const string &);
Lexique mots(string str);
/*
Chic
Estrella
Gaia
Karinga
Maminga
Morue
Morue
Rio
Zenge */

int main(){
	Lexique bis = {Mot("zenge"), Mot("morue"), Mot("karinga"), Mot("maminga"), Mot("gaia"), Mot("estrella"), Mot("rio"), Mot("chic"), Mot("chic"), Mot("zenge"), Mot("morue")};
	
	/*fstream mon_fichier("Les_Miserables.txt", ios::in | ios::out);
	
	Lexique lexique;

	string str;
	getline(mon_fichier, str, '\0');
	lexique = mots(str);	
	mon_fichier.close(); 
	for(int i = 0; i<50; ++i){
		cout << lexique[i].getMot() << endl;
	}*/
	Lexique lex;
	lex.push_back(lexique[0]);
	if(lexique[1].getMot() < lex[0].getMot()){
		lex.insert(lex.begin(), lexique[1]);
	}
	else{
		lex.push_back(lexique[1]);
	}
	
	for(int i = 2; i < lexique.size(); ++i){

		int pos = dichotomie(lex, lexique[i].getMot());

		if(lexique[i].getMot() == lex[pos].getMot()){
			lex[pos].incremente();

		}
		else{

			lex.insert(lex.begin()+pos, lexique[i]);
		}
	}
	
	for(int j = 0; j < lex.size(); ++j){
		cout << lex[j].getMot() << " : "<< lex[j].getOccurence() << endl;
	}*/
			
	
	
}

int dichotomie(const Lexique & lex, const string & str){
	int max = lex.size();
	int min =  0;
	

	int compt = 0;

	while(compt <= lex.size()){
		int dist=((max + min) / 2);

		if(lex[dist].getMot() == str){
			return dist;
		}
		if(str < lex[dist].getMot()){
			max = dist;
		}
		
		else if( str > lex[dist].getMot()){
			min = dist;
		}
		
		if(min == max){
			return min;
		}
		++compt;
	}
	return max;
}

/*Lexique mots(string str){


	Lexique lexique;

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
		if(lexique.size() >= 2){

			int pos = dichotomie(lexique, mot);

			if(mot == lexique[pos].getMot()){
				lexique[pos].incremente();

			}
			else{

				lexique.insert(lexique.begin()+pos, Mot(mot));
			}
			
		}
		else if(lexique.size() == 0 ){
			lexique.push_back(Mot(mot));
		}
		else{
			if(mot < lexique[0].getMot()){
				lexique.insert(lexique.begin(), Mot(mot));
			}
			else{
				lexique.push_back(Mot(mot));
			}
	}
		
		str.erase(0,pos+1);

	
	}


	return lexique;
	
	
}
*/
		
		
