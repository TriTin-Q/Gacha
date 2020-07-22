#include "Fight.hpp"
#include <Windows.h>

void Fight::initVariables()
{
}

void Fight::initFonts()
{
	if (!this->font.loadFromFile("Fonts/NaughtyMonster.ttf")) {
		throw("THERE'S A PROBLEM WITH THE FONTS !");
	}
}

void Fight::initKeybinds()
{
	std::ifstream ifs("Config/mainmenustate_keybinds.ini");


	if (ifs.is_open())
	{
		std::string key = "";
		std::string key_value = "";

		while (ifs >> key >> key_value) {

			this->keybinds[key] = this->supportedKeys->at(key_value);

		}
	}
	ifs.close();
}

void Fight::initButton()
{
}

void Fight::initBackground()
{
	this->background.setSize(
		sf::Vector2f(this->window->getSize().x
			, this->window->getSize().y)
	);

	if (!this->background_image.loadFromFile("Data/Background_fight.jpg")) {
		throw "ERROR PICTURE OF BACKGROUND !";
	}
	this->background.setTexture(&this->background_image);
}

void Fight::initCharacter(int nbCharac)
{

}

Fight::Fight(sf::RenderWindow * window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, int indice)
	:State(window, supportedKeys, states)
{

	this->initVariables();
	this->initFonts();
	this->initButton();
	this->initBackground();
	this->initKeybinds();
}

Fight::~Fight()
{

}

void Fight::endState()
{
	std::cout << "End Game State !" << "\n";

}



void Fight::BoxText(int indice)
{
	if (!boxTextTexture.loadFromFile("Data/textBox.jpg"))
	{
		throw("TEXTURE TEXTBOX'S GOT A PROBLEM");
	}
	this->boxText.setTexture(&this->boxTextTexture);
	this->boxText.setSize(sf::Vector2f(this->window->getSize().x - 40, 400));
	this->boxText.setPosition(sf::Vector2f(20, this->window->getSize().y - 420));
	this->text.setPosition(this->boxText.getPosition().x + 70, this->boxText.getPosition().y + 20);
	this->text.setCharacterSize(30);
	this->text.setFont(this->font);
	if (indice == 0) {
		if (!iconTexture.loadFromFile("Data/Deku0.png")) {
			throw("TEXTURE DEKU'S BOX GOT A PROBLEM");
		}
		this->icon.setTexture(&this->iconTexture);
		this->icon.setSize(sf::Vector2f(350, 350));
		this->icon.setPosition(this->boxText.getPosition().x
			, this->boxText.getPosition().y - this->icon.getSize().y);
		this->text.setString("YUEI !! Je vais pas vous déçvoir, All... \n *se fait couper la parole*");
	}
	if (indice == 1){
		if (!iconTexture.loadFromFile("Data/Bakugo1.png")) {
			throw("TEXTURE BAKUGO'S BOX GOT A PROBLEM");
		}
		this->icon.setTexture(&this->iconTexture);
		this->icon.setSize(sf::Vector2f(350, 350));
		this->icon.setPosition(this->boxText.getPosition().x + this->boxText.getSize().x
			- this->icon.getSize().x
			, this->boxText.getPosition().y - this->icon.getSize().y);
	this->text.setString("DEKUUU !!!");
	}
}

void Fight::updateBoxText(int indice)
{	
	BoxText(indice);
	//Sleep(5000);

}

void Fight::updateInput(const float & dt)
{
	this->CheckQuit();

}

void Fight::updateButton()
{
}

void Fight::renderButton(sf::RenderTarget * target)
{
}

void Fight::update(const float & dt)
{
	this->updateInput(dt);
	this->updateButton();
	this->updateMousePosition();
	this->updateBoxText(0);
	
}

void Fight::render(sf::RenderTarget * target)
{
	if (!target) {
		target = this->window;
	}
	target->draw(this->background);
	target->draw(this->boxText);	
	target->draw(this->icon);
	target->draw(this->text);
}
