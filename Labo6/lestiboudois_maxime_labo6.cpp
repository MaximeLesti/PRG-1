/* Maxime Lestiboudois */
/* 02/10/2023 */
/* Laboratoire 6: Déterminer à l'aide des coordonnées la forme géométrique représentée */

#include <iostream>
#include <math.h>
using namespace std;
 int main (){
 	int ax, ay, bx, by, cx, cy, dx, dy;
 	//Insertion des données
 	cout << "Entrez  consécutivement et séparées d'un espace les coordonnées des sommets\n";
 	cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
 	
 	//calcul des vecteurs
 	const int vecteur_ab_x = bx-ax;
 	const int vecteur_ab_y = by-ay;
 	
 	const int vecteur_bc_x = cx-bx;
 	const int vecteur_bc_y = cy-by;
 	
 	const int vecteur_cd_x = dx-cx;
 	const double vecteur_cd_y = dy-cy;
 	
 	const int vecteur_da_x = ax-dx;
 	const int vecteur_da_y = ay-dy;
 	
 	const int vecteur_bd_x = dx-bx;
 	const int vecteur_bd_y = dy-by;
 	
 	const int vecteur_ac_x = cx-ax;
 	const int vecteur_ac_y = cy-ay;
 	
 	//calcul des distances entre les points et des diagonales
 	const int distance_au_carre_de_a_b = vecteur_ab_x*vecteur_ab_x + vecteur_ab_y*vecteur_ab_y;
 	const int distance_au_carre_de_b_c = vecteur_bc_x*vecteur_bc_x + vecteur_bc_y*vecteur_bc_y;
 	const int distance_au_carre_de_c_d = vecteur_cd_x*vecteur_cd_x + vecteur_cd_y*vecteur_cd_y;
 	const int distance_au_carre_de_d_a = vecteur_da_x*vecteur_da_x + vecteur_da_y*vecteur_da_y;
 	
 	//calcul des vecteurs parallèles
 	const bool ab_cd_parallele = (bx-ax)*(dy-cy) == (by-ay)*(dx-cx);
 	const bool bc_da_parallele = (cx-bx)*(ay-dy) == (cy-by)*(ax-dx);
 	// calcul des vecteurs perpendiculaires
 	const bool ab_cd_perpendiculaire = vecteur_ab_x*vecteur_bc_x + vecteur_ab_y*vecteur_bc_y == 0;
 	const bool cd_da_perpendiculaire = vecteur_cd_x*vecteur_da_x + vecteur_cd_y*vecteur_da_y == 0;
 	const bool da_ab_perpendiculaire = vecteur_da_x*vecteur_ab_x + vecteur_da_y*vecteur_ab_y == 0;
 	const bool diagonales_perpendiculaire = vecteur_bd_x*vecteur_ac_x + vecteur_bd_y*vecteur_ac_y == 0;
 	
 	
 	//Affichage selon les conditions spécifiques des différents quadrilatères 
 	if(distance_au_carre_de_a_b == distance_au_carre_de_c_d && distance_au_carre_de_b_c == distance_au_carre_de_d_a && ab_cd_parallele && bc_da_parallele){
 			if(ab_cd_perpendiculaire && cd_da_perpendiculaire && da_ab_perpendiculaire){
 				if(distance_au_carre_de_b_c == distance_au_carre_de_c_d){
 					cout << "Le quadrilatère est un carré" << endl;
 				  }
 				else {
 					cout << "Le quadrilatère est un rectangle" << endl;
 				  }
 			  }
 			else {
 				if(diagonales_perpendiculaire){
					cout << "Le quadrilatère est un losange" << endl;
			  	  }	
			  	else{
 				cout << "Le quadrilatère est un parallèlogramme" << endl;
 			   	  }
 			   }	 	
 	  }
 	 else{
 		if(ab_cd_parallele || bc_da_parallele){
		 	cout << "Le quadrilatère est un trapèze" << endl;
		  }
		 else{
 			cout << "Le quadrilatère n'a pas de de forme définie" << endl;
 		  }
 	}
 	
 	
 }	
