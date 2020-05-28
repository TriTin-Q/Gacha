#ifndef MAINMENUSTATE_HPP
#define MAINMENUSTATE_HPP
#include "Button.hpp"
#include "Accueil.hpp"



class MainMenuState :
	public State
{
private:
	Entity player;
	sf::RectangleShape background;
	sf::Texture  background_image;
	sf::Font font;

	std::map<std::string, Button*> buttons;

	Button * gameState_btn;


	//functions 
	void initVariables();
	void initFonts();
	void initKeybinds();
	void initButton();
	void initBackground();

protected:

public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~MainMenuState();

	void endState();

	void updateInput(const float& dt);
	void updateButton();
	void renderButton(sf::RenderTarget* target = nullptr);
	//void renderImage();
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);


};
#endif

