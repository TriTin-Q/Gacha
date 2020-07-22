#ifndef FIGHT_HPP
#define FIGHT_HPP

#include "State.hpp"
#include "ButtonReturn.h"

class Fight :
	public State
{
private:
	sf::RectangleShape background;
	sf::Texture  background_image;
	sf::Font font;

	sf::RectangleShape icon;
	sf::Texture iconTexture;

	sf::RectangleShape icon2;
	sf::Texture iconTexture2;

	sf::RectangleShape boxText;
	sf::Texture boxTextTexture;
	sf::Text text;

	sf::Texture textureCharacter;

	//functions 

	void initVariables();
	void initFonts();
	void initKeybinds();
	void initButton();
	void initBackground();
	void initCharacter(int nbCharac);

public:
	Fight(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, int indice);
	virtual ~Fight();

	void endState();


	void BoxText(int indice);
	void updateBoxText(int indice);
	void updateInput(const float& dt);
	void updateButton();
	void renderButton(sf::RenderTarget* target = nullptr);
	//void renderImage();
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);
};
#endif

