#include "Pneu.h"

Pneu::Pneu(sf::Texture& textura, sf::Vector2f posicao, sf::Vector2f desHitbox, sf::Vector2f tamanhoHitbox, int intervalo) :
	Obstaculo(textura, posicao, desHitbox, tamanhoHitbox, intervalo)
{
	this->peso = 1;
}

Pneu::~Pneu()
{
}
