#include "Inimigo.h"

Inimigo::Inimigo(sf::Texture& textura, sf::Vector2f posicao,sf::Vector2f desHitbox, sf::Vector2f tamanhoHitbox,int vida) :
	Personagem(textura, posicao, desHitbox, tamanhoHitbox, vida)
{
}


Inimigo::~Inimigo()
{
}


void Inimigo::emColisao(sf::Vector2f direcao)
{
	if (direcao.x < 0.0f)
	{
		//colisao na esquerda
		this->velocidadeVetorial.x = 0.0f;
		this->danoPermitido = true;
		this->foiAtacado = false;
	}
	else if (direcao.x > 0.0f)
	{
		//colisao na direita
		this->velocidadeVetorial.x = 0.0f;
		this->danoPermitido = true;
		this->foiAtacado = false;
	}

	if (direcao.y < 0.0f)
	{
		//colisao por baixo
		this->velocidadeVetorial.y = 0.0f;
	}
	else if (direcao.y > 0.0f)
	{
		//colisao por cima
		this->velocidadeVetorial.y = 0.0f;
		this->danoPermitido = false;
		this->foiAtacado = true;
		
	}
}

void Inimigo::atualizaMovimento(const float& dt)
{
}

