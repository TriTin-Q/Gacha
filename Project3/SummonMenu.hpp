#ifndef SUMMONMENU_HPP
#define SUMMONMENU_HPP
#include "State.hpp"
#include "ButtonSummon.hpp"
#include "Summon.hpp"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class SummonMenu :
	public State
{
private:

private:
	sf::RectangleShape background;
	sf::Texture  background_image;
	sf::Font font;

	std::map<std::string, ButtonSummon*> Button;

	sf::RectangleShape icon;
	sf::Texture iconTexture;

	void initVariables();
	void initFonts();
	void initKeybinds();
	void initButton();
	void initBackground();

public:
	SummonMenu(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~SummonMenu();

	void endState();
	void updateInput(const float& dt);
	void updateButton();
	void renderButton(sf::RenderTarget* target = nullptr);
	//void renderImage();
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);

};

#endif