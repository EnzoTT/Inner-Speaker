#include "BarraDeVida.h"



BarraDeVida::BarraDeVida(float comprimento, float altura, string textura0, string textura1, string textura2, string textura3, string textura4, string textura5, string textura6)
{
	
	this->textura0.loadFromFile(textura0);
	this->textura1.loadFromFile(textura1);
	this->textura2.loadFromFile(textura2);
	this->textura3.loadFromFile(textura3);
	this->textura4.loadFromFile(textura4);
	this->textura5.loadFromFile(textura5);
	this->textura6.loadFromFile(textura6);

	this->retangulo.setSize(sf::Vector2f(comprimento, altura));
	this->retangulo.setPosition(50, 350);
	this->retangulo.setTexture(&this->textura6);
}


BarraDeVida::~BarraDeVida()
{
}


void BarraDeVida::atualiza(int vida)
{
	if (vida == 5)
	{
		this->retangulo.setTexture(&this->textura5);
	}
	if (vida == 4)
	{
		this->retangulo.setTexture(&this->textura4);
	}
	if (vida == 3)
	{
		this->retangulo.setTexture(&this->textura3);
	}
	if (vida == 2)
	{
		this->retangulo.setTexture(&this->textura2);
	}
	if (vida == 1)
	{
		this->retangulo.setTexture(&this->textura1);
	}
	if (vida == 0)
	{
		this->retangulo.setTexture(&this->textura0);
	
	}




}

void BarraDeVida::renderiza(sf::RenderTarget& target)
{
	target.draw(this->retangulo);
}

void BarraDeVida::atualizaPos(sf::Vector2f pos)
{
	this->retangulo.setPosition(pos);
}
