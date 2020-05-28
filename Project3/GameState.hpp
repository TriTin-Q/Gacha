#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "State.hpp"
class GameState :
	public State
{
private:
	Entity player;

	//functions 
	void initKeybinds();


public:
	GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~GameState();

	
	void endState();

	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);
};

#endif

