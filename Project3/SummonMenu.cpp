#include "SummonMenu.hpp"

void SummonMenu::initVariables()
{
}

void SummonMenu::initFonts()
{
	if (!this->font.loadFromFile("Fonts/NaughtyMonster.ttf")) {
		throw("THERE'S A PROBLEM WITH THE FONTS !");
	}
}

void SummonMenu::initKeybinds()
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

void SummonMenu::initButton()
{
	if (this->iconTexture.loadFromFile("Data/ButtonSummon.png")) {
		this->icon.setTexture(&this->iconTexture);
		std::cout << "THE CHARACH ICON'S SUMMON IS OK ! " << "\n";
		this->Button["SUMMON_STATE"] = new ButtonSummon(this->window->getSize().x/2 - icon.getSize().x -150, 50
			, &this->font, "Summon !",
			this->icon, this->iconTexture);
	}
	else {
		std::cout << "THERE'S A PROBLEM WITH THE CHARACTER ICON" << "\n";
	}
}

void SummonMenu::initBackground()
{
	this->background.setSize(
		sf::Vector2f(this->window->getSize().x
			, this->window->getSize().y)
	);

	if (!this->background_image.loadFromFile("Data/BackgroundSummon.png")) {
		throw "ERROR PICTURE OF BACKGROUND !";
	}
	this->background.setTexture(&this->background_image);
}

SummonMenu::SummonMenu(sf::RenderWindow * window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	:State(window, supportedKeys, states)
{
	this->initVariables();
	this->initFonts();
	this->initButton();
	this->initBackground();
	this->initKeybinds();
}

SummonMenu::~SummonMenu()
{
}

void SummonMenu::endState()
{
}

void SummonMenu::updateInput(const float & dt)
{
	this->CheckQuit();

}

void SummonMenu::updateButton()
{
	//update all the buttons
	for (auto it : this->Button) {
		it.second->update(this->mousePosView);
	}
	srand(time(NULL));
	int i = rand() % 2;
	if (this->Button["SUMMON_STATE"]->isPressed()) {
		this->states->push(new Summon(this->window, this->supportedKeys, this->states,i));

	}
}

void SummonMenu::renderButton(sf::RenderTarget * target)
{
	for (auto it : this->Button) {
		it.second->render(target);
	}
}

void SummonMenu::update(const float & dt)
{
	this->updateInput(dt);
	this->updateButton();
	this->updateMousePosition();
}

void SummonMenu::render(sf::RenderTarget * target)
{
	if (!target) {
		target = this->window;
	}
	target->draw(this->background);
	this->renderButton(target);

}
