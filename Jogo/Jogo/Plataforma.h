#pragma once
#include "Entidade.h"
class Plataforma :public Entidade
{
private:
	
public:
	Plataforma(sf::Texture& textura, sf::Vector2f posicao, sf::Vector2f desHitbox, sf::Vector2f tamanhoHitbox, bool transparente);
	~Plataforma();

};

