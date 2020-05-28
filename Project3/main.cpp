#include "Game.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Personnage.hpp"
#include <sstream>
#include <ctime>
#include <cstdlib>

int main() {

	Game game;

	game.run();

	//Personnage perso;
	//std::string Bakugo = "Bakugo";
	//bool testBakugo = perso.obtenu(Bakugo);
	//std::cout << "Bool : " << testBakugo << "\n";

	//std::ifstream ifs("Personnages/Deku.ini");
	//std::string titre = "None";
	//std::string name;
	//std::string describ;
	//float level;
	//float point_de_vie;
	//int rank; float speed; float speed_bar;
	//float mana_bar; string capcity_name;
	//float niveau_max; int indice; string obtenu;




	//if (ifs.is_open()) {
	//	std::getline(ifs, titre);
	//	ifs >> name;
	//	ifs >> describ;
	//	ifs >> level;
	//	ifs >> point_de_vie;
	//	ifs >> rank;
	//	ifs >> speed;
	//	ifs >> speed_bar;
	//	ifs >> mana_bar;
	//	ifs >> capcity_name;
	//	ifs >> niveau_max;
	//	ifs >> indice;
	//	ifs >> obtenu;

	//}



	//Personnage Perso(name, describ, level, point_de_vie, rank, speed, speed_bar
	//	, mana_bar, capcity_name, niveau_max, indice,obtenu);
	//Perso.afficher_perso(Perso);

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
	//bool attaque_plus = false;
	//float rotation = 0;

	//int tmp = 0;
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


	//		if (sprite1.getPosition().x == window.getSize().x / 2 - 200 && tmp <= 30) {
	//			course = false;
	//			surPlace = true;
	//			attaque = false;
	//			sprite1.setPosition(sprite1.getPosition().x + 20, sprite1.getPosition().y);
	//			sprite2.setPosition(sprite1.getPosition().x, sprite1.getPosition().y);

	//			sprite1.setPosition(sprite1.getPosition().x - 20, sprite1.getPosition().y);
	//			sprite2.setPosition(sprite1.getPosition().x, sprite1.getPosition().y);
	//		}
	//		rectSourceSprite1.left += 57;
	//		sprite1.setTextureRect(rectSourceSprite1);
	//		if (course == true) {
	//			sprite1.setPosition(sprite1.getPosition().x + 10, window.getPosition().y + 200);

	//		}
	//		tmp++;
	//		std::cout << "TMP : " << tmp << "\n";
	//		if (tmp >= 25) {
	//			surPlace = false;
	//			attaque = true;
	//			attaque_plus = true;
	//			sprite3.setPosition(sprite1.getPosition().x, sprite1.getPosition().y);

	//			if (attaque_plus == true) {
	//				sprite4.setPosition(sprite4.getPosition().x + 10, sprite4.getPosition().y);
	//				//if (sprite4.getPosition().x >= window.getPosition().x) {
	//				//	attaque_plus = false;
	//				//}
	//			}

	//			if (tmp == 30) {
	//				tmp = 0;
	//			}
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
	///*	if (attaque_plus == true) {
	//		window.draw(sprite4);
	//	 }*/



	//	window.display();
	//}
	
	return 0;
 }