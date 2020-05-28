#include "Personnage.hpp"

Personnage::Personnage(string name,string describ, float level, 
	float point_de_vie, 
	int rank, float speed, float speed_bar, 
	float mana_bar, string capcity_name, 
	float niveau_max, int indice, bool obtenu) {

	nom = name;
	description = describ;
	niveau = level;
	pv = point_de_vie;
	rang = rank;
	vitesse = speed;
	barre_vitesse = speed_bar;
	nom_capacite = capcity_name;
	barre_mana = mana_bar;
	lvl_max = niveau_max;
	indice_Perso = indice;
	attaque = select_power(rank);


}

Personnage::Personnage()
{
}


Personnage::~Personnage()
{
}

float Personnage::select_power(int rang) {
	switch (rang) {
	case 0:
		return 30;
		break;
	case 1:
		return 50;
		break;
	}
	return 0;
}

void Personnage::afficher_personnage(int test)
{
	
}

void Personnage::afficher_perso(Personnage perso)
{
	std::cout << "Nom : " << perso.nom << "\n";
	std::cout << "Nom : " << perso.description << "\n";
}

bool Personnage::obtenu(string perso)
{
		string file = "Personnages\\";
		file += perso;
		file += ".ini";
		std::cout << "Nom du fichier :" << file << "\n";
		std::ifstream ifs(file);
		std::string titre = "None";
		std::string name;
		std::string describ;
		float level;
		float point_de_vie;
		int rank; float speed; float speed_bar;
		float mana_bar; string capcity_name;
		float niveau_max; int indice; bool obtenu;

		if (ifs.is_open()) {
			std::getline(ifs, titre);
			ifs >> name;
			ifs >> describ;
			ifs >> level;
			ifs >> point_de_vie;
			ifs >> rank;
			ifs >> speed;
			ifs >> speed_bar;
			ifs >> mana_bar;
			ifs >> capcity_name;
			ifs >> niveau_max;
			ifs >> indice;
			ifs >> obtenu;

	}
	//à revoir pourquoi il faut utilisé &Class::membre
	return  obtenu;
}
