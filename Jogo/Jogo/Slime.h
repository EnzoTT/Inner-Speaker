#pragma once
#include "Inimigo.h"

class Slime:
	public Inimigo
{
private:
	int cont;
	char direcao;
public:
	Slime(sf::Texture& textura, sf::Vector2f posicao, sf::Vector2f desHitbox, sf::Vector2f tamanhoHitbox);
	~Slime();

	virtual void atualizaMovimento(const float& dt);
};

