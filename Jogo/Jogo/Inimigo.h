#pragma once
#include<SFML/Graphics.hpp>
#include"Personagem.h"


class Inimigo : public Personagem
{
protected:
	bool danoPermitido;
	bool foiAtacado;

	bool morto;
public:
	Inimigo( sf::Texture& textura, sf::Vector2f posicao, sf::Vector2f desHitbox, sf::Vector2f tamanhoHitbox, int vida);
	~Inimigo();

	
	virtual void emColisao(sf::Vector2f direcao);
	virtual void atualizaMovimento(const float& dt);

	//sets e gets
	int getVida() { return this->vida; }
	void setVida(int vida) { this->vida = vida; }

	bool getDano() { return this->danoPermitido; }
	void setDano(bool danoPermitido) { this->danoPermitido = danoPermitido; }

	bool getFoiAtacado() { return this->foiAtacado; }

	void setMorto(bool morto) { this->morto = morto; }
	bool getMorto() { return this->morto; }
		   	 
};

