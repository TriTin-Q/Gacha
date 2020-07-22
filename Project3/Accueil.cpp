#include "Accueil.hpp"


void Accueil::initVariables()
{
}

void Accueil::initFonts()
{
	if (!this->font.loadFromFile("Fonts/NaughtyMonster.ttf")) {
		throw("THERE'S A PROBLEM WITH THE FONTS !");
	}
}

void Accueil::initButton()
{
	if (this->iconTexture.loadFromFile("Data/Personnages.png")) {
		this->icon.setTexture(&this->iconTexture);
		std::cout << "THE CHARACH ICON IS OK ! " << "\n";
		this->buttons["CHARAC_STATE"] = new ButtonInGame(50,
			100 ,&this->font, "Personnages",
			this->icon, this->iconTexture);
	}
	else {
		std::cout << "THERE'S A PROBLEM WITH THE CHARACTER ICON" << "\n";
	}
	if (this->iconTexture2.loadFromFile("Data/Fight.png")) {
		this->icon2.setTexture(&this->iconTexture2);
		std::cout << "THE CHARACH ICON IS OK ! " << "\n";
		this->buttons["FIGHT_STATE"] = new ButtonInGame(50,
			300, &this->font, "Combats",
			this->icon2, this->iconTexture2);
	}
	else {
		std::cout << "THERE'S A PROBLEM WITH THE CHARACTER ICON" << "\n";
	}
	if (this->iconTexture3.loadFromFile("Data/Gacha.png")) {
		this->icon3.setTexture(&this->iconTexture3);
		std::cout << "THE CHARACH ICON IS OK ! " << "\n";
		this->buttons["GACHA_STATE"] = new ButtonInGame(50,
			this->window->getSize().y - 300, &this->font, "Recrute!",
			this->icon3, this->iconTexture3);
	}
	else {
		std::cout << "THERE'S A PROBLEM WITH THE CHARACTER ICON" << "\n";
	}

}

void Accueil::initBackground()
{

	this->background.setSize(
		sf::Vector2f(this->window->getSize().x
			, this->window->getSize().y)
	);
	//this->background.setFillColor(sf::Color::White);

	if (!this->background_image.loadFromFile("Data/Room.jpg")) {
		throw "ERROR PICTURE OF BACKGROUND !";
	}
	this->background.setTexture(&this->background_image);

	this->fond.setPosition(0, 0);
	this->fond.setSize(sf::Vector2f(250, this->window->getSize().y));
	this->fond.setFillColor(sf::Color(255, 255, 255, 150));
	this->fond.setOutlineThickness(3);
	this->fond.setOutlineColor(sf::Color(0, 0, 0, 255));

}

void Accueil::initKeybinds()
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

Accueil::Accueil(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	:State(window, supportedKeys, states)
{
	this->initVariables();
	this->initFonts();
	this->initButton();
	this->initBackground();
	this->initKeybinds();
}

Accueil::~Accueil()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it) {
		it->second;
	}
}


void Accueil::updateInput(const float & dt)
{
	this->CheckQuit();

}

void Accueil::endState()
{
	std::cout << "End Game State !" << "\n";
}

void Accueil::updateButton()
{
	//update all the buttons
	for (auto it : this->buttons) {
		it.second->update(this->mousePosView);
	}

	//Liste des personnages
	if (this->buttons["CHARAC_STATE"]->isPressed()) {
		this->states->push(new Box(this->window, this->supportedKeys, this->states));

	}

	if (this->buttons["FIGHT_STATE"]->isPressed()) {
		this->states->push(new Scenario(this->window, this->supportedKeys, this->states));

	}
	if (this->buttons["GACHA_STATE"]->isPressed()) {
		this->states->push(new SummonMenu(this->window, this->supportedKeys, this->states));

	}
	/*if (this->buttons["CHARAC_STATE"]->isPressed()) {
		this->states->push(new GameState(this->window, this->supportedKeys, this->states));

	}*/
}

void Accueil::renderButton(sf::RenderTarget * target)
{
	//this->gameState_btn->render(target);
	for (auto it : this->buttons) {
		it.second->render(target);
	}
}

void Accueil::update(const float& dt)
{
	this->updateInput(dt);
	this->updateButton();
	this->updateMousePosition();
}

void Accueil::render(sf::RenderTarget* target)
{
	if (!target) {
		target = this->window;
	}
	target->draw(this->background);
	target->draw(this->fond);

	this->renderButton(target);

}
