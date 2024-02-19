/* Maxime Lestiboudois */
/* 26/01/2024 */
/* Définitions des méthodes de la classe Sint */

//Constructeur de la classe Sint
Sint::Sint(int entier_signe){
	if(entier_signe < 0){
		this -> signe = 1;
		this -> uint = Uint(-entier_signe);
	}
	else {
		this -> signe  = 0;
		this -> uint = Uint(entier_signe);
	}
}
	
//Redéfiniton de l'opérateur unaire - pour la classe Sint
Sint Sint::operator-() const{
	Sint sint = *this;
	sint.signe = (this->signe == 0) ? 1 : 0;
	return sint;
}

//Redéfintion de l'opérateur += de la classe Sint
Sint & Sint::operator+= (const Sint & droite){

	if(this->signe == droite.signe){
		this->uint += droite.uint;
	}
	else {
		if(this->uint > droite.uint){
			this->signe = droite.signe;
			this->uint = droite.uint - this->uint;
		}
		else{
			
			this->uint -= droite.uint;
		}
	}
	return *this;	
}

//Redéfinition de l'opérateur -= de la classe Sint
Sint & Sint::operator-= (Sint droite){

	droite += -*this;
	*this = droite;
	return *this;	
}

//Redéfinition de l'opérateur *= de la classe Sint
Sint & Sint::operator*= (const Sint & droite){
	this->signe = (this->signe == droite.signe) ? 0 : 1;
	this->uint *= droite.uint;
	
	return *this;
}
//Redéfinition de l'opérateur /= de la classe Sint
Sint & Sint::operator/= (const Sint & droite){
	this->signe = (this->signe == droite.signe) ? 0 : 1;
	this->uint = droite.uint/this->uint;
	
	return *this;
}

//Redéfinition de l'opérateur de l'addition de la classe Sint
Sint Sint::operator+ (Sint droite) const{
	return (droite += *this);
}

//Redéfintion de l'opérateur de la soustraction de la classe Sint
Sint Sint::operator- (Sint droite) const{	
	return (droite-= *this);
}

//Redéfinition de l'opérateur de la multiplication de la classe Sint
Sint Sint::operator* (Sint droite) const{
	return (droite *= *this);
	
}

//Redéfinition de l'opérateur de la division de la classe Sint
Sint Sint::operator/ (Sint droite) const{
	Sint sint = *this;
	
	return (sint /= droite);
}

//Redéfinition de l'opérateur du modulo de la classe Sint
Sint Sint::operator% (const Sint & droite) const{
	if(this->signe == 1)
		throw std::out_of_range("modulo négatif");
	Sint sint = *this;
	sint.uint = this->uint % droite.uint;
	
	return sint;	
}

//Redéfinition de l'opérateur d'équivalence de la classe Sint
bool Sint::operator==(const Sint & droite) const{
	
	return (this->signe == droite.signe && this->uint == droite.uint);
}

//Redéfinition de l'opérateur de non-équivalence de la classe Sint
bool Sint::operator!=(const Sint & droite) const{
	return !(*this == droite);
}

//Redéfinition de l'opérateur de comparaison "inférieur à" de la classe Sint
bool Sint::operator>(const Sint & droite) const{
	
	return (this->signe != droite.signe) ? (this->signe == 0) : (this->uint < droite.uint);
}

//Redéfinition de l'opérateur de comparaison "supérieur à" de la classe Sint
bool Sint::operator<(const Sint & droite) const{
	return (this->signe != droite.signe) ? (this->signe == 1) : (this->uint > droite.uint);
}

//Redéfinition de l'opérateur de comparaison "inférieur ou égal à" de la classe Sint
bool Sint::operator<=(const Sint & droite) const{
	return (*this<droite || *this == droite);
}

//Redéfinition de l'opérateur de comparaison "supérieur ou égal à" de la classe Sint
bool Sint::operator>=(const Sint & droite) const{
	return (*this>droite || *this == droite);
}
//Méthode retournant vrai si la valeur de l'instance de Sint est nulle
bool Sint::isNull(){
	return this->uint.isNull();
}

//Surcharge de la fonction << des flux pour 
std::ostream & operator<< (std::ostream & sortie, const Sint & objet){
	sortie << objet.uint;
	return sortie;
}

