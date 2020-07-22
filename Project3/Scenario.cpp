#include "Scenario.hpp"


void Scenario::initVariables()
{

}

void Scenario::initFonts()
{
	if (!this->font.loadFromFile("Fonts/NaughtyMonster.ttf")) {
		throw("THERE'S A PROBLEM WITH THE FONTS !");
	}
}

void Scenario::initButton()
{
	if (this->iconTexture.loadFromFile("Data/class.png")) {
		this->icon.setTexture(&this->iconTexture);
		this->buttons["SCHOOL_SCENARIO"] = new ButtonScenario(50,
			100
			, &this->font, "SCHOOL SCENARIO"
			,
			this->icon, this->iconTexture);
	}
	else {
		std::cout << "THERE'S A PROBLEM WITH SCHOOLSCENARIO'S ICON" << "\n";
	}

	if (this->iconTexture2.loadFromFile("Data/Tomura.png")) {
		this->icon2.setTexture(&this->iconTexture2);
		this->buttons["ADVENTURE_SCENARIO"] = new ButtonScenario(this->window->getSize().x - this->icon2.getSize().x -700 
			, 400
			, &this->font, "ADVENTURE SCENARIO"
			,
			this->icon2, this->iconTexture2);

	}
	else {
		std::cout << "THERE'S A PROBLEM WITH VILLAIN'S ICON" << "\n";
	}

	if (this->iconReturnTexture.loadFromFile("Data/return.png")) {
		this->iconReturn.setTexture(&this->iconReturnTexture);
		this->iconReturn.setSize(sf::Vector2f(10, 10));
		std::cout << "THE RETURN ICON IS OK ! " << "\n";
		this->button["RETURN_TO_MENU"] = new ButtonReturn(
			2
			,
			2
			,
			&this->font, ""
			,
			this->iconReturn, this->iconReturnTexture);
	}
	else {
		std::cout << "THERE'S A PROBLEM WITH THE CHARACTER ICON" << "\n";
	}
}

void Scenario::initBackground()
{
	this->background.setSize(
		sf::Vector2f(this->window->getSize().x
			, this->window->getSize().y)
	);

	if (!this->background_image.loadFromFile("Data/BackgroundChoose.png")) {
		throw "ERROR PICTURE OF BACKGROUND !";
	}
	this->background.setTexture(&this->background_image);
}

void Scenario::initKeybinds()
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



Scenario::Scenario(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	:State(window, supportedKeys, states)
{
	this->initVariables();
	this->initFonts();
	this->initButton();
	this->initBackground();
	this->initKeybinds();


}

Scenario::~Scenario()
{
	//delete this->gameState_btn;
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it) {
		it->second;
	}
}


void Scenario::updateInput(const float & dt)
{
	this->CheckQuit();
	//sf::Keyboard::Key::F6
	//Update player Input
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {

	}*/

}

void Scenario::updateButton()
{
	//update all the buttons
	for (auto it : this->buttons) {
		it.second->update(this->mousePosView);
	}

	for (auto it : this->button) {
		it.second->update(this->mousePosView);
	}

	//if (this->buttons["SCHOOL_SCENARIO"]->isPressed()) {
	//	this->states->push(new Fight(this->window, this->supportedKeys, this->states,0));

	//}

	//	//Return
	if (this->button["RETURN_TO_MENU"]->isPressed()) {
		this->states->push(new Accueil(this->window, this->supportedKeys, this->states));

	}

}

void Scenario::renderButton(sf::RenderTarget * target)
{
	//this->gameState_btn->render(target);
	for (auto it : this->buttons) {
		it.second->render(target);
	}

	for (auto it : this->button) {
		it.second->render(target);
	}
}



void Scenario::endState()
{
	std::cout << "End Game State !" << "\n";
}

void Scenario::update(const float& dt)
{
	//this->sound.play();
	this->updateInput(dt);
	this->updateButton();
	this->updateMousePosition();
	/*system("cls");
	std::cout << this->mousePosView.x <<","<<this->mousePosView.y << "\n";*/

}

void Scenario::render(sf::RenderTarget* target)
{

	if (!target) {
		target = this->window;
	}
	target->draw(this->background);
	this->renderButton(target);

}
