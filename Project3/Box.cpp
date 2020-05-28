#include "Box.hpp"
void Box::initVariables()
{
}

void Box::initFonts()
{
	if (!this->font.loadFromFile("Fonts/NaughtyMonster.ttf")) {
		throw("THERE'S A PROBLEM WITH THE FONTS !");
	}
}

void Box::initButton(Personnage perso)
{
	/*int i = 0;
	while (tabNom[i] != "") {

	}*/
		std::string Deku = "Deku";
		bool testDeku = perso.obtenu(Deku);

		std::string Bakugo = "Bakugo";
		bool testBakugo = perso.obtenu(Bakugo);

		std::string Ochaco = "Ochaco";
		bool testOchaco = perso.obtenu(Ochaco);

		std::string Shoto = "Shoto";
		bool testShoto = perso.obtenu(Shoto);

		std::string Tsuyu = "Tsuyu";
		bool testTsuyu = perso.obtenu(Tsuyu);

		std::string Eijiro = "Eijiro";
		bool testEijiro = perso.obtenu(Eijiro);

		std::string All_Might = "All_Might";
		bool testAll_Might = perso.obtenu(All_Might);

		std::string Denki = "Denki";
		bool testDenki = perso.obtenu(Denki);

		std::string Fumikage = "Fumikage";
		bool testFumikage = perso.obtenu(Fumikage);

		std::string Iida = "Iida";
		bool testIida = perso.obtenu(Iida);

		std::string Kyoka = "Kyoka";
		bool testKyoka = perso.obtenu(Kyoka);

		std::string Mina = "Mina";
		bool testMina = perso.obtenu(Mina);

		std::string Momo = "Momo";
		bool testMomo = perso.obtenu(Momo);
	

	//Buttons
	if (testDeku == 1) {
		if (this->iconTexture.loadFromFile("Data/Deku_icon.png")) {
			this->icon.setTexture(&this->iconTexture);
			std::cout << "THE CHARACH ICON IS OK ! " << "\n";
			this->buttons["CHARAC_DEKU"] = new ButtonCharacter(
				200
				,
				this->window->getSize().y / 12
				,
				&this->font, "Deku \n Le nouveau héro né \n LvL 1"
				,
				this->icon, this->iconTexture);
		}
		else {
			std::cout << "THERE'S A PROBLEM WITH DEKU'S ICON" << "\n";
		}
	}

	if (testBakugo == 1) {
		if (this->iconTexture2.loadFromFile("Data/Bakugo_Icon.png")) {
			this->icon2.setTexture(&this->iconTexture2);
			std::cout << "THE CHARACH ICON IS OK ! " << "\n";
			this->buttons["CHARAC_BAKUGO"] = new ButtonCharacter(
				200
				,
				this->window->getSize().y / 3.5
				,

				&this->font, "Bakugo \n L'élève explosif \n LvL 1"
				,
				this->icon2, this->iconTexture2);
		}
		else {
			std::cout << "THERE'S A PROBLEM WITH BAKUGO'S ICON" << "\n";
		}
	}
	else {
		if (this->iconTexture2.loadFromFile("Data/Bakugo_NotYet.png")) {
			this->icon2.setTexture(&this->iconTexture2);
			std::cout << "THE CHARACH ICON IS OK ! " << "\n";
			this->buttons["CHARAC_BAKUGO_NOTYET"] = new ButtonCharacter(
				200
				,
				this->window->getSize().y / 3.5
				,

				&this->font, "Unavaible"
				,
				this->icon2, this->iconTexture2);
		}
		else {
			std::cout << "THERE'S A PROBLEM WITH BAKUGO'S ICON" << "\n";
		}
	}

	if (testOchaco == 1) {
		if (this->iconTexture3.loadFromFile("Data/Personnages/Ochacho_icon.png")) {
			this->icon3.setTexture(&this->iconTexture3);
			std::cout << "THE CHARACH ICON IS OK ! " << "\n";
			this->buttons["CHARAC_OCHACO"] = new ButtonCharacter(
				200
				,
				this->window->getSize().y / 2
				,

				&this->font, "Ochaco \n Uravity \n LvL 1"
				,
				this->icon3, this->iconTexture3);
		}
		else {
			std::cout << "THERE'S A PROBLEM WITH THE CHARACTER ICON" << "\n";
		}
	}
	else {
		if (this->iconTexture3.loadFromFile("Data/Personnages/Ochaco_icon_NotYet.png")) {
			this->icon3.setTexture(&this->iconTexture3);
			std::cout << "THE CHARACH ICON IS OK ! " << "\n";
			this->buttons["CHARAC_OCHACO_NOTYET"] = new ButtonCharacter(
				200
				,
				this->window->getSize().y / 2
				,

				&this->font, "Unavaible"
				,
				this->icon3, this->iconTexture3);
		}
		else {
			std::cout << "THERE'S A PROBLEM WITH BAKUGO'S ICON" << "\n";
		}
	}

	if (testShoto == 1) {
		if (this->iconTexture4.loadFromFile("Data/Personnages/Shoto_icon.png")) {
			this->icon4.setTexture(&this->iconTexture4);
			std::cout << "THE CHARACH ICON IS OK ! " << "\n";
			this->buttons["CHARAC_SHOTO"] = new ButtonCharacter(
				200
				,
				this->window->getSize().y - 150
				,

				&this->font, "Shoto \n LvL 1"
				,
				this->icon4, this->iconTexture4);
		}
		else {
			std::cout << "THERE'S A PROBLEM WITH THE CHARACTER ICON" << "\n";
		}
	}
	else {
		if (this->iconTexture4.loadFromFile("Data/Personnages/Shoto_icon_NotYet.png")) {
			this->icon4.setTexture(&this->iconTexture4);
			std::cout << "THE CHARACH ICON IS OK ! " << "\n";
			this->buttons["CHARAC_SHOTO_NOTYET"] = new ButtonCharacter(
				200
				,
				this->window->getSize().y -200
				,

				&this->font, "Unavaible"
				,
				this->icon4, this->iconTexture4);
		}
		else {
			std::cout << "THERE'S A PROBLEM WITH BAKUGO'S ICON" << "\n";
		}
	}

	if (testTsuyu == 1) {
		if (this->iconTexture5.loadFromFile("Data/Personnages/Tsuyu_icon.png")) {
			this->icon5.setTexture(&this->iconTexture5);
			std::cout << "THE CHARACH ICON IS OK ! " << "\n";
			this->buttons["CHARAC_TSUYU"] = new ButtonCharacter(
				600
				,
				this->window->getSize().y / 12
				,
				&this->font, "Tsuyu \n Froppy \n LvL 1"
				,
				this->icon5, this->iconTexture5);
		}
		else {
			std::cout << "THERE'S A PROBLEM WITH Tsuyu'S ICON" << "\n";
		}
	}
	else {
		if (this->iconTexture5.loadFromFile("Data/Personnages/Tsuyu_icon_NotYet.png")) {
			this->icon5.setTexture(&this->iconTexture5);
			std::cout << "THE CHARACH ICON IS OK ! " << "\n";
			this->buttons["CHARAC_TSUYU_NOTYET"] = new ButtonCharacter(
				600
				,
				this->window->getSize().y /12
				,

				&this->font, "Unavaible"
				,
				this->icon5, this->iconTexture5);
		}
		else {
			std::cout << "THERE'S A PROBLEM WITH TSUTU'S ICON" << "\n";
		}
	}


	if (testFumikage == 1) {
		if (this->iconTexture6.loadFromFile("Data/Personnages/Fumikage_Icon.png")) {
			this->icon6.setTexture(&this->iconTexture6);
			std::cout << "THE CHARACH ICON IS OK ! " << "\n";
			this->buttons["CHARAC_FUMIKAGE"] = new ButtonCharacter(
				600
				,
				this->window->getSize().y / 3.5
				,

				&this->font, "Fumikage \n Shadow \n LvL 1"
				,
				this->icon6, this->iconTexture6);
		}
		else {
			std::cout << "THERE'S A PROBLEM WITH Fumikage'S ICON" << "\n";
		}
	}
	else {
		if (this->iconTexture6.loadFromFile("Data/Personnages/Fumikage_icon_NotYet.png")) {
			this->icon6.setTexture(&this->iconTexture6);
			std::cout << "THE CHARACH ICON IS OK ! " << "\n";
			this->buttons["CHARAC_FUMIKAGE_NOTYET"] = new ButtonCharacter(
				600
				,
				this->window->getSize().y / 3.5
				,

				&this->font, "Unavaible"
				,
				this->icon6, this->iconTexture6);
		}
		else {
			std::cout << "THERE'S A PROBLEM WITH FUMIKAGE'S ICON" << "\n";
		}
	}

	if (testMina == 1) {
		if (this->iconTexture7.loadFromFile("Data/Personnages/Mina_icon.png")) {
			this->icon7.setTexture(&this->iconTexture7);
			std::cout << "THE CHARACH ICON IS OK ! " << "\n";
			this->buttons["CHARAC_MINA"] = new ButtonCharacter(
				600
				,
				this->window->getSize().y / 2
				,

				&this->font, "Mina \n Pinkie \n LvL 1"
				,
				this->icon7, this->iconTexture7);
		}
		else {
			std::cout << "THERE'S A PROBLEM WITH THE CHARACTER ICON" << "\n";
		}
	}
	else {
		if (this->iconTexture7.loadFromFile("Data/Personnages/Mina_icon_NotYet.png")) {
			this->icon7.setTexture(&this->iconTexture7);
			std::cout << "THE CHARACH ICON IS OK ! " << "\n";
			this->buttons["CHARAC_MINA_NOTYET"] = new ButtonCharacter(
				600
				,
				this->window->getSize().y / 2
				,

				&this->font, "Unavaible"
				,
				this->icon7, this->iconTexture7);
		}
		else {
			std::cout << "THERE'S A PROBLEM WITH MINA'S ICON" << "\n";
		}
	}

	if (testMomo == 1) {
		if (this->iconTexture8.loadFromFile("Data/Personnages/Momo_icon.png")) {
			this->icon8.setTexture(&this->iconTexture8);
			std::cout << "THE CHARACH ICON IS OK ! " << "\n";
			this->buttons["CHARAC_MOMO"] = new ButtonCharacter(
				600
				,
				this->window->getSize().y - 150
				,

				&this->font, "Momo\n Creati \n LvL 1"
				,
				this->icon8, this->iconTexture8);
		}
		else {
			std::cout << "THERE'S A PROBLEM WITH THE CHARACTER ICON" << "\n";
		}
	}
	else {
		if (this->iconTexture8.loadFromFile("Data/Personnages/Momo_icon_NotYet.png")) {
			this->icon8.setTexture(&this->iconTexture8);
			std::cout << "THE CHARACH ICON IS OK ! " << "\n";
			this->buttons["CHARAC_MOMO_NOTYET"] = new ButtonCharacter(
				600
				,
				this->window->getSize().y - 200
				,

				&this->font, "Unavaible"
				,
				this->icon8, this->iconTexture8);
		}
		else {
			std::cout << "THERE'S A PROBLEM WITH MOMO'S ICON" << "\n";
		}
	}


	if (testEijiro == 1) {
		if (this->iconTexture9.loadFromFile("Data/Personnages/Eijiro_icon.png")) {
			this->icon9.setTexture(&this->iconTexture5);
			std::cout << "THE CHARACH ICON IS OK ! " << "\n";
			this->buttons["CHARAC_EIJIRO"] = new ButtonCharacter(
				1000
				,
				this->window->getSize().y / 12
				,
				&this->font, "Eijiro \n Red Riot \n LvL 1"
				,
				this->icon9, this->iconTexture9);
		}
		else {
			std::cout << "THERE'S A PROBLEM WITH Tsuyu'S ICON" << "\n";
		}
	}
	else {
		if (this->iconTexture9.loadFromFile("Data/Personnages/Eijiro_icon_NotYet.png")) {
			this->icon9.setTexture(&this->iconTexture9);
			std::cout << "THE CHARACH ICON IS OK ! " << "\n";
			this->buttons["CHARAC_EIJIRO_NOTYET"] = new ButtonCharacter(
				1000
				,
				this->window->getSize().y / 12
				,

				&this->font, "Unavaible"
				,
				this->icon9, this->iconTexture9);
		}
		else {
			std::cout << "THERE'S A PROBLEM WITH EIJIRO'S ICON" << "\n";
		}
	}


	if (testDenki == 1) {
		if (this->iconTexture10.loadFromFile("Data/Personnages/Denki_Icon.png")) {
			this->icon10.setTexture(&this->iconTexture6);
			std::cout << "THE CHARACH ICON IS OK ! " << "\n";
			this->buttons["CHARAC_DENKI"] = new ButtonCharacter(
				1000
				,
				this->window->getSize().y / 3.5
				,

				&this->font, "Denki \n ChargeBolt \n LvL 1"
				,
				this->icon10, this->iconTexture10);
		}
		else {
			std::cout << "THERE'S A PROBLEM WITH Fumikage'S ICON" << "\n";
		}
	}
	else {
		if (this->iconTexture10.loadFromFile("Data/Personnages/Denki_icon_NotYet.png")) {
			this->icon10.setTexture(&this->iconTexture10);
			std::cout << "THE CHARACH ICON IS OK ! " << "\n";
			this->buttons["CHARAC_DENKI_NOTYET"] = new ButtonCharacter(
				1000
				,
				this->window->getSize().y / 3.5
				,

				&this->font, "Unavaible"
				,
				this->icon10, this->iconTexture10);
		}
		else {
			std::cout << "THERE'S A PROBLEM WITH DENKI'S ICON" << "\n";
		}
	}

	if (testIida == 1) {
		if (this->iconTexture11.loadFromFile("Data/Personnages/Iida_icon.png")) {
			this->icon11.setTexture(&this->iconTexture11);
			std::cout << "THE CHARACH ICON IS OK ! " << "\n";
			this->buttons["CHARAC_IIDA"] = new ButtonCharacter(
				1000
				,
				this->window->getSize().y / 2
				,

				&this->font, "Iida \n Engine \n LvL 1"
				,
				this->icon11, this->iconTexture11);
		}
		else {
			std::cout << "THERE'S A PROBLEM WITH THE CHARACTER ICON" << "\n";
		}
	}
	else {
		if (this->iconTexture11.loadFromFile("Data/Personnages/Iida_icon_NotYet.png")) {
			this->icon11.setTexture(&this->iconTexture11);
			std::cout << "THE CHARACH ICON IS OK ! " << "\n";
			this->buttons["CHARAC_IIDA_NOTYET"] = new ButtonCharacter(
				1000
				,
				this->window->getSize().y / 2
				,

				&this->font, "Unavaible"
				,
				this->icon11, this->iconTexture11);
		}
		else {
			std::cout << "THERE'S A PROBLEM WITH IIDA'S ICON" << "\n";
		}
	}

	if (testKyoka== 1) {
		if (this->iconTexture12.loadFromFile("Data/Personnages/Kyoka_icon.png")) {
			this->icon12.setTexture(&this->iconTexture12);
			std::cout << "THE CHARACH ICON IS OK ! " << "\n";
			this->buttons["CHARAC_KYOKA"] = new ButtonCharacter(
				1000
				,
				this->window->getSize().y - 150
				,

				&this->font, "Kyoka\n Earphone-Jack \n LvL 1"
				,
				this->icon12, this->iconTexture12);
		}
		else {
			std::cout << "THERE'S A PROBLEM WITH THE CHARACTER ICON" << "\n";
		}
	}
	else {
		if (this->iconTexture12.loadFromFile("Data/Personnages/Kyoka_icon_NotYet.png")) {
			this->icon12.setTexture(&this->iconTexture12);
			std::cout << "THE CHARACH ICON IS OK ! " << "\n";
			this->buttons["CHARAC_KYOKA_NOTYET"] = new ButtonCharacter(
				1000
				,
				this->window->getSize().y - 200
				,

				&this->font, "Unavaible"
				,
				this->icon12, this->iconTexture12);
		}
		else {
			std::cout << "THERE'S A PROBLEM WITH KYOKA'S ICON" << "\n";
		}
	}

	//Button retour
	if (this->iconReturnTexture.loadFromFile("Data/return.png")) {
		this->iconReturn.setTexture(&this->iconReturnTexture);
		this->iconReturn.setSize(sf::Vector2f(10, 10));
		std::cout << "THE RETURN ICON IS OK ! " << "\n";
		this->button["RETURN_TO_MENU"] = new ButtonReturn(
			2
			,
			2
			,
			&this->font, ""
			,
			this->iconReturn, this->iconReturnTexture);
	}
	else {
		std::cout << "THERE'S A PROBLEM WITH THE CHARACTER ICON" << "\n";
	}

}

