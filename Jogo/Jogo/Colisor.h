#pragma once
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<stack>
#include<vector>   
#include<map>

using namespace std;
#include "Animador.h"

class Colisor
{
private:
	sf::Sprite& sprite;
	sf::RectangleShape& hitbox;



public:
	Colisor(sf::Sprite& sprite, sf::RectangleShape& hitbox);
	~Colisor();

	void move(float deltaX, float deltaY)
	{
		sprite.move(deltaX, deltaY);
	}

	bool verificaColisao(Colisor& outroCorpo, sf::Vector2f& direcao, float repulsao);
	
	//Funcoes com relacao ao retangulo (hitbox)
	sf::Vector2f getPosicao()
	{
		return hitbox.getPosition();
	}
	
	sf::Vector2f getMetadeDoTamanho()
	{
		//return sf::Vector2f((sprite.getGlobalBounds().width/ 2.0f), (sprite.getGlobalBounds().height / 2.0f)-2);
		return hitbox.getSize() / 2.f;
		
	}

};

