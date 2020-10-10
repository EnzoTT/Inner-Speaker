#pragma once

#include "Colisor.h"

//Essa é uma classe que é herança de qualquer objeto do jogo
class Entidade
{
private:
protected:

	sf::Sprite sprite;

	sf::RectangleShape hitbox;
	sf::Vector2f desHitbox;


public:
	//construtora e destrutora
	Entidade(sf::Texture& textura, sf::Vector2f posicao, sf::Vector2f desHitbox, sf::Vector2f tamanhoHitbox);
	virtual ~Entidade();

	//Funcoes componentes
	void atualizaHitbox(); //Atualiza a hitbox com relacao a pos do sprite


	//Funcoes
	virtual void renderiza(sf::RenderTarget& target);
	

	//Gets
	Colisor getColisor()
	{
		return Colisor(this->sprite,this->hitbox);
	}

	sf::Vector2f getPosicao() { return sprite.getPosition(); }
	void setPosicao(sf::Vector2f pos) { this->sprite.setPosition(pos); }

};
