#ifndef ACCUEIL_HPP
#define ACCUEIL_HPP

#include "GameState.hpp"
#include "ButtonInGame.hpp"
#include "State.hpp"
#include "Box.hpp"


class Accueil :
	public State
{
private:
	sf::RectangleShape background;
	sf::Texture  background_image;
	sf::Font font;

	std::map<std::string, ButtonInGame*> buttons;

	sf::RectangleShape icon;
	sf::Texture  iconTexture;

	sf::RectangleShape icon2;
	sf::Texture  iconTexture2;

	sf::RectangleShape icon3;
	sf::Texture  iconTexture3;


	ButtonInGame * gameState_btn;


	//functions 
	void initVariables();
	void initFonts();
	void initButton();
	void initBackground();
	void initKeybinds();



public:
	Accueil(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~Accueil();


	void endState();

	void updateButton();
	void renderButton(sf::RenderTarget* target = nullptr);
	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);
};

#endif

