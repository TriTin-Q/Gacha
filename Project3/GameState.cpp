#include "GameState.hpp"

void GameState::initKeybinds()
{
	std::ifstream ifs("Config/gamestate_keybinds.ini");


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

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	:State(window, supportedKeys,states)
{
	this->initKeybinds();
}

GameState::~GameState()
{
}


void GameState::updateInput(const float & dt)
{
	this->CheckQuit();
	//sf::Keyboard::Key::F6
	//Update player Input
	//Déplacement à gauche
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT")))){
		this->player.move(dt, -1.f, 0.f);
	}
	//Déplacement à Droite
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT")))) {
		this->player.move(dt, 1.f, 0.f);
	}
	//Déplacement à Haut
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP")))) {
		this->player.move(dt, 0.f, -1.f);
	}
	//Déplacement à Bas
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN")))) {
		this->player.move(dt, 0.f, 1.f);
	}
}

void GameState::endState()
{
	std::cout << "End Game State !" << "\n";
}

void GameState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);
	this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target) {
		target = this->window;
	}
	this->player.render(target);
}
