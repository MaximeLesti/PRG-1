/*Maxime Lestiboudois, le 22/09/2023*/
/*Laboratoire 2*/
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
  cout << nb_secondes << " secondes valent "
       << semaine << " semaines, " 
       << jour << " jours, " 
       << heure << " heures, " 
       << minute << " minutes et "
       << seconde <<" secondes"
       << endl;
}
