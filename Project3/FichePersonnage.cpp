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

void FichePersonnage::initBackground(int VilOrHero)
{
	
	this->background.setSize(
		sf::Vector2f(this->window->getSize().x
			, this->window->getSize().y)
	);
	//this->background.setFillColor(sf::Color::White);
	if (VilOrHero == 0) {

		if (!this->background_image.loadFromFile("Data/UA.jpg")) {
			throw "ERROR PICTURE OF BACKGROUND !";
		}
		this->background.setTexture(&this->background_image);
	}
	if (VilOrHero == 1) {
		if (!this->background_image.loadFromFile("Data/Bar.jpg")) {
			throw "ERROR PICTURE OF BACKGROUND !";
		}
		this->background.setTexture(&this->background_image);
	}
}

void FichePersonnage::initInformation(int indice)
{
	//Deku
	if (indice == 0) {
		//Image du personnage
		if (this->iconPersonnageTexture.loadFromFile("Data/Deku_Revetement.png")) {

			this->iconPersonnage.setTexture(&this->iconPersonnageTexture);
			std::cout << "THE CHARACH DEKU ICON IS OK ! " << "\n";

			this->iconPersonnage.setPosition(sf::Vector2f(this->window->getSize().x / 20, this->window->getSize().y / 12));
			this->iconPersonnage.setSize(sf::Vector2f(446 / 1.2, 608 / 1.2));
		}

		//Fond blanc principal
		this->iconPersonnageFond.setPosition(10, 10);
		this->iconPersonnageFond.setSize(sf::Vector2f(this->window->getSize().x - 20, this->window->getSize().y - 20));
		this->iconPersonnageFond.setFillColor(sf::Color(255, 255, 255, 150));
		this->iconPersonnageFond.setOutlineThickness(3);
		this->iconPersonnageFond.setOutlineColor(sf::Color(0, 0, 0, 255));


		this->textInformation.setFont(this->font);
		this->textInformation.setPosition(sf::Vector2f(this->window->getSize().x / 2.6, this->window->getSize().y / 8));
		this->textInformation.setFillColor(sf::Color(0, 0, 0, 255));
		this->textInformation.setCharacterSize(18);
		std::string textPrincipal = " Age : 15 ans \n\n Taille : 166 cm \n\n Genre : Masculin \n\n Statut : Elève de Yuei \n \n Style de combat : Corps à corps \n\n ______________";
		
		std::ifstream ifs("Personnages/Deku.ini");
		std::string titre = "None";
		std::string name;
		std::string describ;
		float level;
		float point_de_vie;
		int rank; float speed; float speed_bar;
		float mana_bar; std::string capcity_name;
		float niveau_max; int indice;



		if (ifs.is_open()) {
			std::getline(ifs, titre);
			ifs >> name;
			ifs >> describ;
			ifs >> level;
			ifs >> point_de_vie;
			ifs >> rank;
			ifs >> speed;
			ifs >> speed_bar;
			ifs >> mana_bar;
			ifs >> capcity_name;
			ifs >> niveau_max;
			ifs >> indice;

		}
		std::ostringstream oss;
		oss <<"\n \n"<<" Level : "<<level<<"\n \n" " PV : " << point_de_vie << "\n\n "<<"Statut : " << rank << "\n\n" << "Vitesse : "<<speed<<"\n\n"<<"Capacité : "<<capcity_name;
		std::string var = oss.str();
		this->textInformation.setString(var);
		textPrincipal += var;

		this->textInformation.setString(textPrincipal);



		//Texte Nom Prénom
		this->textNom.setPosition(sf::Vector2f(this->iconPersonnage.getPosition().x + (this->iconPersonnage.getSize().x / 3), this->iconPersonnage.getPosition().y + this->iconPersonnage.getSize().y + 5));
		this->textNom.setFont(this->font);
		this->textNom.setFillColor(sf::Color(12, 102, 35, 255));
		this->textNom.setCharacterSize(22);
		this->textNom.setString("Midoriya Izuku");
	}
	//Bakugo
	if (indice == 1) {
		//Image du personnage
		if (this->iconPersonnageTexture.loadFromFile("Data/Bakugo.png")) {

			this->iconPersonnage.setTexture(&this->iconPersonnageTexture);
			std::cout << "THE CHARACH DEKU ICON IS OK ! " << "\n";

			this->iconPersonnage.setPosition(sf::Vector2f(-20, -20));
			this->iconPersonnage.setSize(sf::Vector2f(600, 608));
		}

		//Fond blanc principal
		this->iconPersonnageFond.setPosition(10, 10);
		this->iconPersonnageFond.setSize(sf::Vector2f(this->window->getSize().x - 20, this->window->getSize().y - 20));
		this->iconPersonnageFond.setFillColor(sf::Color(255, 255, 255, 150));
		this->iconPersonnageFond.setOutlineThickness(3);
		this->iconPersonnageFond.setOutlineColor(sf::Color(0, 0, 0, 255));


		this->textInformation.setFont(this->font);
		this->textInformation.setPosition(sf::Vector2f(this->window->getSize().x / 2.6, this->window->getSize().y / 8));
		this->textInformation.setFillColor(sf::Color(0, 0, 0, 255));
		this->textInformation.setCharacterSize(18);
		this->textInformation.setString(
			" Age : 15 ans \n\n Taille : 172 cm \n\n Genre : Masculin \n\n Statut : Elève de Yuei \n \n Style de combat : Frappe et esquive \n\n ______________");

		//Texte Nom Prénom
		this->textNom.setPosition(sf::Vector2f(this->iconPersonnage.getPosition().x + (this->iconPersonnage.getSize().x / 3), this->iconPersonnage.getPosition().y + this->iconPersonnage.getSize().y - 40));
		this->textNom.setFont(this->font);
		this->textNom.setFillColor(sf::Color(117, 4, 7, 255));
		this->textNom.setCharacterSize(22);
		this->textNom.setString("Katsuki Bakugo");
	}
	//Tomokura
	if (indice == 2) {
		//Image du personnage
		if (this->iconPersonnageTexture.loadFromFile("Data/Tomura.png")) {

			this->iconPersonnage.setTexture(&this->iconPersonnageTexture);
			std::cout << "THE CHARACH DEKU ICON IS OK ! " << "\n";

			this->iconPersonnage.setPosition(sf::Vector2f(60, 90));
			this->iconPersonnage.setSize(sf::Vector2f(450, 400));
		}

		//Fond blanc principal
		this->iconPersonnageFond.setPosition(10, 10);
		this->iconPersonnageFond.setSize(sf::Vector2f(this->window->getSize().x - 20, this->window->getSize().y - 20));
		this->iconPersonnageFond.setFillColor(sf::Color(255, 255, 255, 150));
		this->iconPersonnageFond.setOutlineThickness(3);
		this->iconPersonnageFond.setOutlineColor(sf::Color(0, 0, 0, 255));


		this->textInformation.setFont(this->font);
		this->textInformation.setPosition(sf::Vector2f(this->window->getSize().x / 2.6, this->window->getSize().y / 8));
		this->textInformation.setFillColor(sf::Color(0, 0, 0, 255));
		this->textInformation.setCharacterSize(18);
		this->textInformation.setString(
			"Age : 20 ans \n\n Taille : 175 cm \n\n Genre : Masculin \n\n Statut : Chef de l'Alliance des Super-Vilains \n \n Style de combat : Corps à Corps\n\n ______________");

		//Texte Nom Prénom
		this->textNom.setPosition(sf::Vector2f(this->iconPersonnage.getPosition().x + (this->iconPersonnage.getSize().x / 3), this->iconPersonnage.getPosition().y + this->iconPersonnage.getSize().y ));
		this->textNom.setFont(this->font);
		this->textNom.setFillColor(sf::Color(117, 4, 7, 255));
		this->textNom.setCharacterSize(22);
		this->textNom.setString("Tomura Shigaraki");
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

FichePersonnage::FichePersonnage(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, int indice, int VilOrHero)
	:State(window, supportedKeys, states)
{
	this->initVariables();
	this->initFonts();
	this->initButton();
	this->initBackground(VilOrHero);
	this->initKeybinds();
	this->initInformation(indice);

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
	target->draw(this->iconPersonnageFond);
	target->draw(this->iconPersonnage);
	target->draw(this->textNom);
	target->draw(this->textInformation);
	target->draw(this->text);
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
	this->renderInformation(target);
	this->renderButton(target);

	

}