#pragma once
#include "Inimigo.h"
class Fantasma :
	public Inimigo
{
private:
	int cont;
	char direcao;

public:
	Fantasma(sf::Texture& textura, sf::Vector2f posicao, sf::Vector2f desHitbox, sf::Vector2f tamanhoHitbox);
	~Fantasma();

	virtual void atualizaMovimento(const float& dt);

};

