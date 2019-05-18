
#include <SFML/Graphics.hpp>
#include "mangoTree.h"
#include <thread>
#include <vector>
#include<iostream>
using namespace sf;
using namespace std;
int main()
{

	mangoTree lista;
	mangoTree lista2;
	vector<mangoFruit*>mangos = lista.getVector();
	vector<mangoFruit*>mangos2 = lista2.getVector();

	bool dosArboles = false;

	thread t1(&mangoTree::menu, lista,ref(lista),ref(lista2),ref(dosArboles));
	t1.detach();

	
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
	// ================================
	// = ARBOLES					  =
	// ================================
	Texture* texture = new Texture();
	if (!texture->loadFromFile("dqu.png")) {
		
	}

	Sprite* sprite = new Sprite();
	sprite->setTexture(*texture);

	
	Texture* texture2 = new Texture();
	if (!texture2->loadFromFile("dqu.png")) {

	}

	Sprite* sprite2 = new Sprite();
	sprite2->setTexture(*texture2);
	sprite2->setPosition(Vector2f(550, 0));

	// ================================
	// = GRASS  					  =
	// ================================

	Texture* grass = new Texture();
	if (!grass->loadFromFile("grass.png")) {
		cout << "hola";
	}
	

	Sprite* grass2 = new Sprite();
	grass2->setTexture(*grass);
	grass2->setPosition(Vector2f(0, 340));
	grass2->setScale(Vector2f(0.4f, 0.4f));


	// ================================
	// = SKY						  =
	// ================================

	Texture* sky = new Texture();
	if (!sky->loadFromFile("sky.png")) {
		cout << "hola";
	}


	Sprite* sky2 = new Sprite();
	sky2->setTexture(*sky);
	sky2->setPosition(Vector2f(0,0));
	//sky2->setScale(Vector2f(0.4f, 0.4f));

	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(*sky2);
		window.draw(*grass2);
		window.draw(*sprite);
	
		for (std::vector<mangoFruit *>::iterator it = mangos.begin(); it != mangos.end(); ++it) {

			Texture* texture = new Texture();
			if (!texture->loadFromFile("mango.png")) {

			}

			Sprite* sprite = new Sprite();
			sprite->setTexture(*texture);

			sprite->setScale(0.03f * (*it)->getWeight(), 0.03f * (*it)->getWeight());
			sprite->setPosition(Vector2f((*it)->x, (*it)->y));
			window.draw((*sprite));
			delete sprite;
			delete texture;
		}
		if (dosArboles) {
			window.draw((*sprite2));

			for (std::vector<mangoFruit*>::iterator it = mangos2.begin(); it != mangos2.end(); ++it) {

				Texture* texture = new Texture();
				if (!texture->loadFromFile("mango.png")) {

				}

				Sprite* sprite = new Sprite();
				sprite->setTexture(*texture);

				sprite->setScale(0.03f * (*it)->getWeight(), 0.03f * (*it)->getWeight());
				sprite->setPosition(Vector2f((*it)->x, (*it)->y));
				window.draw((*sprite));
				delete sprite;
				delete texture;
			}

		}
			

		window.display();

		mangos = lista.getVector();
		mangos2 = lista2.getVector();
		
	}

	return 0;
}