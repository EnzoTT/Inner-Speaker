#pragma once
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<stack>
#include<vector>   
#include<map>

using namespace std;

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"

class BarraDeVida
{
private:
	sf::RectangleShape retangulo;
	sf::Texture textura6;
	sf::Texture textura5;
	sf::Texture textura4;
	sf::Texture textura3;
	sf::Texture textura2;
	sf::Texture textura1;
	sf::Texture textura0;



public:
	BarraDeVida(float comprimento, float altura, string textura6, string textura5, string textura4, string textura3, string textura2, string textura1,string textura0);
	~BarraDeVida();

	void atualiza(int vida);
	void renderiza(sf::RenderTarget& target);

	void atualizaPos(sf::Vector2f pos);
};

