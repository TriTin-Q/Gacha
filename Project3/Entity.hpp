#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <fstream>
#include <sstream>
#include <stack>
#include <map>

#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"
class Entity
{
private:

protected:
	//Utilisons "protected, car entity va être utilisé dans beauoup de classe
	//For the hitBox
	sf::RectangleShape shape;
	float mouvementSpeed;
public:
	Entity();
	virtual ~Entity();

	//functions
	virtual void move(const float& dt, const float dir_x, const float dir_y);
	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);
};

#endif