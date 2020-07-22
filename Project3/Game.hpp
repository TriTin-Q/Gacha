#ifndef GAME_HPP
#define GAME_HPP

#include "MainMenuState.hpp"

class Game
{
private:
	 //Variable
	sf::RenderWindow * window;
	sf::Event sfEvent;
	//optimisation de la fenêtre
	std::vector<sf::VideoMode> videoMode;

	sf::ContextSettings windowSettings;
	bool fullscreen;

	sf::Clock dtClock;
	float dt;

	sf::SoundBuffer buffer;
	sf::Sound sound;

	std::stack<State*> states;


	std::map<std::string, int> supportedKeys;

	//Initialisation
	void initViarables();
	void initWindow();
	void initStates();
	void initKeys();
	void initSound();

public:
	Game();
	virtual ~Game();
	
	//functions
	void endApplication();

	//Update
 	void updateDt();
	void updateSFMLEvents();
	void update();

	//render
	void render();

	//core
	void run();

};
#endif