#ifndef SUMMON_HPP
#define SUMMON_HPP
#include "State.hpp"
#include <ctime>
#include <cstdlib>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class Summon :
	public State
{
private:
	bool smoke;
	int tmp = 0;

	sf::IntRect rectSourceSprite1;
	sf::Sprite sprite1;
	sf::Sprite sprite2;

	sf::IntRect rectSourceSprite3;
	sf::Sprite sprite3;

	sf::Texture texture;
	sf::RectangleShape icon;
	sf::Texture texture2;
	sf::Texture texture3;

	sf::Font font;
	sf::Clock clock;

	sf::RectangleShape background;
	sf::RectangleShape background2;
	sf::Texture background_image2;
	sf::Texture background_image;

	void initVariables();
	void initFonts();
	void initKeybinds();
	void initButton();
	void initBackground();
	void initCharacter(int nbCharac);

public:
	Summon(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, int indice);
	virtual ~Summon();

	void endState();

	void updateInput(const float& dt);
	void updateButton();
	void updateCharcter();
	void renderButton(sf::RenderTarget* target = nullptr);
	//void renderImage();
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);

};
#endif