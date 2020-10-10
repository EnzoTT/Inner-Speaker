#include "Caixa.h"

Caixa::Caixa(sf::Texture& textura, sf::Vector2f posicao, sf::Vector2f desHitbox, sf::Vector2f tamanhoHitbox, int intervalo):
	Obstaculo (textura, posicao, desHitbox, tamanhoHitbox,intervalo)
{
	this->peso = 0;
}


Caixa::~Caixa()
{
}



