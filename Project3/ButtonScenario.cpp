#include "ButtonScenario.h"

ButtonScenario::ButtonScenario(float x, float y,
	sf::Font* font, std::string text
	, sf::RectangleShape shape, sf::Texture texture)
{
	this->buttonState = IDLE_M;
	this->icon = shape;
	this->iconTexture = iconTexture;
	this->icon.setPosition(sf::Vector2f(x, y));
	//this->icon.setSize(sf::Vector2f(width, height));
	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	//this->text.setFillColor(sf::Color::Black);
	//this->text.setCharacterSize(18);

	if (this->icon.getPosition().x < 600) {
		this->text.setPosition(
			//(this->icon.getPosition().x + (this->icon.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f + 250)
			this->icon.getPosition().x + this->icon.getSize().x + 600
			,
			this->icon.getPosition().y + this->icon.getSize().y + 300
			//(this->icon.getPosition().y + (this->icon.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f + 70)
		);
	}
	else {
		this->text.setPosition(
			//(this->icon.getPosition().x + (this->icon.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f + 250)
			this->icon.getPosition().x + this->icon.getSize().x - 300
			,
			this->icon.getPosition().y + this->icon.getSize().y + 300
			//(this->icon.getPosition().y + (this->icon.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f + 70)
		);
	}




}

ButtonScenario::~ButtonScenario()
{
}

const bool ButtonScenario::isPressed() const
{
	if (this->buttonState == ACTIVE_M) {
		return true;
	}
	else {
		return false;
	}
}

void ButtonScenario::update(const sf::Vector2f mousePos)
{
	this->buttonState = IDLE_M;

	//met à jour le booléen pour le HOVER_M et l'appuie*
	//HOVER_M
	if (this->icon.getGlobalBounds().contains(mousePos)) {
		this->buttonState = HOVER_M;
		//Pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			this->buttonState = ACTIVE_M;
		}
	}
	switch (this->buttonState)
	{
	case IDLE_M:
		this->icon.setSize(sf::Vector2f(600, 600));
		this->text.setCharacterSize(26);
		this->text.setFillColor(sf::Color(0, 0, 0, 255));

		std::cout << "BTN IS IDLE_M" << "\n";
		break;
	case HOVER_M:
		this->icon.setSize(sf::Vector2f(620, 620));
		this->text.setCharacterSize(30);
		this->text.setFillColor(sf::Color(0, 0, 0, 255));

		std::cout << "BTN IS HOVER_M" << "\n";
		break;
	case ACTIVE_M:
		this->icon.setSize(sf::Vector2f(600, 600));
		this->text.setCharacterSize(28);
		this->text.setFillColor(sf::Color(0, 0, 0, 255));
		std::cout << "BTN IS ACTIVE_M" << "\n";

		break;
	default:
		this->icon.setSize(sf::Vector2f(600, 600));
		this->text.setFillColor(sf::Color(0, 0, 0, 0));
		std::cout << "BTN IS BY DEFAULT" << "\n";
		break;
	}
}

void ButtonScenario::render(sf::RenderTarget * target)
{
	target->draw(this->icon);
	target->draw(this->text);
}
