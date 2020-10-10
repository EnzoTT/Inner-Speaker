#include <SFML/Graphics.hpp>
#include <iostream>
#include "Jogo.h"
//Enzo e Ale
using namespace std;
static const float VIEW_HEIGHT = 512.0f;
void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{
	//CODIGO ANTIGO
	/*sf::RenderWindow window(sf::VideoMode(540.0f, 540.0f), "SFML Tutorial");
	
	

	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
	sf::Texture playerTexture;
	playerTexture.loadFromFile("personagem.png");


	Player player(&playerTexture, sf::Vector2u(6, 2), 0.15f, 100.0f);
	
	float deltaTime = 0.0f;
	sf::Clock clock;

	
	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
	
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				ResizeView(window, view);
				break;
			}
			
		}
		

		player.Update(deltaTime);
		view.setCenter(player.GetPosition());


		//Limpa a janela
		window.clear();
		window.setView(view);
	
		player.Draw(window);
		window.display();
	}
	*/
	Jogo jogo;
	jogo.run();
	
	return 0;

}