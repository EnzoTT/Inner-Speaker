#include "Obstaculo.h"



Obstaculo::Obstaculo(sf::Texture& textura, sf::Vector2f posicao, sf::Vector2f desHitbox, sf::Vector2f tamanhoHitbox, int intervalo)
	:Entidade(Entidade(textura, posicao, desHitbox, tamanhoHitbox))

{
	this->intervalo = intervalo;
}


Obstaculo::~Obstaculo()
{
}

void Obstaculo::atualiza(const float& dt)
{
	velocidadeVetorial.x = 0.0f;
	atualizaHitbox();
	velocidadeVetorial.y += 981.0f * dt;
	if (cai)
	{
		sprite.move(sf::Vector2f(0,3));
	}
	else
	{
	sprite.move(velocidadeVetorial * dt);

	}
}

void Obstaculo::emColisao(sf::Vector2f direcao)
{
	if (direcao.x < 0.0f)
	{
		//colisao na esquerda
		this->velocidadeVetorial.x = 0.0f;



	}
	else if (direcao.x > 0.0f)
	{
		//colisao na direita
		this->velocidadeVetorial.x = 0.0f;


	}

	if (direcao.y < 0.0f)
	{
		//colisao por baixo
		this->velocidadeVetorial.y = 0.0f;
		cai = false;

	}
	else if(!(direcao.y < 0.0f))
	{
		cai = true;
	}
	else if (direcao.y > 0.0f)
	{
		//colisao por cima
		this->velocidadeVetorial.y = 0.0f;

	}
}

void Obstaculo::movimento(const float& dt, sf::Vector2f deslocamento)
{
	//Move o sprite
	this->sprite.move(deslocamento.x * this->velocidadeEscalar * dt, deslocamento.y * velocidadeEscalar * dt);
}
