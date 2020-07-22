#ifndef SCENARIO_HPP
#define SCENARIO_HPP

#include "State.hpp"
#include "ButtonScenario.h"
#include "ButtonReturn.h"
#include "Accueil.hpp"
#include "Fight.hpp"

class Scenario :
	public State
{
	sf::RectangleShape background;
	sf::Texture  background_image;
	sf::Font font;

	std::map<std::string, ButtonScenario*> buttons;

	std::map<std::string, ButtonReturn*> button;


	sf::RectangleShape icon;
	sf::Texture iconTexture;

	sf::RectangleShape icon2;
	sf::Texture iconTexture2;

	sf::RectangleShape iconReturn;
	sf::Texture  iconReturnTexture;

	//functions 
	void initVariables();
	void initFonts();
	void initKeybinds();
	void initButton();
	void initBackground();

protected:

public:
	Scenario(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~Scenario();

	void endState();

	void updateInput(const float& dt);
	void updateButton();
	void renderButton(sf::RenderTarget* target = nullptr);
	//void renderImage();
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);
};
#endif 
