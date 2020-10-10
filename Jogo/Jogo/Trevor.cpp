#include "Trevor.h"



Trevor::Trevor(sf::Texture& textura, sf::Vector2f posicao, sf::Vector2f desHitbox, sf::Vector2f tamanhoHitbox) :
	Inimigo(textura, posicao, desHitbox, tamanhoHitbox, 10)
{
	this->velocidadeEscalar = 400.f;
	this->animador->addAnimacao("ATACANDO", 40.f, 0, 1, 1, 1, 80, 90);
	this->animador->addAnimacao("ANDANDO", 40.f, 0, 0, 3, 0, 51, 90);
	this->animador->addAnimacao("DANO", 60.f, 0, 2, 1, 2, 50, 90);
	this->animador->addAnimacao("MORRENDO", 60.f, 0, 3, 6000, 3, 95, 90);
	this->danoPermitido = true;
	this->foiAtacado = false;
	this->cont = 0;
	this->atacando = false;
	this->ciclo = 0;
	this->direcao = -1;
}


Trevor::~Trevor()
{
}

void Trevor::atualizaMovimento(const float& dt)
{
	if (morto)
	{
		this->animador->play("MORRENDO", dt);
		this->hitbox.setSize(sf::Vector2f(1, 0));
		this->desHitbox.y = 90;
	}
	else
	{

	velocidadeVetorial.x = 0.0f;
	if (ciclo == 400)
	{
		direcao *= -1;
		ciclo = 0;
	}

	if (cont == 50 && atacando == false)
	{
		atacando = true;
		cont = 0;
	}
	else if (cont == 50 && atacando == true)
	{
		atacando = false;
		cont = 0;
	}

	if (atacando == true)
	{
		this->animador->play("ATACANDO", dt);
	}
	else if (direcao == 1)
	{
		this->sprite.setOrigin(0, 0);
		this->sprite.setScale(1, 1);
		velocidadeVetorial.x += velocidadeEscalar;
		this->animador->play("ANDANDO", dt);
	}
	else if(direcao == -1)
	{
		this->sprite.setOrigin(70, 0);
		this->sprite.setScale(-1, 1);
		velocidadeVetorial.x -= velocidadeEscalar;
		this->animador->play("ANDANDO", dt);
	}

	cont++;
	ciclo++;
	sprite.move(velocidadeVetorial * dt);
	}
	atualizaHitbox();
	velocidadeVetorial.y += 981.0f * dt;
}


