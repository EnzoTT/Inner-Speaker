#include "Alterego.h"


Alterego::Alterego(sf::Texture& textura, sf::Vector2f posicao, sf::Vector2f desHitbox, sf::Vector2f tamanhoHitbox):
	Inimigo(textura, posicao, desHitbox, tamanhoHitbox, 2)
{
	this->velocidadeEscalar = 150.f;
	this->animador->addAnimacao("MORREU", 50.f, 0, 1, 4000, 1, 120, 120);
	this->animador->addAnimacao("ANDANDO", 60.f, 0, 0, 3, 0, 120, 120);
	this->danoPermitido = true;
	this->foiAtacado = false;
	this->cont = 0;
	this->direcao = rand(-1, 1);
	if (this->direcao == 0)
	{
		direcao = -1;
	}
}

Alterego::~Alterego()
{
}

void Alterego::atualizaMovimento(const float& dt)
{
	if (morto)
	{
		this->animador->play("MORREU", dt);
		this->hitbox.setSize(sf::Vector2f(1, 0));
		this->desHitbox.y = 120;
	}
	else
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
		this->sprite.setOrigin(150, 0);
		this->sprite.setScale(-1, 1);
		velocidadeVetorial.x -= velocidadeEscalar;
		this->animador->play("ANDANDO", dt);
	}
	cont++;
	sprite.move(velocidadeVetorial * dt);
	}
	atualizaHitbox();
}
