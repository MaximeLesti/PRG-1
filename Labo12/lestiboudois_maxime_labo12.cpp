/* Maxime Lestiboudois */
/* 27/10/2023 */
/* Laboratoire 12: Utilisation et implémentation du système de Cryptage RSA */

#include <iostream>
#include <random>
using namespace std;
//Décalaration de structures
struct doublet_d_euclide {int n1; int n2;};

//Déclaration de fonction
bool est_ce_premier(int);
int euclide(int, int);
doublet_d_euclide algo_euclide_etendu(int, int);
bool sont_ils_premiers_entre_eux(int, int, int);
int exponentiation_modulaire(int, int, int);
int trouver_la_cle_secrete(int, int);


int main(){
	int p;
	int q;
	int e;
	
	cout << "Vous êtes Alice. Pour que Bob puisse vous transmettre un message secret, "
	"veuillez  introduire dans l'ordre deux nombres premiers (non-égaux) ainsi qu'un nombre e "
	"premier avec (p-1)(q-1) (e < 2³¹ - 1)" << endl;
	
	
		cin >> p >> q >> e;
		
		if(p == q || !est_ce_premier(p) || !est_ce_premier(q) || !sont_ils_premiers_entre_eux((p-1), (q-1), e) ){
			cout << "Les données sont incorrectes." << endl;
			}
		else{

			int cle_publique_n = p * q;
			int cle_secrete_d = algo_euclide_etendu(e, (p-1)*(q-1)).n1;
			
			cout << "Voici la clé publique: " << cle_publique_n << 
			", ainsi que la clé secrète: " << cle_secrete_d << endl;
			
			int message;
			
			cout << "Pour vérifier la teneur de notre code, veuillez introduire un message (nombre entier) inférieur à la clé publique" << endl;
			cin >> message;
			
			int message_crypte = exponentiation_modulaire(message, e, cle_publique_n);
			
			cout << "Voici le message crypté: " << message_crypte << endl;;
			
			message = exponentiation_modulaire(message_crypte, cle_secrete_d, cle_publique_n);
			cout << "Voici le message retrouvé: " << message << endl;
			
			
		}
	
}

bool est_ce_premier(int p){
	 
	int nombre_random;
	
	if(p < 2) {
		return false;
	}
	if(p == 2) {
		return true;
	}
	
	for (int i = 0 ; i < 10 ; ++i){	
		do{
			nombre_random = rand() % p;
		} while(nombre_random == 0);
		
		if(exponentiation_modulaire(nombre_random, (p - 1), p) != 1) {

		 	return false;
		 }
		 int q = 1;
		 int u = p - 1;
		 
		 while(u % 2 == 0 and q == 1){
			u = u / 2;
			q = exponentiation_modulaire(nombre_random, u, p);
			if( q != 1 and q != p-1) {

				return false;
			}				
	 	}
	}
	return true;
}

bool sont_ils_premiers_entre_eux(int p, int q, int e){
	int nombre_1= p*q;
	int pgdc = euclide(nombre_1, e);
	return (pgdc == 1);
}
int euclide(int nombre_1, int nombre_2){
	while(nombre_2 != 0){
		int t = nombre_2;
		nombre_2 = nombre_1 % nombre_2;
		nombre_1 = t;
	  }
	return nombre_1;
}
int trouver_la_cle_secrete(int e, int n){
	return algo_euclide_etendu(e,n).n1;
}
	
doublet_d_euclide algo_euclide_etendu(int e, int n){
	doublet_d_euclide dr;
	int r = n;
	int r_prime = e;
	int d = 0;
	int d_prime = 1;

	do{

		int q = r / r_prime;
		int rs = r;
		int ds = d;
		r = r_prime;
		d = d_prime;
		r_prime = rs - (q * r_prime);
		d_prime = ds - (q * d_prime);

	}while(r_prime != 0);
	
	if(d < 0){
		d =  d + n;
	}
	dr.n1 = d;
	dr.n2 = r;
	return dr;
	
	
		
}
int exponentiation_modulaire(int b, int e, int m){
	
	int r = 1;
	while(e > 0){
		if(e % 2 == 0){
			b = (b * b) % m;
			e = e / 2;
		}
		else {
			r = (r * b) % m;
			e = e - 1;
		}
	}
	return r;
}






