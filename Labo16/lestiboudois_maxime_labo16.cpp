/* Maxime Lestiboudois */
/* 13/11/2023 */
/* Laboratoire 16 : Génération d'un fichier KLM à l'aide d'un fichier txt fournissant des coordonnées WPGS84 lambda et phi */

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

// Déclaration de constantes
const char separateur_coord = ',';
const char separateur = ' ';
//Déclaration de structures
struct coord {string e; string n;};
//Déclaration de fonctions
string generationKLM(string);
string WPGS84toCH1903(string);

int main(){
	string nom;
	int assurance;
	string ligne = "";
	string marathon;
	fstream mon_fichier("marathon_de_la_heig.txt", ios::in | ios::out);
	while(getline(mon_fichier, ligne)){
		if(ligne !=""){
			marathon += WPGS84toCH1903(ligne);

		}
	}

	mon_fichier.close();
	
	cout << "Quel nom voulez-vous donner à votre fichier (ajoutez l'extension .klm) ?\nAttention, s'il existe déjà, le fichier existant sera écraser." << endl;
	getline(cin, nom);
	
	
	
	ofstream fichierKLM;
	fichierKLM.open(nom);
	fichierKLM << generationKLM(marathon);
	fichierKLM.close();


}

string generationKLM(string str){
	string syntaxe_debut = "<kml xmlns=\"http://www.opengis.net/kml/2.2\">\n   <Document>\n      <name>Marathon HEIG</name>\n      <Placemark>\n        <Style>\n           <LineStyle>\n             <color>660000cc</color>\n             <width>5</width>\n          </LineStyle>\n        </Style>\n        <LineString>\n          <altitudeMode>clampToGround</altitudeMode>\n          <coordinates>";
	string syntaxe_fin ="\n          </coordinates>\n        </LineString>\n      </Placemark>\n   </Document>\n</kml>";

	return syntaxe_debut + str + syntaxe_fin;
}

string WPGS84toCH1903(string str){
	size_t espace = str.find(separateur);
	string s_x (str,0,espace);
	string s_y (str, espace+1);
	
	double x = pow(10, -8)*((double) stoi(s_x)/100.0);
	double y = pow(10, -8)*((double) stoi(s_y)/100.0);

	double lambda_0 = 7.4386372
			+ 13.13606 * x
			+ 2.19856 *x * y
			+ 0.3628 * x * y * y
			- 0.121 * x * x * x;
			
	double phi_0 = 46.9510811
			+ 8.9952 * y
			- 0.75272 * x * x
			- 0.00702 * y * y
			- 0.1242 * x * x * y
			- 0.0389 * y * y * y;
			
	double lambda = lambda_0 * 100 / 36;
	double phi = phi_0 * 100 / 36;
	
	return to_string(lambda) + separateur_coord + to_string(phi) + separateur;
}
