#include "FichePersonnage.hpp"

void FichePersonnage::initVariables()
{
}

void FichePersonnage::initFonts()
{
	if (!this->font.loadFromFile("Fonts/NaughtyMonster.ttf")) {
		throw("THERE'S A PROBLEM WITH THE FONTS !");
	}
}

void FichePersonnage::initButton()
{

	if (this->iconReturnTexture.loadFromFile("Data/return.png")) {
		this->iconReturn.setTexture(&this->iconReturnTexture);
		this->iconReturn.setSize(sf::Vector2f(10, 10));
		std::cout << "THE RETURN ICON IS OK ! " << "\n";
		this->button["RETURN_TO_BOX"] = new ButtonReturn(
			10
			,
			10
			,
			&this->font, ""
			,
			this->iconReturn, this->iconReturnTexture);
	}

	else {
		std::cout << "THERE'S A PROBLEM WITH THE CHARACTER ICON" << "\n";
	}

}

void FichePersonnage::initBackground(std::string color)
{
	
	this->background.setSize(
		sf::Vector2f(this->window->getSize().x
			, this->window->getSize().y)
	);
	//this->background.setFillColor(sf::Color::White);
	if (!this->background_image.loadFromFile("Data/Background.jpg")) {
		throw "ERROR PICTURE OF BACKGROUND !";
	}
	this->background.setTexture(&this->background_image);

	if (color == "green") {
		if (!this->firstBackTexture.loadFromFile("Data/green.png")) {
			throw "ERROR COLOR GREEN ! ";
		}
		this->firstBack.setTexture(&this->firstBackTexture);
		this->secondBack.setTexture(&this->firstBackTexture);
		this->thirdBack.setTexture(&this->firstBackTexture);
		this->fourthBack.setTexture(&this->firstBackTexture);
		
		//Emplacement et taille 
		this->firstBack.setSize(sf::Vector2f(this->window->getSize().x / 1.3, this->window->getSize().y - 150));
		this->firstBack.setPosition(sf::Vector2f(50, 50));
		this->secondBack.setSize(sf::Vector2f(300, 200));
		this->secondBack.setPosition(sf::Vector2f(this->firstBack.getPosition().x + this->firstBack.getSize().x + 20, this->firstBack.getPosition().y));
		this->thirdBack.setSize(sf::Vector2f(300, 150));
		this->thirdBack.setPosition(sf::Vector2f(this->secondBack.getPosition().x, this->secondBack.getPosition().y + this->secondBack.getSize().y + 10));
		this->fourthBack.setSize(sf::Vector2f(300, 560));
		this->fourthBack.setPosition(sf::Vector2f(this->thirdBack.getPosition().x, this->thirdBack.getPosition().y + this->thirdBack.getSize().y + 10));
	}
	if (color == "red") {
		if (!this->firstBackTexture.loadFromFile("Data/red.jpg")) {
			throw "ERROR COLOR GREEN ! ";
		}
		this->firstBack.setTexture(&this->firstBackTexture);
		this->secondBack.setTexture(&this->firstBackTexture);
		this->thirdBack.setTexture(&this->firstBackTexture);
		this->fourthBack.setTexture(&this->firstBackTexture);

		//Emplacement et taille 
		this->firstBack.setSize(sf::Vector2f(this->window->getSize().x / 1.3, this->window->getSize().y - 150));
		this->firstBack.setPosition(sf::Vector2f(50, 50));
		this->secondBack.setSize(sf::Vector2f(300, 200));
		this->secondBack.setPosition(sf::Vector2f(this->firstBack.getPosition().x + this->firstBack.getSize().x + 20, this->firstBack.getPosition().y));
		this->thirdBack.setSize(sf::Vector2f(300, 150));
		this->thirdBack.setPosition(sf::Vector2f(this->secondBack.getPosition().x, this->secondBack.getPosition().y + this->secondBack.getSize().y + 10));
		this->fourthBack.setSize(sf::Vector2f(300, 560));
		this->fourthBack.setPosition(sf::Vector2f(this->thirdBack.getPosition().x, this->thirdBack.getPosition().y + this->thirdBack.getSize().y + 10));
	}
}

