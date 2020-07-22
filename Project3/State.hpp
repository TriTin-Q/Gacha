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

	/*Les fonctions virtuelles garantissent que la fonction correcte est appel�e pour un objet, 
	quel que soit le type de r�f�rence (ou pointeur) utilis� pour l'appel de fonction.
 - Ils sont principalement utilis�s pour atteindre le polymorphisme d'ex�cution
 - Les fonctions sont d�clar�es avec un mot-cl� virtuel dans la classe de base.
 - La r�solution de l'appel de fonction se fait au moment de l'ex�cution.*/

	const bool& getQuit()const;
	virtual void CheckQuit();
	virtual void updateMousePosition();
	virtual void endState() = 0;
	virtual void updateInput(const float& dt)= 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr)= 0;
};
#endif

