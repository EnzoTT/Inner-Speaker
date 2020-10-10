#pragma once
#include "EstadoFase.h"
class Fase1 :
	public EstadoFase
{
private:
	sf::Clock timer;

public:
	Fase1(sf::RenderWindow* janela, std::stack<Estado*>* estados, bool ativaCoop, bool carregaFase);
	~Fase1();

	virtual void atualiza(const float& deltaTime);
	virtual void renderiza(sf::RenderTarget* target);
	
	
};

