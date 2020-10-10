#include "Personagem.h"
#include <chrono>
#include <random>

Personagem::Personagem(sf::Texture& textura, sf::Vector2f posicao,sf::Vector2f desHitbox, sf::Vector2f tamanhoHitbox, int vida) :
	Entidade(textura, posicao, desHitbox, tamanhoHitbox)
{	
	this->animador = new Animador(sprite, textura);
	this->vida = vida;
}

Personagem::~Personagem()
{
	delete(this->animador);
}

void Personagem::atualizaVida(bool colidiu)
{
	if (colidiu)
	{
		vida--;
		
		//cout << "Jogador tomou dano" << endl;
	}
	
}

void Personagem::atualizaMovimento(const float& dt)
{
}

int Personagem::rand(int min, int max)
{
	//tem que por essa função aqui em algum lugar e dai os paramentros sao o numero minimo e o numero maximo do random

		// obtain a seed from the system clock:
	unsigned seed = static_cast<int> (std::chrono::system_clock::now().time_since_epoch().count());

	// seeds the random number engine, the mersenne_twister_engine
	std::mt19937 generator(seed);

	// set a distribution range (1 - 100)
	std::uniform_int_distribution<int> distribution(min, max);

	return distribution(generator);
}
