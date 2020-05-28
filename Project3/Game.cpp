#include "Game.hpp"

void Game::initViarables()
{
	this->window = NULL;
	this->dt = 0.f;
	this->fullscreen = false;
}

void Game::initWindow() {

	std::ifstream ifs("Config/window.ini");
	this->videoMode = sf::VideoMode::getFullscreenModes();
	bool fullscreen = false;
	std::string titre = "None";
	sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
	unsigned framrate_limit = 120;
	bool vertical_sync_enabled = false;
	unsigned antialiasing_level = 0;

	if (ifs.is_open()) {
		std::getline(ifs, titre);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> fullscreen;
		ifs >> framrate_limit;
		ifs >> vertical_sync_enabled;
		ifs >> antialiasing_level;
	}

	ifs.close();

	this->fullscreen = fullscreen;
	sf::ContextSettings window_settings;
	this->windowSettings.antialiasingLevel = antialiasing_level;
	if (fullscreen)
		this->window = new sf::RenderWindow(window_bounds, titre,sf::Style::Fullscreen,window_settings);
	else {
		this->window = new sf::RenderWindow(window_bounds, titre,
			sf::Style::Titlebar |
			sf::Style::Close, window_settings);
	}
	this->window->setFramerateLimit(framrate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);

}

void Game::initKeys()
{
	std::ifstream ifs("Config/supported_key.ini");


	if (ifs.is_open()) 
	{
	
		std::string key = "";
		int key_value = 0;
		
		while (ifs >> key >> key_value) {
		
			this->supportedKeys[key] = key_value;

		}
	}

	ifs.close();



	//Debug test : affiche la correspondance avec toute les touches
	/*for (auto i : this->supportedKeys) {
		std::cout << i.first << " " << i.second << "\n";
	}*/



}

void Game::initStates()
{
	this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states));
	//this->states.push(new GameState(this->window, &this->supportedKeys));
}



Game::Game(){
	initWindow();
	initKeys();
	initStates();

}

Game::~Game(){
	delete this->window;

	while (!this->states.empty()) {
		delete this->states.top();
		this -> states.pop();

	}
}

void Game::endApplication()
{
	std::cout << "Ending Application" << "\n";
}

void Game::updateDt()
{
	//Fonction permettant de voir le temps que prend la mise à jour et le render par frame
	this->dt = this->dtClock.restart().asSeconds();

	//system("cls");
	//std::cout << dt << "\n";
}

void Game::updateSFMLEvents()
{
	while (window->pollEvent(sfEvent))
	{
		if (sfEvent.type == sf::Event::Closed)
			window->close();
	}


}

void Game::update()
{
	this ->updateSFMLEvents();
	if (!this->states.empty()) {
		this->states.top()->update(this->dt);

		if (this->states.top()->getQuit()) {
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}

	}
	else {
		this->endApplication();
		this->window->close();
	}
}

void Game::render()
{
	window->clear();
	//window->draw(shape);
	if (!this->states.empty()) {
		this->states.top()->render();

	}
	window->display();
}

void Game::run()
{
	while (window->isOpen())
	{
		updateDt();
		update();
		render();

	}
}
