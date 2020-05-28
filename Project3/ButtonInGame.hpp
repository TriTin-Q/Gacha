#ifndef BUTTONINGAME_HPP
#define BUTTONINGAME_HPP


#include <sstream>

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"

enum btn_states { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };

class ButtonInGame
{
private:
	//Boutton 
	short unsigned buttonState;

	sf::RectangleShape shape;
	sf::RectangleShape icon;
	sf::Texture  iconTexture;


	sf::Font* font;
	sf::Text text;

	/*sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color actifColor;*/
public:
	
	ButtonInGame(float x, float y, sf::Font* font, std::string text,
		 sf::RectangleShape shape, sf::Texture texture);
	~ButtonInGame();

	//functions 
	const bool isPressed() const;

	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);
};

#endif