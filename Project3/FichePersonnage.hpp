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

	sf::RectangleShape iconPersonnage;
	sf::Texture  iconPersonnageTexture;

	sf::RectangleShape iconPersonnageFond;


	sf::RectangleShape iconInformation;
	sf::Text textInformation;

	sf::RectangleShape iconCapacity;
	sf::Text textCapacity;

	sf::RectangleShape iconStat;
	sf::Text textStats;

	sf::RectangleShape iconReturn;
	sf::Texture  iconReturnTexture;
	//functions 
	void initVariables();
	void initFonts();
	void initKeybinds();
	void initButton();
	void initBackground(int VilOrHero);
	void initInformation(int indice);
	


public:
	//Indice : 0-Deku, 1-Bakugo, 2-Tomura
	//Villain_Or_Hero : Pour le background 
 	FichePersonnage(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, int indice, int Villain_Or_Hero);
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

