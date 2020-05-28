#ifndef STATE_HPP
#define STATE_HPP

#include "Entity.hpp"

class State
{
protected:
	std::stack<State*>* states;

	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;

	bool quit;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;


	//Ressources
	std::vector<sf::Texture> textures;

	//functions
	virtual void initKeybinds() = 0;

public:
	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~State();

	/*Les fonctions virtuelles garantissent que la fonction correcte est appelée pour un objet, 
	quel que soit le type de référence (ou pointeur) utilisé pour l'appel de fonction.
 - Ils sont principalement utilisés pour atteindre le polymorphisme d'exécution
 - Les fonctions sont déclarées avec un mot-clé virtuel dans la classe de base.
 - La résolution de l'appel de fonction se fait au moment de l'exécution.*/

	const bool& getQuit()const;
	virtual void CheckQuit();
	virtual void updateMousePosition();
	virtual void endState() = 0;
	virtual void updateInput(const float& dt)= 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr)= 0;
};
#endif

