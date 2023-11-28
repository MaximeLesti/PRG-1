/*Maxime Lestiboudois, le 22/09/2023*/
/*Laboratoire 5*/
/* Transformation en semaines, jours, heure, minutes et secondes d'un temps exprimé en secondes*/

#include <iostream>

using namespace std;

const int semaine_en_secondes= 604800;
const int jour_en_secondes=86400;
const int heure_en_secondes=3600;
const int minute_en_secondes=60;

int main()
{
  int nb_secondes; //  nombre de secondes entrées par l'utilisateur
  cout << "Nombre de seconde à transformer en jour, heures, minutes et secondes: " << endl;
  cin >> nb_secondes;
  
  // calcul du nombre de semaines, de jours, d'heures, de minutes et de secondes dans le nombre introduit par l'utilisateur
  int semaine = nb_secondes/semaine_en_secondes;
  int reste=nb_secondes%semaine_en_secondes;
  int jour =reste/jour_en_secondes;
  reste= reste%jour_en_secondes;
  int heure = reste/heure_en_secondes;
  reste=reste%heure_en_secondes;  
  int minute = reste/minute_en_secondes;
  int seconde = reste%minute_en_secondes;
  
  
  // Affichage du résultat 
  if (nb_secondes < minute_en_secondes){
  	if(nb_secondes == 1){
  		cout << "Vous avez introduit 1 seconde";
  		}
  	else{
  		cout << "Vous avez introduit " << nb_secondes << " secondes.";
  	}
  }
  else{
	  cout << nb_secondes << " secondes valent ";
	  
	  if (semaine >= 1){
	  	if(semaine ==1){
	  		cout << semaine << " semaine, ";
	  	}
	  	else{
		  	cout << semaine << " semaines, ";
		  }
	  }
	  if (jour >= 1){
	  	if(jour ==1){
	  		cout << jour << " jour, ";
	  	}
	  	else{
		  	cout << jour << " jours, ";
		  }
	  }
	  if (heure >= 1){
	  	if(heure ==1){
	  		cout << heure << " heure, ";
	  	}
	  	else{
		  	cout << heure << " heures, ";
		  }
	  }
	  if (minute >= 1){
	  	if(minute ==1){
	  		cout << minute << " minute ";
	  	}
	  	else{
		  	cout << minute << " minutes ";
		  }
	  }
	  
	   if(seconde ==1){
		cout << " et " <<seconde << " seconde ";
	   }
	   else{
	  	cout << " et " << seconde << " secondes ";
	   }
       }
}

