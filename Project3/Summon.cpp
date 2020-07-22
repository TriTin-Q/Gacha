#include "Summon.hpp"

void Summon::initVariables()
{
}

void Summon::initFonts()
{
	if (!this->font.loadFromFile("Fonts/NaughtyMonster.ttf")) {
		throw("THERE'S A PROBLEM WITH THE FONTS !");
	}
}

void Summon::initKeybinds()
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

void Summon::initButton()
{
}

void Summon::initBackground()
{
	this->background.setSize(
		sf::Vector2f(this->window->getSize().x
			, this->window->getSize().y)
	);

	if (!this->background_image.loadFromFile("Data/Background.jpg")) {
		throw "ERROR PICTURE OF BACKGROUND !";
	}
	this->background.setTexture(&this->background_image);
}

void Summon::initCharacter(int n)
{


		if (n == 0) {
			if (!this->texture2.loadFromFile("Data/Deku3D.png")) {
				std::cout << "PROBELM'S WITH THE SPRITE FILE" << "\n";
			}
			this->icon.setTexture(&this->texture2);
			this->icon.setSize(sf::Vector2f(400, 650));
			this->icon.setPosition((this->window->getSize().x / 2) - (this->icon.getSize().x/2)
				, (this->window->getSize().y / 2 - (this->icon.getSize().y / 2)));
		}
		if (n == 1) {
			if (!this->texture2.loadFromFile("Data/Bakugo3D.png")) {
				std::cout << "PROBELM'S WITH THE SPRITE FILE" << "\n";
			}
			this->icon.setTexture(&this->texture2);
			this->icon.setSize(sf::Vector2f(350, 650));
			this->icon.setPosition((this->window->getSize().x / 2) - (this->icon.getSize().x/2)
				, (this->window->getSize().y / 2 - (this->icon.getSize().y / 2)));
		}
		if (n == 2) {
			if (!this->texture2.loadFromFile("Data/Ochaco3D.png")) {
				std::cout << "PROBELM'S WITH THE SPRITE FILE" << "\n";
			}
			this->icon.setTexture(&texture2);
			this->icon.setSize(sf::Vector2f(450, 600));
			this->icon.setPosition((this->window->getSize().x / 2) - (this->icon.getSize().x / 2)
				, (this->window->getSize().y / 2 - (this->icon.getSize().y / 2)));
		}
		if (n == 3) {
			if (!texture2.loadFromFile("Data/Tenya3D.png")) {
				std::cout << "PROBELM'S WITH THE SPRITE FILE" << "\n";
			}
			this->icon.setTexture(&texture2);
			this->icon.setSize(sf::Vector2f(600, 600));
			this->icon.setPosition((this->window->getSize().x / 2) - (this->icon.getSize().x / 2)
				, (this->window->getSize().y / 2 - (this->icon.getSize().y / 2)));
		}
		if (n == 4) {
			if (!texture2.loadFromFile("Data/Shoto3D.png")) {
				std::cout << "PROBELM'S WITH THE SPRITE FILE" << "\n";
			}
			this->icon.setTexture(&texture2);
			this->icon.setSize(sf::Vector2f(650, 600));
			this->icon.setPosition((this->window->getSize().x / 2) - (this->icon.getSize().x / 2)
				, (this->window->getSize().y / 2 - (this->icon.getSize().y / 2)));
		}
		if (n == 5) {
			if (!texture2.loadFromFile("Data/Tsuyu3D.png")) {
				std::cout << "PROBELM'S WITH THE SPRITE FILE" << "\n";
			}
			this->icon.setTexture(&texture2);
			this->icon.setSize(sf::Vector2f(650, 600));
			this->icon.setPosition((this->window->getSize().x / 2) - (this->icon.getSize().x / 2)
				, (this->window->getSize().y / 2 - (this->icon.getSize().y / 2)));
		}
}

Summon::Summon(sf::RenderWindow * window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, int indice)
	:State(window, supportedKeys, states)
{
	this->initVariables();
	this->initFonts();
	this->initButton();
	this->initBackground();
	this->initKeybinds();
	this->initCharacter(indice);
}

Summon::~Summon()
{
}

void Summon::endState()
{
}

void Summon::updateInput(const float & dt)
{
	this->CheckQuit();

}

void Summon::updateButton()
{
}

void Summon::updateCharcter()
{
	if (!texture.loadFromFile("Data/thunderSprite.png")) {
		std::cout << "PROBELM'S WITH THE SPRITE FILE" << "\n";
	}

	if (!texture3.loadFromFile("Data/smokeSprite.png")) {
		std::cout << "PROBELM'S WITH THE SPRITE FILE" << "\n";
	}
	this->rectSourceSprite1 = { 0, 0, 192, 192 };
	this->sprite1 = { this->texture, this->rectSourceSprite1 };
	sprite1.setScale(sf::Vector2f(2, 2));
	this->smoke = false;

	//sf::IntRect rectSourceSprite1(0, 0, 192, 192);
	this->sprite2 = { this->texture, this->rectSourceSprite1 };
	this->sprite2.setScale(sf::Vector2f(2, 2));
	this->sprite2.setPosition(sf::Vector2f(this->window->getSize().x - 400, 400));

	this->rectSourceSprite3 = { 0, 0, 125, 125 };
	this->sprite3 = { this->texture3, this->rectSourceSprite3 };
	this->sprite3.setScale(sf::Vector2f(7, 6));
	this->sprite3.setPosition(this->window->getSize().x / 2 - 400
		, this->window->getSize().y / 2 - 300);

		if (this->clock.getElapsedTime().asSeconds() > 0.1f) {
			//Course
			if (this->rectSourceSprite1.left == 960) {
				this->rectSourceSprite1.left = 0;
				this->rectSourceSprite1.top += 192;
				if (this->rectSourceSprite1.top == 960) {
					this->rectSourceSprite1.top = 0;
					if (this->tmp == 0) this->tmp = 1;
					else this->tmp = 2; this->smoke = true;
				}
			}
			if (this->rectSourceSprite3.left == 875) {
				this->rectSourceSprite3.left = 0;
				this->rectSourceSprite3.top += 125;
				if (this->rectSourceSprite3.top == 875) {
					this->smoke = false;
					this->rectSourceSprite3.top = 0;
				}
			}

			this->rectSourceSprite1.left += 192;
			this->sprite1.setTextureRect(rectSourceSprite1);
			this->sprite2.setTextureRect(rectSourceSprite1);
			this->sprite2.setOrigin(this->rectSourceSprite1.width / 2.f, this->rectSourceSprite1.height / 2.f);
			this->sprite2.setRotation(60);
			this->rectSourceSprite3.left += 125;
			this->sprite3.setTextureRect(rectSourceSprite3);
			clock.restart();
		}

	
		
}

void Summon::renderButton(sf::RenderTarget * target)
{
}

void Summon::update(const float & dt)
{
	this->updateInput(dt);
	this->updateButton();
	this->updateMousePosition();
	this->updateCharcter();
}

void Summon::render(sf::RenderTarget * target)
{

	if (!target) {
		target = this->window;
	}
	target->draw(this->background);

	while (this->window->isOpen()) {

		if (this->tmp == 0) {
			this->window->draw(this->sprite1);
		}
		if (this->tmp == 1) {
			this->window->draw(this->sprite2);
		}
		if (this->smoke == true) {
			this->window->draw(this->sprite3);
		}
	}

}