void FichePersonnage::initInformation(int indice, int VilOrHero)
{
	//Deku

	if (indice == 0 ) {
		//Image du personnage
		//Les différentes forme du personnanges

		if (this->casualTexture.loadFromFile("Data/Fiche_Personnage/Deku_Casual.png")) {

			this->casual.setTexture(&this->casualTexture);
			std::cout << "THE CHARACH DEKU'S CASUAL ICON IS OK ! " << "\n";

			this->casual.setPosition(sf::Vector2f(this->firstBack.getPosition().x + 10, this->firstBack.getPosition().y + this->firstBack.getSize().y - 700));
			this->casual.setSize(sf::Vector2f(this->firstBack.getSize().x / 3.2, this->firstBack.getSize().y / 1.3));
		}
		if (this->uniformeTexture.loadFromFile("Data/Fiche_Personnage/Deku_School.png")) {

			this->uniforme.setTexture(&this->uniformeTexture);
			std::cout << "THE CHARACH DEKU'S uniforme ICON IS OK ! " << "\n";

			this->uniforme.setPosition(sf::Vector2f(this->casual.getPosition().x + this->casual.getSize().x + 100, this->casual.getPosition().y + 30));
			this->uniforme.setSize(sf::Vector2f(this->firstBack.getSize().x / 7, this->firstBack.getSize().y / 1.4));
		}
		if (this->costumeTexture.loadFromFile("Data/Fiche_Personnage/Deku_Costume.png")) {

			this->costume.setTexture(&this->costumeTexture);
			std::cout << "THE CHARACH DEKU'S CASUAL ICON IS OK ! " << "\n";

			this->costume.setPosition(sf::Vector2f(this->uniforme.getPosition().x + this->uniforme.getSize().x + 150, this->uniforme.getPosition().y + 20));
			this->costume.setSize(sf::Vector2f(this->firstBack.getSize().x / 5, this->firstBack.getSize().y / 1.45));
		}


		this->textCasual.setFont(this->font);		
		this->textUniforme.setFont(this->font);
		this->textCostume.setFont(this->font);

		this->textCasual.setPosition(sf::Vector2f(this->casual.getPosition().x + this->casual.getSize().x/2, this->casual.getPosition().y ));
		this->textUniforme.setPosition(sf::Vector2f(this->uniforme.getPosition().x + this->uniforme.getSize().x / 2 - 10, this->uniforme.getPosition().y - 50));
		this->textCostume.setPosition(sf::Vector2f(this->costume.getPosition().x + this->costume.getSize().x / 2 -10, this->costume.getPosition().y - 50));

		this->textCasual.setFillColor(sf::Color(255, 255, 255, 255));
		this->textUniforme.setFillColor(sf::Color(255, 255, 255, 255));
		this->textCostume.setFillColor(sf::Color(255, 255, 255, 255));

		this->textCasual.setCharacterSize(22);
		this->textUniforme.setCharacterSize(22);
		this->textCostume.setCharacterSize(22);

		this->textCasual.setString("Casual");
		this->textUniforme.setString("Uniforme");
		this->textCostume.setString("Costume");

		//Logo et noms
		if (this->logoTexture.loadFromFile("Data/Fiche_Personnage/UA.png")) {

			this->logo.setTexture(&this->logoTexture);
			std::cout << "THE CHARACH LOGO ICON IS OK ! " << "\n";

			this->logo.setPosition(sf::Vector2f(this->secondBack.getPosition().x + this->secondBack.getSize().x/2 - (this->casual.getSize().x/5), this->secondBack.getPosition().y + 10));
			this->logo.setSize(sf::Vector2f(this->secondBack.getSize().x / 1.5, this->secondBack.getSize().y / 1.5));
			this->textName.setFont(this->font);
			this->textName.setPosition(sf::Vector2f(this->logo.getPosition().x +30, this->logo.getPosition().y + this->logo.getSize().y ));
			this->textName.setFillColor(sf::Color(255, 255, 255, 255));
			this->textName.setCharacterSize(26);
			this->textName.setString("Izuku Midoriya");
		}

		//Nom héro
		this->textHeroName.setFont(this->font);
		this->textHeroName.setPosition(sf::Vector2f(this->thirdBack.getPosition().x + 30, this->thirdBack.getPosition().y + 60));
		this->textHeroName.setFillColor(sf::Color(255, 255, 255, 255));
		this->textHeroName.setCharacterSize(30);
		this->textHeroName.setString("Hero Name : Deku");

		//Information général du personnage
		this->textInformation.setFont(this->font);
		this->textInformation.setPosition(sf::Vector2f(this->fourthBack.getPosition().x + 5, this->fourthBack.getPosition().y + 10));
		this->textInformation.setFillColor(sf::Color(255, 255, 255, 255));
		this->textInformation.setCharacterSize(22);
		this->textInformation.setString("Taille : 166 cm \n \n Alter : One For All \n   est un Alter transferable qui \n fut possede par de nombreux \n hotes. \n One For All permet à \n l\x27 hôte \n d’accéder à la puissance \n des utilisateurs precedents de \n l\x27 alter.\n Semble aussi modifier l\x27 apparence \n de l’utilisateur de différentes \n façons.");
	}
	//Bakugo
	if (indice == 1) {
		//Image du personnage
		//Les différentes forme du personnanges

		if (this->casualTexture.loadFromFile("Data/Fiche_Personnage/Bakugo_Casual.png")) {

			this->casual.setTexture(&this->casualTexture);
			std::cout << "THE CHARACH Bakugo'S CASUAL ICON IS OK ! " << "\n";

			this->casual.setPosition(sf::Vector2f(this->firstBack.getPosition().x + 10, this->firstBack.getPosition().y + this->firstBack.getSize().y - 700));
			this->casual.setSize(sf::Vector2f(this->firstBack.getSize().x / 5, this->firstBack.getSize().y / 1.35));
		}
		if (this->uniformeTexture.loadFromFile("Data/Fiche_Personnage/Bakugo_School.png")) {

			this->uniforme.setTexture(&this->uniformeTexture);
			std::cout << "THE CHARACH Bakugo'S uniforme ICON IS OK ! " << "\n";

			this->uniforme.setPosition(sf::Vector2f(this->casual.getPosition().x + this->casual.getSize().x + 150, this->casual.getPosition().y + 30));
			this->uniforme.setSize(sf::Vector2f(this->firstBack.getSize().x / 5, this->firstBack.getSize().y / 1.4));
		}
		if (this->costumeTexture.loadFromFile("Data/Fiche_Personnage/Bakugo_Costume.png")) {

			this->costume.setTexture(&this->costumeTexture);
			std::cout << "THE CHARACH Bakugo'S CASUAL ICON IS OK ! " << "\n";

			this->costume.setPosition(sf::Vector2f(this->uniforme.getPosition().x + this->uniforme.getSize().x + 200, this->uniforme.getPosition().y - 20));
			this->costume.setSize(sf::Vector2f(this->firstBack.getSize().x / 4, this->firstBack.getSize().y / 1.35));
		}


		this->textCasual.setFont(this->font);
		this->textUniforme.setFont(this->font);
		this->textCostume.setFont(this->font);

		this->textCasual.setPosition(sf::Vector2f(this->casual.getPosition().x + this->casual.getSize().x / 2 - 25, this->casual.getPosition().y - 20));
		this->textUniforme.setPosition(sf::Vector2f(this->uniforme.getPosition().x + this->uniforme.getSize().x / 2 - 10, this->uniforme.getPosition().y - 50));
		this->textCostume.setPosition(sf::Vector2f(this->costume.getPosition().x + this->costume.getSize().x / 2 - 70, this->costume.getPosition().y - 50));

		this->textCasual.setFillColor(sf::Color(255, 255, 255, 255));
		this->textUniforme.setFillColor(sf::Color(255, 255, 255, 255));
		this->textCostume.setFillColor(sf::Color(255, 255, 255, 255));

		this->textCasual.setCharacterSize(22);
		this->textUniforme.setCharacterSize(22);
		this->textCostume.setCharacterSize(22);

		this->textCasual.setString("Casual");
		this->textUniforme.setString("Uniforme");
		this->textCostume.setString("Costume");

		//Logo et noms
		if (this->logoTexture.loadFromFile("Data/Fiche_Personnage/UA.png")) {

			this->logo.setTexture(&this->logoTexture);
			std::cout << "THE CHARACH LOGO ICON IS OK ! " << "\n";

			this->logo.setPosition(sf::Vector2f(this->secondBack.getPosition().x + this->secondBack.getSize().x / 2 - (this->casual.getSize().x / 5), this->secondBack.getPosition().y + 10));
			this->logo.setSize(sf::Vector2f(this->secondBack.getSize().x / 1.5, this->secondBack.getSize().y / 1.5));
			this->textName.setFont(this->font);
			this->textName.setPosition(sf::Vector2f(this->logo.getPosition().x + 30, this->logo.getPosition().y + this->logo.getSize().y));
			this->textName.setFillColor(sf::Color(255, 255, 255, 255));
			this->textName.setCharacterSize(26);
			this->textName.setString("Bakugo Katsuki");
		}

		//Nom héro
		this->textHeroName.setFont(this->font);
		this->textHeroName.setPosition(sf::Vector2f(this->thirdBack.getPosition().x + 30, this->thirdBack.getPosition().y + 60));
		this->textHeroName.setFillColor(sf::Color(255, 255, 255, 255));
		this->textHeroName.setCharacterSize(25);
		this->textHeroName.setString("Hero Name : King Bomberkill");

		//Information général du personnage
		this->textInformation.setFont(this->font);
		this->textInformation.setPosition(sf::Vector2f(this->fourthBack.getPosition().x + 5, this->fourthBack.getPosition().y + 10));
		this->textInformation.setFillColor(sf::Color(255, 255, 255, 255));
		this->textInformation.setCharacterSize(22);
		this->textInformation.setString("Taille : 172 cm \n \n Alter : Explosion \n  permet à son posseseur de créer\n des explosions à volonté grâce à\n la sueur\n de ses mains, cette sueur\n est en partie composée\n de nitroglycérine qui vient \n des glandes sudoripares des paumes\n qui ont subi une mutation");
	}
	
}

