#include "Robo.h"





Robo::Robo(sf::Texture& textura, sf::Vector2f posicao, sf::Vector2f desHitbox, sf::Vector2f tamanhoHitbox):
	Inimigo(textura, posicao, desHitbox, tamanhoHitbox, 3)
{
	this->velocidadeEscalar = 90.f;
	this->animador->addAnimacao("MORREU", 50.f, 0, 1, 40000, 1, 99, 100);
	this->animador->addAnimacao("ANDANDO", 60.f, 0, 0, 3, 0, 99, 100);
	this->danoPermitido = true;
	this->foiAtacado = false;
	this->cont = 0;
	this->direcao = rand(-1,1);
	if (this->direcao == 0)
	{
		direcao = -1;
	}
}


Robo::~Robo()
{
}

void Robo::atualizaMovimento(const float& dt)
{
	velocidadeVetorial.x = 0.0f;
	if (morto)
	{
		this->animador->play("MORREU", dt);
		this->hitbox.setSize(sf::Vector2f(1, 0));
		this->desHitbox.y = 90;
	}
	else
	{

	if (cont == 200)
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
		this->sprite.setOrigin(90, 0);
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
