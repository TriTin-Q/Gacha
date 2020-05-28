#ifndef BOX_HPP
#define BOX_HPP

#include "GameState.hpp"
#include "ButtonCharacter.hpp"
#include "ButtonReturn.h"
#include "State.hpp"
#include "Accueil.hpp"
#include "FichePersonnage.hpp"
#include "Personnage.hpp"

class Box : 
	public State
{
private:
	std::string tabNom[100] = { "Deku", "Bakugo","All_Might","Denki","Eijiro"
		,"Fumikage","iida","kyoka","Mina","Miyrio","Momo","Ochaco","Shoto","Tsuyu","" };

	sf::RectangleShape background;
	sf::Texture  background_image;
	sf::Font font;
	sf::Text text;
	sf::Text text2;


	std::map<std::string, ButtonCharacter*> buttons;
	std::map<std::string, ButtonReturn*> button;


	sf::RectangleShape icon;
	sf::Texture  iconTexture;
	sf::RectangleShape icon2;
	sf::Texture  iconTexture2;
	sf::RectangleShape icon3;
	sf::Texture  iconTexture3;
	sf::RectangleShape icon4;
	sf::Texture  iconTexture4;
	sf::RectangleShape icon5;
	sf::Texture  iconTexture5;
	sf::RectangleShape icon6;
	sf::Texture  iconTexture6;
	sf::RectangleShape icon7;
	sf::Texture  iconTexture7;
	sf::RectangleShape icon8;
	sf::Texture  iconTexture8;
	sf::RectangleShape icon9;
	sf::Texture  iconTexture9;
	sf::RectangleShape icon10;
	sf::Texture  iconTexture10;
	sf::RectangleShape icon11;
	sf::Texture  iconTexture11;
	sf::RectangleShape icon12;
	sf::Texture  iconTexture12;
	sf::RectangleShape icon13;
	sf::Texture  iconTexture13;


	sf::RectangleShape iconReturn;
	sf::Texture  iconReturnTexture;

	//functions 
	void initVariables();
	void initFonts();
	void initButton(Personnage);
	void initBackground();
	void initKeybinds();

public:
	Box(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual~Box();

	void endState();

	void updateButton();
	void renderButton(sf::RenderTarget* target = nullptr);
	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);
};
#endif

