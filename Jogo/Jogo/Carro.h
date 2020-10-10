#pragma once
#include "Obstaculo.h"
class Carro :
	public Obstaculo
{
public:
	Carro(sf::Texture& textura, sf::Vector2f posicao, sf::Vector2f desHitbox, sf::Vector2f tamanhoHitbox, int intervalo);
	~Carro();
};

