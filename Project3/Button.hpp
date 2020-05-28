#ifndef BUTTON_HPP
#define BUTTON_HPP


#include <sstream>

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"

enum button_states{BUTTON_IDLE = 0, BUTTON_HOVER, BUTTON_ACTIVE};

class Button
{
private:
	//Boutton 
	short unsigned buttonState;

	sf::RectangleShape shape;
	sf::RectangleShape icon;

	sf::Texture  iconTexture;

	sf::Font* font;
	sf::Text text;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color actifColor;
public:
	Button(float x, float y, float width, float height,
		sf::Font* font, std::string text, sf::Color idleColor,
		sf::Color hoverColor, sf::Color actifColor);
	~Button();

	//functions 
	const bool isPressed() const;
	
	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);
};

#endif