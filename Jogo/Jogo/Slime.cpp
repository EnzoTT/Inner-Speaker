#pragma once
#include "Slime.h"



Slime::Slime(sf::Texture& textura, sf::Vector2f posicao, sf::Vector2f desHitbox, sf::Vector2f tamanhoHitbox):
	Inimigo(textura, posicao, desHitbox, tamanhoHitbox, 1)
{
	this->velocidadeEscalar = 60.f;
	this->animador->addAnimacao("MORREU", 35.f, 0, 1, 3, 1000, 98, 100);
	this->animador->addAnimacao("ANDANDO", 60.f, 0, 0, 3, 0, 98, 100);
	this->danoPermitido = true;
	this->foiAtacado = false;
	this->cont = 0;
	this->direcao = rand(-1, 1);
	this->morto = false;
	if (this->direcao == 0)
	{
		direcao = 1;
	}
}

Slime::~Slime()
{
}

void Slime::atualizaMovimento(const float& dt)
{
	velocidadeVetorial.x = 0.0f;
	if (morto)
	{
		this->animador->play("MORREU", dt);
		this->hitbox.setSize(sf::Vector2f(1, 0));
		this->desHitbox.y = 70;
	}
	else
	{
		if (cont == 250)
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
		sprite.move(velocidadeVetorial * dt);
	}
		atualizaHitbox();
		velocidadeVetorial.y += 981.0f * dt;
}
