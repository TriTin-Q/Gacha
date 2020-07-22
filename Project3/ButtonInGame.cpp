#include "ButtonInGame.hpp"


ButtonInGame::ButtonInGame(float x, float y, 
	sf::Font* font, std::string text
	, sf::RectangleShape shape, sf::Texture texture)
{
	this->buttonState = BTN_IDLE;
	this->icon = shape;
	this->iconTexture = iconTexture;
	this->icon.setPosition(sf::Vector2f(x, y));
	//this->icon.setSize(sf::Vector2f(width, height))
	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	//this->text.setFillColor(sf::Color::Black);
	this->text.setCharacterSize(22);
	this->text.setPosition(
		//(this->icon.getPosition().x + (this->icon.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f + 60)
		this->icon.getPosition().x + this->icon.getSize().x + 30
		,
		this->icon.getPosition().y - 30
		//(this->icon.getPosition().y + (this->icon.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f -20)
	);



}

ButtonInGame::~ButtonInGame()
{
}


//ACCESSEUR 
const bool ButtonInGame::isPressed() const
{
	if (this->buttonState == BTN_ACTIVE) {
		return true;
	}
	else {
		return false;
	}
}


void ButtonInGame::update(const sf::Vector2f mousePos)
{
	this->buttonState = BTN_IDLE;

	//met à jour le booléen pour le hover et l'appuie*
	//HOVER
	if (this->icon.getGlobalBounds().contains(mousePos)) {
		this->buttonState = BTN_HOVER;
		//Pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			this->buttonState = BTN_ACTIVE;
		}
	}
	switch (this->buttonState)
	{
	case BTN_IDLE:
		this->icon.setSize(sf::Vector2f(150,150));
		this->text.setFillColor(sf::Color(0,0,0,0));

		std::cout << "BTN IS IDLE" << "\n";
		break;
	case BTN_HOVER:
		this->icon.setSize(sf::Vector2f(160,160));
		this->text.setFillColor(sf::Color(0, 0, 0, 255));

		std::cout << "BTN IS HOVER" << "\n";
		break;
	case BTN_ACTIVE:
		this->icon.setSize(sf::Vector2f(150, 150));
		this->text.setFillColor(sf::Color(0, 0, 0, 0));
		std::cout << "BTN IS ACTIVE" << "\n";

		break;
	default:
		this->icon.setSize(sf::Vector2f(150, 150));
		this->text.setFillColor(sf::Color(0, 0, 0, 0));
		std::cout << "BTN IS BY DEFAULT" << "\n";
		break;
	}
}

void ButtonInGame::render(sf::RenderTarget * target)
{
	target->draw(this->icon);
	target->draw(this->text);
}

