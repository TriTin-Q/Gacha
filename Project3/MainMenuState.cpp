#include "MainMenuState.hpp"


void MainMenuState::initVariables()
{

}

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/NaughtyMonster.ttf")) {
		throw("THERE'S A PROBLEM WITH THE FONTS !");
	}
}

void MainMenuState::initKeybinds()
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

void MainMenuState::initButton()
{
	this->buttons["GAME_STATE"] = new Button(this->window->getSize().x /2.35,
		this->window->getSize().y /1.4, 200, 75
		, &this->font, "Start to be a Hero !",
		sf::Color(242, 171, 56, 200), sf::Color(250, 217, 55, 255),
		sf::Color(255, 255, 255, 200));

	this->buttons["EXIT_STATE"] = new Button(this->window->getSize().x / 2.25 
		, this->window->getSize().y/1.2, 150, 50
		, &this->font, "Quit the game",
		sf::Color(247, 5, 33, 200), sf::Color(247, 5, 33, 255),
		sf::Color(247, 5, 33, 200));
}

void MainMenuState::initBackground()
{
	this->background.setSize(
		sf::Vector2f(this->window->getSize().x
		, this->window->getSize().y)
	);

	if (!this->background_image.loadFromFile("Data/Wallpaper.png")) {
		throw "ERROR PICTURE OF BACKGROUND !";
	}
	this->background.setTexture(&this->background_image);
}

void MainMenuState::initSound()
{

	//if (!this->buffer.loadFromFile("Data/sound/menu.wav"))
	//	throw("ERROR, SOUND");
	//// on charge quelque chose dans le buffer...
	//this->buffer.loadFromFile("Data/sound/menu.wav");
	//this->sound.setBuffer(buffer);
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	:State(window, supportedKeys,states)
{
	this->initSound();
	this->initVariables();
	this->initFonts();
	this->initKeybinds();
	this->initButton();
	this->initBackground();

	//this->background_image;

	//this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	//this->background.setFillColor(sf::Color::Black);
	
}

MainMenuState::~MainMenuState()
{
	//delete this->gameState_btn;
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it) {
		it->second;
	}
}


void MainMenuState::updateInput(const float & dt)
{
	this->CheckQuit();
	//sf::Keyboard::Key::F6
	//Update player Input
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {

	}*/

}

void MainMenuState::updateButton()
{
	//update all the buttons
	for(auto it : this->buttons) {
		it.second->update(this->mousePosView);
	}

	//Start Game 
	if (this->buttons["GAME_STATE"]->isPressed()) {
		this->states->push(new Accueil(this->window, this->supportedKeys, this->states));
	}
	 
	//A FAIRE
	//if (this->buttons["EXIT_STATE"]->isPressed()) {
	//	this->states->push(new Accueil(this->window, this->supportedKeys, this->states));

	//}

	

}

void MainMenuState::renderButton(sf::RenderTarget * target)
{
	//this->gameState_btn->render(target);
	for (auto it : this->buttons) {
		it.second->render(target);
	}
}



void MainMenuState::endState()
{
	std::cout << "End Game State !" << "\n";
}

void MainMenuState::update(const float& dt)
{
	//this->sound.play();
	this->updateMousePosition();
	this->updateInput(dt);
	/*system("cls");
	std::cout << this->mousePosView.x <<","<<this->mousePosView.y << "\n";*/
	this->updateButton();

}

void MainMenuState::render(sf::RenderTarget* target)
{

	if (!target) {
		target = this->window;
	}
	target->draw(this->background);
	this->renderButton(target);

}
