#include "Fantasma.h"

Fantasma::Fantasma(sf::Texture& textura, sf::Vector2f posicao, sf::Vector2f desHitbox, sf::Vector2f tamanhoHitbox):
	Inimigo(textura, posicao, desHitbox, tamanhoHitbox, 2)
{
	this->velocidadeEscalar = 150.f;//teste
	this->animador->addAnimacao("MORREU", 100.f, 0, 1, 4, 1, 120, 120);
	this->animador->addAnimacao("ANDANDO", 105.f, 0, 0, 3, 0, 120, 120);
	this->danoPermitido = true;
	this->foiAtacado = false;
	this->cont = 0;
	this->direcao = 1;
}

Fantasma::~Fantasma()
{
}

void Fantasma::atualizaMovimento(const float& dt)
{
	velocidadeVetorial.x = 0.0f;
	velocidadeVetorial.y = 0.0f;
	if (cont == 400)
	{
		direcao *= -1;
		cont = 0;
	}

	if (direcao == 1)
	{
		this->sprite.setOrigin(0, 0);
		this->sprite.setScale(1, 1);
		velocidadeVetorial.x += velocidadeEscalar;
		this->animador->play("ANDANDO", dt);
	}
	else if (direcao == -1)
	{
		this->sprite.setOrigin(100, 0);
		this->sprite.setScale(-1, 1);
		velocidadeVetorial.x -= velocidadeEscalar;
		this->animador->play("ANDANDO", dt);
	}
	cont++;
	atualizaHitbox();
	sprite.move(velocidadeVetorial * dt);
}
