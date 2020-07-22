#ifndef FICHEPERSONNAGE_HPP
#define FICHEPERSONNAGE_HPP

#include "GameState.hpp"
#include "ButtonReturn.h"
#include "State.hpp"
#include "Box.hpp"

class FichePersonnage : 
	public State
{
private:

	sf::RectangleShape background;
	sf::Texture  background_image;
	sf::Font font;
	sf::Text text;

	std::map<std::string, ButtonReturn*> button;

	sf::Text textNom;

	sf::RectangleShape logo;
	sf::Texture  logoTexture;

	sf::RectangleShape casual;
	sf::Texture casualTexture;

	sf::RectangleShape uniforme;
	sf::Texture uniformeTexture;

	sf::RectangleShape costume;
	sf::Texture costumeTexture;

	sf::RectangleShape firstBack;
	sf::Texture firstBackTexture;

	sf::RectangleShape secondBack;

	sf::RectangleShape thirdBack;

	sf::RectangleShape fourthBack;

	sf::Text textInformation;

	sf::Text textName;
	sf::Text textCasual;
	sf::Text textUniforme;
	sf::Text textCostume;


	sf::RectangleShape iconStat;
	sf::Text textHeroName;


	sf::RectangleShape iconReturn;
	sf::Texture  iconReturnTexture;
	//functions 
	void initVariables();
	void initFonts();
	void initKeybinds();
	void initButton();
	void initBackground(std::string color);
	void initInformation(int indice, int vilOrHero);
	


public:
	//Indice : 0-Deku, 1-Bakugo, 2-Tomura
	//Villain_Or_Hero : Pour le background 
 	FichePersonnage(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states,
		int indice, int Villain_Or_Hero, std::string color);
	virtual ~FichePersonnage();

	void endState();

	void updateInput(const float& dt);
	void updateButton();
	void renderButton(sf::RenderTarget* target = nullptr);
	void updateInformation();
	void renderInformation(sf::RenderTarget* target = nullptr);
	//void renderImage();
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);

};

#endif

