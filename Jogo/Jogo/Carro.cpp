#include "Carro.h"

Carro::Carro(sf::Texture& textura, sf::Vector2f posicao, sf::Vector2f desHitbox, sf::Vector2f tamanhoHitbox, int intervalo) :
	Obstaculo(textura, posicao, desHitbox, tamanhoHitbox, intervalo)
{
	peso = 1;
}

Carro::~Carro()
{
}
