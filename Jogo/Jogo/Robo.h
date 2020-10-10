#pragma once
#include "Inimigo.h"
class Robo :
	public Inimigo
{
private:
	int cont;
	char direcao;
public:
	Robo(sf::Texture& textura, sf::Vector2f posicao, sf::Vector2f desHitbox, sf::Vector2f tamanhoHitbox);
	~Robo();

	virtual void atualizaMovimento(const float& dt);
};

