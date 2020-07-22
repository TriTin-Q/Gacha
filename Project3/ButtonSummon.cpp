#include "ButtonSummon.hpp"

ButtonSummon::ButtonSummon(float x, float y, sf::Font * font, std::string text, sf::RectangleShape shape, sf::Texture texture)
{
	this->buttonState = IDLE_Summon;
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
		//(this->icon.getPosition().x + (this->icon.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f + 250)
		this->icon.getPosition().x + 100
		,
		this->icon.getPosition().y + 40
		//(this->icon.getPosition().y + (this->icon.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f + 70)
	);
}

ButtonSummon::~ButtonSummon()
{
}

const bool ButtonSummon::isPressed() const
{
	if (this->buttonState == ACTIVE_Summon) {
		return true;
	}
	else {
		return false;
	}
}

void ButtonSummon::update(const sf::Vector2f mousePos)
{
	this->buttonState = IDLE_Summon;

	//met à jour le booléen pour le HOVER_Summon et l'appuie*
	//HOVER_Summon
	if (this->icon.getGlobalBounds().contains(mousePos)) {
		this->buttonState = HOVER_Summon;
		//Pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			this->buttonState = ACTIVE_Summon;
		}
	}
	switch (this->buttonState)
	{
	case IDLE_Summon:
		this->icon.setSize(sf::Vector2f(300, 110));
		this->text.setCharacterSize(28);
		this->text.setFillColor(sf::Color(255, 255, 255, 255));

		std::cout << "BTN IS IDLE_Summon" << "\n";
		break;
	case HOVER_Summon:
		this->icon.setSize(sf::Vector2f(305, 115));
		this->text.setCharacterSize(30);
		this->text.setFillColor(sf::Color(255, 255, 255, 255));

		std::cout << "BTN IS HOVER_Summon" << "\n";
		break;
	case ACTIVE_Summon:
		this->icon.setSize(sf::Vector2f(300, 110));
		this->text.setCharacterSize(28);
		this->text.setFillColor(sf::Color(255, 255, 255, 255));
		std::cout << "BTN IS ACTIVE_Summon" << "\n";

		break;
	default:
		this->icon.setSize(sf::Vector2f(300, 110));
		this->text.setFillColor(sf::Color(255, 255, 255, 0));
		std::cout << "BTN IS BY DEFAULT" << "\n";
		break;
	}
}

void ButtonSummon::render(sf::RenderTarget * target)
{
	target->draw(this->icon);
	target->draw(this->text);
}
