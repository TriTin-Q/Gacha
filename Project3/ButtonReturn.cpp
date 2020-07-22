#include "ButtonReturn.h"
ButtonReturn::ButtonReturn(float x, float y,
	sf::Font* font, std::string text
	, sf::RectangleShape shape, sf::Texture texture)
{
	this->buttonState = IDLE_BTN;
	this->icon = shape;
	this->iconTexture = iconTexture;
	this->icon.setPosition(sf::Vector2f(x, y));
	//this->icon.setSize(sf::Vector2f(width, height));
	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	//this->text.setFillColor(sf::Color::Black);
	//this->text.setCharacterSize(18);
	this->text.setPosition(
		(this->icon.getPosition().x + (this->icon.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f + 250)
		,
		(this->icon.getPosition().y + (this->icon.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f + 70)
	);
}

ButtonReturn::~ButtonReturn()
{
}

const bool ButtonReturn::isPressed() const
{
 	if (this->buttonState == ACTIVE_BTN) {
		return true;
	}
	else {
		return false;
	}
}

void ButtonReturn::update(const sf::Vector2f mousePos)
{
	this->buttonState = IDLE_BTN;

	//met à jour le booléen pour le hover et l'appuie*
	//HOVER
	if (this->icon.getGlobalBounds().contains(mousePos)) {
		this->buttonState = HOVER_BTN;
		//Pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			this->buttonState = ACTIVE_BTN;
		}
	}
	switch (this->buttonState)
	{
	case IDLE_BTN:
		this->icon.setSize(sf::Vector2f(40,40));
		this->text.setCharacterSize(16);
		this->text.setFillColor(sf::Color(0, 0, 0, 255));

		std::cout << "BTN IS IDLE" << "\n";
		break;
	case HOVER_BTN:
		this->icon.setSize(sf::Vector2f(45, 45));
		this->text.setCharacterSize(18);
		this->text.setFillColor(sf::Color(0, 0, 0, 255));

		std::cout << "BTN IS HOVER" << "\n";
		break;
	case ACTIVE_BTN:
		this->icon.setSize(sf::Vector2f(40, 40));
		this->text.setCharacterSize(16);
		this->text.setFillColor(sf::Color(0, 0, 0, 255));
		std::cout << "BTN IS ACTIVE" << "\n";

		break;
	default:
		this->icon.setSize(sf::Vector2f(40,40));
		this->text.setFillColor(sf::Color(0, 0, 0, 0));
		std::cout << "BTN IS BY DEFAULT" << "\n";
		break;
	}
}

void ButtonReturn::render(sf::RenderTarget * target)
{
	target->draw(this->icon);
	target->draw(this->text);
}
