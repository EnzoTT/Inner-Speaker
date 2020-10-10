#include "Entidade.h"



//Construtora/Destrutora
Entidade::Entidade(sf::Texture& textura, sf::Vector2f posicao,sf::Vector2f desHitbox, sf::Vector2f tamanhoHitbox)
{
	//offset
	this->desHitbox = desHitbox;

	//cria sprite
	this->sprite.setTexture(textura);
	this->sprite.setPosition(posicao);

	//cria hitbox
	this->hitbox.setPosition(this->sprite.getPosition().x + this->desHitbox.x, this->sprite.getPosition().y + this->desHitbox.y);
	this->hitbox.setSize(tamanhoHitbox);
	
	//teste
	this->hitbox.setFillColor(sf::Color::Transparent);
	//this->hitbox.setOutlineThickness(1.f);
	//this->hitbox.setOutlineColor(sf::Color::Green);
}

Entidade::~Entidade()
{
	
}

//Funcoes de Componentes

void Entidade::atualizaHitbox()
{
	//Atualiza com relacao ao sprite 
	this->hitbox.setPosition(this->sprite.getPosition().x + this->desHitbox.x, this->sprite.getPosition().y + this->desHitbox.y);
}

//Funcoes
void Entidade::renderiza(sf::RenderTarget& target)
{
	//Renderiza os elementos da entidade
		target.draw(this->sprite);

		target.draw(this->hitbox);
}

