/* Maxime Lestiboudois */
/* 17/11/2023 */
/* Laboratoire 17.2 : Récupérer un fichier caché dans une image au format BMP. */


#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const int pos_data_fichier = 10;
const int taille_octet = 8;
int main(){
	
	string nom_cache="";

	string nom_fichier;

	cout << "Quel fichier au format bmp voulez-vous ouvrir (sans l'extension)" << endl;
	getline(cin, nom_fichier);
	string fichier = nom_fichier + "_1_.bmp";
	string sys = "cp " + nom_fichier + ".bmp " + fichier ;
	system(sys.data());
	ifstream image(fichier, ios::in | ios::binary);

	image.seekg(pos_data_fichier);
	
	uint32_t pos_data;
	image.read((char*)&pos_data, 4);
	image.seekg(pos_data);

	
	int compt = 0;
	char nb;
	do{
		nb=0;

		for(int i = 0; i < taille_octet ; ++i){
			char data;
			image.get(data);

			if(data%2 != 0){
				nb |= 1<<i;
			}
			
		}
		nom_cache += nb;
	}while( nb != '\0');
	
cout << nom_cache <<endl;

	uint32_t taille_fichier_cache=0;
	int compteur = 0;
	for(int j =0; j<4 ; ++j){
		for(int i = 0; i < taille_octet ; ++i){
			char data;
			image.get(data);

			if(data%2 != 0){
				taille_fichier_cache |= 1<<compteur;
			}
			++compteur;
			
			
		}
	}
	
	ofstream fichier_cache;
	fichier_cache.open(nom_cache);
	
cout<< taille_fichier_cache <<endl;

	for(int j =0; j<taille_fichier_cache ; ++j){
			char fich=0;
			for(int i = 0; i < taille_octet ; ++i){
				char data;
				image.get(data);

				if(data%2 != 0){
					fich |= 1<<i;
				}
				
			}
		fichier_cache.write((char*)&fich, 1);
	}
	
	image.close();

	fichier_cache.close();

}
