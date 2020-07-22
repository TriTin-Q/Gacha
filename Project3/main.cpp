#include "Game.hpp"
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
#include "Personnage.hpp"
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

int main() {

	Game game;

	game.run();


	//SON MUSIQUE 

	//sf::RenderWindow window(sf::VideoMode(1000, 700), "SFML sound !");
	//
	//sf::SoundBuffer buffer;
	//if (!buffer.loadFromFile("Data/sound/menu.wav"))
	//	return -1;
	//// on charge quelque chose dans le buffer...
	//buffer.loadFromFile("Data/sound/menu.wav");
	//sf::Sound sound;
	//sound.setBuffer(buffer);
	//sound.play();


	//while (window.isOpen()) {
	//	sf::Event event;
	//	while (window.pollEvent(event)) {
	//		switch (event.type) {
	//		case sf::Event::Closed:
	//				window.close();

	//				break;
	//		}
	//	}
	//	window.clear();

	//	window.display();
	//}


	// PARTIE ANIMATION COMBAT
	//sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works!");
	//sf::Texture texture;

	//sf::RectangleShape background;
	//sf::Texture  background_image;


	//background.setSize(
	//	sf::Vector2f(window.getSize().x
	//		,window.getSize().y)
	//);

	//if (!background_image.loadFromFile("Data/Background_fight.jpg")) {
	//	throw "ERROR PICTURE OF BACKGROUND !";
	//}
	//background.setTexture(&background_image);

	//if (!texture.loadFromFile("Data/Sprites/SpriteAll_Ocacho.png")) {
	//	std::cout << "PROBELM'S WITH THE SPRITE FILE" << "\n";
	//}


	//sf::IntRect rectSourceSprite1(0, 60,57, 60);
	//sf::Sprite sprite1(texture,rectSourceSprite1);
	//sprite1.setScale(sf::Vector2f(3, 3));
	////sprite1.setPosition(0, window.getPosition().y);

	//sf::IntRect rectSourceSprite2(23, 120, 38, 60);
	//sf::Sprite sprite2(texture, rectSourceSprite2);
	//sprite2.setScale(sf::Vector2f(3, 3));

	//sf::IntRect rectSourceSprite3(30, 181, 37, 60);
	//sf::Sprite sprite3(texture, rectSourceSprite3);
	//sprite3.setScale(sf::Vector2f(3, 3));

	//sf::IntRect rectSourceSprite4(210, 240, 80, 80);
	//sf::Sprite sprite4(texture, rectSourceSprite4);
	//sprite4.setScale(sf::Vector2f(1.5, 1.5));
	////sprite4.setPosition(300, 300);


	//bool AuCentre = false;
	//bool course = true;
	//bool surPlace = false;
	//bool attaque = false;
	//bool attaquePossible = false;
	//bool attaque_plus = false;
	//float rotation = 0;

	//int tmpPossible = 0;
	//int avance = 20;
	//sf::Clock clock;

	//while (window.isOpen())
	//{
	//	sf::Event event;
	//	while (window.pollEvent(event))
	//	{
	//		if (event.type == sf::Event::Closed)
	//			window.close();
	//	}

	//	if (clock.getElapsedTime().asSeconds() > 0.2f) {
	//		//Course
	//		if (rectSourceSprite1.left == 399) {
	//			rectSourceSprite1.left = 0;
	//		}
	//		//surplace
	//		if (rectSourceSprite2.left == 251) {
	//			rectSourceSprite2.left = 23;
	//		}
	//		//Attaque
	//		if (rectSourceSprite3.left == 182) {
	//			rectSourceSprite3.left = 30;
	//		}


	//		if (sprite1.getPosition().x == window.getSize().x / 2 - 200 ) {
	//			course = false;
	//			surPlace = true;
	//			attaque = false;
	//			attaquePossible = true;

	//			sprite1.setPosition(sprite1.getPosition().x + 20, sprite1.getPosition().y);
	//			sprite2.setPosition(sprite1.getPosition().x, sprite1.getPosition().y);

	//			sprite1.setPosition(sprite1.getPosition().x - 20, sprite1.getPosition().y);
	//			sprite2.setPosition(sprite1.getPosition().x, sprite1.getPosition().y);
	//		}
	//		rectSourceSprite1.left += 57;
	//		sprite1.setTextureRect(rectSourceSprite1);
	//		if (course == true) {
	//			sprite1.setPosition(sprite1.getPosition().x + 10, window.getPosition().y + 100);

	//		}
	//		if ( attaquePossible == true) {
	//			tmpPossible++;
	//			std::cout << "TMP Posible : " << tmpPossible << "\n";
	//			if (tmpPossible <= 10) {
	//				surPlace = false;
	//				attaque = true;
	//				attaque_plus = true;
	//				sprite3.setPosition(sprite1.getPosition().x, sprite1.getPosition().y);

	//				if (attaque_plus == true) {
	//					for (int i = 0; i < 5; i++) {
	//						sprite4.setPosition(sprite4.getPosition().x + 10, sprite4.getPosition().y);

	//					}
	//					//if (sprite4.getPosition().x >= window.getPosition().x) {
	//					//	attaque_plus = false;
	//					//}
	//				}
	//			}
	//			if (tmpPossible >= 10) {
	//				surPlace = true;;
	//				//attaquePossible = false; 
	//				attaque_plus = false;
	//				if (tmpPossible >= 20) {
	//					tmpPossible = 0;
	//				}
	//			}
	//				

	//		}
	//		sprite4.setPosition(sprite3.getPosition().x + (rectSourceSprite3.height / 2.0f) + 100 + avance, sprite3.getPosition().y + (rectSourceSprite3.width / 2.0f) + 50);
	//		sprite4.setOrigin(rectSourceSprite4.width / 2.f, rectSourceSprite4.height / 2.f);
	//		sprite4.setRotation(rotation += 5.0f);

	//		rectSourceSprite3.left += 38;
	//		sprite3.setTextureRect(rectSourceSprite3);

	//		rectSourceSprite2.left += 38;
	//		sprite2.setTextureRect(rectSourceSprite2);

	//		clock.restart();
	//		
	//	}
	//	

	//	window.clear();
	//	window.draw(background);
	//	if (course == true) {
	//		window.draw(sprite1);

	//	}
	//	if (surPlace == true) {
	//		window.draw(sprite2);
	//	}
	//	if (attaque == true) {
	//		window.draw(sprite3);
	//		window.draw(sprite4);

	//	}
	//	//if (attaque_plus == true) {
	//	//	window.draw(sprite4);
	//	// }



	//	window.display();
	//}
	

	// PARTIE ANIMATION INVOCATION
	//sf::RenderWindow window(sf::VideoMode(1600, 1000), "SFML works!");
	//sf::Texture texture;
	//sf::RectangleShape icon;
	//sf::Texture texture2;
	//sf::Texture texture3;

	//sf::RectangleShape background;
	//sf::RectangleShape background2;
	//sf::Texture background_image2;
	//sf::Texture background_image;
	//
	//
	//


	//background.setSize(
	//	sf::Vector2f(window.getSize().x
	//		,window.getSize().y)
	//);

	//if (!background_image.loadFromFile("Data/Background.jpg")) {
	//	throw "ERROR PICTURE OF BACKGROUND !";
	//}
	//background.setTexture(&background_image);

	//if (!texture.loadFromFile("Data/thunderSprite.png")) {
	//	std::cout << "PROBELM'S WITH THE SPRITE FILE" << "\n";
	//}

	//if (!texture3.loadFromFile("Data/smokeSprite.png")) {
	//	std::cout << "PROBELM'S WITH THE SPRITE FILE" << "\n";
	//}

	//sf::IntRect rectSourceSprite1(0, 0,192, 192);
	//sf::Sprite sprite1(texture,rectSourceSprite1);
	//sprite1.setScale(sf::Vector2f(2,2));
	//srand(time(NULL));
	//int n = rand() % 5;
	////int n = 5;
	//bool smoke = false;

	////sf::IntRect rectSourceSprite1(0, 0, 192, 192);
	//sf::Sprite sprite2(texture, rectSourceSprite1);
	//sprite2.setScale(sf::Vector2f(2, 2));
	//sprite2.setPosition(sf::Vector2f(window.getSize().x - 400, 400));

	//sf::IntRect rectSourceSprite3(0, 0, 125, 125);
	//sf::Sprite sprite3(texture3, rectSourceSprite3);
	//sprite3.setScale(sf::Vector2f(7, 6));
	//sprite3.setPosition(window.getSize().x / 2 - 400
	//	, window.getSize().y / 2 - 300);

	//sf::Clock clock;
	//
	//int tmp = 0;

	//while (window.isOpen())
	//{
	//	sf::Event event;
	//	while (window.pollEvent(event))
	//	{
	//		if (event.type == sf::Event::Closed)
	//			window.close();
	//	}

	//	if (clock.getElapsedTime().asSeconds() > 0.1f) {
	//		//Course
	//		if (rectSourceSprite1.left == 960) {
	//			rectSourceSprite1.left = 0;
	//			rectSourceSprite1.top += 192;
	//			if (rectSourceSprite1.top == 960) {
	//				rectSourceSprite1.top = 0;
	//				if (tmp == 0) tmp = 1;
	//				else tmp = 2; smoke = true;
	//			}
	//		}
	//		if (rectSourceSprite3.left == 875) {
	//			rectSourceSprite3.left = 0;
	//			rectSourceSprite3.top += 125;
	//			if (rectSourceSprite3.top == 875) {
	//				smoke = false;
	//				rectSourceSprite3.top = 0;
	//			}
	//		}

	//		rectSourceSprite1.left += 192;
	//		sprite1.setTextureRect(rectSourceSprite1);
	//		sprite2.setTextureRect(rectSourceSprite1);
	//		sprite2.setOrigin(rectSourceSprite1.width / 2.f, rectSourceSprite1.height / 2.f);
	//		sprite2.setRotation(60);
	//		rectSourceSprite3.left += 125;
	//		sprite3.setTextureRect(rectSourceSprite3);
	//		clock.restart();
	//		
	//		
	//	}
	//	

	//	window.clear();
	//	window.draw(background);
	//	if (tmp == 0) {
	//		window.draw(sprite1);
	//	}
	//	if (tmp == 1) {
	//		window.draw(sprite2);
	//	}
	//	if (tmp == 2) {
	//		if (n == 0) {
	//			if (!texture2.loadFromFile("Data/Deku3D.png")) {
	//				std::cout << "PROBELM'S WITH THE SPRITE FILE" << "\n";
	//			}
	//			icon.setTexture(&texture2);
	//			icon.setSize(sf::Vector2f(400, 650));
	//			icon.setPosition((window.getSize().x / 2) - (icon.getSize().x/2)
	//				, (window.getSize().y / 2 - (icon.getSize().y / 2)));
	//		}
	//		if (n == 1) {
	//			if (!texture2.loadFromFile("Data/Bakugo3D.png")) {
	//				std::cout << "PROBELM'S WITH THE SPRITE FILE" << "\n";
	//			}
	//			icon.setTexture(&texture2);
	//			icon.setSize(sf::Vector2f(350, 650));
	//			icon.setPosition((window.getSize().x / 2) - (icon.getSize().x/2)
	//				, (window.getSize().y / 2 - (icon.getSize().y / 2)));
	//		}
	//		if (n == 2) {
	//			if (!texture2.loadFromFile("Data/Ochaco3D.png")) {
	//				std::cout << "PROBELM'S WITH THE SPRITE FILE" << "\n";
	//			}
	//			icon.setTexture(&texture2);
	//			icon.setSize(sf::Vector2f(450, 600));
	//			icon.setPosition((window.getSize().x / 2) - (icon.getSize().x / 2)
	//				, (window.getSize().y / 2 - (icon.getSize().y / 2)));
	//		}
	//		if (n == 3) {
	//			if (!texture2.loadFromFile("Data/Tenya3D.png")) {
	//				std::cout << "PROBELM'S WITH THE SPRITE FILE" << "\n";
	//			}
	//			icon.setTexture(&texture2);
	//			icon.setSize(sf::Vector2f(600, 600));
	//			icon.setPosition((window.getSize().x / 2) - (icon.getSize().x / 2)
	//				, (window.getSize().y / 2 - (icon.getSize().y / 2)));
	//		}
	//		if (n == 4) {
	//			if (!texture2.loadFromFile("Data/Shoto3D.png")) {
	//				std::cout << "PROBELM'S WITH THE SPRITE FILE" << "\n";
	//			}
	//			icon.setTexture(&texture2);
	//			icon.setSize(sf::Vector2f(650, 600));
	//			icon.setPosition((window.getSize().x / 2) - (icon.getSize().x / 2)
	//				, (window.getSize().y / 2 - (icon.getSize().y / 2)));
	//		}
	//		if (n == 5) {
	//			if (!texture2.loadFromFile("Data/Tsuyu3D.png")) {
	//				std::cout << "PROBELM'S WITH THE SPRITE FILE" << "\n";
	//			}
	//			icon.setTexture(&texture2);
	//			icon.setSize(sf::Vector2f(650, 600));
	//			icon.setPosition((window.getSize().x / 2) - (icon.getSize().x / 2)
	//				, (window.getSize().y / 2 - (icon.getSize().y / 2)));
	//		}
	//		window.draw(icon);
	//		if (smoke == true) {
	//			window.draw(sprite3);
	//		}
	//	}

	//	window.display();
	//}

	return 0;
 } 