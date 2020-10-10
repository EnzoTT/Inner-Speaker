#include "Plataforma.h"

Plataforma::Plataforma(sf::Texture& textura, sf::Vector2f posicao, sf::Vector2f desHitbox, sf::Vector2f tamanhoHitbox, bool transparente):
	Entidade(textura, posicao, desHitbox, tamanhoHitbox)
{
	if (transparente)
	{
		this->sprite.setColor(sf::Color::Transparent);
	}
}

Plataforma::~Plataforma()
{
}

