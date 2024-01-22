


Sint::Sint(int sint){
	if(sint < 0){
		this -> signe = 1;
		this -> uint = Uint(-sint);
	}
	else {
		this -> signe  = 0;
		this -> uint = Uint(sint);
	}
}
Sint operator-(const Sint & gauche, const Sint & droite){

	Sint retour = Sint();
	
	if(gauche.signe == 0 && droite.signe == 0){
		if(gauche.uint < droite.uint){	
			retour.uint = droite.uint - gauche.uint;
			retour.signe = 1;
		}
		else{
			retour.uint = gauche.uint - droite.uint;
			retour.signe = 0;
		}
	}
	else if(gauche.signe == 1 && droite.signe == 0){
		retour.uint = gauche.uint + droite.uint;
		retour.signe = 1;
	}
	else if(gauche.signe == 0 && droite.signe == 1){
		retour.uint = gauche.uint + droite.uint;
		retour.signe = 0;
	}
	else{
		if(gauche.uint > droite.uint){	
			retour.uint = gauche.uint - droite.uint;
			retour.signe = 1;
		}
		else{
			retour.uint = droite.uint - gauche.uint;
			retour.signe = 0;
		}
	}
	return retour;	
}
	
		
	