void FichePersonnage::initKeybinds()
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

FichePersonnage::FichePersonnage(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, int indice, int VilOrHero,std::string color)
	:State(window, supportedKeys, states)
{
	this->initVariables();
	this->initFonts();
	this->initButton();
	this->initBackground(color);
	this->initKeybinds();
	this->initInformation(indice, VilOrHero);
}

FichePersonnage::~FichePersonnage()
{
	/*auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it) {
		it->second;
	}*/
}

void FichePersonnage::updateInput(const float & dt)
{
	this->CheckQuit();

}

void FichePersonnage::endState()
{
	std::cout << "End Game State !" << "\n";
}

void FichePersonnage::updateButton()
{
	//update all the buttons
	/*for (auto it : this->buttons) {
		it.second->update(this->mousePosView);
	}*/
	for (auto it : this->button) {
		it.second->update(this->mousePosView);
	}

	//Start Game 
	/*if (this->buttons["CHARAC_STATE"]->isPressed()) {
		this->states->push(new GameState(this->window, this->supportedKeys, this->states));

	}
	if (this->buttons["CHARAC_STATE"]->isPressed()) {
		this->states->push(new GameState(this->window, this->supportedKeys, this->states));

	}*/
	//FichePersonnage
	//if (this->button["CHARAC_DEKU"]->isPressed()) {
	//	this->states->push(new FichePersonnage(this->window, this->supportedKeys, this->states));

	//}
	////Return
	if (this->button["RETURN_TO_BOX"]->isPressed()) {
		this->states->push(new Box(this->window, this->supportedKeys, this->states));

	}
}

void FichePersonnage::renderButton(sf::RenderTarget * target)
{
	//this->gameState_btn->render(target);
	/*for (auto it : this->buttons) {
		it.second->render(target);
	}*/

	for (auto it : this->button) {
		it.second->render(target);
	}
}

void FichePersonnage::updateInformation()
{
	
}

void FichePersonnage::renderInformation(sf::RenderTarget * target)
{
	target->draw(this->casual);
	target->draw(this->uniforme);
	target->draw(this->costume);
	target->draw(this->textCostume);
	target->draw(this->textCasual);
	target->draw(this->textUniforme);
	target->draw(this->logo);
	target->draw(this->textName);
	target->draw(this->textHeroName);
	target->draw(this->textInformation);
	
}

void FichePersonnage::update(const float& dt)
{
	this->updateInput(dt);
	this->updateButton();
	this->updateMousePosition();
}

void FichePersonnage::render(sf::RenderTarget* target)
{
	if (!target) {
		target = this->window;
	}
	target->draw(this->background);
	target->draw(this->firstBack);
	target->draw(this->secondBack);
	target->draw(this->thirdBack);
	target->draw(this->fourthBack);
	this->renderInformation(target);
	this->renderButton(target);

	

}