#include "Jogador.h"

//Construtora/Destrutora
Jogador::Jogador(sf::Texture& textura, sf::Vector2f posicao, sf::Vector2f desHitbox, sf::Vector2f tamanhoHitbox, float alturaPulo) :
	Personagem(textura, posicao, desHitbox, tamanhoHitbox, 6)
{
	this->velocidadeEscalar = 150.f;//teste
	this->alturaPulo = alturaPulo;
	this->animador->addAnimacao("PARADO", 55.f, 0, 0, 4, 0, 100, 101);
	this->animador->addAnimacao("ANDANDO", 50.f, 0, 1, 5, 1, 100, 100);
	this->animador->addAnimacao("PULO", 92.f, 4, 2, 5, 2, 100, 100);
	this->animador->addAnimacao("DANO", 55.f, 0, 3, 4, 3, 100, 100);
	this->animador->addAnimacao("MORTE", 50.f, 0, 4, 100000, 4, 100, 100);
	this->atacou = false;
	this->puloPermitido = true;
}

Jogador::~Jogador()
{
}

void Jogador::pular(const float& dt )
{
	puloPermitido = false;
	atacou = false;
	velocidadeVetorial.y = -sqrtf(2.0f * 981.0f * alturaPulo);
	
}

void Jogador::atualizaMovimento(const float& dt)
{

	velocidadeVetorial.x = 0.0f;
	if (vida > 0)
	{
		if (this->segundoJogador)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				this->sprite.setOrigin(100, 0);
				this->sprite.setScale(-1, 1);
				velocidadeVetorial.x -= velocidadeEscalar;
				if (puloPermitido)
				{
					this->animador->play("ANDANDO", dt);
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				this->sprite.setOrigin(0, 0);
				this->sprite.setScale(1, 1);
				velocidadeVetorial.x += velocidadeEscalar;
				if (puloPermitido)
				{
					this->animador->play("ANDANDO", dt);
				}
			}

			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && puloPermitido) || atacou)
			{
				pular(dt);
			}

			else if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) &&
				!(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) &&
				!(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && puloPermitido)
			{
				this->animador->play("PARADO", dt);
			}

			else if (!puloPermitido)
			{
				this->animador->play("PULO", dt);
			}
		}
		else
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				this->sprite.setOrigin(100, 0);
				this->sprite.setScale(-1, 1);
				velocidadeVetorial.x -= velocidadeEscalar;
				if (puloPermitido)
				{
					this->animador->play("ANDANDO", dt);
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				this->sprite.setOrigin(0, 0);
				this->sprite.setScale(1, 1);
				velocidadeVetorial.x += velocidadeEscalar;
				if (puloPermitido)
				{
					this->animador->play("ANDANDO", dt);
				}
			}

			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) && puloPermitido) || atacou)
			{
				pular(dt);
				
			}

			else if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) &&
				!(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) &&
				!(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && puloPermitido)
			{
				this->animador->play("PARADO", dt);
			}

			else if (!puloPermitido)
			{
				this->animador->play("PULO", dt);
			}
		}
	}
	else 
	{
		this->animador->play("MORTE", dt);
		this->hitbox.setSize(sf::Vector2f(100, 15));
		this->desHitbox = sf::Vector2f(0, 80);
	

	}
	atualizaHitbox();
	velocidadeVetorial.y += 981.0f * dt;
	sprite.move(velocidadeVetorial * dt);


}

void Jogador::emColisao(sf::Vector2f direcao)
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
		this->puloPermitido = true;
	}
	else if (direcao.y > 0.0f)
	{
		//colisao por cima
		this->velocidadeVetorial.y = 0.0f;
	}
}






