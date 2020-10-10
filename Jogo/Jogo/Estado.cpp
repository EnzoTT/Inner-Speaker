#include "Estado.h"
#include <chrono>
#include <random>

Estado::Estado(sf::RenderWindow* janela, std::stack<Estado*>* estados, bool ativaCoop)
{
	this->janela = janela;
	this->estados = estados;
	this->sair = false;
	this->ativaCoop = ativaCoop;
	this->pausado = false;
}

Estado::~Estado()
{
	
}

const bool & Estado::getSair() const
{
	return this->sair;
}

//Pede para fechar o estado
void Estado::fechaEstado()
{
	this->sair = true;
}

void Estado::pausaEstado()
{
	this->pausado = true;
}

void Estado::despausaEstado()
{
	this->pausado = false;
}

int Estado::rand(int min, int max)
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

//Atualiza a posicao do mouse  
void Estado::atualizaPosMouse()
{
	this->posMouseTela = sf::Mouse::getPosition();
	this->posMouseJanela = sf::Mouse::getPosition(*this->janela);
	this->posMouseView = this->janela->mapPixelToCoords(sf::Mouse::getPosition(*this->janela));
}

void Estado::atualizaTeclas(const float& deltaTime)
{
}
