#pragma once
#include "Obstaculo.h"
class Pneu :
	public Obstaculo
{
public:
	Pneu(sf::Texture& textura, sf::Vector2f posicao, sf::Vector2f desHitbox, sf::Vector2f tamanhoHitbox,int intervalo);
	~Pneu();
};

