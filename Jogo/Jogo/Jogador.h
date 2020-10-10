#pragma once
#include "Personagem.h"

class Jogador : public Personagem
{
private:

	bool puloPermitido;	
	float alturaPulo;
	bool atacou;
	bool segundoJogador;

	


public:
	//construtora e destrutora
	Jogador(sf::Texture& textura, sf::Vector2f posicao, sf::Vector2f desHitbox, sf::Vector2f tamanhoHitbox, float alturaPulo);
	virtual ~Jogador();
	

	void pular(const float& dt);
	virtual void atualizaMovimento(const float& dt);
	void emColisao(sf::Vector2f direcao);

	//sets e gets
	sf::Vector2f getVelocidadeVetorial() { return velocidadeVetorial; }
	void setPulo(bool pulo) { this->puloPermitido = pulo; }
	void setJogador(bool jogador) { this->segundoJogador = jogador; }
	void setAtacou(bool atacou) { this->atacou = atacou; }
	bool getAtacou() { return atacou; }


};

