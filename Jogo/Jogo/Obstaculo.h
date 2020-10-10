#pragma once
#include "Entidade.h"
class Obstaculo :
	public Entidade
{
protected:
	int intervalo;//qual plataforma foi colocado

	float velocidadeEscalar;
	sf::Vector2f velocidadeVetorial;

	bool cai;

	int peso;

	vector<Obstaculo*> obstaculos;//vetor com todos os obstaculos

public:
	Obstaculo(sf::Texture& textura, sf::Vector2f posicao, sf::Vector2f desHitbox, sf::Vector2f tamanhoHitbox,int intervalo);
	~Obstaculo();
	
	virtual void atualiza(const float& dt);
	void emColisao(sf::Vector2f direcao);

	int getIntervalo() { return this->intervalo; }

	int getPeso() { return this->peso; }

	virtual void movimento(const float& dt, sf::Vector2f deslocamento);

	//Funcoes do vetor de obstaculos
};

