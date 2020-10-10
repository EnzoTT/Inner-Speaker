#pragma once
#include "Entidade.h"
class Personagem : public Entidade
{
protected:
	
	Animador* animador;

	float velocidadeEscalar;
	sf::Vector2f velocidadeVetorial;

	int vida;//Se a vida for zero acontece alguma coisa tipo colocar o ranking 
	bool invencivel;


public:
	//Construtora e Destrutora
	Personagem(sf::Texture& textura, sf::Vector2f posicao,sf::Vector2f desHitbox, sf::Vector2f tamanhoHitbox,int vida);
	~Personagem();

	virtual void atualizaVida(bool colidiu);
	virtual void emColisao(sf::Vector2f direcao) = 0;
	virtual void atualizaMovimento(const float& dt);

	//Sets e Gets
	int getVida() { return this->vida; }
	void setVida(int vida) { this->vida = vida; }
	bool getInvencivel() { return this->invencivel; }
	void setInvencivel(bool invencivel) { this->invencivel = invencivel; }

	int rand(int min, int max);
};