void Box::initBackground()
{
	this->background.setSize(
		sf::Vector2f(this->window->getSize().x
			, this->window->getSize().y)
	);
	//this->background.setFillColor(sf::Color::White);

	if (!this->background_image.loadFromFile("Data/UA_1-A.png")) {
		throw "ERROR PICTURE OF BACKGROUND !";
	}
	this->background.setTexture(&this->background_image);
}

void Box::initKeybinds()
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


Box::Box(sf::RenderWindow * window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	:State(window,supportedKeys,states)
{
	Personnage perso;
	this->initVariables();
	this->initFonts();
	this->initButton(perso);
	this->initBackground();
	this->initKeybinds();
}

Box::~Box()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it) {
		it->second;
	}
}

void Box::updateInput(const float & dt)
{
	this->CheckQuit();

}

void Box::endState()
{
	std::cout << "End Game State !" << "\n";
}

void Box::updateButton()
{
	Personnage perso;
	//update all the buttons
	for (auto it : this->buttons) {
		it.second->update(this->mousePosView);
	}
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
	std::string Deku = "Deku";
	bool testDeku = perso.obtenu(Deku);


	std::string Bakugo = "Bakugo";
	bool testBakugo = perso.obtenu(Bakugo);

	//FichePersonnage
	if (testDeku == 1) {
		if (this->buttons["CHARAC_DEKU"]->isPressed()) {
			this->states->push(new FichePersonnage(this->window, this->supportedKeys, this->states, 0, 0));

		}
	}

	if (testBakugo == 1) {
		if (this->buttons["CHARAC_BAKUGO"]->isPressed()) {
			this->states->push(new FichePersonnage(this->window, this->supportedKeys, this->states, 1, 0));

		}
	}

	//if (this->buttons["CHARAC_TOMURA"]->isPressed()) {
	//	this->states->push(new FichePersonnage(this->window, this->supportedKeys, this->states, 2, 1));

	//}
	//Return
	if (this->button["RETURN_TO_MENU"]->isPressed()) {
		this->states->push(new Accueil(this->window, this->supportedKeys, this->states));

	}
}

void Box::renderButton(sf::RenderTarget * target)
{
	//this->gameState_btn->render(target);
	for (auto it : this->buttons) {
		
		it.second->render(target);
	}

	for (auto it : this->button) {
		it.second->render(target);
	}

/*	Personnage perso;
	std::string Bakugo = "Bakugo";
	bool testBakugo = perso.obtenu(Bakugo);
	if (testBakugo == 0)*/
}


void Box::update(const float& dt)
{
	this->updateInput(dt);
	this->updateButton();
	this->updateMousePosition();
}

void Box::render(sf::RenderTarget* target)
{
	if (!target) {
		target = this->window;
	}
	target->draw(this->background);
	this->renderButton(target);

}