#ifndef GACHA_PERSONNAGE_HPP
#define GACHA_PERSONNAGE_HPP
#include <string>
#include <iostream>
using namespace std;
#include<fstream>
class Personnage {
private:
	string nom;
	string description;
	float attaque;
	float niveau;
	string rang;
	float pv;
	float vitesse;
	float barre_vitesse;
	float barre_mana;
	float lvl_max;
	int indice_Perso;
	string nom_capacite;
	//bool obtenu;
	//string rareté;
	//Pour la liste des personnage
	int Debutant = 0;
	int Student = 1;
	float speed_bar;
	Personnage * perso;

public:
	//Caractéristique d'un personnage


	Personnage(string name, string describ, float level,
		float point_de_vie,
		int rank, float speed, float speed_bar,
		float mana_bar, string capcity_name,
		float niveau_max, int indice, bool obtenu);
	Personnage();
	~Personnage();
	float select_power(int);
	void afficher_personnage(int);
	void afficher_perso(Personnage);
	void revetement_Deku(Personnage);
	float level_up(Personnage);
	Personnage return_perso(int);
	void capacity(Personnage, Personnage);
	bool obtenu(string);


	Personnage * tab_Personnage[50];

};

#endif
