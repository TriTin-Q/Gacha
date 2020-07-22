#ifndef BUTTONSCNEARIO_H
#define BUTTONSCNEARIO_H

#include <sstream>

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
enum btn_scenario { IDLE_M = 0, HOVER_M, ACTIVE_M };

class ButtonScenario
{
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

	ButtonScenario(float x, float y, sf::Font* font, std::string text,
		sf::RectangleShape shape, sf::Texture texture);
	~ButtonScenario();

	//functions 
	const bool isPressed() const;

	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);
};
#endif

