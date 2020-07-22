#ifndef BUTTONSUMMON_HPP
#define BUTTONSUMMON_HPP

#include <sstream>

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"

enum btn_Summon { IDLE_Summon = 0, HOVER_Summon, ACTIVE_Summon};

class ButtonSummon
{
private:
	short unsigned buttonState;

	sf::RectangleShape shape;
	sf::RectangleShape icon;
	sf::Texture  iconTexture;

	sf::Font* font;
	sf::Text text;

public:

	ButtonSummon(float x, float y, sf::Font* font, std::string text,
		sf::RectangleShape shape, sf::Texture texture);
	~ButtonSummon();

	//functions 
	const bool isPressed() const;

	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);
};

#endif