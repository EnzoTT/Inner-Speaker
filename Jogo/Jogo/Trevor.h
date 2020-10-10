#pragma once
#include "Inimigo.h"
class Trevor :
	public Inimigo
{
private:
	int cont;
	bool atacando;
	int ciclo;
	int direcao;

public:
	Trevor(sf::Texture& textura, sf::Vector2f posicao, sf::Vector2f desHitbox, sf::Vector2f tamanhoHitbox);
	~Trevor();

	virtual void atualizaMovimento(const float& dt);
};

