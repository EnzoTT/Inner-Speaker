#pragma once
#include "Inimigo.h"
class Alterego :
	public Inimigo
{
private:
	int cont;
	char direcao;

public:
	Alterego(sf::Texture& textura, sf::Vector2f posicao, sf::Vector2f desHitbox, sf::Vector2f tamanhoHitbox);
	~Alterego();

	virtual void atualizaMovimento(const float& dt);

};

